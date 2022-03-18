% Robotics project, Menolotto Mariangela & Stefano Maugeri
%% gain for signals from model
fprintf('Gain for sensors\n')
%% con modello nel controllo ideale
% kp_e_nu_speed = 1;
% ki_e_nu_speed = 0.1;
% 
% kp_e_nu_thetadot = 2.2;
% kp_e_nu_phidot = 2;
% 
% k_e_qf = 0.05;
% 
% kp_e_theta = 0.37;

%% con modello nel controllo reale, dati con mahony
% kp_e_nu_speed = 5; % pre= 4
% ki_e_nu_speed = 0;
% 
% kp_e_nu_thetadot = 10; % pre= 7
% kp_e_nu_phidot = 6;   % pre= 9
% 
% k_e_qf = 0.9;
% 
% kp_e_theta = 30;       % pre = 9

%% con modello nel controllo reale, dati con kalman. con CI = 0
kp_e_nu_speed = 6;      % pre 9
ki_e_nu_speed = 2.5;    %
kp_e_nu_phidot = 7;   % pre 8

kp_e_nu_thetadot = 7;   % pre 7

k_e_qf = 0.1;

kp_e_theta = 40;       % pre = 40
%% kalman, con CI != 0
% kp_e_nu_speed = 9;
% ki_e_nu_speed = 1;
% 
% kp_e_nu_thetadot = 50; 
% kp_e_nu_phidot = 13;
% 
% k_e_qf = 0.1;
% 
% kp_e_theta = 40;


