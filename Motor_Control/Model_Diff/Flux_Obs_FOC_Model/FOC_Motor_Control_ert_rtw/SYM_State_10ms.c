/*
 * File: SYM_State_10ms.c
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

#include "SYM_State_10ms.h"

/* Include model header file for global data */
#include "FOC_Motor_Control.h"
#include "FOC_Motor_Control_private.h"

/* Output and update for function-call system: '<S2>/SYM_State_10ms' */
void SYM_State_10ms(void)
{
  /* Sum: '<S207>/Add1' incorporates:
   *  Constant: '<S207>/Constant1'
   *  Product: '<S207>/Divide1'
   *  Product: '<S209>/Product'
   *  Product: '<S209>/Product1'
   *  Sum: '<S207>/Add'
   *  Sum: '<S209>/Add'
   *  UnitDelay: '<S207>/Unit Delay'
   */
  Motor_Power += ((rtDW.UnitDelay2 * rtDW.UnitDelay1 + rtDW.UnitDelay3 *
                   rtDW.UnitDelay4) - Motor_Power) * 0.005F;

  /* Sum: '<S208>/Add1' incorporates:
   *  Constant: '<S208>/Constant1'
   *  Constant: '<S210>/Constant2'
   *  Product: '<S208>/Divide1'
   *  Product: '<S210>/Product1'
   *  Product: '<S210>/Product2'
   *  Product: '<S210>/Product3'
   *  Product: '<S210>/Product4'
   *  Sum: '<S208>/Add'
   *  Sum: '<S210>/Subtract'
   *  UnitDelay: '<S208>/Unit Delay'
   */
  Motor_Torque += ((-0.00019999966F * rtDW.UnitDelay2 * rtDW.UnitDelay3 +
                    0.0260812F * rtDW.UnitDelay3) * 3.0F - Motor_Torque) *
    0.005F;

  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S205>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
   *  ActionPort: '<S206>/Action Port'
   */
  /* If: '<S6>/If1' incorporates:
   *  Inport: '<Root>/Start_Stop'
   *  SignalConversion generated from: '<S205>/Out1'
   *  SignalConversion generated from: '<S206>/Out1'
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
