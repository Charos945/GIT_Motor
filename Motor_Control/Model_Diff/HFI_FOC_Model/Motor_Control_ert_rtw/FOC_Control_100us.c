/*
 * File: FOC_Control_100us.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Nov 19 17:54:27 2021
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

/* Output and update for atomic system: '<S36>/Angle_set' */
void Angle_set(void)
{
  /* If: '<S37>/If1' incorporates:
   *  Constant: '<S37>/HFI_AngleEnable'
   */
  if (HFI_Parameter.HFI_Fuc_Enalbe == 1) {
    /* Outputs for IfAction SubSystem: '<S37>/Subsystem' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    /* If: '<S48>/If1' */
    if (rtDW.RUN_state == 3) {
      /* Outputs for IfAction SubSystem: '<S48>/Subsystem1' incorporates:
       *  ActionPort: '<S50>/Action Port'
       */
      /* Merge: '<S36>/Merge1' incorporates:
       *  Inport: '<S50>/HFI_Angle'
       */
      rtDW.Merge1 = rtDW.Merge2_i;

      /* End of Outputs for SubSystem: '<S48>/Subsystem1' */
    } else {
      if (rtDW.RUN_state < 3) {
        /* Outputs for IfAction SubSystem: '<S48>/Subsystem2' incorporates:
         *  ActionPort: '<S51>/Action Port'
         */
        /* Merge: '<S36>/Merge1' incorporates:
         *  Inport: '<S51>/IPD_Angle'
         */
        rtDW.Merge1 = rtDW.IPD_angle;

        /* End of Outputs for SubSystem: '<S48>/Subsystem2' */
      }
    }

    /* End of If: '<S48>/If1' */
    /* End of Outputs for SubSystem: '<S37>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S37>/Subsystem1' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    /* Merge: '<S36>/Merge1' incorporates:
     *  Inport: '<S49>/Reso_angle'
     */
    rtDW.Merge1 = Hall_Angle;

    /* End of Outputs for SubSystem: '<S37>/Subsystem1' */
  }

  /* End of If: '<S37>/If1' */
}

/* Output and update for atomic system: '<S36>/Clarke_Transform' */
void Clarke_Transform(void)
{
  /* Outputs for Atomic SubSystem: '<S38>/Clark1' */
  /* Gain: '<S52>/Gain2' incorporates:
   *  Gain: '<S52>/Gain'
   *  Gain: '<S52>/Gain1'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S52>/Add'
   */
  Ialpha = ((rtU.Phase_CurrentABC[0] - 0.5F * rtU.Phase_CurrentABC[1]) - 0.5F *
            rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* Gain: '<S52>/Gain5' incorporates:
   *  Gain: '<S52>/Gain3'
   *  Gain: '<S52>/Gain4'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S52>/Add1'
   */
  Ibeta = (0.866025388F * rtU.Phase_CurrentABC[1] - 0.866025388F *
           rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* End of Outputs for SubSystem: '<S38>/Clark1' */
}

/*
 * Output and update for action system:
 *    '<S53>/Over_M'
 *    '<S173>/Over_M'
 */
void Over_M(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S55>/Gain' */
  *rty_Out1 = 0.666666687F * rtu_Bus_voltage;

  /* Gain: '<S55>/Gain1' */
  *rty_Out2 = -0.666666687F * rtu_Bus_voltage;
}

/*
 * Output and update for action system:
 *    '<S53>/Normal'
 *    '<S173>/Normal'
 */
void Normal(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S54>/Gain' */
  *rty_Out1 = 0.577350259F * rtu_Bus_voltage;

  /* Gain: '<S54>/Gain1' */
  *rty_Out2 = -0.577350259F * rtu_Bus_voltage;
}

/* Output and update for atomic system: '<S36>/D_Current_PI' */
void D_Current_PI(void)
{
  real32_T Merge1_b;
  real32_T Merge_a;
  real32_T rtb_Add;
  real32_T rtb_Switch_h;

  /* Sum: '<S39>/Add2' */
  rtb_Switch_h = rtDW.Add - Id_measured;

  /* DiscreteIntegrator: '<S53>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_p != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE_a = 0.0F;
  }

  /* Sum: '<S53>/Add' incorporates:
   *  Constant: '<S53>/Kp'
   *  DiscreteIntegrator: '<S53>/Discrete-Time Integrator'
   *  Product: '<S53>/Product'
   */
  rtb_Add = PI_Parameter.ID_Kp * rtb_Switch_h +
    rtDW.DiscreteTimeIntegrator_DSTATE_a;

  /* If: '<S53>/If1' incorporates:
   *  Constant: '<S53>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S53>/Over_M' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S53>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S53>/Normal' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S53>/Normal' */
  }

  /* End of If: '<S53>/If1' */

  /* Switch: '<S56>/Switch2' incorporates:
   *  RelationalOperator: '<S56>/LowerRelop1'
   *  RelationalOperator: '<S56>/UpperRelop'
   *  Switch: '<S56>/Switch'
   */
  if (rtb_Add > Merge_a) {
    /* Switch: '<S56>/Switch2' */
    Vd_voltage = Merge_a;
  } else if (rtb_Add < Merge1_b) {
    /* Switch: '<S56>/Switch' incorporates:
     *  Switch: '<S56>/Switch2'
     */
    Vd_voltage = Merge1_b;
  } else {
    /* Switch: '<S56>/Switch2' incorporates:
     *  Switch: '<S56>/Switch'
     */
    Vd_voltage = rtb_Add;
  }

  /* End of Switch: '<S56>/Switch2' */

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S53>/Cons'
   *  UnitDelay: '<S53>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_k) {
    rtb_Switch_h = 0.0F;
  }

  /* End of Switch: '<S53>/Switch' */

  /* Update for DiscreteIntegrator: '<S53>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S53>/Ki'
   *  Product: '<S53>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += PI_Parameter.ID_Ki * rtb_Switch_h *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_p = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S53>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S53>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_k = (rtb_Add == Vd_voltage);
}

/* Output and update for atomic system: '<S36>/Inverse_Park_Transform' */
void Inverse_Park_Transform(void)
{
  /* Sum: '<S41>/Add1' incorporates:
   *  Product: '<S41>/Product1'
   *  Product: '<S41>/Product2'
   */
  V_alpha = rtDW.Add * rtDW.Cosine - Vq_voltage * rtDW.Sine;

  /* Sum: '<S41>/Add2' incorporates:
   *  Product: '<S41>/Product3'
   *  Product: '<S41>/Product4'
   */
  V_beta = rtDW.Add * rtDW.Sine + Vq_voltage * rtDW.Cosine;
}

/* Output and update for atomic system: '<S36>/Park_Transform' */
void Park_Transform(void)
{
  /* Sum: '<S42>/Add1' incorporates:
   *  Product: '<S42>/Product1'
   *  Product: '<S42>/Product2'
   */
  Id_measured = Ialpha * rtDW.Cosine + Ibeta * rtDW.Sine;

  /* Sum: '<S42>/Add2' incorporates:
   *  Product: '<S42>/Produc3t'
   *  Product: '<S42>/Product4'
   */
  Iq_measured = Ibeta * rtDW.Cosine - Ialpha * rtDW.Sine;
}

/* Output and update for atomic system: '<S36>/Q_Current_PI' */
void Q_Current_PI(void)
{
  real32_T Merge1_d;
  real32_T Merge_h;
  real32_T rtb_Add;
  real32_T rtb_Switch_k;

  /* Sum: '<S43>/Add2' */
  rtb_Switch_k = rtDW.Merge1_n - Iq_measured;

  /* DiscreteIntegrator: '<S173>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE_i = 0.0F;
  }

  /* Sum: '<S173>/Add' incorporates:
   *  Constant: '<S173>/Kp'
   *  DiscreteIntegrator: '<S173>/Discrete-Time Integrator'
   *  Product: '<S173>/Product'
   */
  rtb_Add = PI_Parameter.IQ_Kp * rtb_Switch_k +
    rtDW.DiscreteTimeIntegrator_DSTATE_i;

  /* If: '<S173>/If1' incorporates:
   *  Constant: '<S173>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S173>/Over_M' incorporates:
     *  ActionPort: '<S175>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_h, &Merge1_d);

    /* End of Outputs for SubSystem: '<S173>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S173>/Normal' incorporates:
     *  ActionPort: '<S174>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_h, &Merge1_d);

    /* End of Outputs for SubSystem: '<S173>/Normal' */
  }

  /* End of If: '<S173>/If1' */

  /* Switch: '<S176>/Switch2' incorporates:
   *  RelationalOperator: '<S176>/LowerRelop1'
   *  RelationalOperator: '<S176>/UpperRelop'
   *  Switch: '<S176>/Switch'
   */
  if (rtb_Add > Merge_h) {
    Vq_voltage = Merge_h;
  } else if (rtb_Add < Merge1_d) {
    /* Switch: '<S176>/Switch' */
    Vq_voltage = Merge1_d;
  } else {
    Vq_voltage = rtb_Add;
  }

  /* End of Switch: '<S176>/Switch2' */

  /* Switch: '<S173>/Switch' incorporates:
   *  Constant: '<S173>/Cons'
   *  UnitDelay: '<S173>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_i) {
    rtb_Switch_k = 0.0F;
  }

  /* End of Switch: '<S173>/Switch' */

  /* Update for DiscreteIntegrator: '<S173>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S173>/Ki'
   *  Product: '<S173>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_i += PI_Parameter.IQ_Ki * rtb_Switch_k *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S173>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S173>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_i = (rtb_Add == Vq_voltage);
}

/* Output and update for atomic system: '<S36>/SVPWM' */
void SVPWM(void)
{
  real32_T rtb_Add1_fq;
  real32_T rtb_Gain_a;
  real32_T rtb_IndexVector1;
  real32_T rtb_IndexVector_c;
  real32_T rtb_Saturation;

  /* Outputs for Atomic SubSystem: '<S44>/XYZ Caculate' */
  /* Outputs for Atomic SubSystem: '<S44>/N Sector  Caculate' */
  /* Gain: '<S179>/Gain' incorporates:
   *  Gain: '<S182>/Gain'
   */
  rtb_IndexVector1 = 1.73205078F * rtDW.Merge_g;

  /* End of Outputs for SubSystem: '<S44>/XYZ Caculate' */

  /* Saturate: '<S179>/Saturation' incorporates:
   *  Gain: '<S179>/Gain'
   *  Gain: '<S179>/Gain1'
   *  Gain: '<S179>/Gain2'
   *  Sum: '<S179>/Add'
   *  Sum: '<S179>/Add1'
   *  Sum: '<S179>/Add2'
   *  Switch: '<S179>/Switch'
   *  Switch: '<S179>/Switch1'
   *  Switch: '<S179>/Switch2'
   */
  rtb_Saturation = (real32_T)((((rtb_IndexVector1 - rtDW.Merge1_i >= 0.0F) << 1)
    + (rtDW.Merge1_i >= 0.0F)) + (((0.0F - rtDW.Merge1_i) - rtb_IndexVector1 >=
    0.0F) << 2));
  if (rtb_Saturation > 6.0F) {
    rtb_Saturation = 6.0F;
  } else {
    if (rtb_Saturation < 1.0F) {
      rtb_Saturation = 1.0F;
    }
  }

  /* End of Saturate: '<S179>/Saturation' */
  /* End of Outputs for SubSystem: '<S44>/N Sector  Caculate' */

  /* Outputs for Atomic SubSystem: '<S44>/XYZ Caculate' */
  /* Saturate: '<S182>/Saturation' incorporates:
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (rtU.Bus_Voltage > 1200.0F) {
    rtb_Add1_fq = 1200.0F;
  } else if (rtU.Bus_Voltage < 0.0001F) {
    rtb_Add1_fq = 0.0001F;
  } else {
    rtb_Add1_fq = rtU.Bus_Voltage;
  }

  /* End of Saturate: '<S182>/Saturation' */

  /* Product: '<S182>/Divide' incorporates:
   *  Constant: '<S182>/Constant'
   *  Constant: '<S36>/Constant4'
   */
  rtb_Add1_fq = 0.000173205073F / rtb_Add1_fq;

  /* End of Outputs for SubSystem: '<S44>/XYZ Caculate' */

  /* Outputs for Atomic SubSystem: '<S44>/T1 T2  Caculate' */
  /* MultiPortSwitch: '<S180>/Index Vector' incorporates:
   *  Gain: '<S180>/Gain'
   *  Gain: '<S180>/Gain1'
   *  Gain: '<S180>/Gain2'
   *  Gain: '<S182>/Gain1'
   *  Gain: '<S182>/Gain2'
   *  Product: '<S182>/Product'
   *  Product: '<S182>/Product1'
   *  Product: '<S182>/Product2'
   *  Sum: '<S182>/Add1'
   *  Sum: '<S182>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    /* Outputs for Atomic SubSystem: '<S44>/XYZ Caculate' */
    rtb_IndexVector_c = (rtb_IndexVector1 - rtDW.Merge1_i) * -0.5F * rtb_Add1_fq;

    /* MultiPortSwitch: '<S180>/Index Vector1' incorporates:
     *  Gain: '<S182>/Gain1'
     *  Gain: '<S182>/Gain2'
     *  Product: '<S182>/Product1'
     *  Product: '<S182>/Product2'
     *  Sum: '<S182>/Add1'
     *  Sum: '<S182>/Add2'
     */
    rtb_Gain_a = ((0.0F - rtDW.Merge1_i) - rtb_IndexVector1) * -0.5F *
      rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S44>/XYZ Caculate' */
    break;

   case 2:
    /* Outputs for Atomic SubSystem: '<S44>/XYZ Caculate' */
    rtb_IndexVector_c = ((0.0F - rtDW.Merge1_i) - rtb_IndexVector1) * -0.5F *
      rtb_Add1_fq;

    /* MultiPortSwitch: '<S180>/Index Vector1' incorporates:
     *  Gain: '<S180>/Gain'
     *  Gain: '<S182>/Gain2'
     *  Product: '<S182>/Product'
     *  Product: '<S182>/Product1'
     *  Sum: '<S182>/Add2'
     */
    rtb_Gain_a = -(rtDW.Merge1_i * rtb_Add1_fq);

    /* End of Outputs for SubSystem: '<S44>/XYZ Caculate' */
    break;

   case 3:
    /* Outputs for Atomic SubSystem: '<S44>/XYZ Caculate' */
    rtb_IndexVector_c = -((rtb_IndexVector1 - rtDW.Merge1_i) * -0.5F *
                          rtb_Add1_fq);

    /* MultiPortSwitch: '<S180>/Index Vector1' incorporates:
     *  Gain: '<S180>/Gain2'
     *  Gain: '<S182>/Gain1'
     *  Product: '<S182>/Product'
     *  Product: '<S182>/Product2'
     *  Sum: '<S182>/Add1'
     */
    rtb_Gain_a = rtDW.Merge1_i * rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S44>/XYZ Caculate' */
    break;

   case 4:
    /* Outputs for Atomic SubSystem: '<S44>/XYZ Caculate' */
    rtb_IndexVector_c = -(rtDW.Merge1_i * rtb_Add1_fq);

    /* MultiPortSwitch: '<S180>/Index Vector1' incorporates:
     *  Gain: '<S180>/Gain'
     *  Gain: '<S182>/Gain1'
     *  Product: '<S182>/Product'
     *  Product: '<S182>/Product2'
     *  Sum: '<S182>/Add1'
     */
    rtb_Gain_a = (rtb_IndexVector1 - rtDW.Merge1_i) * -0.5F * rtb_Add1_fq;

    /* End of Outputs for SubSystem: '<S44>/XYZ Caculate' */
    break;

   case 5:
    /* Outputs for Atomic SubSystem: '<S44>/XYZ Caculate' */
    rtb_IndexVector_c = rtDW.Merge1_i * rtb_Add1_fq;

    /* MultiPortSwitch: '<S180>/Index Vector1' incorporates:
     *  Gain: '<S180>/Gain1'
     *  Gain: '<S182>/Gain2'
     *  Product: '<S182>/Product'
     *  Product: '<S182>/Product1'
     *  Sum: '<S182>/Add2'
     */
    rtb_Gain_a = -(((0.0F - rtDW.Merge1_i) - rtb_IndexVector1) * -0.5F *
                   rtb_Add1_fq);

    /* End of Outputs for SubSystem: '<S44>/XYZ Caculate' */
    break;

   default:
    /* Outputs for Atomic SubSystem: '<S44>/XYZ Caculate' */
    rtb_IndexVector_c = -(((0.0F - rtDW.Merge1_i) - rtb_IndexVector1) * -0.5F *
                          rtb_Add1_fq);

    /* MultiPortSwitch: '<S180>/Index Vector1' incorporates:
     *  Gain: '<S180>/Gain1'
     *  Gain: '<S180>/Gain2'
     *  Gain: '<S182>/Gain1'
     *  Gain: '<S182>/Gain2'
     *  Product: '<S182>/Product1'
     *  Product: '<S182>/Product2'
     *  Sum: '<S182>/Add1'
     *  Sum: '<S182>/Add2'
     */
    rtb_Gain_a = -((rtb_IndexVector1 - rtDW.Merge1_i) * -0.5F * rtb_Add1_fq);

    /* End of Outputs for SubSystem: '<S44>/XYZ Caculate' */
    break;
  }

  /* End of MultiPortSwitch: '<S180>/Index Vector' */

  /* Sum: '<S180>/Add' */
  rtb_Add1_fq = rtb_IndexVector_c + rtb_Gain_a;

  /* Switch: '<S180>/Switch' incorporates:
   *  Constant: '<S36>/Constant4'
   *  Product: '<S180>/Divide'
   *  Product: '<S180>/Divide1'
   *  Sum: '<S180>/Add1'
   *  Switch: '<S180>/Switch2'
   */
  if (!(0.0001F - rtb_Add1_fq > 0.0F)) {
    rtb_IndexVector_c = rtb_IndexVector_c * 0.0001F / rtb_Add1_fq;
    rtb_Gain_a *= 1.0F / rtb_Add1_fq * 0.0001F;
  }

  /* End of Switch: '<S180>/Switch' */
  /* End of Outputs for SubSystem: '<S44>/T1 T2  Caculate' */

  /* Outputs for Atomic SubSystem: '<S44>/Tcm calculate' */
  /* Gain: '<S181>/Gain2' incorporates:
   *  Constant: '<S36>/Constant4'
   *  Sum: '<S181>/Add'
   */
  rtb_Add1_fq = ((0.0001F - rtb_IndexVector_c) - rtb_Gain_a) * 0.25F;

  /* Sum: '<S181>/Add1' incorporates:
   *  Gain: '<S181>/Gain'
   */
  rtb_IndexVector_c = 0.5F * rtb_IndexVector_c + rtb_Add1_fq;

  /* MultiPortSwitch: '<S181>/Index Vector' incorporates:
   *  Gain: '<S181>/Gain1'
   *  Sum: '<S181>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S181>/Index Vector1' */
    rtb_IndexVector1 = rtb_Add1_fq;

    /* MultiPortSwitch: '<S181>/Index Vector2' incorporates:
     *  Gain: '<S181>/Gain1'
     *  Sum: '<S181>/Add2'
     */
    rtb_Add1_fq = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 2:
    rtb_Saturation = rtb_Add1_fq;

    /* MultiPortSwitch: '<S181>/Index Vector1' incorporates:
     *  Gain: '<S181>/Gain1'
     *  Sum: '<S181>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S181>/Index Vector2' */
    rtb_Add1_fq = rtb_IndexVector_c;
    break;

   case 3:
    rtb_Saturation = rtb_Add1_fq;

    /* MultiPortSwitch: '<S181>/Index Vector1' */
    rtb_IndexVector1 = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S181>/Index Vector2' incorporates:
     *  Gain: '<S181>/Gain1'
     *  Sum: '<S181>/Add2'
     */
    rtb_Add1_fq = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 4:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S181>/Index Vector1' incorporates:
     *  Gain: '<S181>/Gain1'
     *  Sum: '<S181>/Add2'
     */
    rtb_IndexVector1 = rtb_IndexVector_c;
    break;

   case 5:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S181>/Index Vector1' incorporates:
     *  Gain: '<S181>/Gain1'
     *  Sum: '<S181>/Add2'
     */
    rtb_IndexVector1 = rtb_Add1_fq;

    /* MultiPortSwitch: '<S181>/Index Vector2' */
    rtb_Add1_fq = rtb_IndexVector_c;
    break;

   default:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S181>/Index Vector1' incorporates:
     *  Gain: '<S181>/Gain1'
     *  Sum: '<S181>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;
  }

  /* End of MultiPortSwitch: '<S181>/Index Vector' */
  /* End of Outputs for SubSystem: '<S44>/Tcm calculate' */

  /* If: '<S44>/If1' */
  if (rtDW.Merge1_a == 0) {
    /* Gain: '<S44>/Gain' */
    rtb_Saturation *= 8.399E+7F;

    /* Outputs for IfAction SubSystem: '<S44>/Enable_Motor' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    /* Saturate: '<S178>/Saturation' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S44>/Merge' */
      rtDW.Merge_c = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S44>/Merge' */
      rtDW.Merge_c = 1.0F;
    } else {
      /* Merge: '<S44>/Merge' */
      rtDW.Merge_c = rtb_Saturation;
    }

    /* End of Saturate: '<S178>/Saturation' */
    /* End of Outputs for SubSystem: '<S44>/Enable_Motor' */

    /* Gain: '<S44>/Gain2' */
    rtb_Saturation = 8.399E+7F * rtb_IndexVector1;

    /* Outputs for IfAction SubSystem: '<S44>/Enable_Motor' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    /* Saturate: '<S178>/Saturation1' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S44>/Merge1' */
      rtDW.Merge1_h = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S44>/Merge1' */
      rtDW.Merge1_h = 1.0F;
    } else {
      /* Merge: '<S44>/Merge1' */
      rtDW.Merge1_h = rtb_Saturation;
    }

    /* End of Saturate: '<S178>/Saturation1' */
    /* End of Outputs for SubSystem: '<S44>/Enable_Motor' */

    /* Gain: '<S44>/Gain3' */
    rtb_Saturation = 8.399E+7F * rtb_Add1_fq;

    /* Outputs for IfAction SubSystem: '<S44>/Enable_Motor' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    /* Saturate: '<S178>/Saturation2' */
    if (rtb_Saturation > 4199.0F) {
      /* Merge: '<S44>/Merge2' */
      rtDW.Merge2_d = 4199.0F;
    } else if (rtb_Saturation < 1.0F) {
      /* Merge: '<S44>/Merge2' */
      rtDW.Merge2_d = 1.0F;
    } else {
      /* Merge: '<S44>/Merge2' */
      rtDW.Merge2_d = rtb_Saturation;
    }

    /* End of Saturate: '<S178>/Saturation2' */
    /* End of Outputs for SubSystem: '<S44>/Enable_Motor' */
  } else {
    if (rtDW.Merge1_a == 1) {
      /* Outputs for IfAction SubSystem: '<S44>/Disable_Motor' incorporates:
       *  ActionPort: '<S177>/Action Port'
       */
      /* Merge: '<S44>/Merge' incorporates:
       *  Constant: '<S177>/Constant'
       *  SignalConversion generated from: '<S177>/Out1'
       */
      rtDW.Merge_c = 0.0F;

      /* Merge: '<S44>/Merge1' incorporates:
       *  Constant: '<S177>/Constant1'
       *  SignalConversion generated from: '<S177>/Out2'
       */
      rtDW.Merge1_h = 0.0F;

      /* Merge: '<S44>/Merge2' incorporates:
       *  Constant: '<S177>/Constant2'
       *  SignalConversion generated from: '<S177>/Out3'
       */
      rtDW.Merge2_d = 0.0F;

      /* End of Outputs for SubSystem: '<S44>/Disable_Motor' */
    }
  }

  /* End of If: '<S44>/If1' */
}

/* Output and update for action system: '<S45>/Set_Idq' */
void Set_Idq(void)
{
  /* Inport: '<S183>/Id_Command' incorporates:
   *  Constant: '<S45>/Constant2'
   */
  rtDW.Add = 0.0F;

  /* Inport: '<S183>/Iq_Command' incorporates:
   *  Constant: '<S45>/Constant1'
   */
  rtDW.Merge1_n = 0.0F;
}

/* Output and update for action system: '<S45>/Set_Idq1' */
void Set_Idq1(void)
{
  /* Inport: '<S184>/Id_Command' */
  rtDW.Add = Id_ref;

  /* Inport: '<S184>/Iq_Command' */
  rtDW.Merge1_n = Iq_ref;
}

/* Output and update for atomic system: '<S36>/Set_Idq' */
void Set_Idq_p(void)
{
  /* If: '<S45>/If1' */
  if ((rtDW.RUN_state == 2) || (rtDW.RUN_state == 1)) {
    /* Outputs for IfAction SubSystem: '<S45>/Set_Idq' incorporates:
     *  ActionPort: '<S183>/Action Port'
     */
    Set_Idq();

    /* End of Outputs for SubSystem: '<S45>/Set_Idq' */
  } else {
    /* Outputs for IfAction SubSystem: '<S45>/Set_Idq1' incorporates:
     *  ActionPort: '<S184>/Action Port'
     */
    Set_Idq1();

    /* End of Outputs for SubSystem: '<S45>/Set_Idq1' */
  }

  /* End of If: '<S45>/If1' */
}

/* Output and update for atomic system: '<S36>/Sine_Cosine' */
void Sine_Cosine_m(void)
{
  real32_T rtb_Saturation;
  uint32_T Cosine_tmp;

  /* Saturate: '<S46>/Saturation' */
  if (rtDW.Merge1 > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Merge1 < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Merge1;
  }

  /* End of Saturate: '<S46>/Saturation' */

  /* Lookup_n-D: '<S46>/Cosine' incorporates:
   *  Lookup_n-D: '<S46>/Sine'
   *  Saturate: '<S46>/Saturation'
   */
  Cosine_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);
  rtDW.Cosine = rtConstP.pooled18[Cosine_tmp];

  /* Lookup_n-D: '<S46>/Sine' */
  rtDW.Sine = rtConstP.pooled14[Cosine_tmp];
}

/* System initialize for atomic system: '<S5>/FOC' */
void FOC_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S36>/HF_Observer' */
  HF_Observer_Init();

  /* End of SystemInitialize for SubSystem: '<S36>/HF_Observer' */
}

/* Output and update for atomic system: '<S5>/FOC' */
void FOC(void)
{
  /* Outputs for Atomic SubSystem: '<S36>/Clarke_Transform' */
  Clarke_Transform();

  /* End of Outputs for SubSystem: '<S36>/Clarke_Transform' */

  /* Outputs for Atomic SubSystem: '<S36>/HF_Observer' */
  HF_Observer();

  /* End of Outputs for SubSystem: '<S36>/HF_Observer' */

  /* Outputs for Atomic SubSystem: '<S36>/Set_Idq' */
  Set_Idq_p();

  /* End of Outputs for SubSystem: '<S36>/Set_Idq' */

  /* Outputs for Atomic SubSystem: '<S36>/Angle_set' */
  Angle_set();

  /* End of Outputs for SubSystem: '<S36>/Angle_set' */

  /* Outputs for Atomic SubSystem: '<S36>/Sine_Cosine' */
  Sine_Cosine_m();

  /* End of Outputs for SubSystem: '<S36>/Sine_Cosine' */

  /* Outputs for Atomic SubSystem: '<S36>/Park_Transform' */
  Park_Transform();

  /* End of Outputs for SubSystem: '<S36>/Park_Transform' */

  /* Outputs for Atomic SubSystem: '<S36>/D_Current_PI' */
  D_Current_PI();

  /* End of Outputs for SubSystem: '<S36>/D_Current_PI' */

  /* Sum: '<S36>/Add' */
  rtDW.Add = rtDW.DataTypeConversion + Vd_voltage;

  /* Outputs for Atomic SubSystem: '<S36>/Q_Current_PI' */
  Q_Current_PI();

  /* End of Outputs for SubSystem: '<S36>/Q_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S36>/Inverse_Park_Transform' */
  Inverse_Park_Transform();

  /* End of Outputs for SubSystem: '<S36>/Inverse_Park_Transform' */

  /* If: '<S47>/If1' incorporates:
   *  Inport: '<S185>/In1'
   *  Inport: '<S185>/In2'
   *  Inport: '<S186>/In1'
   *  Inport: '<S186>/In2'
   */
  if ((rtDW.HFI_state < 3) && (rtDW.HFI_state > 0)) {
    /* Outputs for IfAction SubSystem: '<S47>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S186>/Action Port'
     */
    rtDW.Merge_g = rtDW.Merge_o;
    rtDW.Merge1_i = rtDW.Merge1_dq;

    /* End of Outputs for SubSystem: '<S47>/If Action Subsystem2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S47>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S185>/Action Port'
     */
    rtDW.Merge_g = V_alpha;
    rtDW.Merge1_i = V_beta;

    /* End of Outputs for SubSystem: '<S47>/If Action Subsystem1' */
  }

  /* End of If: '<S47>/If1' */

  /* Outputs for Atomic SubSystem: '<S36>/SVPWM' */
  SVPWM();

  /* End of Outputs for SubSystem: '<S36>/SVPWM' */

  /* Update for Atomic SubSystem: '<S36>/HF_Observer' */
  HF_Observer_Update();

  /* End of Update for SubSystem: '<S36>/HF_Observer' */
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
