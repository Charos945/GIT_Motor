%Motor Control
%Set Motor Parameters%

pmsm = struct;
pmsm.RatedVoltage = 24.0;  %TBD
pmsm.RatedSpeed = 10000.0;  %TBD
pmsm.CurrentMax = single(10);    %TBD
pmsm.VoltageMax = 36;    %TBD
pmsm.PolePairs = 2;
pmsm.StatorPhaseResistance = single(0.4); % RS
pmsm.InductanceLd = single(0.0040);         % Ld
pmsm.InductanceLq = single(0.0042);        % Lq
pmsm.InductanceLs = single((pmsm.InductanceLd+pmsm.InductanceLq)/2);
pmsm.FluxLinkage = single(0.0260812);           %Flux
pmsm.TorqueConstant =single(1.5*pmsm.PolePairs*pmsm.FluxLinkage);
pmsm.Jkgm2 = 1e-4;


%Set Inverter Parameters%
inverter = struct;
inverter.BusVoltage = 24.0;
inverter.BusVoltageMax = 36.0;
inverter.BusVoltageMin = 10.0;
inverter.CurrentMax = single(10);
inverter.PWM_frequency = 10000;     %20Khz
inverter.Ts=1/inverter.PWM_frequency; %Ts
inverter.Speed_PI_T =0.002;%s
%SMO parameters
SMO = struct;
SMO.Func_Enable=uint8(0);
SMO.Angle_Enable=uint8(0);
SMO.A=single(1-pmsm.StatorPhaseResistance*inverter.Ts/pmsm.InductanceLd);
SMO.B=single((pmsm.InductanceLd-pmsm.InductanceLq)*inverter.Ts/pmsm.InductanceLd);
SMO.C=single(inverter.Ts/pmsm.InductanceLd);
SMO.k=single(2.0);%0.2 1.2
SMO.m=single(0.15);%0.8 1.8
SMO.tao=single(0.5);
SMO.PLL_KP =single(2*0.707*100);
SMO.PLL_Ki =single(100*100);
SMO.Angle_offset = single(0);

temp_SMO = Simulink.Parameter;
temp_SMO.Value=SMO;
temp_SMO.CoderInfo.StorageClass='ExportedGlobal';
SMO = temp_SMO;
clear tmp_SMO_Param

tmp_BusInfo = Simulink.Bus.createObject(SMO.Value);
SMOParam_STRUCT = eval(tmp_BusInfo.busName);
SMO.DataType='Bus: SMOParam_STRUCT';
clear(tmp_BusInfo.busName);
clear tmp_SMO_Param_BusInfo;

currentloop = struct;
currentloop.wc = single(8000); %rad/s 电流环带宽
currentloop.kp_d = pmsm.InductanceLd * currentloop.wc;
currentloop.ki_d = currentloop.wc*inverter.Ts;
currentloop.kp_q = pmsm.InductanceLq * currentloop.wc;
currentloop.ki_q= pmsm.StatorPhaseResistance*currentloop.wc*inverter.Ts;
%Set Speed and Current PI Parameters%
%Speed PI Parameters%
ctrlParamsPI = struct;
ctrlParamsPI.ws= single(0.5);% 速度带宽
ctrlParamsPI.speed_PI_Kp =single(0.000267);%single(ctrlParamsPI.ws*pmsm.Jkgm2/(1.5*pmsm.PolePairs*pmsm.Jkgm2 ));%sensor :kp =0.25 Ki=0.55
ctrlParamsPI.speed_PI_Ki =single(0.00633);%single(ctrlParamsPI.ws*ctrlParamsPI.speed_PI_Kp); %sensorless:kp=0.008 Ki=0.12
ctrlParamsPI.speed_PI_OutputMax =single(1.5);
ctrlParamsPI.speed_PI_OutputMin =single(-1.5);
ctrlParamsPI.speed_PI_Tsample=single(inverter.Speed_PI_T/inverter.Ts); %0.002s
%ID PI Parameters%

ctrlParamsPI.ID_Current_PI_Kp =single(currentloop.kp_d);
ctrlParamsPI.ID_Current_PI_Ki =single(currentloop.ki_d);
ctrlParamsPI.ID_Current_PI_OutputMax =single(inverter.BusVoltage/sqrt(3));
ctrlParamsPI.ID_Current_PI_OutputMin =single(-inverter.BusVoltage/sqrt(3));
%IQ PI Parameters%
ctrlParamsPI.IQ_Current_PI_Kp = single(currentloop.kp_q);
ctrlParamsPI.IQ_Current_PI_Ki = single(currentloop.ki_q);
ctrlParamsPI.IQ_Current_PI_OutputMax = single(inverter.BusVoltage/sqrt(3));
ctrlParamsPI.IQ_Current_PI_OutputMin =single(-inverter.BusVoltage/sqrt(3));
%% Create parameter structure in generated code
tmp_ctrlParamsPI = Simulink.Parameter;
tmp_ctrlParamsPI.Value=ctrlParamsPI;
tmp_ctrlParamsPI.CoderInfo.StorageClass='ExportedGlobal';
ctrlParamsPI = tmp_ctrlParamsPI;
clear tmp_ctrlParamsPI

tmp_ctrlParamsPI_BusInfo = Simulink.Bus.createObject(ctrlParamsPI.Value);
CTRLPARAMS_STRUCT = eval(tmp_ctrlParamsPI_BusInfo.busName);
ctrlParamsPI.DataType='Bus: CTRLPARAMS_STRUCT';
clear(tmp_ctrlParamsPI_BusInfo.busName);
clear tmp_ctrlParamsPI_BusInfo;
%Open Loop Parameters
OPL_Param = struct;
OPL_Param.Func_Enable=uint8(0);
OPL_Param.Angle_Enable=uint8(0);
OPL_Param.Target_RPM = single(800.0);
OPL_Param.Acc_Times =single(0.5); %s
OPL_Param.Revup_Times =single(0.1); %s
OPL_Param.Current_ref =single(5.0);
OPL_Param.Constant = single(OPL_Param.Target_RPM/OPL_Param.Acc_Times/inverter.PWM_frequency);
OPL_Param.Target_RPMMax=single(OPL_Param.Target_RPM);
OPL_Param.Target_RPMMin=single(-OPL_Param.Target_RPM);

%% Create parameter structure in generated code
tmp_OPL_Param = Simulink.Parameter;
tmp_OPL_Param.Value=OPL_Param;
tmp_OPL_Param.CoderInfo.StorageClass='ExportedGlobal';
OPL_Param = tmp_OPL_Param;
clear tmp_OPL_Param

tmp_BusInfo = Simulink.Bus.createObject(OPL_Param.Value);
OPLParam_STRUCT = eval(tmp_BusInfo.busName);
OPL_Param.DataType='Bus: OPLParam_STRUCT';
clear(tmp_BusInfo.busName);
clear tmp_BusInfo;

Resolver_Parameter = struct;
Resolver_Parameter.Func_Enable=uint8(1);
Resolver_Parameter.Angle_Enable=uint8(0);
Resolver_Parameter.PLL_Func_Enable=uint8(1);
Resolver_Parameter.PLL_Angle_Enable=uint8(0);
Resolver_Parameter.Angle_offset =single(0.0);
Resolver_Parameter.PLL_Angle_offset =single(1.02);

tmp_Resolver_struct = Simulink.Parameter;
tmp_Resolver_struct.Value=Resolver_Parameter;
tmp_Resolver_struct.CoderInfo.StorageClass='ExportedGlobal';
Resolver_Parameter = tmp_Resolver_struct;
clear tmp_Resolver_struct

tmp_BusInfo = Simulink.Bus.createObject(Resolver_Parameter.Value);
Resolver_STRUCT = eval(tmp_BusInfo.busName);
Resolver_Parameter.DataType='Bus: Resolver_STRUCT';
clear(tmp_BusInfo.busName);
clear tmp_BusInfo;

%Cloose Loop Parameters
CL_Param = struct;
CL_Param.Mode = uint8(1);  %1:speed mode, 2:Torque mode
CL_Param.Target_RPM = single(1000.0);
CL_Param.Acc_Times =single(1); %s

CL_Param.Current_IQref =single(0.5);
CL_Param.Angle_offset =single(0.1985);
CL_Param.Constant = single(CL_Param.Target_RPM/CL_Param.Acc_Times*inverter.Speed_PI_T);
CL_Param.Target_RPMMax=single(CL_Param.Target_RPM);
CL_Param.Target_RPMMin=single(-CL_Param.Target_RPM);

%% Create parameter structure in generated code
tmp_CL_Param = Simulink.Parameter;
tmp_CL_Param.Value=CL_Param;
tmp_CL_Param.CoderInfo.StorageClass='ExportedGlobal';
CL_Param = tmp_CL_Param;
clear tmp_CL_Param

tmp_BusInfo = Simulink.Bus.createObject(CL_Param.Value);
CLParam_STRUCT = eval(tmp_BusInfo.busName);
CL_Param.DataType='Bus: CLParam_STRUCT';
clear(tmp_BusInfo.busName);
clear tmp_BusInfo;

%Flux weakening
Flux_weak = struct;
Flux_weak.Enable=uint8(0);%1 :enable 0:disable
Flux_weak.Idref_min = single(-4);
Flux_weak.Idref_max =single(0);
Flux_weak.Kp=single(0.05);
Flux_weak.Ki=single(0.8);
Flux_weak.Ismax =single(10);

%% Create parameter structure in generated code
tmp_Fluxweak_struct = Simulink.Parameter;
tmp_Fluxweak_struct.Value=Flux_weak;
tmp_Fluxweak_struct.CoderInfo.StorageClass='ExportedGlobal';
Flux_weak = tmp_Fluxweak_struct;
clear tmp_Fluxweak_struct

tmp_BusInfo = Simulink.Bus.createObject(Flux_weak.Value);
Fluxweak_STRUCT = eval(tmp_BusInfo.busName);
Flux_weak.DataType='Bus: Fluxweak_STRUCT';
clear(tmp_BusInfo.busName);
clear tmp_BusInfo;

HFI = struct;
HFI.Func_Enable = uint8(0);
HFI.Angle_Enable = uint8(0);
HFI.Inj_HV = single(12);  %V
HFI.Inj_HF = single(1000);  %Hz
HFI.IPD_V =single(12);
HFI.IPD_F =single(500);
HFI.IPD_Time =single(0.1);%ms
HFI.NS_V = single(12);
HFI.NS_Time =single(0.05);%ms
HFI.NS_Plus_Time=single(0.001);%ms
HFI.NS_Low_Time=single(0.01);%ms
HFI.Switch_Time=single(0.5);
HFI.NS2RUN_Time=single(0.1);%ms
HFI.We = single(2*pi*HFI.Inj_HF);
HFI.bw_BPF = single(100);    %
HFI.HPF = single(HFI.Inj_HF - HFI.bw_BPF/2);
HFI.LPF = single(HFI.Inj_HF + HFI.bw_BPF/2);
HFI.PI_Kp = single(100);
HFI.PI_Ki = single(5000);


%% Create parameter structure in generated code
tmp_HFI_struct = Simulink.Parameter;
tmp_HFI_struct.Value=HFI;
tmp_HFI_struct.CoderInfo.StorageClass='ExportedGlobal';
HFI = tmp_HFI_struct;
clear tmp_HFI_struct

tmp_BusInfo = Simulink.Bus.createObject(HFI.Value);
HFI_STRUCT = eval(tmp_BusInfo.busName);
HFI.DataType='Bus: HFI_STRUCT';
clear(tmp_BusInfo.busName);
clear tmp_BusInfo;

Hall_Parameter = struct;
Hall_Parameter.Func_Enable=uint8(1);
Hall_Parameter.Angle_Enable=uint8(1);
Hall_Parameter.BLDC_Start=uint8(0);
Hall_Parameter.BLDC_Start_Time=single(0);
Hall_Parameter.Start_duty=single(0.7);
Hall_Parameter.shift=single(-0.25);
Hall_Parameter.Timer_frequency=single(1e-5);

Hall_Parameter.Sector_3=single(0);
Hall_Parameter.Sector_2=single(pi/3);
Hall_Parameter.Sector_6=single(2*pi/3);
Hall_Parameter.Sector_4=single(pi);
Hall_Parameter.Sector_5=single(4*pi/3);
Hall_Parameter.Sector_1=single(5*pi/3);

tmp_Hall_struct = Simulink.Parameter;
tmp_Hall_struct.Value=Hall_Parameter;
tmp_Hall_struct.CoderInfo.StorageClass='ExportedGlobal';
Hall_Parameter = tmp_Hall_struct;
clear tmp_Hall_struct

tmp_BusInfo = Simulink.Bus.createObject(Hall_Parameter.Value);
Hall_STRUCT = eval(tmp_BusInfo.busName);
Hall_Parameter.DataType='Bus: Hall_STRUCT';
clear(tmp_BusInfo.busName);
clear tmp_BusInfo;

%Flux weakening
FluxObsever = struct;
FluxObsever.Func_Enable=uint8(1);%1 :enable 0:disable
FluxObsever.Angle_Enable=uint8(0);%1 :enable 0:disable
FluxObsever.Omega = single(1000);
FluxObsever.Kp =single(10);


%% Create parameter structure in generated code
tmp_FluxObsever_struct = Simulink.Parameter;
tmp_FluxObsever_struct.Value=FluxObsever;
tmp_FluxObsever_struct.CoderInfo.StorageClass='ExportedGlobal';
FluxObsever = tmp_FluxObsever_struct;
clear tmp_FluxObsever_struct

tmp_BusInfo = Simulink.Bus.createObject(FluxObsever.Value);
FluxObsever_STRUCT = eval(tmp_BusInfo.busName);
FluxObsever.DataType='Bus: FluxObsever_STRUCT';
clear(tmp_BusInfo.busName);
clear tmp_BusInfo;


