% Robotics project, Menolotto Mariangela & Stefano Maugeri

%%
thickness = [2.7, 2.5 2.0];

color_kalman_meas = '--r';
color_mahony_meas = '--b';
color_ref = '-k';

kalman_only = 0;


figure('Name', "Robotics project: Menolotto & Maugeri")

%%
%% prima riga
subplot(3,1,1);
hold on
plot(out.alpha_real.Time,out.alpha_real.Data*180/pi, color_ref,'LineWidth', thickness(1))
if kalman_only == 0
    plot(out.alpha_esimt_mahony.Time,out.alpha_esimt_mahony.Data, color_mahony_meas,'LineWidth', thickness(2))
end
plot(out.alpha_esimt_kalman.Time,out.alpha_esimt_kalman.Data, color_kalman_meas,'LineWidth', thickness(3))
if kalman_only == 0
    legend('real', 'mahony', 'kalman')
%    legend('real', 'mahony')
else
    legend('real', 'kalman')    
end
xlabel('Time (s)');
ylabel('deg');
hold off
grid
title('alpha(t) - slope angle')


subplot(3,1,2);
hold on
plot(out.theta.Time, out.theta.Data*180/pi, color_ref,'LineWidth', thickness(1))
if kalman_only == 0
    plot(out.theta_esimt_mahony.Time,out.theta_esimt_mahony.Data, color_mahony_meas,'LineWidth', thickness(2))
end
plot(out.theta_esimt_kalman.Time,out.theta_esimt_kalman.Data, color_kalman_meas,'LineWidth', thickness(3))
xlabel('Time (s)');
ylabel('deg');
if kalman_only == 0
    legend('real', 'mahony', 'kalman')
%    legend('real', 'mahony')
else
    legend('real', 'kalman')    
end
hold off
grid
title('theta(t) - yaw angle')


subplot(3,1,3);
hold on
plot(out.phi.Time, out.phi.Data*180/pi, color_ref, 'LineWidth', thickness(1))
if kalman_only == 0
    plot(out.phi_esimt_mahony.Time,out.phi_esimt_mahony.Data, color_mahony_meas,'LineWidth', thickness(2))
end
plot(out.phi_esimt_kalman.Time,out.phi_esimt_kalman.Data, color_kalman_meas,'LineWidth', thickness(3))
xlabel('Time (s)');
ylabel('deg');
if kalman_only == 0
    legend('real', 'mahony', 'kalman')
%    legend('real', 'mahony')
else
    legend('real', 'kalman')    
end
title('phi(t) - pitch angle');
grid
hold off

%% plot derivate
figure('Name', "Robotics project: Menolotto & Maugeri")


subplot(2,1,1);
hold on
plot(out.nu2.Time, out.nu2.Data*180/pi, color_ref,'LineWidth', thickness(1))
if kalman_only == 0
    plot(out.thetadot_esimt_mahony.Time,out.thetadot_esimt_mahony.Data, color_mahony_meas,'LineWidth', thickness(2))
end
plot(out.thetadot_esimt_kalman.Time,out.thetadot_esimt_kalman.Data, color_kalman_meas,'LineWidth', thickness(3))
xlabel('Time (s)');
ylabel('deg/s');
if kalman_only == 0
    legend('real', 'mahony', 'kalman')
%    legend('real', 'mahony')
else
    legend('real', 'kalman')    
end
hold off
grid
title('theta dot(t) - yaw rate')


subplot(3,1,3);
hold on
plot(out.nu3.Time, out.nu3.Data*180/pi, color_ref, 'LineWidth', thickness(1))
if kalman_only == 0
    plot(out.phidot_esimt_mahony.Time,out.phidot_esimt_mahony.Data, color_mahony_meas,'LineWidth', thickness(2))
end
plot(out.phidot_esimt_kamlan.Time,out.phidot_esimt_kamlan.Data, color_kalman_meas,'LineWidth', thickness(3))
xlabel('Time (s)');
ylabel('deg/s');
if kalman_only == 0
    legend('real', 'mahony', 'kalman')
%    legend('real', 'mahony')
else
    legend('real', 'kalman')    
end
title('phi dot(t) - pitch rate');
grid
hold off

