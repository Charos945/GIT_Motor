/*
 * File: Resolver_Angle_cacl.c
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

#include "Resolver_Angle_cacl.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Output and update for atomic system: '<S81>/Sine_Cosine' */
void Sine_Cosine_j(void)
{
  real32_T rtb_Saturation;
  uint32_T Cosine_n_tmp;

  /* Saturate: '<S86>/Saturation' */
  if (rtDW.Cosine_n > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Cosine_n < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Cosine_n;
  }

  /* End of Saturate: '<S86>/Saturation' */

  /* Lookup_n-D: '<S86>/Cosine' incorporates:
   *  Lookup_n-D: '<S86>/Sine'
   *  Saturate: '<S86>/Saturation'
   */
  Cosine_n_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);

  /* Lookup_n-D: '<S86>/Cosine' */
  rtDW.Cosine_n = rtConstP.pooled31[Cosine_n_tmp];

  /* Lookup_n-D: '<S86>/Sine' */
  rtDW.Sine = rtConstP.pooled33[Cosine_n_tmp];
}

/* Output and update for atomic system: '<S9>/Resolver_Angle_cacl' */
void Resolver_Angle_cacl(void)
{
  real32_T rtb_DiscreteTimeIntegrator_i;
  real32_T rtb_Sum;

  /* Product: '<S81>/Product' incorporates:
   *  UnitDelay: '<S81>/Unit Delay4'
   */
  rtDW.Cosine_n = Angle_Theta;

  /* Outputs for Atomic SubSystem: '<S81>/Sine_Cosine' */
  Sine_Cosine_j();

  /* End of Outputs for SubSystem: '<S81>/Sine_Cosine' */

  /* Sum: '<S81>/Sum1' incorporates:
   *  Inport: '<Root>/Resolver_SinCos'
   *  Product: '<S81>/Product1'
   *  Product: '<S81>/Product2'
   *  Product: '<S81>/Product3'
   *  Product: '<S81>/Product4'
   */
  rtb_DiscreteTimeIntegrator_i = rtDW.Cosine_n * rtU.Resolver_signal[1] -
    rtU.Resolver_signal[0] * rtDW.Sine;

  /* Sum: '<S127>/Sum' incorporates:
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  Gain: '<S123>/Proportional Gain'
   */
  rtb_Sum = 141.0F * rtb_DiscreteTimeIntegrator_i + rtDW.Integrator_DSTATE;

  /* Gain: '<S81>/Gain' */
  Speed_RPM = 2.38732409F * rtb_Sum;

  /* Math: '<S81>/Math Function' incorporates:
   *  Constant: '<S81>/2*pi'
   *  DiscreteIntegrator: '<S81>/Discrete-Time Integrator'
   */
  Angle_Theta = rt_modf_snf(rtDW.DiscreteTimeIntegrator_DSTATE, 6.28318548F);

  /* DiscreteFilter: '<S81>/LPF' */
  rtDW.LPF = 0.04F * rtDW.LPF_states_i;

  /* Update for DiscreteIntegrator: '<S118>/Integrator' incorporates:
   *  Gain: '<S115>/Integral Gain'
   */
  rtDW.Integrator_DSTATE += 10000.0F * rtb_DiscreteTimeIntegrator_i * 0.0001F;

  /* Update for DiscreteIntegrator: '<S81>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.0001F * rtb_Sum;

  /* Update for DiscreteFilter: '<S81>/LPF' */
  rtDW.LPF_states_i = Speed_RPM - -0.96F * rtDW.LPF_states_i;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
