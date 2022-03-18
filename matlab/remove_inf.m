% Robotics project, Menolotto Mariangela & Stefano Maugeri
function out_row = remove_inf( input_args )
% This script solve the issue when the plot show you outlier

threshold = 10^1;  % empirical value!

out_row = zeros(length(input_args),1);

for i=1:length(input_args)
    if abs(input_args(i)) > threshold
        out_row(i) = NaN;
    else
        out_row(i) =  input_args(i); 
    end
end

end

