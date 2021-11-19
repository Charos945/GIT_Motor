/*
 * File: FOC_Control_100us.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 18 17:48:38 2021
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

/* Named constants for Chart: '<S33>/Chart' */
#define IN_CLP                         ((uint8_T)1U)
#define IN_OPL                         ((uint8_T)2U)
#define IN_Standby                     ((uint8_T)3U)

/* Output and update for atomic system: '<S33>/Clarke_Transform' */
void Clarke_Transform(void)
{
  /* Outputs for Atomic SubSystem: '<S35>/Clark1' */
  /* Gain: '<S48>/Gain2' incorporates:
   *  Gain: '<S48>/Gain'
   *  Gain: '<S48>/Gain1'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S48>/Add'
   */
  Ialpha = ((rtU.Phase_CurrentABC[0] - 0.5F * rtU.Phase_CurrentABC[1]) - 0.5F *
            rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* Gain: '<S48>/Gain5' incorporates:
   *  Gain: '<S48>/Gain3'
   *  Gain: '<S48>/Gain4'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S48>/Add1'
   */
  Ibeta = (0.866025388F * rtU.Phase_CurrentABC[1] - 0.866025388F *
           rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* End of Outputs for SubSystem: '<S35>/Clark1' */
}

/*
 * Output and update for action system:
 *    '<S49>/Over_M'
 *    '<S118>/Over_M'
 */
void Over_M(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S51>/Gain' */
  *rty_Out1 = 0.666666687F * rtu_Bus_voltage;

  /* Gain: '<S51>/Gain1' */
  *rty_Out2 = -0.666666687F * rtu_Bus_voltage;
}

/*
 * Output and update for action system:
 *    '<S49>/Normal'
 *    '<S118>/Normal'
 */
void Normal(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S50>/Gain' */
  *rty_Out1 = 0.577350259F * rtu_Bus_voltage;

  /* Gain: '<S50>/Gain1' */
  *rty_Out2 = -0.577350259F * rtu_Bus_voltage;
}

/* Output and update for atomic system: '<S33>/D_Current_PI' */
void D_Current_PI(void)
{
  real32_T Merge1_b;
  real32_T Merge_a;
  real32_T rtb_Add;
  real32_T rtb_Switch_h;

  /* Sum: '<S36>/Add2' */
  rtb_Switch_h = Id_ref - Id_measured;

  /* DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_pb !=
       0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_a = 0.0F;
  }

  /* Sum: '<S49>/Add' incorporates:
   *  Constant: '<S49>/Kp'
   *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
   *  Product: '<S49>/Product'
   */
  rtb_Add = PI_Parameter.ID_Kp * rtb_Switch_h +
    rtDW.DiscreteTimeIntegrator_DSTATE_a;

  /* If: '<S49>/If1' incorporates:
   *  Constant: '<S49>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S49>/Over_M' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S49>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S49>/Normal' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S49>/Normal' */
  }

  /* End of If: '<S49>/If1' */

  /* Switch: '<S52>/Switch2' incorporates:
   *  RelationalOperator: '<S52>/LowerRelop1'
   *  RelationalOperator: '<S52>/UpperRelop'
   *  Switch: '<S52>/Switch'
   */
  if (rtb_Add > Merge_a) {
    /* Switch: '<S52>/Switch2' */
    Vd_voltage = Merge_a;
  } else if (rtb_Add < Merge1_b) {
    /* Switch: '<S52>/Switch' incorporates:
     *  Switch: '<S52>/Switch2'
     */
    Vd_voltage = Merge1_b;
  } else {
    /* Switch: '<S52>/Switch2' incorporates:
     *  Switch: '<S52>/Switch'
     */
    Vd_voltage = rtb_Add;
  }

  /* End of Switch: '<S52>/Switch2' */

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Cons'
   *  UnitDelay: '<S49>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_k) {
    rtb_Switch_h = 0.0F;
  }

  /* End of Switch: '<S49>/Switch' */

  /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S49>/Ki'
   *  Product: '<S49>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += PI_Parameter.ID_Ki * rtb_Switch_h *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_pb = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S49>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S49>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_k = (rtb_Add == Vd_voltage);
}

/* Output and update for atomic system: '<S57>/Sine_Cosine' */
void Sine_Cosine(void)
{
  real32_T rtb_Saturation;
  uint32_T Cosine_tmp;

  /* Saturate: '<S59>/Saturation' */
  if (rtDW.UnitDelay > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.UnitDelay < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.UnitDelay;
  }

  /* End of Saturate: '<S59>/Saturation' */

  /* Lookup_n-D: '<S59>/Cosine' incorporates:
   *  Lookup_n-D: '<S59>/Sine'
   *  Saturate: '<S59>/Saturation'
   */
  Cosine_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);

  /* Lookup_n-D: '<S59>/Cosine' */
  rtDW.Cosine = rtConstP.pooled10[Cosine_tmp];

  /* Lookup_n-D: '<S59>/Sine' */
  rtDW.Sine = rtConstP.pooled12[Cosine_tmp];
}

/* System initialize for atomic system: '<S33>/HIGH_SMO' */
void HIGH_SMO_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator' */
  rtDW.Integrator_DSTATE_d = 1.0F;
}

/* Enable for atomic system: '<S33>/HIGH_SMO' */
void HIGH_SMO_Enable(void)
{
  /* Enable for DiscreteIntegrator: '<S54>/Integrator1' */
  rtDW.Integrator1_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S56>/Integrator3' */
  rtDW.Integrator3_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S53>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S55>/Integrator2' */
  rtDW.Integrator2_SYSTEM_ENABLE = 1U;
}

/* Output and update for atomic system: '<S33>/HIGH_SMO' */
void HIGH_SMO(void)
{
  int32_T tmp;
  real32_T Integrator1;
  real32_T Integrator2;
  real32_T Integrator3;
  real32_T rtb_IProdOut;
  real32_T rtb_Integrator;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_Sum_c;
  real32_T rtb_UnitDelay2;
  boolean_T rtb_NotEqual;

  /* UnitDelay: '<S55>/Unit Delay2' */
  rtb_UnitDelay2 = rtDW.UnitDelay2_DSTATE_e;

  /* UnitDelay: '<S56>/Unit Delay3' */
  rtb_SignPreIntegrator = rtDW.UnitDelay3_DSTATE_j;

  /* UnitDelay: '<S53>/Unit Delay' */
  rtb_Sum_c = rtDW.UnitDelay_DSTATE_f;

  /* UnitDelay: '<S57>/Unit Delay' */
  rtDW.speed_hat = rtDW.UnitDelay_DSTATE_p;

  /* UnitDelay: '<S54>/Unit Delay1' */
  rtb_Integrator = rtDW.UnitDelay1_DSTATE_f;

  /* Sum: '<S37>/Sum6' */
  rtb_IProdOut = rtb_Integrator - Ibeta;

  /* Signum: '<S37>/Sign1' */
  if (rtb_IProdOut < 0.0F) {
    rtb_IProdOut = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_IProdOut = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_IProdOut = 0.0F;
  } else {
    rtb_IProdOut = (rtNaNF);
  }

  /* End of Signum: '<S37>/Sign1' */

  /* DiscreteIntegrator: '<S54>/Integrator1' */
  if (rtDW.Integrator1_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S54>/Integrator1' */
    Integrator1 = rtDW.Integrator1_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S54>/Integrator1' incorporates:
     *  Gain: '<S54>/Gain3'
     *  Gain: '<S54>/Gain5'
     *  Gain: '<S54>/Gain6'
     *  Gain: '<S54>/Gain7'
     *  Gain: '<S54>/Gain8'
     *  Product: '<S54>/Product1'
     *  Sum: '<S54>/Add1'
     */
    Integrator1 = ((((rtb_Sum_c * rtDW.speed_hat * -0.125F - 1012.5F *
                      rtb_Integrator) - 2500.0F * rtb_SignPreIntegrator) +
                    2500.0F * V_beta) - SMO_Parameter.SMO_K / 0.0004F *
                   rtb_IProdOut) * 0.0001F + rtDW.Integrator1_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S54>/Integrator1' */

  /* DiscreteIntegrator: '<S56>/Integrator3' */
  if (rtDW.Integrator3_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S56>/Integrator3' */
    Integrator3 = rtDW.Integrator3_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S56>/Integrator3' incorporates:
     *  Gain: '<S56>/Gain10'
     *  Product: '<S56>/Product3'
     *  Sum: '<S56>/Add3'
     */
    Integrator3 = (SMO_Parameter.SMO_K / 0.0004F * rtb_IProdOut + rtDW.speed_hat
                   * rtb_UnitDelay2) * 0.0001F + rtDW.Integrator3_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S56>/Integrator3' */

  /* Gain: '<S53>/Gain' */
  rtb_IProdOut = 1012.5F * rtb_Sum_c;

  /* Sum: '<S37>/Sum2' */
  rtb_Sum_c -= Ialpha;

  /* Signum: '<S37>/Sign' */
  if (rtb_Sum_c < 0.0F) {
    rtb_Sum_c = -1.0F;
  } else if (rtb_Sum_c > 0.0F) {
    rtb_Sum_c = 1.0F;
  } else if (rtb_Sum_c == 0.0F) {
    rtb_Sum_c = 0.0F;
  } else {
    rtb_Sum_c = (rtNaNF);
  }

  /* End of Signum: '<S37>/Sign' */

  /* DiscreteIntegrator: '<S53>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S53>/Integrator' */
    rtb_Integrator = rtDW.Integrator_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S53>/Integrator' incorporates:
     *  Gain: '<S53>/Gain1'
     *  Gain: '<S53>/Gain17'
     *  Gain: '<S53>/Gain2'
     *  Gain: '<S53>/Gain4'
     *  Product: '<S53>/Product'
     *  Sum: '<S53>/Add'
     */
    rtb_Integrator = ((((2500.0F * V_alpha - rtb_IProdOut) - rtb_Integrator *
                        rtDW.speed_hat * -0.125F) - 2500.0F * rtb_UnitDelay2) -
                      SMO_Parameter.SMO_K / 0.0004F * rtb_Sum_c) * 0.0001F +
      rtDW.Integrator_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S53>/Integrator' */

  /* DiscreteIntegrator: '<S55>/Integrator2' */
  if (rtDW.Integrator2_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S55>/Integrator2' */
    Integrator2 = rtDW.Integrator2_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S55>/Integrator2' incorporates:
     *  Gain: '<S55>/Gain9'
     *  Product: '<S55>/Product2'
     *  Sum: '<S55>/Add2'
     */
    Integrator2 = (SMO_Parameter.SMO_M / 0.0004F * rtb_Sum_c - rtDW.speed_hat *
                   rtb_SignPreIntegrator) * 0.0001F + rtDW.Integrator2_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S55>/Integrator2' */

  /* UnitDelay: '<S60>/Unit Delay' */
  rtDW.UnitDelay = rtDW.UnitDelay_DSTATE_h;

  /* Outputs for Atomic SubSystem: '<S57>/Sine_Cosine' */
  Sine_Cosine();

  /* End of Outputs for SubSystem: '<S57>/Sine_Cosine' */

  /* If: '<S61>/If' incorporates:
   *  Constant: '<S116>/Constant'
   *  Constant: '<S117>/Constant'
   *  SignalConversion generated from: '<S116>/Out1'
   *  SignalConversion generated from: '<S117>/Out1'
   */
  if (rtDW.speed_hat > 0.0F) {
    /* Outputs for IfAction SubSystem: '<S61>/If Action Subsystem' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    tmp = 1;

    /* End of Outputs for SubSystem: '<S61>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S61>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    tmp = -1;

    /* End of Outputs for SubSystem: '<S61>/If Action Subsystem1' */
  }

  /* End of If: '<S61>/If' */

  /* Product: '<S61>/Product' incorporates:
   *  Product: '<S57>/Product1'
   *  Product: '<S57>/Product2'
   *  Sum: '<S57>/Sum'
   */
  rtb_IProdOut = ((0.0F - rtDW.Cosine * rtb_UnitDelay2) - rtb_SignPreIntegrator *
                  rtDW.Sine) * (real32_T)tmp;

  /* Sum: '<S104>/Sum' incorporates:
   *  Constant: '<S57>/Kp'
   *  DiscreteIntegrator: '<S95>/Integrator'
   *  Product: '<S100>/PProd Out'
   */
  rtb_Sum_c = 1.414F * SMO_Parameter.SMO_PLL_W * rtb_IProdOut +
    rtDW.Integrator_DSTATE_d;

  /* DeadZone: '<S88>/DeadZone' */
  if (rtb_Sum_c > 3141.59277F) {
    rtb_SignPreIntegrator = rtb_Sum_c - 3141.59277F;
  } else if (rtb_Sum_c >= -3141.59277F) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = rtb_Sum_c - -3141.59277F;
  }

  /* End of DeadZone: '<S88>/DeadZone' */

  /* RelationalOperator: '<S86>/NotEqual' incorporates:
   *  Gain: '<S86>/ZeroGain'
   */
  rtb_NotEqual = (0.0F * rtb_Sum_c != rtb_SignPreIntegrator);

  /* Signum: '<S86>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0F) {
    rtb_SignPreIntegrator = -1.0F;
  } else if (rtb_SignPreIntegrator > 0.0F) {
    rtb_SignPreIntegrator = 1.0F;
  } else if (rtb_SignPreIntegrator == 0.0F) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = (rtNaNF);
  }

  /* End of Signum: '<S86>/SignPreSat' */

  /* Product: '<S92>/IProd Out' incorporates:
   *  Constant: '<S57>/Ki'
   */
  rtb_IProdOut *= SMO_Parameter.SMO_PLL_W * SMO_Parameter.SMO_PLL_W;

  /* Saturate: '<S102>/Saturation' */
  if (rtb_Sum_c > 3141.59277F) {
    rtb_UnitDelay2 = 3141.59277F;
  } else if (rtb_Sum_c < -3141.59277F) {
    rtb_UnitDelay2 = -3141.59277F;
  } else {
    rtb_UnitDelay2 = rtb_Sum_c;
  }

  /* End of Saturate: '<S102>/Saturation' */

  /* Sum: '<S60>/Sum1' incorporates:
   *  Gain: '<S60>/Ts'
   */
  rtb_Sum_c = 0.0001F * rtb_UnitDelay2 + rtDW.UnitDelay;

  /* Update for UnitDelay: '<S55>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE_e = Integrator2;

  /* Update for UnitDelay: '<S56>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE_j = Integrator3;

  /* Update for UnitDelay: '<S53>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_f = rtb_Integrator;

  /* Update for UnitDelay: '<S57>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_p = rtb_UnitDelay2;

  /* Update for UnitDelay: '<S54>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE_f = Integrator1;

  /* Update for DiscreteIntegrator: '<S54>/Integrator1' */
  rtDW.Integrator1_SYSTEM_ENABLE = 0U;
  rtDW.Integrator1_DSTATE = Integrator1;

  /* Update for DiscreteIntegrator: '<S56>/Integrator3' */
  rtDW.Integrator3_SYSTEM_ENABLE = 0U;
  rtDW.Integrator3_DSTATE = Integrator3;

  /* Update for DiscreteIntegrator: '<S53>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 0U;
  rtDW.Integrator_DSTATE = rtb_Integrator;

  /* Update for DiscreteIntegrator: '<S55>/Integrator2' */
  rtDW.Integrator2_SYSTEM_ENABLE = 0U;
  rtDW.Integrator2_DSTATE = Integrator2;

  /* If: '<S112>/If' incorporates:
   *  Constant: '<S112>/Constant'
   *  Constant: '<S112>/Constant1'
   *  RelationalOperator: '<S112>/Relational Operator'
   *  RelationalOperator: '<S112>/Relational Operator1'
   */
  if (rtb_Sum_c > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    /* Update for UnitDelay: '<S60>/Unit Delay' incorporates:
     *  Constant: '<S114>/Constant'
     *  Sum: '<S114>/Sum'
     */
    rtDW.UnitDelay_DSTATE_h = rtb_Sum_c - 6.28318548F;

    /* End of Outputs for SubSystem: '<S112>/If Action Subsystem1' */
  } else if (rtb_Sum_c < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    /* Update for UnitDelay: '<S60>/Unit Delay' incorporates:
     *  Constant: '<S113>/Constant'
     *  Sum: '<S113>/Sum'
     */
    rtDW.UnitDelay_DSTATE_h = rtb_Sum_c + 6.28318548F;

    /* End of Outputs for SubSystem: '<S112>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S112>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    /* Update for UnitDelay: '<S60>/Unit Delay' incorporates:
     *  Inport: '<S115>/In1'
     */
    rtDW.UnitDelay_DSTATE_h = rtb_Sum_c;

    /* End of Outputs for SubSystem: '<S112>/If Action Subsystem2' */
  }

  /* End of If: '<S112>/If' */

  /* Signum: '<S86>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    rtb_UnitDelay2 = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_UnitDelay2 = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_UnitDelay2 = 0.0F;
  } else {
    rtb_UnitDelay2 = (rtNaNF);
  }

  /* End of Signum: '<S86>/SignPreIntegrator' */

  /* Switch: '<S86>/Switch' incorporates:
   *  Constant: '<S86>/Constant1'
   *  DataTypeConversion: '<S86>/DataTypeConv1'
   *  DataTypeConversion: '<S86>/DataTypeConv2'
   *  Logic: '<S86>/AND3'
   *  RelationalOperator: '<S86>/Equal1'
   */
  if (rtb_NotEqual && ((int8_T)rtb_SignPreIntegrator == (int8_T)rtb_UnitDelay2))
  {
    rtb_IProdOut = 0.0F;
  }

  /* End of Switch: '<S86>/Switch' */

  /* Update for DiscreteIntegrator: '<S95>/Integrator' */
  rtDW.Integrator_DSTATE_d += 0.0001F * rtb_IProdOut;
}

/* Output and update for atomic system: '<S33>/Inverse_Park_Transform' */
void Inverse_Park_Transform(void)
{
  /* Sum: '<S39>/Add' incorporates:
   *  Product: '<S39>/Product1'
   *  Product: '<S39>/Product2'
   *  Sum: '<S39>/Add1'
   */
  V_alpha = Vd_voltage * rtDW.Cosine - Vq_voltage * rtDW.speed_hat;

  /* Sum: '<S39>/Add3' incorporates:
   *  Product: '<S39>/Product3'
   *  Product: '<S39>/Product4'
   *  Sum: '<S39>/Add2'
   */
  V_beta = Vd_voltage * rtDW.speed_hat + Vq_voltage * rtDW.Cosine;
}

/* Output and update for atomic system: '<S33>/Park_Transform' */
void Park_Transform(void)
{
  /* Sum: '<S43>/Add1' incorporates:
   *  Product: '<S43>/Product1'
   *  Product: '<S43>/Product2'
   */
  Id_measured = Ialpha * rtDW.Cosine + Ibeta * rtDW.speed_hat;

  /* Sum: '<S43>/Add2' incorporates:
   *  Product: '<S43>/Produc3t'
   *  Product: '<S43>/Product4'
   */
  Iq_measured = Ibeta * rtDW.Cosine - Ialpha * rtDW.speed_hat;
}

/* Output and update for atomic system: '<S33>/Q_Current_PI' */
void Q_Current_PI(void)
{
  real32_T Merge1_d;
  real32_T Merge_h;
  real32_T rtb_Add;
  real32_T rtb_Switch_k;

  /* Sum: '<S44>/Add2' */
  rtb_Switch_k = rtDW.Merge1 - Iq_measured;

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

/* Output and update for atomic system: '<S33>/SVPWM' */
void SVPWM(void)
{
  real32_T rtb_Add1_fq;
  real32_T rtb_Gain_a;
  real32_T rtb_IndexVector1;
  real32_T rtb_IndexVector_c;
  real32_T rtb_Saturation;

  /* Outputs for Atomic SubSystem: '<S45>/XYZ Caculate' */
  /* Outputs for Atomic SubSystem: '<S45>/N Sector  Caculate' */
  /* Gain: '<S124>/Gain' incorporates:
   *  Gain: '<S127>/Gain'
   */
  rtb_IndexVector1 = 1.73205078F * V_alpha;

  /* End of Outputs for SubSystem: '<S45>/XYZ Caculate' */

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
  /* End of Outputs for SubSystem: '<S45>/N Sector  Caculate' */

  /* Outputs for Atomic SubSystem: '<S45>/XYZ Caculate' */
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
   *  Constant: '<S33>/Constant4'
   */
  rtb_Add1_fq = 0.000173205073F / rtb_Add1_fq;

  /* End of Outputs for SubSystem: '<S45>/XYZ Caculate' */

  /* Outputs for Atomic SubSystem: '<S45>/T1 T2  Caculate' */
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
    /* Outputs for Atomic SubSystem: '<S45>/XYZ Caculate' */
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

    /* End of Outputs for SubSystem: '<S45>/XYZ Caculate' */
    break;

   case 2:
    /* Outputs for Atomic SubSystem: '<S45>/XYZ Caculate' */
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

    /* End of Outputs for SubSystem: '<S45>/XYZ Caculate' */
    break;

   case 3:
    /* Outputs for Atomic SubSystem: '<S45>/XYZ Caculate' */
    rtb_IndexVector_c = -((rtb_IndexVector1 - V_beta) * -0.5F * rtb_Add1_fq);

    /* MultiPortSwitch: '<S125>/Index Vector1' incorporates:
     *  Gain: '<S125>/Gain2'
     *  Gain: '<S127>/Gain1'
     *  Product: '<S127>/Product'
     *  Product: '<S127>/Product2'
     *  Sum: '<S127>/Add1'
     */
    rtb_Gain_a = V_beta * rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S45>/XYZ Caculate' */
    break;

   case 4:
    /* Outputs for Atomic SubSystem: '<S45>/XYZ Caculate' */
    rtb_IndexVector_c = -(V_beta * rtb_Add1_fq);

    /* MultiPortSwitch: '<S125>/Index Vector1' incorporates:
     *  Gain: '<S125>/Gain'
     *  Gain: '<S127>/Gain1'
     *  Product: '<S127>/Product'
     *  Product: '<S127>/Product2'
     *  Sum: '<S127>/Add1'
     */
    rtb_Gain_a = (rtb_IndexVector1 - V_beta) * -0.5F * rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S45>/XYZ Caculate' */
    break;

   case 5:
    /* Outputs for Atomic SubSystem: '<S45>/XYZ Caculate' */
    rtb_IndexVector_c = V_beta * rtb_Add1_fq;

    /* MultiPortSwitch: '<S125>/Index Vector1' incorporates:
     *  Gain: '<S125>/Gain1'
     *  Gain: '<S127>/Gain2'
     *  Product: '<S127>/Product'
     *  Product: '<S127>/Product1'
     *  Sum: '<S127>/Add2'
     */
    rtb_Gain_a = -(((0.0F - V_beta) - rtb_IndexVector1) * -0.5F * rtb_Add1_fq);

    /* End of Outputs for SubSystem: '<S45>/XYZ Caculate' */
    break;

   default:
    /* Outputs for Atomic SubSystem: '<S45>/XYZ Caculate' */
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

    /* End of Outputs for SubSystem: '<S45>/XYZ Caculate' */
    break;
  }

  /* End of MultiPortSwitch: '<S125>/Index Vector' */

  /* Sum: '<S125>/Add' */
  rtb_Add1_fq = rtb_IndexVector_c + rtb_Gain_a;

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S33>/Constant4'
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
  /* End of Outputs for SubSystem: '<S45>/T1 T2  Caculate' */

  /* Outputs for Atomic SubSystem: '<S45>/Tcm calculate' */
  /* Gain: '<S126>/Gain2' incorporates:
   *  Constant: '<S33>/Constant4'
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
  /* End of Outputs for SubSystem: '<S45>/Tcm calculate' */

  /* If: '<S45>/If1' */
  if (rtDW.Merge1_a == 0) {
    /* Gain: '<S45>/Gain' */
    rtb_Saturation *= 8.399E+7F;

    /* Outputs for IfAction SubSystem: '<S45>/Enable_Motor' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    /* Saturate: '<S123>/Saturation' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S45>/Merge' */
      rtDW.Merge_c = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S45>/Merge' */
      rtDW.Merge_c = 1.0F;
    } else {
      /* Merge: '<S45>/Merge' */
      rtDW.Merge_c = rtb_Saturation;
    }

    /* End of Saturate: '<S123>/Saturation' */
    /* End of Outputs for SubSystem: '<S45>/Enable_Motor' */

    /* Gain: '<S45>/Gain2' */
    rtb_Saturation = 8.399E+7F * rtb_IndexVector1;

    /* Outputs for IfAction SubSystem: '<S45>/Enable_Motor' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    /* Saturate: '<S123>/Saturation1' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S45>/Merge1' */
      rtDW.Merge1_h = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S45>/Merge1' */
      rtDW.Merge1_h = 1.0F;
    } else {
      /* Merge: '<S45>/Merge1' */
      rtDW.Merge1_h = rtb_Saturation;
    }

    /* End of Saturate: '<S123>/Saturation1' */
    /* End of Outputs for SubSystem: '<S45>/Enable_Motor' */

    /* Gain: '<S45>/Gain3' */
    rtb_Saturation = 8.399E+7F * rtb_Add1_fq;

    /* Outputs for IfAction SubSystem: '<S45>/Enable_Motor' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    /* Saturate: '<S123>/Saturation2' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S45>/Merge2' */
      rtDW.Merge2_d = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S45>/Merge2' */
      rtDW.Merge2_d = 1.0F;
    } else {
      /* Merge: '<S45>/Merge2' */
      rtDW.Merge2_d = rtb_Saturation;
    }

    /* End of Saturate: '<S123>/Saturation2' */
    /* End of Outputs for SubSystem: '<S45>/Enable_Motor' */
  } else {
    if (rtDW.Merge1_a == 1) {
      /* Outputs for IfAction SubSystem: '<S45>/Disable_Motor' incorporates:
       *  ActionPort: '<S122>/Action Port'
       */
      /* Merge: '<S45>/Merge' incorporates:
       *  Constant: '<S122>/Constant'
       *  SignalConversion generated from: '<S122>/Out1'
       */
      rtDW.Merge_c = 0.0F;

      /* Merge: '<S45>/Merge1' incorporates:
       *  Constant: '<S122>/Constant1'
       *  SignalConversion generated from: '<S122>/Out2'
       */
      rtDW.Merge1_h = 0.0F;

      /* Merge: '<S45>/Merge2' incorporates:
       *  Constant: '<S122>/Constant2'
       *  SignalConversion generated from: '<S122>/Out3'
       */
      rtDW.Merge2_d = 0.0F;

      /* End of Outputs for SubSystem: '<S45>/Disable_Motor' */
    }
  }

  /* End of If: '<S45>/If1' */
}

/* Output and update for atomic system: '<S33>/Sine_Cosine' */
void Sine_Cosine_m(void)
{
  real32_T rtb_Saturation;
  uint32_T Cosine_tmp;

  /* Saturate: '<S46>/Saturation' */
  if (rtDW.Merge_g > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Merge_g < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Merge_g;
  }

  /* End of Saturate: '<S46>/Saturation' */

  /* Lookup_n-D: '<S46>/Cosine' incorporates:
   *  Lookup_n-D: '<S46>/Sine'
   *  Saturate: '<S46>/Saturation'
   */
  Cosine_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);
  rtDW.Cosine = rtConstP.pooled10[Cosine_tmp];

  /* Lookup_n-D: '<S46>/Sine' */
  rtDW.speed_hat = rtConstP.pooled12[Cosine_tmp];
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
  /* SystemInitialize for Atomic SubSystem: '<S33>/HIGH_SMO' */
  HIGH_SMO_Init();

  /* End of SystemInitialize for SubSystem: '<S33>/HIGH_SMO' */
}

/* Enable for atomic system: '<S5>/FOC' */
void FOC_Enable(void)
{
  /* Enable for Atomic SubSystem: '<S33>/HIGH_SMO' */
  HIGH_SMO_Enable();

  /* End of Enable for SubSystem: '<S33>/HIGH_SMO' */
}

/* Output and update for atomic system: '<S5>/FOC' */
void FOC(void)
{
  real32_T rtb_Add1_hc;
  uint8_T rtb_Motor_State;

  /* UnitDelay: '<S33>/Unit Delay1' */
  rtDW.UnitDelay1_c = rtDW.UnitDelay1_DSTATE_d;

  /* Chart: '<S33>/Chart' incorporates:
   *  Constant: '<S33>/Constant6'
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
           (OPL_Parameter.OPL_Time / 0.0001 - 1.0E-12)) && (rtDW.UnitDelay1_c >
           0.0F)) {
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

  /* End of Chart: '<S33>/Chart' */

  /* SwitchCase: '<S33>/Switch Case' incorporates:
   *  Constant: '<S33>/Constant2'
   *  Inport: '<S42>/OPL_Torque'
   *  Inport: '<S47>/In1'
   */
  switch (rtb_Motor_State) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S33>/OpenLoop' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    /* Merge: '<S33>/Merge2' incorporates:
     *  Constant: '<S42>/2pi2'
     *  DiscreteIntegrator: '<S42>/Discrete-Time Integrator1'
     *  Math: '<S42>/Mod2'
     *  SignalConversion generated from: '<S42>/Force_Angle'
     */
    rtDW.Merge2_f = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE, 6.28318548F);
    rtDW.Merge1 = OPL_Parameter.OPL_Torque;

    /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator1' incorporates:
     *  Constant: '<S33>/Constant2'
     *  DiscreteIntegrator: '<S42>/Discrete-Time Integrator2'
     *  Gain: '<S42>/We'
     *  Inport: '<S42>/OPL_Torque'
     */
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.209439516F *
      rtDW.DiscreteTimeIntegrator2_DSTATE * 0.0001F;

    /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator2' incorporates:
     *  Constant: '<S33>/Constant1'
     *  Constant: '<S33>/Constant3'
     *  Product: '<S42>/Product'
     */
    rtDW.DiscreteTimeIntegrator2_DSTATE += 1.0F / OPL_Parameter.OPL_Time *
      OPL_Parameter.OPL_Speed * 0.0001F;

    /* End of Outputs for SubSystem: '<S33>/OpenLoop' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S33>/Subsystem' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    rtDW.Merge1 = Iq_ref;

    /* Merge: '<S33>/Merge2' incorporates:
     *  Inport: '<S47>/In1'
     *  Inport: '<S47>/In2'
     *  UnitDelay: '<S33>/Unit Delay2'
     */
    rtDW.Merge2_f = rtDW.UnitDelay2_DSTATE_k;

    /* End of Outputs for SubSystem: '<S33>/Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S33>/Switch Case' */

  /* Outputs for Atomic SubSystem: '<S33>/Clarke_Transform' */
  Clarke_Transform();

  /* End of Outputs for SubSystem: '<S33>/Clarke_Transform' */

  /* If: '<S33>/If1' incorporates:
   *  Constant: '<S33>/Flux_Enable'
   *  Inport: '<S38>/Hall_Angle'
   *  Inport: '<S41>/Obs_Angle'
   */
  if (SMO_Parameter.SMO_Theta_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S33>/Obs_Angle' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    rtDW.Merge_g = rtDW.Merge2_f;

    /* End of Outputs for SubSystem: '<S33>/Obs_Angle' */
  } else {
    if (SMO_Parameter.SMO_Theta_Enable == 0) {
      /* Outputs for IfAction SubSystem: '<S33>/Hall_Angle' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      rtDW.Merge_g = Hall_Angle;

      /* End of Outputs for SubSystem: '<S33>/Hall_Angle' */
    }
  }

  /* End of If: '<S33>/If1' */

  /* Outputs for Atomic SubSystem: '<S33>/Sine_Cosine' */
  Sine_Cosine_m();

  /* End of Outputs for SubSystem: '<S33>/Sine_Cosine' */

  /* Outputs for Atomic SubSystem: '<S33>/Park_Transform' */
  Park_Transform();

  /* End of Outputs for SubSystem: '<S33>/Park_Transform' */

  /* Outputs for Atomic SubSystem: '<S33>/D_Current_PI' */
  D_Current_PI();

  /* End of Outputs for SubSystem: '<S33>/D_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S33>/Q_Current_PI' */
  Q_Current_PI();

  /* End of Outputs for SubSystem: '<S33>/Q_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S33>/Inverse_Park_Transform' */
  Inverse_Park_Transform();

  /* End of Outputs for SubSystem: '<S33>/Inverse_Park_Transform' */

  /* Outputs for Atomic SubSystem: '<S33>/HIGH_SMO' */
  HIGH_SMO();

  /* End of Outputs for SubSystem: '<S33>/HIGH_SMO' */

  /* Sum: '<S40>/Add1' incorporates:
   *  Constant: '<S40>/Constant1'
   *  Gain: '<S33>/Gain1'
   *  Product: '<S40>/Divide1'
   *  Sum: '<S40>/Add'
   *  UnitDelay: '<S40>/Unit Delay'
   */
  rtb_Add1_hc = (4.77464819F * rtDW.speed_hat - rtDW.UnitDelay_DSTATE_n) *
    SpeedFilter_Fn + rtDW.UnitDelay_DSTATE_n;

  /* Outputs for Atomic SubSystem: '<S33>/SVPWM' */
  SVPWM();

  /* End of Outputs for SubSystem: '<S33>/SVPWM' */

  /* Update for UnitDelay: '<S33>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE_d = rtb_Add1_hc;

  /* Update for UnitDelay: '<S33>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE_k = rtDW.UnitDelay;

  /* Update for UnitDelay: '<S40>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_n = rtb_Add1_hc;
}

/* System initialize for function-call system: '<S2>/FOC_Control_100us' */
void FOC_Control_100us_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S5>/FOC' */
  FOC_Init();

  /* End of SystemInitialize for SubSystem: '<S5>/FOC' */
}

/* Enable for function-call system: '<S2>/FOC_Control_100us' */
void FOC_Control_100us_Enable(void)
{
  /* Enable for Atomic SubSystem: '<S5>/FOC' */
  FOC_Enable();

  /* End of Enable for SubSystem: '<S5>/FOC' */
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
