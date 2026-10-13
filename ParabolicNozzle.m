%% Parabolic Nozzle Calculations (many many many calculations)
clear; 
clc; 
close all;

%Given
Ixxp = 252099.557 * 0.00029263965; %kg*m^2
MomentArm = 6.5 * 0.0254; %in -> m
SvAmount = 2; %2 correct cause they counter each other
delta_phi_deg = 5; %assumed
PressureSupply = 210.0 * 6894.76; %psi -> pa
D_inlet = 0.250 * 0.0254; %in -> m

%GN2
gamma = 1.40;
GasConstantR = 296.8; %J/kg*K
g0 = 9.80665; %m/s^2

%Assumtions
t = 4.0; %s
T0 = 293.15; %K
ConvergentHalfAngle = 30.0; %Degrees
theta_i = 10.0; %Rao Bell initial expansion angle, degrees
theta_e = 7.0;  %Rao Bell exit parallel angle, degrees (Optimized parallel lip)
PressureLoss  = 0.92;   %8 percent drop
SeaLevelPressure = 101325; %Pa
DisturbanceTorque = 2.0; %N*m
margin = 2.0;
WallThickness = 3.5; %mm for a 3D print

%Angular Acceleration
AlphaRequired = (4 * deg2rad(delta_phi_deg)) / (t^2);
MinAlpha  = (DisturbanceTorque * margin) / Ixxp;
alpha = max(AlphaRequired, MinAlpha);

%Required Maneuver Target
RequiredTorque = Ixxp * alpha; %N*m
RequiredThrust = RequiredTorque / (MomentArm * SvAmount); %N per nozzle

%Ideal Thermodynamic Expansion Sizing (P_exit = P_ambient for Max Torque)
P0 = PressureSupply * PressureLoss;
ExitMach = sqrt((2 / (gamma - 1)) * ((P0 / SeaLevelPressure)^((gamma - 1) / gamma) - 1));
Cf = sqrt((2 * gamma^2 / (gamma - 1)) * (2 / (gamma + 1))^((gamma + 1) / (gamma - 1)) * (1 - (SeaLevelPressure / P0)^((gamma - 1) / gamma)));

ThroatChokedArea = RequiredThrust / (P0 * Cf);
ThroatDiameterArea = 2 * sqrt(ThroatChokedArea / pi);
ThroatExitArea = (1 / ExitMach) * ((2 / (gamma + 1)) * (1 + (gamma - 1) / 2 * ExitMach^2))^((gamma + 1) / (2 * (gamma - 1)));
ThroatExitDiameter  = 2 * sqrt((ThroatChokedArea * ThroatExitArea) / pi);

%Divergence Factor & Maximum Torque Output
lambda = (1 + cos(deg2rad(theta_e))) / 2; %99.63% Efficiency
GeneratedThrust = lambda * (P0 * ThroatChokedArea * Cf); 
SingleNozzleTorque = GeneratedThrust * MomentArm; 
TotalGeneratedTorque = SingleNozzleTorque * SvAmount; 

%Mass Flow
ve = lambda * sqrt(2 * T0 * GasConstantR * (gamma / (gamma - 1)) * (1 - (SeaLevelPressure / P0)^((gamma - 1) / gamma))); 
Isp = ve / g0; 
mdot = GeneratedThrust / ve;                      
mdotConverted = mdot * 1000;                       
rho = 1.165;                                  
mdotSCFM = (mdot / rho) * 2118.88;        
totalmdotConverted  = mdotConverted * SvAmount;
totalmdotSCFM = mdotSCFM * SvAmount;

%% 3D Generation (Smooth C1 Rao Parabolic Bell Profile)
R_t = ThroatDiameterArea / 2; 
R_e = ThroatExitDiameter / 2; 
R_inlet = D_inlet / 2; 

beta = deg2rad(ConvergentHalfAngle);
t_i = deg2rad(theta_i);
t_e = deg2rad(theta_e);

R_u_up = 1.5 * R_t; 
R_u_dn = 1.5 * R_t; 

% 1. Upstream Arc
alpha_up = linspace(-beta, 0, 30);
x_arc_up = R_u_up * sin(alpha_up);
r_arc_up = R_t + R_u_up * (1 - cos(alpha_up));

% 2. Convergent Funnel
x_touch = x_arc_up(1);
r_touch = r_arc_up(1);
HLIF = (R_inlet - r_touch) / tan(beta); 
x_conv = linspace(-(HLIF + abs(x_touch)), x_touch, 50);
r_conv = R_inlet - (x_conv - x_conv(1)) * tan(beta);

% 3. Downstream Arc
alpha_dn = linspace(0, t_i, 30);
x_arc_dn = R_u_dn * sin(alpha_dn);
r_arc_dn = R_t + R_u_dn * (1 - cos(alpha_dn));

% 4. Parabolic Bell Curve (Accelerated Expansion -> Shorter Length!)
x_a = x_arc_dn(end);
r_a = r_arc_dn(end);
m_i = tan(t_i);
m_e = tan(t_e);

HLEB_prime = (R_e - r_a) / ((m_i + m_e) / 2); % Parabolic segment length
a_prime = (m_e - m_i) / (2 * HLEB_prime);

N_bell = 100;
x_prime_bell = linspace(0, HLEB_prime, N_bell);
r_bell = a_prime * (x_prime_bell.^2) + m_i * x_prime_bell + r_a;
x_bell = x_prime_bell + x_a;

x_total_m = [x_conv(1:end-1), x_arc_up(1:end-1), x_arc_dn(1:end-1), x_bell];
r_inner_m = [r_conv(1:end-1), r_arc_up(1:end-1), r_arc_dn(1:end-1), r_bell];

x_total = x_total_m * 1000; 
r_inner = r_inner_m * 1000; 
r_outer = r_inner + WallThickness; 

TotalLength = abs(x_total_m(1)) + x_total_m(end); 

%% 3D Mesh
N_theta = 60;
theta = linspace(0, 2*pi, N_theta);

[X_mesh, THETA_mesh] = meshgrid(x_total, theta);
[R_inside_mesh, ~] = meshgrid(r_inner, theta);
[R_outside_mesh, ~] = meshgrid(r_outer, theta);

Y_inner = R_inside_mesh  .* cos(THETA_mesh);
Z_inner = R_inside_mesh  .* sin(THETA_mesh);
Y_outer = R_outside_mesh .* cos(THETA_mesh);
Z_outer = R_outside_mesh .* sin(THETA_mesh);

%% Display
fprintf('ALPHA\n');
fprintf('Alpha Maneuver = %f rad/s^2 (%f deg/s^2)\n', AlphaRequired, rad2deg(AlphaRequired));
fprintf('Alpha Disturb = %f rad/s^2 (%f deg/s^2)\n', MinAlpha, rad2deg(MinAlpha));
fprintf('Alpha = %f rad/s^2 (%f deg/s^2)\n', alpha, rad2deg(alpha));
fprintf('\n');
fprintf('THRUST AND TORQUE\n');
fprintf('Divergence Efficiency (lambda) = %f (%.2f%%)\n', lambda, lambda * 100);
fprintf('Required Roll Torque      = %f N*m (%f in*lbf)\n', RequiredTorque, RequiredTorque * 8.85075);
fprintf('Single Nozzle Torque      = %f N*m (%f in*lbf)\n', SingleNozzleTorque, SingleNozzleTorque * 8.85075);
fprintf('Total Generated Torque    = %f N*m (%f in*lbf)\n', TotalGeneratedTorque, TotalGeneratedTorque * 8.85075);
fprintf('Generated Thrust / Nozzle = %f N (%f lbf)\n', GeneratedThrust, GeneratedThrust * 0.224809);
fprintf('\n');
fprintf('GAS FLOW\n');
fprintf('Exhaust Velocity (ve) = %f m/s\n', ve);
fprintf('Specific Impulse (Isp) = %f s\n', Isp);
fprintf('Single Nozzle Mass Flow = %f g/s (%f SCFM)\n', mdotConverted, mdotSCFM);
fprintf('Total Mass Flow (2 Svs) = %f g/s (%f SCFM)\n', totalmdotConverted, totalmdotSCFM);
fprintf('\n');
fprintf('NOZZLE OPTIMIZED DIMENSIONS\n');
fprintf('Throat Diameter (Dt) = %f mm (%f in)\n', ThroatDiameterArea*1000, ThroatDiameterArea/0.0254);
fprintf('Exit Diameter (De) =  %f mm (%f in)\n', ThroatExitDiameter*1000, ThroatExitDiameter/0.0254);
fprintf('Total Nozzle Length (L_tot) = %f mm (%f in)\n', TotalLength*1000, TotalLength/0.0254);
fprintf('Outer Wall Thickness = %f mm (%f in)\n', WallThickness, WallThickness/25.4);

%% Figure
figure('Color', [1 1 1]);
InnerSurface = surf(X_mesh, Y_inner, Z_inner); hold on;
set(InnerSurface, 'FaceColor', [1 0.5 0.8], 'EdgeColor', 'none', 'FaceAlpha', 0.9);
OuterSurface = surf(X_mesh, Y_outer, Z_outer);
set(OuterSurface, 'FaceColor', [0.5 0.5 0.9], 'EdgeColor', 'none', 'FaceAlpha', 0.35);

camlight head; 
lighting gouraud; 
axis equal; 
grid on; 
view(35, 20);
title('Thruster Design', 'FontSize', 12);
xlabel('X (mm)'); ylabel('Y (mm)'); zlabel('Z (mm)');
legend([InnerSurface, OuterSurface], {'Inner Surface', 'Outer Surface'}, 'Location', 'best');
rotate3d on;



%% =========================================================================
%% SIEMENS NX EXPORT MODULE (FIXED FOR STUDIO SPLINE)
%% =========================================================================

% % 1. Remove duplicate points at the throat junction
% [x_unique, idx] = unique(x_total, 'stable');
% r_in_unique     = r_inner(idx);
% r_out_unique    = r_outer(idx);
% 
% % 2. Write Inner Contour (.pt file)
% fid_in = fopen('nx_inner_contour.dat', 'w');
% for i = 1:length(x_unique)
%     fprintf(fid_in, '%.6f %.6f %.6f\n', x_unique(i), r_in_unique(i), 0.0);
% end
% fclose(fid_in);
% 
% % 3. Write Outer Contour (.pt file)
% fid_out = fopen('nx_outer_contour.dat', 'w');
% for i = 1:length(x_unique)
%     fprintf(fid_out, '%.6f %.6f %.6f\n', x_unique(i), r_out_unique(i), 0.0);
% end
% fclose(fid_out);
% 
% fprintf('\n[SIEMENS NX EXPORT SUCCESSFUL]:\n');
% fprintf(' -> "nx_inner_contour.pt" generated (%d unique points).\n', length(x_unique));
% fprintf(' -> "nx_outer_contour.pt" generated (%d unique points).\n', length(x_unique));