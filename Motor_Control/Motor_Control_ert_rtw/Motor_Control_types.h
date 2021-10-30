/*
 * File: Motor_Control_types.h
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 3.5
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun Sep  5 09:33:37 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Motor_Control_types_h_
#define RTW_HEADER_Motor_Control_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_SMOParam_STRUCT_
#define DEFINED_TYPEDEF_FOR_SMOParam_STRUCT_

typedef struct {
  uint8_T Func_Enable;
  uint8_T Angle_Enable;
  real32_T A;
  real32_T B;
  real32_T C;
  real32_T k;
  real32_T m;
  real32_T tao;
  real32_T PLL_KP;
  real32_T PLL_Ki;
  real32_T Angle_offset;
} SMOParam_STRUCT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Fluxweak_STRUCT_
#define DEFINED_TYPEDEF_FOR_Fluxweak_STRUCT_

typedef struct {
  uint8_T Enable;
  real32_T Idref_min;
  real32_T Idref_max;
  real32_T Kp;
  real32_T Ki;
  real32_T Ismax;
} Fluxweak_STRUCT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HFI_STRUCT_
#define DEFINED_TYPEDEF_FOR_HFI_STRUCT_

typedef struct {
  uint8_T Func_Enable;
  uint8_T Angle_Enable;
  real32_T Inj_HV;
  real32_T Inj_HF;
  real32_T IPD_V;
  real32_T IPD_F;
  real32_T IPD_Time;
  real32_T NS_V;
  real32_T NS_Time;
  real32_T NS_Plus_Time;
  real32_T NS_Low_Time;
  real32_T Switch_Time;
  real32_T NS2RUN_Time;
  real32_T We;
  real32_T bw_BPF;
  real32_T HPF;
  real32_T LPF;
  real32_T PI_Kp;
  real32_T PI_Ki;
} HFI_STRUCT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Resolver_STRUCT_
#define DEFINED_TYPEDEF_FOR_Resolver_STRUCT_

typedef struct {
  uint8_T Func_Enable;
  uint8_T Angle_Enable;
  uint8_T PLL_Func_Enable;
  uint8_T PLL_Angle_Enable;
  real32_T Angle_offset;
  real32_T PLL_Angle_offset;
} Resolver_STRUCT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FluxObsever_STRUCT_
#define DEFINED_TYPEDEF_FOR_FluxObsever_STRUCT_

typedef struct {
  uint8_T Func_Enable;
  uint8_T Angle_Enable;
  real32_T Omega;
  real32_T Kp;
} FluxObsever_STRUCT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Hall_STRUCT_
#define DEFINED_TYPEDEF_FOR_Hall_STRUCT_

typedef struct {
  uint8_T Func_Enable;
  uint8_T Angle_Enable;
  uint8_T BLDC_Start;
  real32_T BLDC_Start_Time;
  real32_T Start_duty;
  real32_T shift;
  real32_T Timer_frequency;
  real32_T Sector_6;
  real32_T Sector_4;
  real32_T Sector_5;
  real32_T Sector_1;
  real32_T Sector_3;
  real32_T Sector_2;
} Hall_STRUCT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_OPLParam_STRUCT_
#define DEFINED_TYPEDEF_FOR_OPLParam_STRUCT_

typedef struct {
  uint8_T Func_Enable;
  uint8_T Angle_Enable;
  real32_T Target_RPM;
  real32_T Acc_Times;
  real32_T Revup_Times;
  real32_T Current_ref;
  real32_T Constant;
  real32_T Target_RPMMax;
  real32_T Target_RPMMin;
} OPLParam_STRUCT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CLParam_STRUCT_
#define DEFINED_TYPEDEF_FOR_CLParam_STRUCT_

typedef struct {
  uint8_T Mode;
  real32_T Target_RPM;
  real32_T Acc_Times;
  real32_T Current_IQref;
  real32_T Angle_offset;
  real32_T Constant;
  real32_T Target_RPMMax;
  real32_T Target_RPMMin;
} CLParam_STRUCT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CTRLPARAMS_STRUCT_
#define DEFINED_TYPEDEF_FOR_CTRLPARAMS_STRUCT_

typedef struct {
  real32_T ws;
  real32_T speed_PI_Kp;
  real32_T speed_PI_Ki;
  real32_T speed_PI_OutputMax;
  real32_T speed_PI_OutputMin;
  real32_T speed_PI_Tsample;
  real32_T ID_Current_PI_Kp;
  real32_T ID_Current_PI_Ki;
  real32_T ID_Current_PI_OutputMax;
  real32_T ID_Current_PI_OutputMin;
  real32_T IQ_Current_PI_Kp;
  real32_T IQ_Current_PI_Ki;
  real32_T IQ_Current_PI_OutputMax;
  real32_T IQ_Current_PI_OutputMin;
} CTRLPARAMS_STRUCT;

#endif

#ifndef struct_tag_56f1cdaGgiZ2ZmtsGAepW
#define struct_tag_56f1cdaGgiZ2ZmtsGAepW

struct tag_56f1cdaGgiZ2ZmtsGAepW
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real32_T ForgettingFactor;
  real32_T pwN;
  real32_T pmN;
  real32_T plambda;
};

#endif                                 /*struct_tag_56f1cdaGgiZ2ZmtsGAepW*/

#ifndef typedef_c_dsp_private_ExponentialMovingAverage
#define typedef_c_dsp_private_ExponentialMovingAverage

typedef struct tag_56f1cdaGgiZ2ZmtsGAepW c_dsp_private_ExponentialMovingAverage;

#endif                        /*typedef_c_dsp_private_ExponentialMovingAverage*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap;

#endif                                 /*typedef_cell_wrap*/

#ifndef struct_tag_m1xTwSPz71iHpsYxepaAlB
#define struct_tag_m1xTwSPz71iHpsYxepaAlB

struct tag_m1xTwSPz71iHpsYxepaAlB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap inputVarSize;
  real32_T ForgettingFactor;
  c_dsp_private_ExponentialMovingAverage *pStatistic;
  int32_T NumChannels;
  c_dsp_private_ExponentialMovingAverage _pobj0;
};

#endif                                 /*struct_tag_m1xTwSPz71iHpsYxepaAlB*/

#ifndef typedef_dsp_simulink_MovingAverage
#define typedef_dsp_simulink_MovingAverage

typedef struct tag_m1xTwSPz71iHpsYxepaAlB dsp_simulink_MovingAverage;

#endif                                 /*typedef_dsp_simulink_MovingAverage*/

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#endif                                 /* RTW_HEADER_Motor_Control_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
