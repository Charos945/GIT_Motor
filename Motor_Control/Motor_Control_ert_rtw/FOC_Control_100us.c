/*
 * File: FOC_Control_100us.c
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

#include "FOC_Control_100us.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Output and update for atomic system: '<S183>/Angle_set' */
void Angle_set(void)
{
  /* If: '<S186>/If1' incorporates:
   *  Constant: '<S186>/HFI_AngleEnable'
   */
  if (HFI.Angle_Enable == 1) {
    /* Outputs for IfAction SubSystem: '<S186>/Subsystem' incorporates:
     *  ActionPort: '<S198>/Action Port'
     */
    /* If: '<S198>/If1' */
    if (rtDW.HFI_state == 3) {
      /* Outputs for IfAction SubSystem: '<S198>/Subsystem1' incorporates:
       *  ActionPort: '<S200>/Action Port'
       */
      /* Merge: '<S183>/Merge' incorporates:
       *  Inport: '<S200>/HFI_Angle'
       */
      rtDW.Merge_b = rtDW.Merge2_j;

      /* End of Outputs for SubSystem: '<S198>/Subsystem1' */
    } else {
      if (rtDW.HFI_state < 3) {
        /* Outputs for IfAction SubSystem: '<S198>/Subsystem2' incorporates:
         *  ActionPort: '<S201>/Action Port'
         */
        /* Merge: '<S183>/Merge' incorporates:
         *  Inport: '<S201>/IPD_Angle'
         */
        rtDW.Merge_b = rtDW.IPD_angle;

        /* End of Outputs for SubSystem: '<S198>/Subsystem2' */
      }
    }

    /* End of If: '<S198>/If1' */
    /* End of Outputs for SubSystem: '<S186>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S186>/Subsystem1' incorporates:
     *  ActionPort: '<S199>/Action Port'
     */
    /* Merge: '<S183>/Merge' incorporates:
     *  Inport: '<S199>/Reso_angle'
     */
    rtDW.Merge_b = rtDW.Merge1;

    /* End of Outputs for SubSystem: '<S186>/Subsystem1' */
  }

  /* End of If: '<S186>/If1' */
}

/* Output and update for atomic system: '<S183>/Clarke_Transform' */
void Clarke_Transform(void)
{
  /* Outputs for Atomic SubSystem: '<S187>/Clark1' */
  /* Gain: '<S202>/Gain2' incorporates:
   *  Gain: '<S202>/Gain'
   *  Gain: '<S202>/Gain1'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S202>/Add'
   */
  rtDW.Gain2_d = ((rtU.Phase_CurrentABC[0] - 0.5F * rtU.Phase_CurrentABC[1]) -
                  0.5F * rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* Gain: '<S202>/Gain5' incorporates:
   *  Gain: '<S202>/Gain3'
   *  Gain: '<S202>/Gain4'
   *  Inport: '<Root>/Phase_CurrentABC'
   *  Sum: '<S202>/Add1'
   */
  rtDW.Gain5 = (0.866025388F * rtU.Phase_CurrentABC[1] - 0.866025388F *
                rtU.Phase_CurrentABC[2]) * 0.816496611F;

  /* End of Outputs for SubSystem: '<S187>/Clark1' */
}

/* Disable for atomic system: '<S183>/D_Current_PI' */
void D_Current_PI_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S203>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_jc = rtDW.DiscreteTimeIntegrator_ac;
}

/* Output and update for atomic system: '<S183>/D_Current_PI' */
void D_Current_PI(void)
{
  real32_T rtb_Add;
  real32_T rtb_Switch;

  /* Sum: '<S188>/Add2' incorporates:
   *  Outport: '<Root>/Tc'
   */
  rtb_Switch = rtY.Tc - rtDW.Add1;

  /* DiscreteIntegrator: '<S203>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_ac = rtDW.DiscreteTimeIntegrator_DSTATE_jc;

  /* Sum: '<S203>/Add' incorporates:
   *  Constant: '<S203>/Kp'
   *  Product: '<S203>/Product'
   */
  rtb_Add = ctrlParamsPI.ID_Current_PI_Kp * rtb_Switch +
    rtDW.DiscreteTimeIntegrator_ac;

  /* Saturate: '<S203>/Saturation' */
  if (rtb_Add > ctrlParamsPI.ID_Current_PI_OutputMax) {
    /* Saturate: '<S203>/Saturation' */
    rtDW.Saturation_l = ctrlParamsPI.ID_Current_PI_OutputMax;
  } else if (rtb_Add < ctrlParamsPI.ID_Current_PI_OutputMin) {
    /* Saturate: '<S203>/Saturation' */
    rtDW.Saturation_l = ctrlParamsPI.ID_Current_PI_OutputMin;
  } else {
    /* Saturate: '<S203>/Saturation' */
    rtDW.Saturation_l = rtb_Add;
  }

  /* End of Saturate: '<S203>/Saturation' */

  /* Switch: '<S203>/Switch' incorporates:
   *  Constant: '<S203>/Cons'
   *  UnitDelay: '<S203>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_k2) {
    rtb_Switch = 0.0F;
  }

  /* End of Switch: '<S203>/Switch' */

  /* Update for DiscreteIntegrator: '<S203>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S203>/Ki'
   *  Product: '<S203>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_jc += ctrlParamsPI.ID_Current_PI_Ki *
    rtb_Switch * 0.0001F;

  /* Update for UnitDelay: '<S203>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S203>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_k2 = (rtb_Add == rtDW.Saturation_l);
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T tmp;
  real32_T tmp_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

/* Disable for atomic system: '<S204>/Flux_weak' */
void Flux_weak_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S207>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_b = rtDW.DiscreteTimeIntegrator_lp;
}

/* Output and update for atomic system: '<S204>/Flux_weak' */
void Flux_weak_a(void)
{
  real32_T rtb_Add;
  real32_T rtb_Saturation;
  real32_T tmp;

  /* Fcn: '<S206>/Fcn' incorporates:
   *  Outport: '<Root>/Tc'
   */
  rtb_Saturation = rt_powf_snf(rtDW.Add2_f, 2.0F) + rt_powf_snf(rtY.Tc, 2.0F);
  if (rtb_Saturation < 0.0F) {
    rtb_Saturation = -(real32_T)sqrt(-rtb_Saturation);
  } else {
    rtb_Saturation = (real32_T)sqrt(rtb_Saturation);
  }

  /* End of Fcn: '<S206>/Fcn' */

  /* Switch: '<S207>/Switch' incorporates:
   *  Constant: '<S206>/Constant'
   *  Constant: '<S207>/Cons'
   *  Sum: '<S206>/Sum1'
   *  UnitDelay: '<S207>/Unit Delay3'
   */
  if (rtDW.UnitDelay3_DSTATE_c) {
    tmp = 13.8564062F - rtb_Saturation;
  } else {
    tmp = 0.0F;
  }

  /* End of Switch: '<S207>/Switch' */

  /* DiscreteIntegrator: '<S207>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_lp = rtDW.DiscreteTimeIntegrator_DSTATE_b;

  /* Sum: '<S207>/Add' incorporates:
   *  Constant: '<S206>/Constant'
   *  Constant: '<S207>/Kp'
   *  Product: '<S207>/Product'
   *  Sum: '<S206>/Sum1'
   */
  rtb_Add = (13.8564062F - rtb_Saturation) * Flux_weak.Kp +
    rtDW.DiscreteTimeIntegrator_lp;

  /* Saturate: '<S207>/Saturation' */
  if (rtb_Add > Flux_weak.Idref_max) {
    rtb_Saturation = Flux_weak.Idref_max;
  } else if (rtb_Add < Flux_weak.Idref_min) {
    rtb_Saturation = Flux_weak.Idref_min;
  } else {
    rtb_Saturation = rtb_Add;
  }

  /* End of Saturate: '<S207>/Saturation' */

  /* Merge: '<S189>/Merge' incorporates:
   *  Sum: '<S206>/Add1'
   */
  rtDW.Merge_p2 = rtDW.uDLookupTable4 + rtb_Saturation;

  /* Merge: '<S189>/Merge1' incorporates:
   *  Inport: '<S206>/Iq_input'
   */
  rtDW.Merge1_i = rtDW.Merge_l;

  /* Update for UnitDelay: '<S207>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S207>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_c = (rtb_Add == rtb_Saturation);

  /* Update for DiscreteIntegrator: '<S207>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S207>/Ki'
   *  Product: '<S207>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_b += Flux_weak.Ki * tmp * 0.0001F;
}

/* Output and update for atomic system: '<S183>/Inverse_Park_Transform' */
void Inverse_Park_Transform(void)
{
  /* Sum: '<S191>/Add1' incorporates:
   *  Outport: '<Root>/Tb'
   *  Outport: '<Root>/Tc'
   *  Product: '<S191>/Product1'
   *  Product: '<S191>/Product2'
   */
  rtDW.Add1_l = rtY.Tc * rtDW.Add2_f - rtDW.Saturation_b * rtY.Tb;

  /* Sum: '<S191>/Add2' incorporates:
   *  Outport: '<Root>/Tb'
   *  Outport: '<Root>/Tc'
   *  Product: '<S191>/Product3'
   *  Product: '<S191>/Product4'
   */
  rtDW.Add2_f = rtY.Tc * rtY.Tb + rtDW.Saturation_b * rtDW.Add2_f;
}

/* Output and update for atomic system: '<S183>/Park_Transform' */
void Park_Transform(void)
{
  /* Sum: '<S192>/Add1' incorporates:
   *  Outport: '<Root>/Tb'
   *  Product: '<S192>/Product1'
   *  Product: '<S192>/Product2'
   */
  rtDW.Add1 = rtDW.Gain2_d * rtDW.Add2_f + rtDW.Gain5 * rtY.Tb;

  /* Sum: '<S192>/Add2' incorporates:
   *  Outport: '<Root>/Tb'
   *  Product: '<S192>/Produc3t'
   *  Product: '<S192>/Product4'
   */
  rtDW.Add2 = rtDW.Gain5 * rtDW.Add2_f - rtDW.Gain2_d * rtY.Tb;
}

/* Disable for atomic system: '<S183>/Q_Current_PI' */
void Q_Current_PI_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S273>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_k0 = rtDW.DiscreteTimeIntegrator_p;
}

/* Output and update for atomic system: '<S183>/Q_Current_PI' */
void Q_Current_PI(void)
{
  real32_T rtb_Add;
  real32_T rtb_Switch;

  /* Sum: '<S193>/Add2' incorporates:
   *  Outport: '<Root>/Ta'
   */
  rtb_Switch = rtY.Ta - rtDW.Add2;

  /* DiscreteIntegrator: '<S273>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_p = rtDW.DiscreteTimeIntegrator_DSTATE_k0;

  /* Sum: '<S273>/Add' incorporates:
   *  Constant: '<S273>/Kp'
   *  Product: '<S273>/Product'
   */
  rtb_Add = ctrlParamsPI.IQ_Current_PI_Kp * rtb_Switch +
    rtDW.DiscreteTimeIntegrator_p;

  /* Saturate: '<S273>/Saturation' */
  if (rtb_Add > ctrlParamsPI.IQ_Current_PI_OutputMax) {
    rtDW.Saturation_b = ctrlParamsPI.IQ_Current_PI_OutputMax;
  } else if (rtb_Add < ctrlParamsPI.IQ_Current_PI_OutputMin) {
    rtDW.Saturation_b = ctrlParamsPI.IQ_Current_PI_OutputMin;
  } else {
    rtDW.Saturation_b = rtb_Add;
  }

  /* End of Saturate: '<S273>/Saturation' */

  /* Switch: '<S273>/Switch' incorporates:
   *  Constant: '<S273>/Cons'
   *  UnitDelay: '<S273>/Unit Delay3'
   */
  if (!rtDW.UnitDelay3_DSTATE_o) {
    rtb_Switch = 0.0F;
  }

  /* End of Switch: '<S273>/Switch' */

  /* Update for DiscreteIntegrator: '<S273>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S273>/Ki'
   *  Product: '<S273>/Product1'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_k0 += ctrlParamsPI.IQ_Current_PI_Ki *
    rtb_Switch * 0.0001F;

  /* Update for UnitDelay: '<S273>/Unit Delay3' incorporates:
   *  RelationalOperator: '<S273>/Relational Operator1'
   */
  rtDW.UnitDelay3_DSTATE_o = (rtb_Add == rtDW.Saturation_b);
}

/* Output and update for atomic system: '<S183>/SVPWM' */
void SVPWM(void)
{
  real32_T rtb_Add;
  real32_T rtb_Gain_e;
  real32_T rtb_IndexVector1;
  real32_T rtb_IndexVector_c;
  real32_T rtb_Saturation;

  /* Outputs for Atomic SubSystem: '<S194>/XYZ Caculate' */
  /* Outputs for Atomic SubSystem: '<S194>/N Sector  Caculate' */
  /* Gain: '<S274>/Gain' incorporates:
   *  Gain: '<S277>/Gain'
   */
  rtb_Gain_e = 1.73205078F * rtDW.Merge_m;

  /* End of Outputs for SubSystem: '<S194>/XYZ Caculate' */

  /* Saturate: '<S274>/Saturation' incorporates:
   *  Gain: '<S274>/Gain'
   *  Gain: '<S274>/Gain1'
   *  Gain: '<S274>/Gain2'
   *  Sum: '<S274>/Add'
   *  Sum: '<S274>/Add1'
   *  Sum: '<S274>/Add2'
   *  Switch: '<S274>/Switch'
   *  Switch: '<S274>/Switch1'
   *  Switch: '<S274>/Switch2'
   */
  rtb_Saturation = (real32_T)((((rtb_Gain_e - rtDW.Merge1_f >= 0.0F) << 1) +
    (rtDW.Merge1_f >= 0.0F)) + (((0.0F - rtDW.Merge1_f) - rtb_Gain_e >= 0.0F) <<
    2));
  if (rtb_Saturation > 6.0F) {
    rtb_Saturation = 6.0F;
  } else {
    if (rtb_Saturation < 1.0F) {
      rtb_Saturation = 1.0F;
    }
  }

  /* End of Saturate: '<S274>/Saturation' */
  /* End of Outputs for SubSystem: '<S194>/N Sector  Caculate' */

  /* Outputs for Atomic SubSystem: '<S194>/T1 T2  Caculate' */
  /* MultiPortSwitch: '<S275>/Index Vector' incorporates:
   *  Gain: '<S275>/Gain'
   *  Gain: '<S275>/Gain1'
   *  Gain: '<S275>/Gain2'
   *  Gain: '<S277>/Gain1'
   *  Gain: '<S277>/Gain2'
   *  Product: '<S277>/Product'
   *  Product: '<S277>/Product1'
   *  Product: '<S277>/Product2'
   *  Sum: '<S277>/Add1'
   *  Sum: '<S277>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    /* Outputs for Atomic SubSystem: '<S194>/XYZ Caculate' */
    rtb_IndexVector_c = (rtb_Gain_e - rtDW.Merge1_f) * -0.5F * 7.2168782E-6F;

    /* MultiPortSwitch: '<S275>/Index Vector1' incorporates:
     *  Gain: '<S277>/Gain1'
     *  Gain: '<S277>/Gain2'
     *  Product: '<S277>/Product1'
     *  Product: '<S277>/Product2'
     *  Sum: '<S277>/Add1'
     *  Sum: '<S277>/Add2'
     */
    rtb_Gain_e = ((0.0F - rtDW.Merge1_f) - rtb_Gain_e) * -0.5F * 7.2168782E-6F;

    /* End of Outputs for SubSystem: '<S194>/XYZ Caculate' */
    break;

   case 2:
    /* Outputs for Atomic SubSystem: '<S194>/XYZ Caculate' */
    rtb_IndexVector_c = ((0.0F - rtDW.Merge1_f) - rtb_Gain_e) * -0.5F *
      7.2168782E-6F;

    /* MultiPortSwitch: '<S275>/Index Vector1' incorporates:
     *  Gain: '<S275>/Gain'
     *  Gain: '<S277>/Gain2'
     *  Product: '<S277>/Product'
     *  Product: '<S277>/Product1'
     *  Sum: '<S277>/Add2'
     */
    rtb_Gain_e = -(rtDW.Merge1_f * 7.2168782E-6F);

    /* End of Outputs for SubSystem: '<S194>/XYZ Caculate' */
    break;

   case 3:
    /* Outputs for Atomic SubSystem: '<S194>/XYZ Caculate' */
    rtb_IndexVector_c = -((rtb_Gain_e - rtDW.Merge1_f) * -0.5F * 7.2168782E-6F);

    /* MultiPortSwitch: '<S275>/Index Vector1' incorporates:
     *  Gain: '<S275>/Gain2'
     *  Gain: '<S277>/Gain1'
     *  Product: '<S277>/Product'
     *  Product: '<S277>/Product2'
     *  Sum: '<S277>/Add1'
     */
    rtb_Gain_e = rtDW.Merge1_f * 7.2168782E-6F;

    /* End of Outputs for SubSystem: '<S194>/XYZ Caculate' */
    break;

   case 4:
    /* Outputs for Atomic SubSystem: '<S194>/XYZ Caculate' */
    rtb_IndexVector_c = -(rtDW.Merge1_f * 7.2168782E-6F);

    /* MultiPortSwitch: '<S275>/Index Vector1' incorporates:
     *  Gain: '<S275>/Gain'
     *  Gain: '<S277>/Gain1'
     *  Product: '<S277>/Product'
     *  Product: '<S277>/Product2'
     *  Sum: '<S277>/Add1'
     */
    rtb_Gain_e = (rtb_Gain_e - rtDW.Merge1_f) * -0.5F * 7.2168782E-6F;

    /* End of Outputs for SubSystem: '<S194>/XYZ Caculate' */
    break;

   case 5:
    /* Outputs for Atomic SubSystem: '<S194>/XYZ Caculate' */
    rtb_IndexVector_c = rtDW.Merge1_f * 7.2168782E-6F;

    /* MultiPortSwitch: '<S275>/Index Vector1' incorporates:
     *  Gain: '<S275>/Gain1'
     *  Gain: '<S277>/Gain2'
     *  Product: '<S277>/Product'
     *  Product: '<S277>/Product1'
     *  Sum: '<S277>/Add2'
     */
    rtb_Gain_e = -(((0.0F - rtDW.Merge1_f) - rtb_Gain_e) * -0.5F * 7.2168782E-6F);

    /* End of Outputs for SubSystem: '<S194>/XYZ Caculate' */
    break;

   default:
    /* Outputs for Atomic SubSystem: '<S194>/XYZ Caculate' */
    rtb_IndexVector_c = -(((0.0F - rtDW.Merge1_f) - rtb_Gain_e) * -0.5F *
                          7.2168782E-6F);

    /* MultiPortSwitch: '<S275>/Index Vector1' incorporates:
     *  Gain: '<S275>/Gain1'
     *  Gain: '<S275>/Gain2'
     *  Gain: '<S277>/Gain1'
     *  Gain: '<S277>/Gain2'
     *  Product: '<S277>/Product1'
     *  Product: '<S277>/Product2'
     *  Sum: '<S277>/Add1'
     *  Sum: '<S277>/Add2'
     */
    rtb_Gain_e = -((rtb_Gain_e - rtDW.Merge1_f) * -0.5F * 7.2168782E-6F);

    /* End of Outputs for SubSystem: '<S194>/XYZ Caculate' */
    break;
  }

  /* End of MultiPortSwitch: '<S275>/Index Vector' */

  /* Sum: '<S275>/Add' */
  rtb_Add = rtb_IndexVector_c + rtb_Gain_e;

  /* Switch: '<S275>/Switch' incorporates:
   *  Constant: '<S183>/Constant4'
   *  Product: '<S275>/Divide'
   *  Product: '<S275>/Divide1'
   *  Sum: '<S275>/Add1'
   *  Switch: '<S275>/Switch2'
   */
  if (!(0.0001F - rtb_Add > 0.0F)) {
    rtb_IndexVector_c = rtb_IndexVector_c * 0.0001F / rtb_Add;
    rtb_Gain_e *= 1.0F / rtb_Add * 0.0001F;
  }

  /* End of Switch: '<S275>/Switch' */
  /* End of Outputs for SubSystem: '<S194>/T1 T2  Caculate' */

  /* Outputs for Atomic SubSystem: '<S194>/Tcm calculate' */
  /* Gain: '<S276>/Gain2' incorporates:
   *  Constant: '<S183>/Constant4'
   *  Sum: '<S276>/Add'
   */
  rtb_Add = ((0.0001F - rtb_IndexVector_c) - rtb_Gain_e) * 0.25F;

  /* Sum: '<S276>/Add1' incorporates:
   *  Gain: '<S276>/Gain'
   */
  rtb_IndexVector_c = 0.5F * rtb_IndexVector_c + rtb_Add;

  /* MultiPortSwitch: '<S276>/Index Vector' incorporates:
   *  Gain: '<S276>/Gain1'
   *  Sum: '<S276>/Add2'
   */
  switch ((int32_T)rtb_Saturation) {
   case 1:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S276>/Index Vector1' */
    rtb_IndexVector1 = rtb_Add;

    /* MultiPortSwitch: '<S276>/Index Vector2' incorporates:
     *  Gain: '<S276>/Gain1'
     *  Sum: '<S276>/Add2'
     */
    rtb_Add = 0.5F * rtb_Gain_e + rtb_IndexVector_c;
    break;

   case 2:
    rtb_Saturation = rtb_Add;

    /* MultiPortSwitch: '<S276>/Index Vector1' incorporates:
     *  Gain: '<S276>/Gain1'
     *  Sum: '<S276>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_e + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S276>/Index Vector2' */
    rtb_Add = rtb_IndexVector_c;
    break;

   case 3:
    rtb_Saturation = rtb_Add;

    /* MultiPortSwitch: '<S276>/Index Vector1' */
    rtb_IndexVector1 = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S276>/Index Vector2' incorporates:
     *  Gain: '<S276>/Gain1'
     *  Sum: '<S276>/Add2'
     */
    rtb_Add = 0.5F * rtb_Gain_e + rtb_IndexVector_c;
    break;

   case 4:
    rtb_Saturation = 0.5F * rtb_Gain_e + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S276>/Index Vector1' incorporates:
     *  Gain: '<S276>/Gain1'
     *  Sum: '<S276>/Add2'
     */
    rtb_IndexVector1 = rtb_IndexVector_c;
    break;

   case 5:
    rtb_Saturation = 0.5F * rtb_Gain_e + rtb_IndexVector_c;

    /* MultiPortSwitch: '<S276>/Index Vector1' incorporates:
     *  Gain: '<S276>/Gain1'
     *  Sum: '<S276>/Add2'
     */
    rtb_IndexVector1 = rtb_Add;

    /* MultiPortSwitch: '<S276>/Index Vector2' */
    rtb_Add = rtb_IndexVector_c;
    break;

   default:
    rtb_Saturation = rtb_IndexVector_c;

    /* MultiPortSwitch: '<S276>/Index Vector1' incorporates:
     *  Gain: '<S276>/Gain1'
     *  Sum: '<S276>/Add2'
     */
    rtb_IndexVector1 = 0.5F * rtb_Gain_e + rtb_IndexVector_c;
    break;
  }

  /* End of MultiPortSwitch: '<S276>/Index Vector' */
  /* End of Outputs for SubSystem: '<S194>/Tcm calculate' */

  /* Gain: '<S194>/Gain' incorporates:
   *  Outport: '<Root>/Ta'
   */
  rtY.Ta = 8.399E+7F * rtb_Saturation;

  /* Gain: '<S194>/Gain2' incorporates:
   *  Outport: '<Root>/Tb'
   */
  rtY.Tb = 8.399E+7F * rtb_IndexVector1;

  /* Gain: '<S194>/Gain3' incorporates:
   *  Outport: '<Root>/Tc'
   */
  rtY.Tc = 8.399E+7F * rtb_Add;
}

/* Output and update for action system: '<S195>/Set_Idq' */
void Set_Idq(void)
{
  /* Inport: '<S278>/Id_Command' incorporates:
   *  Constant: '<S195>/Constant2'
   *  Outport: '<Root>/Tc'
   */
  rtY.Tc = 0.0F;

  /* Inport: '<S278>/Iq_Command' incorporates:
   *  Constant: '<S195>/Constant1'
   *  Outport: '<Root>/Ta'
   */
  rtY.Ta = 0.0F;
}

/* Output and update for action system: '<S195>/Set_Idq1' */
void Set_Idq1(void)
{
  /* Inport: '<S279>/Id_Command' incorporates:
   *  Outport: '<Root>/Tc'
   */
  rtY.Tc = rtDW.Merge_p2;

  /* Inport: '<S279>/Iq_Command' incorporates:
   *  Outport: '<Root>/Ta'
   */
  rtY.Ta = rtDW.Merge1_i;
}

/* Output and update for atomic system: '<S183>/Set_Idq' */
void Set_Idq_i(void)
{
  /* If: '<S195>/If1' */
  if ((rtDW.HFI_state == 2) || (rtDW.HFI_state == 1)) {
    /* Outputs for IfAction SubSystem: '<S195>/Set_Idq' incorporates:
     *  ActionPort: '<S278>/Action Port'
     */
    Set_Idq();

    /* End of Outputs for SubSystem: '<S195>/Set_Idq' */
  } else {
    /* Outputs for IfAction SubSystem: '<S195>/Set_Idq1' incorporates:
     *  ActionPort: '<S279>/Action Port'
     */
    Set_Idq1();

    /* End of Outputs for SubSystem: '<S195>/Set_Idq1' */
  }

  /* End of If: '<S195>/If1' */
}

/* Output and update for atomic system: '<S183>/Sine_Cosine' */
void Sine_Cosine_m(void)
{
  real32_T rtb_Saturation;
  uint32_T Add2_f_tmp;

  /* Saturate: '<S196>/Saturation' */
  if (rtDW.Merge_b > 6.28308535F) {
    rtb_Saturation = 6.28308535F;
  } else if (rtDW.Merge_b < 0.0001F) {
    rtb_Saturation = 0.0001F;
  } else {
    rtb_Saturation = rtDW.Merge_b;
  }

  /* End of Saturate: '<S196>/Saturation' */

  /* Lookup_n-D: '<S196>/Cosine' incorporates:
   *  Lookup_n-D: '<S196>/Sine'
   *  Saturate: '<S196>/Saturation'
   */
  Add2_f_tmp = plook_u32f_evencka(rtb_Saturation, 0.0F, 0.00153435534F, 4095U);
  rtDW.Add2_f = rtConstP.pooled31[Add2_f_tmp];

  /* Lookup_n-D: '<S196>/Sine' incorporates:
   *  Outport: '<Root>/Tb'
   */
  rtY.Tb = rtConstP.pooled33[Add2_f_tmp];
}

/* System initialize for action system: '<S5>/FOC' */
void FOC_Init(void)
{
  /* Start for If: '<S189>/If1' */
  rtDW.If1_ActiveSubsystem_cy = -1;

  /* SystemInitialize for Atomic SubSystem: '<S183>/HF_Observer' */
  HF_Observer_Init();

  /* End of SystemInitialize for SubSystem: '<S183>/HF_Observer' */
}

/* Disable for action system: '<S5>/FOC' */
void FOC_Disable(void)
{
  /* Disable for Atomic SubSystem: '<S183>/HF_Observer' */
  HF_Observer_Disable();

  /* End of Disable for SubSystem: '<S183>/HF_Observer' */

  /* Disable for If: '<S189>/If1' */
  if (rtDW.If1_ActiveSubsystem_cy == 0) {
    /* Disable for Atomic SubSystem: '<S204>/Flux_weak' */
    Flux_weak_Disable();

    /* End of Disable for SubSystem: '<S204>/Flux_weak' */
  }

  rtDW.If1_ActiveSubsystem_cy = -1;

  /* End of Disable for If: '<S189>/If1' */

  /* Disable for Atomic SubSystem: '<S183>/D_Current_PI' */
  D_Current_PI_Disable();

  /* End of Disable for SubSystem: '<S183>/D_Current_PI' */

  /* Disable for Atomic SubSystem: '<S183>/Q_Current_PI' */
  Q_Current_PI_Disable();

  /* End of Disable for SubSystem: '<S183>/Q_Current_PI' */
}

/* Output and update for action system: '<S5>/FOC' */
void FOC(void)
{
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Outputs for Atomic SubSystem: '<S183>/Clarke_Transform' */
  Clarke_Transform();

  /* End of Outputs for SubSystem: '<S183>/Clarke_Transform' */

  /* Outputs for Atomic SubSystem: '<S183>/HF_Observer' */
  HF_Observer();

  /* End of Outputs for SubSystem: '<S183>/HF_Observer' */

  /* Outputs for Atomic SubSystem: '<S183>/Angle_set' */
  Angle_set();

  /* End of Outputs for SubSystem: '<S183>/Angle_set' */

  /* UnitDelay: '<S183>/Unit Delay2' */
  rtDW.Add2_f = rtDW.UnitDelay2_DSTATE_d;

  /* UnitDelay: '<S183>/Unit Delay1' incorporates:
   *  Outport: '<Root>/Tc'
   */
  rtY.Tc = rtDW.UnitDelay1_DSTATE_l;

  /* If: '<S189>/If1' incorporates:
   *  Constant: '<S183>/Constant1'
   *  Inport: '<S205>/Id'
   *  Inport: '<S205>/Iq'
   */
  rtPrevAction = rtDW.If1_ActiveSubsystem_cy;
  rtAction = (int8_T)(Flux_weak.Enable != 1);
  rtDW.If1_ActiveSubsystem_cy = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for Atomic SubSystem: '<S204>/Flux_weak' */
    Flux_weak_Disable();

    /* End of Disable for SubSystem: '<S204>/Flux_weak' */
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S189>/Subsystem' incorporates:
     *  ActionPort: '<S204>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S204>/Flux_weak' */
    Flux_weak_a();

    /* End of Outputs for SubSystem: '<S204>/Flux_weak' */
    /* End of Outputs for SubSystem: '<S189>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S189>/Subsystem1' incorporates:
     *  ActionPort: '<S205>/Action Port'
     */
    rtDW.Merge_p2 = rtDW.uDLookupTable4;
    rtDW.Merge1_i = rtDW.Merge_l;

    /* End of Outputs for SubSystem: '<S189>/Subsystem1' */
  }

  /* End of If: '<S189>/If1' */

  /* Outputs for Atomic SubSystem: '<S183>/Set_Idq' */
  Set_Idq_i();

  /* End of Outputs for SubSystem: '<S183>/Set_Idq' */

  /* Outputs for Atomic SubSystem: '<S183>/Sine_Cosine' */
  Sine_Cosine_m();

  /* End of Outputs for SubSystem: '<S183>/Sine_Cosine' */

  /* Outputs for Atomic SubSystem: '<S183>/Park_Transform' */
  Park_Transform();

  /* End of Outputs for SubSystem: '<S183>/Park_Transform' */

  /* Outputs for Atomic SubSystem: '<S183>/D_Current_PI' */
  D_Current_PI();

  /* End of Outputs for SubSystem: '<S183>/D_Current_PI' */

  /* Sum: '<S183>/Sum' incorporates:
   *  Outport: '<Root>/Tc'
   */
  rtY.Tc = rtDW.Saturation_l + rtDW.DataTypeConversion_m;

  /* Outputs for Atomic SubSystem: '<S183>/Q_Current_PI' */
  Q_Current_PI();

  /* End of Outputs for SubSystem: '<S183>/Q_Current_PI' */

  /* Outputs for Atomic SubSystem: '<S183>/Inverse_Park_Transform' */
  Inverse_Park_Transform();

  /* End of Outputs for SubSystem: '<S183>/Inverse_Park_Transform' */

  /* If: '<S197>/If1' incorporates:
   *  Inport: '<S280>/In1'
   *  Inport: '<S280>/In2'
   *  Inport: '<S281>/In1'
   *  Inport: '<S281>/In2'
   */
  if ((rtDW.HFI_state < 3) && (rtDW.HFI_state > 0)) {
    /* Outputs for IfAction SubSystem: '<S197>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S281>/Action Port'
     */
    rtDW.Merge_m = rtDW.Merge_f;
    rtDW.Merge1_f = rtDW.Merge1_g;

    /* End of Outputs for SubSystem: '<S197>/If Action Subsystem2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S197>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S280>/Action Port'
     */
    rtDW.Merge_m = rtDW.Add1_l;
    rtDW.Merge1_f = rtDW.Add2_f;

    /* End of Outputs for SubSystem: '<S197>/If Action Subsystem1' */
  }

  /* End of If: '<S197>/If1' */

  /* Outputs for Atomic SubSystem: '<S183>/SVPWM' */
  SVPWM();

  /* End of Outputs for SubSystem: '<S183>/SVPWM' */

  /* Update for Atomic SubSystem: '<S183>/HF_Observer' */
  HF_Observer_Update();

  /* End of Update for SubSystem: '<S183>/HF_Observer' */

  /* Update for UnitDelay: '<S183>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE_d = rtDW.Saturation_l;

  /* Update for UnitDelay: '<S183>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE_l = rtDW.Saturation_b;
}

/* Output and update for atomic system: '<S5>/Iq_selector' */
void Iq_selector(void)
{
  /* If: '<S184>/If1' incorporates:
   *  Inport: '<S282>/In1'
   *  Inport: '<S283>/In1'
   */
  if ((rtDW.Motor_state == 2) || (rtDW.Motor_state == 3)) {
    /* Outputs for IfAction SubSystem: '<S184>/Subsystem' incorporates:
     *  ActionPort: '<S282>/Action Port'
     */
    rtDW.Merge_l = rtDW.Merge1_n;

    /* End of Outputs for SubSystem: '<S184>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S184>/Subsystem1' incorporates:
     *  ActionPort: '<S283>/Action Port'
     */
    rtDW.Merge_l = rtDW.uDLookupTable5;

    /* End of Outputs for SubSystem: '<S184>/Subsystem1' */
  }

  /* End of If: '<S184>/If1' */
}

/* Output and update for atomic system: '<S5>/MTPA' */
void MTPA(void)
{
  real32_T tmp;

  /* Lookup_n-D: '<S185>/1-D Lookup Table4' incorporates:
   *  Saturate: '<S185>/Saturation'
   */
  if (rtDW.Merge_j > 1.49F) {
    tmp = 1.49F;
  } else if (rtDW.Merge_j < -1.49F) {
    tmp = -1.49F;
  } else {
    tmp = rtDW.Merge_j;
  }

  rtDW.uDLookupTable4 = rtConstP.uDLookupTable4_tableData[plook_u32f_evencka(tmp,
    -1.5F, 0.0149999857F, 200U)];

  /* End of Lookup_n-D: '<S185>/1-D Lookup Table4' */

  /* Lookup_n-D: '<S185>/1-D Lookup Table5' incorporates:
   *  Saturate: '<S185>/Saturation1'
   */
  if (rtDW.Merge_j > 1.49F) {
    tmp = 1.49F;
  } else if (rtDW.Merge_j < -1.49F) {
    tmp = -1.49F;
  } else {
    tmp = rtDW.Merge_j;
  }

  rtDW.uDLookupTable5 = rtConstP.uDLookupTable5_tableData[plook_u32f_evencka(tmp,
    -1.5F, 0.0149999857F, 200U)];

  /* End of Lookup_n-D: '<S185>/1-D Lookup Table5' */
}

/* System initialize for function-call system: '<S2>/FOC_Control_100us' */
void FOC_Control_100us_Init(void)
{
  /* Start for If: '<S5>/If1' */
  rtDW.If1_ActiveSubsystem_b = -1;

  /* SystemInitialize for IfAction SubSystem: '<S5>/FOC' */
  FOC_Init();

  /* End of SystemInitialize for SubSystem: '<S5>/FOC' */
}

/* Output and update for function-call system: '<S2>/FOC_Control_100us' */
void FOC_Control_100us(void)
{
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Outputs for Atomic SubSystem: '<S5>/MTPA' */
  MTPA();

  /* End of Outputs for SubSystem: '<S5>/MTPA' */

  /* Outputs for Atomic SubSystem: '<S5>/Iq_selector' */
  Iq_selector();

  /* End of Outputs for SubSystem: '<S5>/Iq_selector' */

  /* If: '<S5>/If1' incorporates:
   *  Constant: '<S5>/Hall_Enalble'
   *  Outport: '<Root>/BLDC_State'
   */
  rtPrevAction = rtDW.If1_ActiveSubsystem_b;
  rtAction = -1;
  if ((Hall_Parameter.BLDC_Start != 1) || (rtY.BLDC_State == 3)) {
    rtAction = 0;
  }

  rtDW.If1_ActiveSubsystem_b = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    FOC_Disable();
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S5>/FOC' incorporates:
     *  ActionPort: '<S183>/Action Port'
     */
    FOC();

    /* End of Outputs for SubSystem: '<S5>/FOC' */
  }

  /* End of If: '<S5>/If1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
