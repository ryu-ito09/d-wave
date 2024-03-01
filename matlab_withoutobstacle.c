angle = [0,0,4;0,0,4;1,1,3;2,1,2;2,2,2;3,3,2;3,3,2;]
close all;
f1 = figure;
f1.Position = [0 50 600 580];
xo1 = [33.0 38.2];
yo1 = [70.0 71.5];
xo2 = [38.2 43.4];
yo2 = [71.5 73.0];
xo3 = [43.4 48.6];
yo3 = [73.0 74.5];
xo4 = [48.6 53.8];
yo4 = [74.5 76.0];
xo5 = [53.8 59.0];
yo5 = [76.0 77.5];
xo6 = [59.0 64.2];
yo6 = [77.5 79.0];
xo7 = [64.2 69.4];
yo7 = [79.0 80.5];
xo8 = [69.4 74.6];
yo8 = [80.5 82.0];
xo9 = [74.6 79.8];
yo9 = [82.0 83.5];
xo10 = [79.8 85.0];
yo10 = [83.5 85.0];
zo = [-100,40];
[ini0 ini1 ini2] = kinematics(22.5*angle(1,1),22.5*angle(1,2),45.0*angle(1,3));
x_ini = [ini0(1) ini1(1) ini2(1)];
y_ini = [ini0(2) ini1(2) ini2(2)];
z_ini = [ini0(3) ini1(3) ini2(3)];
[tgt0 tgt1 tgt2] = kinematics(22.5*angle(7,1),22.5*angle(7,2),45.0*angle(7,3));
x_tgt = [tgt0(1) tgt1(1) tgt2(1)];
y_tgt = [tgt0(2) tgt1(2) tgt2(2)];
z_tgt = [tgt0(3) tgt1(3) tgt2(3)];
%1回目
%set initial angles
th1_init = 22.5*angle(1,1);
th2_init = 22.5*angle(1,2);
th3_init = 45*angle(1,3);

th_1 = 22.5*angle(2,1);
th_2 = 22.5*angle(2,2);
th_3 = 45*angle(2,3);
%Calculate the trajectory of the robot arm
[th1 th2 th3] = traj3(th1_init,th2_init,th3_init,th_1,th_2,th_3);
%Vizualize
l = length(th1);
frames_per_second = 15;
r = rateControl(frames_per_second)
for i=1:l
    [pos3,pos2,pos1] = kinematics(th1(i),th2(i),th3(i));
    xp = [pos1(1) pos2(1) pos3(1)];
    yp = [pos1(2) pos2(2) pos3(2)];
    zp = [pos1(3) pos2(3) pos3(3)];
    figure(f1);
    p = plot3(xp,yp,zp,"-or","MarkerSize",4,"LineWidth",5);
    p.Color = "blue";
    hold on;
    p_ini = plot3(x_ini,y_ini,z_ini,"-or","MarkerSize",4,"LineWidth",5);
    p_ini.Color = "cyan";
    p_ini.Color(4) = 0.2;
    p_tgt = plot3(x_tgt,y_tgt,z_tgt,"-or","MarkerSize",4,"LineWidth",5);
    p_tgt.Color = "green";
    p_tgt.Color(4) = 0.2;
    hold off;
    view(100,45);
    xlim([-100 200]);
    ylim([-100 200]);
    zlim([-100 200]);
    xlabel('x')
    ylabel('y')
    zlabel('z')
    grid on
    axis square
    waitfor(r);

    
end

%2回目
%set initial angles
th1_init = 22.5*angle(2,1);
th2_init = 22.5*angle(2,2);
th3_init = 45*angle(2,3);

th_1 = 22.5*angle(3,1);
th_2 = 22.5*angle(3,2);
th_3 = 45*angle(3,3);
%Calculate the trajectory of the robot arm
[th1 th2 th3] = traj3(th1_init,th2_init,th3_init,th_1,th_2,th_3);
%Vizualize
l = length(th1);
frames_per_second = 15;
r = rateControl(frames_per_second)
for i=1:l
    [pos3,pos2,pos1] = kinematics(th1(i),th2(i),th3(i));
    xp = [pos1(1) pos2(1) pos3(1)];
    yp = [pos1(2) pos2(2) pos3(2)];
    zp = [pos1(3) pos2(3) pos3(3)];
    figure(f1);
    p = plot3(xp,yp,zp,"-or","MarkerSize",4,"LineWidth",5);
    p.Color = "blue";
    hold on;
    p_ini = plot3(x_ini,y_ini,z_ini,"-or","MarkerSize",4,"LineWidth",5);
    p_ini.Color = "cyan";
    p_ini.Color(4) = 0.2;
    p_tgt = plot3(x_tgt,y_tgt,z_tgt,"-or","MarkerSize",4,"LineWidth",5);
    p_tgt.Color = "green";
    p_tgt.Color(4) = 0.2;
    hold off;
    view(100,45);
    xlim([-100 200]);
    ylim([-100 200]);
    zlim([-100 200]);
    xlabel('x')
    ylabel('y')
    zlabel('z')
    grid on
    axis square
    waitfor(r);
end

%3回目
%set initial angles
th1_init = 22.5*angle(3,1);
th2_init = 22.5*angle(3,2);
th3_init = 45*angle(3,3);

th_1 = 22.5*angle(4,1);
th_2 = 22.5*angle(4,2);
th_3 = 45*angle(4,3);
%Calculate the trajectory of the robot arm
[th1 th2 th3] = traj3(th1_init,th2_init,th3_init,th_1,th_2,th_3);
%Vizualize
l = length(th1);
frames_per_second = 15;
r = rateControl(frames_per_second)
for i=1:l
    [pos3,pos2,pos1] = kinematics(th1(i),th2(i),th3(i));
    xp = [pos1(1) pos2(1) pos3(1)];
    yp = [pos1(2) pos2(2) pos3(2)];
    zp = [pos1(3) pos2(3) pos3(3)];
    figure(f1);
    p = plot3(xp,yp,zp,"-or","MarkerSize",4,"LineWidth",5);
    p.Color = "blue";
    hold on;
    p_ini = plot3(x_ini,y_ini,z_ini,"-or","MarkerSize",4,"LineWidth",5);
    p_ini.Color = "cyan";
    p_ini.Color(4) = 0.2;
    p_tgt = plot3(x_tgt,y_tgt,z_tgt,"-or","MarkerSize",4,"LineWidth",5);
    p_tgt.Color = "green";
    p_tgt.Color(4) = 0.2;
    hold off;
    view(100,45);
    xlim([-100 200]);
    ylim([-100 200]);
    zlim([-100 200]);
    xlabel('x')
    ylabel('y')
    zlabel('z')
    grid on
    axis square
    waitfor(r);
end

%4回目
%set initial angles
th1_init = 22.5*angle(4,1);
th2_init = 22.5*angle(4,2);
th3_init = 45*angle(4,3);

th_1 = 22.5*angle(5,1);
th_2 = 22.5*angle(5,2);
th_3 = 45*angle(5,3);
%Calculate the trajectory of the robot arm
[th1 th2 th3] = traj3(th1_init,th2_init,th3_init,th_1,th_2,th_3);
%Vizualize
l = length(th1);
frames_per_second = 15;
r = rateControl(frames_per_second)
for i=1:l
    [pos3,pos2,pos1] = kinematics(th1(i),th2(i),th3(i));
    xp = [pos1(1) pos2(1) pos3(1)];
    yp = [pos1(2) pos2(2) pos3(2)];
    zp = [pos1(3) pos2(3) pos3(3)];
    figure(f1);
    p = plot3(xp,yp,zp,"-or","MarkerSize",4,"LineWidth",5);
    p.Color = "blue";
    hold on;
    p_ini = plot3(x_ini,y_ini,z_ini,"-or","MarkerSize",4,"LineWidth",5);
    p_ini.Color = "cyan";
    p_ini.Color(4) = 0.2;
    p_tgt = plot3(x_tgt,y_tgt,z_tgt,"-or","MarkerSize",4,"LineWidth",5);
    p_tgt.Color = "green";
    p_tgt.Color(4) = 0.2;
    hold off;
    view(100,45);
    xlim([-100 200]);
    ylim([-100 200]);
    zlim([-100 200]);
    xlabel('x')
    ylabel('y')
    zlabel('z')
    grid on
    axis square
    waitfor(r);
end

%5回目
%set initial angles
th1_init = 22.5*angle(5,1);
th2_init = 22.5*angle(5,2);
th3_init = 45*angle(5,3);

th_1 = 22.5*angle(6,1);
th_2 = 22.5*angle(6,2);
th_3 = 45*angle(6,3);
%Calculate the trajectory of the robot arm
[th1 th2 th3] = traj3(th1_init,th2_init,th3_init,th_1,th_2,th_3);
%Vizualize
l = length(th1);
frames_per_second = 15;
r = rateControl(frames_per_second)
for i=1:l
    [pos3,pos2,pos1] = kinematics(th1(i),th2(i),th3(i));
    xp = [pos1(1) pos2(1) pos3(1)];
    yp = [pos1(2) pos2(2) pos3(2)];
    zp = [pos1(3) pos2(3) pos3(3)];
    figure(f1);
    p = plot3(xp,yp,zp,"-or","MarkerSize",4,"LineWidth",5);
    p.Color = "blue";
    hold on;
    p_ini = plot3(x_ini,y_ini,z_ini,"-or","MarkerSize",4,"LineWidth",5);
    p_ini.Color = "cyan";
    p_ini.Color(4) = 0.2;
    p_tgt = plot3(x_tgt,y_tgt,z_tgt,"-or","MarkerSize",4,"LineWidth",5);
    p_tgt.Color = "green";
    p_tgt.Color(4) = 0.2;
    hold off;
    view(100,45);
    xlim([-100 200]);
    ylim([-100 200]);
    zlim([-100 200]);
    xlabel('x')
    ylabel('y')
    zlabel('z')
    grid on
    axis square
    waitfor(r);
end

%6回目
%set initial angles
th1_init = 22.5*angle(6,1);
th2_init = 22.5*angle(6,2);
th3_init = 45*angle(6,3);

th_1 = 22.5*angle(7,1);
th_2 = 22.5*angle(7,2);
th_3 = 45*angle(7,3);
%Calculate the trajectory of the robot arm
[th1 th2 th3] = traj3(th1_init,th2_init,th3_init,th_1,th_2,th_3);
%Vizualize
l = length(th1);
frames_per_second = 15;
r = rateControl(frames_per_second)
for i=1:l
    [pos3,pos2,pos1] = kinematics(th1(i),th2(i),th3(i));
    xp = [pos1(1) pos2(1) pos3(1)];
    yp = [pos1(2) pos2(2) pos3(2)];
    zp = [pos1(3) pos2(3) pos3(3)];
    figure(f1);
    p = plot3(xp,yp,zp,"-or","MarkerSize",4,"LineWidth",5);
    p.Color = "blue";
    hold on;
    p_ini = plot3(x_ini,y_ini,z_ini,"-or","MarkerSize",4,"LineWidth",5);
    p_ini.Color = "cyan";
    p_ini.Color(4) = 0.2;
    p_tgt = plot3(x_tgt,y_tgt,z_tgt,"-or","MarkerSize",4,"LineWidth",5);
    p_tgt.Color = "green";
    p_tgt.Color(4) = 0.2;
    hold off;
    view(100,45);
    xlim([-100 200]);
    ylim([-100 200]);
    zlim([-100 200]);
    xlabel('x')
    ylabel('y')
    zlabel('z')
    grid on
    axis square
    waitfor(r);
end

%Kinematics
function [pos_3,pos_2,pos_1] = kinematics(th1,th2,th3)
    L1=100;
    L2=50;    
    
    l0 = L1*cos(deg2rad(th2))+L2*cos(deg2rad(th2-th3));
    
    pos_3 = [l0*cos(deg2rad(th1));l0*sin(deg2rad(th1));L1*sin(deg2rad(th2))+L2*sin(deg2rad(th2-th3));];
    pos_2 = [L1*cos(deg2rad(th2))*cos(deg2rad(th1));L1*cos(deg2rad(th2))*sin(deg2rad(th1));L1*sin(deg2rad(th2));];
    pos_1 = [0;0;0;];
end


%Calculate Trajectory
function [th1_ref th2_ref th3_ref]=traj3(start_th1,start_th2,start_th3,goal_th1,goal_th2,goal_th3) 
%Time to reach goal
T = 2;%[sec]
Ts = 0.05;
init_mat = [start_th1;start_th2;start_th3;];
A = init_mat;
    for t = 0:Ts:T;
        B = [(goal_th1-start_th1)*t/T+start_th1;(goal_th2-start_th2)*t/T+start_th2;(goal_th3-start_th3)*t/T+start_th3;];
        A = [A B];
    end
th1_ref = A(1,:);
th2_ref = A(2,:);
th3_ref = A(3,:);
end
