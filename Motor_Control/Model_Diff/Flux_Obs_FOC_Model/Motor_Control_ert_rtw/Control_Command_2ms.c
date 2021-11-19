/*
 * File: Control_Command_2ms.c
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

#include "Control_Command_2ms.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Disable for action system: '<S25>/Speed_PI' */
void Speed_PI_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_g = rtDW.DiscreteTimeIntegrator_f;
}

/* Output and update for action system: '<S25>/Speed_PI' */
void Speed_PI(void)
{
  real32_T rtb_Add;
  real32_T rtb_Saturation;
  real32_T tmp;

  /* Sum: '<S30>/Sum' incorporates:
   *  Inport: '<Root>/Speed_target'
   */
  rtb_Saturation = rtU.Speed_target - rtDW.Merge;

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/Cons'
   *  UnitDelay: '<S31>/Unit Delay3'
   */
  if (rtDW.UnitDelay3_DSTATE_m) {
    tmp = rtb_Saturation;
  } else {
    tmp = 0.0F;
  }

  /* End of Switch: '<S31>/Switch' */

  /* DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_h != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE_g = 0.0F;
  }

  /* DiscreteIntegrator: '<S31>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_f = rtDW.DiscreteTimeIntegrator_DSTATE_g;

  /* Sum: '<S31>/Add' incorporates:
   *  Constant: '<S31>/Kp'
   *  Product: '<S31>/Product'
   */
  rtb_Add = PI_Parameter.Speed_Kp * rtb_Saturation +
    rtDW.DiscreteTimeIntegrator_f;

  /* Saturate: '<S31>/Saturation' */
  if (rtb_Add > PI_Parameter.Speed_PI_OutputMax) {
    rtb_Saturation = PI_Parameter.Speed_PI_OutputMax;
  } else if (rtb_Add < PI_Parameter.Speed_PI_OutputMin) {
    rtb_Saturation = PI_Parameter.Speed_PI_OutputMin;
  } else {
    rtb_Saturation = rtb_Add;
  }

  /* End of Saturate: '<S31>/Saturation' */

  /* Merge: '<S25>/Merge' incorporates:
   *  SignalConversion generated from: '<S28>/Iq_ref'
   */
  rtDW.Merge_c = rtb_Saturation;

  /* Update for UnitDelay: '<S31>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S31>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_m = (rtb_Add == rtb_Saturation);

  /* Update for DiscreteIntegrator: '<S31>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S31>/Ki'
   *  Product: '<S31>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_g += PI_Parameter.Speed_Ki * tmp * 0.002F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_h = (int8_T)(rtDW.Merge1_a > 0);
}

/* Output and update for action system: '<S25>/Switch Case Action Subsystem' */
void SwitchCaseActionSubsystem(void)
{
  /* Inport: '<S29>/Iq_in' incorporates:
   *  Inport: '<Root>/Torque_ref'
   */
  rtDW.Merge_c = rtU.Torque_ref;
}

/* System initialize for atomic system: '<S4>/Control_Command_2ms' */
void Control_Command_2ms_Init(void)
{
  /* Start for SwitchCase: '<S25>/Switch Case' */
  rtDW.SwitchCase_ActiveSubsystem = -1;
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
     *  ActionPort: '<S28>/Action Port'
     */
    Speed_PI();

    /* End of Outputs for SubSystem: '<S25>/Speed_PI' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S25>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    SwitchCaseActionSubsystem();

    /* End of Outputs for SubSystem: '<S25>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S25>/Switch Case' */
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T tmp;
  real32_T tmp_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = fabsf(u0);
    tmp_0 = fabsf(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = sqrtf(u0);
    } else if ((u0 < 0.0F) && (u1 > floorf(u1))) {
      y = (rtNaNF);
    } else {
      y = powf(u0, u1);
    }
  }

  return y;
}

/* Disable for atomic system: '<S32>/Flux_weak' */
void Flux_weak_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE = rtDW.DiscreteTimeIntegrator;
}

/* Output and update for atomic system: '<S32>/Flux_weak' */
void Flux_weak(void)
{
  real32_T rtb_Add;
  real32_T rtb_Saturation;
  real32_T tmp;

  /* Fcn: '<S34>/Fcn' */
  rtb_Saturation = rt_powf_snf(rtDW.UnitDelay1, 2.0F) + rt_powf_snf
    (rtDW.UnitDelay4, 2.0F);

  /* If: '<S34>/If1' incorporates:
   *  Constant: '<S34>/Over_modulation'
   *  Gain: '<S36>/Gain'
   *  Gain: '<S37>/Gain'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S34>/Over_M' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    tmp = 0.666666687F * rtU.Bus_Voltage;

    /* End of Outputs for SubSystem: '<S34>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S34>/Normal' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    tmp = 0.577350259F * rtU.Bus_Voltage;

    /* End of Outputs for SubSystem: '<S34>/Normal' */
  }

  /* End of If: '<S34>/If1' */

  /* Fcn: '<S34>/Fcn' */
  if (rtb_Saturation < 0.0F) {
    rtb_Saturation = -sqrtf(-rtb_Saturation);
  } else {
    rtb_Saturation = sqrtf(rtb_Saturation);
  }

  /* Sum: '<S34>/Sum1' */
  rtb_Saturation = tmp - rtb_Saturation;

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/Cons'
   *  UnitDelay: '<S35>/Unit Delay3'
   */
  if (rtDW.UnitDelay3_DSTATE_c) {
    tmp = rtb_Saturation;
  } else {
    tmp = 0.0F;
  }

  /* End of Switch: '<S35>/Switch' */

  /* DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE = 0.0F;
  }

  /* DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE;

  /* Sum: '<S35>/Add' incorporates:
   *  Constant: '<S35>/Kp'
   *  Product: '<S35>/Product'
   */
  rtb_Add = FluxWeak_Parameter.FluxWeak_Kp * rtb_Saturation +
    rtDW.DiscreteTimeIntegrator;

  /* Saturate: '<S35>/Saturation' */
  if (rtb_Add > FluxWeak_Parameter.FluxWeak_Idref_max) {
    rtb_Saturation = FluxWeak_Parameter.FluxWeak_Idref_max;
  } else if (rtb_Add < FluxWeak_Parameter.FluxWeak_Idref_min) {
    rtb_Saturation = FluxWeak_Parameter.FluxWeak_Idref_min;
  } else {
    rtb_Saturation = rtb_Add;
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* Sum: '<S34>/Add1' */
  Id_ref = rtb_Saturation;

  /* Inport: '<S34>/Iq_input' */
  Iq_ref = rtDW.Merge_c;

  /* Update for UnitDelay: '<S35>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S35>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_c = (rtb_Add == rtb_Saturation);

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S35>/Ki'
   *  Product: '<S35>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE += FluxWeak_Parameter.FluxWeak_Ki * tmp *
    0.002F;
  rtDW.DiscreteTimeIntegrator_PrevResetState = (int8_T)(rtDW.Merge1_a > 0);
}

/* System initialize for function-call system: '<S2>/Control_Command_2ms' */
void Control_Command_2ms_o_Init(void)
{
  /* Start for If: '<S26>/If1' */
  rtDW.If1_ActiveSubsystem = -1;

  /* SystemInitialize for Atomic SubSystem: '<S4>/Control_Command_2ms' */
  Control_Command_2ms_Init();

  /* End of SystemInitialize for SubSystem: '<S4>/Control_Command_2ms' */
}

/* Output and update for function-call system: '<S2>/Control_Command_2ms' */
void Control_Command_2ms_k(void)
{
  int8_T rtAction;
  int8_T rtPrevAction;

  /* If: '<S27>/If1' incorporates:
   *  Constant: '<S27>/Flux_Enable'
   *  Inport: '<S38>/Hall_Speed'
   *  Inport: '<S39>/Obs_Speed'
   */
  if (Flux_Parameter.Flux_Theta_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S27>/Obs_Spd' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    rtDW.Merge = Obs_Speed;

    /* End of Outputs for SubSystem: '<S27>/Obs_Spd' */
  } else {
    if (Flux_Parameter.Flux_Theta_Enable == 0) {
      /* Outputs for IfAction SubSystem: '<S27>/Hall_Spd' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      rtDW.Merge = Hall_Speed;

      /* End of Outputs for SubSystem: '<S27>/Hall_Spd' */
    }
  }

  /* End of If: '<S27>/If1' */

  /* Outputs for Atomic SubSystem: '<S4>/Control_Command_2ms' */
  Control_Command_2ms();

  /* End of Outputs for SubSystem: '<S4>/Control_Command_2ms' */

  /* If: '<S26>/If1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Inport: '<S33>/Id'
   *  Inport: '<S33>/Iq'
   */
  rtPrevAction = rtDW.If1_ActiveSubsystem;
  rtAction = (int8_T)(FluxWeak_Parameter.FluxWeak_Enable != 1);
  rtDW.If1_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for Atomic SubSystem: '<S32>/Flux_weak' */
    Flux_weak_Disable();

    /* End of Disable for SubSystem: '<S32>/Flux_weak' */
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S26>/Subsystem' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S32>/Flux_weak' */
    Flux_weak();

    /* End of Outputs for SubSystem: '<S32>/Flux_weak' */
    /* End of Outputs for SubSystem: '<S26>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/Subsystem1' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    Id_ref = 0.0F;
    Iq_ref = rtDW.Merge_c;

    /* End of Outputs for SubSystem: '<S26>/Subsystem1' */
  }

  /* End of If: '<S26>/If1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
