/*
 * File: FOC_Control_100us.c
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

#include "FOC_Control_100us.h"

/* Include model header file for global data */
#include "FOC_Motor_Control.h"
#include "FOC_Motor_Control_private.h"

/* Output and update for atomic system: '<S95>/Clarke_Transform' */
void Clarke_Transform(void)
{
  /* Outputs for Atomic SubSystem: '<S96>/Clark1' */
  /* Gain: '<S107>/Gain2' incorporates:
   *  Gain: '<S107>/Gain'
   *  Gain: '<S107>/Gain1'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S107>/Add'
   */
  Ialpha = ((rtU.Phase_CurrentABC[0] - 0.5F * rtU.Phase_CurrentABC[1]) - 0.5F *
            rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* Gain: '<S107>/Gain5' incorporates:
   *  Gain: '<S107>/Gain3'
   *  Gain: '<S107>/Gain4'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S107>/Add1'
   */
  Ibeta = (0.866025388F * rtU.Phase_CurrentABC[1] - 0.866025388F *
           rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* End of Outputs for SubSystem: '<S96>/Clark1' */
}

/* Output and update for atomic system: '<S95>/DT_Compensation' */
void DT_Compensation(void)
{
  real32_T rtb_Add1_j;
  real32_T rtb_Add1_n;
  real32_T rtb_Fcn;
  real32_T rtb_Itheta2;
  real32_T rtb_Merge1;

  /* Outputs for Enabled SubSystem: '<S97>/DT_Compensation' incorporates:
   *  EnablePort: '<S108>/Enable'
   */
  if (rtDW.Constant3 > 0.0F) {
    /* Fcn: '<S108>/Fcn' incorporates:
     *  Constant: '<S95>/Constant2'
     *  Constant: '<S95>/IdRef2'
     *  Inport: '<Root>/Bus_Voltage'
     */
    rtb_Fcn = Dead_Time * rtU.Bus_Voltage / 0.0001F;

    /* Sum: '<S114>/Add1' incorporates:
     *  Constant: '<S114>/Constant1'
     *  Product: '<S114>/Divide1'
     *  Sum: '<S114>/Add'
     *  UnitDelay: '<S114>/Unit Delay'
     */
    rtb_Add1_n = (Id_measured - rtDW.UnitDelay_DSTATE_p) * 0.005F +
      rtDW.UnitDelay_DSTATE_p;

    /* Sum: '<S113>/Add1' incorporates:
     *  Constant: '<S113>/Constant1'
     *  Product: '<S113>/Divide1'
     *  Sum: '<S113>/Add'
     *  UnitDelay: '<S113>/Unit Delay'
     */
    rtb_Add1_j = (Iq_measured - rtDW.UnitDelay_DSTATE_n) * 0.005F +
      rtDW.UnitDelay_DSTATE_n;

    /* If: '<S115>/B>0' */
    if (rtb_Add1_n > 0.0F) {
      /* Outputs for IfAction SubSystem: '<S115>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S121>/Action Port'
       */
      /* Lookup_n-D: '<S121>/1-D Lookup Table4' incorporates:
       *  Product: '<S121>/Divide'
       *  Saturate: '<S121>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 > 572.0F) {
        rtb_Itheta2 = 572.0F;
      } else {
        if (rtb_Itheta2 < -572.0F) {
          rtb_Itheta2 = -572.0F;
        }
      }

      /* Merge: '<S115>/Merge2' incorporates:
       *  Lookup_n-D: '<S121>/1-D Lookup Table4'
       *  SignalConversion generated from: '<S121>/IsTheta'
       */
      rtDW.Merge2_n = rtConstP.pooled6[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)];

      /* End of Outputs for SubSystem: '<S115>/If Action Subsystem8' */
    }

    /* End of If: '<S115>/B>0' */

    /* If: '<S115>/A>=0andB<0' */
    if ((rtb_Add1_j >= 0.0F) && (rtb_Add1_n < 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S115>/If Action Subsystem9' incorporates:
       *  ActionPort: '<S122>/Action Port'
       */
      /* Lookup_n-D: '<S122>/1-D Lookup Table4' incorporates:
       *  Product: '<S122>/Divide'
       *  Saturate: '<S122>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 < -572.0F) {
        rtb_Itheta2 = -572.0F;
      }

      /* Merge: '<S115>/Merge2' incorporates:
       *  Constant: '<S122>/Constant'
       *  Lookup_n-D: '<S122>/1-D Lookup Table4'
       *  SignalConversion generated from: '<S122>/IsTheta'
       *  Sum: '<S122>/Add'
       */
      rtDW.Merge2_n = rtConstP.pooled6[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)] + 3.14159274F;

      /* End of Outputs for SubSystem: '<S115>/If Action Subsystem9' */
    }

    /* End of If: '<S115>/A>=0andB<0' */

    /* If: '<S115>/B<0andA<0' */
    if ((rtb_Add1_j < 0.0F) && (rtb_Add1_n < 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S115>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S118>/Action Port'
       */
      /* Lookup_n-D: '<S118>/1-D Lookup Table4' incorporates:
       *  Product: '<S118>/Divide'
       *  Saturate: '<S118>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 > 572.0F) {
        rtb_Itheta2 = 572.0F;
      }

      /* Merge: '<S115>/Merge2' incorporates:
       *  Constant: '<S118>/Constant'
       *  Lookup_n-D: '<S118>/1-D Lookup Table4'
       *  Sum: '<S118>/Add'
       */
      rtDW.Merge2_n = rtConstP.pooled6[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)] - 3.14159274F;

      /* End of Outputs for SubSystem: '<S115>/If Action Subsystem10' */
    }

    /* End of If: '<S115>/B<0andA<0' */

    /* If: '<S115>/B=0andA>0' */
    if ((rtb_Add1_j > 0.0F) && (rtb_Add1_n == 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S115>/If Action Subsystem11' incorporates:
       *  ActionPort: '<S119>/Action Port'
       */
      /* Merge: '<S115>/Merge2' incorporates:
       *  Constant: '<S119>/Constant'
       *  SignalConversion generated from: '<S119>/IsTheta'
       */
      rtDW.Merge2_n = 1.57079637F;

      /* End of Outputs for SubSystem: '<S115>/If Action Subsystem11' */
    }

    /* End of If: '<S115>/B=0andA>0' */

    /* If: '<S115>/B=0andA<0' */
    if ((rtb_Add1_j < 0.0F) && (rtb_Add1_n == 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S115>/If Action Subsystem12' incorporates:
       *  ActionPort: '<S120>/Action Port'
       */
      /* Merge: '<S115>/Merge2' incorporates:
       *  Constant: '<S120>/Constant'
       *  SignalConversion generated from: '<S120>/IsTheta'
       */
      rtDW.Merge2_n = -1.57079637F;

      /* End of Outputs for SubSystem: '<S115>/If Action Subsystem12' */
    }

    /* End of If: '<S115>/B=0andA<0' */

    /* Sum: '<S109>/Add1' */
    rtb_Itheta2 = rtDW.Merge2_n + rtDW.Merge_g;

    /* If: '<S112>/If1' incorporates:
     *  Inport: '<S116>/Angle_input'
     */
    if (rtb_Itheta2 > 6.28318548F) {
      /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S117>/Action Port'
       */
      IfActionSubsystem2(rtb_Itheta2, &rtb_Merge1);

      /* End of Outputs for SubSystem: '<S112>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S116>/Action Port'
       */
      rtb_Merge1 = rtb_Itheta2;

      /* End of Outputs for SubSystem: '<S112>/If Action Subsystem1' */
    }

    /* End of If: '<S112>/If1' */

    /* If: '<S110>/If1' */
    if ((rtb_Merge1 > 5.75958F) || (rtb_Merge1 <= 0.523598F)) {
      /* Outputs for IfAction SubSystem: '<S110>/Subsystem' incorporates:
       *  ActionPort: '<S123>/Action Port'
       */
      /* Gain: '<S123>/Gain' */
      rtDW.Merge_p[0] = rtb_Fcn;

      /* Gain: '<S123>/Gain1' */
      rtDW.Merge_p[1] = -rtb_Fcn;

      /* Gain: '<S123>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S110>/Subsystem' */
    } else if ((rtb_Merge1 > 0.523598F) && (rtb_Merge1 <= 1.57079601F)) {
      /* Outputs for IfAction SubSystem: '<S110>/Subsystem1' incorporates:
       *  ActionPort: '<S124>/Action Port'
       */
      /* Gain: '<S124>/Gain' */
      rtDW.Merge_p[0] = rtb_Fcn;

      /* Gain: '<S124>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S124>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S110>/Subsystem1' */
    } else if ((rtb_Merge1 > 1.57079601F) && (rtb_Merge1 <= 2.61799312F)) {
      /* Outputs for IfAction SubSystem: '<S110>/Subsystem2' incorporates:
       *  ActionPort: '<S125>/Action Port'
       */
      /* Gain: '<S125>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S125>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S125>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S110>/Subsystem2' */
    } else if ((rtb_Merge1 > 2.61799312F) && (rtb_Merge1 <= 3.66519094F)) {
      /* Outputs for IfAction SubSystem: '<S110>/Subsystem3' incorporates:
       *  ActionPort: '<S126>/Action Port'
       */
      /* Gain: '<S126>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S126>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S126>/Gain2' */
      rtDW.Merge_p[2] = rtb_Fcn;

      /* End of Outputs for SubSystem: '<S110>/Subsystem3' */
    } else if ((rtb_Merge1 > 3.66519094F) && (rtb_Merge1 <= 4.71238899F)) {
      /* Outputs for IfAction SubSystem: '<S110>/Subsystem4' incorporates:
       *  ActionPort: '<S127>/Action Port'
       */
      /* Gain: '<S127>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S127>/Gain1' */
      rtDW.Merge_p[1] = -rtb_Fcn;

      /* Gain: '<S127>/Gain2' */
      rtDW.Merge_p[2] = rtb_Fcn;

      /* End of Outputs for SubSystem: '<S110>/Subsystem4' */
    } else {
      if ((rtb_Merge1 > 4.71238899F) && (rtb_Merge1 <= 5.75958F)) {
        /* Outputs for IfAction SubSystem: '<S110>/Subsystem5' incorporates:
         *  ActionPort: '<S128>/Action Port'
         */
        /* Gain: '<S128>/Gain' */
        rtDW.Merge_p[0] = rtb_Fcn;

        /* Gain: '<S128>/Gain1' */
        rtDW.Merge_p[1] = -rtb_Fcn;

        /* Gain: '<S128>/Gain2' */
        rtDW.Merge_p[2] = rtb_Fcn;

        /* End of Outputs for SubSystem: '<S110>/Subsystem5' */
      }
    }

    /* End of If: '<S110>/If1' */

    /* Fcn: '<S111>/Fcn' */
    rtDW.Fcn = ((rtDW.Merge_p[0] - 0.5F * rtDW.Merge_p[1]) - 0.5F *
                rtDW.Merge_p[2]) * 0.666666687F;

    /* Fcn: '<S111>/Fcn1' */
    rtDW.Fcn1 = (rtDW.Merge_p[1] - rtDW.Merge_p[2]) * 0.577350259F;

    /* Update for UnitDelay: '<S114>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_p = rtb_Add1_n;

    /* Update for UnitDelay: '<S113>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_n = rtb_Add1_j;
  }

  /* End of Outputs for SubSystem: '<S97>/DT_Compensation' */
}

/*
 * Output and update for action system:
 *    '<S129>/Over_M'
 *    '<S195>/Over_M'
 */
void Over_M(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S131>/Gain' */
  *rty_Out1 = 0.666666687F * rtu_Bus_voltage;

  /* Gain: '<S131>/Gain1' */
  *rty_Out2 = -0.666666687F * rtu_Bus_voltage;
}

/*
 * Output and update for action system:
 *    '<S129>/Normal'
 *    '<S195>/Normal'
 */
void Normal(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S130>/Gain' */
  *rty_Out1 = 0.577350259F * rtu_Bus_voltage;

  /* Gain: '<S130>/Gain1' */
  *rty_Out2 = -0.577350259F * rtu_Bus_voltage;
}

/* Output and update for atomic system: '<S95>/D_Current_PI' */
void D_Current_PI(void)
{
  real32_T Merge1_b;
  real32_T Merge_a;
  real32_T rtb_Add_jn;
  real32_T rtb_Switch_h;

  /* Sum: '<S98>/Add2' */
  rtb_Switch_h = Id_ref - Id_measured;

  /* DiscreteIntegrator: '<S129>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_pb !=
       0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_a = 0.0F;
  }

  /* Sum: '<S129>/Add' incorporates:
   *  Constant: '<S129>/Kp'
   *  DiscreteIntegrator: '<S129>/Discrete-Time Integrator'
   *  Product: '<S129>/Product'
   */
  rtb_Add_jn = PI_Parameter.ID_Kp * rtb_Switch_h +
    rtDW.DiscreteTimeIntegrator_DSTATE_a;

  /* If: '<S129>/If1' incorporates:
   *  Constant: '<S129>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S129>/Over_M' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S129>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S129>/Normal' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S129>/Normal' */
  }

  /* End of If: '<S129>/If1' */

  /* Switch: '<S132>/Switch2' incorporates:
   *  RelationalOperator: '<S132>/LowerRelop1'
   *  RelationalOperator: '<S132>/UpperRelop'
   *  Switch: '<S132>/Switch'
   */
  if (rtb_Add_jn > Merge_a) {
    /* Switch: '<S132>/Switch2' */
    Vd_voltage = Merge_a;
  } else if (rtb_Add_jn < Merge1_b) {
    /* Switch: '<S132>/Switch' incorporates:
     *  Switch: '<S132>/Switch2'
     */
    Vd_voltage = Merge1_b;
  } else {
    /* Switch: '<S132>/Switch2' incorporates:
     *  Switch: '<S132>/Switch'
     */
    Vd_voltage = rtb_Add_jn;
  }

  /* End of Switch: '<S132>/Switch2' */

  /* Switch: '<S129>/Switch' incorporates:
   *  Constant: '<S129>/Cons'
   *  UnitDelay: '<S129>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_k) {
    rtb_Switch_h = 0.0F;
  }

  /* End of Switch: '<S129>/Switch' */

  /* Update for DiscreteIntegrator: '<S129>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S129>/Ki'
   *  Product: '<S129>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += PI_Parameter.ID_Ki * rtb_Switch_h *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_pb = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S129>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S129>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_k = (rtb_Add_jn == Vd_voltage);
}

/* Output and update for atomic system: '<S135>/Sine_Cosine' */
void Sine_Cosine(void)
{
  real32_T rtb_Saturation;
  uint32_T Add1_n_tmp;

  /* Saturate: '<S139>/Saturation' */
  if (rtDW.UnitDelay > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.UnitDelay < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.UnitDelay;
  }

  /* End of Saturate: '<S139>/Saturation' */

  /* Lookup_n-D: '<S139>/Cosine' incorporates:
   *  Lookup_n-D: '<S139>/Sine'
   *  Saturate: '<S139>/Saturation'
   */
  Add1_n_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);

  /* Sum: '<S134>/Add1' incorporates:
   *  Lookup_n-D: '<S139>/Cosine'
   */
  rtDW.Add1_n = rtConstP.pooled29[Add1_n_tmp];

  /* Lookup_n-D: '<S139>/Sine' */
  rtDW.Sine = rtConstP.pooled31[Add1_n_tmp];
}

/* Output and update for atomic system: '<S95>/Inverse_Park_Transform' */
void Inverse_Park_Transform(void)
{
  /* Sum: '<S101>/Add' incorporates:
   *  Product: '<S101>/Product1'
   *  Product: '<S101>/Product2'
   *  Sum: '<S101>/Add1'
   */
  V_alpha = Vd_voltage * rtDW.Add4 - Vq_voltage * rtDW.Add3;

  /* Sum: '<S101>/Add3' incorporates:
   *  Product: '<S101>/Product3'
   *  Product: '<S101>/Product4'
   *  Sum: '<S101>/Add2'
   */
  V_beta = Vd_voltage * rtDW.Add3 + Vq_voltage * rtDW.Add4;
}

/* Output and update for atomic system: '<S95>/Park_Transform' */
void Park_Transform(void)
{
  /* Sum: '<S103>/Add1' incorporates:
   *  Product: '<S103>/Product1'
   *  Product: '<S103>/Product2'
   */
  Id_measured = Ialpha * rtDW.Add4 + Ibeta * rtDW.Add3;

  /* Sum: '<S103>/Add2' incorporates:
   *  Product: '<S103>/Produc3t'
   *  Product: '<S103>/Product4'
   */
  Iq_measured = Ibeta * rtDW.Add4 - Ialpha * rtDW.Add3;
}

/* Output and update for atomic system: '<S95>/Q_Current_PI' */
void Q_Current_PI(void)
{
  real32_T Merge1_d;
  real32_T Merge_hp;
  real32_T rtb_Add_it;
  real32_T rtb_Switch_k;

  /* Sum: '<S104>/Add2' */
  rtb_Switch_k = Iq_ref - Iq_measured;

  /* DiscreteIntegrator: '<S195>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_p != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE_i = 0.0F;
  }

  /* Sum: '<S195>/Add' incorporates:
   *  Constant: '<S195>/Kp'
   *  DiscreteIntegrator: '<S195>/Discrete-Time Integrator'
   *  Product: '<S195>/Product'
   */
  rtb_Add_it = PI_Parameter.IQ_Kp * rtb_Switch_k +
    rtDW.DiscreteTimeIntegrator_DSTATE_i;

  /* If: '<S195>/If1' incorporates:
   *  Constant: '<S195>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S195>/Over_M' incorporates:
     *  ActionPort: '<S197>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_hp, &Merge1_d);

    /* End of Outputs for SubSystem: '<S195>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S195>/Normal' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_hp, &Merge1_d);

    /* End of Outputs for SubSystem: '<S195>/Normal' */
  }

  /* End of If: '<S195>/If1' */

  /* Switch: '<S198>/Switch2' incorporates:
   *  RelationalOperator: '<S198>/LowerRelop1'
   *  RelationalOperator: '<S198>/UpperRelop'
   *  Switch: '<S198>/Switch'
   */
  if (rtb_Add_it > Merge_hp) {
    Vq_voltage = Merge_hp;
  } else if (rtb_Add_it < Merge1_d) {
    /* Switch: '<S198>/Switch' */
    Vq_voltage = Merge1_d;
  } else {
    Vq_voltage = rtb_Add_it;
  }

  /* End of Switch: '<S198>/Switch2' */

  /* Switch: '<S195>/Switch' incorporates:
   *  Constant: '<S195>/Cons'
   *  UnitDelay: '<S195>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_i) {
    rtb_Switch_k = 0.0F;
  }

  /* End of Switch: '<S195>/Switch' */

  /* Update for DiscreteIntegrator: '<S195>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S195>/Ki'
   *  Product: '<S195>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_i += PI_Parameter.IQ_Ki * rtb_Switch_k *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_p = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S195>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S195>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_i = (rtb_Add_it == Vq_voltage);
}

/* Output and update for atomic system: '<S95>/SVPWM' */
void SVPWM(void)
{
  real32_T rtb_Add1_n;
  real32_T rtb_Gain_a;
  real32_T rtb_IndexVector1;
  real32_T rtb_IndexVector_c;
  real32_T rtb_Saturation;

  /* Outputs for Atomic SubSystem: '<S105>/XYZ Caculate' */
  /* Outputs for Atomic SubSystem: '<S105>/N Sector  Caculate' */
  /* Gain: '<S201>/Gain' incorporates:
   *  Gain: '<S204>/Gain'
   */
  rtb_Gain_a = 1.73205078F * rtDW.Add3;

  /* End of Outputs for SubSystem: '<S105>/XYZ Caculate' */

  /* Saturate: '<S201>/Saturation' incorporates:
   *  Gain: '<S201>/Gain'
   *  Gain: '<S201>/Gain1'
   *  Gain: '<S201>/Gain2'
   *  Sum: '<S201>/Add'
   *  Sum: '<S201>/Add1'
   *  Sum: '<S201>/Add2'
   *  Switch: '<S201>/Switch'
   *  Switch: '<S201>/Switch1'
   *  Switch: '<S201>/Switch2'
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

  /* End of Saturate: '<S201>/Saturation' */
  /* End of Outputs for SubSystem: '<S105>/N Sector  Caculate' */

  /* Outputs for Atomic SubSystem: '<S105>/XYZ Caculate' */
  /* Saturate: '<S204>/Saturation' incorporates:
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (rtU.Bus_Voltage > 1200.0F) {
    rtb_Add1_n = 1200.0F;
  } else if (rtU.Bus_Voltage < 0.0001F) {
    rtb_Add1_n = 0.0001F;
  } else {
    rtb_Add1_n = rtU.Bus_Voltage;
  }

  /* End of Saturate: '<S204>/Saturation' */

  /* Product: '<S204>/Divide' incorporates:
   *  Constant: '<S204>/Constant'
   *  Constant: '<S95>/Constant4'
   */
  rtb_Add1_n = 0.000173205073F / rtb_Add1_n;

  /* End of Outputs for SubSystem: '<S105>/XYZ Caculate' */

  /* Outputs for Atomic SubSystem: '<S105>/T1 T2  Caculate' */
  /* MultiPortSwitch: '<S202>/Index Vector' incorporates:
   *  Gain: '<S202>/Gain'
   *  Gain: '<S202>/Gain1'
   *  Gain: '<S202>/Gain2'
   *  Gain: '<S204>/Gain1'
   *  Gain: '<S204>/Gain2'
   *  Product: '<S204>/Product'
   *  Product: '<S204>/Product1'
   *  Product: '<S204>/Product2'
   *  Sum: '<S204>/Add1'
   *  Sum: '<S204>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    /* Outputs for Atomic SubSystem: '<S105>/XYZ Caculate' */
    rtb_IndexVector_c = (rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_n;

    /* MultiPortSwitch: '<S202>/Index Vector1' incorporates:
     *  Gain: '<S204>/Gain1'
     *  Gain: '<S204>/Gain2'
     *  Product: '<S204>/Product1'
     *  Product: '<S204>/Product2'
     *  Sum: '<S204>/Add1'
     *  Sum: '<S204>/Add2'
     */
    rtb_Gain_a = ((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S105>/XYZ Caculate' */
    break;

   case 2:
    /* Outputs for Atomic SubSystem: '<S105>/XYZ Caculate' */
    rtb_IndexVector_c = ((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_n;

    /* MultiPortSwitch: '<S202>/Index Vector1' incorporates:
     *  Gain: '<S202>/Gain'
     *  Gain: '<S204>/Gain2'
     *  Product: '<S204>/Product'
     *  Product: '<S204>/Product1'
     *  Sum: '<S204>/Add2'
     */
    rtb_Gain_a = -(rtDW.Add4 * rtb_Add1_n);

    /* End of Outputs for SubSystem: '<S105>/XYZ Caculate' */
    break;

   case 3:
    /* Outputs for Atomic SubSystem: '<S105>/XYZ Caculate' */
    rtb_IndexVector_c = -((rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_n);

    /* MultiPortSwitch: '<S202>/Index Vector1' incorporates:
     *  Gain: '<S202>/Gain2'
     *  Gain: '<S204>/Gain1'
     *  Product: '<S204>/Product'
     *  Product: '<S204>/Product2'
     *  Sum: '<S204>/Add1'
     */
    rtb_Gain_a = rtDW.Add4 * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S105>/XYZ Caculate' */
    break;

   case 4:
    /* Outputs for Atomic SubSystem: '<S105>/XYZ Caculate' */
    rtb_IndexVector_c = -(rtDW.Add4 * rtb_Add1_n);

    /* MultiPortSwitch: '<S202>/Index Vector1' incorporates:
     *  Gain: '<S202>/Gain'
     *  Gain: '<S204>/Gain1'
     *  Product: '<S204>/Product'
     *  Product: '<S204>/Product2'
     *  Sum: '<S204>/Add1'
     */
    rtb_Gain_a = (rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S105>/XYZ Caculate' */
    break;

   case 5:
    /* Outputs for Atomic SubSystem: '<S105>/XYZ Caculate' */
    rtb_IndexVector_c = rtDW.Add4 * rtb_Add1_n;

    /* MultiPortSwitch: '<S202>/Index Vector1' incorporates:
     *  Gain: '<S202>/Gain1'
     *  Gain: '<S204>/Gain2'
     *  Product: '<S204>/Product'
     *  Product: '<S204>/Product1'
     *  Sum: '<S204>/Add2'
     */
    rtb_Gain_a = -(((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_n);

    /* End of Outputs for SubSystem: '<S105>/XYZ Caculate' */
    break;

   default:
    /* Outputs for Atomic SubSystem: '<S105>/XYZ Caculate' */
    rtb_IndexVector_c = -(((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_n);

    /* MultiPortSwitch: '<S202>/Index Vector1' incorporates:
     *  Gain: '<S202>/Gain1'
     *  Gain: '<S202>/Gain2'
     *  Gain: '<S204>/Gain1'
     *  Gain: '<S204>/Gain2'
     *  Product: '<S204>/Product1'
     *  Product: '<S204>/Product2'
     *  Sum: '<S204>/Add1'
     *  Sum: '<S204>/Add2'
     */
    rtb_Gain_a = -((rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_n);

    /* End of Outputs for SubSystem: '<S105>/XYZ Caculate' */
    break;
  }

  /* End of MultiPortSwitch: '<S202>/Index Vector' */

  /* Sum: '<S202>/Add' */
  rtb_Add1_n = rtb_IndexVector_c + rtb_Gain_a;

  /* Switch: '<S202>/Switch' incorporates:
   *  Constant: '<S95>/Constant4'
   *  Product: '<S202>/Divide'
   *  Product: '<S202>/Divide1'
   *  Sum: '<S202>/Add1'
   *  Switch: '<S202>/Switch2'
   */
  if (!(0.0001F - rtb_Add1_n > 0.0F)) {
    rtb_IndexVector_c = rtb_IndexVector_c * 0.0001F / rtb_Add1_n;
    rtb_Gain_a *= 1.0F / rtb_Add1_n * 0.0001F;
  }

  /* End of Switch: '<S202>/Switch' */
  /* End of Outputs for SubSystem: '<S105>/T1 T2  Caculate' */

  /* Outputs for Atomic SubSystem: '<S105>/Tcm calculate' */
  /* Gain: '<S203>/Gain2' incorporates:
   *  Constant: '<S95>/Constant4'
   *  Sum: '<S203>/Add'
   */
  rtb_Add1_n = ((0.0001F - rtb_IndexVector_c) - rtb_Gain_a) * 0.25F;

  /* Sum: '<S203>/Add1' incorporates:
   *  Gain: '<S203>/Gain'
   */
  rtb_IndexVector_c = 0.5F * rtb_IndexVector_c + rtb_Add1_n;

  /* MultiPortSwitch: '<S203>/Index Vector' incorporates:
   *  Gain: '<S203>/Gain1'
   *  Sum: '<S203>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S203>/Index Vector1' */
    rtb_IndexVector1 = rtb_Add1_n;

    /* MultiPortSwitch: '<S203>/Index Vector2' incorporates:
     *  Gain: '<S203>/Gain1'
     *  Sum: '<S203>/Add2'
     */
    rtb_Add1_n = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 2:
    rtb_Saturation = rtb_Add1_n;

    /* MultiPortSwitch: '<S203>/Index Vector1' incorporates:
     *  Gain: '<S203>/Gain1'
     *  Sum: '<S203>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S203>/Index Vector2' */
    rtb_Add1_n = rtb_IndexVector_c;
    break;

   case 3:
    rtb_Saturation = rtb_Add1_n;

    /* MultiPortSwitch: '<S203>/Index Vector1' */
    rtb_IndexVector1 = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S203>/Index Vector2' incorporates:
     *  Gain: '<S203>/Gain1'
     *  Sum: '<S203>/Add2'
     */
    rtb_Add1_n = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 4:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S203>/Index Vector1' incorporates:
     *  Gain: '<S203>/Gain1'
     *  Sum: '<S203>/Add2'
     */
    rtb_IndexVector1 = rtb_IndexVector_c;
    break;

   case 5:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S203>/Index Vector1' incorporates:
     *  Gain: '<S203>/Gain1'
     *  Sum: '<S203>/Add2'
     */
    rtb_IndexVector1 = rtb_Add1_n;

    /* MultiPortSwitch: '<S203>/Index Vector2' */
    rtb_Add1_n = rtb_IndexVector_c;
    break;

   default:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S203>/Index Vector1' incorporates:
     *  Gain: '<S203>/Gain1'
     *  Sum: '<S203>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;
  }

  /* End of MultiPortSwitch: '<S203>/Index Vector' */
  /* End of Outputs for SubSystem: '<S105>/Tcm calculate' */

  /* If: '<S105>/If1' */
  if (rtDW.Merge1_a == 0) {
    /* Outputs for IfAction SubSystem: '<S105>/Enable_Motor' incorporates:
     *  ActionPort: '<S200>/Action Port'
     */
    /* Merge: '<S105>/Merge' incorporates:
     *  Gain: '<S105>/Gain'
     *  Inport: '<S200>/In1'
     */
    rtDW.Merge_c4 = 8.399E+7F * rtb_Saturation;

    /* Merge: '<S105>/Merge1' incorporates:
     *  Gain: '<S105>/Gain2'
     *  Inport: '<S200>/In2'
     */
    rtDW.Merge1_h = 8.399E+7F * rtb_IndexVector1;

    /* Merge: '<S105>/Merge2' incorporates:
     *  Gain: '<S105>/Gain3'
     *  Inport: '<S200>/In3'
     */
    rtDW.Merge2_d = 8.399E+7F * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S105>/Enable_Motor' */
  } else {
    if (rtDW.Merge1_a == 1) {
      /* Outputs for IfAction SubSystem: '<S105>/Disable_Motor' incorporates:
       *  ActionPort: '<S199>/Action Port'
       */
      /* Merge: '<S105>/Merge' incorporates:
       *  Constant: '<S199>/Constant'
       *  SignalConversion generated from: '<S199>/Out1'
       */
      rtDW.Merge_c4 = 0.0F;

      /* Merge: '<S105>/Merge1' incorporates:
       *  Constant: '<S199>/Constant1'
       *  SignalConversion generated from: '<S199>/Out2'
       */
      rtDW.Merge1_h = 0.0F;

      /* Merge: '<S105>/Merge2' incorporates:
       *  Constant: '<S199>/Constant2'
       *  SignalConversion generated from: '<S199>/Out3'
       */
      rtDW.Merge2_d = 0.0F;

      /* End of Outputs for SubSystem: '<S105>/Disable_Motor' */
    }
  }

  /* End of If: '<S105>/If1' */
}

/* Output and update for atomic system: '<S95>/Sine_Cosine' */
void Sine_Cosine_m(void)
{
  real32_T rtb_Saturation;
  uint32_T Add4_tmp;

  /* Saturate: '<S106>/Saturation' */
  if (rtDW.Merge_g > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Merge_g < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Merge_g;
  }

  /* End of Saturate: '<S106>/Saturation' */

  /* Lookup_n-D: '<S106>/Cosine' incorporates:
   *  Lookup_n-D: '<S106>/Sine'
   *  Saturate: '<S106>/Saturation'
   */
  Add4_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);
  rtDW.Add4 = rtConstP.pooled29[Add4_tmp];

  /* Lookup_n-D: '<S106>/Sine' */
  rtDW.Add3 = rtConstP.pooled31[Add4_tmp];
}

/* Output and update for atomic system: '<S5>/FOC' */
void FOC(void)
{
  /* If: '<S95>/If1' incorporates:
   *  Constant: '<S95>/Flux_Enable'
   *  Inport: '<S100>/Hall_Angle'
   *  Inport: '<S102>/Obs_Angle'
   *  UnitDelay: '<S95>/Unit Delay2'
   */
  if (Flux_Parameter.Flux_Theta_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S95>/Obs_Angle' incorporates:
     *  ActionPort: '<S102>/Action Port'
     */
    rtDW.Merge_g = rtDW.UnitDelay;

    /* End of Outputs for SubSystem: '<S95>/Obs_Angle' */
  } else {
    if (Flux_Parameter.Flux_Theta_Enable == 0) {
      /* Outputs for IfAction SubSystem: '<S95>/Hall_Angle' incorporates:
       *  ActionPort: '<S100>/Action Port'
       */
      rtDW.Merge_g = Hall_Angle;

      /* End of Outputs for SubSystem: '<S95>/Hall_Angle' */
    }
  }

  /* End of If: '<S95>/If1' */

  /* Constant: '<S95>/Constant3' */
  rtDW.Constant3 = Dead_Com_Enable;

  /* Outputs for Atomic SubSystem: '<S95>/Clarke_Transform' */
  Clarke_Transform();

  /* End of Outputs for SubSystem: '<S95>/Clarke_Transform' */

  /* Outputs for Atomic SubSystem: '<S95>/Sine_Cosine' */
  Sine_Cosine_m();

  /* End of Outputs for SubSystem: '<S95>/Sine_Cosine' */

  /* Outputs for Atomic SubSystem: '<S95>/Park_Transform' */
  Park_Transform();

  /* End of Outputs for SubSystem: '<S95>/Park_Transform' */

  /* Outputs for Atomic SubSystem: '<S95>/DT_Compensation' */
  DT_Compensation();

  /* End of Outputs for SubSystem: '<S95>/DT_Compensation' */

  /* Outputs for Atomic SubSystem: '<S95>/D_Current_PI' */
  D_Current_PI();

  /* End of Outputs for SubSystem: '<S95>/D_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S95>/Q_Current_PI' */
  Q_Current_PI();

  /* End of Outputs for SubSystem: '<S95>/Q_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S95>/Inverse_Park_Transform' */
  Inverse_Park_Transform();

  /* End of Outputs for SubSystem: '<S95>/Inverse_Park_Transform' */

  /* Sum: '<S95>/Add3' */
  rtDW.Add3 = rtDW.Fcn + V_alpha;

  /* Sum: '<S95>/Add4' */
  rtDW.Add4 = rtDW.Fcn1 + V_beta;

  /* Outputs for Enabled SubSystem: '<S99>/Flux_observer' incorporates:
   *  EnablePort: '<S133>/Enable'
   */
  rtDW.Flux_observer_MODE = false;

  /* End of Outputs for SubSystem: '<S99>/Flux_observer' */

  /* Outputs for Atomic SubSystem: '<S95>/SVPWM' */
  SVPWM();

  /* End of Outputs for SubSystem: '<S95>/SVPWM' */
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
