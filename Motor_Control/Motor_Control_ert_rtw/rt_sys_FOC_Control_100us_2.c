/*
 * File: rt_sys_FOC_Control_100us_2.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov  4 09:51:01 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "rt_sys_FOC_Control_100us_2.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/*
 * Output and update for action system:
 *    '<S113>/If Action Subsystem2'
 *    '<S10>/If Action Subsystem2'
 */
void IfActionSubsystem2(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S118>/Subtract1' incorporates:
   *  Constant: '<S118>/2pi'
   */
  *rty_Out1 = rtu_In1 - 6.28318548F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
