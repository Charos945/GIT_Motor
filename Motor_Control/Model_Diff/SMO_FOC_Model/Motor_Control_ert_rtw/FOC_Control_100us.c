/*
 * File: FOC_Control_100us.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov  4 09:51:01 2021
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

/* Output and update for atomic system: '<S95>/Clarke_Transform' */
void Clarke_Transform(void)
{
  /* Outputs for Atomic SubSystem: '<S96>/Clark1' */
  /* Gain: '<S108>/Gain2' incorporates:
   *  Gain: '<S108>/Gain'
   *  Gain: '<S108>/Gain1'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S108>/Add'
   */
  Ialpha = ((rtU.Phase_CurrentABC[0] - 0.5F * rtU.Phase_CurrentABC[1]) - 0.5F *
            rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* Gain: '<S108>/Gain5' incorporates:
   *  Gain: '<S108>/Gain3'
   *  Gain: '<S108>/Gain4'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S108>/Add1'
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
   *  EnablePort: '<S109>/Enable'
   */
  if (rtDW.Constant3 > 0.0F) {
    /* Fcn: '<S109>/Fcn' incorporates:
     *  Constant: '<S95>/Constant2'
     *  Constant: '<S95>/IdRef2'
     *  Inport: '<Root>/Bus_Voltage'
     */
    rtb_Fcn = Dead_Time * rtU.Bus_Voltage / 0.0001F;

    /* Sum: '<S115>/Add1' incorporates:
     *  Constant: '<S115>/Constant1'
     *  Product: '<S115>/Divide1'
     *  Sum: '<S115>/Add'
     *  UnitDelay: '<S115>/Unit Delay'
     */
    rtb_Add1_n = (Id_measured - rtDW.UnitDelay_DSTATE_p) * 0.005F +
      rtDW.UnitDelay_DSTATE_p;

    /* Sum: '<S114>/Add1' incorporates:
     *  Constant: '<S114>/Constant1'
     *  Product: '<S114>/Divide1'
     *  Sum: '<S114>/Add'
     *  UnitDelay: '<S114>/Unit Delay'
     */
    rtb_Add1_j = (Iq_measured - rtDW.UnitDelay_DSTATE_n) * 0.005F +
      rtDW.UnitDelay_DSTATE_n;

    /* If: '<S116>/B>0' */
    if (rtb_Add1_n > 0.0F) {
      /* Outputs for IfAction SubSystem: '<S116>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S122>/Action Port'
       */
      /* Lookup_n-D: '<S122>/1-D Lookup Table4' incorporates:
       *  Product: '<S122>/Divide'
       *  Saturate: '<S122>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 > 572.0F) {
        rtb_Itheta2 = 572.0F;
      } else {
        if (rtb_Itheta2 < -572.0F) {
          rtb_Itheta2 = -572.0F;
        }
      }

      /* Merge: '<S116>/Merge2' incorporates:
       *  Lookup_n-D: '<S122>/1-D Lookup Table4'
       *  SignalConversion generated from: '<S122>/IsTheta'
       */
      rtDW.Merge2_n = rtConstP.pooled7[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)];

      /* End of Outputs for SubSystem: '<S116>/If Action Subsystem8' */
    }

    /* End of If: '<S116>/B>0' */

    /* If: '<S116>/A>=0andB<0' */
    if ((rtb_Add1_j >= 0.0F) && (rtb_Add1_n < 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S116>/If Action Subsystem9' incorporates:
       *  ActionPort: '<S123>/Action Port'
       */
      /* Lookup_n-D: '<S123>/1-D Lookup Table4' incorporates:
       *  Product: '<S123>/Divide'
       *  Saturate: '<S123>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 < -572.0F) {
        rtb_Itheta2 = -572.0F;
      }

      /* Merge: '<S116>/Merge2' incorporates:
       *  Constant: '<S123>/Constant'
       *  Lookup_n-D: '<S123>/1-D Lookup Table4'
       *  SignalConversion generated from: '<S123>/IsTheta'
       *  Sum: '<S123>/Add'
       */
      rtDW.Merge2_n = rtConstP.pooled7[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)] + 3.14159274F;

      /* End of Outputs for SubSystem: '<S116>/If Action Subsystem9' */
    }

    /* End of If: '<S116>/A>=0andB<0' */

    /* If: '<S116>/B<0andA<0' */
    if ((rtb_Add1_j < 0.0F) && (rtb_Add1_n < 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S116>/If Action Subsystem10' incorporates:
       *  ActionPort: '<S119>/Action Port'
       */
      /* Lookup_n-D: '<S119>/1-D Lookup Table4' incorporates:
       *  Product: '<S119>/Divide'
       *  Saturate: '<S119>/Saturation'
       */
      rtb_Itheta2 = rtb_Add1_j / rtb_Add1_n;
      if (rtb_Itheta2 > 572.0F) {
        rtb_Itheta2 = 572.0F;
      }

      /* Merge: '<S116>/Merge2' incorporates:
       *  Constant: '<S119>/Constant'
       *  Lookup_n-D: '<S119>/1-D Lookup Table4'
       *  Sum: '<S119>/Add'
       */
      rtDW.Merge2_n = rtConstP.pooled7[plook_u32f_evencka(rtb_Itheta2, -573.0F,
        0.279785156F, 4096U)] - 3.14159274F;

      /* End of Outputs for SubSystem: '<S116>/If Action Subsystem10' */
    }

    /* End of If: '<S116>/B<0andA<0' */

    /* If: '<S116>/B=0andA>0' */
    if ((rtb_Add1_j > 0.0F) && (rtb_Add1_n == 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S116>/If Action Subsystem11' incorporates:
       *  ActionPort: '<S120>/Action Port'
       */
      /* Merge: '<S116>/Merge2' incorporates:
       *  Constant: '<S120>/Constant'
       *  SignalConversion generated from: '<S120>/IsTheta'
       */
      rtDW.Merge2_n = 1.57079637F;

      /* End of Outputs for SubSystem: '<S116>/If Action Subsystem11' */
    }

    /* End of If: '<S116>/B=0andA>0' */

    /* If: '<S116>/B=0andA<0' */
    if ((rtb_Add1_j < 0.0F) && (rtb_Add1_n == 0.0F)) {
      /* Outputs for IfAction SubSystem: '<S116>/If Action Subsystem12' incorporates:
       *  ActionPort: '<S121>/Action Port'
       */
      /* Merge: '<S116>/Merge2' incorporates:
       *  Constant: '<S121>/Constant'
       *  SignalConversion generated from: '<S121>/IsTheta'
       */
      rtDW.Merge2_n = -1.57079637F;

      /* End of Outputs for SubSystem: '<S116>/If Action Subsystem12' */
    }

    /* End of If: '<S116>/B=0andA<0' */

    /* Sum: '<S110>/Add1' */
    rtb_Itheta2 = rtDW.Merge2_n + rtDW.Merge1_i;

    /* If: '<S113>/If1' incorporates:
     *  Inport: '<S117>/Angle_input'
     */
    if (rtb_Itheta2 > 6.28318548F) {
      /* Outputs for IfAction SubSystem: '<S113>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S118>/Action Port'
       */
      IfActionSubsystem2(rtb_Itheta2, &rtb_Merge1);

      /* End of Outputs for SubSystem: '<S113>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S113>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S117>/Action Port'
       */
      rtb_Merge1 = rtb_Itheta2;

      /* End of Outputs for SubSystem: '<S113>/If Action Subsystem1' */
    }

    /* End of If: '<S113>/If1' */

    /* If: '<S111>/If1' */
    if ((rtb_Merge1 > 5.75958F) || (rtb_Merge1 <= 0.523598F)) {
      /* Outputs for IfAction SubSystem: '<S111>/Subsystem' incorporates:
       *  ActionPort: '<S124>/Action Port'
       */
      /* Gain: '<S124>/Gain' */
      rtDW.Merge_p[0] = rtb_Fcn;

      /* Gain: '<S124>/Gain1' */
      rtDW.Merge_p[1] = -rtb_Fcn;

      /* Gain: '<S124>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S111>/Subsystem' */
    } else if ((rtb_Merge1 > 0.523598F) && (rtb_Merge1 <= 1.57079601F)) {
      /* Outputs for IfAction SubSystem: '<S111>/Subsystem1' incorporates:
       *  ActionPort: '<S125>/Action Port'
       */
      /* Gain: '<S125>/Gain' */
      rtDW.Merge_p[0] = rtb_Fcn;

      /* Gain: '<S125>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S125>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S111>/Subsystem1' */
    } else if ((rtb_Merge1 > 1.57079601F) && (rtb_Merge1 <= 2.61799312F)) {
      /* Outputs for IfAction SubSystem: '<S111>/Subsystem2' incorporates:
       *  ActionPort: '<S126>/Action Port'
       */
      /* Gain: '<S126>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S126>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S126>/Gain2' */
      rtDW.Merge_p[2] = -rtb_Fcn;

      /* End of Outputs for SubSystem: '<S111>/Subsystem2' */
    } else if ((rtb_Merge1 > 2.61799312F) && (rtb_Merge1 <= 3.66519094F)) {
      /* Outputs for IfAction SubSystem: '<S111>/Subsystem3' incorporates:
       *  ActionPort: '<S127>/Action Port'
       */
      /* Gain: '<S127>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S127>/Gain1' */
      rtDW.Merge_p[1] = rtb_Fcn;

      /* Gain: '<S127>/Gain2' */
      rtDW.Merge_p[2] = rtb_Fcn;

      /* End of Outputs for SubSystem: '<S111>/Subsystem3' */
    } else if ((rtb_Merge1 > 3.66519094F) && (rtb_Merge1 <= 4.71238899F)) {
      /* Outputs for IfAction SubSystem: '<S111>/Subsystem4' incorporates:
       *  ActionPort: '<S128>/Action Port'
       */
      /* Gain: '<S128>/Gain' */
      rtDW.Merge_p[0] = -rtb_Fcn;

      /* Gain: '<S128>/Gain1' */
      rtDW.Merge_p[1] = -rtb_Fcn;

      /* Gain: '<S128>/Gain2' */
      rtDW.Merge_p[2] = rtb_Fcn;

      /* End of Outputs for SubSystem: '<S111>/Subsystem4' */
    } else {
      if ((rtb_Merge1 > 4.71238899F) && (rtb_Merge1 <= 5.75958F)) {
        /* Outputs for IfAction SubSystem: '<S111>/Subsystem5' incorporates:
         *  ActionPort: '<S129>/Action Port'
         */
        /* Gain: '<S129>/Gain' */
        rtDW.Merge_p[0] = rtb_Fcn;

        /* Gain: '<S129>/Gain1' */
        rtDW.Merge_p[1] = -rtb_Fcn;

        /* Gain: '<S129>/Gain2' */
        rtDW.Merge_p[2] = rtb_Fcn;

        /* End of Outputs for SubSystem: '<S111>/Subsystem5' */
      }
    }

    /* End of If: '<S111>/If1' */

    /* Fcn: '<S112>/Fcn' */
    rtDW.Fcn = ((rtDW.Merge_p[0] - 0.5F * rtDW.Merge_p[1]) - 0.5F *
                rtDW.Merge_p[2]) * 0.666666687F;

    /* Fcn: '<S112>/Fcn1' */
    rtDW.Fcn1 = (rtDW.Merge_p[1] - rtDW.Merge_p[2]) * 0.577350259F;

    /* Update for UnitDelay: '<S115>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_p = rtb_Add1_n;

    /* Update for UnitDelay: '<S114>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_n = rtb_Add1_j;
  }

  /* End of Outputs for SubSystem: '<S97>/DT_Compensation' */
}

/*
 * Output and update for action system:
 *    '<S130>/Over_M'
 *    '<S200>/Over_M'
 */
void Over_M(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S132>/Gain' */
  *rty_Out1 = 0.666666687F * rtu_Bus_voltage;

  /* Gain: '<S132>/Gain1' */
  *rty_Out2 = -0.666666687F * rtu_Bus_voltage;
}

/*
 * Output and update for action system:
 *    '<S130>/Normal'
 *    '<S200>/Normal'
 */
void Normal(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T *rty_Out2)
{
  /* Gain: '<S131>/Gain' */
  *rty_Out1 = 0.577350259F * rtu_Bus_voltage;

  /* Gain: '<S131>/Gain1' */
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

  /* DiscreteIntegrator: '<S130>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_pb !=
       0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_a = 0.0F;
  }

  /* Sum: '<S130>/Add' incorporates:
   *  Constant: '<S130>/Kp'
   *  DiscreteIntegrator: '<S130>/Discrete-Time Integrator'
   *  Product: '<S130>/Product'
   */
  rtb_Add_jn = PI_Parameter.ID_Kp * rtb_Switch_h +
    rtDW.DiscreteTimeIntegrator_DSTATE_a;

  /* If: '<S130>/If1' incorporates:
   *  Constant: '<S130>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S130>/Over_M' incorporates:
     *  ActionPort: '<S132>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S130>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S130>/Normal' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_a, &Merge1_b);

    /* End of Outputs for SubSystem: '<S130>/Normal' */
  }

  /* End of If: '<S130>/If1' */

  /* Switch: '<S133>/Switch2' incorporates:
   *  RelationalOperator: '<S133>/LowerRelop1'
   *  RelationalOperator: '<S133>/UpperRelop'
   *  Switch: '<S133>/Switch'
   */
  if (rtb_Add_jn > Merge_a) {
    /* Switch: '<S133>/Switch2' */
    Vd_voltage = Merge_a;
  } else if (rtb_Add_jn < Merge1_b) {
    /* Switch: '<S133>/Switch' incorporates:
     *  Switch: '<S133>/Switch2'
     */
    Vd_voltage = Merge1_b;
  } else {
    /* Switch: '<S133>/Switch2' incorporates:
     *  Switch: '<S133>/Switch'
     */
    Vd_voltage = rtb_Add_jn;
  }

  /* End of Switch: '<S133>/Switch2' */

  /* Switch: '<S130>/Switch' incorporates:
   *  Constant: '<S130>/Cons'
   *  UnitDelay: '<S130>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_k) {
    rtb_Switch_h = 0.0F;
  }

  /* End of Switch: '<S130>/Switch' */

  /* Update for DiscreteIntegrator: '<S130>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S130>/Ki'
   *  Product: '<S130>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += PI_Parameter.ID_Ki * rtb_Switch_h *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_pb = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S130>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S130>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_k = (rtb_Add_jn == Vd_voltage);
}

/* Output and update for atomic system: '<S138>/Sine_Cosine' */
void Sine_Cosine(void)
{
  real32_T rtb_Saturation;
  uint32_T Cosine_tmp;

  /* Saturate: '<S141>/Saturation' */
  if (rtDW.UnitDelay > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.UnitDelay < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.UnitDelay;
  }

  /* End of Saturate: '<S141>/Saturation' */

  /* Lookup_n-D: '<S141>/Cosine' incorporates:
   *  Lookup_n-D: '<S141>/Sine'
   *  Saturate: '<S141>/Saturation'
   */
  Cosine_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);

  /* Lookup_n-D: '<S141>/Cosine' */
  rtDW.Cosine = rtConstP.pooled30[Cosine_tmp];

  /* Lookup_n-D: '<S141>/Sine' */
  rtDW.Sine = rtConstP.pooled32[Cosine_tmp];
}

/* System initialize for atomic system: '<S95>/HIGH_SMO' */
void HIGH_SMO_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S177>/Integrator' */
  rtDW.Integrator_DSTATE_i = 1.0F;
}

/* Enable for atomic system: '<S95>/HIGH_SMO' */
void HIGH_SMO_Enable(void)
{
  /* Enable for DiscreteIntegrator: '<S134>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S136>/Integrator2' */
  rtDW.Integrator2_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S135>/Integrator1' */
  rtDW.Integrator1_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S137>/Integrator3' */
  rtDW.Integrator3_SYSTEM_ENABLE = 1U;
}

/* Output and update for atomic system: '<S95>/HIGH_SMO' */
void HIGH_SMO(void)
{
  int32_T tmp;
  real32_T Integrator;
  real32_T Integrator3;
  real32_T rtb_Gain8;
  real32_T rtb_Gain9;
  real32_T rtb_IProdOut;
  real32_T rtb_Integrator;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_Sum_fh;
  boolean_T rtb_NotEqual;

  /* UnitDelay: '<S134>/Unit Delay' */
  rtb_SignPreIntegrator = rtDW.UnitDelay_DSTATE_k;

  /* UnitDelay: '<S135>/Unit Delay1' */
  rtb_Sum_fh = rtDW.UnitDelay1_DSTATE_e;

  /* Sum: '<S102>/Add1' incorporates:
   *  UnitDelay: '<S138>/Unit Delay'
   */
  rtDW.Add1_c = rtDW.UnitDelay_DSTATE_h;

  /* UnitDelay: '<S136>/Unit Delay2' */
  rtb_Integrator = rtDW.UnitDelay2_DSTATE_e;

  /* Sum: '<S99>/Sum2' */
  rtb_IProdOut = rtb_SignPreIntegrator - Ialpha;

  /* Signum: '<S99>/Sign' */
  if (rtb_IProdOut < 0.0F) {
    rtb_IProdOut = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_IProdOut = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_IProdOut = 0.0F;
  } else {
    rtb_IProdOut = (rtNaNF);
  }

  /* End of Signum: '<S99>/Sign' */

  /* DiscreteIntegrator: '<S134>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S134>/Integrator' */
    Integrator = rtDW.Integrator_DSTATE_n;
  } else {
    /* DiscreteIntegrator: '<S134>/Integrator' incorporates:
     *  Gain: '<S134>/Gain'
     *  Gain: '<S134>/Gain1'
     *  Gain: '<S134>/Gain17'
     *  Gain: '<S134>/Gain2'
     *  Gain: '<S134>/Gain4'
     *  Product: '<S134>/Product'
     *  Sum: '<S134>/Add'
     */
    Integrator = ((((250.0F * rtDW.Add3 - 100.0F * rtb_SignPreIntegrator) -
                    rtb_Sum_fh * rtDW.Add1_c * -0.05F) - 250.0F * rtb_Integrator)
                  - SMO_Parameter.SMO_K / 0.004F * rtb_IProdOut) * 0.0001F +
      rtDW.Integrator_DSTATE_n;
  }

  /* End of DiscreteIntegrator: '<S134>/Integrator' */

  /* Gain: '<S136>/Gain9' */
  rtb_Gain9 = SMO_Parameter.SMO_M / 0.004F * rtb_IProdOut;

  /* UnitDelay: '<S137>/Unit Delay3' */
  rtb_IProdOut = rtDW.UnitDelay3_DSTATE_n;

  /* DiscreteIntegrator: '<S136>/Integrator2' */
  if (rtDW.Integrator2_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S136>/Integrator2' */
    rtb_Gain9 = rtDW.Integrator2_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S136>/Integrator2' incorporates:
     *  Product: '<S136>/Product2'
     *  Sum: '<S136>/Add2'
     */
    rtb_Gain9 = (rtb_Gain9 - rtDW.Add1_c * rtb_IProdOut) * 0.0001F +
      rtDW.Integrator2_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S136>/Integrator2' */

  /* Gain: '<S135>/Gain8' */
  rtb_Gain8 = 100.0F * rtb_Sum_fh;

  /* Sum: '<S99>/Sum6' */
  rtb_Sum_fh -= Ibeta;

  /* Signum: '<S99>/Sign1' */
  if (rtb_Sum_fh < 0.0F) {
    rtb_Sum_fh = -1.0F;
  } else if (rtb_Sum_fh > 0.0F) {
    rtb_Sum_fh = 1.0F;
  } else if (rtb_Sum_fh == 0.0F) {
    rtb_Sum_fh = 0.0F;
  } else {
    rtb_Sum_fh = (rtNaNF);
  }

  /* End of Signum: '<S99>/Sign1' */

  /* DiscreteIntegrator: '<S135>/Integrator1' */
  if (rtDW.Integrator1_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S135>/Integrator1' */
    rtb_Gain8 = rtDW.Integrator1_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S135>/Integrator1' incorporates:
     *  Gain: '<S135>/Gain3'
     *  Gain: '<S135>/Gain5'
     *  Gain: '<S135>/Gain6'
     *  Gain: '<S135>/Gain7'
     *  Product: '<S135>/Product1'
     *  Sum: '<S135>/Add1'
     */
    rtb_Gain8 = ((((rtb_SignPreIntegrator * rtDW.Add1_c * -0.05F - rtb_Gain8) -
                   250.0F * rtb_IProdOut) + 250.0F * rtDW.Add4) -
                 SMO_Parameter.SMO_K / 0.004F * rtb_Sum_fh) * 0.0001F +
      rtDW.Integrator1_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S135>/Integrator1' */

  /* DiscreteIntegrator: '<S137>/Integrator3' */
  if (rtDW.Integrator3_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S137>/Integrator3' */
    Integrator3 = rtDW.Integrator3_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S137>/Integrator3' incorporates:
     *  Gain: '<S137>/Gain10'
     *  Product: '<S137>/Product3'
     *  Sum: '<S137>/Add3'
     */
    Integrator3 = (SMO_Parameter.SMO_K / 0.004F * rtb_Sum_fh + rtDW.Add1_c *
                   rtb_Integrator) * 0.0001F + rtDW.Integrator3_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S137>/Integrator3' */

  /* UnitDelay: '<S142>/Unit Delay' */
  rtDW.UnitDelay = rtDW.UnitDelay_DSTATE_j;

  /* Outputs for Atomic SubSystem: '<S138>/Sine_Cosine' */
  Sine_Cosine();

  /* End of Outputs for SubSystem: '<S138>/Sine_Cosine' */

  /* If: '<S143>/If' incorporates:
   *  Constant: '<S198>/Constant'
   *  Constant: '<S199>/Constant'
   *  SignalConversion generated from: '<S198>/Out1'
   *  SignalConversion generated from: '<S199>/Out1'
   */
  if (rtDW.Add1_c > 0.0F) {
    /* Outputs for IfAction SubSystem: '<S143>/If Action Subsystem' incorporates:
     *  ActionPort: '<S198>/Action Port'
     */
    tmp = 1;

    /* End of Outputs for SubSystem: '<S143>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S143>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S199>/Action Port'
     */
    tmp = -1;

    /* End of Outputs for SubSystem: '<S143>/If Action Subsystem1' */
  }

  /* End of If: '<S143>/If' */

  /* Product: '<S143>/Product' incorporates:
   *  Product: '<S138>/Product1'
   *  Product: '<S138>/Product2'
   *  Sum: '<S138>/Sum'
   */
  rtb_IProdOut = ((0.0F - rtDW.Cosine * rtb_Integrator) - rtb_IProdOut *
                  rtDW.Sine) * (real32_T)tmp;

  /* Sum: '<S186>/Sum' incorporates:
   *  Constant: '<S138>/Kp'
   *  DiscreteIntegrator: '<S177>/Integrator'
   *  Product: '<S182>/PProd Out'
   */
  rtb_Sum_fh = 1.414F * SMO_Parameter.SMO_PLL_W * rtb_IProdOut +
    rtDW.Integrator_DSTATE_i;

  /* DeadZone: '<S170>/DeadZone' */
  if (rtb_Sum_fh > 3141.59277F) {
    rtb_SignPreIntegrator = rtb_Sum_fh - 3141.59277F;
  } else if (rtb_Sum_fh >= -3141.59277F) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = rtb_Sum_fh - -3141.59277F;
  }

  /* End of DeadZone: '<S170>/DeadZone' */

  /* RelationalOperator: '<S168>/NotEqual' incorporates:
   *  Gain: '<S168>/ZeroGain'
   */
  rtb_NotEqual = (0.0F * rtb_Sum_fh != rtb_SignPreIntegrator);

  /* Signum: '<S168>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0F) {
    rtb_SignPreIntegrator = -1.0F;
  } else if (rtb_SignPreIntegrator > 0.0F) {
    rtb_SignPreIntegrator = 1.0F;
  } else if (rtb_SignPreIntegrator == 0.0F) {
    rtb_SignPreIntegrator = 0.0F;
  } else {
    rtb_SignPreIntegrator = (rtNaNF);
  }

  /* End of Signum: '<S168>/SignPreSat' */

  /* Product: '<S174>/IProd Out' incorporates:
   *  Constant: '<S138>/Ki'
   */
  rtb_IProdOut *= SMO_Parameter.SMO_PLL_W * SMO_Parameter.SMO_PLL_W;

  /* Saturate: '<S184>/Saturation' */
  if (rtb_Sum_fh > 3141.59277F) {
    rtb_Sum_fh = 3141.59277F;
  } else {
    if (rtb_Sum_fh < -3141.59277F) {
      rtb_Sum_fh = -3141.59277F;
    }
  }

  /* End of Saturate: '<S184>/Saturation' */

  /* Sum: '<S142>/Sum1' incorporates:
   *  Gain: '<S142>/Ts'
   */
  rtb_Integrator = 0.0001F * rtb_Sum_fh + rtDW.UnitDelay;

  /* Update for UnitDelay: '<S134>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_k = Integrator;

  /* Update for UnitDelay: '<S135>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE_e = rtb_Gain8;

  /* Update for UnitDelay: '<S138>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_h = rtb_Sum_fh;

  /* Update for UnitDelay: '<S136>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE_e = rtb_Gain9;

  /* Update for DiscreteIntegrator: '<S134>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 0U;
  rtDW.Integrator_DSTATE_n = Integrator;

  /* Update for UnitDelay: '<S137>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE_n = Integrator3;

  /* Update for DiscreteIntegrator: '<S136>/Integrator2' */
  rtDW.Integrator2_SYSTEM_ENABLE = 0U;
  rtDW.Integrator2_DSTATE = rtb_Gain9;

  /* Update for DiscreteIntegrator: '<S135>/Integrator1' */
  rtDW.Integrator1_SYSTEM_ENABLE = 0U;
  rtDW.Integrator1_DSTATE = rtb_Gain8;

  /* Update for DiscreteIntegrator: '<S137>/Integrator3' */
  rtDW.Integrator3_SYSTEM_ENABLE = 0U;
  rtDW.Integrator3_DSTATE = Integrator3;

  /* If: '<S194>/If' incorporates:
   *  Constant: '<S194>/Constant'
   *  Constant: '<S194>/Constant1'
   *  RelationalOperator: '<S194>/Relational Operator'
   *  RelationalOperator: '<S194>/Relational Operator1'
   */
  if (rtb_Integrator > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S194>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    /* Update for UnitDelay: '<S142>/Unit Delay' incorporates:
     *  Constant: '<S196>/Constant'
     *  Sum: '<S196>/Sum'
     */
    rtDW.UnitDelay_DSTATE_j = rtb_Integrator - 6.28318548F;

    /* End of Outputs for SubSystem: '<S194>/If Action Subsystem1' */
  } else if (rtb_Integrator < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S194>/If Action Subsystem' incorporates:
     *  ActionPort: '<S195>/Action Port'
     */
    /* Update for UnitDelay: '<S142>/Unit Delay' incorporates:
     *  Constant: '<S195>/Constant'
     *  Sum: '<S195>/Sum'
     */
    rtDW.UnitDelay_DSTATE_j = rtb_Integrator + 6.28318548F;

    /* End of Outputs for SubSystem: '<S194>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S194>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S197>/Action Port'
     */
    /* Update for UnitDelay: '<S142>/Unit Delay' incorporates:
     *  Inport: '<S197>/In1'
     */
    rtDW.UnitDelay_DSTATE_j = rtb_Integrator;

    /* End of Outputs for SubSystem: '<S194>/If Action Subsystem2' */
  }

  /* End of If: '<S194>/If' */

  /* Signum: '<S168>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    rtb_Sum_fh = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_Sum_fh = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_Sum_fh = 0.0F;
  } else {
    rtb_Sum_fh = (rtNaNF);
  }

  /* End of Signum: '<S168>/SignPreIntegrator' */

  /* Switch: '<S168>/Switch' incorporates:
   *  Constant: '<S168>/Constant1'
   *  DataTypeConversion: '<S168>/DataTypeConv1'
   *  DataTypeConversion: '<S168>/DataTypeConv2'
   *  Logic: '<S168>/AND3'
   *  RelationalOperator: '<S168>/Equal1'
   */
  if (rtb_NotEqual && ((int8_T)rtb_SignPreIntegrator == (int8_T)rtb_Sum_fh)) {
    rtb_IProdOut = 0.0F;
  }

  /* End of Switch: '<S168>/Switch' */

  /* Update for DiscreteIntegrator: '<S177>/Integrator' */
  rtDW.Integrator_DSTATE_i += 0.0001F * rtb_IProdOut;
}

/* Output and update for atomic system: '<S95>/Inverse_Park_Transform' */
void Inverse_Park_Transform(void)
{
  /* Sum: '<S101>/Add' incorporates:
   *  Product: '<S101>/Product1'
   *  Product: '<S101>/Product2'
   *  Sum: '<S101>/Add1'
   */
  V_alpha = Vd_voltage * rtDW.Add1_c - Vq_voltage * rtDW.Add4;

  /* Sum: '<S101>/Add3' incorporates:
   *  Product: '<S101>/Product3'
   *  Product: '<S101>/Product4'
   *  Sum: '<S101>/Add2'
   */
  V_beta = Vd_voltage * rtDW.Add4 + Vq_voltage * rtDW.Add1_c;
}

/* Output and update for atomic system: '<S95>/Park_Transform' */
void Park_Transform(void)
{
  /* Sum: '<S104>/Add1' incorporates:
   *  Product: '<S104>/Product1'
   *  Product: '<S104>/Product2'
   */
  Id_measured = Ialpha * rtDW.Add1_c + Ibeta * rtDW.Add4;

  /* Sum: '<S104>/Add2' incorporates:
   *  Product: '<S104>/Produc3t'
   *  Product: '<S104>/Product4'
   */
  Iq_measured = Ibeta * rtDW.Add1_c - Ialpha * rtDW.Add4;
}

/* Output and update for atomic system: '<S95>/Q_Current_PI' */
void Q_Current_PI(void)
{
  real32_T Merge1_d;
  real32_T Merge_hp;
  real32_T rtb_Add_it;
  real32_T rtb_Switch_k;

  /* Sum: '<S105>/Add2' */
  rtb_Switch_k = Iq_ref - Iq_measured;

  /* DiscreteIntegrator: '<S200>/Discrete-Time Integrator' */
  if ((rtDW.Merge1_a != 0) || (rtDW.DiscreteTimeIntegrator_PrevResetState_p != 0))
  {
    rtDW.DiscreteTimeIntegrator_DSTATE_i = 0.0F;
  }

  /* Sum: '<S200>/Add' incorporates:
   *  Constant: '<S200>/Kp'
   *  DiscreteIntegrator: '<S200>/Discrete-Time Integrator'
   *  Product: '<S200>/Product'
   */
  rtb_Add_it = PI_Parameter.IQ_Kp * rtb_Switch_k +
    rtDW.DiscreteTimeIntegrator_DSTATE_i;

  /* If: '<S200>/If1' incorporates:
   *  Constant: '<S200>/Over_modulation'
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (CTL_Parameter.Over_modulation) {
    /* Outputs for IfAction SubSystem: '<S200>/Over_M' incorporates:
     *  ActionPort: '<S202>/Action Port'
     */
    Over_M(rtU.Bus_Voltage, &Merge_hp, &Merge1_d);

    /* End of Outputs for SubSystem: '<S200>/Over_M' */
  } else {
    /* Outputs for IfAction SubSystem: '<S200>/Normal' incorporates:
     *  ActionPort: '<S201>/Action Port'
     */
    Normal(rtU.Bus_Voltage, &Merge_hp, &Merge1_d);

    /* End of Outputs for SubSystem: '<S200>/Normal' */
  }

  /* End of If: '<S200>/If1' */

  /* Switch: '<S203>/Switch2' incorporates:
   *  RelationalOperator: '<S203>/LowerRelop1'
   *  RelationalOperator: '<S203>/UpperRelop'
   *  Switch: '<S203>/Switch'
   */
  if (rtb_Add_it > Merge_hp) {
    Vq_voltage = Merge_hp;
  } else if (rtb_Add_it < Merge1_d) {
    /* Switch: '<S203>/Switch' */
    Vq_voltage = Merge1_d;
  } else {
    Vq_voltage = rtb_Add_it;
  }

  /* End of Switch: '<S203>/Switch2' */

  /* Switch: '<S200>/Switch' incorporates:
   *  Constant: '<S200>/Cons'
   *  UnitDelay: '<S200>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_i) {
    rtb_Switch_k = 0.0F;
  }

  /* End of Switch: '<S200>/Switch' */

  /* Update for DiscreteIntegrator: '<S200>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S200>/Ki'
   *  Product: '<S200>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_i += PI_Parameter.IQ_Ki * rtb_Switch_k *
    0.0001F;
  rtDW.DiscreteTimeIntegrator_PrevResetState_p = (int8_T)(rtDW.Merge1_a > 0);

  /* Update for UnitDelay: '<S200>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S200>/Relational Operator1'
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

  /* Outputs for Atomic SubSystem: '<S106>/XYZ Caculate' */
  /* Outputs for Atomic SubSystem: '<S106>/N Sector  Caculate' */
  /* Gain: '<S206>/Gain' incorporates:
   *  Gain: '<S209>/Gain'
   */
  rtb_Gain_a = 1.73205078F * rtDW.Add3;

  /* End of Outputs for SubSystem: '<S106>/XYZ Caculate' */

  /* Saturate: '<S206>/Saturation' incorporates:
   *  Gain: '<S206>/Gain'
   *  Gain: '<S206>/Gain1'
   *  Gain: '<S206>/Gain2'
   *  Sum: '<S206>/Add'
   *  Sum: '<S206>/Add1'
   *  Sum: '<S206>/Add2'
   *  Switch: '<S206>/Switch'
   *  Switch: '<S206>/Switch1'
   *  Switch: '<S206>/Switch2'
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

  /* End of Saturate: '<S206>/Saturation' */
  /* End of Outputs for SubSystem: '<S106>/N Sector  Caculate' */

  /* Outputs for Atomic SubSystem: '<S106>/XYZ Caculate' */
  /* Saturate: '<S209>/Saturation' incorporates:
   *  Inport: '<Root>/Bus_Voltage'
   */
  if (rtU.Bus_Voltage > 1200.0F) {
    rtb_Add1_n = 1200.0F;
  } else if (rtU.Bus_Voltage < 0.0001F) {
    rtb_Add1_n = 0.0001F;
  } else {
    rtb_Add1_n = rtU.Bus_Voltage;
  }

  /* End of Saturate: '<S209>/Saturation' */

  /* Product: '<S209>/Divide' incorporates:
   *  Constant: '<S209>/Constant'
   *  Constant: '<S95>/Constant4'
   */
  rtb_Add1_n = 0.000173205073F / rtb_Add1_n;

  /* End of Outputs for SubSystem: '<S106>/XYZ Caculate' */

  /* Outputs for Atomic SubSystem: '<S106>/T1 T2  Caculate' */
  /* MultiPortSwitch: '<S207>/Index Vector' incorporates:
   *  Gain: '<S207>/Gain'
   *  Gain: '<S207>/Gain1'
   *  Gain: '<S207>/Gain2'
   *  Gain: '<S209>/Gain1'
   *  Gain: '<S209>/Gain2'
   *  Product: '<S209>/Product'
   *  Product: '<S209>/Product1'
   *  Product: '<S209>/Product2'
   *  Sum: '<S209>/Add1'
   *  Sum: '<S209>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    /* Outputs for Atomic SubSystem: '<S106>/XYZ Caculate' */
    rtb_IndexVector_c = (rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_n;

    /* MultiPortSwitch: '<S207>/Index Vector1' incorporates:
     *  Gain: '<S209>/Gain1'
     *  Gain: '<S209>/Gain2'
     *  Product: '<S209>/Product1'
     *  Product: '<S209>/Product2'
     *  Sum: '<S209>/Add1'
     *  Sum: '<S209>/Add2'
     */
    rtb_Gain_a = ((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S106>/XYZ Caculate' */
    break;

   case 2:
    /* Outputs for Atomic SubSystem: '<S106>/XYZ Caculate' */
    rtb_IndexVector_c = ((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_n;

    /* MultiPortSwitch: '<S207>/Index Vector1' incorporates:
     *  Gain: '<S207>/Gain'
     *  Gain: '<S209>/Gain2'
     *  Product: '<S209>/Product'
     *  Product: '<S209>/Product1'
     *  Sum: '<S209>/Add2'
     */
    rtb_Gain_a = -(rtDW.Add4 * rtb_Add1_n);

    /* End of Outputs for SubSystem: '<S106>/XYZ Caculate' */
    break;

   case 3:
    /* Outputs for Atomic SubSystem: '<S106>/XYZ Caculate' */
    rtb_IndexVector_c = -((rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_n);

    /* MultiPortSwitch: '<S207>/Index Vector1' incorporates:
     *  Gain: '<S207>/Gain2'
     *  Gain: '<S209>/Gain1'
     *  Product: '<S209>/Product'
     *  Product: '<S209>/Product2'
     *  Sum: '<S209>/Add1'
     */
    rtb_Gain_a = rtDW.Add4 * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S106>/XYZ Caculate' */
    break;

   case 4:
    /* Outputs for Atomic SubSystem: '<S106>/XYZ Caculate' */
    rtb_IndexVector_c = -(rtDW.Add4 * rtb_Add1_n);

    /* MultiPortSwitch: '<S207>/Index Vector1' incorporates:
     *  Gain: '<S207>/Gain'
     *  Gain: '<S209>/Gain1'
     *  Product: '<S209>/Product'
     *  Product: '<S209>/Product2'
     *  Sum: '<S209>/Add1'
     */
    rtb_Gain_a = (rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S106>/XYZ Caculate' */
    break;

   case 5:
    /* Outputs for Atomic SubSystem: '<S106>/XYZ Caculate' */
    rtb_IndexVector_c = rtDW.Add4 * rtb_Add1_n;

    /* MultiPortSwitch: '<S207>/Index Vector1' incorporates:
     *  Gain: '<S207>/Gain1'
     *  Gain: '<S209>/Gain2'
     *  Product: '<S209>/Product'
     *  Product: '<S209>/Product1'
     *  Sum: '<S209>/Add2'
     */
    rtb_Gain_a = -(((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_n);

    /* End of Outputs for SubSystem: '<S106>/XYZ Caculate' */
    break;

   default:
    /* Outputs for Atomic SubSystem: '<S106>/XYZ Caculate' */
    rtb_IndexVector_c = -(((0.0F - rtDW.Add4) - rtb_Gain_a) * -0.5F * rtb_Add1_n);

    /* MultiPortSwitch: '<S207>/Index Vector1' incorporates:
     *  Gain: '<S207>/Gain1'
     *  Gain: '<S207>/Gain2'
     *  Gain: '<S209>/Gain1'
     *  Gain: '<S209>/Gain2'
     *  Product: '<S209>/Product1'
     *  Product: '<S209>/Product2'
     *  Sum: '<S209>/Add1'
     *  Sum: '<S209>/Add2'
     */
    rtb_Gain_a = -((rtb_Gain_a - rtDW.Add4) * -0.5F * rtb_Add1_n);

    /* End of Outputs for SubSystem: '<S106>/XYZ Caculate' */
    break;
  }

  /* End of MultiPortSwitch: '<S207>/Index Vector' */

  /* Sum: '<S207>/Add' */
  rtb_Add1_n = rtb_IndexVector_c + rtb_Gain_a;

  /* Switch: '<S207>/Switch' incorporates:
   *  Constant: '<S95>/Constant4'
   *  Product: '<S207>/Divide'
   *  Product: '<S207>/Divide1'
   *  Sum: '<S207>/Add1'
   *  Switch: '<S207>/Switch2'
   */
  if (!(0.0001F - rtb_Add1_n > 0.0F)) {
    rtb_IndexVector_c = rtb_IndexVector_c * 0.0001F / rtb_Add1_n;
    rtb_Gain_a *= 1.0F / rtb_Add1_n * 0.0001F;
  }

  /* End of Switch: '<S207>/Switch' */
  /* End of Outputs for SubSystem: '<S106>/T1 T2  Caculate' */

  /* Outputs for Atomic SubSystem: '<S106>/Tcm calculate' */
  /* Gain: '<S208>/Gain2' incorporates:
   *  Constant: '<S95>/Constant4'
   *  Sum: '<S208>/Add'
   */
  rtb_Add1_n = ((0.0001F - rtb_IndexVector_c) - rtb_Gain_a) * 0.25F;

  /* Sum: '<S208>/Add1' incorporates:
   *  Gain: '<S208>/Gain'
   */
  rtb_IndexVector_c = 0.5F * rtb_IndexVector_c + rtb_Add1_n;

  /* MultiPortSwitch: '<S208>/Index Vector' incorporates:
   *  Gain: '<S208>/Gain1'
   *  Sum: '<S208>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S208>/Index Vector1' */
    rtb_IndexVector1 = rtb_Add1_n;

    /* MultiPortSwitch: '<S208>/Index Vector2' incorporates:
     *  Gain: '<S208>/Gain1'
     *  Sum: '<S208>/Add2'
     */
    rtb_Add1_n = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 2:
    rtb_Saturation = rtb_Add1_n;

    /* MultiPortSwitch: '<S208>/Index Vector1' incorporates:
     *  Gain: '<S208>/Gain1'
     *  Sum: '<S208>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S208>/Index Vector2' */
    rtb_Add1_n = rtb_IndexVector_c;
    break;

   case 3:
    rtb_Saturation = rtb_Add1_n;

    /* MultiPortSwitch: '<S208>/Index Vector1' */
    rtb_IndexVector1 = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S208>/Index Vector2' incorporates:
     *  Gain: '<S208>/Gain1'
     *  Sum: '<S208>/Add2'
     */
    rtb_Add1_n = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;

   case 4:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S208>/Index Vector1' incorporates:
     *  Gain: '<S208>/Gain1'
     *  Sum: '<S208>/Add2'
     */
    rtb_IndexVector1 = rtb_IndexVector_c;
    break;

   case 5:
    rtb_Saturation = 0.5F * rtb_Gain_a + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S208>/Index Vector1' incorporates:
     *  Gain: '<S208>/Gain1'
     *  Sum: '<S208>/Add2'
     */
    rtb_IndexVector1 = rtb_Add1_n;

    /* MultiPortSwitch: '<S208>/Index Vector2' */
    rtb_Add1_n = rtb_IndexVector_c;
    break;

   default:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S208>/Index Vector1' incorporates:
     *  Gain: '<S208>/Gain1'
     *  Sum: '<S208>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_a + rtb_IndexVector_c;
    break;
  }

  /* End of MultiPortSwitch: '<S208>/Index Vector' */
  /* End of Outputs for SubSystem: '<S106>/Tcm calculate' */

  /* If: '<S106>/If1' */
  if (rtDW.Merge1_a == 0) {
    /* Outputs for IfAction SubSystem: '<S106>/Enable_Motor' incorporates:
     *  ActionPort: '<S205>/Action Port'
     */
    /* Merge: '<S106>/Merge' incorporates:
     *  Gain: '<S106>/Gain'
     *  Inport: '<S205>/In1'
     */
    rtDW.Merge_c4 = 8.399E+7F * rtb_Saturation;

    /* Merge: '<S106>/Merge1' incorporates:
     *  Gain: '<S106>/Gain2'
     *  Inport: '<S205>/In2'
     */
    rtDW.Merge1_h = 8.399E+7F * rtb_IndexVector1;

    /* Merge: '<S106>/Merge2' incorporates:
     *  Gain: '<S106>/Gain3'
     *  Inport: '<S205>/In3'
     */
    rtDW.Merge2_d = 8.399E+7F * rtb_Add1_n;

    /* End of Outputs for SubSystem: '<S106>/Enable_Motor' */
  } else {
    if (rtDW.Merge1_a == 1) {
      /* Outputs for IfAction SubSystem: '<S106>/Disable_Motor' incorporates:
       *  ActionPort: '<S204>/Action Port'
       */
      /* Merge: '<S106>/Merge' incorporates:
       *  Constant: '<S204>/Constant'
       *  SignalConversion generated from: '<S204>/Out1'
       */
      rtDW.Merge_c4 = 0.0F;

      /* Merge: '<S106>/Merge1' incorporates:
       *  Constant: '<S204>/Constant1'
       *  SignalConversion generated from: '<S204>/Out2'
       */
      rtDW.Merge1_h = 0.0F;

      /* Merge: '<S106>/Merge2' incorporates:
       *  Constant: '<S204>/Constant2'
       *  SignalConversion generated from: '<S204>/Out3'
       */
      rtDW.Merge2_d = 0.0F;

      /* End of Outputs for SubSystem: '<S106>/Disable_Motor' */
    }
  }

  /* End of If: '<S106>/If1' */
}

/* Output and update for atomic system: '<S95>/Sine_Cosine' */
void Sine_Cosine_m(void)
{
  real32_T rtb_Saturation;
  uint32_T Add1_c_tmp;

  /* Saturate: '<S107>/Saturation' */
  if (rtDW.Merge_g > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Merge_g < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Merge_g;
  }

  /* End of Saturate: '<S107>/Saturation' */

  /* Lookup_n-D: '<S107>/Cosine' incorporates:
   *  Lookup_n-D: '<S107>/Sine'
   *  Saturate: '<S107>/Saturation'
   */
  Add1_c_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);
  rtDW.Add1_c = rtConstP.pooled30[Add1_c_tmp];

  /* Lookup_n-D: '<S107>/Sine' */
  rtDW.Add4 = rtConstP.pooled32[Add1_c_tmp];
}

/* System initialize for atomic system: '<S5>/FOC' */
void FOC_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S95>/HIGH_SMO' */
  HIGH_SMO_Init();

  /* End of SystemInitialize for SubSystem: '<S95>/HIGH_SMO' */
}

/* Enable for atomic system: '<S5>/FOC' */
void FOC_Enable(void)
{
  /* Enable for Atomic SubSystem: '<S95>/HIGH_SMO' */
  HIGH_SMO_Enable();

  /* End of Enable for SubSystem: '<S95>/HIGH_SMO' */
}

/* Output and update for atomic system: '<S5>/FOC' */
void FOC(void)
{
  real32_T rtb_UnitDelay_ad;

  /* Constant: '<S95>/Constant3' */
  rtDW.Constant3 = Dead_Com_Enable;

  /* Outputs for Atomic SubSystem: '<S95>/Clarke_Transform' */
  Clarke_Transform();

  /* End of Outputs for SubSystem: '<S95>/Clarke_Transform' */

  /* If: '<S95>/If1' incorporates:
   *  Constant: '<S95>/SMO_Enable'
   *  Inport: '<S100>/Hall_Angle'
   *  Inport: '<S103>/Obs_Angle'
   *  UnitDelay: '<S95>/Unit Delay2'
   */
  if (SMO_Parameter.SMO_Theta_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S95>/Obs_Angle' incorporates:
     *  ActionPort: '<S103>/Action Port'
     */
    rtDW.Merge_g = rtDW.UnitDelay2_DSTATE_k;

    /* End of Outputs for SubSystem: '<S95>/Obs_Angle' */
  } else {
    if (SMO_Parameter.SMO_Theta_Enable == 0) {
      /* Outputs for IfAction SubSystem: '<S95>/Hall_Angle' incorporates:
       *  ActionPort: '<S100>/Action Port'
       */
      rtDW.Merge_g = rtDW.Merge1_i;

      /* End of Outputs for SubSystem: '<S95>/Hall_Angle' */
    }
  }

  /* End of If: '<S95>/If1' */

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

  /* Outputs for Atomic SubSystem: '<S95>/HIGH_SMO' */
  HIGH_SMO();

  /* End of Outputs for SubSystem: '<S95>/HIGH_SMO' */

  /* UnitDelay: '<S102>/Unit Delay' */
  rtb_UnitDelay_ad = rtDW.UnitDelay_DSTATE_fl;

  /* Sum: '<S102>/Add1' incorporates:
   *  Constant: '<S102>/Constant1'
   *  Gain: '<S95>/Gain1'
   *  Product: '<S102>/Divide1'
   *  Sum: '<S102>/Add'
   */
  rtDW.Add1_c = (4.77464819F * rtDW.Add1_c - rtb_UnitDelay_ad) * SpeedFilter_Fn
    + rtb_UnitDelay_ad;

  /* Outputs for Atomic SubSystem: '<S95>/SVPWM' */
  SVPWM();

  /* End of Outputs for SubSystem: '<S95>/SVPWM' */

  /* Update for UnitDelay: '<S95>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE_k = rtDW.UnitDelay;

  /* Update for UnitDelay: '<S102>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_fl = rtDW.Add1_c;
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
