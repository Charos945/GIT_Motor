/*
 * File: SYM_State_10ms.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Nov 16 10:26:25 2021
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
  /* Sum: '<S130>/Add1' incorporates:
   *  Constant: '<S130>/Constant1'
   *  Product: '<S130>/Divide1'
   *  Product: '<S132>/Product'
   *  Product: '<S132>/Product1'
   *  Sum: '<S130>/Add'
   *  Sum: '<S132>/Add'
   *  UnitDelay: '<S130>/Unit Delay'
   */
  Motor_Power += ((rtDW.UnitDelay2 * rtDW.UnitDelay1 + rtDW.UnitDelay3 *
                   rtDW.UnitDelay4) - Motor_Power) * 0.005F;

  /* Sum: '<S131>/Add1' incorporates:
   *  Constant: '<S131>/Constant1'
   *  Constant: '<S133>/Constant2'
   *  Product: '<S131>/Divide1'
   *  Product: '<S133>/Product1'
   *  Product: '<S133>/Product2'
   *  Product: '<S133>/Product3'
   *  Product: '<S133>/Product4'
   *  Sum: '<S131>/Add'
   *  Sum: '<S133>/Subtract'
   *  UnitDelay: '<S131>/Unit Delay'
   */
  Motor_Torque += ((-0.00019999966F * rtDW.UnitDelay2 * rtDW.UnitDelay3 +
                    0.0260812F * rtDW.UnitDelay3) * 3.0F - Motor_Torque) *
    0.005F;

  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S128>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
   *  ActionPort: '<S129>/Action Port'
   */
  /* If: '<S6>/If1' incorporates:
   *  Inport: '<Root>/Start_Stop'
   *  SignalConversion generated from: '<S128>/Out1'
   *  SignalConversion generated from: '<S129>/Out1'
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
