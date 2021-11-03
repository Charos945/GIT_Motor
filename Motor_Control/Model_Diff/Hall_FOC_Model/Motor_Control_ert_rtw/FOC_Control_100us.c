/*
 * File: FOC_Control_100us.c
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

#include "FOC_Control_100us.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Output and update for atomic system: '<S92>/Clarke_Transform' */
void Clarke_Transform(void)
{
  /* Outputs for Atomic SubSystem: '<S93>/Clark1' */
  /* Gain: '<S103>/Gain2' incorporates:
   *  Gain: '<S103>/Gain'
   *  Gain: '<S103>/Gain1'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S103>/Add'
   */
  Ialpha = ((rtU.Phase_CurrentABC[0] - 0.5F * rtU.Phase_CurrentABC[1]) - 0.5F *
            rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* Gain: '<S103>/Gain5' incorporates:
   *  Gain: '<S103>/Gain3'
   *  Gain: '<S103>/Gain4'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S103>/Add1'
   */
  Ibeta = (0.866025388F * rtU.Phase_CurrentABC[1] - 0.866025388F *
           rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* End of Outputs for SubSystem: '<S93>/Clark1' */
}

/* Output and update for atomic system: '<S92>/DT_Compensation' */
void DT_Compensation(void)
{
  real32_T rtb_Add1_j;
  real32_T rtb_Add1_n;
  real32_T rtb_Fcn;
  real32_T rtb_Itheta2;
  real32_T rtb_Merge1;

  /* Outputs for Enabled SubSystem: '<S94>/DT_Compensation' incorporates:
   *  EnablePort: '<S104>/Enable'
   */
  if (rtDW.Constant3 > 0.0F) {
    /* Fcn: '<S104>/Fcn' incorporates:
     *  Constant: '<S92>/Constant2'
     *  Constant: '<S92>/IdRef2'
     *  Inport: '<Root>/Bus_Voltage'
     */
    rtb_Fcn = Dead_Time * rtU.Bus_Voltage / 0.0001F;

    /* Sum: '<S110>/Add1' incorporates:
     *  Constant: '<S110>/Constant1'
     *  Product: '<S110>/Divide1'
     *  Sum: '<S110>/Add'
     *  UnitDelay: '<S110>/Unit Delay'
     */
    rtb_Add1_n = (Id_measured - rtDW.UnitDelay_DSTATE_pd) * 0.005F +
      rtDW.UnitDelay_DSTATE_pd;

    /* Sum: '<S109>/Add1' incorporates:
     *  Constant: '<S109>/Constant1'
     *  Product: '<S109>/Divide1'
     *  Sum: '<S109>/Add'
     *  UnitDelay: '<S109>/Unit Delay'
     */
    rtb_Add1_j = (Iq_measured - rtDW.UnitDelay_DSTATE_n) * 0.005F +
      rtDW.UnitDelay_DSTATE_n;

    /* If: '<S111>/B>0' */
    if (rtb_Add1_n > 0.0F) {
      /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S117>/Action Port'
       */
      /* Lookup_n-D: '<S117>/1-D Lookup Table4' incorporates:
       *  Product: '<S117>/Divide'
       *  Saturate: '<S117>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 > 572.0F) {
        rtb_Itheta2 = 572.0F;
      } else {
        if (rtb_Itheta2 < -572.0F) {
          rtb_Itheta2 = -572.0F;
        }
      }

      /* Merge: '<S111>/Merge2' incorporates:
       *  Lookup_n-D: '<S117>/1-D Lookup Table4'
       *  SignalConversion generated from: '<S117>/IsTheta'
       */
      rtDW.Merge2_n = rtConstP.pooled6[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)];

      /* End of Outputs for SubSystem: '<S111>/If Action Subsystem8' */
    }

    /* End of If: '<S111>/B>0' */

    /* If: '<S111>/A>=0andB<0' */
    if ((rtb_Add1_j >= 0.0F) && (rtb_Add1_n < 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem9' incorporates:
       *  ActionPort: '<S118>/Action Port'
       */
      /* Lookup_n-D: '<S118>/1-D Lookup Table4' incorporates:
       *  Product: '<S118>/Divide'
       *  Saturate: '<S118>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 < -572.0F) {
        rtb_Itheta2 = -572.0F;
      }

      /* Merge: '<S111>/Merge2' incorporates:
       *  Constant: '<S118>/Constant'
       *  Lookup_n-D: '<S118>/1-D Lookup Table4'
       *  SignalConversion generated from: '<S118>/IsTheta'
       *  Sum: '<S118>/Add'
       */
      rtDW.Merge2_n = rtConstP.pooled6[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)] + 3.14159274F;

      /* End of Outputs for SubSystem: '<S111>/If Action Subsystem9' */
    }

    /* End of If: '<S111>/A>=0andB<0' */

    /* If: '<S111>/B<0andA<0' */
    if ((rtb_Add1_j < 0.0F) && (rtb_Add1_n < 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S114>/Action Port'
       */
      /* Lookup_n-D: '<S114>/1-D Lookup Table4' incorporates:
       *  Product: '<S114>/Divide'
       *  Saturate: '<S114>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 > 572.0F) {
        rtb_Itheta2 = 572.0F;
      }

      /* Merge: '<S111>/Merge2' incorporates:
       *  Constant: '<S114>/Constant'
       *  Lookup_n-D: '<S114>/1-D Lookup Table4'
       *  Sum: '<S114>/Add'
       */
      rtDW.Merge2_n = rtConstP.pooled6[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)] - 3.14159274F;

      /* End of Outputs for SubSystem: '<S111>/If Action Subsystem10' */
    }

    /* End of If: '<S111>/B<0andA<0' */

    /* If: '<S111>/B=0andA>0' */
    if ((rtb_Add1_j > 0.0F) && (rtb_Add1_n == 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem11' incorporates:
       *  ActionPort: '<S115>/Action Port'
       */
      /* Merge: '<S111>/Merge2' incorporates:
       *  Constant: '<S115>/Constant'
       *  SignalConversion generated from: '<S115>/IsTheta'
       */
      rtDW.Merge2_n = 1.57079637F;

      /* End of Outputs for SubSystem: '<S111>/If Action Subsystem11' */
    }

    /* End of If: '<S111>/B=0andA>0' */

    /* If: '<S111>/B=0andA<0' */
    if ((rtb_Add1_j < 0.0F) && (rtb_Add1_n == 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem12' incorporates:
       *  ActionPort: '<S116>/Action Port'
       */
      /* Merge: '<S111>/Merge2' incorporates:
       *  Constant: '<S116>/Constant'
       *  SignalConversion generated from: '<S116>/IsTheta'
       */
      rtDW.Merge2_n = -1.57079637F;

      /* End of Outputs for SubSystem: '<S111>/If Action Subsystem12' */
    }

    /* End of If: '<S111>/B=0andA<0' */

    /* Sum: '<S105>/Add1' */
    rtb_Itheta2 = rtDW.Merge2_n + rtDW.Merge1_i;

    /* If: '<S108>/If1' incorporates:
     *  Inport: '<S112>/Angle_input'
     */
    if (rtb_Itheta2 > 6.28318548F) {
      /* Outputs for IfAction SubSystem: '<S108>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S113>/Action Port'
       */
      IfActionSubsystem2(rtb_Itheta2, &rtb_Merge1);

      /* End of Outputs for SubSystem: '<S108>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S108>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S112>/Action Port'
       */
      rtb_Merge1 = rtb_Itheta2;

      /* End of Outputs for SubSystem: '<S108>/If Action Subsystem1' */
    }

    /* End of If: '<S108>/If1' */

    /* If: '<S106>/If1' */
    if ((rtb_Merge1 > 5.75958F) || (rtb_Merge1 <= 0.523598F)) {
      /* Outputs for IfAction SubSystem: '<S106>/Subsystem' incorporates:
       *  ActionPort: '<S119>/Action Port'
       */
      /* Gain: '<S119>/Gain' */
      rtDW.Merge_p[0] = rtb_Fcn;

      /* Gain: '<S119>/Gain1' */
      rtDW.Merge_p[1] = -rtb_Fcn;

      /* Gain: '<S119>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S106>/Subsystem' */
    } else if ((rtb_Merge1 > 0.523598F) && (rtb_Merge1 <= 1.57079601F)) {
      /* Outputs for IfAction SubSystem: '<S106>/Subsystem1' incorporates:
       *  ActionPort: '<S120>/Action Port'
       */
      /* Gain: '<S120>/Gain' */
      rtDW.Merge_p[0] = rtb_Fcn;

      /* Gain: '<S120>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S120>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S106>/Subsystem1' */
    } else if ((rtb_Merge1 > 1.57079601F) && (rtb_Merge1 <= 2.61799312F)) {
      /* Outputs for IfAction SubSystem: '<S106>/Subsystem2' incorporates:
       *  ActionPort: '<S121>/Action Port'
       */
      /* Gain: '<S121>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S121>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S121>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S106>/Subsystem2' */
    } else if ((rtb_Merge1 > 2.61799312F) && (rtb_Merge1 <= 3.66519094F)) {
      /* Outputs for IfAction SubSystem: '<S106>/Subsystem3' incorporates:
       *  ActionPort: '<S122>/Action Port'
       */
      /* Gain: '<S122>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S122>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S122>/Gain2' */
      rtDW.Merge_p[2] = rtb_Fcn;

      /* End of Outputs for SubSystem: '<S106>/Subsystem3' */
    } else if ((rtb_Merge1 > 3.66519094F) && (rtb_Merge1 <= 4.71238899F)) {
      /* Outputs for IfAction SubSystem: '<S106>/Subsystem4' incorporates:
       *  ActionPort: '<S123>/Action Port'
       */
      /* Gain: '<S123>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S123>/Gain1' */
      rtDW.Merge_p[1] = -rtb_Fcn;

      /* Gain: '<S123>/Gain2' */
      rtDW.Merge_p[2] = rtb_Fcn;

      /* End of Outputs for SubSystem: '<S106>/Subsystem4' */
    } else {
      if ((rtb_Merge1 > 4.71238899F) && (rtb_Merge1 <= 5.75958F)) {
        /* Outputs for IfAction SubSystem: '<S106>/Subsystem5' incorporates:
         *  ActionPort: '<S124>/Action Port'
         */
        /* Gain: '<S124>/Gain' */
        rtDW.Merge_p[0] = rtb_Fcn;

        /* Gain: '<S124>/Gain1' */
        rtDW.Merge_p[1] = -rtb_Fcn;

        /* Gain: '<S124>/Gain2' */
        rtDW.Merge_p[2] = rtb_Fcn;

        /* End of Outputs for SubSystem: '<S106>/Subsystem5' */
      }
    }

    /* End of If: '<S106>/If1' */

    /* Fcn: '<S107>/Fcn' */
    rtDW.Fcn = ((rtDW.Merge_p[0] - 0.5F * rtDW.Merge_p[1]) - 0.5F *
                rtDW.Merge_p[2]) * 0.666666687F;

    /* Fcn: '<S107>/Fcn1' */
    rtDW.Fcn1 = (rtDW.Merge_p[1] - rtDW.Merge_p[2]) * 0.577350259F;

    /* Update for UnitDelay: '<S110>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_pd = rtb_Add1_n;

    /* Update for UnitDelay: '<S109>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_n = rtb_Add1_j;
  }

  /* End of Outputs for SubSystem: '<S94>/DT_Compensation' */
}

/*
 * Output and update for action system:
 *    '<S125>/Over_M'
 *    '<S152>/Over_M'
 */
void Over_M(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S127>/Gain' */
  *rty_Out1 = 0.666666687F * rtu_Bus_voltage;

  /* Gain: '<S127>/Gain1' */
  *rty_Out2 = -0.666666687F * rtu_Bus_voltage;
}

/*
 * Output and update for action system:
 *    '<S125>/Normal'
 *    '<S152>/Normal'
 */
void Normal(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S126>/Gain' */
  *rty_Out1 = 0.577350259F * rtu_Bus_voltage;

  /* Gain: '<S126>/Gain1' */
  *rty_Out2 = -0.577350259F * rtu_Bus_voltage;
}

/* Output and update for atomic system: '<S92>/D_Current_PI' */
void D_Current_PI(void)
{
  real32_T Merge1_b;
  real32_T Merge_a;
  real32_T rtb_Add_jn;
  real32_T rtb_Switch_h;

  /* Sum: '<S95>/Add2' */
  rtb_Switch_h = Id_ref - Id_measured;

  /* DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_pb !=
       0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_a = 0.0F;
  }

  /* Sum: '<S125>/Add' incorporates:
   *  Constant: '<S125>/Kp'
   *  DiscreteIntegrator: '<S125>/Discrete-Time Integrator'
   *  Product: '<S125>/Product'
   */
  rtb_Add_jn = PI_Parameter.ID_Kp * rtb_Switch_h +
    rtDW.DiscreteTimeIntegrator_DSTATE_a;

  /* If: '<S125>/If1' incorporates:
   *  Constant: '<S125>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S125>/Over_M' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S125>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S125>/Normal' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S125>/Normal' */
  }

  /* End of If: '<S125>/If1' */

  /* Switch: '<S128>/Switch2' incorporates:
   *  RelationalOperator: '<S128>/LowerRelop1'
   *  RelationalOperator: '<S128>/UpperRelop'
   *  Switch: '<S128>/Switch'
   */
  if (rtb_Add_jn > Merge_a) {
    /* Switch: '<S128>/Switch2' */
    Vd_voltage = Merge_a;
  } else if (rtb_Add_jn < Merge1_b) {
    /* Switch: '<S128>/Switch' incorporates:
     *  Switch: '<S128>/Switch2'
     */
    Vd_voltage = Merge1_b;
  } else {
    /* Switch: '<S128>/Switch2' incorporates:
     *  Switch: '<S128>/Switch'
     */
    Vd_voltage = rtb_Add_jn;
  }

  /* End of Switch: '<S128>/Switch2' */

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S125>/Cons'
   *  UnitDelay: '<S125>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_k) {
    rtb_Switch_h = 0.0F;
  }

  /* End of Switch: '<S125>/Switch' */

  /* Update for DiscreteIntegrator: '<S125>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S125>/Ki'
   *  Product: '<S125>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += PI_Parameter.ID_Ki * rtb_Switch_h *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_pb = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S125>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S125>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_k = (rtb_Add_jn == Vd_voltage);
}

/* Output and update for atomic system: '<S92>/FeedForward' */
void FeedForward(void)
{
  /* Outputs for Enabled SubSystem: '<S96>/Subsystem' incorporates:
   *  EnablePort: '<S129>/Enable'
   */
  if (rtDW.Constant1 > 0.0F) {
    /* Sum: '<S129>/Subtract3' incorporates:
     *  Gain: '<S129>/Ld'
     *  Gain: '<S129>/Rs1'
     *  Gain: '<S129>/flux'
     *  Product: '<S129>/Product2'
     *  Sum: '<S129>/Subtract2'
     */
    rtDW.Subtract3 = (0.004F * Iq_measured * Id_measured + 0.4F * rtDW.Add3) +
      0.0260812F * Iq_measured;

    /* Sum: '<S129>/Subtract1' incorporates:
     *  Gain: '<S129>/Lq'
     *  Gain: '<S129>/Rs'
     *  Product: '<S129>/Product1'
     */
    rtDW.Subtract1 = 0.4F * Id_measured - 0.0042F * Iq_measured * rtDW.Add3;
  }

  /* End of Outputs for SubSystem: '<S96>/Subsystem' */
}

/* Output and update for atomic system: '<S130>/Sine_Cosine1' */
void Sine_Cosine1(void)
{
  real32_T rtb_Saturation;
  uint32_T Cosine_tmp;

  /* Saturate: '<S133>/Saturation' */
  if (rtDW.Sum12 > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Sum12 < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Sum12;
  }

  /* End of Saturate: '<S133>/Saturation' */

  /* Lookup_n-D: '<S133>/Cosine' incorporates:
   *  Lookup_n-D: '<S133>/Sine'
   *  Saturate: '<S133>/Saturation'
   */
  Cosine_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);

  /* Lookup_n-D: '<S133>/Cosine' */
  rtDW.Cosine = rtConstP.pooled28[Cosine_tmp];

  /* Lookup_n-D: '<S133>/Sine' */
  rtDW.Sine_k = rtConstP.pooled30[Cosine_tmp];
}

/* Output and update for atomic system: '<S130>/Sine_Cosine2' */
void Sine_Cosine2(void)
{
  real32_T rtb_Saturation;
  uint32_T Sum13_tmp;

  /* Saturate: '<S134>/Saturation' */
  if (rtDW.Sum12 > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Sum12 < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Sum12;
  }

  /* End of Saturate: '<S134>/Saturation' */

  /* Lookup_n-D: '<S134>/Cosine' incorporates:
   *  Lookup_n-D: '<S134>/Sine'
   *  Saturate: '<S134>/Saturation'
   */
  Sum13_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);

  /* Sum: '<S137>/Sum13' incorporates:
   *  Lookup_n-D: '<S134>/Cosine'
   */
  rtDW.Sum13 = rtConstP.pooled28[Sum13_tmp];

  /* Lookup_n-D: '<S134>/Sine' */
  rtDW.Sine_g = rtConstP.pooled30[Sum13_tmp];
}

/* Output and update for atomic system: '<S92>/Har_Compensation' */
void Har_Compensation(void)
{
  real32_T rtb_Add1_b_idx_0;
  real32_T rtb_Add1_b_idx_1;
  real32_T rtb_Add1_i;
  real32_T rtb_Add1_k_idx_1;
  real32_T rtb_Add1_m_idx_0;
  real32_T rtb_Add1_m_idx_1;
  real32_T rtb_Fcn;
  real32_T rtb_Fcn1_p;
  real32_T rtb_Sum;
  real32_T rtb_Sum6;

  /* Outputs for Enabled SubSystem: '<S97>/Har_Compensation' incorporates:
   *  EnablePort: '<S130>/Enable'
   */
  if (rtDW.Constant5 > 0.0F) {
    rtDW.Har_Compensation_MODE = true;

    /* Gain: '<S130>/Gain' */
    rtb_Sum = -5.0F * rtDW.Merge1_i;

    /* Sum: '<S135>/Subtract' incorporates:
     *  Constant: '<S135>/Te2'
     *  Constant: '<S135>/Te3'
     *  DataTypeConversion: '<S135>/Data Type Conversion'
     *  Product: '<S135>/Divide'
     *  Product: '<S135>/Divide1'
     */
    rtDW.Sum12 = rtb_Sum - (real32_T)(int32_T)floorf(rtb_Sum / 6.28318548F) *
      6.28318548F;

    /* Outputs for Atomic SubSystem: '<S130>/Sine_Cosine1' */
    Sine_Cosine1();

    /* End of Outputs for SubSystem: '<S130>/Sine_Cosine1' */

    /* Sum: '<S138>/Add1' incorporates:
     *  Constant: '<S138>/Constant1'
     *  Fcn: '<S140>/Fcn2'
     *  Fcn: '<S140>/Fcn3'
     *  Product: '<S138>/Divide1'
     *  Sum: '<S138>/Add'
     *  UnitDelay: '<S138>/Unit Delay'
     */
    rtb_Add1_m_idx_0 = ((Ialpha * rtDW.Cosine + Ibeta * rtDW.Sine_k) -
                        rtDW.UnitDelay_DSTATE_m[0]) * 0.005F +
      rtDW.UnitDelay_DSTATE_m[0];
    rtb_Add1_m_idx_1 = ((Ibeta * rtDW.Cosine - Ialpha * rtDW.Sine_k) -
                        rtDW.UnitDelay_DSTATE_m[1]) * 0.005F +
      rtDW.UnitDelay_DSTATE_m[1];

    /* Sum: '<S139>/Add1' incorporates:
     *  Constant: '<S139>/Constant1'
     *  Product: '<S139>/Divide1'
     *  Sum: '<S139>/Add'
     *  UnitDelay: '<S139>/Unit Delay'
     */
    rtb_Add1_b_idx_0 = (rtb_Add1_m_idx_0 - rtDW.UnitDelay_DSTATE_c[0]) * 0.005F
      + rtDW.UnitDelay_DSTATE_c[0];
    rtb_Add1_b_idx_1 = (rtb_Add1_m_idx_1 - rtDW.UnitDelay_DSTATE_c[1]) * 0.005F
      + rtDW.UnitDelay_DSTATE_c[1];

    /* Gain: '<S130>/Gain1' */
    rtb_Sum6 = 7.0F * rtDW.Merge1_i;

    /* Sum: '<S136>/Subtract' incorporates:
     *  Constant: '<S136>/Te2'
     *  Constant: '<S136>/Te3'
     *  DataTypeConversion: '<S136>/Data Type Conversion'
     *  Product: '<S136>/Divide'
     *  Product: '<S136>/Divide1'
     */
    rtDW.Sum12 = rtb_Sum6 - (real32_T)(int32_T)floorf(rtb_Sum6 / 6.28318548F) *
      6.28318548F;

    /* Outputs for Atomic SubSystem: '<S130>/Sine_Cosine2' */
    Sine_Cosine2();

    /* End of Outputs for SubSystem: '<S130>/Sine_Cosine2' */

    /* Sum: '<S141>/Add1' incorporates:
     *  Constant: '<S141>/Constant1'
     *  Fcn: '<S143>/Fcn2'
     *  Fcn: '<S143>/Fcn3'
     *  Product: '<S141>/Divide1'
     *  Sum: '<S141>/Add'
     *  UnitDelay: '<S141>/Unit Delay'
     */
    rtb_Sum = ((Ialpha * rtDW.Sum13 + Ibeta * rtDW.Sine_g) -
               rtDW.UnitDelay_DSTATE_p[0]) * 0.005F + rtDW.UnitDelay_DSTATE_p[0];
    rtb_Add1_k_idx_1 = ((Ibeta * rtDW.Sum13 - Ialpha * rtDW.Sine_g) -
                        rtDW.UnitDelay_DSTATE_p[1]) * 0.005F +
      rtDW.UnitDelay_DSTATE_p[1];

    /* DiscreteIntegrator: '<S147>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_o = rtDW.DiscreteTimeIntegrator_DSTATE_h;

    /* DiscreteIntegrator: '<S149>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_d = rtDW.DiscreteTimeIntegrator_DSTATE_d;

    /* Gain: '<S137>/Gain8' */
    rtb_Fcn = 7.0F * rtDW.Add3;

    /* Gain: '<S137>/Gain3' */
    rtb_Sum6 = 5.0F * rtDW.Add3;

    /* DiscreteIntegrator: '<S146>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_a = rtDW.DiscreteTimeIntegrator_DSTATE_m;

    /* DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_g = rtDW.DiscreteTimeIntegrator_DSTATE_k;

    /* Sum: '<S142>/Add1' incorporates:
     *  Constant: '<S142>/Constant1'
     *  Product: '<S142>/Divide1'
     *  Sum: '<S142>/Add'
     *  UnitDelay: '<S142>/Unit Delay'
     */
    rtb_Add1_i = (rtb_Sum - rtDW.UnitDelay_DSTATE_l[0]) * 0.005F +
      rtDW.UnitDelay_DSTATE_l[0];

    /* Update for UnitDelay: '<S138>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_m[0] = rtb_Add1_m_idx_0;

    /* Update for UnitDelay: '<S139>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_c[0] = rtb_Add1_b_idx_0;

    /* Update for UnitDelay: '<S141>/Unit Delay' incorporates:
     *  Sum: '<S142>/Add'
     */
    rtDW.UnitDelay_DSTATE_p[0] = rtb_Sum;

    /* Update for UnitDelay: '<S142>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_l[0] = rtb_Add1_i;

    /* Sum: '<S142>/Add1' incorporates:
     *  Constant: '<S142>/Constant1'
     *  Product: '<S142>/Divide1'
     *  Sum: '<S142>/Add'
     *  UnitDelay: '<S142>/Unit Delay'
     */
    rtb_Add1_m_idx_0 = rtb_Add1_i;
    rtb_Add1_i = (rtb_Add1_k_idx_1 - rtDW.UnitDelay_DSTATE_l[1]) * 0.005F +
      rtDW.UnitDelay_DSTATE_l[1];

    /* Update for UnitDelay: '<S138>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_m[1] = rtb_Add1_m_idx_1;

    /* Update for UnitDelay: '<S139>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_c[1] = rtb_Add1_b_idx_1;

    /* Update for UnitDelay: '<S141>/Unit Delay' incorporates:
     *  Sum: '<S142>/Add'
     */
    rtDW.UnitDelay_DSTATE_p[1] = rtb_Add1_k_idx_1;

    /* Update for UnitDelay: '<S142>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_l[1] = rtb_Add1_i;

    /* Sum: '<S147>/Add' incorporates:
     *  Constant: '<S137>/id7+'
     *  Constant: '<S147>/Kp'
     *  Product: '<S147>/Product'
     *  Sum: '<S137>/Sum6'
     */
    rtb_Sum = (0.0F - rtb_Add1_m_idx_0) * Harmonic_Com.Harmonic_Id7th_Kp +
      rtDW.DiscreteTimeIntegrator_o;

    /* Saturate: '<S147>/Saturation' */
    if (rtb_Sum > Harmonic_Com.Harmonic_Id7th_Max) {
      rtb_Sum = Harmonic_Com.Harmonic_Id7th_Max;
    } else {
      if (rtb_Sum < Harmonic_Com.Harmonic_Id7th_Min) {
        rtb_Sum = Harmonic_Com.Harmonic_Id7th_Min;
      }
    }

    /* End of Saturate: '<S147>/Saturation' */

    /* Sum: '<S149>/Add' incorporates:
     *  Constant: '<S137>/iq7+'
     *  Constant: '<S149>/Kp'
     *  Product: '<S149>/Product'
     *  Sum: '<S137>/Sum7'
     */
    rtb_Add1_m_idx_1 = (0.0F - rtb_Add1_i) * Harmonic_Com.Harmonic_Iq7th_Kp +
      rtDW.DiscreteTimeIntegrator_d;

    /* Saturate: '<S149>/Saturation' */
    if (rtb_Add1_m_idx_1 > Harmonic_Com.Harmonic_Iq7th_Max) {
      rtb_Add1_m_idx_1 = Harmonic_Com.Harmonic_Iq7th_Max;
    } else {
      if (rtb_Add1_m_idx_1 < Harmonic_Com.Harmonic_Iq7th_Min) {
        rtb_Add1_m_idx_1 = Harmonic_Com.Harmonic_Iq7th_Min;
      }
    }

    /* End of Saturate: '<S149>/Saturation' */

    /* Sum: '<S137>/Sum10' incorporates:
     *  Constant: '<S137>/id7+'
     *  Constant: '<S137>/iq7+'
     *  Fcn: '<S150>/Fcn'
     *  Gain: '<S137>/Gain5'
     *  Gain: '<S137>/Gain7'
     *  Product: '<S137>/Product2'
     *  Sum: '<S137>/Sum6'
     *  Sum: '<S137>/Sum7'
     *  Sum: '<S137>/Sum8'
     */
    rtb_Add1_k_idx_1 = (0.4F * rtb_Sum - rtb_Fcn * rtb_Add1_m_idx_1 * 0.0042F) +
      (-rtb_Fcn * 0.0042F * (0.0F - rtb_Add1_i) + (0.0F - rtb_Add1_m_idx_0) *
       0.4F);

    /* Sum: '<S137>/Sum11' incorporates:
     *  Constant: '<S137>/id7+'
     *  Constant: '<S137>/iq7+'
     *  Fcn: '<S150>/Fcn1'
     *  Gain: '<S137>/Gain6'
     *  Gain: '<S137>/Gain9'
     *  Product: '<S137>/Product3'
     *  Sum: '<S137>/Sum6'
     *  Sum: '<S137>/Sum7'
     *  Sum: '<S137>/Sum9'
     */
    rtb_Add1_m_idx_1 = (rtb_Sum * rtb_Fcn * 0.004F + 0.4F * rtb_Add1_m_idx_1) +
      (rtb_Fcn * 0.004F * (0.0F - rtb_Add1_m_idx_0) + (0.0F - rtb_Add1_i) * 0.4F);

    /* Sum: '<S146>/Add' incorporates:
     *  Constant: '<S137>/id5+'
     *  Constant: '<S146>/Kp'
     *  Product: '<S146>/Product'
     *  Sum: '<S137>/Sum'
     */
    rtb_Fcn = (0.0F - rtb_Add1_b_idx_0) * Harmonic_Com.Harmonic_Id5th_Kp +
      rtDW.DiscreteTimeIntegrator_a;

    /* Saturate: '<S146>/Saturation' */
    if (rtb_Fcn > Harmonic_Com.Harmonic_Id5th_Max) {
      rtb_Fcn = Harmonic_Com.Harmonic_Id5th_Max;
    } else {
      if (rtb_Fcn < Harmonic_Com.Harmonic_Id5th_Min) {
        rtb_Fcn = Harmonic_Com.Harmonic_Id5th_Min;
      }
    }

    /* End of Saturate: '<S146>/Saturation' */

    /* Sum: '<S148>/Add' incorporates:
     *  Constant: '<S137>/iq5+'
     *  Constant: '<S148>/Kp'
     *  Product: '<S148>/Product'
     *  Sum: '<S137>/Sum1'
     */
    rtb_Sum = (0.0F - rtb_Add1_b_idx_1) * Harmonic_Com.Harmonic_Iq5th_Kp +
      rtDW.DiscreteTimeIntegrator_g;

    /* Saturate: '<S148>/Saturation' */
    if (rtb_Sum > Harmonic_Com.Harmonic_Iq5th_Max) {
      rtb_Sum = Harmonic_Com.Harmonic_Iq5th_Max;
    } else {
      if (rtb_Sum < Harmonic_Com.Harmonic_Iq5th_Min) {
        rtb_Sum = Harmonic_Com.Harmonic_Iq5th_Min;
      }
    }

    /* End of Saturate: '<S148>/Saturation' */

    /* Sum: '<S137>/Sum4' incorporates:
     *  Constant: '<S137>/id5+'
     *  Constant: '<S137>/iq5+'
     *  Fcn: '<S151>/Fcn'
     *  Gain: '<S137>/Gain'
     *  Gain: '<S137>/Gain2'
     *  Product: '<S137>/Product'
     *  Sum: '<S137>/Sum'
     *  Sum: '<S137>/Sum1'
     *  Sum: '<S137>/Sum2'
     */
    rtb_Fcn1_p = (rtb_Sum6 * 0.0042F * (0.0F - rtb_Add1_b_idx_1) + (0.0F -
      rtb_Add1_b_idx_0) * 0.4F) + (rtb_Sum6 * rtb_Sum * 0.0042F + 0.4F * rtb_Fcn);

    /* Sum: '<S137>/Sum5' incorporates:
     *  Constant: '<S137>/id5+'
     *  Constant: '<S137>/iq5+'
     *  Fcn: '<S151>/Fcn1'
     *  Gain: '<S137>/Gain1'
     *  Gain: '<S137>/Gain4'
     *  Product: '<S137>/Product1'
     *  Sum: '<S137>/Sum'
     *  Sum: '<S137>/Sum1'
     *  Sum: '<S137>/Sum3'
     */
    rtb_Sum6 = (-rtb_Sum6 * 0.004F * (0.0F - rtb_Add1_b_idx_0) + (0.0F -
      rtb_Add1_b_idx_1) * 0.4F) + (0.4F * rtb_Sum - rtb_Fcn * rtb_Sum6 * 0.004F);

    /* Sum: '<S137>/Sum12' incorporates:
     *  Fcn: '<S144>/Fcn'
     *  Fcn: '<S145>/Fcn'
     */
    rtDW.Sum12 = (rtb_Fcn1_p * rtDW.Cosine - rtb_Sum6 * rtDW.Sine_k) +
      (rtb_Add1_k_idx_1 * rtDW.Sum13 - rtb_Add1_m_idx_1 * rtDW.Sine_g);

    /* Fcn: '<S144>/Fcn1' */
    rtb_Fcn1_p = rtb_Fcn1_p * rtDW.Sine_k + rtb_Sum6 * rtDW.Cosine;

    /* Fcn: '<S145>/Fcn1' */
    rtb_Add1_k_idx_1 = rtb_Add1_k_idx_1 * rtDW.Sine_g + rtb_Add1_m_idx_1 *
      rtDW.Sum13;

    /* Sum: '<S137>/Sum13' */
    rtDW.Sum13 = rtb_Fcn1_p + rtb_Add1_k_idx_1;

    /* Update for DiscreteIntegrator: '<S147>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S137>/id7+'
     *  Constant: '<S147>/Ki'
     *  Product: '<S147>/Product1'
     *  Sum: '<S137>/Sum6'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE_h += (0.0F - rtb_Add1_m_idx_0) *
      Harmonic_Com.Harmonic_Id7th_Ki * 0.0001F;

    /* Update for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S137>/iq7+'
     *  Constant: '<S149>/Ki'
     *  Product: '<S149>/Product1'
     *  Sum: '<S137>/Sum7'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE_d += (0.0F - rtb_Add1_i) *
      Harmonic_Com.Harmonic_Iq7th_Ki * 0.0001F;

    /* Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S137>/id5+'
     *  Constant: '<S146>/Ki'
     *  Product: '<S146>/Product1'
     *  Sum: '<S137>/Sum'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE_m += (0.0F - rtb_Add1_b_idx_0) *
      Harmonic_Com.Harmonic_Id5th_Ki * 0.0001F;

    /* Update for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S137>/iq5+'
     *  Constant: '<S148>/Ki'
     *  Product: '<S148>/Product1'
     *  Sum: '<S137>/Sum1'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE_k += (0.0F - rtb_Add1_b_idx_1) *
      Harmonic_Com.Harmonic_Iq5th_Ki * 0.0001F;
  } else {
    if (rtDW.Har_Compensation_MODE) {
      /* Disable for DiscreteIntegrator: '<S147>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_DSTATE_h = rtDW.DiscreteTimeIntegrator_o;

      /* Disable for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_DSTATE_d = rtDW.DiscreteTimeIntegrator_d;

      /* Disable for DiscreteIntegrator: '<S146>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_DSTATE_m = rtDW.DiscreteTimeIntegrator_a;

      /* Disable for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_DSTATE_k = rtDW.DiscreteTimeIntegrator_g;
      rtDW.Har_Compensation_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S97>/Har_Compensation' */
}

/* Output and update for atomic system: '<S92>/Inverse_Park_Transform' */
void Inverse_Park_Transform(void)
{
  /* Sum: '<S98>/Add' incorporates:
   *  Product: '<S98>/Product1'
   *  Product: '<S98>/Product2'
   *  Sum: '<S98>/Add1'
   */
  V_alpha = rtDW.Add * rtDW.Add4 - rtDW.Add1_a * rtDW.Sine;

  /* Sum: '<S98>/Add3' incorporates:
   *  Product: '<S98>/Product3'
   *  Product: '<S98>/Product4'
   *  Sum: '<S98>/Add2'
   */
  V_beta = rtDW.Add * rtDW.Sine + rtDW.Add1_a * rtDW.Add4;
}

/* Output and update for atomic system: '<S92>/Park_Transform' */
void Park_Transform(void)
{
  /* Sum: '<S99>/Add1' incorporates:
   *  Product: '<S99>/Product1'
   *  Product: '<S99>/Product2'
   */
  Id_measured = Ialpha * rtDW.Add4 + Ibeta * rtDW.Sine;

  /* Sum: '<S99>/Add2' incorporates:
   *  Product: '<S99>/Produc3t'
   *  Product: '<S99>/Product4'
   */
  Iq_measured = Ibeta * rtDW.Add4 - Ialpha * rtDW.Sine;
}

/* Output and update for atomic system: '<S92>/Q_Current_PI' */
void Q_Current_PI(void)
{
  real32_T Merge1_d;
  real32_T Merge_h;
  real32_T rtb_Add_it;
  real32_T rtb_Switch_k;

  /* Sum: '<S100>/Add2' */
  rtb_Switch_k = Iq_ref - Iq_measured;

  /* DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_p != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE_i = 0.0F;
  }

  /* Sum: '<S152>/Add' incorporates:
   *  Constant: '<S152>/Kp'
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   *  Product: '<S152>/Product'
   */
  rtb_Add_it = PI_Parameter.IQ_Kp * rtb_Switch_k +
    rtDW.DiscreteTimeIntegrator_DSTATE_i;

  /* If: '<S152>/If1' incorporates:
   *  Constant: '<S152>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S152>/Over_M' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_h, &Merge1_d);

    /* End of Outputs for SubSystem: '<S152>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S152>/Normal' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_h, &Merge1_d);

    /* End of Outputs for SubSystem: '<S152>/Normal' */
  }

  /* End of If: '<S152>/If1' */

  /* Switch: '<S155>/Switch2' incorporates:
   *  RelationalOperator: '<S155>/LowerRelop1'
   *  RelationalOperator: '<S155>/UpperRelop'
   *  Switch: '<S155>/Switch'
   */
  if (rtb_Add_it > Merge_h) {
    /* Switch: '<S155>/Switch2' */
    Vq_voltage = Merge_h;
  } else if (rtb_Add_it < Merge1_d) {
    /* Switch: '<S155>/Switch' incorporates:
     *  Switch: '<S155>/Switch2'
     */
    Vq_voltage = Merge1_d;
  } else {
    /* Switch: '<S155>/Switch2' incorporates:
     *  Switch: '<S155>/Switch'
     */
    Vq_voltage = rtb_Add_it;
  }

  /* End of Switch: '<S155>/Switch2' */

  /* Switch: '<S152>/Switch' incorporates:
   *  Constant: '<S152>/Cons'
   *  UnitDelay: '<S152>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_i) {
    rtb_Switch_k = 0.0F;
  }

  /* End of Switch: '<S152>/Switch' */

  /* Update for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S152>/Ki'
   *  Product: '<S152>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_i += PI_Parameter.IQ_Ki * rtb_Switch_k *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_p = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S152>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S152>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_i = (rtb_Add_it == Vq_voltage);
}

/* Output and update for atomic system: '<S92>/SVPWM' */
void SVPWM(void)
{
  real32_T rtb_Add1_j;
  real32_T rtb_Gain_a;
  real32_T rtb_IndexVector1;
  real32_T rtb_IndexVector_c;
  real32_T rtb_Saturation;

  /* Outputs for Atomic SubSystem: '<S101>/XYZ Caculate' */
  /* Outputs for Atomic SubSystem: '<S101>/N Sector  Caculate' */
  /* Gain: '<S158>/Gain' incorporates:
   *  Gain: '<S161>/Gain'
   */
  rtb_Gain_a = 1.73205078F * rtDW.Add3;

  /* End of Outputs for SubSystem: '<S101>/XYZ Caculate' */

  /* Saturate: '<S158>/Saturation' incorporates:
   *  Gain: '<S158>/Gain'
   *  Gain: '<S158>/Gain1'
   *  Gain: '<S158>/Gain2'
   *  Sum: '<S158>/Add'
   *  Sum: '<S158>/Add1'
   *  Sum: '<S158>/Add2'
   *  Switch: '<S158>/Switch'
   *  Switch: '<S158>/Switch1'
   *  Switch: '<S158>/Switch2'
   */
  rtb_Saturation = (real32_T)((((rtb_Gain_a - rtDW.Add4 >= 0.0F) << 1) +
    (rtDW.Add4 >= 0.0F)) + (((0.0F - rtDW.Add4) - rtb_Gain_a >= 0.0F) << 2));
  if (rtb_Saturation > 6.0F) {
    rtb_Saturation = 6.0F;
  } else {
    if (rtb_Saturation < 1.0F) {
      rtb_Saturation = 1.0F;
    }
  }

  /* End of Saturate: '<S158>/Saturation' */
  /* End of Outputs for SubSystem: '<S101>/N Sector  Caculate' */

  /* Outputs for Atomic SubSystem: '<S101>/XYZ Caculate' */
  /* Saturate: '<S161>/Saturation' incorporates:
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (rtU.Bus_Voltage > 1200.0F) {
    rtb_Add1_j = 1200.0F;
  } else if (rtU.Bus_Voltage < 0.0001F) {
    rtb_Add1_j = 0.0001F;
  } else {
    rtb_Add1_j = rtU.Bus_Voltage;
  }

  /* End of Saturate: '<S161>/Saturation' */

  /* Product: '<S161>/Divide' incorporates:
   *  Constant: '<S161>/Constant'
   *  Constant: '<S92>/Constant4'
   */
  rtb_Add1_j = 0.000173205073F / rtb_Add1_j;

  /* End of Outputs for SubSystem: '<S101>/XYZ Caculate' */

  /* Outputs for Atomic SubSystem: '<S101>/T1 T2  Caculate' */
  /* MultiPortSwitch: '<S159>/Index Vector' incorporates:
   *  Gain: '<S159>/Gain'
   *  Gain: '<S159>/Gain1'
   *  Gain: '<S159>/Gain2'
   *  Gain: '<S161>/Gain1'
   *  Gain: '<S161>/Gain2'
   *  Product: '<S161>/Product'
   *  Product: '<S161>/Product1'
   *  Product: '<S161>/Product2'
   *  Sum: '<S161>/Add1'
   *  Sum: '<S161>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    /* Outputs for Atomic SubSystem: '<S101>/XYZ Caculate' */
    rtb_IndexVector_c = (rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_j;

    /* MultiPortSwitch: '<S159>/Index Vector1' incorporates:
     *  Gain: '<S161>/Gain1'
     *  Gain: '<S161>/Gain2'
     *  Product: '<S161>/Product1'
     *  Product: '<S161>/Product2'
     *  Sum: '<S161>/Add1'
     *  Sum: '<S161>/Add2'
     */
    rtb_Gain_a = ((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_j;

    /* End of Outputs for SubSystem: '<S101>/XYZ Caculate' */
    break;

   case 2:
    /* Outputs for Atomic SubSystem: '<S101>/XYZ Caculate' */
    rtb_IndexVector_c = ((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_j;

    /* MultiPortSwitch: '<S159>/Index Vector1' incorporates:
     *  Gain: '<S159>/Gain'
     *  Gain: '<S161>/Gain2'
     *  Product: '<S161>/Product'
     *  Product: '<S161>/Product1'
     *  Sum: '<S161>/Add2'
     */
    rtb_Gain_a = -(rtDW.Add4 * rtb_Add1_j);

    /* End of Outputs for SubSystem: '<S101>/XYZ Caculate' */
    break;

   case 3:
    /* Outputs for Atomic SubSystem: '<S101>/XYZ Caculate' */
    rtb_IndexVector_c = -((rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_j);

    /* MultiPortSwitch: '<S159>/Index Vector1' incorporates:
     *  Gain: '<S159>/Gain2'
     *  Gain: '<S161>/Gain1'
     *  Product: '<S161>/Product'
     *  Product: '<S161>/Product2'
     *  Sum: '<S161>/Add1'
     */
    rtb_Gain_a = rtDW.Add4 * rtb_Add1_j;

    /* End of Outputs for SubSystem: '<S101>/XYZ Caculate' */
    break;

   case 4:
    /* Outputs for Atomic SubSystem: '<S101>/XYZ Caculate' */
    rtb_IndexVector_c = -(rtDW.Add4 * rtb_Add1_j);

    /* MultiPortSwitch: '<S159>/Index Vector1' incorporates:
     *  Gain: '<S159>/Gain'
     *  Gain: '<S161>/Gain1'
     *  Product: '<S161>/Product'
     *  Product: '<S161>/Product2'
     *  Sum: '<S161>/Add1'
     */
    rtb_Gain_a = (rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_j;

    /* End of Outputs for SubSystem: '<S101>/XYZ Caculate' */
    break;

   case 5:
    /* Outputs for Atomic SubSystem: '<S101>/XYZ Caculate' */
    rtb_IndexVector_c = rtDW.Add4 * rtb_Add1_j;

    /* MultiPortSwitch: '<S159>/Index Vector1' incorporates:
     *  Gain: '<S159>/Gain1'
     *  Gain: '<S161>/Gain2'
     *  Product: '<S161>/Product'
     *  Product: '<S161>/Product1'
     *  Sum: '<S161>/Add2'
     */
    rtb_Gain_a = -(((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_j);

    /* End of Outputs for SubSystem: '<S101>/XYZ Caculate' */
    break;

   default:
    /* Outputs for Atomic SubSystem: '<S101>/XYZ Caculate' */
    rtb_IndexVector_c = -(((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_j);

    /* MultiPortSwitch: '<S159>/Index Vector1' incorporates:
     *  Gain: '<S159>/Gain1'
     *  Gain: '<S159>/Gain2'
     *  Gain: '<S161>/Gain1'
     *  Gain: '<S161>/Gain2'
     *  Product: '<S161>/Product1'
     *  Product: '<S161>/Product2'
     *  Sum: '<S161>/Add1'
     *  Sum: '<S161>/Add2'
     */
    rtb_Gain_a = -((rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_j);

    /* End of Outputs for SubSystem: '<S101>/XYZ Caculate' */
    break;
  }

  /* End of MultiPortSwitch: '<S159>/Index Vector' */

  /* Sum: '<S159>/Add' */
  rtb_Add1_j = rtb_IndexVector_c + rtb_Gain_a;

  /* Switch: '<S159>/Switch' incorporates:
   *  Constant: '<S92>/Constant4'
   *  Product: '<S159>/Divide'
   *  Product: '<S159>/Divide1'
   *  Sum: '<S159>/Add1'
   *  Switch: '<S159>/Switch2'
   */
  if (!(0.0001F - rtb_Add1_j > 0.0F)) {
    rtb_IndexVector_c = rtb_IndexVector_c * 0.0001F / rtb_Add1_j;
    rtb_Gain_a *= 1.0F / rtb_Add1_j * 0.0001F;
  }

  /* End of Switch: '<S159>/Switch' */
  /* End of Outputs for SubSystem: '<S101>/T1 T2  Caculate' */

  /* Outputs for Atomic SubSystem: '<S101>/Tcm calculate' */
  /* Gain: '<S160>/Gain2' incorporates:
   *  Constant: '<S92>/Constant4'
   *  Sum: '<S160>/Add'
   */
  rtb_Add1_j = ((0.0001F - rtb_IndexVector_c) - rtb_Gain_a) * 0.25F;

  /* Sum: '<S160>/Add1' incorporates:
   *  Gain: '<S160>/Gain'
   */
  rtb_IndexVector_c = 0.5F * rtb_IndexVector_c + rtb_Add1_j;

  /* MultiPortSwitch: '<S160>/Index Vector' incorporates:
   *  Gain: '<S160>/Gain1'
   *  Sum: '<S160>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S160>/Index Vector1' */
    rtb_IndexVector1 = rtb_Add1_j;

    /* MultiPortSwitch: '<S160>/Index Vector2' incorporates:
     *  Gain: '<S160>/Gain1'
     *  Sum: '<S160>/Add2'
     */
    rtb_Add1_j = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 2:
    rtb_Saturation = rtb_Add1_j;

    /* MultiPortSwitch: '<S160>/Index Vector1' incorporates:
     *  Gain: '<S160>/Gain1'
     *  Sum: '<S160>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S160>/Index Vector2' */
    rtb_Add1_j = rtb_IndexVector_c;
    break;

   case 3:
    rtb_Saturation = rtb_Add1_j;

    /* MultiPortSwitch: '<S160>/Index Vector1' */
    rtb_IndexVector1 = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S160>/Index Vector2' incorporates:
     *  Gain: '<S160>/Gain1'
     *  Sum: '<S160>/Add2'
     */
    rtb_Add1_j = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 4:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S160>/Index Vector1' incorporates:
     *  Gain: '<S160>/Gain1'
     *  Sum: '<S160>/Add2'
     */
    rtb_IndexVector1 = rtb_IndexVector_c;
    break;

   case 5:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S160>/Index Vector1' incorporates:
     *  Gain: '<S160>/Gain1'
     *  Sum: '<S160>/Add2'
     */
    rtb_IndexVector1 = rtb_Add1_j;

    /* MultiPortSwitch: '<S160>/Index Vector2' */
    rtb_Add1_j = rtb_IndexVector_c;
    break;

   default:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S160>/Index Vector1' incorporates:
     *  Gain: '<S160>/Gain1'
     *  Sum: '<S160>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;
  }

  /* End of MultiPortSwitch: '<S160>/Index Vector' */
  /* End of Outputs for SubSystem: '<S101>/Tcm calculate' */

  /* If: '<S101>/If1' */
  if (rtDW.Merge1_a == 0) {
    /* Outputs for IfAction SubSystem: '<S101>/Enable_Motor' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    /* Merge: '<S101>/Merge' incorporates:
     *  Gain: '<S101>/Gain'
     *  Inport: '<S157>/In1'
     */
    rtDW.Merge_c4 = 8.399E+7F * rtb_Saturation;

    /* Merge: '<S101>/Merge1' incorporates:
     *  Gain: '<S101>/Gain2'
     *  Inport: '<S157>/In2'
     */
    rtDW.Merge1_h = 8.399E+7F * rtb_IndexVector1;

    /* Merge: '<S101>/Merge2' incorporates:
     *  Gain: '<S101>/Gain3'
     *  Inport: '<S157>/In3'
     */
    rtDW.Merge2_d = 8.399E+7F * rtb_Add1_j;

    /* End of Outputs for SubSystem: '<S101>/Enable_Motor' */
  } else {
    if (rtDW.Merge1_a == 1) {
      /* Outputs for IfAction SubSystem: '<S101>/Disable_Motor' incorporates:
       *  ActionPort: '<S156>/Action Port'
       */
      /* Merge: '<S101>/Merge' incorporates:
       *  Constant: '<S156>/Constant'
       *  SignalConversion generated from: '<S156>/Out1'
       */
      rtDW.Merge_c4 = 0.0F;

      /* Merge: '<S101>/Merge1' incorporates:
       *  Constant: '<S156>/Constant1'
       *  SignalConversion generated from: '<S156>/Out2'
       */
      rtDW.Merge1_h = 0.0F;

      /* Merge: '<S101>/Merge2' incorporates:
       *  Constant: '<S156>/Constant2'
       *  SignalConversion generated from: '<S156>/Out3'
       */
      rtDW.Merge2_d = 0.0F;

      /* End of Outputs for SubSystem: '<S101>/Disable_Motor' */
    }
  }

  /* End of If: '<S101>/If1' */
}

/* Output and update for atomic system: '<S92>/Sine_Cosine' */
void Sine_Cosine(void)
{
  real32_T rtb_Saturation;
  uint32_T Add4_tmp;

  /* Saturate: '<S102>/Saturation' */
  if (rtDW.Merge1_i > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Merge1_i < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Merge1_i;
  }

  /* End of Saturate: '<S102>/Saturation' */

  /* Lookup_n-D: '<S102>/Cosine' incorporates:
   *  Lookup_n-D: '<S102>/Sine'
   *  Saturate: '<S102>/Saturation'
   */
  Add4_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);
  rtDW.Add4 = rtConstP.pooled28[Add4_tmp];

  /* Lookup_n-D: '<S102>/Sine' */
  rtDW.Sine = rtConstP.pooled30[Add4_tmp];
}

/* Output and update for atomic system: '<S5>/FOC' */
void FOC(void)
{
  /* Outputs for Atomic SubSystem: '<S92>/Clarke_Transform' */
  Clarke_Transform();

  /* End of Outputs for SubSystem: '<S92>/Clarke_Transform' */

  /* Outputs for Atomic SubSystem: '<S92>/Sine_Cosine' */
  Sine_Cosine();

  /* End of Outputs for SubSystem: '<S92>/Sine_Cosine' */

  /* Outputs for Atomic SubSystem: '<S92>/Park_Transform' */
  Park_Transform();

  /* End of Outputs for SubSystem: '<S92>/Park_Transform' */

  /* Outputs for Atomic SubSystem: '<S92>/D_Current_PI' */
  D_Current_PI();

  /* End of Outputs for SubSystem: '<S92>/D_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S92>/Q_Current_PI' */
  Q_Current_PI();

  /* End of Outputs for SubSystem: '<S92>/Q_Current_PI' */

  /* Constant: '<S92>/Constant1' */
  rtDW.Constant1 = FF_Enable;

  /* Gain: '<S92>/Pn ' incorporates:
   *  Outport: '<Root>/Speed_Measured'
   */
  rtDW.Add3 = 0.209439516F * rtY.Speed_Measured;

  /* Outputs for Atomic SubSystem: '<S92>/FeedForward' */
  FeedForward();

  /* End of Outputs for SubSystem: '<S92>/FeedForward' */

  /* Sum: '<S92>/Add1' */
  rtDW.Add1_a = Vq_voltage + rtDW.Subtract3;

  /* Sum: '<S92>/Add' */
  rtDW.Add = Vd_voltage + rtDW.Subtract1;

  /* Outputs for Atomic SubSystem: '<S92>/Inverse_Park_Transform' */
  Inverse_Park_Transform();

  /* End of Outputs for SubSystem: '<S92>/Inverse_Park_Transform' */

  /* Constant: '<S92>/Constant3' */
  rtDW.Constant3 = Dead_Com_Enable;

  /* Outputs for Atomic SubSystem: '<S92>/DT_Compensation' */
  DT_Compensation();

  /* End of Outputs for SubSystem: '<S92>/DT_Compensation' */

  /* Constant: '<S92>/Constant5' */
  rtDW.Constant5 = Harmonic_Com.Harmonic_Com_Enable;

  /* Outputs for Atomic SubSystem: '<S92>/Har_Compensation' */
  Har_Compensation();

  /* End of Outputs for SubSystem: '<S92>/Har_Compensation' */

  /* Sum: '<S92>/Add3' */
  rtDW.Add3 = (rtDW.Fcn + V_alpha) + rtDW.Sum12;

  /* Sum: '<S92>/Add4' */
  rtDW.Add4 = (rtDW.Fcn1 + V_beta) + rtDW.Sum13;

  /* Outputs for Atomic SubSystem: '<S92>/SVPWM' */
  SVPWM();

  /* End of Outputs for SubSystem: '<S92>/SVPWM' */
}

/* Output and update for function-call system: '<S2>/FOC_Control_100us' */
void FOC_Control_100us(void)
{
  /* Outputs for Atomic SubSystem: '<S5>/FOC' */
  FOC();

  /* End of Outputs for SubSystem: '<S5>/FOC' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
