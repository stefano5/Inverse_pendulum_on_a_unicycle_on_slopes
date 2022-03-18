clear all
close 
clc

parametriEgo

addpath('Matrici_eq_dinamica')

fprintf('Generazione matrici simulink...\n')

syms alpha real
syms x y theta phi thetar thetal taur taul real
syms xdot ydot thetadot phidot thetardot thetaldot real



%Vettori delle coordinate libere e delle quasi velocità
q = [x; y; theta; phi; thetar; thetal];
qdot = [xdot; ydot; thetadot; phidot; thetardot; thetaldot];

%%
%Definizione matrici utili

%Jacobiano
Jr = [1, 0, -l*sin(theta), 0, 0, 0;
    0, 1, l*cos(theta), 0, 0, 0;
    0, 0, 0, 0, 0, 0;
    0, 0, 0, 1, 1, 0;
    0, 0, sin(phi), 0, 0, 0;
    0, 0, cos(phi), 0, 0, 0];

Jl = [1, 0, l*sin(theta), 0, 0, 0;
    0, 1, -l*cos(theta), 0, 0, 0;
    0, 0, 0, 0, 0, 0;
    0, 0, 0, 1, 0, 1;
    0, 0, sin(phi), 0, 0, 0;
    0, 0, cos(phi), 0, 0, 0];

Jc = [1, 0, L*cos(theta)*sin(phi), L*sin(theta)*cos(phi), 0, 0;
    0, 1, L*sin(theta)*sin(phi), -L*cos(theta)*cos(phi), 0, 0;
    0, 0, 0, -L*sin(phi), 0, 0;
    0, 0, 0, 1, 0, 0;
    0, 0, sin(phi), 0, 0, 0;
    0, 0, cos(phi), 0, 0, 0];

J = blkdiag(Jr,Jl,Jc);


%% Matrice di massa
Jrmat = formula(Jr);
Jlmat = formula(Jl);
Jcmat = formula(Jc);

B = mw*Jrmat(1:3,:)'*Jrmat(1:3,:)+Jrmat(4:6,:)'*Iw*Jrmat(4:6,:)+ ...
    mw*Jlmat(1:3,:)'*Jlmat(1:3,:)+Jlmat(4:6,:)'*Iw*Jlmat(4:6,:)+ ...
    mb*Jcmat(1:3,:)'*Jcmat(1:3,:)+Jcmat(4:6,:)'*Ib*Jcmat(4:6,:);

%% Matrice di Coriolis
C = sym(zeros(6,6));

for i=1:6
    for j=1:6
        for k=1:6
            C(i,j) = C(i,j) + 0.5*(diff(B(i,j),q(k)) + diff(B(i,k),q(j)) - diff(B(j,k),q(i)))*qdot(k);
        end
    end
end


%% Matrice delle forze gravitazionali
G = sym(zeros(6,1));

rot_is = [1,0,0; 0,cos(-alpha),-sin(-alpha); 0, sin(-alpha), cos(-alpha)];


for i=1:6
    G(i) = -mw*(rot_is*g)'*(Jrmat(1:3,i)+Jlmat(1:3,i)) - mb*(rot_is*g)'*Jcmat(1:3,i);
end

%% Forze generalizzate
Q = [0; 0; 0; 0; taur; taul];

%Matrice Pfaffiana e base del suo nullo
A = [cos(theta), sin(theta), 0, 0, 0, 0;
    1, 0, -l*sin(theta), -r*sin(theta), -r*sin(theta), 0;
    0, 1, l*cos(theta), r*cos(theta), r*cos(theta), 0;
    1, 0, l*sin(theta), -r*sin(theta), 0, -r*sin(theta);
    0, 1, -l*cos(theta), r*cos(theta), 0, r*cos(theta)];

%% 
fprintf('Matrici calcolate...\n')

a = input('Vuoi sovrascrivere le matrici della dinamica esistenti (s/n)? ','s');

if strcmp(a, 's') 
    matlabFunction(B, 'File','Matrici_eq_dinamica/B_dynamic_matrix.m');
    matlabFunction(C, 'File','Matrici_eq_dinamica/C_dynamic_matrix.m');
    matlabFunction(G, 'File','Matrici_eq_dinamica/G_dynamic_vector.m');
    %matlabFunction(S, 'File','Matrici_eq_dinamica/S_dynamic_matrix.m');
    fprintf('\nMatrici NL sovrascritte nel path [Matrici_eq_dinamica/]\n')
else
    fprintf('\nMatrici NL generate nel WS ma non sovrascritte\n')
end




