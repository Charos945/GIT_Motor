/*
 * File: Control_Command_2ms.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Nov 19 17:54:27 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Control_Command_2ms.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* System initialize for action system: '<S25>/Speed_PI' */
void Speed_PI_Init(void)
{
  /* Start for If: '<S30>/If1' */
  rtDW.If1_ActiveSubsystem = -1;
}

/* Disable for action system: '<S25>/Speed_PI' */
void Speed_PI_Disable(void)
{
  /* Disable for If: '<S30>/If1' */
  switch (rtDW.If1_ActiveSubsystem) {
   case 0:
    /* Disable for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE_d = rtDW.DiscreteTimeIntegrator_m;
    break;

   case 1:
    /* Disable for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE = rtDW.DiscreteTimeIntegrator;
    break;

   case 2:
    break;
  }

  rtDW.If1_ActiveSubsystem = -1;

  /* End of Disable for If: '<S30>/If1' */
}

/* Output and update for action system: '<S25>/Speed_PI' */
void Speed_PI(void)
{
  real32_T rtb_Saturation;
  real32_T rtb_Sum_o;
  real32_T tmp;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Sum: '<S29>/Sum' incorporates:
   *  Inport: '<Root>/Speed_target'
   */
  rtb_Sum_o = rtU.Speed_target - rtDW.Merge;

  /* If: '<S30>/If1' incorporates:
   *  Constant: '<S30>/HFI_Enalble'
   */
  rtPrevAction = rtDW.If1_ActiveSubsystem;
  if ((rtDW.UnitDelay7 == 3) && (HFI_Parameter.HFI_Fuc_Enalbe == 1)) {
    rtAction = 0;
  } else if (HFI_Parameter.HFI_Fuc_Enalbe == 0) {
    rtAction = 1;
  } else {
    rtAction = 2;
  }

  rtDW.If1_ActiveSubsystem = rtAction;
  if (rtPrevAction != rtAction) {
    switch (rtPrevAction) {
     case 0:
      /* Disable for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_DSTATE_d = rtDW.DiscreteTimeIntegrator_m;
      break;

     case 1:
      /* Disable for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_DSTATE = rtDW.DiscreteTimeIntegrator;
      break;

     case 2:
      break;
    }
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S30>/Speed_Control' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/Cons'
     *  UnitDelay: '<S31>/Unit Delay3'
     */
    if (rtDW.UnitDelay3_DSTATE_a) {
      tmp = rtb_Sum_o;
    } else {
      tmp = 0.0F;
    }

    /* End of Switch: '<S31>/Switch' */

    /* DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_m = rtDW.DiscreteTimeIntegrator_DSTATE_d;

    /* Sum: '<S31>/Add' incorporates:
     *  Constant: '<S31>/Kp'
     *  Product: '<S31>/Product'
     */
    rtb_Sum_o = PI_Parameter.Speed_Kp * rtb_Sum_o +
      rtDW.DiscreteTimeIntegrator_m;

    /* Saturate: '<S31>/Saturation' */
    if (rtb_Sum_o > PI_Parameter.Speed_PI_OutputMax) {
      rtb_Saturation = PI_Parameter.Speed_PI_OutputMax;
    } else if (rtb_Sum_o < PI_Parameter.Speed_PI_OutputMin) {
      rtb_Saturation = PI_Parameter.Speed_PI_OutputMin;
    } else {
      rtb_Saturation = rtb_Sum_o;
    }

    /* End of Saturate: '<S31>/Saturation' */

    /* SignalConversion generated from: '<S31>/PI_Out' */
    Iq_ref = rtb_Saturation;

    /* Update for UnitDelay: '<S31>/Unit Delay3' incorporates:
     *  RelationalOperator: '<S31>/Relational Operator1'
     */
    rtDW.UnitDelay3_DSTATE_a = (rtb_Sum_o == rtb_Saturation);

    /* Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S31>/Ki'
     *  Product: '<S31>/Product1'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE_d += PI_Parameter.Speed_Ki * tmp * 0.002F;

    /* End of Outputs for SubSystem: '<S30>/Speed_Control' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S30>/Speed_Control1' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S32>/Cons'
     *  UnitDelay: '<S32>/Unit Delay3'
     */
    if (rtDW.UnitDelay3_DSTATE_l) {
      tmp = rtb_Sum_o;
    } else {
      tmp = 0.0F;
    }

    /* End of Switch: '<S32>/Switch' */

    /* DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE;

    /* Sum: '<S32>/Add' incorporates:
     *  Constant: '<S32>/Kp'
     *  Product: '<S32>/Product'
     */
    rtb_Sum_o = PI_Parameter.Speed_Kp * rtb_Sum_o + rtDW.DiscreteTimeIntegrator;

    /* Saturate: '<S32>/Saturation' */
    if (rtb_Sum_o > PI_Parameter.Speed_PI_OutputMax) {
      rtb_Saturation = PI_Parameter.Speed_PI_OutputMax;
    } else if (rtb_Sum_o < PI_Parameter.Speed_PI_OutputMin) {
      rtb_Saturation = PI_Parameter.Speed_PI_OutputMin;
    } else {
      rtb_Saturation = rtb_Sum_o;
    }

    /* End of Saturate: '<S32>/Saturation' */

    /* SignalConversion generated from: '<S32>/PI_Out' */
    Iq_ref = rtb_Saturation;

    /* Update for UnitDelay: '<S32>/Unit Delay3' incorporates:
     *  RelationalOperator: '<S32>/Relational Operator1'
     */
    rtDW.UnitDelay3_DSTATE_l = (rtb_Sum_o == rtb_Saturation);

    /* Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S32>/Ki'
     *  Product: '<S32>/Product1'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE += PI_Parameter.Speed_Ki * tmp * 0.002F;

    /* End of Outputs for SubSystem: '<S30>/Speed_Control1' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S30>/Speed_Control2' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* SignalConversion generated from: '<S33>/PI_Out' incorporates:
     *  Constant: '<S33>/Constant'
     */
    Iq_ref = 0.0F;

    /* End of Outputs for SubSystem: '<S30>/Speed_Control2' */
    break;
  }

  /* End of If: '<S30>/If1' */
}

/* Output and update for action system: '<S25>/Switch Case Action Subsystem' */
void SwitchCaseActionSubsystem(void)
{
  /* Inport: '<S28>/Iq_in' incorporates:
   *  Inport: '<Root>/Torque_ref'
   */
  Iq_ref = rtU.Torque_ref;
}

/* System initialize for atomic system: '<S4>/Control_Command_2ms' */
void Control_Command_2ms_Init(void)
{
  /* Start for SwitchCase: '<S25>/Switch Case' */
  rtDW.SwitchCase_ActiveSubsystem = -1;

  /* SystemInitialize for IfAction SubSystem: '<S25>/Speed_PI' */
  Speed_PI_Init();

  /* End of SystemInitialize for SubSystem: '<S25>/Speed_PI' */
}

/* Output and update for atomic system: '<S4>/Control_Command_2ms' */
void Control_Command_2ms(void)
{
  int8_T rtAction;
  int8_T rtPrevAction;

  /* SwitchCase: '<S25>/Switch Case' incorporates:
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
    /* Outputs for IfAction SubSystem: '<S25>/Speed_PI' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    Speed_PI();

    /* End of Outputs for SubSystem: '<S25>/Speed_PI' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S25>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    SwitchCaseActionSubsystem();

    /* End of Outputs for SubSystem: '<S25>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S25>/Switch Case' */
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

  /* If: '<S26>/If1' incorporates:
   *  Constant: '<S26>/Flux_Enable'
   *  Inport: '<S34>/Hall_Speed'
   *  Inport: '<S35>/Obs_Speed'
   */
  if (SMO_Parameter.SMO_Theta_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S26>/Obs_Spd' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    rtDW.Merge = Obs_Speed;

    /* End of Outputs for SubSystem: '<S26>/Obs_Spd' */
  } else {
    if (SMO_Parameter.SMO_Theta_Enable == 0) {
      /* Outputs for IfAction SubSystem: '<S26>/Hall_Spd' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      rtDW.Merge = Hall_Speed;

      /* End of Outputs for SubSystem: '<S26>/Hall_Spd' */
    }
  }

  /* End of If: '<S26>/If1' */

  /* Outputs for Atomic SubSystem: '<S4>/Control_Command_2ms' */
  Control_Command_2ms();

  /* End of Outputs for SubSystem: '<S4>/Control_Command_2ms' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
