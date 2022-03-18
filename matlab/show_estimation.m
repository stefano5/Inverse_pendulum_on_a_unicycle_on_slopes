% Robotics project, Menolotto Mariangela & Stefano Maugeri
%%
thickness = 1.1;
%close all

color_ref = 'b';
color_meas = 'r';

figure

%% prima riga
p23=subplot(3,1,1);
hold on
plot(out.estim_alpha.Time,out.estim_alpha.Data, color_meas,'LineWidth', thickness)
plot(out.real_alpha.Time,out.real_alpha.Data, color_ref,'LineWidth', thickness)
legend('estimation', 'real')
xlabel('Time (s)');
ylabel('deg');
hold off
grid
title('alpha(t) - slope angle')


p12=subplot(3,1,2);
hold on
plot(out.theta_meas.Time, out.theta_meas.Data, color_meas,'LineWidth', thickness)
plot(out.theta.Time, out.theta.Data*180/pi, color_ref,'LineWidth', thickness)
xlabel('Time (s)');
ylabel('deg');
legend('estimation','real');
hold off
grid
title('theta(t) - yaw angle')


p41=subplot(3,1,3);
hold on
plot(out.estim_phi.Time, out.estim_phi.Data, color_meas, 'LineWidth', thickness)
plot(out.real_phi.Time, out.real_phi.Data, color_ref, 'LineWidth', thickness)
xlabel('Time (s)');
ylabel('deg');
legend('estimation', 'real');
title('phi(t) - pitch angle');
grid
hold off
