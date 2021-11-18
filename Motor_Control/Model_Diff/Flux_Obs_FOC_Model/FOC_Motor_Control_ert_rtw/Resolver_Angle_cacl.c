/*
 * File: Resolver_Angle_cacl.c
 *
 * Code generated for Simulink model 'FOC_Motor_Control'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Nov 15 13:44:38 2021
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
#include "FOC_Motor_Control.h"
#include "FOC_Motor_Control_private.h"

/* Output and update for atomic system: '<S11>/Sine_Cosine' */
void Sine_Cosine_b(void)
{
  real32_T rtb_Saturation;
  uint32_T LPF_tmp;

  /* Saturate: '<S15>/Saturation' */
  if (rtDW.Speed_RPM > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Speed_RPM < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Speed_RPM;
  }

  /* End of Saturate: '<S15>/Saturation' */

  /* Lookup_n-D: '<S15>/Cosine' incorporates:
   *  Lookup_n-D: '<S15>/Sine'
   *  Saturate: '<S15>/Saturation'
   */
  LPF_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);

  /* DiscreteFilter: '<S11>/LPF' incorporates:
   *  Lookup_n-D: '<S15>/Cosine'
   */
  rtDW.LPF = rtConstP.pooled29[LPF_tmp];

  /* Lookup_n-D: '<S15>/Sine' */
  rtDW.Angle_Theta = rtConstP.pooled31[LPF_tmp];
}

real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T q;
  real32_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      q = fabsf(u0 / u1);
      yEq = !(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else {
      if ((u0 < 0.0F) != (u1 < 0.0F)) {
        y += u1;
      }
    }
  }

  return y;
}

/* Output and update for atomic system: '<S7>/Resolver_Angle_cacl' */
void Resolver_Angle_cacl(void)
{
  real32_T rtb_DiscreteTimeIntegrator;
  real32_T rtb_Sum_n;

  /* Product: '<S11>/Product' incorporates:
   *  UnitDelay: '<S11>/Unit Delay4'
   */
  rtDW.Speed_RPM = rtDW.UnitDelay4_DSTATE_j;

  /* Outputs for Atomic SubSystem: '<S11>/Sine_Cosine' */
  Sine_Cosine_b();

  /* End of Outputs for SubSystem: '<S11>/Sine_Cosine' */

  /* Sum: '<S11>/Sum1' incorporates:
   *  Product: '<S11>/Product1'
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   *  Product: '<S11>/Product4'
   */
  rtb_DiscreteTimeIntegrator = rtDW.LPF * 0.0F - 0.0F * rtDW.Angle_Theta;

  /* Sum: '<S56>/Sum' incorporates:
   *  DiscreteIntegrator: '<S47>/Integrator'
   *  Gain: '<S52>/Proportional Gain'
   */
  rtb_Sum_n = 141.0F * rtb_DiscreteTimeIntegrator + rtDW.Integrator_DSTATE;

  /* Gain: '<S11>/Gain' */
  rtDW.Speed_RPM = 2.38732409F * rtb_Sum_n;

  /* Math: '<S11>/Math Function' incorporates:
   *  Constant: '<S11>/2*pi'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   */
  rtDW.Angle_Theta = rt_modf_snf(rtDW.DiscreteTimeIntegrator_DSTATE, 6.28318548F);

  /* DiscreteFilter: '<S11>/LPF' */
  rtDW.LPF = 0.04F * rtDW.LPF_states;

  /* Update for UnitDelay: '<S11>/Unit Delay4' */
  rtDW.UnitDelay4_DSTATE_j = rtDW.Angle_Theta;

  /* Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
   *  Gain: '<S44>/Integral Gain'
   */
  rtDW.Integrator_DSTATE += 10000.0F * rtb_DiscreteTimeIntegrator * 0.0001F;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.0001F * rtb_Sum_n;

  /* Update for DiscreteFilter: '<S11>/LPF' */
  rtDW.LPF_states = rtDW.Speed_RPM - -0.96F * rtDW.LPF_states;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
