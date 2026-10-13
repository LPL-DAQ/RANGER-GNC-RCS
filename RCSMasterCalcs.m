%% =========================================================================
%% RCS_Master_Calcs.m
%% Consolidated Roll Control System (RCS) sizing + performance script
%% for the USC LPL hopper vehicle cold-gas RCS.
%%
%% Merged from: RCS_180_sweep.m, ParabolicNozzle.m, LPLTestBedCalcs.m,
%%              LineLoss.m
%% Per request: the nozzle 3D bell-profile figure and the Siemens NX
%% spline export are NOT included. Every numeric value IS included.
%% =========================================================================
%
% ------------------------- VALUE CONFLICTS FOUND -------------------------
% The four source scripts disagreed on several supposedly-fixed physical
% quantities. Resolutions used below, and why.
%
% 1) Ixxp (roll moment of inertia): source scripts disagreed.
%      -> CONFIRMED correct value: 252,099.557 lbm*in^2 (matches
%         ParabolicNozzle.m and LPLTestBedCalcs.m). RCS_180_sweep.m's
%         value was wrong and is not used.
%
% 2) Moment arm / nozzle radius: source scripts disagreed.
%      -> CONFIRMED correct value: 6.5 in (matches ParabolicNozzle.m,
%         consistent with the corrected Ixxp above). RCS_180_sweep.m's
%         value was wrong and is not used.
%
% 3) GN2 gas constant R:
%      RCS_180_sweep.m / ParabolicNozzle.m / LPLTestBedCalcs.m .. 296.8 J/kg-K
%      LineLoss.m ................................................ 297 J/kg-K
%      -> USED 296.8 J/kg-K (3-of-4 majority).
%
% 4) Stagnation temperature T0:
%      RCS_180_sweep.m / LPLTestBedCalcs.m / LineLoss.m .......... 300 K
%      ParabolicNozzle.m ........................................... 293.15 K
%      -> USED 300 K (3-of-4 majority).
%
% 5) Regulator pressure, gauge vs. absolute:
%      RCS_180_sweep.m & LPLTestBedCalcs.m fed 100 psi straight into the
%      Pa conversion (i.e. implicitly treated it as already absolute).
%      LineLoss.m explicitly did P0_abs = 100 psi(gauge) + 14.7 (atm).
%      -> USED LineLoss.m's gauge+atm convention, since that's the
%         physically correct way to turn a regulator setpoint into an
%         absolute pressure for the choked-flow equations. This makes
%         mdot/thrust/torque here a bit higher than running
%         RCS_180_sweep.m or LPLTestBedCalcs.m alone would give.
%
% 6) Orifice/throat diameter:
%      RCS_180_sweep.m: fixed, already-selected 5/16" orifice.
%      LineLoss.m: separate dthroat = 0.298 in, dorifice = 0.188 in, AND a
%      hardcoded Athroat = 2.16e-5 m^2 that matches neither of its own
%      diameters.
%      -> USED the fixed 5/16" orifice (RCS_180_sweep.m's value, not
%         contradicted by a clean fixed value elsewhere) and derived the
%         flow area from it directly instead of LineLoss.m's inconsistent
%         hardcoded value. *** CONFIRM this is still the correct orifice,
%         given the Ixxp/moment-arm correction above. ***
%
% 7) ParabolicNozzle.m used its own separate supply pressure (210 psi) and
%    a flat 8% loss factor (0.92) for its throat-sizing calc, instead of
%    the detailed loss chain in LineLoss.m.
%      -> USED the delivered pressure computed in Section 3 below (this
%         script's own line-loss chain) instead, so these numbers differ
%         from running ParabolicNozzle.m standalone.
%
% 8) LPLTestBedCalcs.m assumed a flat GN2 density of 2.0 lbm/ft^3 for line
%    sizing.
%      -> USED the actual computed density (rho = P/RT at the resolved
%         P0/R/T0) instead.
%
% 9) Target maneuver spec (used only to CHECK the fixed orifice, not to
%    re-size it): delta_phi = 5 deg in t = 4 s, disturbance torque 2 N*m,
%    margin = 2x -- all carried over unchanged as ParabolicNozzle.m's own
%    assumptions (nothing else conflicted with these).
%
% ------------------------- BEHAVIOR CHANGE FLAGGED ------------------------
% RCS_180_sweep.m's pressure-droop loop (its "OPERATING PRESSURE &
% CAPABILITY" section) computed a droop-adjusted pressure at every
% timestep but then only ever used the LAST iteration's value (t = 15 s)
% for mdot/thrust/torque -- so in the original script the droop model had
% no actual effect on the sweep sim; thrust/torque were constant the whole
% run. That's reproduced below as an option, but the main sweep sim now
% uses TIME-VARYING pressure (thrust/torque recomputed every timestep from
% the drooping tank pressure), since that appears to be the model's
% intent. Set USE_TIME_VARYING_DROOP = false to restore the original
% constant-pressure behavior.
% =========================================================================

clear; clc; close all;

USE_TIME_VARYING_DROOP = true;   % see note above

%% =====================  1. CONSTANTS & GAS PROPERTIES  ===================
g       = 32.174;      % ft/s^2
D2R     = pi/180;
R2D     = 180/pi;
gamma   = 1.4;
R_gas   = 296.8;        % J/kg-K, GN2   (resolved conflict #3)
T0      = 300;          % K             (resolved conflict #4)
Cd      = 0.9;
Isp_GN2 = 65;            % s

%% =====================  2. VALIDATED HARDWARE PROPERTIES  ================
Ixxp_lbm_in2 = 252099.557;                   % lbm*in^2  (confirmed value, conflict #1)
Ixxp         = Ixxp_lbm_in2 / g / 144;       % slug*ft^2
Ixxp_SI      = Ixxp_lbm_in2 * 0.00029263965; % kg*m^2

r_nozzle_in = 6.5;                            % in        (confirmed value, conflict #2)
r_nozzle_ft = r_nozzle_in / 12;
r_nozzle_m  = r_nozzle_in * 0.0254;

D_orifice_in = 5/16;                          % in, fixed selected orifice
D_orifice_m  = D_orifice_in * 0.0254;
A_orifice_m2 = pi * D_orifice_m^2 / 4;

fprintf('=== HARDWARE ===\n');
fprintf('Ixxp = %.4f slug-ft^2 (%.4f kg-m^2)\n', Ixxp, Ixxp_SI);
fprintf('Moment arm = %.3f in (%.4f m)\n', r_nozzle_in, r_nozzle_m);
fprintf('Fixed orifice diameter = %.4f in (A = %.6e m^2)\n\n', D_orifice_in, A_orifice_m2);

%% ============  3. SUPPLY PRESSURE & LINE LOSSES (LineLoss.m)  ============
P0_reg_psi = 200;                     % psi, regulator setpoint
P0_abs_psi = P0_reg_psi + 14.7;       % psi absolute (resolved conflict #5)
P0_Pa      = P0_abs_psi * 6894.76;    % Pa, at the regulator/tank

choke_factor = sqrt(gamma/(R_gas*T0)) * (2/(gamma+1))^((gamma+1)/(2*(gamma-1)));
mdot_kg_s    = Cd * A_orifice_m2 * P0_Pa * choke_factor;   % kg/s, choked flow
mdot_lbm_s   = mdot_kg_s / 0.45359237;
mdot_slugs_s = mdot_lbm_s / g;

rho_line  = P0_Pa / (R_gas * T0);     % kg/m^3

D_line_in = 4/8;                      % in, distribution line (LineLoss.m assumption)
D_line_m  = D_line_in * 0.0254;
A_line_m2 = pi * D_line_m^2 / 4;
v_line    = mdot_kg_s / (rho_line * A_line_m2);   % m/s

% Major (friction) loss
f_darcy = 0.0225;      % Darcy friction factor, assumed (0.015-0.03 range average)
L_line  = 0.333;       % m, assumed line length
D_hyd   = 0.0075756;   % m, internal diameter used for the friction calc (LineLoss.m)
dP_major_Pa  = f_darcy * (L_line/D_hyd) * (rho_line * v_line^2 / 2);
dP_major_psi = dP_major_Pa / 6894.76;

% Minor losses (fittings), matching the PID
fittings = {struct('name','tbranch', 'count',2,'K',1.5), ...
            struct('name','solenoid','count',1,'K',3.0), ...
            struct('name','elbow90', 'count',2,'K',0.75), ...
            struct('name','orifice', 'count',1,'K',3.63)};
K_sum = 0;
for i = 1:numel(fittings)
    K_sum = K_sum + fittings{i}.count * fittings{i}.K;
end
dP_minor_Pa  = K_sum * 0.5 * rho_line * v_line^2;
dP_minor_psi = dP_minor_Pa / 6894.76;

dP_total_Pa  = dP_major_Pa + dP_minor_Pa;
dP_total_psi = dP_total_Pa / 6894.76;

P_thruster_Pa  = P0_Pa - dP_total_Pa;   % delivered pressure at the thruster inlet
P_thruster_psi = P_thruster_Pa / 6894.76;

fprintf('=== SUPPLY PRESSURE & LINE LOSSES ===\n');
fprintf('Regulator: %.1f psig -> %.2f psia (%.0f Pa)\n', P0_reg_psi, P0_abs_psi, P0_Pa);
fprintf('mdot (fixed orifice, choked) = %.6f kg/s (%.6f lbm/s)\n', mdot_kg_s, mdot_lbm_s);
fprintf('Velocity in %.3f" line = %.3f m/s\n', D_line_in, v_line);
fprintf('Major (friction) loss = %.4f psi\n', dP_major_psi);
fprintf('Minor (fittings) loss = %.4f psi (K_sum = %.2f)\n', dP_minor_psi, K_sum);
fprintf('Total line loss = %.4f psi\n', dP_total_psi);
fprintf('Delivered pressure at thruster = %.3f psia (%.0f Pa)\n\n', P_thruster_psi, P_thruster_Pa);

%% ==========  4. THRUSTER PERFORMANCE (fixed orifice, validated formula)  ==
% F = mdot * Isp * g, gated on valve-open time -- NOT the solenoid force
% sensor (per your teammate's note on the Simscape model).
F_actual_lbf = mdot_slugs_s * Isp_GN2 * g;
F_actual_N   = F_actual_lbf * 4.4482216153;

Torque_actual_ftlbf = F_actual_lbf * r_nozzle_ft;
Torque_actual_Nm    = F_actual_N   * r_nozzle_m;

alpha_actual_rad = Torque_actual_ftlbf / Ixxp;   % rad/s^2
alpha_actual_deg = alpha_actual_rad / D2R;

fprintf('=== THRUSTER PERFORMANCE (per nozzle) ===\n');
fprintf('Thrust  = %.4f lbf (%.4f N)\n', F_actual_lbf, F_actual_N);
fprintf('Torque  = %.4f ft-lbf (%.4f N-m)\n', Torque_actual_ftlbf, Torque_actual_Nm);
fprintf('Achievable alpha = %.4f rad/s^2 (%.3f deg/s^2)\n\n', alpha_actual_rad, alpha_actual_deg);

%% ====  4b. ROLL TORQUE AT r = 6.5": WITHOUT vs. WITH A NOZZLE  =============
% Same mass flow (mdot_kg_s, choked at the fixed orifice, Section 3) in
% both cases -- the only difference is what happens to the gas AFTER the
% throat:
%   Without nozzle: bare orifice, gas leaves at sonic (Mach 1) throat
%   velocity v* -- there's no diverging section to keep accelerating it.
%   With nozzle: a diverging (parabolic) section continues expanding the
%   gas down to ambient pressure, accelerating it well past sonic to the
%   full exhaust velocity ve. Same mdot, higher exit velocity -> more
%   thrust -> more torque. Both cases use the SAME 6.5" moment arm.
theta_e_deg      = 7.0;      % deg, Rao bell exit parallel angle (divergence loss)
SeaLevelPressure = 101325;   % Pa

lambda = (1 + cos(theta_e_deg*D2R))/2;

T_star = T0 * (2/(gamma+1));                 % throat static temp at Mach 1, K
v_star = sqrt(gamma * R_gas * T_star);        % sonic throat velocity, m/s (no nozzle)
ve     = lambda * sqrt(2*T0*R_gas*(gamma/(gamma-1)) * ...
         (1 - (SeaLevelPressure/P0_Pa)^((gamma-1)/gamma)));   % full-expansion exit velocity, m/s (with nozzle)

Thrust_without_nozzle_N   = mdot_kg_s * v_star;
Thrust_with_nozzle_N      = mdot_kg_s * ve;
Thrust_without_nozzle_lbf = Thrust_without_nozzle_N * 0.224809;
Thrust_with_nozzle_lbf    = Thrust_with_nozzle_N * 0.224809;

Torque_without_nozzle_ftlbf = Thrust_without_nozzle_lbf * r_nozzle_ft;   % at r = 6.5 in
Torque_without_nozzle_Nm    = Thrust_without_nozzle_N   * r_nozzle_m;

Torque_with_nozzle_ftlbf = Thrust_with_nozzle_lbf * r_nozzle_ft;        % at r = 6.5 in
Torque_with_nozzle_Nm    = Thrust_with_nozzle_N   * r_nozzle_m;

fprintf('=== ROLL TORQUE AT r = %.2f in: WITHOUT vs. WITH A NOZZLE ===\n', r_nozzle_in);
fprintf('Without nozzle (sonic throat only): v* = %.2f m/s -> Thrust = %.4f lbf (%.4f N) -> Torque = %.4f ft-lbf (%.4f N-m)\n', ...
    v_star, Thrust_without_nozzle_lbf, Thrust_without_nozzle_N, Torque_without_nozzle_ftlbf, Torque_without_nozzle_Nm);
fprintf('With nozzle (full expansion): ve = %.2f m/s -> Thrust = %.4f lbf (%.4f N) -> Torque = %.4f ft-lbf (%.4f N-m)\n', ...
    ve, Thrust_with_nozzle_lbf, Thrust_with_nozzle_N, Torque_with_nozzle_ftlbf, Torque_with_nozzle_Nm);
fprintf('--> Adding the nozzle increases roll torque by %.1f%%\n\n', ...
    100*(Torque_with_nozzle_ftlbf/Torque_without_nozzle_ftlbf - 1));

%% ====  5. MANEUVER REQUIREMENT CHECK & IDEAL NOZZLE SIZING (ParabolicNozzle.m) ====
SvAmount          = 2;      % opposing nozzle pair (ParabolicNozzle.m assumption)
delta_phi_deg     = 5;      % deg, assumed target slew
t_maneuver        = 4.0;    % s, assumed maneuver time
DisturbanceTorque = 2.0;    % N*m, assumed disturbance
margin            = 2.0;    % safety margin factor
% (theta_e_deg, SeaLevelPressure, lambda already computed in Section 4b)

AlphaRequired = (4 * (delta_phi_deg*D2R)) / (t_maneuver^2);   % rad/s^2, slew-driven
MinAlpha      = (DisturbanceTorque * margin) / Ixxp_SI;        % rad/s^2, disturbance-driven
AlphaTarget   = max(AlphaRequired, MinAlpha);

RequiredTorque = Ixxp_SI * AlphaTarget;                     % N*m
RequiredThrust = RequiredTorque / (r_nozzle_m * SvAmount);  % N, per nozzle

P0_ideal = P_thruster_Pa;   % delivered pressure from Section 3, used for this sizing check
Cf = sqrt((2*gamma^2/(gamma-1)) * (2/(gamma+1))^((gamma+1)/(gamma-1)) * ...
     (1 - (SeaLevelPressure/P0_ideal)^((gamma-1)/gamma)));
ExitMach = sqrt((2/(gamma-1)) * ((P0_ideal/SeaLevelPressure)^((gamma-1)/gamma) - 1));

ThroatArea_ideal   = RequiredThrust / (P0_ideal * Cf);
ThroatDiam_ideal_m  = 2*sqrt(ThroatArea_ideal/pi);
ThroatDiam_ideal_in = ThroatDiam_ideal_m/0.0254;

ve = lambda * sqrt(2*T0*R_gas*(gamma/(gamma-1)) * (1 - (SeaLevelPressure/P0_ideal)^((gamma-1)/gamma)));
Isp_ideal = ve/9.80665;

fprintf('=== MANEUVER REQUIREMENT CHECK ===\n');
fprintf('Target: %.1f deg in %.1f s | disturbance margin: %.1fx %.1f N-m\n', delta_phi_deg, t_maneuver, margin, DisturbanceTorque);
fprintf('Alpha required (slew) = %.4f rad/s^2 | Alpha required (disturbance) = %.4f rad/s^2\n', AlphaRequired, MinAlpha);
fprintf('Governing alpha target = %.4f rad/s^2\n', AlphaTarget);
fprintf('Required torque = %.4f N-m | Required thrust/nozzle = %.4f N\n', RequiredTorque, RequiredThrust);
fprintf('Ideal (max-torque) throat diameter for this requirement = %.4f in\n', ThroatDiam_ideal_in);
fprintf('Ideal exhaust velocity = %.2f m/s | Ideal Isp = %.2f s\n', ve, Isp_ideal);
fprintf('Actual fixed orifice diameter = %.4f in\n', D_orifice_in);
if alpha_actual_rad >= AlphaTarget
    fprintf('--> Fixed %.4f" orifice MEETS the alpha requirement (%.1f%% margin)\n\n', D_orifice_in, 100*(alpha_actual_rad/AlphaTarget - 1));
else
    fprintf('--> Fixed %.4f" orifice DOES NOT MEET the alpha requirement (%.1f%% short)\n\n', D_orifice_in, 100*(1 - alpha_actual_rad/AlphaTarget));
end

%% =========  6. STANDARD LINE / ORIFICE SIZE CHECK (LPLTestBedCalcs.m)  ====
V_line_ft_s = 70;   % ft/s, assumed max line velocity
rho_lbm_ft3 = rho_line * 0.062428;   % kg/m^3 -> lbm/ft^3 (resolved conflict #8: uses actual computed density, not the flat 2.0 lbm/ft^3 assumption)
standard_sizes_in = [1/8, 3/16, 1/4, 5/16, 3/8, 1/2, 5/8, 3/4, 1.0];

Vdot_ft3_s = mdot_lbm_s / rho_lbm_ft3;
A_req_ft2  = Vdot_ft3_s / V_line_ft_s;
D_req_ft   = sqrt(4*A_req_ft2/pi);
D_req_in   = D_req_ft * 12;

idx = find(standard_sizes_in >= D_req_in, 1, 'first');
if isempty(idx)
    recommended_line_in = standard_sizes_in(end);
else
    recommended_line_in = standard_sizes_in(idx);
end

[~, idx_orf] = min(abs(standard_sizes_in - D_orifice_in));
nearest_std_orifice_in = standard_sizes_in(idx_orf);

fprintf('=== STANDARD SIZE CHECK ===\n');
fprintf('Required line ID (<=%.0f ft/s cap) = %.4f in -> nearest standard = %.3f in (using %.3f in assumed)\n', V_line_ft_s, D_req_in, recommended_line_in, D_line_in);
fprintf('Fixed orifice (%.4f in) nearest standard size = %.3f in\n\n', D_orifice_in, nearest_std_orifice_in);

%% ===============  7. 180-DEGREE CLOSED-LOOP SWEEP SIMULATION  =============
% (RCS_180_sweep.m) - PD + Schmitt-trigger valve logic validated against
% the Simscape model per your notes.

dt = 0.005;
t_final = 15;
time = (0:dt:t_final)';
N = length(time);

min_pulse_time = 0.10;  % s, fixed minimum valve-open time

% Tank pressure droop model (psi/s), same as RCS_180_sweep.m
droop_rate   = @(t) 2 + 0.05*t;
P_tank_psi_t = P0_abs_psi - droop_rate(time).*time;   % psi absolute, drooping
P_tank_Pa_t  = P_tank_psi_t * 6894.76;

if USE_TIME_VARYING_DROOP
    mdot_slugs_t = (Cd * A_orifice_m2 * P_tank_Pa_t * choke_factor / 0.45359237) / g;  % slugs/s at each t
    F_lbf_t      = mdot_slugs_t * Isp_GN2 * g;
    Torque_t     = F_lbf_t * r_nozzle_ft;
else
    % Reproduces RCS_180_sweep.m's original behavior: constant
    % thrust/torque from the LAST droop value (t = t_final) -- the droop
    % model had no real effect on the sim.
    mdot_slugs_t = repmat(mdot_slugs_s, N, 1);
    F_lbf_t      = repmat(F_actual_lbf, N, 1);
    Torque_t     = repmat(Torque_actual_ftlbf, N, 1);
end

% Initial conditions
phi = 0; omega = 0;

% PD controller gains
Kp = 2; Kd = 5;

% Schmitt trigger
deadzone = 0.02; hysteresis = 0.01;

history_phi = zeros(N,1); history_omega = zeros(N,1);
history_valve = zeros(N,1); history_mass = zeros(N,1);

valve_state = 0; pulse_timer = 0;
total_mass_used_slugs = 0; actuation_count = 0;

% 180-deg reference trace: move 180 deg over 10 s, starting at t = 1 s
start_time = 1.0; duration = 10.0; end_time = start_time + duration;
target_angle = 180.0; sweep_rate = target_angle/duration;

trace_phi_deg = zeros(N,1); trace_omega_deg = zeros(N,1);
for i = 1:N
    t = time(i);
    if t < start_time
        trace_phi_deg(i) = 0; trace_omega_deg(i) = 0;
    elseif t <= end_time
        trace_phi_deg(i) = sweep_rate*(t-start_time);
        trace_omega_deg(i) = sweep_rate;
    else
        trace_phi_deg(i) = target_angle; trace_omega_deg(i) = 0;
    end
end

for i = 1:N
    phi_ref   = trace_phi_deg(i)*D2R;
    omega_ref = trace_omega_deg(i)*D2R;

    error_phi   = phi_ref - phi;
    error_omega = omega_ref - omega;
    control_effort = Kp*error_phi + Kd*error_omega;

    prev_valve = valve_state;
    if pulse_timer > 0
        pulse_timer = pulse_timer - dt;
    else
        if valve_state == 0
            if control_effort > deadzone
                valve_state = 1; pulse_timer = min_pulse_time;
            elseif control_effort < -deadzone
                valve_state = -1; pulse_timer = min_pulse_time;
            end
        elseif valve_state == 1
            if control_effort < (deadzone-hysteresis)
                valve_state = 0;
            end
        elseif valve_state == -1
            if control_effort > -(deadzone-hysteresis)
                valve_state = 0;
            end
        end
    end
    if valve_state ~= 0 && prev_valve == 0
        actuation_count = actuation_count + 1;
    end

    alpha_step = (valve_state * Torque_t(i)) / Ixxp;
    omega = omega + alpha_step*dt;
    phi   = phi + omega*dt;

    if valve_state ~= 0
        total_mass_used_slugs = total_mass_used_slugs + mdot_slugs_t(i)*dt;
    end

    history_phi(i)   = phi/D2R;
    history_omega(i) = omega/D2R;
    history_valve(i) = valve_state;
    history_mass(i)  = total_mass_used_slugs * g;  % lbm
end

fprintf('=== 180-DEG SWEEP SIMULATION SUMMARY ===\n');
fprintf('Total valve actuations: %d\n', actuation_count);
fprintf('Total propellant used: %.4f lbm\n', history_mass(end));
fprintf('Final roll angle: %.2f deg | Final roll rate: %.2f deg/s\n\n', history_phi(end), history_omega(end));

%% Plots
figure('Name','RCS 180-Degree Sweep Maneuver','Position',[100 100 900 800]);

subplot(4,1,1);
plot(time, trace_phi_deg,'k--','LineWidth',1.5,'DisplayName','Target Trace'); hold on;
plot(time, history_phi,'b','LineWidth',1.5,'DisplayName','Actual Position');
ylabel('Roll Angle (deg)'); title('Angular Position'); legend('Location','southeast'); grid on;

subplot(4,1,2);
plot(time, trace_omega_deg,'k--','LineWidth',1.5,'DisplayName','Target Rate'); hold on;
plot(time, history_omega,'r','LineWidth',1.5,'DisplayName','Actual Rate');
ylabel('Roll Rate (deg/s)'); title('Roll Rate Tracking'); legend('Location','northeast'); grid on;

subplot(4,1,3);
stairs(time, history_valve,'k','LineWidth',1.2);
ylabel('Valve Command'); title(sprintf('Actuations: %d Total Valve Firings', actuation_count));
yticks([-1 0 1]); yticklabels({'CCW','OFF','CW'}); ylim([-1.5 1.5]); grid on;

subplot(4,1,4);
plot(time, history_mass,'g','LineWidth',1.5);
ylabel('GN2 Used (lbm)'); xlabel('Time (s)');
title(sprintf('Fuel Usage (Final: %.4f lbm)', history_mass(end))); grid on;