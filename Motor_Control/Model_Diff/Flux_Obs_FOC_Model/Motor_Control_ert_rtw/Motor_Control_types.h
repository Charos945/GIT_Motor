/*
 * File: Motor_Control_types.h
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.54
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 18 10:27:27 2021
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
