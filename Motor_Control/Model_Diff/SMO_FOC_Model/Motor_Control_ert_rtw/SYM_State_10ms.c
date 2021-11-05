/*
 * File: SYM_State_10ms.c
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

#include "SYM_State_10ms.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Output and update for function-call system: '<S2>/SYM_State_10ms' */
void SYM_State_10ms(void)
{
  /* Sum: '<S212>/Add1' incorporates:
   *  Constant: '<S212>/Constant1'
   *  Product: '<S212>/Divide1'
   *  Product: '<S214>/Product'
   *  Product: '<S214>/Product1'
   *  Sum: '<S212>/Add'
   *  Sum: '<S214>/Add'
   *  UnitDelay: '<S212>/Unit Delay'
   */
  Motor_Power += ((rtDW.UnitDelay2 * rtDW.UnitDelay1 + rtDW.UnitDelay3 *
                   rtDW.UnitDelay4) - Motor_Power) * 0.005F;

  /* Sum: '<S213>/Add1' incorporates:
   *  Constant: '<S213>/Constant1'
   *  Constant: '<S215>/Constant2'
   *  Product: '<S213>/Divide1'
   *  Product: '<S215>/Product1'
   *  Product: '<S215>/Product2'
   *  Product: '<S215>/Product3'
   *  Product: '<S215>/Product4'
   *  Sum: '<S213>/Add'
   *  Sum: '<S215>/Subtract'
   *  UnitDelay: '<S213>/Unit Delay'
   */
  Motor_Torque += ((-0.00019999966F * rtDW.UnitDelay2 * rtDW.UnitDelay3 +
                    0.0260812F * rtDW.UnitDelay3) * 3.0F - Motor_Torque) *
    0.005F;

  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S210>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
   *  ActionPort: '<S211>/Action Port'
   */
  /* If: '<S6>/If1' incorporates:
   *  Inport: '<Root>/Start_Stop'
   *  SignalConversion generated from: '<S210>/Out1'
   *  SignalConversion generated from: '<S211>/Out1'
   */
  rtDW.Merge1_a = (uint8_T)(rtU.Start_Stop != 1);

  /* End of Outputs for SubSystem: '<S6>/If Action Subsystem2' */
  /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
