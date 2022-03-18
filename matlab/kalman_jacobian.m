%%
syms alpha theta phi thetadot phidot xdotdot ydotdot;

x = [alpha theta phi thetadot phidot xdotdot ydotdot];

m_e = [0.238836 -0.010851 0.392423];

mx=m_e(1);
my=m_e(2);
mz=m_e(3);


y = sym(zeros(9,1));
g = 9.81;

y(1) = x(5);
y(2) = sin(x(3))*x(4);
y(3) = cos(x(3))*x(4);
y(4) = (sin(x(1))*sin(x(2))*g + cos(x(2))*x(6) + sin(x(2))*x(7));
y(5) = ((cos(x(2))*cos(x(3))*sin(x(1)) + cos(x(1))*sin(x(3)))*g - cos(x(3))*sin(x(2))*x(6) + cos(x(2))*cos(x(3))*x(7));
y(6) = ((cos(x(1))*cos(x(3)) - sin(x(1))*cos(x(2))*sin(x(3)) )*g + sin(x(3))*sin(x(2))*x(6) - cos(x(2))*sin(x(3))*x(7));
y(7) = (mx*cos(x(2)) + (my*cos(x(1))+mz*sin(x(1)))*sin(x(2)));
y(8) = (mz*cos(x(2))*cos(x(3))*sin(x(1)) - mx*cos(x(3))*sin(x(2)) - my*sin(x(1))*sin(x(3)) + cos(x(1))*( my*cos(x(2))*cos(x(3)) + mz*sin(x(3)) )   );
y(9) = ( cos(x(3))* (mz*cos(x(1)) - my*sin(x(1))) - cos(x(2))*(my*cos(x(1))+mz*sin(x(1)))*sin(x(3))+ mx*sin(x(2))*sin(x(3)) );


jacobian(y,x)


