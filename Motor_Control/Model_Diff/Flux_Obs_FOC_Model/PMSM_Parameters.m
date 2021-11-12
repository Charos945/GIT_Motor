%Motor Control
%Set Motor Parameters%
pmsm = struct;
pmsm.RatedVoltage = 24.0;  %TBD
pmsm.PolePairs = 2;
pmsm.StatorPhaseResistance = single(0.008); % RS
pmsm.InductanceLd = single(0.0040);         % Ld
pmsm.InductanceLq = single(0.0042);        % Lq
pmsm.FluxLinkage = single(0.0260812);           %Flux
pmsm.Jkm2=single(0.002);

%Set Inverter Parameters%
inverter = struct;
inverter.BusVoltage = 24.0;
inverter.BusVoltageMax = 36.0;
inverter.BusVoltageMin = 10.0;
inverter.CurrentMax = single(10);
inverter.PWM_frequency = 10000;     %20Khz
inverter.Ts=1/inverter.PWM_frequency; %Ts
inverter.Speed_PI_T =0.002;%s

currentloop = struct;
currentloop.wc = single(8000); %rad/s 电流环带宽
currentloop.kp_d = pmsm.InductanceLd * currentloop.wc;
currentloop.ki_d = currentloop.wc*pmsm.StatorPhaseResistance;
currentloop.kp_q = pmsm.InductanceLq * currentloop.wc;
currentloop.ki_q= pmsm.StatorPhaseResistance*currentloop.wc;
%Set Speed and Current PI Parameters%
%Speed PI Parameters%



