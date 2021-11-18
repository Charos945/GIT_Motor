/*
 * File: FOC_Control_100us.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Nov 16 10:26:25 2021
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

/* Output and update for atomic system: '<S40>/Clarke_Transform' */
void Clarke_Transform(void)
{
  /* Outputs for Atomic SubSystem: '<S41>/Clark1' */
  /* Gain: '<S51>/Gain2' incorporates:
   *  Gain: '<S51>/Gain'
   *  Gain: '<S51>/Gain1'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S51>/Add'
   */
  Ialpha = ((rtU.Phase_CurrentABC[0] - 0.5F * rtU.Phase_CurrentABC[1]) - 0.5F *
            rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* Gain: '<S51>/Gain5' incorporates:
   *  Gain: '<S51>/Gain3'
   *  Gain: '<S51>/Gain4'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S51>/Add1'
   */
  Ibeta = (0.866025388F * rtU.Phase_CurrentABC[1] - 0.866025388F *
           rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* End of Outputs for SubSystem: '<S41>/Clark1' */
}

/*
 * Output and update for action system:
 *    '<S52>/Over_M'
 *    '<S118>/Over_M'
 */
void Over_M(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S54>/Gain' */
  *rty_Out1 = 0.666666687F * rtu_Bus_voltage;

  /* Gain: '<S54>/Gain1' */
  *rty_Out2 = -0.666666687F * rtu_Bus_voltage;
}

/*
 * Output and update for action system:
 *    '<S52>/Normal'
 *    '<S118>/Normal'
 */
void Normal(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S53>/Gain' */
  *rty_Out1 = 0.577350259F * rtu_Bus_voltage;

  /* Gain: '<S53>/Gain1' */
  *rty_Out2 = -0.577350259F * rtu_Bus_voltage;
}

/* Output and update for atomic system: '<S40>/D_Current_PI' */
void D_Current_PI(void)
{
  real32_T Merge1_b;
  real32_T Merge_a;
  real32_T rtb_Add;
  real32_T rtb_Switch_h;

  /* Sum: '<S42>/Add2' */
  rtb_Switch_h = Id_ref - Id_measured;

  /* DiscreteIntegrator: '<S52>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_pb !=
       0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_a = 0.0F;
  }

  /* Sum: '<S52>/Add' incorporates:
   *  Constant: '<S52>/Kp'
   *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator'
   *  Product: '<S52>/Product'
   */
  rtb_Add = PI_Parameter.ID_Kp * rtb_Switch_h +
    rtDW.DiscreteTimeIntegrator_DSTATE_a;

  /* If: '<S52>/If1' incorporates:
   *  Constant: '<S52>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S52>/Over_M' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S52>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S52>/Normal' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S52>/Normal' */
  }

  /* End of If: '<S52>/If1' */

  /* Switch: '<S55>/Switch2' incorporates:
   *  RelationalOperator: '<S55>/LowerRelop1'
   *  RelationalOperator: '<S55>/UpperRelop'
   *  Switch: '<S55>/Switch'
   */
  if (rtb_Add > Merge_a) {
    /* Switch: '<S55>/Switch2' */
    Vd_voltage = Merge_a;
  } else if (rtb_Add < Merge1_b) {
    /* Switch: '<S55>/Switch' incorporates:
     *  Switch: '<S55>/Switch2'
     */
    Vd_voltage = Merge1_b;
  } else {
    /* Switch: '<S55>/Switch2' incorporates:
     *  Switch: '<S55>/Switch'
     */
    Vd_voltage = rtb_Add;
  }

  /* End of Switch: '<S55>/Switch2' */

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Cons'
   *  UnitDelay: '<S52>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_k) {
    rtb_Switch_h = 0.0F;
  }

  /* End of Switch: '<S52>/Switch' */

  /* Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S52>/Ki'
   *  Product: '<S52>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += PI_Parameter.ID_Ki * rtb_Switch_h *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_pb = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S52>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S52>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_k = (rtb_Add == Vd_voltage);
}

/* Output and update for atomic system: '<S58>/Sine_Cosine' */
void Sine_Cosine(void)
{
  real32_T rtb_Saturation;
  uint32_T Cosine_tmp;

  /* Saturate: '<S62>/Saturation' */
  if (rtDW.UnitDelay > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.UnitDelay < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.UnitDelay;
  }

  /* End of Saturate: '<S62>/Saturation' */

  /* Lookup_n-D: '<S62>/Cosine' incorporates:
   *  Lookup_n-D: '<S62>/Sine'
   *  Saturate: '<S62>/Saturation'
   */
  Cosine_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);

  /* Lookup_n-D: '<S62>/Cosine' */
  rtDW.Cosine = rtConstP.pooled7[Cosine_tmp];

  /* Sum: '<S57>/Add1' incorporates:
   *  Lookup_n-D: '<S62>/Sine'
   */
  rtDW.Add1 = rtConstP.pooled9[Cosine_tmp];
}

/* Output and update for atomic system: '<S40>/Inverse_Park_Transform' */
void Inverse_Park_Transform(void)
{
  /* Sum: '<S45>/Add' incorporates:
   *  Product: '<S45>/Product1'
   *  Product: '<S45>/Product2'
   *  Sum: '<S45>/Add1'
   */
  V_alpha = Vd_voltage * rtDW.Add1 - Vq_voltage * rtDW.Cosine;

  /* Sum: '<S45>/Add3' incorporates:
   *  Product: '<S45>/Product3'
   *  Product: '<S45>/Product4'
   *  Sum: '<S45>/Add2'
   */
  V_beta = Vd_voltage * rtDW.Cosine + Vq_voltage * rtDW.Add1;
}

/* Output and update for atomic system: '<S40>/Park_Transform' */
void Park_Transform(void)
{
  /* Sum: '<S47>/Add1' incorporates:
   *  Product: '<S47>/Product1'
   *  Product: '<S47>/Product2'
   */
  Id_measured = Ialpha * rtDW.Add1 + Ibeta * rtDW.Cosine;

  /* Sum: '<S47>/Add2' incorporates:
   *  Product: '<S47>/Produc3t'
   *  Product: '<S47>/Product4'
   */
  Iq_measured = Ibeta * rtDW.Add1 - Ialpha * rtDW.Cosine;
}

/* Output and update for atomic system: '<S40>/Q_Current_PI' */
void Q_Current_PI(void)
{
  real32_T Merge1_d;
  real32_T Merge_h;
  real32_T rtb_Add;
  real32_T rtb_Switch_k;

  /* Sum: '<S48>/Add2' */
  rtb_Switch_k = Iq_ref - Iq_measured;

  /* DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_p != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE_i = 0.0F;
  }

  /* Sum: '<S118>/Add' incorporates:
   *  Constant: '<S118>/Kp'
   *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator'
   *  Product: '<S118>/Product'
   */
  rtb_Add = PI_Parameter.IQ_Kp * rtb_Switch_k +
    rtDW.DiscreteTimeIntegrator_DSTATE_i;

  /* If: '<S118>/If1' incorporates:
   *  Constant: '<S118>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S118>/Over_M' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_h, &Merge1_d);

    /* End of Outputs for SubSystem: '<S118>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S118>/Normal' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_h, &Merge1_d);

    /* End of Outputs for SubSystem: '<S118>/Normal' */
  }

  /* End of If: '<S118>/If1' */

  /* Switch: '<S121>/Switch2' incorporates:
   *  RelationalOperator: '<S121>/LowerRelop1'
   *  RelationalOperator: '<S121>/UpperRelop'
   *  Switch: '<S121>/Switch'
   */
  if (rtb_Add > Merge_h) {
    Vq_voltage = Merge_h;
  } else if (rtb_Add < Merge1_d) {
    /* Switch: '<S121>/Switch' */
    Vq_voltage = Merge1_d;
  } else {
    Vq_voltage = rtb_Add;
  }

  /* End of Switch: '<S121>/Switch2' */

  /* Switch: '<S118>/Switch' incorporates:
   *  Constant: '<S118>/Cons'
   *  UnitDelay: '<S118>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_i) {
    rtb_Switch_k = 0.0F;
  }

  /* End of Switch: '<S118>/Switch' */

  /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S118>/Ki'
   *  Product: '<S118>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_i += PI_Parameter.IQ_Ki * rtb_Switch_k *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_p = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S118>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S118>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_i = (rtb_Add == Vq_voltage);
}

/* Output and update for atomic system: '<S40>/SVPWM' */
void SVPWM(void)
{
  real32_T rtb_Add1_fq;
  real32_T rtb_Gain_a;
  real32_T rtb_IndexVector1;
  real32_T rtb_IndexVector_c;
  real32_T rtb_Saturation;

  /* Outputs for Atomic SubSystem: '<S49>/XYZ Caculate' */
  /* Outputs for Atomic SubSystem: '<S49>/N Sector  Caculate' */
  /* Gain: '<S124>/Gain' incorporates:
   *  Gain: '<S127>/Gain'
   */
  rtb_IndexVector1 = 1.73205078F * V_alpha;

  /* End of Outputs for SubSystem: '<S49>/XYZ Caculate' */

  /* Saturate: '<S124>/Saturation' incorporates:
   *  Gain: '<S124>/Gain'
   *  Gain: '<S124>/Gain1'
   *  Gain: '<S124>/Gain2'
   *  Sum: '<S124>/Add'
   *  Sum: '<S124>/Add1'
   *  Sum: '<S124>/Add2'
   *  Switch: '<S124>/Switch'
   *  Switch: '<S124>/Switch1'
   *  Switch: '<S124>/Switch2'
   */
  rtb_Saturation = (real32_T)((((rtb_IndexVector1 - V_beta >= 0.0F) << 1) +
    (V_beta >= 0.0F)) + (((0.0F - V_beta) - rtb_IndexVector1 >= 0.0F) << 2));
  if (rtb_Saturation > 6.0F) {
    rtb_Saturation = 6.0F;
  } else {
    if (rtb_Saturation < 1.0F) {
      rtb_Saturation = 1.0F;
    }
  }

  /* End of Saturate: '<S124>/Saturation' */
  /* End of Outputs for SubSystem: '<S49>/N Sector  Caculate' */

  /* Outputs for Atomic SubSystem: '<S49>/XYZ Caculate' */
  /* Saturate: '<S127>/Saturation' incorporates:
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (rtU.Bus_Voltage > 1200.0F) {
    rtb_Add1_fq = 1200.0F;
  } else if (rtU.Bus_Voltage < 0.0001F) {
    rtb_Add1_fq = 0.0001F;
  } else {
    rtb_Add1_fq = rtU.Bus_Voltage;
  }

  /* End of Saturate: '<S127>/Saturation' */

  /* Product: '<S127>/Divide' incorporates:
   *  Constant: '<S127>/Constant'
   *  Constant: '<S40>/Constant4'
   */
  rtb_Add1_fq = 0.000173205073F / rtb_Add1_fq;

  /* End of Outputs for SubSystem: '<S49>/XYZ Caculate' */

  /* Outputs for Atomic SubSystem: '<S49>/T1 T2  Caculate' */
  /* MultiPortSwitch: '<S125>/Index Vector' incorporates:
   *  Gain: '<S125>/Gain'
   *  Gain: '<S125>/Gain1'
   *  Gain: '<S125>/Gain2'
   *  Gain: '<S127>/Gain1'
   *  Gain: '<S127>/Gain2'
   *  Product: '<S127>/Product'
   *  Product: '<S127>/Product1'
   *  Product: '<S127>/Product2'
   *  Sum: '<S127>/Add1'
   *  Sum: '<S127>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    /* Outputs for Atomic SubSystem: '<S49>/XYZ Caculate' */
    rtb_IndexVector_c = (rtb_IndexVector1 - V_beta) * -0.5F * rtb_Add1_fq;

    /* MultiPortSwitch: '<S125>/Index Vector1' incorporates:
     *  Gain: '<S127>/Gain1'
     *  Gain: '<S127>/Gain2'
     *  Product: '<S127>/Product1'
     *  Product: '<S127>/Product2'
     *  Sum: '<S127>/Add1'
     *  Sum: '<S127>/Add2'
     */
    rtb_Gain_a = ((0.0F - V_beta) - rtb_IndexVector1) * -0.5F * rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S49>/XYZ Caculate' */
    break;

   case 2:
    /* Outputs for Atomic SubSystem: '<S49>/XYZ Caculate' */
    rtb_IndexVector_c = ((0.0F - V_beta) - rtb_IndexVector1) * -0.5F *
      rtb_Add1_fq;

    /* MultiPortSwitch: '<S125>/Index Vector1' incorporates:
     *  Gain: '<S125>/Gain'
     *  Gain: '<S127>/Gain2'
     *  Product: '<S127>/Product'
     *  Product: '<S127>/Product1'
     *  Sum: '<S127>/Add2'
     */
    rtb_Gain_a = -(V_beta * rtb_Add1_fq);

    /* End of Outputs for SubSystem: '<S49>/XYZ Caculate' */
    break;

   case 3:
    /* Outputs for Atomic SubSystem: '<S49>/XYZ Caculate' */
    rtb_IndexVector_c = -((rtb_IndexVector1 - V_beta) * -0.5F * rtb_Add1_fq);

    /* MultiPortSwitch: '<S125>/Index Vector1' incorporates:
     *  Gain: '<S125>/Gain2'
     *  Gain: '<S127>/Gain1'
     *  Product: '<S127>/Product'
     *  Product: '<S127>/Product2'
     *  Sum: '<S127>/Add1'
     */
    rtb_Gain_a = V_beta * rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S49>/XYZ Caculate' */
    break;

   case 4:
    /* Outputs for Atomic SubSystem: '<S49>/XYZ Caculate' */
    rtb_IndexVector_c = -(V_beta * rtb_Add1_fq);

    /* MultiPortSwitch: '<S125>/Index Vector1' incorporates:
     *  Gain: '<S125>/Gain'
     *  Gain: '<S127>/Gain1'
     *  Product: '<S127>/Product'
     *  Product: '<S127>/Product2'
     *  Sum: '<S127>/Add1'
     */
    rtb_Gain_a = (rtb_IndexVector1 - V_beta) * -0.5F * rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S49>/XYZ Caculate' */
    break;

   case 5:
    /* Outputs for Atomic SubSystem: '<S49>/XYZ Caculate' */
    rtb_IndexVector_c = V_beta * rtb_Add1_fq;

    /* MultiPortSwitch: '<S125>/Index Vector1' incorporates:
     *  Gain: '<S125>/Gain1'
     *  Gain: '<S127>/Gain2'
     *  Product: '<S127>/Product'
     *  Product: '<S127>/Product1'
     *  Sum: '<S127>/Add2'
     */
    rtb_Gain_a = -(((0.0F - V_beta) - rtb_IndexVector1) * -0.5F * rtb_Add1_fq);

    /* End of Outputs for SubSystem: '<S49>/XYZ Caculate' */
    break;

   default:
    /* Outputs for Atomic SubSystem: '<S49>/XYZ Caculate' */
    rtb_IndexVector_c = -(((0.0F - V_beta) - rtb_IndexVector1) * -0.5F *
                          rtb_Add1_fq);

    /* MultiPortSwitch: '<S125>/Index Vector1' incorporates:
     *  Gain: '<S125>/Gain1'
     *  Gain: '<S125>/Gain2'
     *  Gain: '<S127>/Gain1'
     *  Gain: '<S127>/Gain2'
     *  Product: '<S127>/Product1'
     *  Product: '<S127>/Product2'
     *  Sum: '<S127>/Add1'
     *  Sum: '<S127>/Add2'
     */
    rtb_Gain_a = -((rtb_IndexVector1 - V_beta) * -0.5F * rtb_Add1_fq);

    /* End of Outputs for SubSystem: '<S49>/XYZ Caculate' */
    break;
  }

  /* End of MultiPortSwitch: '<S125>/Index Vector' */

  /* Sum: '<S125>/Add' */
  rtb_Add1_fq = rtb_IndexVector_c + rtb_Gain_a;

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S40>/Constant4'
   *  Product: '<S125>/Divide'
   *  Product: '<S125>/Divide1'
   *  Sum: '<S125>/Add1'
   *  Switch: '<S125>/Switch2'
   */
  if (!(0.0001F - rtb_Add1_fq > 0.0F)) {
    rtb_IndexVector_c = rtb_IndexVector_c * 0.0001F / rtb_Add1_fq;
    rtb_Gain_a *= 1.0F / rtb_Add1_fq * 0.0001F;
  }

  /* End of Switch: '<S125>/Switch' */
  /* End of Outputs for SubSystem: '<S49>/T1 T2  Caculate' */

  /* Outputs for Atomic SubSystem: '<S49>/Tcm calculate' */
  /* Gain: '<S126>/Gain2' incorporates:
   *  Constant: '<S40>/Constant4'
   *  Sum: '<S126>/Add'
   */
  rtb_Add1_fq = ((0.0001F - rtb_IndexVector_c) - rtb_Gain_a) * 0.25F;

  /* Sum: '<S126>/Add1' incorporates:
   *  Gain: '<S126>/Gain'
   */
  rtb_IndexVector_c = 0.5F * rtb_IndexVector_c + rtb_Add1_fq;

  /* MultiPortSwitch: '<S126>/Index Vector' incorporates:
   *  Gain: '<S126>/Gain1'
   *  Sum: '<S126>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S126>/Index Vector1' */
    rtb_IndexVector1 = rtb_Add1_fq;

    /* MultiPortSwitch: '<S126>/Index Vector2' incorporates:
     *  Gain: '<S126>/Gain1'
     *  Sum: '<S126>/Add2'
     */
    rtb_Add1_fq = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 2:
    rtb_Saturation = rtb_Add1_fq;

    /* MultiPortSwitch: '<S126>/Index Vector1' incorporates:
     *  Gain: '<S126>/Gain1'
     *  Sum: '<S126>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S126>/Index Vector2' */
    rtb_Add1_fq = rtb_IndexVector_c;
    break;

   case 3:
    rtb_Saturation = rtb_Add1_fq;

    /* MultiPortSwitch: '<S126>/Index Vector1' */
    rtb_IndexVector1 = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S126>/Index Vector2' incorporates:
     *  Gain: '<S126>/Gain1'
     *  Sum: '<S126>/Add2'
     */
    rtb_Add1_fq = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 4:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S126>/Index Vector1' incorporates:
     *  Gain: '<S126>/Gain1'
     *  Sum: '<S126>/Add2'
     */
    rtb_IndexVector1 = rtb_IndexVector_c;
    break;

   case 5:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S126>/Index Vector1' incorporates:
     *  Gain: '<S126>/Gain1'
     *  Sum: '<S126>/Add2'
     */
    rtb_IndexVector1 = rtb_Add1_fq;

    /* MultiPortSwitch: '<S126>/Index Vector2' */
    rtb_Add1_fq = rtb_IndexVector_c;
    break;

   default:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S126>/Index Vector1' incorporates:
     *  Gain: '<S126>/Gain1'
     *  Sum: '<S126>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;
  }

  /* End of MultiPortSwitch: '<S126>/Index Vector' */
  /* End of Outputs for SubSystem: '<S49>/Tcm calculate' */

  /* If: '<S49>/If1' */
  if (rtDW.Merge1_a == 0) {
    /* Gain: '<S49>/Gain' */
    rtb_Saturation *= 8.399E+7F;

    /* Outputs for IfAction SubSystem: '<S49>/Enable_Motor' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    /* Saturate: '<S123>/Saturation' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S49>/Merge' */
      rtDW.Merge_c4 = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S49>/Merge' */
      rtDW.Merge_c4 = 1.0F;
    } else {
      /* Merge: '<S49>/Merge' */
      rtDW.Merge_c4 = rtb_Saturation;
    }

    /* End of Saturate: '<S123>/Saturation' */
    /* End of Outputs for SubSystem: '<S49>/Enable_Motor' */

    /* Gain: '<S49>/Gain2' */
    rtb_Saturation = 8.399E+7F * rtb_IndexVector1;

    /* Outputs for IfAction SubSystem: '<S49>/Enable_Motor' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    /* Saturate: '<S123>/Saturation1' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S49>/Merge1' */
      rtDW.Merge1 = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S49>/Merge1' */
      rtDW.Merge1 = 1.0F;
    } else {
      /* Merge: '<S49>/Merge1' */
      rtDW.Merge1 = rtb_Saturation;
    }

    /* End of Saturate: '<S123>/Saturation1' */
    /* End of Outputs for SubSystem: '<S49>/Enable_Motor' */

    /* Gain: '<S49>/Gain3' */
    rtb_Saturation = 8.399E+7F * rtb_Add1_fq;

    /* Outputs for IfAction SubSystem: '<S49>/Enable_Motor' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    /* Saturate: '<S123>/Saturation2' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S49>/Merge2' */
      rtDW.Merge2_d = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S49>/Merge2' */
      rtDW.Merge2_d = 1.0F;
    } else {
      /* Merge: '<S49>/Merge2' */
      rtDW.Merge2_d = rtb_Saturation;
    }

    /* End of Saturate: '<S123>/Saturation2' */
    /* End of Outputs for SubSystem: '<S49>/Enable_Motor' */
  } else {
    if (rtDW.Merge1_a == 1) {
      /* Outputs for IfAction SubSystem: '<S49>/Disable_Motor' incorporates:
       *  ActionPort: '<S122>/Action Port'
       */
      /* Merge: '<S49>/Merge' incorporates:
       *  Constant: '<S122>/Constant'
       *  SignalConversion generated from: '<S122>/Out1'
       */
      rtDW.Merge_c4 = 0.0F;

      /* Merge: '<S49>/Merge1' incorporates:
       *  Constant: '<S122>/Constant1'
       *  SignalConversion generated from: '<S122>/Out2'
       */
      rtDW.Merge1 = 0.0F;

      /* Merge: '<S49>/Merge2' incorporates:
       *  Constant: '<S122>/Constant2'
       *  SignalConversion generated from: '<S122>/Out3'
       */
      rtDW.Merge2_d = 0.0F;

      /* End of Outputs for SubSystem: '<S49>/Disable_Motor' */
    }
  }

  /* End of If: '<S49>/If1' */
}

/* Output and update for atomic system: '<S40>/Sine_Cosine' */
void Sine_Cosine_m(void)
{
  real32_T rtb_Saturation;
  uint32_T Add1_tmp;

  /* Saturate: '<S50>/Saturation' */
  if (rtDW.Merge_g > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Merge_g < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Merge_g;
  }

  /* End of Saturate: '<S50>/Saturation' */

  /* Lookup_n-D: '<S50>/Cosine' incorporates:
   *  Lookup_n-D: '<S50>/Sine'
   *  Saturate: '<S50>/Saturation'
   */
  Add1_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);
  rtDW.Add1 = rtConstP.pooled7[Add1_tmp];

  /* Lookup_n-D: '<S50>/Sine' */
  rtDW.Cosine = rtConstP.pooled9[Add1_tmp];
}

/* Output and update for atomic system: '<S5>/FOC' */
void FOC(void)
{
  real32_T rtb_Add4;
  real32_T rtb_Add5;
  real32_T rtb_Gain1_g;
  real32_T rtb_Gain_c3;
  real32_T rtb_Integrator;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_Sum;
  real32_T rtb_UnitDelay;
  boolean_T rtb_NotEqual;

  /* Outputs for Atomic SubSystem: '<S40>/Clarke_Transform' */
  Clarke_Transform();

  /* End of Outputs for SubSystem: '<S40>/Clarke_Transform' */

  /* If: '<S40>/If1' incorporates:
   *  Constant: '<S40>/Flux_Enable'
   *  Inport: '<S44>/Hall_Angle'
   *  Inport: '<S46>/Obs_Angle'
   *  UnitDelay: '<S40>/Unit Delay2'
   */
  if (Flux_Parameter.Flux_Theta_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S40>/Obs_Angle' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    rtDW.Merge_g = rtDW.UnitDelay;

    /* End of Outputs for SubSystem: '<S40>/Obs_Angle' */
  } else {
    if (Flux_Parameter.Flux_Theta_Enable == 0) {
      /* Outputs for IfAction SubSystem: '<S40>/Hall_Angle' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      rtDW.Merge_g = Hall_Angle;

      /* End of Outputs for SubSystem: '<S40>/Hall_Angle' */
    }
  }

  /* End of If: '<S40>/If1' */

  /* Outputs for Atomic SubSystem: '<S40>/Sine_Cosine' */
  Sine_Cosine_m();

  /* End of Outputs for SubSystem: '<S40>/Sine_Cosine' */

  /* Outputs for Atomic SubSystem: '<S40>/Park_Transform' */
  Park_Transform();

  /* End of Outputs for SubSystem: '<S40>/Park_Transform' */

  /* Outputs for Atomic SubSystem: '<S40>/D_Current_PI' */
  D_Current_PI();

  /* End of Outputs for SubSystem: '<S40>/D_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S40>/Q_Current_PI' */
  Q_Current_PI();

  /* End of Outputs for SubSystem: '<S40>/Q_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S40>/Inverse_Park_Transform' */
  Inverse_Park_Transform();

  /* End of Outputs for SubSystem: '<S40>/Inverse_Park_Transform' */

  /* Gain: '<S43>/Gain' */
  rtb_SignPreIntegrator = Flux_Parameter.Flux_Gain * Ialpha;

  /* Sum: '<S59>/Add4' incorporates:
   *  Gain: '<S43>/Gain2'
   *  Gain: '<S59>/Gain4'
   */
  rtb_Add4 = Flux_Parameter.Flux_Gain * V_alpha - 0.4F * rtb_SignPreIntegrator;

  /* Sum: '<S60>/Sum' incorporates:
   *  DiscreteIntegrator: '<S60>/Integrator'
   *  Gain: '<S60>/Gain2'
   */
  rtb_SignPreIntegrator = rtDW.Integrator_DSTATE - 0.0041F *
    rtb_SignPreIntegrator;

  /* Gain: '<S43>/Gain1' */
  rtb_Sum = Flux_Parameter.Flux_Gain * Ibeta;

  /* Sum: '<S60>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S60>/Integrator1'
   *  Gain: '<S60>/Gain3'
   */
  rtb_Integrator = rtDW.Integrator1_DSTATE - 0.0041F * rtb_Sum;

  /* Sum: '<S60>/Add2' incorporates:
   *  Math: '<S60>/Math Function'
   *  Math: '<S60>/Math Function1'
   *
   * About '<S60>/Math Function':
   *  Operator: magnitude^2
   *
   * About '<S60>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_UnitDelay = (0.000680229045F - rtb_SignPreIntegrator *
                   rtb_SignPreIntegrator) - rtb_Integrator * rtb_Integrator;

  /* Gain: '<S60>/Gain' incorporates:
   *  Product: '<S60>/Product'
   */
  rtb_Gain_c3 = rtb_UnitDelay * rtb_SignPreIntegrator * Flux_Parameter.Gamma;

  /* Gain: '<S60>/Gain1' incorporates:
   *  Product: '<S60>/Product1'
   */
  rtb_Gain1_g = rtb_UnitDelay * rtb_Integrator * Flux_Parameter.Gamma;

  /* Sum: '<S59>/Add5' incorporates:
   *  Gain: '<S43>/Gain3'
   *  Gain: '<S59>/Gain5'
   */
  rtb_Add5 = Flux_Parameter.Flux_Gain * V_beta - 0.4F * rtb_Sum;

  /* UnitDelay: '<S63>/Unit Delay' */
  rtDW.UnitDelay = rtDW.UnitDelay_DSTATE_j;

  /* Outputs for Atomic SubSystem: '<S58>/Sine_Cosine' */
  Sine_Cosine();

  /* End of Outputs for SubSystem: '<S58>/Sine_Cosine' */

  /* Sum: '<S58>/Sum' incorporates:
   *  Product: '<S58>/Product'
   *  Product: '<S58>/Product1'
   */
  rtb_UnitDelay = rtb_Integrator * rtDW.Cosine - rtDW.Add1 *
    rtb_SignPreIntegrator;

  /* Sum: '<S106>/Sum' incorporates:
   *  Constant: '<S58>/Constant'
   *  DiscreteIntegrator: '<S97>/Integrator'
   *  Gain: '<S58>/Gain'
   *  Product: '<S102>/PProd Out'
   */
  rtb_Sum = Flux_Parameter.pll_xi * Flux_Parameter.pll_omega * rtb_UnitDelay +
    rtDW.Integrator_DSTATE_f;

  /* DeadZone: '<S90>/DeadZone' */
  if (rtb_Sum > 523.598755F) {
    rtb_SignPreIntegrator = rtb_Sum - 523.598755F;
  } else if (rtb_Sum >= -523.598755F) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = rtb_Sum - -523.598755F;
  }

  /* End of DeadZone: '<S90>/DeadZone' */

  /* RelationalOperator: '<S88>/NotEqual' incorporates:
   *  Gain: '<S88>/ZeroGain'
   */
  rtb_NotEqual = (0.0F * rtb_Sum != rtb_SignPreIntegrator);

  /* Signum: '<S88>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0F) {
    rtb_SignPreIntegrator = -1.0F;
  } else if (rtb_SignPreIntegrator > 0.0F) {
    rtb_SignPreIntegrator = 1.0F;
  } else if (rtb_SignPreIntegrator == 0.0F) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = (rtNaNF);
  }

  /* End of Signum: '<S88>/SignPreSat' */

  /* Product: '<S94>/IProd Out' incorporates:
   *  Constant: '<S58>/Constant'
   *  Product: '<S58>/Product2'
   */
  rtb_UnitDelay *= Flux_Parameter.pll_omega * Flux_Parameter.pll_omega;

  /* Signum: '<S88>/SignPreIntegrator' */
  if (rtb_UnitDelay < 0.0F) {
    rtb_Integrator = -1.0F;
  } else if (rtb_UnitDelay > 0.0F) {
    rtb_Integrator = 1.0F;
  } else if (rtb_UnitDelay == 0.0F) {
    rtb_Integrator = 0.0F;
  } else {
    rtb_Integrator = (rtNaNF);
  }

  /* End of Signum: '<S88>/SignPreIntegrator' */

  /* Switch: '<S88>/Switch' incorporates:
   *  Constant: '<S88>/Constant1'
   *  DataTypeConversion: '<S88>/DataTypeConv1'
   *  DataTypeConversion: '<S88>/DataTypeConv2'
   *  Logic: '<S88>/AND3'
   *  RelationalOperator: '<S88>/Equal1'
   */
  if (rtb_NotEqual && ((int8_T)rtb_SignPreIntegrator == (int8_T)rtb_Integrator))
  {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = rtb_UnitDelay;
  }

  /* End of Switch: '<S88>/Switch' */

  /* Saturate: '<S104>/Saturation' */
  if (rtb_Sum > 523.598755F) {
    /* Saturate: '<S104>/Saturation' */
    ObserverOmega = 523.598755F;
  } else if (rtb_Sum < -523.598755F) {
    /* Saturate: '<S104>/Saturation' */
    ObserverOmega = -523.598755F;
  } else {
    /* Saturate: '<S104>/Saturation' */
    ObserverOmega = rtb_Sum;
  }

  /* End of Saturate: '<S104>/Saturation' */

  /* UnitDelay: '<S57>/Unit Delay' */
  rtb_UnitDelay = rtDW.UnitDelay_DSTATE_c;

  /* Sum: '<S57>/Add1' incorporates:
   *  Constant: '<S57>/Constant1'
   *  Gain: '<S56>/Gain1'
   *  Product: '<S57>/Divide1'
   *  Sum: '<S57>/Add'
   */
  rtDW.Add1 = (4.77464819F * ObserverOmega - rtb_UnitDelay) * SpeedFilter_Fn +
    rtb_UnitDelay;

  /* Sum: '<S63>/Sum1' incorporates:
   *  Gain: '<S63>/Ts'
   */
  rtb_Sum = 0.0001F * ObserverOmega + rtDW.UnitDelay;

  /* Outputs for Atomic SubSystem: '<S40>/SVPWM' */
  SVPWM();

  /* End of Outputs for SubSystem: '<S40>/SVPWM' */

  /* Update for DiscreteIntegrator: '<S60>/Integrator' incorporates:
   *  Sum: '<S60>/Add'
   */
  rtDW.Integrator_DSTATE += (rtb_Add4 + rtb_Gain_c3) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S60>/Integrator1' incorporates:
   *  Sum: '<S60>/Add1'
   */
  rtDW.Integrator1_DSTATE += (rtb_Add5 + rtb_Gain1_g) * 0.0001F;

  /* If: '<S114>/If' incorporates:
   *  Constant: '<S114>/Constant'
   *  Constant: '<S114>/Constant1'
   *  RelationalOperator: '<S114>/Relational Operator'
   *  RelationalOperator: '<S114>/Relational Operator1'
   */
  if (rtb_Sum > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    /* Update for UnitDelay: '<S63>/Unit Delay' incorporates:
     *  Constant: '<S116>/Constant'
     *  Sum: '<S116>/Sum'
     */
    rtDW.UnitDelay_DSTATE_j = rtb_Sum - 6.28318548F;

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem1' */
  } else if (rtb_Sum < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    /* Update for UnitDelay: '<S63>/Unit Delay' incorporates:
     *  Constant: '<S115>/Constant'
     *  Sum: '<S115>/Sum'
     */
    rtDW.UnitDelay_DSTATE_j = rtb_Sum + 6.28318548F;

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S114>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    /* Update for UnitDelay: '<S63>/Unit Delay' incorporates:
     *  Inport: '<S117>/In1'
     */
    rtDW.UnitDelay_DSTATE_j = rtb_Sum;

    /* End of Outputs for SubSystem: '<S114>/If Action Subsystem2' */
  }

  /* End of If: '<S114>/If' */

  /* Update for DiscreteIntegrator: '<S97>/Integrator' */
  rtDW.Integrator_DSTATE_f += 0.0001F * rtb_SignPreIntegrator;

  /* Update for UnitDelay: '<S57>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_c = rtDW.Add1;
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
