/*
 * File: Control_Command_2ms.c
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

#include "Control_Command_2ms.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Disable for action system: '<S10>/Speed_PI' */
void Speed_PI_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE = rtDW.DiscreteTimeIntegrator;
}

/* Output and update for action system: '<S10>/Speed_PI' */
void Speed_PI(void)
{
  real32_T rtb_Add_i;
  real32_T rtb_Saturation;
  real32_T tmp;

  /* Sum: '<S13>/Sum' incorporates:
   *  Inport: '<Root>/Speed_target'
   *  Outport: '<Root>/Speed_Measured'
   */
  rtb_Saturation = rtU.Speed_target - rtY.Speed_Measured;

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Cons'
   *  UnitDelay: '<S14>/Unit Delay3'
   */
  if (rtDW.UnitDelay3_DSTATE_m) {
    tmp = rtb_Saturation;
  } else {
    tmp = 0.0F;
  }

  /* End of Switch: '<S14>/Switch' */

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevRese != 0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE = 0.0F;
  }

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE;

  /* Sum: '<S14>/Add' incorporates:
   *  Constant: '<S14>/Kp'
   *  Product: '<S14>/Product'
   */
  rtb_Add_i = PI_Parameter.Speed_Kp * rtb_Saturation +
    rtDW.DiscreteTimeIntegrator;

  /* Saturate: '<S14>/Saturation' */
  if (rtb_Add_i > PI_Parameter.Speed_PI_OutputMax) {
    rtb_Saturation = PI_Parameter.Speed_PI_OutputMax;
  } else if (rtb_Add_i < PI_Parameter.Speed_PI_OutputMin) {
    rtb_Saturation = PI_Parameter.Speed_PI_OutputMin;
  } else {
    rtb_Saturation = rtb_Add_i;
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* SignalConversion generated from: '<S11>/Iq_ref' */
  Iq_ref = rtb_Saturation;

  /* Update for UnitDelay: '<S14>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S14>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_m = (rtb_Add_i == rtb_Saturation);

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S14>/Ki'
   *  Product: '<S14>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE += PI_Parameter.Speed_Ki * tmp * 0.002F;
  rtDW.DiscreteTimeIntegrator_PrevRese = (int8_T)(rtDW.Merge1_a > 0);
}

/* Output and update for action system: '<S10>/Switch Case Action Subsystem' */
void SwitchCaseActionSubsystem(void)
{
  /* Inport: '<S12>/Iq_in' incorporates:
   *  Inport: '<Root>/Torque_ref'
   */
  Iq_ref = rtU.Torque_ref;
}

/* System initialize for atomic system: '<S4>/Control_Command_2ms' */
void Control_Command_2ms_Init(void)
{
  /* Start for SwitchCase: '<S10>/Switch Case' */
  rtDW.SwitchCase_ActiveSubsystem = -1;
}

/* Output and update for atomic system: '<S4>/Control_Command_2ms' */
void Control_Command_2ms(void)
{
  int8_T rtAction;
  int8_T rtPrevAction;

  /* SwitchCase: '<S10>/Switch Case' incorporates:
   *  Constant: '<S2>/Control_Mode'
   */
  rtPrevAction = rtDW.SwitchCase_ActiveSubsystem;
  switch (CTL_Parameter.TorqueMode) {
   case 0:
    rtAction = 0;
    break;

   case 1:
    rtAction = 1;
    break;

   default:
    rtAction = 2;
    break;
  }

  rtDW.SwitchCase_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    Speed_PI_Disable();
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S10>/Speed_PI' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    Speed_PI();

    /* End of Outputs for SubSystem: '<S10>/Speed_PI' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S10>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    SwitchCaseActionSubsystem();

    /* End of Outputs for SubSystem: '<S10>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S10>/Switch Case' */
}

/* System initialize for function-call system: '<S2>/Control_Command_2ms' */
void Control_Command_2ms_o_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S4>/Control_Command_2ms' */
  Control_Command_2ms_Init();

  /* End of SystemInitialize for SubSystem: '<S4>/Control_Command_2ms' */
}

/* Output and update for function-call system: '<S2>/Control_Command_2ms' */
void Control_Command_2ms_k(void)
{
  /* SignalConversion generated from: '<S4>/Id_ref' */
  Id_ref = 0.0F;

  /* Outputs for Atomic SubSystem: '<S4>/Control_Command_2ms' */
  Control_Command_2ms();

  /* End of Outputs for SubSystem: '<S4>/Control_Command_2ms' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
