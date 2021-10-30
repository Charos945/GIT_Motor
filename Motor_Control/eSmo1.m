function [sys,x0,str,ts] = eSmo1(t,x,u,flag,Rs,Ld,Lq,k,m,Ts,Tpu,tao)
    switch flag
        case 0
            [sys,x0,str,ts] = mdlInitializeSizes(Ts);      % 初始化
        case 2
            sys = mdlUpdates(t,x,u,Rs,Ld,Lq,k,m,Tpu,tao);
        case 3
            sys = mdlOutputs(t,x,u); % 计算输出
        case { 1, 4, 9 }
            sys = [];               
        otherwise
            error(['Unhandled flag = ',num2str(flag)]);    %错误处理
    end;                   
end

function [sys,x0,str,ts] = mdlInitializeSizes(Ts)
    sizes = simsizes;
    sizes.NumContStates= 0; %连续状态变量个数
    sizes.NumDiscStates= 10; %离散状态变量个数：
    sizes.NumOutputs= 6;    %输出变量个数
    sizes.NumInputs= 5;     %输入变量个数
    sizes.DirFeedthrough=1; %1直通
    sizes.NumSampleTimes=1;
    sys = simsizes(sizes);
    x0 = 0;   %初始状态
    str = []; 
    ts = [Ts 0]; 
end

  %u(1) input ,Ialpha(k)     x(5) Est_ialpha_last    x(7) Est_Ealpha_last
  %u(2) input ,Ibeta(k)      x(6) Est_ibeta_last     x(8) Est_Ebeta_last
  %u(3) input, Ualpha(k)     x(1) Est_iaplha_now     x(3) Est_Ealpha_now
  %u(4) input, Ubeta(k)      x(2) Est_ibeta_now      x(4) Est_Ealpha_now
  %u(5) input, Est_we(k)
function sys = mdlUpdates(t,x,u,Rs,Ld,Lq,k,m,Tpu,tao)
A=(1-Rs*Tpu/Ld);
B=(Ld-Lq)*Tpu/Ld;
C=Tpu/Ld;

Ialphaerr=x(5)-u(1);
Ibetaerr=x(6)-u(2);
if Ialphaerr>tao
    Zalpha=1;
else if Ialphaerr<-tao
   Zalpha=-1;
else
     Zalpha=Ialphaerr/tao;
    end
end
     
if Ibetaerr>tao
    Zbeta=1;
else if Ibetaerr<-tao
    Zbeta=-1;
else
     Zbeta=Ibetaerr/tao;
    end
end
%Zalpha=sign(Ialphaerr);
%Zbeta=sign(Ibetaerr);

x(1)=A*x(5)-B*u(5)*x(6)+C*(u(3)-x(7))-C*k*Zalpha;
x(2)=A*x(6)+B*u(5)*x(5)+C*(u(4)-x(8))-C*k*Zbeta;
x(3)=x(7)-Tpu*u(5)*x(8)+C*m*Zalpha;
x(4)=x(8)+Tpu*u(5)*x(7)+C*m*Zbeta;
x(5)=x(1);
x(6)=x(2);
x(7)=x(3);
x(8)=x(4);
x(9)=Zalpha;
x(10)=Zbeta;

    sys = [x(1) x(2) x(3) x(4) x(5) x(6) x(7) x(8) x(9) x(10)];
end

function sys = mdlOutputs(t,x,u)


    sys = [x(1) x(2) x(3) x(4) x(9) x(10)];
end
