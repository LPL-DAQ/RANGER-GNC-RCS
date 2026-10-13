% =========================================================================
% RCS_180_Degree_Sweep_Sim.m
% =========================================================================
clear; clc; close all;

%% 1. FIXED HARDWARE & GAS PROPERTIES
g = 32.174;                     
deg2rad = pi/180;
gamma = 1.4; R = 296.8; T0 = 300; Cd = 0.9; Isp_GN2 = 65;

% Testbed Properties
Ixxp = 58443.351 / g / 144;     % ~12.61 slug-ft^2
r_nozzle = 5.0 / 12.0;          % Fixed 5-inch moment arm (0.4167 ft)
D_orifice_in = 5/16;            % Fixed 5/16" Orifice
min_pulse_time = 0.10;          % Fixed 0.1s minimum firing time

%% 2. SIMULATION SETUP
dt = 0.005;                     
t_final = 15;                   % 15 seconds total to see the settling after the maneuver
time = 0:dt:t_final;
N = length(time);

%% 3. OPERATING PRESSURE & CAPABILITY
for i = 1:N
    t = time(i);
    droop_rate = @(t) 2 + 0.05*t;   % psi/s
    P0_psi = 100;
    %volume of error
    %how quickly thats happening
    P_psi = P0_psi - droop_rate(t) * t;                  
    P0_Pa = P_psi * 6894.76;
end

D_actual_m = D_orifice_in / 39.3700787;
A_actual_m2 = pi * (D_actual_m^2) / 4;
choke = sqrt(gamma/(R*T0)) * (2/(gamma+1))^((gamma+1)/(2*(gamma-1)));
mdot_slugs = (Cd * A_actual_m2 * P0_Pa * choke / 0.4536) / g;

F_actual_lbf = mdot_slugs * Isp_GN2 * g;
Torque_actual = F_actual_lbf * r_nozzle;

% Initial Conditions (Start at 0)
phi = 0;             
omega = 0;            

% Controller Gains (PD)
Kp = 2;                       
Kd = 5;                       

% Schmitt Trigger Parameters
deadzone = 0.02;                
hysteresis = 0.01;              

% State Storage Arrays
history_phi = zeros(N, 1);
history_omega = zeros(N, 1);
history_valve = zeros(N, 1);
history_mass = zeros(N, 1);

valve_state = 0;                
pulse_timer = 0;
total_mass_used_slugs = 0;
actuation_count = 0;

%% 4. GENERATE 180-DEGREE TRACE
% We want to move 180 degrees in 10 seconds (18 deg/s average).
% We will start the maneuver at t = 1s and end at t = 11s.
trace_phi_deg = zeros(N, 1);
trace_omega_deg = zeros(N, 1);
start_time = 1.0;
duration = 10.0;
end_time = start_time + duration;
target_angle = 180.0;
sweep_rate = target_angle / duration;

for i = 1:N
    t = time(i);
    if t < start_time
        trace_phi_deg(i) = 0;
        trace_omega_deg(i) = 0;
    elseif t <= end_time
        trace_phi_deg(i) = sweep_rate * (t - start_time);
        trace_omega_deg(i) = sweep_rate;
    else
        trace_phi_deg(i) = target_angle;
        trace_omega_deg(i) = 0;
    end
end

%% 5. MAIN CLOSED-LOOP SIMULATION
for i = 1:N
    
    % Fetch dynamic reference trace for this time step
    phi_ref = trace_phi_deg(i) * deg2rad;
    omega_ref = trace_omega_deg(i) * deg2rad;
    
    % 1. Calculate Continuous Control Effort
    error_phi = phi_ref - phi;
    error_omega = omega_ref - omega;
    control_effort = (Kp * error_phi) + (Kd * error_omega);
    
    % 2. Schmitt Trigger Logic & Actuation Counter
    prev_valve = valve_state;
    
    if pulse_timer > 0
        pulse_timer = pulse_timer - dt;
    else
        if valve_state == 0
            if control_effort > deadzone
                valve_state = 1;
                pulse_timer = min_pulse_time;
            elseif control_effort < -deadzone
                valve_state = -1;
                pulse_timer = min_pulse_time;
            end
        elseif valve_state == 1
            if control_effort < (deadzone - hysteresis)
                valve_state = 0;
            end
        elseif valve_state == -1
            if control_effort > -(deadzone - hysteresis)
                valve_state = 0;
            end
        end
    end
    
    % Count Actuations (Only count when valve turns ON from OFF)
    if valve_state ~= 0 && prev_valve == 0
        actuation_count = actuation_count + 1;
    end
    
    % 3. Vehicle Dynamics
    alpha = (valve_state * Torque_actual) / Ixxp;
    omega = omega + alpha * dt;
    phi = phi + omega * dt;
    
    % 4. Propellant Consumption
    if valve_state ~= 0
        total_mass_used_slugs = total_mass_used_slugs + (mdot_slugs * dt); 
    end
    
    % 5. Log Data
    history_phi(i) = phi / deg2rad;
    history_omega(i) = omega / deg2rad;
    history_valve(i) = valve_state;
    history_mass(i) = total_mass_used_slugs * g; % Convert to lbm
end

%% 6. PLOTTING RESULTS
figure('Name', 'RCS 180-Degree Sweep Maneuver', 'Position', [100, 100, 900, 800]);

% Subplot 1: Angular Position
subplot(4,1,1);
plot(time, trace_phi_deg, 'k--', 'LineWidth', 1.5, 'DisplayName', 'Target Trace'); hold on;
plot(time, history_phi, 'b', 'LineWidth', 1.5, 'DisplayName', 'Actual Position');
ylabel('Roll Angle (deg)'); title('Angular Position'); 
legend('Location', 'southeast'); grid on;

% Subplot 2: Roll Rate
subplot(4,1,2);
plot(time, trace_omega_deg, 'k--', 'LineWidth', 1.5, 'DisplayName', 'Target Rate'); hold on;
plot(time, history_omega, 'r', 'LineWidth', 1.5, 'DisplayName', 'Actual Rate');
ylabel('Roll Rate (deg/s)'); title('Roll Rate Tracking'); 
legend('Location', 'northeast'); grid on;

% Subplot 3: Thruster Commands / Actuations
subplot(4,1,3);
stairs(time, history_valve, 'k', 'LineWidth', 1.2);
ylabel('Valve Command'); title(sprintf('Actuations: %d Total Valve Firings', actuation_count));
yticks([-1 0 1]); yticklabels({'CCW', 'OFF', 'CW'}); ylim([-1.5 1.5]); grid on;

% Subplot 4: Fuel Usage
subplot(4,1,4);
plot(time, history_mass, 'g', 'LineWidth', 1.5);
ylabel('GN2 Used (lbm)'); xlabel('Time (s)'); 
title(sprintf('Fuel Usage (Final: %.4f lbm)', history_mass(end))); grid on;

% Console Output Summary
fprintf('==============================================================\n');
fprintf(' MANEUVER SUMMARY: 180° in 10s\n');
fprintf('==============================================================\n');
fprintf('Total Valve Actuations: %d\n', actuation_count);
fprintf('Total Propellant Used:  %.4f lbm\n', history_mass(end));
fprintf('Final Roll Angle:       %.2f deg\n', history_phi(end));
fprintf('Final Roll Rate:        %.2f deg/s\n', history_omega(end));
fprintf('==============================================================\n');
%display value for alpha
% Display value for alpha
fprintf('Current Angular Acceleration: %.4f rad/s²\n', alpha);

