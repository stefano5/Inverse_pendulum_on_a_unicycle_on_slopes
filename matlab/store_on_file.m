% Robotics project, Menolotto Mariangela & Stefano Maugeri
path = '../mathematica/export/';

if exist(path, 'dir') == 0
   disp("Mathematica not found"); 
end

writematrix(out.x.Data, path + "x.dat")
writematrix(out.y.Data, path + "y.dat")
writematrix(out.theta.Data, path + "theta.dat")
writematrix(out.phi.Data, path + "phi.dat")
writematrix(out.gammar.Data, path + "thetar.dat")
writematrix(out.gammal.Data, path + "thetal.dat")

writematrix(out.nu1.Data, path + "nu1.dat")
writematrix(out.nu2.Data, path + "nu2.dat")
writematrix(out.nu3.Data, path + "nu3.dat")
writematrix(out.nu1_int.Data, path + "nu1int.dat")

writematrix(out.taur.Data, path + "taur.dat")
writematrix(out.taul.Data, path + "taul.dat")

writematrix(out.alpha_real.Data, path + "alpha.dat")
%writematrix(alpha, path + "alpha.dat")

