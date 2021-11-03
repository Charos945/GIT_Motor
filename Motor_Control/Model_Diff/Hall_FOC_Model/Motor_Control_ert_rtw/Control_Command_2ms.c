/*
 * File: Control_Command_2ms.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Nov  1 17:42:50 2021
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

/* Disable for action system: '<S80>/Speed_PI' */
void Speed_PI_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_g = rtDW.DiscreteTimeIntegrator_f;
}

/* Output and update for action system: '<S80>/Speed_PI' */
void Speed_PI(void)
{
  real32_T rtb_Add_i;
  real32_T rtb_Saturation;
  real32_T tmp;

  /* Sum: '<S84>/Sum' incorporates:
   *  Inport: '<Root>/Speed_target'
   *  Outport: '<Root>/Speed_Measured'
   */
  rtb_Saturation = rtU.Speed_target - rtY.Speed_Measured;

  /* Switch: '<S85>/Switch' incorporates:
   *  Constant: '<S85>/Cons'
   *  UnitDelay: '<S85>/Unit Delay3'
   */
  if (rtDW.UnitDelay3_DSTATE_m) {
    tmp = rtb_Saturation;
  } else {
    tmp = 0.0F;
  }

  /* End of Switch: '<S85>/Switch' */

  /* DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_h != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE_g = 0.0F;
  }

  /* DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_f = rtDW.DiscreteTimeIntegrator_DSTATE_g;

  /* Sum: '<S85>/Add' incorporates:
   *  Constant: '<S85>/Kp'
   *  Product: '<S85>/Product'
   */
  rtb_Add_i = PI_Parameter.Speed_Kp * rtb_Saturation +
    rtDW.DiscreteTimeIntegrator_f;

  /* Saturate: '<S85>/Saturation' */
  if (rtb_Add_i > PI_Parameter.Speed_PI_OutputMax) {
    rtb_Saturation = PI_Parameter.Speed_PI_OutputMax;
  } else if (rtb_Add_i < PI_Parameter.Speed_PI_OutputMin) {
    rtb_Saturation = PI_Parameter.Speed_PI_OutputMin;
  } else {
    rtb_Saturation = rtb_Add_i;
  }

  /* End of Saturate: '<S85>/Saturation' */

  /* Merge: '<S80>/Merge' incorporates:
   *  SignalConversion generated from: '<S82>/Iq_ref'
   */
  rtDW.Merge_c = rtb_Saturation;

  /* Update for UnitDelay: '<S85>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S85>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_m = (rtb_Add_i == rtb_Saturation);

  /* Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S85>/Ki'
   *  Product: '<S85>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_g += PI_Parameter.Speed_Ki * tmp * 0.002F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_h = (int8_T)(rtDW.Merge1_a > 0);
}

/* Output and update for action system: '<S80>/Switch Case Action Subsystem' */
void SwitchCaseActionSubsystem(void)
{
  /* Inport: '<S83>/Iq_in' incorporates:
   *  Inport: '<Root>/Torque_ref'
   */
  rtDW.Merge_c = rtU.Torque_ref;
}

/* System initialize for atomic system: '<S4>/Control_Command_2ms' */
void Control_Command_2ms_Init(void)
{
  /* Start for SwitchCase: '<S80>/Switch Case' */
  rtDW.SwitchCase_ActiveSubsystem = -1;
}

/* Output and update for atomic system: '<S4>/Control_Command_2ms' */
void Control_Command_2ms(void)
{
  int8_T rtAction;
  int8_T rtPrevAction;

  /* SwitchCase: '<S80>/Switch Case' incorporates:
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
    /* Outputs for IfAction SubSystem: '<S80>/Speed_PI' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    Speed_PI();

    /* End of Outputs for SubSystem: '<S80>/Speed_PI' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S80>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    SwitchCaseActionSubsystem();

    /* End of Outputs for SubSystem: '<S80>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S80>/Switch Case' */
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

/* Disable for atomic system: '<S86>/Flux_weak' */
void Flux_weak_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_l = rtDW.DiscreteTimeIntegrator;
}

/* Output and update for atomic system: '<S86>/Flux_weak' */
void Flux_weak(void)
{
  real32_T rtb_Add_g;
  real32_T rtb_Saturation;
  real32_T tmp;

  /* Fcn: '<S88>/Fcn' */
  rtb_Saturation = rt_powf_snf(rtDW.UnitDelay1, 2.0F) + rt_powf_snf
    (rtDW.UnitDelay4, 2.0F);

  /* If: '<S88>/If1' incorporates:
   *  Constant: '<S88>/Over_modulation'
   *  Gain: '<S90>/Gain'
   *  Gain: '<S91>/Gain'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S88>/Over_M' incorporates:
     *  ActionPort: '<S91>/Action Port'
     */
    tmp = 0.666666687F * rtU.Bus_Voltage;

    /* End of Outputs for SubSystem: '<S88>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S88>/Normal' incorporates:
     *  ActionPort: '<S90>/Action Port'
     */
    tmp = 0.577350259F * rtU.Bus_Voltage;

    /* End of Outputs for SubSystem: '<S88>/Normal' */
  }

  /* End of If: '<S88>/If1' */

  /* Fcn: '<S88>/Fcn' */
  if (rtb_Saturation < 0.0F) {
    rtb_Saturation = -sqrtf(-rtb_Saturation);
  } else {
    rtb_Saturation = sqrtf(rtb_Saturation);
  }

  /* Sum: '<S88>/Sum1' */
  rtb_Saturation = tmp - rtb_Saturation;

  /* Switch: '<S89>/Switch' incorporates:
   *  Constant: '<S89>/Cons'
   *  UnitDelay: '<S89>/Unit Delay3'
   */
  if (rtDW.UnitDelay3_DSTATE_c) {
    tmp = rtb_Saturation;
  } else {
    tmp = 0.0F;
  }

  /* End of Switch: '<S89>/Switch' */

  /* DiscreteIntegrator: '<S89>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE_l = 0.0F;
  }

  /* DiscreteIntegrator: '<S89>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE_l;

  /* Sum: '<S89>/Add' incorporates:
   *  Constant: '<S89>/Kp'
   *  Product: '<S89>/Product'
   */
  rtb_Add_g = FluxWeak_Parameter.FluxWeak_Kp * rtb_Saturation +
    rtDW.DiscreteTimeIntegrator;

  /* Saturate: '<S89>/Saturation' */
  if (rtb_Add_g > FluxWeak_Parameter.FluxWeak_Idref_max) {
    rtb_Saturation = FluxWeak_Parameter.FluxWeak_Idref_max;
  } else if (rtb_Add_g < FluxWeak_Parameter.FluxWeak_Idref_min) {
    rtb_Saturation = FluxWeak_Parameter.FluxWeak_Idref_min;
  } else {
    rtb_Saturation = rtb_Add_g;
  }

  /* End of Saturate: '<S89>/Saturation' */

  /* Sum: '<S88>/Add1' */
  Id_ref = rtb_Saturation;

  /* Inport: '<S88>/Iq_input' */
  Iq_ref = rtDW.Merge_c;

  /* Update for UnitDelay: '<S89>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S89>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_c = (rtb_Add_g == rtb_Saturation);

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S89>/Ki'
   *  Product: '<S89>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_l += FluxWeak_Parameter.FluxWeak_Ki * tmp *
    0.002F;
  rtDW.DiscreteTimeIntegrator_PrevResetState = (int8_T)(rtDW.Merge1_a > 0);
}

/* System initialize for function-call system: '<S2>/Control_Command_2ms' */
void Control_Command_2ms_o_Init(void)
{
  /* Start for If: '<S81>/If1' */
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

  /* Outputs for Atomic SubSystem: '<S4>/Control_Command_2ms' */
  Control_Command_2ms();

  /* End of Outputs for SubSystem: '<S4>/Control_Command_2ms' */

  /* If: '<S81>/If1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Inport: '<S87>/Id'
   *  Inport: '<S87>/Iq'
   */
  rtPrevAction = rtDW.If1_ActiveSubsystem;
  rtAction = (int8_T)(FluxWeak_Parameter.FluxWeak_Enable != 1);
  rtDW.If1_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for Atomic SubSystem: '<S86>/Flux_weak' */
    Flux_weak_Disable();

    /* End of Disable for SubSystem: '<S86>/Flux_weak' */
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S81>/Subsystem' incorporates:
     *  ActionPort: '<S86>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S86>/Flux_weak' */
    Flux_weak();

    /* End of Outputs for SubSystem: '<S86>/Flux_weak' */
    /* End of Outputs for SubSystem: '<S81>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S81>/Subsystem1' incorporates:
     *  ActionPort: '<S87>/Action Port'
     */
    Id_ref = 0.0F;
    Iq_ref = rtDW.Merge_c;

    /* End of Outputs for SubSystem: '<S81>/Subsystem1' */
  }

  /* End of If: '<S81>/If1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
