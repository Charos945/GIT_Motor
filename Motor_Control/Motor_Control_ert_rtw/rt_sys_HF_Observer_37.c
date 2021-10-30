/*
 * File: rt_sys_HF_Observer_37.c
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

#include "rt_sys_HF_Observer_37.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/*
 * Output and update for action system:
 *    '<S228>/If Action Subsystem2'
 *    '<S232>/If Action Subsystem2'
 *    '<S160>/If Action Subsystem2'
 *    '<S135>/If Action Subsystem2'
 *    '<S80>/If Action Subsystem2'
 */
void IfActionSubsystem2_g(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S230>/Subtract1' incorporates:
   *  Constant: '<S230>/2pi'
   */
  *rty_Out1 = rtu_In1 - 6.28318548F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
