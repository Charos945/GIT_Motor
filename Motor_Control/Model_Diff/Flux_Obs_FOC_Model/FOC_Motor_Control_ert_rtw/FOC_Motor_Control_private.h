/*
 * File: FOC_Motor_Control_private.h
 *
 * Code generated for Simulink model 'FOC_Motor_Control'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Nov 15 13:44:38 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FOC_Motor_Control_private_h_
#define RTW_HEADER_FOC_Motor_Control_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern real32_T rt_modf_snf(real32_T u0, real32_T u1);
extern uint32_T plook_u32f_evencka(real32_T u, real32_T bp0, real32_T bpSpace,
  uint32_T maxIndex);

#endif                             /* RTW_HEADER_FOC_Motor_Control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
