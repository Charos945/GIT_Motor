/*
 * File: SYM_State_10ms.c
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

#include "SYM_State_10ms.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Output and update for function-call system: '<S2>/SYM_State_10ms' */
void SYM_State_10ms(void)
{
  /* Sum: '<S189>/Add1' incorporates:
   *  Constant: '<S189>/Constant1'
   *  Product: '<S189>/Divide1'
   *  Product: '<S191>/Product'
   *  Product: '<S191>/Product1'
   *  Sum: '<S189>/Add'
   *  Sum: '<S191>/Add'
   *  UnitDelay: '<S189>/Unit Delay'
   */
  Motor_Power += ((rtDW.UnitDelay2 * rtDW.UnitDelay1 + rtDW.UnitDelay3 *
                   rtDW.UnitDelay4) - Motor_Power) * 0.005F;

  /* Sum: '<S190>/Add1' incorporates:
   *  Constant: '<S190>/Constant1'
   *  Constant: '<S192>/Constant2'
   *  Product: '<S190>/Divide1'
   *  Product: '<S192>/Product1'
   *  Product: '<S192>/Product2'
   *  Product: '<S192>/Product3'
   *  Product: '<S192>/Product4'
   *  Sum: '<S190>/Add'
   *  Sum: '<S192>/Subtract'
   *  UnitDelay: '<S190>/Unit Delay'
   */
  Motor_Torque += ((-5.00000024E-5F * rtDW.UnitDelay2 * rtDW.UnitDelay3 +
                    0.00529276F * rtDW.UnitDelay3) * 3.0F - Motor_Torque) *
    0.005F;

  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S187>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
   *  ActionPort: '<S188>/Action Port'
   */
  /* If: '<S6>/If1' incorporates:
   *  Inport: '<Root>/Start_Stop'
   *  SignalConversion generated from: '<S187>/Out1'
   *  SignalConversion generated from: '<S188>/Out1'
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
