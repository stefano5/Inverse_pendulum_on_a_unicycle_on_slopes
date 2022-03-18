% Robotics project, Menolotto Mariangela & Stefano Maugeri
close all

%% autoplot is enable
if auto_plot == 0
    fprintf('Warning: autoplot disabled\nTo enable it set: auto_plot = 1\n');
    show_compare_estimation
    store_on_file
   return 
end


%%

thickness = 1.6;

figure('Name', "Robotics project: Menolotto & Maugeri")

%% prima riga
p11=subplot(4,3,1);
plot(out.x.Time,out.x.Data,'k','LineWidth', thickness)
xlabel('Time (s)');
ylabel('m');
grid
title('x(t)')


p12=subplot(4,3,2);
plot(out.y.Time,out.y.Data,'k','LineWidth', thickness)
xlabel('Time (s)');
ylabel('m');
grid
title('y(t)')

p13=subplot(4,3,3);
plot(out.nu1_int.Time,out.nu1_int.Data,'k','LineWidth', thickness)
xlabel('Time (s)');
ylabel('m');
grid
title('q_f(t)')


%% seconda riga

p21=subplot(4,3,4);
hold on
plot(out.gammar.Time,out.gammar.Data*180/pi,'-k','LineWidth', thickness)
hold on
plot(out.gammal.Time,out.gammal.Data*180/pi,'--r','LineWidth', thickness)
legend('gamma_r', 'gamma_l')
xlabel('Time (s)');
ylabel('deg');
hold off
grid
title('gamma_r(t) and gamma_r(t)')

p22=subplot(4,3,5);
plot(out.phi.Time,out.phi.Data*180/pi,'k','LineWidth', thickness)
xlabel('Time (s)');
ylabel('deg');
grid
title('phi(t)')

p23=subplot(4,3,6);
plot(out.theta.Time,out.theta.Data*180/pi,'k','LineWidth', thickness)
xlabel('Time (s)');
ylabel('deg');
grid
title('theta(t) - yaw angle')


%% terza riga

p31=subplot(4,3,7);
plot(out.nu1.Time,out.nu1.Data,'k','LineWidth', thickness)
xlabel('Time (s)');
ylabel('m/s');
grid
title('nu_1(t) - forward velocity (m/s)')

p32=subplot(4,3,8);
plot(out.nu2.Time,out.nu2.Data*180/pi,'k','LineWidth', thickness)
xlabel('Time (s)');
ylabel('deg/s');
grid
title('nu_2(t) - theta dot')

p33=subplot(4,3,9);
plot(out.nu3.Time,out.nu3.Data*180/pi,'k','LineWidth', thickness)
xlabel('Time (s)');
ylabel('deg/s');
grid
title('nu_3(t) - phi dot')

%% quarta riga

p41=subplot(4,3,10);
plot(out.taur.Time,out.taur.Data,'k','LineWidth', thickness)
xlabel('Time (s)');
ylabel('N*m');
grid
title('tau_r(t)')

p42=subplot(4,3,11);
plot(out.taul.Time,out.taur.Data,'k','LineWidth', thickness)
xlabel('Time (s)');
ylabel('N*m');
grid
title('tau_l(t)')

p43=subplot(4,3,12);
hold on
plot(0,0,'-d')
hold on
plot(out.x.Data,out.y.Data,'k','LineWidth', thickness)
xlabel('x(t)');
ylabel('y(t)');
hold off
grid
title('Trajectory (m)')


clear thickness

%%
show_results_controller
show_compare_estimation % real signals, estim signals by mahony, estim signals by kalman
show_compare_errors


%%

store_on_file


