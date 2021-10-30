/*
 * File: Angle_Speed_100us.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 3.5
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun Sep  5 09:33:37 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Angle_Speed_100us.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Named constants for Chart: '<S3>/State_machine' */
#define IN_Motor_CL                    ((uint8_T)1U)
#define IN_Motor_CL1                   ((uint8_T)2U)
#define IN_Motor_OPL                   ((uint8_T)3U)
#define IN_Motor_Start                 ((uint8_T)4U)
#define IN_Motor_Stop                  ((uint8_T)5U)

/* Output and update for atomic system: '<S3>/Angle_Selector' */
void Angle_Selector(void)
{
  /* If: '<S7>/If1' */
  if ((rtDW.Motor_state == 2) || (rtDW.Motor_state == 3)) {
    /* Outputs for IfAction SubSystem: '<S7>/Subsystem' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Merge: '<S7>/Merge' incorporates:
     *  Inport: '<S18>/In1'
     */
    rtDW.FOC_Angle = rtDW.Merge_g;

    /* End of Outputs for SubSystem: '<S7>/Subsystem' */
  } else {
    if (rtDW.Motor_state == 4) {
      /* Outputs for IfAction SubSystem: '<S7>/Subsystem1' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* Merge: '<S7>/Merge' incorporates:
       *  Inport: '<S19>/In1'
       *  Outport: '<Root>/Flux_Angle'
       */
      rtDW.FOC_Angle = rtY.Flux_Angle;

      /* End of Outputs for SubSystem: '<S7>/Subsystem1' */
    }
  }

  /* End of If: '<S7>/If1' */
}

/* Output and update for atomic system: '<S10>/Angle_calibration' */
void Angle_calibration_e(void)
{
  real32_T rtb_Subtract1_a;

  /* Sum: '<S135>/Subtract1' incorporates:
   *  Constant: '<S135>/Angle_offset'
   *  Outport: '<Root>/Wn_est'
   */
  rtb_Subtract1_a = rtY.Wn_est + SMO.Angle_offset;

  /* If: '<S135>/If1' */
  if (rtb_Subtract1_a > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S140>/Action Port'
     */
    IfActionSubsystem2_g(rtb_Subtract1_a, &rtDW.Merge1_a);

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem2' */
  } else if (rtb_Subtract1_a < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    IfActionSubsystem3(rtb_Subtract1_a, &rtDW.Merge1_a);

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S139>/Action Port'
     */
    /* Merge: '<S135>/Merge1' incorporates:
     *  Inport: '<S139>/In1'
     */
    rtDW.Merge1_a = rtb_Subtract1_a;

    /* End of Outputs for SubSystem: '<S135>/If Action Subsystem1' */
  }

  /* End of If: '<S135>/If1' */
}

/* Output and update for atomic system: '<S136>/Sine_Cosine' */
void Sine_Cosine_lc(void)
{
  real32_T rtb_Saturation;
  uint32_T Divide_tmp;

  /* Saturate: '<S142>/Saturation' incorporates:
   *  Outport: '<Root>/Wn_est'
   */
  if (rtY.Wn_est > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtY.Wn_est < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtY.Wn_est;
  }

  /* End of Saturate: '<S142>/Saturation' */

  /* Lookup_n-D: '<S142>/Cosine' incorporates:
   *  Lookup_n-D: '<S142>/Sine'
   *  Saturate: '<S142>/Saturation'
   */
  Divide_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);

  /* Product: '<S136>/Divide' incorporates:
   *  Lookup_n-D: '<S142>/Cosine'
   */
  rtDW.Divide = rtConstP.pooled31[Divide_tmp];

  /* Lookup_n-D: '<S142>/Sine' incorporates:
   *  Outport: '<Root>/Wn_est'
   */
  rtY.Wn_est = rtConstP.pooled33[Divide_tmp];
}

/* Output and update for atomic system: '<S10>/Delta_theta' */
void Delta_theta(void)
{
  real32_T rtb_Saturation;

  /* Outputs for Atomic SubSystem: '<S136>/Sine_Cosine' */
  Sine_Cosine_lc();

  /* End of Outputs for SubSystem: '<S136>/Sine_Cosine' */

  /* Sqrt: '<S136>/Sqrt' incorporates:
   *  Math: '<S136>/Math Function'
   *  Math: '<S136>/Math Function1'
   *  Sum: '<S136>/Add1'
   *
   * About '<S136>/Math Function':
   *  Operator: magnitude^2
   *
   * About '<S136>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Saturation = (real32_T)sqrt(rtDW.SFunctionBuilder_o3 *
    rtDW.SFunctionBuilder_o3 + rtDW.SFunctionBuilder_o4 *
    rtDW.SFunctionBuilder_o4);

  /* Saturate: '<S136>/Saturation' */
  if (rtb_Saturation <= 4.0F) {
    rtb_Saturation = 4.0F;
  }

  /* End of Saturate: '<S136>/Saturation' */

  /* Product: '<S136>/Divide' incorporates:
   *  Gain: '<S136>/Gain'
   *  Outport: '<Root>/Wn_est'
   *  Product: '<S136>/Product'
   *  Product: '<S136>/Product1'
   *  Sum: '<S136>/Add'
   */
  rtDW.Divide = -(rtDW.Divide * rtDW.SFunctionBuilder_o3 + rtY.Wn_est *
                  rtDW.SFunctionBuilder_o4) / rtb_Saturation;
}

/* Disable for action system: '<S3>/SMO' */
void SMO_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_k = rtDW.DiscreteTimeIntegrator;

  /* Disable for DiscreteIntegrator: '<S137>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_h = rtDW.DiscreteTimeIntegrator_a;
}

/* Output and update for action system: '<S3>/SMO' */
void SMO_l(void)
{
  real32_T rtb_Add;

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE_k;

  /* Gain: '<S10>/Gain3' */
  rtDW.Gain3 = 6.28318548F * rtDW.DiscreteTimeIntegrator;

  /* Math: '<S10>/Mod1' incorporates:
   *  Constant: '<S10>/2pi1'
   *  Outport: '<Root>/Wn_est'
   */
  rtY.Wn_est = rt_modf_snf(rtDW.Gain3, 6.28318548F);

  /* Outputs for Atomic SubSystem: '<S10>/Angle_calibration' */
  Angle_calibration_e();

  /* End of Outputs for SubSystem: '<S10>/Angle_calibration' */

  /* Inport: '<S10>/Ubeta' */
  rtDW.Ubeta = rtDW.UnitDelay3;

  /* UnitDelay: '<S10>/Unit Delay2' */
  rtDW.UnitDelay2_k = rtDW.UnitDelay2_DSTATE_p;

  /* S-Function (SMO_Function): '<S138>/S-Function Builder' incorporates:
   *  Constant: '<S138>/Constant'
   *  Constant: '<S138>/Constant1'
   *  Constant: '<S138>/Constant2'
   *  Constant: '<S138>/Constant3'
   *  Constant: '<S138>/Constant4'
   *  Constant: '<S138>/Constant5'
   *  Constant: '<S138>/Constant6'
   */
  SMO_Function_Outputs_wrapper(&rtDW.UnitDelay2, &rtDW.UnitDelay1,
    &rtDW.UnitDelay4, &rtDW.Ubeta, &rtDW.UnitDelay2_k, &SMO.A, &SMO.B, &SMO.C,
    &SMO.k, &SMO.m, &SMO.tao, &rtConstP.pooled30, &rtDW.SFunctionBuilder_o1,
    &rtDW.SFunctionBuilder_o2, &rtDW.SFunctionBuilder_o3,
    &rtDW.SFunctionBuilder_o4, &rtDW.SFunctionBuilder_o5,
    &rtDW.SFunctionBuilder_o6);

  /* Outputs for Atomic SubSystem: '<S10>/Delta_theta' */
  Delta_theta();

  /* End of Outputs for SubSystem: '<S10>/Delta_theta' */

  /* DiscreteIntegrator: '<S137>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_a = rtDW.DiscreteTimeIntegrator_DSTATE_h;

  /* Sum: '<S137>/Add' incorporates:
   *  Gain: '<S137>/Gain2'
   */
  rtb_Add = SMO.PLL_KP * rtDW.Divide + rtDW.DiscreteTimeIntegrator_a;

  /* Gain: '<S10>/Gain1' incorporates:
   *  Outport: '<Root>/Wn_est'
   */
  rtY.Wn_est = 628.318542F * rtb_Add;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_k += 0.01F * rtb_Add;

  /* Update for UnitDelay: '<S10>/Unit Delay2' incorporates:
   *  Outport: '<Root>/Wn_est'
   */
  rtDW.UnitDelay2_DSTATE_p = rtY.Wn_est;

  /* Update for DiscreteIntegrator: '<S137>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S137>/Gain3'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_h += SMO.PLL_Ki * rtDW.Divide * 0.0001F;
}

/* Output and update for atomic system: '<S20>/Sine_Cosine' */
void Sine_Cosine_h(void)
{
  real32_T rtb_Saturation;
  uint32_T Saturation_lm_tmp;

  /* Saturate: '<S24>/Saturation' incorporates:
   *  Outport: '<Root>/Flux_Angle'
   */
  if (rtY.Flux_Angle > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtY.Flux_Angle < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtY.Flux_Angle;
  }

  /* End of Saturate: '<S24>/Saturation' */

  /* Lookup_n-D: '<S24>/Cosine' incorporates:
   *  Lookup_n-D: '<S24>/Sine'
   *  Saturate: '<S24>/Saturation'
   */
  Saturation_lm_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F,
    4095U);

  /* Saturate: '<S66>/Saturation' incorporates:
   *  Lookup_n-D: '<S24>/Cosine'
   */
  rtDW.Saturation_lm = rtConstP.pooled31[Saturation_lm_tmp];

  /* Lookup_n-D: '<S24>/Sine' */
  rtDW.Sine_c = rtConstP.pooled33[Saturation_lm_tmp];
}

/* System initialize for action system: '<S3>/Flux_OBSERVER' */
void Flux_OBSERVER_Init(void)
{
  c_dsp_private_ExponentialMovingAverage *obj_0;
  dsp_simulink_MovingAverage *obj;
  real32_T varargin_2;
  boolean_T flag;

  /* Start for MATLABSystem: '<S8>/Moving Average' */
  rtDW.obj.matlabCodegenIsDeleted = true;
  rtDW.obj.isInitialized = 0;
  rtDW.obj.NumChannels = -1;
  rtDW.obj.matlabCodegenIsDeleted = false;
  flag = (rtDW.obj.isInitialized == 1);
  if (flag) {
    rtDW.obj.TunablePropsChanged = true;
  }

  rtDW.obj.ForgettingFactor = 0.99F;
  obj = &rtDW.obj;
  rtDW.obj.isSetupComplete = false;
  rtDW.obj.isInitialized = 1;
  rtDW.obj.NumChannels = 1;
  varargin_2 = rtDW.obj.ForgettingFactor;
  obj->_pobj0.isInitialized = 0;
  flag = (obj->_pobj0.isInitialized == 1);
  if (flag) {
    obj->_pobj0.TunablePropsChanged = true;
  }

  obj->_pobj0.ForgettingFactor = varargin_2;
  rtDW.obj.pStatistic = &obj->_pobj0;
  rtDW.obj.isSetupComplete = true;
  rtDW.obj.TunablePropsChanged = false;

  /* End of Start for MATLABSystem: '<S8>/Moving Average' */

  /* InitializeConditions for MATLABSystem: '<S8>/Moving Average' */
  obj_0 = rtDW.obj.pStatistic;
  if (obj_0->isInitialized == 1) {
    obj_0->pwN = 1.0F;
    obj_0->pmN = 0.0F;
  }

  /* End of InitializeConditions for MATLABSystem: '<S8>/Moving Average' */
}

/* Disable for action system: '<S3>/Flux_OBSERVER' */
void Flux_OBSERVER_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S22>/Integrator' */
  rtDW.Integrator_DSTATE_m = rtDW.Integrator;

  /* Disable for DiscreteIntegrator: '<S22>/Integrator1' */
  rtDW.Integrator1_DSTATE = rtDW.Integrator1;
}

/* Output and update for action system: '<S3>/Flux_OBSERVER' */
void Flux_OBSERVER(void)
{
  c_dsp_private_ExponentialMovingAverage *obj;
  real32_T rtb_Add2_k;
  real32_T rtb_Gain1_o;
  real32_T rtb_Integrator_d;
  real32_T rtb_Saturation;
  real32_T rtb_Sum;
  real32_T rtb_Sum1_a;
  real32_T rtb_yk;
  boolean_T rtb_NotEqual;

  /* UnitDelay: '<S25>/Unit Delay' incorporates:
   *  Outport: '<Root>/Flux_Angle'
   */
  rtY.Flux_Angle = rtDW.UnitDelay_DSTATE;

  /* Outputs for Atomic SubSystem: '<S20>/Sine_Cosine' */
  Sine_Cosine_h();

  /* End of Outputs for SubSystem: '<S20>/Sine_Cosine' */

  /* DiscreteIntegrator: '<S22>/Integrator' */
  rtDW.Integrator = rtDW.Integrator_DSTATE_m;

  /* Sum: '<S22>/Sum' incorporates:
   *  Gain: '<S22>/Gain2'
   */
  rtb_Sum = rtDW.Integrator - 0.0041F * rtDW.UnitDelay2;

  /* DiscreteIntegrator: '<S22>/Integrator1' */
  rtDW.Integrator1 = rtDW.Integrator1_DSTATE;

  /* Sum: '<S22>/Sum1' incorporates:
   *  Gain: '<S22>/Gain3'
   */
  rtb_Sum1_a = rtDW.Integrator1 - 0.0041F * rtDW.UnitDelay1;

  /* Sum: '<S20>/Sum' incorporates:
   *  Product: '<S20>/Product'
   *  Product: '<S20>/Product1'
   */
  rtb_Integrator_d = rtb_Sum1_a * rtDW.Saturation_lm - rtDW.Sine_c * rtb_Sum;

  /* Product: '<S56>/IProd Out' incorporates:
   *  Constant: '<S20>/Constant'
   *  Product: '<S20>/Product2'
   */
  rtb_Saturation = FluxObsever.Omega * FluxObsever.Omega * rtb_Integrator_d;

  /* Sum: '<S68>/Sum' incorporates:
   *  Constant: '<S20>/Constant'
   *  DiscreteIntegrator: '<S59>/Integrator'
   *  Gain: '<S20>/Gain'
   *  Product: '<S64>/PProd Out'
   */
  rtb_Add2_k = FluxObsever.Kp * FluxObsever.Omega * rtb_Integrator_d +
    rtDW.Integrator_DSTATE_b;

  /* DeadZone: '<S52>/DeadZone' */
  if (rtb_Add2_k > 523.598755F) {
    rtb_Gain1_o = rtb_Add2_k - 523.598755F;
  } else if (rtb_Add2_k >= -523.598755F) {
    rtb_Gain1_o = 0.0F;
  } else {
    rtb_Gain1_o = rtb_Add2_k - -523.598755F;
  }

  /* End of DeadZone: '<S52>/DeadZone' */

  /* RelationalOperator: '<S50>/NotEqual' incorporates:
   *  Gain: '<S50>/ZeroGain'
   */
  rtb_NotEqual = (0.0F * rtb_Add2_k != rtb_Gain1_o);

  /* Signum: '<S50>/SignPreSat' */
  if (rtb_Gain1_o < 0.0F) {
    rtb_Gain1_o = -1.0F;
  } else if (rtb_Gain1_o > 0.0F) {
    rtb_Gain1_o = 1.0F;
  } else if (rtb_Gain1_o == 0.0F) {
    rtb_Gain1_o = 0.0F;
  } else {
    rtb_Gain1_o = (rtNaNF);
  }

  /* End of Signum: '<S50>/SignPreSat' */

  /* Signum: '<S50>/SignPreIntegrator' */
  if (rtb_Saturation < 0.0F) {
    rtb_Integrator_d = -1.0F;
  } else if (rtb_Saturation > 0.0F) {
    rtb_Integrator_d = 1.0F;
  } else if (rtb_Saturation == 0.0F) {
    rtb_Integrator_d = 0.0F;
  } else {
    rtb_Integrator_d = (rtNaNF);
  }

  /* End of Signum: '<S50>/SignPreIntegrator' */

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Constant1'
   *  DataTypeConversion: '<S50>/DataTypeConv1'
   *  DataTypeConversion: '<S50>/DataTypeConv2'
   *  Logic: '<S50>/AND3'
   *  RelationalOperator: '<S50>/Equal1'
   */
  if (rtb_NotEqual && ((int8_T)rtb_Gain1_o == (int8_T)rtb_Integrator_d)) {
    rtb_Integrator_d = 0.0F;
  } else {
    rtb_Integrator_d = rtb_Saturation;
  }

  /* End of Switch: '<S50>/Switch' */

  /* Saturate: '<S66>/Saturation' */
  if (rtb_Add2_k > 523.598755F) {
    rtDW.Saturation_lm = 523.598755F;
  } else if (rtb_Add2_k < -523.598755F) {
    rtDW.Saturation_lm = -523.598755F;
  } else {
    rtDW.Saturation_lm = rtb_Add2_k;
  }

  /* End of Saturate: '<S66>/Saturation' */

  /* MATLABSystem: '<S8>/Moving Average' incorporates:
   *  Abs: '<S8>/Abs'
   */
  if (rtDW.obj.ForgettingFactor != 0.99F) {
    rtb_NotEqual = (rtDW.obj.isInitialized == 1);
    if (rtb_NotEqual) {
      rtDW.obj.TunablePropsChanged = true;
    }

    rtDW.obj.ForgettingFactor = 0.99F;
  }

  if (rtDW.obj.TunablePropsChanged) {
    rtDW.obj.TunablePropsChanged = false;
    obj = rtDW.obj.pStatistic;
    rtb_NotEqual = (obj->isInitialized == 1);
    if (rtb_NotEqual) {
      obj->TunablePropsChanged = true;
    }

    rtDW.obj.pStatistic->ForgettingFactor = rtDW.obj.ForgettingFactor;
  }

  obj = rtDW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pwN = 1.0F;
    obj->pmN = 0.0F;
    obj->plambda = obj->ForgettingFactor;
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    obj->pwN = 1.0F;
    obj->pmN = 0.0F;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->plambda = obj->ForgettingFactor;
  }

  rtb_Add2_k = obj->pwN;
  rtb_Saturation = obj->pmN;
  rtb_Gain1_o = obj->plambda;
  rtb_Saturation = (1.0F - 1.0F / rtb_Add2_k) * rtb_Saturation + 1.0F /
    rtb_Add2_k * (real32_T)fabs(rtDW.Saturation_lm);
  obj->pwN = rtb_Gain1_o * rtb_Add2_k + 1.0F;
  obj->pmN = rtb_Saturation;

  /* Gain: '<S21>/Gain' incorporates:
   *  MATLABSystem: '<S8>/Moving Average'
   */
  rtb_Add2_k = 0.005F * rtb_Saturation;

  /* Saturate: '<S21>/Saturation' */
  if (rtb_Add2_k > 1.0F) {
    rtb_Add2_k = 1.0F;
  } else {
    if (rtb_Add2_k < 0.8F) {
      rtb_Add2_k = 0.8F;
    }
  }

  /* End of Saturate: '<S21>/Saturation' */

  /* Gain: '<S21>/Gain1' */
  rtb_Gain1_o = 0.4F * rtb_Add2_k;

  /* Sum: '<S22>/Add2' incorporates:
   *  Math: '<S22>/Math Function'
   *  Math: '<S22>/Math Function1'
   *
   * About '<S22>/Math Function':
   *  Operator: magnitude^2
   *
   * About '<S22>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Add2_k = (0.000680229045F - rtb_Sum * rtb_Sum) - rtb_Sum1_a * rtb_Sum1_a;

  /* Gain: '<S22>/Gain4' incorporates:
   *  MATLABSystem: '<S8>/Moving Average'
   */
  rtb_Saturation *= 1470.09302F;

  /* Saturate: '<S22>/Saturation' */
  if (rtb_Saturation > 5.0E+6F) {
    rtb_Saturation = 5.0E+6F;
  } else {
    if (rtb_Saturation < 200000.0F) {
      rtb_Saturation = 200000.0F;
    }
  }

  /* End of Saturate: '<S22>/Saturation' */

  /* Sum: '<S25>/Sum1' incorporates:
   *  Gain: '<S25>/Ts'
   *  Outport: '<Root>/Flux_Angle'
   */
  rtb_yk = 0.0001F * rtDW.Saturation_lm + rtY.Flux_Angle;

  /* If: '<S76>/If' incorporates:
   *  Constant: '<S76>/Constant'
   *  Constant: '<S76>/Constant1'
   *  RelationalOperator: '<S76>/Relational Operator'
   *  RelationalOperator: '<S76>/Relational Operator1'
   */
  if (rtb_yk > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    /* Update for UnitDelay: '<S25>/Unit Delay' incorporates:
     *  Constant: '<S78>/Constant'
     *  Sum: '<S78>/Sum'
     */
    rtDW.UnitDelay_DSTATE = rtb_yk - 6.28318548F;

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem1' */
  } else if (rtb_yk < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    /* Update for UnitDelay: '<S25>/Unit Delay' incorporates:
     *  Constant: '<S77>/Constant'
     *  Sum: '<S77>/Sum'
     */
    rtDW.UnitDelay_DSTATE = rtb_yk + 6.28318548F;

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    /* Update for UnitDelay: '<S25>/Unit Delay' incorporates:
     *  Inport: '<S79>/In1'
     */
    rtDW.UnitDelay_DSTATE = rtb_yk;

    /* End of Outputs for SubSystem: '<S76>/If Action Subsystem2' */
  }

  /* End of If: '<S76>/If' */

  /* Update for DiscreteIntegrator: '<S22>/Integrator' incorporates:
   *  Product: '<S21>/Product'
   *  Product: '<S22>/Product'
   *  Product: '<S22>/Product2'
   *  Sum: '<S21>/Add4'
   *  Sum: '<S22>/Add'
   */
  rtDW.Integrator_DSTATE_m += ((rtDW.UnitDelay4 - rtDW.UnitDelay2 * rtb_Gain1_o)
    + rtb_Add2_k * rtb_Sum * rtb_Saturation) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S22>/Integrator1' incorporates:
   *  Product: '<S21>/Product1'
   *  Product: '<S22>/Product1'
   *  Product: '<S22>/Product3'
   *  Sum: '<S21>/Add5'
   *  Sum: '<S22>/Add1'
   */
  rtDW.Integrator1_DSTATE += ((rtDW.UnitDelay3 - rtDW.UnitDelay1 * rtb_Gain1_o)
    + rtb_Add2_k * rtb_Sum1_a * rtb_Saturation) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S59>/Integrator' */
  rtDW.Integrator_DSTATE_b += 0.0001F * rtb_Integrator_d;
}

/* Output and update for action system: '<S3>/Startup_OPL' */
void Startup_OPL(void)
{
  real32_T DiscreteTimeIntegrator1_DSTATE_tmp;

  /* If: '<S14>/If2' */
  if (rtDW.Motor_state == 2) {
    /* Outputs for IfAction SubSystem: '<S14>/Subsystem' incorporates:
     *  ActionPort: '<S176>/Action Port'
     */
    /* DiscreteIntegrator: '<S176>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1 = rtDW.DiscreteTimeIntegrator1_DSTATE_g;

    /* DataTypeConversion: '<S176>/DT1' incorporates:
     *  Constant: '<S176>/2pi2'
     *  Math: '<S176>/Mod2'
     */
    rtDW.Merge_g = rt_modf_snf(rtDW.DiscreteTimeIntegrator1, 6.28318548F);

    /* Sum: '<S176>/Subtract' */
    rtDW.Subtract = rtDW.Gain3 - rtDW.DiscreteTimeIntegrator1;

    /* DataTypeConversion: '<S176>/DT2' incorporates:
     *  Constant: '<S3>/Iq_Command'
     */
    rtDW.Merge1_n = OPL_Param.Current_ref;

    /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S176>/Discrete-Time Integrator2'
     *  Gain: '<S176>/We'
     */
    rtDW.DiscreteTimeIntegrator1_DSTATE_g += 0.209439516F *
      rtDW.DiscreteTimeIntegrator2_DSTATE_j * 0.0001F;

    /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S14>/OPL_SpeedRPM'
     *  Constant: '<S176>/Constant1'
     *  Product: '<S176>/Product'
     */
    rtDW.DiscreteTimeIntegrator2_DSTATE_j += 1.0F / OPL_Param.Acc_Times *
      OPL_Param.Target_RPM * 0.0001F;

    /* End of Outputs for SubSystem: '<S14>/Subsystem' */
  } else {
    if (rtDW.Motor_state == 3) {
      /* Outputs for IfAction SubSystem: '<S14>/Subsystem1' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      /* DataTypeConversion: '<S177>/DT1' incorporates:
       *  Constant: '<S177>/2pi2'
       *  DiscreteIntegrator: '<S177>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S177>/Discrete-Time Integrator2'
       *  Math: '<S177>/Mod2'
       *  Sum: '<S177>/Subtract'
       */
      rtDW.Merge_g = rt_modf_snf((rtDW.DiscreteTimeIntegrator1_DSTATE +
        rtDW.DiscreteTimeIntegrator1) + rtDW.DiscreteTimeIntegrator2_DSTATE,
        6.28318548F);

      /* DataTypeConversion: '<S177>/DT2' incorporates:
       *  Constant: '<S3>/Iq_Command'
       *  DiscreteIntegrator: '<S177>/Discrete-Time Integrator3'
       *  Sum: '<S177>/Subtract1'
       */
      rtDW.Merge1_n = OPL_Param.Current_ref -
        rtDW.DiscreteTimeIntegrator3_DSTATE;

      /* Product: '<S177>/Divide' incorporates:
       *  Constant: '<S177>/Constant1'
       *  Constant: '<S177>/Constant2'
       *  Product: '<S177>/Divide1'
       */
      DiscreteTimeIntegrator1_DSTATE_tmp = 1.0F / OPL_Param.Revup_Times;

      /* Update for DiscreteIntegrator: '<S177>/Discrete-Time Integrator1' incorporates:
       *  Constant: '<S177>/Constant1'
       *  Product: '<S177>/Divide'
       */
      rtDW.DiscreteTimeIntegrator1_DSTATE += rtDW.Subtract /
        DiscreteTimeIntegrator1_DSTATE_tmp * 0.0001F;

      /* Update for DiscreteIntegrator: '<S177>/Discrete-Time Integrator2' incorporates:
       *  Constant: '<S14>/OPL_SpeedRPM'
       *  Gain: '<S177>/We'
       */
      rtDW.DiscreteTimeIntegrator2_DSTATE += 0.209439516F * OPL_Param.Target_RPM
        * 0.0001F;

      /* Update for DiscreteIntegrator: '<S177>/Discrete-Time Integrator3' incorporates:
       *  Constant: '<S177>/Iq_Command'
       *  Product: '<S177>/Divide1'
       */
      rtDW.DiscreteTimeIntegrator3_DSTATE += OPL_Param.Current_ref / 2.0F /
        DiscreteTimeIntegrator1_DSTATE_tmp * 0.0001F;

      /* End of Outputs for SubSystem: '<S14>/Subsystem1' */
    }
  }

  /* End of If: '<S14>/If2' */
}

/* Output and update for atomic system: '<S9>/Angle_calibration' */
void Angle_calibration_a(void)
{
  real32_T rtb_Subtract1_c2;

  /* Sum: '<S80>/Subtract1' incorporates:
   *  Constant: '<S80>/Angle_offset'
   */
  rtb_Subtract1_c2 = Angle_Theta + Resolver_Parameter.PLL_Angle_offset;

  /* If: '<S80>/If1' */
  if (rtb_Subtract1_c2 > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    IfActionSubsystem2_g(rtb_Subtract1_c2, &rtDW.Merge1_m);

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem2' */
  } else if (rtb_Subtract1_c2 < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S84>/Action Port'
     */
    IfActionSubsystem3(rtb_Subtract1_c2, &rtDW.Merge1_m);

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S80>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    /* Merge: '<S80>/Merge1' incorporates:
     *  Inport: '<S82>/In1'
     */
    rtDW.Merge1_m = rtb_Subtract1_c2;

    /* End of Outputs for SubSystem: '<S80>/If Action Subsystem1' */
  }

  /* End of If: '<S80>/If1' */
}

/* Output and update for action system: '<S3>/Resolver_Observer' */
void Resolver_Observer(void)
{
  /* Outputs for Atomic SubSystem: '<S9>/Resolver_Angle_cacl' */
  Resolver_Angle_cacl();

  /* End of Outputs for SubSystem: '<S9>/Resolver_Angle_cacl' */

  /* Outputs for Atomic SubSystem: '<S9>/Angle_calibration' */
  Angle_calibration_a();

  /* End of Outputs for SubSystem: '<S9>/Angle_calibration' */
}

/* Output and update for atomic system: '<S13>/Speed_cacl' */
void Speed_cacl(void)
{
  int32_T rtb_Wrap_To_Pi;
  real32_T Speed_RPM_i;

  /* Gain: '<S175>/Wrap_To_Pi' incorporates:
   *  DataTypeConversion: '<S175>/Convert_to_Uint32'
   *  Gain: '<S175>/Scale_Input'
   *  Inport: '<Root>/Angle_Theta'
   */
  rtb_Wrap_To_Pi = (int32_T)(1.70891312E+8F * rtU.Angle_Theta_e) << 2;

  /* Gain: '<S175>/RPM_Gain' incorporates:
   *  DataTypeConversion: '<S175>/Difference_to_Single'
   *  Delay: '<S175>/Position_Delay'
   *  Gain: '<S175>/Scale_Output'
   *  Sum: '<S175>/Difference_Wrap'
   */
  Speed_RPM_i = (real32_T)(rtb_Wrap_To_Pi - rtDW.Position_Delay_DSTATE) *
    1.46291804E-5F * 4.77464819F;

  /* DiscreteFilter: '<S175>/LPF' */
  rtDW.Speed_RPM_Filtered = 0.5F * rtDW.LPF_states;

  /* Update for Delay: '<S175>/Position_Delay' */
  rtDW.Position_Delay_DSTATE = rtb_Wrap_To_Pi;

  /* Update for DiscreteFilter: '<S175>/LPF' */
  rtDW.LPF_states = Speed_RPM_i - -0.5F * rtDW.LPF_states;
}

/* Output and update for action system: '<S3>/Speed_Resolver' */
void Speed_Resolver(void)
{
  /* DataTypeConversion: '<S13>/DT2' incorporates:
   *  Inport: '<Root>/Angle_Theta'
   */
  rtDW.Direct_Angle = rtU.Angle_Theta_e;

  /* Outputs for Atomic SubSystem: '<S13>/Speed_cacl' */
  Speed_cacl();

  /* End of Outputs for SubSystem: '<S13>/Speed_cacl' */
}

/* Output and update for atomic system: '<S3>/State_machine' */
void State_machine(void)
{
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  /* Chart: '<S3>/State_machine' */
  if (rtDW.is_active_c5_Motor_Control == 0U) {
    rtDW.is_active_c5_Motor_Control = 1U;
    rtDW.is_c5_Motor_Control = IN_Motor_Start;
    rtDW.Motor_state = 1U;
  } else {
    switch (rtDW.is_c5_Motor_Control) {
     case IN_Motor_CL:
      if (!rtDW.Merge_cb) {
        rtDW.is_c5_Motor_Control = IN_Motor_Stop;
        rtDW.Motor_state = 0U;
      } else {
        rtDW.is_c5_Motor_Control = IN_Motor_CL1;
        rtDW.Motor_state = 4U;
      }
      break;

     case IN_Motor_CL1:
      rtDW.Motor_state = 4U;
      if (!rtDW.Merge_cb) {
        rtDW.is_c5_Motor_Control = IN_Motor_Stop;
        rtDW.Motor_state = 0U;
      }
      break;

     case IN_Motor_OPL:
      rtDW.Motor_state = 2U;
      if ((rtDW.temporalCounter_i1 >= (uint32_T)ceil(OPL_Param.Acc_Times /
            0.0001 - 1.0E-12)) && rtDW.Merge_cb && (rtDW.CL_flag == 1.0) &&
          (rtDW.UnitDelay1_i > OPL_Param.Target_RPM - 100.0F)) {
        rtDW.is_c5_Motor_Control = IN_Motor_CL;
        rtDW.Motor_state = 3U;
      } else {
        if (!rtDW.Merge_cb) {
          rtDW.is_c5_Motor_Control = IN_Motor_Stop;
          rtDW.Motor_state = 0U;
        }
      }
      break;

     case IN_Motor_Start:
      if (!rtDW.Merge_cb) {
        rtDW.is_c5_Motor_Control = IN_Motor_Stop;
        rtDW.Motor_state = 0U;
      } else {
        rtDW.is_c5_Motor_Control = IN_Motor_OPL;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.Motor_state = 2U;
        rtDW.CL_flag = 1.0;
      }
      break;

     default:
      /* case IN_Motor_Stop: */
      rtDW.Motor_state = 0U;
      if (rtDW.Merge_cb) {
        rtDW.is_c5_Motor_Control = IN_Motor_Start;
        rtDW.Motor_state = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/State_machine' */
}

/* System initialize for function-call system: '<S2>/Angle_Speed_100us' */
void Angle_Speed_100us_Init(void)
{
  /* Start for If: '<S3>/If2' */
  rtDW.If2_ActiveSubsystem = -1;

  /* Start for If: '<S3>/If3' */
  rtDW.If3_ActiveSubsystem = -1;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Flux_OBSERVER' */
  Flux_OBSERVER_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/Flux_OBSERVER' */

  /* SystemInitialize for IfAction SubSystem: '<S3>/SpeedAndAngle' */
  SpeedAndAngle_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/SpeedAndAngle' */
}

/* Output and update for function-call system: '<S2>/Angle_Speed_100us' */
void Angle_Speed_100us(void)
{
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Outputs for IfAction SubSystem: '<S3>/Subsystem1' incorporates:
   *  ActionPort: '<S17>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S3>/Subsystem' incorporates:
   *  ActionPort: '<S16>/Action Port'
   */
  /* If: '<S3>/If7' incorporates:
   *  Constant: '<S3>/OPL_Angle_Enable'
   *  Constant: '<S3>/OPL_Enable'
   *  SignalConversion generated from: '<S16>/Out1'
   *  SignalConversion generated from: '<S17>/Out1'
   */
  rtDW.Merge_cb = ((OPL_Param.Func_Enable == 1) && (OPL_Param.Angle_Enable == 1));

  /* End of Outputs for SubSystem: '<S3>/Subsystem' */
  /* End of Outputs for SubSystem: '<S3>/Subsystem1' */

  /* UnitDelay: '<S3>/Unit Delay1' */
  rtDW.UnitDelay1_i = rtDW.UnitDelay1_DSTATE_p;

  /* Chart: '<S3>/State_machine' */
  State_machine();

  /* If: '<S3>/If2' incorporates:
   *  Constant: '<S3>/SMO_Enalble'
   */
  rtPrevAction = rtDW.If2_ActiveSubsystem;
  rtAction = -1;
  if (SMO.Func_Enable == 1) {
    rtAction = 0;
  }

  rtDW.If2_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    SMO_Disable();
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S3>/SMO' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    SMO_l();

    /* End of Outputs for SubSystem: '<S3>/SMO' */
  }

  /* End of If: '<S3>/If2' */

  /* If: '<S3>/If4' */
  if ((rtDW.Motor_state == 2) || (rtDW.Motor_state == 3) || (rtDW.Motor_state ==
       3)) {
    /* Outputs for IfAction SubSystem: '<S3>/Startup_OPL' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    Startup_OPL();

    /* End of Outputs for SubSystem: '<S3>/Startup_OPL' */
  }

  /* End of If: '<S3>/If4' */

  /* If: '<S3>/If3' incorporates:
   *  Constant: '<S3>/Flux_Obsever'
   */
  rtPrevAction = rtDW.If3_ActiveSubsystem;
  rtAction = -1;
  if (FluxObsever.Func_Enable == 1) {
    rtAction = 0;
  }

  rtDW.If3_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    Flux_OBSERVER_Disable();
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S3>/Flux_OBSERVER' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    Flux_OBSERVER();

    /* End of Outputs for SubSystem: '<S3>/Flux_OBSERVER' */
  }

  /* End of If: '<S3>/If3' */

  /* Outputs for Atomic SubSystem: '<S3>/Angle_Selector' */
  Angle_Selector();

  /* End of Outputs for SubSystem: '<S3>/Angle_Selector' */

  /* Outport: '<Root>/Flux_Speed' incorporates:
   *  Gain: '<S3>/Gain1'
   */
  rtY.Flux_Speed = 4.77464819F * rtDW.Saturation_lm;

  /* If: '<S3>/If5' incorporates:
   *  Constant: '<S3>/PLL_Enable'
   */
  if (Resolver_Parameter.PLL_Func_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S3>/Resolver_Observer' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    Resolver_Observer();

    /* End of Outputs for SubSystem: '<S3>/Resolver_Observer' */
  }

  /* End of If: '<S3>/If5' */

  /* If: '<S3>/If1' incorporates:
   *  Constant: '<S3>/Hall_Enalble'
   */
  if (Hall_Parameter.Func_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S3>/SpeedAndAngle' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    SpeedAndAngle();

    /* End of Outputs for SubSystem: '<S3>/SpeedAndAngle' */
  }

  /* End of If: '<S3>/If1' */

  /* If: '<S12>/If3' incorporates:
   *  Constant: '<S12>/Hall_Angle_Enable'
   *  Inport: '<S171>/In1'
   *  Inport: '<S171>/In2'
   *  Outport: '<Root>/Hall_Speed'
   */
  if (Hall_Parameter.Angle_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S12>/Hall' incorporates:
     *  ActionPort: '<S171>/Action Port'
     */
    rtDW.Merge = rtY.Hall_Speed;
    rtDW.Merge1 = rtDW.Merge1_c;

    /* End of Outputs for SubSystem: '<S12>/Hall' */
  }

  /* End of If: '<S12>/If3' */

  /* If: '<S12>/If1' incorporates:
   *  Constant: '<S12>/Resolver_PLL_Enable'
   *  Inport: '<S173>/In1'
   *  Inport: '<S173>/In2'
   */
  if (Resolver_Parameter.PLL_Angle_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S12>/Resolver_PLL' incorporates:
     *  ActionPort: '<S173>/Action Port'
     */
    rtDW.Merge = rtDW.LPF;
    rtDW.Merge1 = rtDW.Merge1_m;

    /* End of Outputs for SubSystem: '<S12>/Resolver_PLL' */
  }

  /* End of If: '<S12>/If1' */

  /* If: '<S12>/If2' incorporates:
   *  Constant: '<S12>/Sensorless_Enable'
   *  Constant: '<S12>/Sensorless_Enable1'
   *  Inport: '<S174>/In1'
   *  Inport: '<S174>/In2'
   *  Outport: '<Root>/Flux_Speed'
   */
  if ((OPL_Param.Func_Enable == 1) || (FluxObsever.Angle_Enable == 1)) {
    /* Outputs for IfAction SubSystem: '<S12>/Sensorless' incorporates:
     *  ActionPort: '<S174>/Action Port'
     */
    rtDW.Merge = rtY.Flux_Speed;
    rtDW.Merge1 = rtDW.FOC_Angle;

    /* End of Outputs for SubSystem: '<S12>/Sensorless' */
  }

  /* End of If: '<S12>/If2' */

  /* If: '<S3>/If6' incorporates:
   *  Constant: '<S3>/Dir_Angle_Enable'
   */
  if (Resolver_Parameter.Func_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S3>/Speed_Resolver' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    Speed_Resolver();

    /* End of Outputs for SubSystem: '<S3>/Speed_Resolver' */
  }

  /* End of If: '<S3>/If6' */

  /* If: '<S12>/If5' incorporates:
   *  Constant: '<S12>/Resolver_Enable'
   *  Inport: '<S172>/In1'
   *  Inport: '<S172>/In2'
   */
  if (Resolver_Parameter.Angle_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S12>/Resolver_Dir' incorporates:
     *  ActionPort: '<S172>/Action Port'
     */
    rtDW.Merge = rtDW.Speed_RPM_Filtered;
    rtDW.Merge1 = rtDW.Direct_Angle;

    /* End of Outputs for SubSystem: '<S12>/Resolver_Dir' */
  }

  /* End of If: '<S12>/If5' */

  /* Update for UnitDelay: '<S3>/Unit Delay1' incorporates:
   *  Outport: '<Root>/Flux_Speed'
   */
  rtDW.UnitDelay1_DSTATE_p = rtY.Flux_Speed;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
