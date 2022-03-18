% Robotics project, Menolotto Mariangela & Stefano Maugeri
%%
clear
close
clc

addpath('Matrici_eq_dinamica')
addpath('Sistema_SS')

%% Parametri fisici
l = 0.248;
L = 0.379;
r = 0.13;
mb = 21.7+0.536*10+0.381*2;
mw = 1.6;

%syms l L r mb mw real


tau_max = 11; % N*m, da "An integrated dynamic fall protection and recovery system for two-wheeled humanoids"
maximum_speed = 0.3; % m/s, avarage speed: 0.25 m/s  


Ib = [1.7 0 0;
    0 1.86 0;
    0 0 0.22];
Iw = [5.3 0 0;
    0 3.21 0;
    0 0 3.21]*10^(-3);

g = [0; 0; -9.81];

Ts = 1/100;
TsGraph = 1/100;
TsController = 1/100;
initial_conditions = [0,0,0*pi/180,0*pi/180,0,0]

fprintf('Parameters loaded\n')


%% Sensors
% data from: https://invensense.tdk.com/wp-content/uploads/2015/02/RM-MPU-9250A-00-v1.6.pdf

rng('shuffle'); 
seedAcc1 = ceil(rand()*10);
seedAcc2 = ceil(rand()*10);

seedGyro1 = ceil(rand()*10);
seedGyro2 = ceil(rand()*10);
 
accNoiseDens = 300; % ug/rt(Hz)
totAccNoisePower=(accNoiseDens* 10^-6 * 9.8)^2;

gyroNoiseDens = 0.1; % °/s rt(Hz)
totGyroNoisePower = (gyroNoiseDens * pi/180)^2;
resolution_gyro = 1/131;

campmag=[0.238836 -0.010851 0.392423];


campnormalized = campmag/sqrt(campmag(1)^2+campmag(2)^2+campmag(3)^2);



%% Control gain

%ego_control_gains_model
ego_control_gains_sensors


%% kalman parameters
P0 = 1500*eye(7);
% alpha, theta, phi, theta dot, phi dot, x dot dot, y dot dot
x0 = zeros(7,1);
% x0(1) = 15*pi/180;
% x0(3) = 10*pi/180;

%% auto plot
auto_plot = 1;
