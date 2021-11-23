/*
 * File: rt_sys_HF_Observer_37.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.79
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Nov 23 17:08:07 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "rt_sys_HF_Observer_37.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/*
 * Output and update for action system:
 *    '<S78>/If Action Subsystem2'
 *    '<S82>/If Action Subsystem2'
 *    '<S19>/If Action Subsystem2'
 */
void IfActionSubsystem2_k(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S80>/Subtract1' incorporates:
   *  Constant: '<S80>/2pi'
   */
  *rty_Out1 = rtu_In1 - 6.28318548F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
