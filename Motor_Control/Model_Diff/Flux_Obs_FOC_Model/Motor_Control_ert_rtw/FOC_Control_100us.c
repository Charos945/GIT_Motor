/*
 * File: FOC_Control_100us.c
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

#include "FOC_Control_100us.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Named constants for Chart: '<S40>/Chart' */
#define IN_CLP                         ((uint8_T)1U)
#define IN_OPL                         ((uint8_T)2U)
#define IN_Standby                     ((uint8_T)3U)

/* Output and update for atomic system: '<S40>/Clarke_Transform' */
void Clarke_Transform(void)
{
  /* Outputs for Atomic SubSystem: '<S42>/Clark1' */
  /* Gain: '<S54>/Gain2' incorporates:
   *  Gain: '<S54>/Gain'
   *  Gain: '<S54>/Gain1'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S54>/Add'
   */
  Ialpha = ((rtU.Phase_CurrentABC[0] - 0.5F * rtU.Phase_CurrentABC[1]) - 0.5F *
            rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* Gain: '<S54>/Gain5' incorporates:
   *  Gain: '<S54>/Gain3'
   *  Gain: '<S54>/Gain4'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S54>/Add1'
   */
  Ibeta = (0.866025388F * rtU.Phase_CurrentABC[1] - 0.866025388F *
           rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* End of Outputs for SubSystem: '<S42>/Clark1' */
}

/*
 * Output and update for action system:
 *    '<S55>/Over_M'
 *    '<S121>/Over_M'
 */
void Over_M(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S57>/Gain' */
  *rty_Out1 = 0.666666687F * rtu_Bus_voltage;

  /* Gain: '<S57>/Gain1' */
  *rty_Out2 = -0.666666687F * rtu_Bus_voltage;
}

/*
 * Output and update for action system:
 *    '<S55>/Normal'
 *    '<S121>/Normal'
 */
void Normal(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S56>/Gain' */
  *rty_Out1 = 0.577350259F * rtu_Bus_voltage;

  /* Gain: '<S56>/Gain1' */
  *rty_Out2 = -0.577350259F * rtu_Bus_voltage;
}

/* Output and update for atomic system: '<S40>/D_Current_PI' */
void D_Current_PI(void)
{
  real32_T Merge1_b;
  real32_T Merge_a;
  real32_T rtb_Add;
  real32_T rtb_Switch_h;

  /* Sum: '<S43>/Add2' */
  rtb_Switch_h = Id_ref - Id_measured;

  /* DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_pb !=
       0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_a = 0.0F;
  }

  /* Sum: '<S55>/Add' incorporates:
   *  Constant: '<S55>/Kp'
   *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator'
   *  Product: '<S55>/Product'
   */
  rtb_Add = PI_Parameter.ID_Kp * rtb_Switch_h +
    rtDW.DiscreteTimeIntegrator_DSTATE_a;

  /* If: '<S55>/If1' incorporates:
   *  Constant: '<S55>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S55>/Over_M' incorporates:
     *  ActionPort: '<S57>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S55>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S55>/Normal' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S55>/Normal' */
  }

  /* End of If: '<S55>/If1' */

  /* Switch: '<S58>/Switch2' incorporates:
   *  RelationalOperator: '<S58>/LowerRelop1'
   *  RelationalOperator: '<S58>/UpperRelop'
   *  Switch: '<S58>/Switch'
   */
  if (rtb_Add > Merge_a) {
    /* Switch: '<S58>/Switch2' */
    Vd_voltage = Merge_a;
  } else if (rtb_Add < Merge1_b) {
    /* Switch: '<S58>/Switch' incorporates:
     *  Switch: '<S58>/Switch2'
     */
    Vd_voltage = Merge1_b;
  } else {
    /* Switch: '<S58>/Switch2' incorporates:
     *  Switch: '<S58>/Switch'
     */
    Vd_voltage = rtb_Add;
  }

  /* End of Switch: '<S58>/Switch2' */

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S55>/Cons'
   *  UnitDelay: '<S55>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_k) {
    rtb_Switch_h = 0.0F;
  }

  /* End of Switch: '<S55>/Switch' */

  /* Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S55>/Ki'
   *  Product: '<S55>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += PI_Parameter.ID_Ki * rtb_Switch_h *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_pb = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S55>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S55>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_k = (rtb_Add == Vd_voltage);
}

/* Output and update for atomic system: '<S61>/Sine_Cosine' */
void Sine_Cosine(void)
{
  real32_T rtb_Saturation;
  uint32_T Sine_tmp;

  /* Saturate: '<S65>/Saturation' */
  if (rtDW.UnitDelay > 6.28218508F) {
    rtb_Saturation = 6.28218508F;
  } else if (rtDW.UnitDelay < 0.001F) {
    rtb_Saturation = 0.001F;
  } else {
    rtb_Saturation = rtDW.UnitDelay;
  }

  /* End of Saturate: '<S65>/Saturation' */

  /* Lookup_n-D: '<S65>/Cosine' incorporates:
   *  Lookup_n-D: '<S65>/Sine'
   *  Saturate: '<S65>/Saturation'
   */
  Sine_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);

  /* Lookup_n-D: '<S52>/Sine' incorporates:
   *  Lookup_n-D: '<S65>/Cosine'
   */
  rtDW.Sine = rtConstP.pooled6[Sine_tmp];

  /* Lookup_n-D: '<S52>/Cosine' incorporates:
   *  Lookup_n-D: '<S65>/Sine'
   */
  rtDW.Cosine = rtConstP.pooled8[Sine_tmp];
}

/* Output and update for atomic system: '<S40>/Inverse_Park_Transform' */
void Inverse_Park_Transform(void)
{
  /* Sum: '<S46>/Add' incorporates:
   *  Product: '<S46>/Product1'
   *  Product: '<S46>/Product2'
   *  Sum: '<S46>/Add1'
   */
  V_alpha = Vd_voltage * rtDW.Cosine - Vq_voltage * rtDW.Sine;

  /* Sum: '<S46>/Add3' incorporates:
   *  Product: '<S46>/Product3'
   *  Product: '<S46>/Product4'
   *  Sum: '<S46>/Add2'
   */
  V_beta = Vd_voltage * rtDW.Sine + Vq_voltage * rtDW.Cosine;
}

/* Output and update for atomic system: '<S40>/Park_Transform' */
void Park_Transform(void)
{
  /* Sum: '<S49>/Add1' incorporates:
   *  Product: '<S49>/Product1'
   *  Product: '<S49>/Product2'
   */
  Id_measured = Ialpha * rtDW.Cosine + Ibeta * rtDW.Sine;

  /* Sum: '<S49>/Add2' incorporates:
   *  Product: '<S49>/Produc3t'
   *  Product: '<S49>/Product4'
   */
  Iq_measured = Ibeta * rtDW.Cosine - Ialpha * rtDW.Sine;
}

/* Output and update for atomic system: '<S40>/Q_Current_PI' */
void Q_Current_PI(void)
{
  real32_T Merge1_d;
  real32_T Merge_h;
  real32_T rtb_Add;
  real32_T rtb_Switch_k;

  /* Sum: '<S50>/Add2' */
  rtb_Switch_k = rtDW.Merge1 - Iq_measured;

  /* DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_p != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE_i = 0.0F;
  }

  /* Sum: '<S121>/Add' incorporates:
   *  Constant: '<S121>/Kp'
   *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator'
   *  Product: '<S121>/Product'
   */
  rtb_Add = PI_Parameter.IQ_Kp * rtb_Switch_k +
    rtDW.DiscreteTimeIntegrator_DSTATE_i;

  /* If: '<S121>/If1' incorporates:
   *  Constant: '<S121>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S121>/Over_M' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_h, &Merge1_d);

    /* End of Outputs for SubSystem: '<S121>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S121>/Normal' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_h, &Merge1_d);

    /* End of Outputs for SubSystem: '<S121>/Normal' */
  }

  /* End of If: '<S121>/If1' */

  /* Switch: '<S124>/Switch2' incorporates:
   *  RelationalOperator: '<S124>/LowerRelop1'
   *  RelationalOperator: '<S124>/UpperRelop'
   *  Switch: '<S124>/Switch'
   */
  if (rtb_Add > Merge_h) {
    Vq_voltage = Merge_h;
  } else if (rtb_Add < Merge1_d) {
    /* Switch: '<S124>/Switch' */
    Vq_voltage = Merge1_d;
  } else {
    Vq_voltage = rtb_Add;
  }

  /* End of Switch: '<S124>/Switch2' */

  /* Switch: '<S121>/Switch' incorporates:
   *  Constant: '<S121>/Cons'
   *  UnitDelay: '<S121>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_i) {
    rtb_Switch_k = 0.0F;
  }

  /* End of Switch: '<S121>/Switch' */

  /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S121>/Ki'
   *  Product: '<S121>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_i += PI_Parameter.IQ_Ki * rtb_Switch_k *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_p = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S121>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S121>/Relational Operator1'
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

  /* Outputs for Atomic SubSystem: '<S51>/XYZ Caculate' */
  /* Outputs for Atomic SubSystem: '<S51>/N Sector  Caculate' */
  /* Gain: '<S127>/Gain' incorporates:
   *  Gain: '<S130>/Gain'
   */
  rtb_IndexVector1 = 1.73205078F * V_alpha;

  /* End of Outputs for SubSystem: '<S51>/XYZ Caculate' */

  /* Saturate: '<S127>/Saturation' incorporates:
   *  Gain: '<S127>/Gain'
   *  Gain: '<S127>/Gain1'
   *  Gain: '<S127>/Gain2'
   *  Sum: '<S127>/Add'
   *  Sum: '<S127>/Add1'
   *  Sum: '<S127>/Add2'
   *  Switch: '<S127>/Switch'
   *  Switch: '<S127>/Switch1'
   *  Switch: '<S127>/Switch2'
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

  /* End of Saturate: '<S127>/Saturation' */
  /* End of Outputs for SubSystem: '<S51>/N Sector  Caculate' */

  /* Outputs for Atomic SubSystem: '<S51>/XYZ Caculate' */
  /* Saturate: '<S130>/Saturation' incorporates:
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (rtU.Bus_Voltage > 1200.0F) {
    rtb_Add1_fq = 1200.0F;
  } else if (rtU.Bus_Voltage < 0.0001F) {
    rtb_Add1_fq = 0.0001F;
  } else {
    rtb_Add1_fq = rtU.Bus_Voltage;
  }

  /* End of Saturate: '<S130>/Saturation' */

  /* Product: '<S130>/Divide' incorporates:
   *  Constant: '<S130>/Constant'
   *  Constant: '<S40>/Constant4'
   */
  rtb_Add1_fq = 0.000173205073F / rtb_Add1_fq;

  /* End of Outputs for SubSystem: '<S51>/XYZ Caculate' */

  /* Outputs for Atomic SubSystem: '<S51>/T1 T2  Caculate' */
  /* MultiPortSwitch: '<S128>/Index Vector' incorporates:
   *  Gain: '<S128>/Gain'
   *  Gain: '<S128>/Gain1'
   *  Gain: '<S128>/Gain2'
   *  Gain: '<S130>/Gain1'
   *  Gain: '<S130>/Gain2'
   *  Product: '<S130>/Product'
   *  Product: '<S130>/Product1'
   *  Product: '<S130>/Product2'
   *  Sum: '<S130>/Add1'
   *  Sum: '<S130>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    /* Outputs for Atomic SubSystem: '<S51>/XYZ Caculate' */
    rtb_IndexVector_c = (rtb_IndexVector1 - V_beta) * -0.5F * rtb_Add1_fq;

    /* MultiPortSwitch: '<S128>/Index Vector1' incorporates:
     *  Gain: '<S130>/Gain1'
     *  Gain: '<S130>/Gain2'
     *  Product: '<S130>/Product1'
     *  Product: '<S130>/Product2'
     *  Sum: '<S130>/Add1'
     *  Sum: '<S130>/Add2'
     */
    rtb_Gain_a = ((0.0F - V_beta) - rtb_IndexVector1) * -0.5F * rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S51>/XYZ Caculate' */
    break;

   case 2:
    /* Outputs for Atomic SubSystem: '<S51>/XYZ Caculate' */
    rtb_IndexVector_c = ((0.0F - V_beta) - rtb_IndexVector1) * -0.5F *
      rtb_Add1_fq;

    /* MultiPortSwitch: '<S128>/Index Vector1' incorporates:
     *  Gain: '<S128>/Gain'
     *  Gain: '<S130>/Gain2'
     *  Product: '<S130>/Product'
     *  Product: '<S130>/Product1'
     *  Sum: '<S130>/Add2'
     */
    rtb_Gain_a = -(V_beta * rtb_Add1_fq);

    /* End of Outputs for SubSystem: '<S51>/XYZ Caculate' */
    break;

   case 3:
    /* Outputs for Atomic SubSystem: '<S51>/XYZ Caculate' */
    rtb_IndexVector_c = -((rtb_IndexVector1 - V_beta) * -0.5F * rtb_Add1_fq);

    /* MultiPortSwitch: '<S128>/Index Vector1' incorporates:
     *  Gain: '<S128>/Gain2'
     *  Gain: '<S130>/Gain1'
     *  Product: '<S130>/Product'
     *  Product: '<S130>/Product2'
     *  Sum: '<S130>/Add1'
     */
    rtb_Gain_a = V_beta * rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S51>/XYZ Caculate' */
    break;

   case 4:
    /* Outputs for Atomic SubSystem: '<S51>/XYZ Caculate' */
    rtb_IndexVector_c = -(V_beta * rtb_Add1_fq);

    /* MultiPortSwitch: '<S128>/Index Vector1' incorporates:
     *  Gain: '<S128>/Gain'
     *  Gain: '<S130>/Gain1'
     *  Product: '<S130>/Product'
     *  Product: '<S130>/Product2'
     *  Sum: '<S130>/Add1'
     */
    rtb_Gain_a = (rtb_IndexVector1 - V_beta) * -0.5F * rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S51>/XYZ Caculate' */
    break;

   case 5:
    /* Outputs for Atomic SubSystem: '<S51>/XYZ Caculate' */
    rtb_IndexVector_c = V_beta * rtb_Add1_fq;

    /* MultiPortSwitch: '<S128>/Index Vector1' incorporates:
     *  Gain: '<S128>/Gain1'
     *  Gain: '<S130>/Gain2'
     *  Product: '<S130>/Product'
     *  Product: '<S130>/Product1'
     *  Sum: '<S130>/Add2'
     */
    rtb_Gain_a = -(((0.0F - V_beta) - rtb_IndexVector1) * -0.5F * rtb_Add1_fq);

    /* End of Outputs for SubSystem: '<S51>/XYZ Caculate' */
    break;

   default:
    /* Outputs for Atomic SubSystem: '<S51>/XYZ Caculate' */
    rtb_IndexVector_c = -(((0.0F - V_beta) - rtb_IndexVector1) * -0.5F *
                          rtb_Add1_fq);

    /* MultiPortSwitch: '<S128>/Index Vector1' incorporates:
     *  Gain: '<S128>/Gain1'
     *  Gain: '<S128>/Gain2'
     *  Gain: '<S130>/Gain1'
     *  Gain: '<S130>/Gain2'
     *  Product: '<S130>/Product1'
     *  Product: '<S130>/Product2'
     *  Sum: '<S130>/Add1'
     *  Sum: '<S130>/Add2'
     */
    rtb_Gain_a = -((rtb_IndexVector1 - V_beta) * -0.5F * rtb_Add1_fq);

    /* End of Outputs for SubSystem: '<S51>/XYZ Caculate' */
    break;
  }

  /* End of MultiPortSwitch: '<S128>/Index Vector' */

  /* Sum: '<S128>/Add' */
  rtb_Add1_fq = rtb_IndexVector_c + rtb_Gain_a;

  /* Switch: '<S128>/Switch' incorporates:
   *  Constant: '<S40>/Constant4'
   *  Product: '<S128>/Divide'
   *  Product: '<S128>/Divide1'
   *  Sum: '<S128>/Add1'
   *  Switch: '<S128>/Switch2'
   */
  if (!(0.0001F - rtb_Add1_fq > 0.0F)) {
    rtb_IndexVector_c = rtb_IndexVector_c * 0.0001F / rtb_Add1_fq;
    rtb_Gain_a *= 1.0F / rtb_Add1_fq * 0.0001F;
  }

  /* End of Switch: '<S128>/Switch' */
  /* End of Outputs for SubSystem: '<S51>/T1 T2  Caculate' */

  /* Outputs for Atomic SubSystem: '<S51>/Tcm calculate' */
  /* Gain: '<S129>/Gain2' incorporates:
   *  Constant: '<S40>/Constant4'
   *  Sum: '<S129>/Add'
   */
  rtb_Add1_fq = ((0.0001F - rtb_IndexVector_c) - rtb_Gain_a) * 0.25F;

  /* Sum: '<S129>/Add1' incorporates:
   *  Gain: '<S129>/Gain'
   */
  rtb_IndexVector_c = 0.5F * rtb_IndexVector_c + rtb_Add1_fq;

  /* MultiPortSwitch: '<S129>/Index Vector' incorporates:
   *  Gain: '<S129>/Gain1'
   *  Sum: '<S129>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S129>/Index Vector1' */
    rtb_IndexVector1 = rtb_Add1_fq;

    /* MultiPortSwitch: '<S129>/Index Vector2' incorporates:
     *  Gain: '<S129>/Gain1'
     *  Sum: '<S129>/Add2'
     */
    rtb_Add1_fq = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 2:
    rtb_Saturation = rtb_Add1_fq;

    /* MultiPortSwitch: '<S129>/Index Vector1' incorporates:
     *  Gain: '<S129>/Gain1'
     *  Sum: '<S129>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S129>/Index Vector2' */
    rtb_Add1_fq = rtb_IndexVector_c;
    break;

   case 3:
    rtb_Saturation = rtb_Add1_fq;

    /* MultiPortSwitch: '<S129>/Index Vector1' */
    rtb_IndexVector1 = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S129>/Index Vector2' incorporates:
     *  Gain: '<S129>/Gain1'
     *  Sum: '<S129>/Add2'
     */
    rtb_Add1_fq = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 4:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S129>/Index Vector1' incorporates:
     *  Gain: '<S129>/Gain1'
     *  Sum: '<S129>/Add2'
     */
    rtb_IndexVector1 = rtb_IndexVector_c;
    break;

   case 5:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S129>/Index Vector1' incorporates:
     *  Gain: '<S129>/Gain1'
     *  Sum: '<S129>/Add2'
     */
    rtb_IndexVector1 = rtb_Add1_fq;

    /* MultiPortSwitch: '<S129>/Index Vector2' */
    rtb_Add1_fq = rtb_IndexVector_c;
    break;

   default:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S129>/Index Vector1' incorporates:
     *  Gain: '<S129>/Gain1'
     *  Sum: '<S129>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;
  }

  /* End of MultiPortSwitch: '<S129>/Index Vector' */
  /* End of Outputs for SubSystem: '<S51>/Tcm calculate' */

  /* If: '<S51>/If1' */
  if (rtDW.Merge1_a == 0) {
    /* Gain: '<S51>/Gain' */
    rtb_Saturation *= 8.399E+7F;

    /* Outputs for IfAction SubSystem: '<S51>/Enable_Motor' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    /* Saturate: '<S126>/Saturation' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S51>/Merge' */
      rtDW.Merge_c4 = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S51>/Merge' */
      rtDW.Merge_c4 = 1.0F;
    } else {
      /* Merge: '<S51>/Merge' */
      rtDW.Merge_c4 = rtb_Saturation;
    }

    /* End of Saturate: '<S126>/Saturation' */
    /* End of Outputs for SubSystem: '<S51>/Enable_Motor' */

    /* Gain: '<S51>/Gain2' */
    rtb_Saturation = 8.399E+7F * rtb_IndexVector1;

    /* Outputs for IfAction SubSystem: '<S51>/Enable_Motor' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    /* Saturate: '<S126>/Saturation1' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S51>/Merge1' */
      rtDW.Merge1_h = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S51>/Merge1' */
      rtDW.Merge1_h = 1.0F;
    } else {
      /* Merge: '<S51>/Merge1' */
      rtDW.Merge1_h = rtb_Saturation;
    }

    /* End of Saturate: '<S126>/Saturation1' */
    /* End of Outputs for SubSystem: '<S51>/Enable_Motor' */

    /* Gain: '<S51>/Gain3' */
    rtb_Saturation = 8.399E+7F * rtb_Add1_fq;

    /* Outputs for IfAction SubSystem: '<S51>/Enable_Motor' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    /* Saturate: '<S126>/Saturation2' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S51>/Merge2' */
      rtDW.Merge2_d = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S51>/Merge2' */
      rtDW.Merge2_d = 1.0F;
    } else {
      /* Merge: '<S51>/Merge2' */
      rtDW.Merge2_d = rtb_Saturation;
    }

    /* End of Saturate: '<S126>/Saturation2' */
    /* End of Outputs for SubSystem: '<S51>/Enable_Motor' */
  } else {
    if (rtDW.Merge1_a == 1) {
      /* Outputs for IfAction SubSystem: '<S51>/Disable_Motor' incorporates:
       *  ActionPort: '<S125>/Action Port'
       */
      /* Merge: '<S51>/Merge' incorporates:
       *  Constant: '<S125>/Constant'
       *  SignalConversion generated from: '<S125>/Out1'
       */
      rtDW.Merge_c4 = 0.0F;

      /* Merge: '<S51>/Merge1' incorporates:
       *  Constant: '<S125>/Constant1'
       *  SignalConversion generated from: '<S125>/Out2'
       */
      rtDW.Merge1_h = 0.0F;

      /* Merge: '<S51>/Merge2' incorporates:
       *  Constant: '<S125>/Constant2'
       *  SignalConversion generated from: '<S125>/Out3'
       */
      rtDW.Merge2_d = 0.0F;

      /* End of Outputs for SubSystem: '<S51>/Disable_Motor' */
    }
  }

  /* End of If: '<S51>/If1' */
}

/* Output and update for atomic system: '<S40>/Sine_Cosine' */
void Sine_Cosine_m(void)
{
  real32_T rtb_Saturation;
  uint32_T Cosine_tmp;

  /* Saturate: '<S52>/Saturation' */
  if (rtDW.Merge_g > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Merge_g < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Merge_g;
  }

  /* End of Saturate: '<S52>/Saturation' */

  /* Lookup_n-D: '<S52>/Cosine' incorporates:
   *  Lookup_n-D: '<S52>/Sine'
   *  Saturate: '<S52>/Saturation'
   */
  Cosine_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);
  rtDW.Cosine = rtConstP.pooled6[Cosine_tmp];

  /* Lookup_n-D: '<S52>/Sine' */
  rtDW.Sine = rtConstP.pooled8[Cosine_tmp];
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

/* System initialize for atomic system: '<S5>/FOC' */
void FOC_Init(void)
{
  c_dsp_private_ExponentialMovingAverage *obj_0;
  dsp_simulink_MovingAverage *obj;
  real32_T varargin_2;
  boolean_T flag;

  /* Start for MATLABSystem: '<S59>/Moving Average' */
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

  /* End of Start for MATLABSystem: '<S59>/Moving Average' */

  /* InitializeConditions for MATLABSystem: '<S59>/Moving Average' */
  obj_0 = rtDW.obj.pStatistic;
  if (obj_0->isInitialized == 1) {
    obj_0->pwN = 1.0F;
    obj_0->pmN = 0.0F;
  }

  /* End of InitializeConditions for MATLABSystem: '<S59>/Moving Average' */
}

/* Output and update for atomic system: '<S5>/FOC' */
void FOC(void)
{
  c_dsp_private_ExponentialMovingAverage *obj;
  real32_T rtb_Add2_ny;
  real32_T rtb_Add4;
  real32_T rtb_Gain1_b;
  real32_T rtb_Gain1_c;
  real32_T rtb_IProdOut;
  real32_T rtb_Product_ev;
  real32_T rtb_Saturation;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_SignPreSat;
  real32_T rtb_Sum1;
  real32_T rtb_ZeroGain;
  uint8_T rtb_Motor_State;
  boolean_T rtb_NotEqual;

  /* UnitDelay: '<S60>/Unit Delay' */
  rtb_Gain1_c = rtDW.UnitDelay_DSTATE_c;

  /* UnitDelay: '<S66>/Unit Delay' */
  rtDW.UnitDelay = rtDW.UnitDelay_DSTATE_p;

  /* Outputs for Atomic SubSystem: '<S61>/Sine_Cosine' */
  Sine_Cosine();

  /* End of Outputs for SubSystem: '<S61>/Sine_Cosine' */

  /* Outputs for Atomic SubSystem: '<S40>/Clarke_Transform' */
  Clarke_Transform();

  /* End of Outputs for SubSystem: '<S40>/Clarke_Transform' */

  /* Gain: '<S44>/Gain' */
  rtb_Add2_ny = Flux_Parameter.Flux_Gain * Ialpha;

  /* Sum: '<S63>/Sum' incorporates:
   *  DiscreteIntegrator: '<S63>/Integrator'
   *  Gain: '<S63>/Gain2'
   */
  rtb_Saturation = rtDW.Integrator_DSTATE - 0.000425F * rtb_Add2_ny;

  /* Gain: '<S44>/Gain1' */
  rtb_Gain1_b = Flux_Parameter.Flux_Gain * Ibeta;

  /* Sum: '<S63>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S63>/Integrator1'
   *  Gain: '<S63>/Gain3'
   */
  rtb_Sum1 = rtDW.Integrator1_DSTATE - 0.000425F * rtb_Gain1_b;

  /* Sum: '<S61>/Sum' incorporates:
   *  Product: '<S61>/Product'
   *  Product: '<S61>/Product1'
   */
  rtb_IProdOut = rtb_Sum1 * rtDW.Sine - rtDW.Cosine * rtb_Saturation;

  /* Sum: '<S109>/Sum' incorporates:
   *  Constant: '<S61>/Constant'
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S61>/Gain'
   *  Product: '<S105>/PProd Out'
   */
  rtb_SignPreSat = Flux_Parameter.pll_xi * Flux_Parameter.pll_omega *
    rtb_IProdOut + rtDW.Integrator_DSTATE_e;

  /* Saturate: '<S107>/Saturation' */
  if (rtb_SignPreSat > 523.598755F) {
    rtb_SignPreIntegrator = 523.598755F;
  } else if (rtb_SignPreSat < -523.598755F) {
    rtb_SignPreIntegrator = -523.598755F;
  } else {
    rtb_SignPreIntegrator = rtb_SignPreSat;
  }

  /* End of Saturate: '<S107>/Saturation' */

  /* Sum: '<S60>/Add1' incorporates:
   *  Constant: '<S60>/Constant1'
   *  Gain: '<S59>/Gain1'
   *  Product: '<S60>/Divide1'
   *  Sum: '<S60>/Add'
   */
  rtDW.Add1 = (4.77464819F * rtb_SignPreIntegrator - rtb_Gain1_c) *
    SpeedFilter_Fn + rtb_Gain1_c;

  /* Chart: '<S40>/Chart' incorporates:
   *  Constant: '<S40>/Constant6'
   */
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c3_Motor_Control == 0U) {
    rtDW.is_active_c3_Motor_Control = 1U;
    rtDW.is_c3_Motor_Control = IN_Standby;
    rtb_Motor_State = 0U;
  } else {
    switch (rtDW.is_c3_Motor_Control) {
     case IN_CLP:
      rtb_Motor_State = 2U;
      break;

     case IN_OPL:
      if ((rtDW.Merge1_a == 0) && (rtDW.temporalCounter_i1 >= (uint32_T)ceil
           (OPL_Parameter.OPL_Time / 0.0001 - 1.0E-12)) && (rtDW.Add1 > 500.0F))
      {
        rtDW.is_c3_Motor_Control = IN_CLP;
        rtb_Motor_State = 2U;
      } else {
        rtb_Motor_State = 1U;
      }
      break;

     default:
      /* case IN_Standby: */
      if (rtDW.Merge1_a == 0) {
        rtDW.is_c3_Motor_Control = IN_OPL;
        rtDW.temporalCounter_i1 = 0U;
        rtb_Motor_State = 1U;
      } else {
        rtb_Motor_State = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S40>/Chart' */

  /* SwitchCase: '<S40>/Switch Case' incorporates:
   *  Constant: '<S40>/Constant2'
   *  Inport: '<S48>/OPL_Torque'
   *  Inport: '<S53>/In1'
   */
  switch (rtb_Motor_State) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S40>/OpenLoop' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    /* Merge: '<S40>/Merge2' incorporates:
     *  Constant: '<S48>/2pi2'
     *  DiscreteIntegrator: '<S48>/Discrete-Time Integrator1'
     *  Math: '<S48>/Mod2'
     *  SignalConversion generated from: '<S48>/Force_Angle'
     */
    rtDW.Merge2_f = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE, 6.28318548F);
    rtDW.Merge1 = OPL_Parameter.OPL_Torque;

    /* Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator1' incorporates:
     *  Constant: '<S40>/Constant2'
     *  DiscreteIntegrator: '<S48>/Discrete-Time Integrator2'
     *  Gain: '<S48>/We'
     *  Inport: '<S48>/OPL_Torque'
     */
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.209439516F *
      rtDW.DiscreteTimeIntegrator2_DSTATE * 0.0001F;

    /* Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S40>/Constant1'
     *  Constant: '<S40>/Constant3'
     *  Product: '<S48>/Product'
     */
    rtDW.DiscreteTimeIntegrator2_DSTATE += 1.0F / OPL_Parameter.OPL_Time *
      OPL_Parameter.OPL_Speed * 0.0001F;

    /* End of Outputs for SubSystem: '<S40>/OpenLoop' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S40>/Subsystem' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    rtDW.Merge1 = Iq_ref;

    /* Merge: '<S40>/Merge2' incorporates:
     *  Inport: '<S53>/In1'
     *  Inport: '<S53>/In2'
     *  UnitDelay: '<S40>/Unit Delay2'
     */
    rtDW.Merge2_f = rtDW.UnitDelay2_DSTATE_k;

    /* End of Outputs for SubSystem: '<S40>/Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S40>/Switch Case' */

  /* If: '<S40>/If1' incorporates:
   *  Constant: '<S40>/Flux_Enable'
   *  Inport: '<S45>/Hall_Angle'
   *  Inport: '<S47>/Obs_Angle'
   */
  if (Flux_Parameter.Flux_Theta_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S40>/Obs_Angle' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    rtDW.Merge_g = rtDW.Merge2_f;

    /* End of Outputs for SubSystem: '<S40>/Obs_Angle' */
  } else {
    if (Flux_Parameter.Flux_Theta_Enable == 0) {
      /* Outputs for IfAction SubSystem: '<S40>/Hall_Angle' incorporates:
       *  ActionPort: '<S45>/Action Port'
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

  /* MATLABSystem: '<S59>/Moving Average' incorporates:
   *  Abs: '<S59>/Abs'
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

  rtb_Gain1_c = obj->pwN;
  rtb_ZeroGain = obj->pmN;
  rtb_Add4 = obj->plambda;
  rtb_ZeroGain = (1.0F - 1.0F / rtb_Gain1_c) * rtb_ZeroGain + 1.0F / rtb_Gain1_c
    * fabsf(rtb_SignPreIntegrator);
  obj->pwN = rtb_Add4 * rtb_Gain1_c + 1.0F;
  obj->pmN = rtb_ZeroGain;

  /* Gain: '<S62>/Gain' incorporates:
   *  MATLABSystem: '<S59>/Moving Average'
   */
  rtb_Gain1_c = 0.005F * rtb_ZeroGain;

  /* Saturate: '<S62>/Saturation' */
  if (rtb_Gain1_c > 1.0F) {
    rtb_Gain1_c = 1.0F;
  } else {
    if (rtb_Gain1_c < 0.8F) {
      rtb_Gain1_c = 0.8F;
    }
  }

  /* End of Saturate: '<S62>/Saturation' */

  /* Gain: '<S62>/Gain1' */
  rtb_Gain1_c *= 0.405F;

  /* Sum: '<S62>/Add4' incorporates:
   *  Gain: '<S44>/Gain2'
   *  Product: '<S62>/Product'
   */
  rtb_Add4 = Flux_Parameter.Flux_Gain * V_alpha - rtb_Add2_ny * rtb_Gain1_c;

  /* Sum: '<S63>/Add2' incorporates:
   *  Math: '<S63>/Math Function'
   *  Math: '<S63>/Math Function1'
   *
   * About '<S63>/Math Function':
   *  Operator: magnitude^2
   *
   * About '<S63>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Add2_ny = (2.80133099E-5F - rtb_Saturation * rtb_Saturation) - rtb_Sum1 *
    rtb_Sum1;

  /* Product: '<S63>/Product' */
  rtb_Product_ev = rtb_Add2_ny * rtb_Saturation;

  /* Gain: '<S63>/Gain4' incorporates:
   *  MATLABSystem: '<S59>/Moving Average'
   */
  rtb_Saturation = 35697.3203F * rtb_ZeroGain;

  /* Saturate: '<S63>/Saturation' */
  if (rtb_Saturation > 5.0E+6F) {
    rtb_Saturation = 5.0E+6F;
  } else {
    if (rtb_Saturation < 200000.0F) {
      rtb_Saturation = 200000.0F;
    }
  }

  /* End of Saturate: '<S63>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S40>/SVPWM' */
  SVPWM();

  /* End of Outputs for SubSystem: '<S40>/SVPWM' */

  /* Sum: '<S66>/Sum1' incorporates:
   *  Gain: '<S66>/Ts'
   */
  rtb_SignPreIntegrator = 0.0001F * rtb_SignPreIntegrator + rtDW.UnitDelay;

  /* Gain: '<S91>/ZeroGain' */
  rtb_ZeroGain = 0.0F * rtb_SignPreSat;

  /* DeadZone: '<S93>/DeadZone' */
  if (rtb_SignPreSat > 523.598755F) {
    rtb_SignPreSat -= 523.598755F;
  } else if (rtb_SignPreSat >= -523.598755F) {
    rtb_SignPreSat = 0.0F;
  } else {
    rtb_SignPreSat -= -523.598755F;
  }

  /* End of DeadZone: '<S93>/DeadZone' */

  /* RelationalOperator: '<S91>/NotEqual' */
  rtb_NotEqual = (rtb_ZeroGain != rtb_SignPreSat);

  /* Signum: '<S91>/SignPreSat' */
  if (rtb_SignPreSat < 0.0F) {
    rtb_SignPreSat = -1.0F;
  } else if (rtb_SignPreSat > 0.0F) {
    rtb_SignPreSat = 1.0F;
  } else if (rtb_SignPreSat == 0.0F) {
    rtb_SignPreSat = 0.0F;
  } else {
    rtb_SignPreSat = (rtNaNF);
  }

  /* End of Signum: '<S91>/SignPreSat' */

  /* Product: '<S97>/IProd Out' incorporates:
   *  Constant: '<S61>/Constant'
   *  Product: '<S61>/Product2'
   */
  rtb_IProdOut *= Flux_Parameter.pll_omega * Flux_Parameter.pll_omega;

  /* Update for UnitDelay: '<S60>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_c = rtDW.Add1;

  /* If: '<S117>/If' incorporates:
   *  Constant: '<S117>/Constant'
   *  Constant: '<S117>/Constant1'
   *  RelationalOperator: '<S117>/Relational Operator'
   *  RelationalOperator: '<S117>/Relational Operator1'
   */
  if (rtb_SignPreIntegrator > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    /* Update for UnitDelay: '<S66>/Unit Delay' incorporates:
     *  Constant: '<S119>/Constant'
     *  Sum: '<S119>/Sum'
     */
    rtDW.UnitDelay_DSTATE_p = rtb_SignPreIntegrator - 6.28318548F;

    /* End of Outputs for SubSystem: '<S117>/If Action Subsystem1' */
  } else if (rtb_SignPreIntegrator < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    /* Update for UnitDelay: '<S66>/Unit Delay' incorporates:
     *  Constant: '<S118>/Constant'
     *  Sum: '<S118>/Sum'
     */
    rtDW.UnitDelay_DSTATE_p = rtb_SignPreIntegrator + 6.28318548F;

    /* End of Outputs for SubSystem: '<S117>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    /* Update for UnitDelay: '<S66>/Unit Delay' incorporates:
     *  Inport: '<S120>/In1'
     */
    rtDW.UnitDelay_DSTATE_p = rtb_SignPreIntegrator;

    /* End of Outputs for SubSystem: '<S117>/If Action Subsystem2' */
  }

  /* End of If: '<S117>/If' */

  /* Update for DiscreteIntegrator: '<S63>/Integrator' incorporates:
   *  Product: '<S63>/Product2'
   *  Sum: '<S63>/Add'
   */
  rtDW.Integrator_DSTATE += (rtb_Product_ev * rtb_Saturation + rtb_Add4) *
    0.0001F;

  /* Update for DiscreteIntegrator: '<S63>/Integrator1' incorporates:
   *  Gain: '<S44>/Gain3'
   *  Product: '<S62>/Product1'
   *  Product: '<S63>/Product1'
   *  Product: '<S63>/Product3'
   *  Sum: '<S62>/Add5'
   *  Sum: '<S63>/Add1'
   */
  rtDW.Integrator1_DSTATE += ((Flux_Parameter.Flux_Gain * V_beta - rtb_Gain1_b *
    rtb_Gain1_c) + rtb_Add2_ny * rtb_Sum1 * rtb_Saturation) * 0.0001F;

  /* Signum: '<S91>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    rtb_Add2_ny = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_Add2_ny = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_Add2_ny = 0.0F;
  } else {
    rtb_Add2_ny = (rtNaNF);
  }

  /* End of Signum: '<S91>/SignPreIntegrator' */

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Constant1'
   *  DataTypeConversion: '<S91>/DataTypeConv1'
   *  DataTypeConversion: '<S91>/DataTypeConv2'
   *  Logic: '<S91>/AND3'
   *  RelationalOperator: '<S91>/Equal1'
   */
  if (rtb_NotEqual && ((int8_T)rtb_SignPreSat == (int8_T)rtb_Add2_ny)) {
    rtb_IProdOut = 0.0F;
  }

  /* End of Switch: '<S91>/Switch' */

  /* Update for DiscreteIntegrator: '<S100>/Integrator' */
  rtDW.Integrator_DSTATE_e += 0.0001F * rtb_IProdOut;

  /* Update for UnitDelay: '<S40>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE_k = rtDW.UnitDelay;
}

/* System initialize for function-call system: '<S2>/FOC_Control_100us' */
void FOC_Control_100us_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S5>/FOC' */
  FOC_Init();

  /* End of SystemInitialize for SubSystem: '<S5>/FOC' */
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
