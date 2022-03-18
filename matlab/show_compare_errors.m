% Robotics project, Menolotto Mariangela & Stefano Maugeri
thickness = 1.5;

color_ref = '--r';
color_meas = '-k';
color_ = 'k';

choose_graph_to_plot = 3; % choose_graph_to_plot = 1 = kalman, choose_graph_to_plot=2 mahony, choose_graph_to_plot=3 entrambi


%% Angles
figure('Name', "Robotics project: Menolotto & Maugeri")

% 

subplot(3,1,1);
hold on
if choose_graph_to_plot == 1
    plot(out.kalman_alpha_err.Time,out.kalman_alpha_err.Data, color_,'LineWidth', thickness)
    legend('kalman')
elseif choose_graph_to_plot == 2
    plot(out.mahony_alpha_err.Time,out.mahony_alpha_err.Data, color_,'LineWidth', thickness)
    legend('mahony')
else
    plot(out.kalman_alpha_err.Time,out.kalman_alpha_err.Data, color_meas,'LineWidth', thickness)
    plot(out.mahony_alpha_err.Time,out.mahony_alpha_err.Data, color_ref,'LineWidth', thickness)    
    legend('kalman', 'mahony')
end
xlabel('Time (s)');
ylabel('deg');
hold off
grid
title('Error in alpha(t) - slope angle')


subplot(3,1,2);
hold on
if choose_graph_to_plot == 1
    plot(out.kalman_theta_err.Time, out.kalman_theta_err.Data, color_,'LineWidth', thickness)
    legend('kalman')
elseif choose_graph_to_plot == 2
    plot(out.mahony_theta_err.Time, out.mahony_theta_err.Data, color_,'LineWidth', thickness)
    legend('mahony')
else
    plot(out.kalman_theta_err.Time, out.kalman_theta_err.Data, color_meas,'LineWidth', thickness)
    plot(out.mahony_theta_err.Time, out.mahony_theta_err.Data, color_ref,'LineWidth', thickness)
    legend('kalman', 'mahony')
end
xlabel('Time (s)');
ylabel('deg');
hold off
grid
title('Error in theta(t) - yaw angle')


p41=subplot(3,1,3);
hold on
if choose_graph_to_plot == 1
    plot(out.kalman_phi_err.Time, out.kalman_phi_err.Data, color_, 'LineWidth', thickness)
    legend('kalman')
elseif choose_graph_to_plot == 2
    plot(out.mahony_phi_err.Time, out.mahony_phi_err.Data, color_, 'LineWidth', thickness)
    legend('mahony')
else
    plot(out.kalman_phi_err.Time, out.kalman_phi_err.Data, color_meas, 'LineWidth', thickness)
    plot(out.mahony_phi_err.Time, out.mahony_phi_err.Data, color_ref, 'LineWidth', thickness)
    legend('kalman', 'mahony')
end
xlabel('Time (s)');
ylabel('deg');
title('phi(t) - pitch angle');
grid
hold off


%% Velocities
figure('Name', "Robotics project: Menolotto & Maugeri")

% 

subplot(3,1,1);
hold on
if choose_graph_to_plot == 1
    plot(out.kalman_phidot_err.Time,out.kalman_phidot_err.Data, color_,'LineWidth', thickness)
    legend('kalman')
elseif choose_graph_to_plot == 2
    plot(out.mahony_phidot_err.Time,out.mahony_phidot_err.Data, color_,'LineWidth', thickness)
    legend('mahony')
else
    plot(out.kalman_phidot_err.Time,out.kalman_phidot_err.Data, color_meas,'LineWidth', thickness)
    plot(out.mahony_phidot_err.Time,out.mahony_phidot_err.Data, color_ref,'LineWidth', thickness)
    legend('kalman', 'mahony')
end
xlabel('Time (s)');
ylabel('deg/s');
hold off
grid
title('Error in phidot(t) - pitch rate')


subplot(3,1,2);
hold on
if choose_graph_to_plot == 1
    plot(out.kalman_thetadot_err.Time, out.kalman_thetadot_err.Data, color_,'LineWidth', thickness)
    legend('kalman')
elseif choose_graph_to_plot == 2
    plot(out.mahony_thetadot_err.Time, out.mahony_thetadot_err.Data, color_,'LineWidth', thickness)
    legend('mahony')
else
    plot(out.kalman_thetadot_err.Time, out.kalman_thetadot_err.Data, color_meas,'LineWidth', thickness)
    plot(out.mahony_thetadot_err.Time, out.mahony_thetadot_err.Data, color_ref,'LineWidth', thickness)
    legend('kalman', 'mahony')
end
xlabel('Time (s)');
ylabel('deg/s');
hold off
grid
title('Error in thetadot(t) - yaw rate')

%%
clear thickness color_ref color_meas color_ choose_graph_to_plot

