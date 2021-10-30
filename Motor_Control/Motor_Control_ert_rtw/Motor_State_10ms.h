/*
 * File: Motor_State_10ms.h
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

#ifndef RTW_HEADER_Motor_State_10ms_h_
#define RTW_HEADER_Motor_State_10ms_h_
#ifndef Motor_Control_COMMON_INCLUDES_
#define Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Motor_Control_COMMON_INCLUDES_ */

#include "Motor_Control_types.h"

extern void Motor_State_10ms(real32_T rtu_Id, real32_T rtu_Vd, real32_T rtu_Iq,
  real32_T rtu_Vq);

#endif                                 /* RTW_HEADER_Motor_State_10ms_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
