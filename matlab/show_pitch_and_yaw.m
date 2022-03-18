% Robotics project, Menolotto Mariangela & Stefano Maugeri
figure
hold on
plot(out.phi.Time, out.phi.Data*180/pi, 'k', 'LineWidth', 1.1)
plot(out.theta.Time, out.theta.Data*180/pi, 'r', 'LineWidth', 1.1)
xlabel('Time (s)')
ylabel('deg')
grid on
legend('pitch','yaw');
