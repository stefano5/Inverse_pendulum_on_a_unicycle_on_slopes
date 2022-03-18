%close all

thickness = 1.7;

color_ref = 'r';
color_meas = 'b';

figure('Name', "Robotics project: Menolotto & Maugeri")

%% prima riga
subplot(3,3,1);
hold on
plot(out.qf_meas.Time, out.qf_meas.Data, color_meas, 'LineWidth', thickness)
plot(out.qf_ref.Time, out.qf_ref.Data, color_ref, 'LineWidth', thickness)
xlabel('Time (s)');
ylabel('m');
legend('meas','zero');
hold off
grid
title('q_f(t)')


subplot(3,3,2);
hold on
plot(out.theta_meas.Time, out.theta_meas.Data, color_meas,'LineWidth', thickness)
plot(out.theta_ref.Time, out.theta_ref.Data, color_ref,'LineWidth', thickness)
plot(out.theta_ref.Time, out.theta.Data*180/pi, '--k' ,'LineWidth', thickness)
xlabel('Time (s)');
ylabel('deg');
legend('estim','ref', 'real');
hold off
grid
title('theta(t) - yaw angle')


subplot(3,3,3);
hold on
plot(out.estim_phi.Time, out.estim_phi.Data, color_meas, 'LineWidth', thickness)
plot(out.real_phi.Time, out.real_phi.Data, color_ref, 'LineWidth', thickness)
xlabel('Time (s)');
ylabel('deg');
legend({'estim','real'})
title('phi(t) - pitch angle');
grid
hold off




%% seconda riga

subplot(3,3,4);
hold on
plot(out.v_avanz_meas.Time, out.v_avanz_meas.Data, color_meas,'LineWidth', thickness)
plot(out.v_avanz_ref.Time, out.v_avanz_ref.Data, color_ref,'LineWidth', thickness)
xlabel('Time (s)');
ylabel('m/s');
legend('meas','ref');
hold off
grid
title('v_f(t) - forward velocity')


subplot(3,3,5);
hold on
plot(out.theta_dot_meas.Time, out.theta_dot_meas.Data*180/pi, color_meas, 'LineWidth', thickness)
plot(out.theta_dot_ref.Time, out.theta_dot_ref.Data*180/pi, color_ref, 'LineWidth', thickness)
plot(out.nu2.Time, out.nu2.Data*180/pi, '--k', 'LineWidth', thickness)
xlabel('Time (s)');
ylabel('deg/s');
legend('meas','ref','real');
hold off
grid
title('theta dot(t) - yaw rate')


subplot(3,3,6);
hold on
plot(out.phi_dot_meas.Time,out.phi_dot_meas.Data*180/pi, color_meas,'LineWidth', thickness)
plot(out.phi_dot_ref.Time,out.phi_dot_ref.Data*180/pi, color_ref,'LineWidth', thickness)
plot(out.nu3.Time, out.nu3.Data*180/pi, '--k', 'LineWidth', thickness)
hold off
legend('meas','ref', 'real');
xlabel('Time (s)');
ylabel('deg/s');
hold off
grid
title('phi dot(t) - pitch rate')


%% terza riga

subplot(3,3,7);
hold on
plot(out.estim_alpha.Time,out.estim_alpha.Data, color_meas,'LineWidth', thickness)
plot(out.real_alpha.Time,out.real_alpha.Data, color_ref,'LineWidth', thickness)
legend('estim', 'real')
xlabel('Time (s)');
ylabel('deg');
hold off
grid
title('alpha(t) - slope angle')

subplot(3,3,8);
hold on
plot(out.taur.Time,out.taur.Data,'-k','LineWidth', thickness)
plot(out.taul.Time,out.taul.Data,'--r','LineWidth', thickness)
xlabel('Time (s)');
ylabel('N*m');
legend('tau_r(t)','tau_l(t)');
title('tau(t)')
grid
hold off

subplot(3,3,9);
hold on
plot(0,0,'-d')
hold on
plot(out.x.Data,out.y.Data,'k','LineWidth', thickness)
xlabel('x(t)');
ylabel('y(t)');
hold off
grid
title('Trajectory (m)')


%%


clear thickness color_ref color_meas
