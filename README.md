# Dependence
None, just download it and use it with simulink 2020b or a newer version.


# Explanation
This was a project made by Mariangela Menolotto and Stefano Maugeri as a Robotics course project for Università di Pisa. 
The goal of the project was to model and control a robot of Università di Pisa. This robot is an inverse pendulum mounted over an unicycle. At Università di Pisa, they call this robot "Alter-Ego", so sometimes you'll read "ego" inside the folders, we use the word "ego" to refer to the robot. 

Università di Pisa have already developed this robot, but it is not able to go on slopes, so they asked us (as students) to devolop a controller that let the robot walk on slopes. This was the challenge of our Robotics project.

We started from scratch, modelling an inverse pendulum over a unicycle on a splope on Mathematica. You will find the equations in "mathemtatica/dynamic and static of an inverse pendulum over a unicycle on slopes.nb".
Then we wrote the model in Simulink, computing the dynamics matrices stored on "matlab\Matrici_eq_dinamica\". 
A model based controller was developed. Two estimators were also developed: 
1. Kalman filter (EKF) 
2. Mahony filter

You'll find more tecnical information and all the implemented equations on:

		Final presentation.pptx
		
# Simulink
To run the simulation, just open the file:

		matlab/system2020b.slx

then press the "Run" button and wait until the simulation ends (a few seconds). After this, you will see the most meaningful plots.

The needed files will automaticly run when you press "run".


# Mathematica
If you want to see the simulation video, run the file:

		mathematica/visualization_matlab_simulation.nb

then evaluate the notebook and press "play".
