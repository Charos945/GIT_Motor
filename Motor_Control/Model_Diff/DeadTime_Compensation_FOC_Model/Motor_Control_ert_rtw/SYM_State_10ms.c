/*
 * File: SYM_State_10ms.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct 29 16:39:03 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
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
  /* Sum: '<S60>/Add1' incorporates:
   *  Constant: '<S60>/Constant1'
   *  Product: '<S60>/Divide1'
   *  Product: '<S62>/Product'
   *  Product: '<S62>/Product1'
   *  Sum: '<S60>/Add'
   *  Sum: '<S62>/Add'
   *  UnitDelay: '<S60>/Unit Delay'
   */
  Motor_Power += ((rtDW.UnitDelay2 * rtDW.UnitDelay1 + rtDW.UnitDelay3 *
                   rtDW.UnitDelay4) - Motor_Power) * 0.005F;

  /* Sum: '<S61>/Add1' incorporates:
   *  Constant: '<S61>/Constant1'
   *  Constant: '<S63>/Constant2'
   *  Product: '<S61>/Divide1'
   *  Product: '<S63>/Product1'
   *  Product: '<S63>/Product2'
   *  Product: '<S63>/Product3'
   *  Product: '<S63>/Product4'
   *  Sum: '<S61>/Add'
   *  Sum: '<S63>/Subtract'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  Motor_Torque += ((-0.000171500011F * rtDW.UnitDelay2 * rtDW.UnitDelay3 +
                    0.1125F * rtDW.UnitDelay3) * 6.0F - Motor_Torque) * 0.005F;

  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S58>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
   *  ActionPort: '<S59>/Action Port'
   */
  /* If: '<S6>/If1' incorporates:
   *  Inport: '<Root>/Start_Stop'
   *  SignalConversion generated from: '<S58>/Out1'
   *  SignalConversion generated from: '<S59>/Out1'
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
