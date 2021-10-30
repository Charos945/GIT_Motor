/*
 * File: FOC_Control_100us.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Oct 29 16:39:03 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "FOC_Control_100us.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Output and update for atomic system: '<S15>/Clarke_Transform' */
void Clarke_Transform(void)
{
  /* Outputs for Atomic SubSystem: '<S16>/Clark1' */
  /* Gain: '<S24>/Gain2' incorporates:
   *  Gain: '<S24>/Gain'
   *  Gain: '<S24>/Gain1'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S24>/Add'
   */
  Ialpha = ((rtU.Phase_CurrentABC[0] - 0.5F * rtU.Phase_CurrentABC[1]) - 0.5F *
            rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* Gain: '<S24>/Gain5' incorporates:
   *  Gain: '<S24>/Gain3'
   *  Gain: '<S24>/Gain4'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S24>/Add1'
   */
  Ibeta = (0.866025388F * rtU.Phase_CurrentABC[1] - 0.866025388F *
           rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* End of Outputs for SubSystem: '<S16>/Clark1' */
}

/* Output and update for atomic system: '<S15>/DT_Compensation' */
void DT_Compensation(void)
{
  real32_T rtb_Add1_j;
  real32_T rtb_Add1_n;
  real32_T rtb_Fcn;
  real32_T rtb_Itheta2;

  /* Outputs for Enabled SubSystem: '<S17>/DT_Compensation' incorporates:
   *  EnablePort: '<S25>/Enable'
   */
  if (rtDW.Step > 0.0) {
    /* Fcn: '<S25>/Fcn' incorporates:
     *  Constant: '<S15>/Constant2'
     *  Constant: '<S15>/IdRef2'
     *  Inport: '<Root>/Bus_Voltage'
     */
    rtb_Fcn = Dead_Time * rtU.Bus_Voltage / 5.0E-5F;

    /* Sum: '<S31>/Add1' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Product: '<S31>/Divide1'
     *  Sum: '<S31>/Add'
     *  UnitDelay: '<S31>/Unit Delay'
     */
    rtb_Add1_n = (Id_measured - rtDW.UnitDelay_DSTATE_p) * 0.005F +
      rtDW.UnitDelay_DSTATE_p;

    /* Sum: '<S30>/Add1' incorporates:
     *  Constant: '<S30>/Constant1'
     *  Product: '<S30>/Divide1'
     *  Sum: '<S30>/Add'
     *  UnitDelay: '<S30>/Unit Delay'
     */
    rtb_Add1_j = (Iq_measured - rtDW.UnitDelay_DSTATE_n) * 0.005F +
      rtDW.UnitDelay_DSTATE_n;

    /* If: '<S32>/B>0' */
    if (rtb_Add1_n > 0.0F) {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      /* Lookup_n-D: '<S38>/1-D Lookup Table4' incorporates:
       *  Product: '<S38>/Divide'
       *  Saturate: '<S38>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 > 572.0F) {
        rtb_Itheta2 = 572.0F;
      } else {
        if (rtb_Itheta2 < -572.0F) {
          rtb_Itheta2 = -572.0F;
        }
      }

      /* Merge: '<S32>/Merge2' incorporates:
       *  Lookup_n-D: '<S38>/1-D Lookup Table4'
       *  SignalConversion generated from: '<S38>/IsTheta'
       */
      rtDW.Merge2_n = rtConstP.pooled7[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)];

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem8' */
    }

    /* End of If: '<S32>/B>0' */

    /* If: '<S32>/A>=0andB<0' */
    if ((rtb_Add1_j >= 0.0F) && (rtb_Add1_n < 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem9' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      /* Lookup_n-D: '<S39>/1-D Lookup Table4' incorporates:
       *  Product: '<S39>/Divide'
       *  Saturate: '<S39>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 < -572.0F) {
        rtb_Itheta2 = -572.0F;
      }

      /* Merge: '<S32>/Merge2' incorporates:
       *  Constant: '<S39>/Constant'
       *  Lookup_n-D: '<S39>/1-D Lookup Table4'
       *  SignalConversion generated from: '<S39>/IsTheta'
       *  Sum: '<S39>/Add'
       */
      rtDW.Merge2_n = rtConstP.pooled7[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)] + 3.14159274F;

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem9' */
    }

    /* End of If: '<S32>/A>=0andB<0' */

    /* If: '<S32>/B<0andA<0' */
    if ((rtb_Add1_j < 0.0F) && (rtb_Add1_n < 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* Lookup_n-D: '<S35>/1-D Lookup Table4' incorporates:
       *  Product: '<S35>/Divide'
       *  Saturate: '<S35>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 > 572.0F) {
        rtb_Itheta2 = 572.0F;
      }

      /* Merge: '<S32>/Merge2' incorporates:
       *  Constant: '<S35>/Constant'
       *  Lookup_n-D: '<S35>/1-D Lookup Table4'
       *  Sum: '<S35>/Add'
       */
      rtDW.Merge2_n = rtConstP.pooled7[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)] - 3.14159274F;

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem10' */
    }

    /* End of If: '<S32>/B<0andA<0' */

    /* If: '<S32>/B=0andA>0' */
    if ((rtb_Add1_j > 0.0F) && (rtb_Add1_n == 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem11' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* Merge: '<S32>/Merge2' incorporates:
       *  Constant: '<S36>/Constant'
       *  SignalConversion generated from: '<S36>/IsTheta'
       */
      rtDW.Merge2_n = 1.57079637F;

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem11' */
    }

    /* End of If: '<S32>/B=0andA>0' */

    /* If: '<S32>/B=0andA<0' */
    if ((rtb_Add1_j < 0.0F) && (rtb_Add1_n == 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem12' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* Merge: '<S32>/Merge2' incorporates:
       *  Constant: '<S37>/Constant'
       *  SignalConversion generated from: '<S37>/IsTheta'
       */
      rtDW.Merge2_n = -1.57079637F;

      /* End of Outputs for SubSystem: '<S32>/If Action Subsystem12' */
    }

    /* End of If: '<S32>/B=0andA<0' */

    /* Sum: '<S26>/Add1' */
    rtb_Itheta2 = rtDW.Merge2_n + rtDW.Direct_Angle;

    /* If: '<S29>/If1' */
    if (rtb_Itheta2 > 6.28318548F) {
      /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      /* Sum: '<S34>/Subtract1' incorporates:
       *  Constant: '<S34>/2pi'
       */
      rtb_Itheta2 -= 6.28318548F;

      /* End of Outputs for SubSystem: '<S29>/If Action Subsystem2' */
    }

    /* End of If: '<S29>/If1' */

    /* If: '<S27>/If1' */
    if ((rtb_Itheta2 > 5.75958F) || (rtb_Itheta2 <= 0.523598F)) {
      /* Outputs for IfAction SubSystem: '<S27>/Subsystem' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      /* Gain: '<S40>/Gain' */
      rtDW.Merge_p[0] = rtb_Fcn;

      /* Gain: '<S40>/Gain1' */
      rtDW.Merge_p[1] = -rtb_Fcn;

      /* Gain: '<S40>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S27>/Subsystem' */
    } else if ((rtb_Itheta2 > 0.523598F) && (rtb_Itheta2 <= 1.57079601F)) {
      /* Outputs for IfAction SubSystem: '<S27>/Subsystem1' incorporates:
       *  ActionPort: '<S41>/Action Port'
       */
      /* Gain: '<S41>/Gain' */
      rtDW.Merge_p[0] = rtb_Fcn;

      /* Gain: '<S41>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S41>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S27>/Subsystem1' */
    } else if ((rtb_Itheta2 > 1.57079601F) && (rtb_Itheta2 <= 2.61799312F)) {
      /* Outputs for IfAction SubSystem: '<S27>/Subsystem2' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      /* Gain: '<S42>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S42>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S42>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S27>/Subsystem2' */
    } else if ((rtb_Itheta2 > 2.61799312F) && (rtb_Itheta2 <= 3.66519094F)) {
      /* Outputs for IfAction SubSystem: '<S27>/Subsystem3' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      /* Gain: '<S43>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S43>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S43>/Gain2' */
      rtDW.Merge_p[2] = rtb_Fcn;

      /* End of Outputs for SubSystem: '<S27>/Subsystem3' */
    } else if ((rtb_Itheta2 > 3.66519094F) && (rtb_Itheta2 <= 4.71238899F)) {
      /* Outputs for IfAction SubSystem: '<S27>/Subsystem4' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      /* Gain: '<S44>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S44>/Gain1' */
      rtDW.Merge_p[1] = -rtb_Fcn;

      /* Gain: '<S44>/Gain2' */
      rtDW.Merge_p[2] = rtb_Fcn;

      /* End of Outputs for SubSystem: '<S27>/Subsystem4' */
    } else {
      if ((rtb_Itheta2 > 4.71238899F) && (rtb_Itheta2 <= 5.75958F)) {
        /* Outputs for IfAction SubSystem: '<S27>/Subsystem5' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */
        /* Gain: '<S45>/Gain' */
        rtDW.Merge_p[0] = rtb_Fcn;

        /* Gain: '<S45>/Gain1' */
        rtDW.Merge_p[1] = -rtb_Fcn;

        /* Gain: '<S45>/Gain2' */
        rtDW.Merge_p[2] = rtb_Fcn;

        /* End of Outputs for SubSystem: '<S27>/Subsystem5' */
      }
    }

    /* End of If: '<S27>/If1' */

    /* Fcn: '<S28>/Fcn' */
    rtDW.Fcn = ((rtDW.Merge_p[0] - 0.5F * rtDW.Merge_p[1]) - 0.5F *
                rtDW.Merge_p[2]) * 0.666666687F;

    /* Fcn: '<S28>/Fcn1' */
    rtDW.Fcn1 = (rtDW.Merge_p[1] - rtDW.Merge_p[2]) * 0.577350259F;

    /* Update for UnitDelay: '<S31>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_p = rtb_Add1_n;

    /* Update for UnitDelay: '<S30>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_n = rtb_Add1_j;
  }

  /* End of Outputs for SubSystem: '<S17>/DT_Compensation' */
}

/*
 * Output and update for atomic system:
 *    '<S46>/Normal'
 *    '<S49>/Normal'
 */
void Normal(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S47>/Gain' */
  *rty_Out1 = 0.577350259F * rtu_Bus_voltage;

  /* Gain: '<S47>/Gain1' */
  *rty_Out2 = -0.577350259F * rtu_Bus_voltage;
}

/* Output and update for atomic system: '<S15>/D_Current_PI' */
void D_Current_PI(void)
{
  real32_T rtb_Add_jn;
  real32_T rtb_Gain;
  real32_T rtb_Gain1;
  real32_T rtb_Switch_h;

  /* Sum: '<S18>/Add2' */
  rtb_Switch_h = Id_ref - Id_measured;

  /* DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevR_pb != 0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_a = 0.0F;
  }

  /* Sum: '<S46>/Add' incorporates:
   *  Constant: '<S46>/Kp'
   *  DiscreteIntegrator: '<S46>/Discrete-Time Integrator'
   *  Product: '<S46>/Product'
   */
  rtb_Add_jn = PI_Parameter.ID_Kp * rtb_Switch_h +
    rtDW.DiscreteTimeIntegrator_DSTATE_a;

  /* Outputs for Atomic SubSystem: '<S46>/Normal' */
  /* Inport: '<Root>/Bus_Voltage' */
  Normal(rtU.Bus_Voltage, &rtb_Gain, &rtb_Gain1);

  /* End of Outputs for SubSystem: '<S46>/Normal' */

  /* Switch: '<S48>/Switch2' incorporates:
   *  RelationalOperator: '<S48>/LowerRelop1'
   *  RelationalOperator: '<S48>/UpperRelop'
   *  Switch: '<S48>/Switch'
   */
  if (rtb_Add_jn > rtb_Gain) {
    /* Switch: '<S48>/Switch2' */
    Vd_voltage = rtb_Gain;
  } else if (rtb_Add_jn < rtb_Gain1) {
    /* Switch: '<S48>/Switch' incorporates:
     *  Switch: '<S48>/Switch2'
     */
    Vd_voltage = rtb_Gain1;
  } else {
    /* Switch: '<S48>/Switch2' incorporates:
     *  Switch: '<S48>/Switch'
     */
    Vd_voltage = rtb_Add_jn;
  }

  /* End of Switch: '<S48>/Switch2' */

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/Cons'
   *  UnitDelay: '<S46>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_k) {
    rtb_Switch_h = 0.0F;
  }

  /* End of Switch: '<S46>/Switch' */

  /* Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S46>/Ki'
   *  Product: '<S46>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += PI_Parameter.ID_Ki * rtb_Switch_h *
    5.0E-5F;
  rtDW.DiscreteTimeIntegrator_PrevR_pb = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S46>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S46>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_k = (rtb_Add_jn == Vd_voltage);
}

/* Output and update for atomic system: '<S15>/Inverse_Park_Transform' */
void Inverse_Park_Transform(void)
{
  /* Sum: '<S19>/Add' incorporates:
   *  Product: '<S19>/Product1'
   *  Product: '<S19>/Product2'
   *  Sum: '<S19>/Add1'
   */
  V_alpha = Vd_voltage * rtDW.Add4 - Vq_voltage * rtDW.Add3;

  /* Sum: '<S19>/Add3' incorporates:
   *  Product: '<S19>/Product3'
   *  Product: '<S19>/Product4'
   *  Sum: '<S19>/Add2'
   */
  V_beta = Vd_voltage * rtDW.Add3 + Vq_voltage * rtDW.Add4;
}

/* Output and update for atomic system: '<S15>/Park_Transform' */
void Park_Transform(void)
{
  /* Sum: '<S20>/Add1' incorporates:
   *  Product: '<S20>/Product1'
   *  Product: '<S20>/Product2'
   */
  Id_measured = Ialpha * rtDW.Add4 + Ibeta * rtDW.Add3;

  /* Sum: '<S20>/Add2' incorporates:
   *  Product: '<S20>/Produc3t'
   *  Product: '<S20>/Product4'
   */
  Iq_measured = Ibeta * rtDW.Add4 - Ialpha * rtDW.Add3;
}

/* Output and update for atomic system: '<S15>/Q_Current_PI' */
void Q_Current_PI(void)
{
  real32_T rtb_Add_it;
  real32_T rtb_Gain;
  real32_T rtb_Gain1;
  real32_T rtb_Switch_k;

  /* Sum: '<S21>/Add2' */
  rtb_Switch_k = Iq_ref - Iq_measured;

  /* DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_i = 0.0F;
  }

  /* Sum: '<S49>/Add' incorporates:
   *  Constant: '<S49>/Kp'
   *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
   *  Product: '<S49>/Product'
   */
  rtb_Add_it = PI_Parameter.IQ_Kp * rtb_Switch_k +
    rtDW.DiscreteTimeIntegrator_DSTATE_i;

  /* Outputs for Atomic SubSystem: '<S49>/Normal' */
  /* Inport: '<Root>/Bus_Voltage' */
  Normal(rtU.Bus_Voltage, &rtb_Gain, &rtb_Gain1);

  /* End of Outputs for SubSystem: '<S49>/Normal' */

  /* Switch: '<S51>/Switch2' incorporates:
   *  RelationalOperator: '<S51>/LowerRelop1'
   *  RelationalOperator: '<S51>/UpperRelop'
   *  Switch: '<S51>/Switch'
   */
  if (rtb_Add_it > rtb_Gain) {
    Vq_voltage = rtb_Gain;
  } else if (rtb_Add_it < rtb_Gain1) {
    /* Switch: '<S51>/Switch' */
    Vq_voltage = rtb_Gain1;
  } else {
    Vq_voltage = rtb_Add_it;
  }

  /* End of Switch: '<S51>/Switch2' */

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Cons'
   *  UnitDelay: '<S49>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_i) {
    rtb_Switch_k = 0.0F;
  }

  /* End of Switch: '<S49>/Switch' */

  /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S49>/Ki'
   *  Product: '<S49>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_i += PI_Parameter.IQ_Ki * rtb_Switch_k *
    5.0E-5F;
  rtDW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S49>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S49>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_i = (rtb_Add_it == Vq_voltage);
}

/* Output and update for atomic system: '<S15>/SVPWM' */
void SVPWM(void)
{
  real32_T rtb_Add1_n;
  real32_T rtb_Gain;
  real32_T rtb_IndexVector1;
  real32_T rtb_IndexVector_c;
  real32_T rtb_Saturation;

  /* Outputs for Atomic SubSystem: '<S22>/XYZ Caculate' */
  /* Outputs for Atomic SubSystem: '<S22>/N Sector  Caculate' */
  /* Gain: '<S54>/Gain' incorporates:
   *  Gain: '<S57>/Gain'
   */
  rtb_Gain = 1.73205078F * rtDW.Add3;

  /* End of Outputs for SubSystem: '<S22>/XYZ Caculate' */

  /* Saturate: '<S54>/Saturation' incorporates:
   *  Gain: '<S54>/Gain'
   *  Gain: '<S54>/Gain1'
   *  Gain: '<S54>/Gain2'
   *  Sum: '<S54>/Add'
   *  Sum: '<S54>/Add1'
   *  Sum: '<S54>/Add2'
   *  Switch: '<S54>/Switch'
   *  Switch: '<S54>/Switch1'
   *  Switch: '<S54>/Switch2'
   */
  rtb_Saturation = (real32_T)((((rtb_Gain - rtDW.Add4 >= 0.0F) << 1) +
    (rtDW.Add4 >= 0.0F)) + (((0.0F - rtDW.Add4) - rtb_Gain >= 0.0F) << 2));
  if (rtb_Saturation > 6.0F) {
    rtb_Saturation = 6.0F;
  } else {
    if (rtb_Saturation < 1.0F) {
      rtb_Saturation = 1.0F;
    }
  }

  /* End of Saturate: '<S54>/Saturation' */
  /* End of Outputs for SubSystem: '<S22>/N Sector  Caculate' */

  /* Outputs for Atomic SubSystem: '<S22>/XYZ Caculate' */
  /* Saturate: '<S57>/Saturation' incorporates:
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (rtU.Bus_Voltage > 1200.0F) {
    rtb_Add1_n = 1200.0F;
  } else if (rtU.Bus_Voltage < 0.0001F) {
    rtb_Add1_n = 0.0001F;
  } else {
    rtb_Add1_n = rtU.Bus_Voltage;
  }

  /* End of Saturate: '<S57>/Saturation' */

  /* Product: '<S57>/Divide' incorporates:
   *  Constant: '<S15>/Constant4'
   *  Constant: '<S57>/Constant'
   */
  rtb_Add1_n = 8.66025366E-5F / rtb_Add1_n;

  /* End of Outputs for SubSystem: '<S22>/XYZ Caculate' */

  /* Outputs for Atomic SubSystem: '<S22>/T1 T2  Caculate' */
  /* MultiPortSwitch: '<S55>/Index Vector' incorporates:
   *  Gain: '<S55>/Gain'
   *  Gain: '<S55>/Gain1'
   *  Gain: '<S55>/Gain2'
   *  Gain: '<S57>/Gain1'
   *  Gain: '<S57>/Gain2'
   *  Product: '<S57>/Product'
   *  Product: '<S57>/Product1'
   *  Product: '<S57>/Product2'
   *  Sum: '<S57>/Add1'
   *  Sum: '<S57>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    /* Outputs for Atomic SubSystem: '<S22>/XYZ Caculate' */
    rtb_IndexVector_c = (rtb_Gain - rtDW.Add4) * -0.5F * rtb_Add1_n;

    /* MultiPortSwitch: '<S55>/Index Vector1' incorporates:
     *  Gain: '<S57>/Gain1'
     *  Gain: '<S57>/Gain2'
     *  Product: '<S57>/Product1'
     *  Product: '<S57>/Product2'
     *  Sum: '<S57>/Add1'
     *  Sum: '<S57>/Add2'
     */
    rtb_Gain = ((0.0F - rtDW.Add4) - rtb_Gain) * -0.5F * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S22>/XYZ Caculate' */
    break;

   case 2:
    /* Outputs for Atomic SubSystem: '<S22>/XYZ Caculate' */
    rtb_IndexVector_c = ((0.0F - rtDW.Add4) - rtb_Gain) * -0.5F * rtb_Add1_n;

    /* MultiPortSwitch: '<S55>/Index Vector1' incorporates:
     *  Gain: '<S55>/Gain'
     *  Gain: '<S57>/Gain2'
     *  Product: '<S57>/Product'
     *  Product: '<S57>/Product1'
     *  Sum: '<S57>/Add2'
     */
    rtb_Gain = -(rtDW.Add4 * rtb_Add1_n);

    /* End of Outputs for SubSystem: '<S22>/XYZ Caculate' */
    break;

   case 3:
    /* Outputs for Atomic SubSystem: '<S22>/XYZ Caculate' */
    rtb_IndexVector_c = -((rtb_Gain - rtDW.Add4) * -0.5F * rtb_Add1_n);

    /* MultiPortSwitch: '<S55>/Index Vector1' incorporates:
     *  Gain: '<S55>/Gain2'
     *  Gain: '<S57>/Gain1'
     *  Product: '<S57>/Product'
     *  Product: '<S57>/Product2'
     *  Sum: '<S57>/Add1'
     */
    rtb_Gain = rtDW.Add4 * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S22>/XYZ Caculate' */
    break;

   case 4:
    /* Outputs for Atomic SubSystem: '<S22>/XYZ Caculate' */
    rtb_IndexVector_c = -(rtDW.Add4 * rtb_Add1_n);

    /* MultiPortSwitch: '<S55>/Index Vector1' incorporates:
     *  Gain: '<S55>/Gain'
     *  Gain: '<S57>/Gain1'
     *  Product: '<S57>/Product'
     *  Product: '<S57>/Product2'
     *  Sum: '<S57>/Add1'
     */
    rtb_Gain = (rtb_Gain - rtDW.Add4) * -0.5F * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S22>/XYZ Caculate' */
    break;

   case 5:
    /* Outputs for Atomic SubSystem: '<S22>/XYZ Caculate' */
    rtb_IndexVector_c = rtDW.Add4 * rtb_Add1_n;

    /* MultiPortSwitch: '<S55>/Index Vector1' incorporates:
     *  Gain: '<S55>/Gain1'
     *  Gain: '<S57>/Gain2'
     *  Product: '<S57>/Product'
     *  Product: '<S57>/Product1'
     *  Sum: '<S57>/Add2'
     */
    rtb_Gain = -(((0.0F - rtDW.Add4) - rtb_Gain) * -0.5F * rtb_Add1_n);

    /* End of Outputs for SubSystem: '<S22>/XYZ Caculate' */
    break;

   default:
    /* Outputs for Atomic SubSystem: '<S22>/XYZ Caculate' */
    rtb_IndexVector_c = -(((0.0F - rtDW.Add4) - rtb_Gain) * -0.5F * rtb_Add1_n);

    /* MultiPortSwitch: '<S55>/Index Vector1' incorporates:
     *  Gain: '<S55>/Gain1'
     *  Gain: '<S55>/Gain2'
     *  Gain: '<S57>/Gain1'
     *  Gain: '<S57>/Gain2'
     *  Product: '<S57>/Product1'
     *  Product: '<S57>/Product2'
     *  Sum: '<S57>/Add1'
     *  Sum: '<S57>/Add2'
     */
    rtb_Gain = -((rtb_Gain - rtDW.Add4) * -0.5F * rtb_Add1_n);

    /* End of Outputs for SubSystem: '<S22>/XYZ Caculate' */
    break;
  }

  /* End of MultiPortSwitch: '<S55>/Index Vector' */

  /* Sum: '<S55>/Add' */
  rtb_Add1_n = rtb_IndexVector_c + rtb_Gain;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S15>/Constant4'
   *  Product: '<S55>/Divide'
   *  Product: '<S55>/Divide1'
   *  Sum: '<S55>/Add1'
   *  Switch: '<S55>/Switch2'
   */
  if (!(5.0E-5F - rtb_Add1_n > 0.0F)) {
    rtb_IndexVector_c = rtb_IndexVector_c * 5.0E-5F / rtb_Add1_n;
    rtb_Gain *= 1.0F / rtb_Add1_n * 5.0E-5F;
  }

  /* End of Switch: '<S55>/Switch' */
  /* End of Outputs for SubSystem: '<S22>/T1 T2  Caculate' */

  /* Outputs for Atomic SubSystem: '<S22>/Tcm calculate' */
  /* Gain: '<S56>/Gain2' incorporates:
   *  Constant: '<S15>/Constant4'
   *  Sum: '<S56>/Add'
   */
  rtb_Add1_n = ((5.0E-5F - rtb_IndexVector_c) - rtb_Gain) * 0.25F;

  /* Sum: '<S56>/Add1' incorporates:
   *  Gain: '<S56>/Gain'
   */
  rtb_IndexVector_c = 0.5F * rtb_IndexVector_c + rtb_Add1_n;

  /* MultiPortSwitch: '<S56>/Index Vector' incorporates:
   *  Gain: '<S56>/Gain1'
   *  Sum: '<S56>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S56>/Index Vector1' */
    rtb_IndexVector1 = rtb_Add1_n;

    /* MultiPortSwitch: '<S56>/Index Vector2' incorporates:
     *  Gain: '<S56>/Gain1'
     *  Sum: '<S56>/Add2'
     */
    rtb_Add1_n = 0.5F * rtb_Gain + rtb_IndexVector_c;
    break;

   case 2:
    rtb_Saturation = rtb_Add1_n;

    /* MultiPortSwitch: '<S56>/Index Vector1' incorporates:
     *  Gain: '<S56>/Gain1'
     *  Sum: '<S56>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S56>/Index Vector2' */
    rtb_Add1_n = rtb_IndexVector_c;
    break;

   case 3:
    rtb_Saturation = rtb_Add1_n;

    /* MultiPortSwitch: '<S56>/Index Vector1' */
    rtb_IndexVector1 = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S56>/Index Vector2' incorporates:
     *  Gain: '<S56>/Gain1'
     *  Sum: '<S56>/Add2'
     */
    rtb_Add1_n = 0.5F * rtb_Gain + rtb_IndexVector_c;
    break;

   case 4:
    rtb_Saturation = 0.5F * rtb_Gain + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S56>/Index Vector1' incorporates:
     *  Gain: '<S56>/Gain1'
     *  Sum: '<S56>/Add2'
     */
    rtb_IndexVector1 = rtb_IndexVector_c;
    break;

   case 5:
    rtb_Saturation = 0.5F * rtb_Gain + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S56>/Index Vector1' incorporates:
     *  Gain: '<S56>/Gain1'
     *  Sum: '<S56>/Add2'
     */
    rtb_IndexVector1 = rtb_Add1_n;

    /* MultiPortSwitch: '<S56>/Index Vector2' */
    rtb_Add1_n = rtb_IndexVector_c;
    break;

   default:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S56>/Index Vector1' incorporates:
     *  Gain: '<S56>/Gain1'
     *  Sum: '<S56>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain + rtb_IndexVector_c;
    break;
  }

  /* End of MultiPortSwitch: '<S56>/Index Vector' */
  /* End of Outputs for SubSystem: '<S22>/Tcm calculate' */

  /* If: '<S22>/If1' */
  if (rtDW.Merge1_a == 0) {
    /* Outputs for IfAction SubSystem: '<S22>/Enable_Motor' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    /* Merge: '<S22>/Merge' incorporates:
     *  Gain: '<S22>/Gain'
     *  Inport: '<S53>/In1'
     */
    rtDW.Merge = 2.0E+8F * rtb_Saturation;

    /* Merge: '<S22>/Merge1' incorporates:
     *  Gain: '<S22>/Gain2'
     *  Inport: '<S53>/In2'
     */
    rtDW.Merge1 = 2.0E+8F * rtb_IndexVector1;

    /* Merge: '<S22>/Merge2' incorporates:
     *  Gain: '<S22>/Gain3'
     *  Inport: '<S53>/In3'
     */
    rtDW.Merge2 = 2.0E+8F * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S22>/Enable_Motor' */
  } else {
    if (rtDW.Merge1_a == 1) {
      /* Outputs for IfAction SubSystem: '<S22>/Disable_Motor' incorporates:
       *  ActionPort: '<S52>/Action Port'
       */
      /* Merge: '<S22>/Merge' incorporates:
       *  Constant: '<S52>/Constant'
       *  SignalConversion generated from: '<S52>/Out1'
       */
      rtDW.Merge = 0.0F;

      /* Merge: '<S22>/Merge1' incorporates:
       *  Constant: '<S52>/Constant1'
       *  SignalConversion generated from: '<S52>/Out2'
       */
      rtDW.Merge1 = 0.0F;

      /* Merge: '<S22>/Merge2' incorporates:
       *  Constant: '<S52>/Constant2'
       *  SignalConversion generated from: '<S52>/Out3'
       */
      rtDW.Merge2 = 0.0F;

      /* End of Outputs for SubSystem: '<S22>/Disable_Motor' */
    }
  }

  /* End of If: '<S22>/If1' */
}

/* Output and update for atomic system: '<S15>/Sine_Cosine' */
void Sine_Cosine(void)
{
  real32_T rtb_Saturation;
  uint32_T Add4_tmp;

  /* Saturate: '<S23>/Saturation' */
  if (rtDW.Direct_Angle > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Direct_Angle < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Direct_Angle;
  }

  /* End of Saturate: '<S23>/Saturation' */

  /* Lookup_n-D: '<S23>/Cosine' incorporates:
   *  Lookup_n-D: '<S23>/Sine'
   *  Saturate: '<S23>/Saturation'
   */
  Add4_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);
  rtDW.Add4 = rtConstP.Cosine_tableData[Add4_tmp];

  /* Lookup_n-D: '<S23>/Sine' */
  rtDW.Add3 = rtConstP.Sine_tableData[Add4_tmp];
}

/* Output and update for atomic system: '<S5>/FOC' */
void FOC(void)
{
  /* Step: '<S15>/Step' */
  rtDW.Step = !(((rtM->Timing.clockTick0) * 5.0E-5) < 0.2);

  /* Outputs for Atomic SubSystem: '<S15>/Clarke_Transform' */
  Clarke_Transform();

  /* End of Outputs for SubSystem: '<S15>/Clarke_Transform' */

  /* Outputs for Atomic SubSystem: '<S15>/Sine_Cosine' */
  Sine_Cosine();

  /* End of Outputs for SubSystem: '<S15>/Sine_Cosine' */

  /* Outputs for Atomic SubSystem: '<S15>/Park_Transform' */
  Park_Transform();

  /* End of Outputs for SubSystem: '<S15>/Park_Transform' */

  /* Outputs for Atomic SubSystem: '<S15>/DT_Compensation' */
  DT_Compensation();

  /* End of Outputs for SubSystem: '<S15>/DT_Compensation' */

  /* Outputs for Atomic SubSystem: '<S15>/D_Current_PI' */
  D_Current_PI();

  /* End of Outputs for SubSystem: '<S15>/D_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S15>/Q_Current_PI' */
  Q_Current_PI();

  /* End of Outputs for SubSystem: '<S15>/Q_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S15>/Inverse_Park_Transform' */
  Inverse_Park_Transform();

  /* End of Outputs for SubSystem: '<S15>/Inverse_Park_Transform' */

  /* Sum: '<S15>/Add3' */
  rtDW.Add3 = rtDW.Fcn + V_alpha;

  /* Sum: '<S15>/Add4' */
  rtDW.Add4 = rtDW.Fcn1 + V_beta;

  /* Outputs for Atomic SubSystem: '<S15>/SVPWM' */
  SVPWM();

  /* End of Outputs for SubSystem: '<S15>/SVPWM' */
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
