/*
 * File: SYM_State_10ms.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 18 15:11:34 2021
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
  /* Sum: '<S133>/Add1' incorporates:
   *  Constant: '<S133>/Constant1'
   *  Product: '<S133>/Divide1'
   *  Product: '<S135>/Product'
   *  Product: '<S135>/Product1'
   *  Sum: '<S133>/Add'
   *  Sum: '<S135>/Add'
   *  UnitDelay: '<S133>/Unit Delay'
   */
  Motor_Power += ((rtDW.UnitDelay2 * rtDW.UnitDelay1 + rtDW.UnitDelay3 *
                   rtDW.UnitDelay4) - Motor_Power) * 0.005F;

  /* Sum: '<S134>/Add1' incorporates:
   *  Constant: '<S134>/Constant1'
   *  Constant: '<S136>/Constant2'
   *  Product: '<S134>/Divide1'
   *  Product: '<S136>/Product1'
   *  Product: '<S136>/Product2'
   *  Product: '<S136>/Product3'
   *  Product: '<S136>/Product4'
   *  Sum: '<S134>/Add'
   *  Sum: '<S136>/Subtract'
   *  UnitDelay: '<S134>/Unit Delay'
   */
  Motor_Torque += ((-5.00000024E-5F * rtDW.UnitDelay2 * rtDW.UnitDelay3 +
                    0.00529276F * rtDW.UnitDelay3) * 3.0F - Motor_Torque) *
    0.005F;

  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S131>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
   *  ActionPort: '<S132>/Action Port'
   */
  /* If: '<S6>/If1' incorporates:
   *  Inport: '<Root>/Start_Stop'
   *  SignalConversion generated from: '<S131>/Out1'
   *  SignalConversion generated from: '<S132>/Out1'
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
