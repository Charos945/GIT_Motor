/*
 * File: HF_Observer.c
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

#include "HF_Observer.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Named constants for Chart: '<S57>/HFI_State_machine' */
#define IN_HFI_IPD                     ((uint8_T)1U)
#define IN_HFI_NS                      ((uint8_T)2U)
#define IN_HFI_RUN                     ((uint8_T)3U)

/* Named constants for Chart: '<S61>/NS_State_machine' */
#define IN_NS_1                        ((uint8_T)1U)
#define IN_NS_2                        ((uint8_T)2U)
#define IN_NS_3                        ((uint8_T)3U)
#define IN_NS_4                        ((uint8_T)4U)
#define IN_NS_5                        ((uint8_T)5U)

/* Named constants for Chart: '<S58>/StartRUN_State_machine' */
#define IN_NS_2_RUN                    ((uint8_T)1U)
#define IN_RUN                         ((uint8_T)2U)
#define IN_Start_RUN                   ((uint8_T)3U)

/* Output and update for atomic system: '<S57>/HFI_State_machine' */
void HFI_State_machine(void)
{
  if (rtDW.temporalCounter_i1_m < MAX_uint32_T) {
    rtDW.temporalCounter_i1_m++;
  }

  /* Chart: '<S57>/HFI_State_machine' incorporates:
   *  Constant: '<S57>/Constant'
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S57>/HFI_Enalble'
   */
  if (rtDW.is_active_c7_Motor_Control == 0U) {
    rtDW.is_active_c7_Motor_Control = 1U;
    rtDW.is_c7_Motor_Control = IN_HFI_IPD;
    rtDW.temporalCounter_i1_m = 0U;
    rtDW.HFI_state = 1U;
    rtDW.IPD_flag = 1.0;
  } else {
    switch (rtDW.is_c7_Motor_Control) {
     case IN_HFI_IPD:
      rtDW.HFI_state = 1U;
      if ((rtDW.temporalCounter_i1_m >= (uint32_T)ceil
           (HFI_Parameter.HFI_IPD_Time / 0.0001 - 1.0E-12)) &&
          (HFI_Parameter.HFI_Fuc_Enalbe == 1) && (rtDW.IPD_flag == 1.0)) {
        rtDW.is_c7_Motor_Control = IN_HFI_NS;
        rtDW.temporalCounter_i1_m = 0U;
        rtDW.HFI_state = 2U;
        rtDW.NS_flag = 1.0;
      }
      break;

     case IN_HFI_NS:
      rtDW.HFI_state = 2U;
      if ((rtDW.temporalCounter_i1_m >= (uint32_T)ceil(HFI_Parameter.HFI_NS_Time
            / 0.0001 - 1.0E-12)) && (rtDW.NS_flag == 1.0)) {
        rtDW.is_c7_Motor_Control = IN_HFI_RUN;
        rtDW.HFI_state = 3U;
      }
      break;

     default:
      /* case IN_HFI_RUN: */
      rtDW.HFI_state = 3U;
      break;
    }
  }

  /* End of Chart: '<S57>/HFI_State_machine' */
}

/* Output and update for atomic system: '<S60>/Sine_Cosine' */
void Sine_Cosine(void)
{
  uint32_T Gain1_tmp;

  /* Lookup_n-D: '<S146>/Cosine' incorporates:
   *  Lookup_n-D: '<S146>/Sine'
   *  Product: '<S145>/Product1'
   */
  Gain1_tmp = plook_u32f_evencka(rtDW.Product1, 0.0F, 0.00153435534F, 4095U);

  /* Gain: '<S147>/Gain1' incorporates:
   *  Lookup_n-D: '<S146>/Cosine'
   */
  rtDW.Gain1 = rtConstP.pooled18[Gain1_tmp];

  /* Lookup_n-D: '<S146>/Sine' */
  rtDW.Sine_dg = rtConstP.pooled14[Gain1_tmp];
}

/* Output and update for action system: '<S57>/IPD' */
void IPD(void)
{
  real32_T rtb_Add;
  real32_T rtb_RMS;
  real32_T rtb_RMS1;
  real32_T rtb_RMS2;

  /* Product: '<S145>/Product1' incorporates:
   *  Constant: '<S145>/Const2'
   *  Delay: '<S145>/Delay'
   *  Memory: '<S145>/Memory'
   *  RelationalOperator: '<S145>/Relational Operator1'
   */
  rtDW.Product1 = (real32_T)(rtDW.Delay_DSTATE_o < 6.28318548F) *
    rtDW.Memory_PreviousInput_d3;

  /* Outputs for Atomic SubSystem: '<S60>/Sine_Cosine' */
  Sine_Cosine();

  /* End of Outputs for SubSystem: '<S60>/Sine_Cosine' */

  /* Merge: '<S57>/Merge' incorporates:
   *  Constant: '<S60>/Constant'
   *  Fcn: '<S60>/7'
   */
  rtDW.Merge_o = HFI_Parameter.HFI_IPD_V * rtDW.Gain1;

  /* Merge: '<S57>/Merge1' incorporates:
   *  Constant: '<S60>/Constant'
   *  Fcn: '<S60>/8'
   */
  rtDW.Merge1_dq = HFI_Parameter.HFI_IPD_V * rtDW.Sine_dg;

  /* Sum: '<S145>/Add' incorporates:
   *  Constant: '<S145>/Const1'
   */
  rtb_Add = 6.28318548F * HFI_Parameter.HFI_IPD_F / 10000.0F + rtDW.Product1;

  /* S-Function (sdspstatfcns): '<S147>/RMS' incorporates:
   *  Inport: '<Root>/Phase_CurrentABC'
   */
  rtDW.RMS_Iteration++;
  if (rtDW.RMS_Iteration > 1U) {
    rtDW.RMS_SqData += rtU.Phase_CurrentABC[0] * rtU.Phase_CurrentABC[0];
    rtb_RMS = sqrtf(rtDW.RMS_SqData / (real32_T)rtDW.RMS_Iteration);
  } else {
    if (rtDW.RMS_Iteration == 0U) {
      rtDW.RMS_Iteration = 1U;
    }

    rtDW.RMS_SqData = rtU.Phase_CurrentABC[0] * rtU.Phase_CurrentABC[0];
    rtb_RMS = fabsf(rtU.Phase_CurrentABC[0]);
  }

  /* End of S-Function (sdspstatfcns): '<S147>/RMS' */

  /* S-Function (sdspstatfcns): '<S147>/RMS1' incorporates:
   *  Inport: '<Root>/Phase_CurrentABC'
   */
  rtDW.RMS1_Iteration++;
  if (rtDW.RMS1_Iteration > 1U) {
    rtDW.RMS1_SqData += rtU.Phase_CurrentABC[1] * rtU.Phase_CurrentABC[1];
    rtb_RMS1 = sqrtf(rtDW.RMS1_SqData / (real32_T)rtDW.RMS1_Iteration);
  } else {
    if (rtDW.RMS1_Iteration == 0U) {
      rtDW.RMS1_Iteration = 1U;
    }

    rtDW.RMS1_SqData = rtU.Phase_CurrentABC[1] * rtU.Phase_CurrentABC[1];
    rtb_RMS1 = fabsf(rtU.Phase_CurrentABC[1]);
  }

  /* End of S-Function (sdspstatfcns): '<S147>/RMS1' */

  /* S-Function (sdspstatfcns): '<S147>/RMS2' incorporates:
   *  Inport: '<Root>/Phase_CurrentABC'
   */
  rtDW.RMS2_Iteration++;
  if (rtDW.RMS2_Iteration > 1U) {
    rtDW.RMS2_SqData += rtU.Phase_CurrentABC[2] * rtU.Phase_CurrentABC[2];
    rtb_RMS2 = sqrtf(rtDW.RMS2_SqData / (real32_T)rtDW.RMS2_Iteration);
  } else {
    if (rtDW.RMS2_Iteration == 0U) {
      rtDW.RMS2_Iteration = 1U;
    }

    rtDW.RMS2_SqData = rtU.Phase_CurrentABC[2] * rtU.Phase_CurrentABC[2];
    rtb_RMS2 = fabsf(rtU.Phase_CurrentABC[2]);
  }

  /* End of S-Function (sdspstatfcns): '<S147>/RMS2' */

  /* If: '<S147>/If1' */
  if ((rtb_RMS > rtb_RMS2) && (rtb_RMS2 > rtb_RMS1)) {
    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S149>/Action Port'
     */
    /* Merge: '<S147>/Merge' incorporates:
     *  Fcn: '<S149>/Fcn'
     */
    rtDW.Merge_l = (rtb_RMS2 - rtb_RMS1) / (rtb_RMS - rtb_RMS1) * 30.0F;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem2' */
  } else if ((rtb_RMS2 > rtb_RMS) && (rtb_RMS > rtb_RMS1)) {
    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S148>/Action Port'
     */
    /* Merge: '<S147>/Merge' incorporates:
     *  Fcn: '<S148>/Fcn'
     */
    rtDW.Merge_l = (rtb_RMS2 - rtb_RMS) / (rtb_RMS2 - rtb_RMS1) * 30.0F + 30.0F;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem1' */
  } else if ((rtb_RMS2 > rtb_RMS1) && (rtb_RMS1 > rtb_RMS)) {
    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    /* Merge: '<S147>/Merge' incorporates:
     *  Fcn: '<S150>/Fcn'
     */
    rtDW.Merge_l = (rtb_RMS1 - rtb_RMS) / (rtb_RMS2 - rtb_RMS) * 30.0F + 60.0F;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem3' */
  } else if ((rtb_RMS1 > rtb_RMS2) && (rtb_RMS2 > rtb_RMS)) {
    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    /* Merge: '<S147>/Merge' incorporates:
     *  Fcn: '<S151>/Fcn'
     */
    rtDW.Merge_l = (rtb_RMS1 - rtb_RMS2) / (rtb_RMS1 - rtb_RMS) * 30.0F + 90.0F;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem4' */
  } else if ((rtb_RMS1 > rtb_RMS) && (rtb_RMS > rtb_RMS2)) {
    /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    /* Merge: '<S147>/Merge' incorporates:
     *  Fcn: '<S152>/Fcn'
     */
    rtDW.Merge_l = (rtb_RMS - rtb_RMS2) / (rtb_RMS1 - rtb_RMS2) * 30.0F + 120.0F;

    /* End of Outputs for SubSystem: '<S147>/If Action Subsystem5' */
  } else {
    if ((rtb_RMS > rtb_RMS1) && (rtb_RMS1 > rtb_RMS2)) {
      /* Outputs for IfAction SubSystem: '<S147>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S153>/Action Port'
       */
      /* Merge: '<S147>/Merge' incorporates:
       *  Fcn: '<S153>/Fcn'
       */
      rtDW.Merge_l = (rtb_RMS - rtb_RMS1) / (rtb_RMS - rtb_RMS2) * 30.0F +
        150.0F;

      /* End of Outputs for SubSystem: '<S147>/If Action Subsystem6' */
    }
  }

  /* End of If: '<S147>/If1' */

  /* Gain: '<S147>/Gain1' */
  rtDW.Gain1 = 0.0174532924F * rtDW.Merge_l;

  /* Update for Delay: '<S145>/Delay' */
  rtDW.Delay_DSTATE_o = rtb_Add;

  /* Update for Memory: '<S145>/Memory' */
  rtDW.Memory_PreviousInput_d3 = rtb_Add;
}

/* Output and update for atomic system: '<S61>/NS_State_machine' */
void NS_State_machine(void)
{
  if (rtDW.temporalCounter_i1_a < MAX_uint32_T) {
    rtDW.temporalCounter_i1_a++;
  }

  /* Chart: '<S61>/NS_State_machine' incorporates:
   *  Constant: '<S61>/Constant1'
   *  Constant: '<S61>/Constant2'
   */
  if (rtDW.is_active_c8_Motor_Control == 0U) {
    rtDW.is_active_c8_Motor_Control = 1U;
    rtDW.is_c8_Motor_Control = IN_NS_1;
    rtDW.temporalCounter_i1_a = 0U;
    rtDW.NS_state = 1U;
    rtDW.NS_1_flag = 1.0;
  } else {
    switch (rtDW.is_c8_Motor_Control) {
     case IN_NS_1:
      rtDW.NS_state = 1U;
      if ((rtDW.temporalCounter_i1_a >= (uint32_T)ceil
           (HFI_Parameter.HFI_NS_Low_Time / 0.0001 - 1.0E-12)) &&
          (rtDW.NS_1_flag == 1.0)) {
        rtDW.is_c8_Motor_Control = IN_NS_2;
        rtDW.temporalCounter_i1_a = 0U;
        rtDW.NS_state = 2U;
        rtDW.NS_2_flag = 1.0;
      }
      break;

     case IN_NS_2:
      rtDW.NS_state = 2U;
      if ((rtDW.temporalCounter_i1_a >= (uint32_T)ceil
           (HFI_Parameter.HFI_Pulse_Time / 0.0001 - 1.0E-12)) && (rtDW.NS_2_flag
           == 1.0)) {
        rtDW.is_c8_Motor_Control = IN_NS_3;
        rtDW.temporalCounter_i1_a = 0U;
        rtDW.NS_state = 3U;
        rtDW.NS_3_flag = 1.0;
      }
      break;

     case IN_NS_3:
      rtDW.NS_state = 3U;
      if ((rtDW.temporalCounter_i1_a >= (uint32_T)ceil
           (HFI_Parameter.HFI_NS_Low_Time / 0.0001 - 1.0E-12)) &&
          (rtDW.NS_3_flag == 1.0)) {
        rtDW.is_c8_Motor_Control = IN_NS_4;
        rtDW.temporalCounter_i1_a = 0U;
        rtDW.NS_state = 4U;
        rtDW.NS_4_flag = 1.0;
      }
      break;

     case IN_NS_4:
      rtDW.NS_state = 4U;
      if ((rtDW.temporalCounter_i1_a >= (uint32_T)ceil
           (HFI_Parameter.HFI_Pulse_Time / 0.0001 - 1.0E-12)) && (rtDW.NS_4_flag
           == 1.0)) {
        rtDW.is_c8_Motor_Control = IN_NS_5;
        rtDW.NS_state = 5U;
      }
      break;

     default:
      /* case IN_NS_5: */
      rtDW.NS_state = 5U;
      break;
    }
  }

  /* End of Chart: '<S61>/NS_State_machine' */
}

/* Output and update for atomic system: '<S155>/Sine_Cosine' */
void Sine_Cosine_b(void)
{
  uint32_T Cosine_g_tmp;

  /* Lookup_n-D: '<S160>/Cosine' incorporates:
   *  Delay: '<S57>/Delay1'
   *  Lookup_n-D: '<S160>/Sine'
   */
  Cosine_g_tmp = plook_u32f_evencka(rtDW.Delay1, 0.0F, 0.00153435534F, 4095U);

  /* Lookup_n-D: '<S160>/Cosine' */
  rtDW.Cosine_g = rtConstP.pooled18[Cosine_g_tmp];

  /* Lookup_n-D: '<S160>/Sine' */
  rtDW.Sine_p = rtConstP.pooled14[Cosine_g_tmp];
}

/* Output and update for atomic system: '<S156>/Sine_Cosine' */
void Sine_Cosine_i(void)
{
  uint32_T Id_j_tmp;

  /* Lookup_n-D: '<S161>/Cosine' incorporates:
   *  Delay: '<S57>/Delay1'
   *  Inport: '<S156>/Id'
   *  Lookup_n-D: '<S161>/Sine'
   */
  Id_j_tmp = plook_u32f_evencka(rtDW.Delay1, 0.0F, 0.00153435534F, 4095U);
  rtDW.Id_j = rtConstP.pooled18[Id_j_tmp];

  /* Lookup_n-D: '<S161>/Sine' */
  rtDW.Sine_d = rtConstP.pooled14[Id_j_tmp];
}

/* Output and update for atomic system: '<S157>/Sine_Cosine' */
void Sine_Cosine_d(void)
{
  uint32_T Cosine_m_tmp;

  /* Lookup_n-D: '<S162>/Cosine' incorporates:
   *  Delay: '<S57>/Delay1'
   *  Lookup_n-D: '<S162>/Sine'
   */
  Cosine_m_tmp = plook_u32f_evencka(rtDW.Delay1, 0.0F, 0.00153435534F, 4095U);

  /* Lookup_n-D: '<S162>/Cosine' */
  rtDW.Cosine_m = rtConstP.pooled18[Cosine_m_tmp];

  /* Lookup_n-D: '<S162>/Sine' */
  rtDW.Sine_a = rtConstP.pooled14[Cosine_m_tmp];
}

/* Output and update for atomic system: '<S158>/Sine_Cosine' */
void Sine_Cosine_e(void)
{
  uint32_T Id_tmp;

  /* Lookup_n-D: '<S163>/Cosine' incorporates:
   *  Inport: '<S158>/Id'
   *  Lookup_n-D: '<S163>/Sine'
   *  Merge: '<S164>/Merge1'
   */
  Id_tmp = plook_u32f_evencka(rtDW.Merge1_hm, 0.0F, 0.00153435534F, 4095U);
  rtDW.Id = rtConstP.pooled18[Id_tmp];

  /* Lookup_n-D: '<S163>/Sine' */
  rtDW.Sine_n = rtConstP.pooled14[Id_tmp];
}

/*
 * Output and update for action system:
 *    '<S164>/If Action Subsystem2'
 *    '<S170>/If Action Subsystem2'
 */
void IfActionSubsystem2(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S166>/Subtract1' incorporates:
   *  Constant: '<S166>/2pi'
   */
  *rty_Out1 = rtu_In1 - 6.28318548F;
}

/* Output and update for action system: '<S57>/NS' */
void NS(void)
{
  real32_T rtb_Abs;
  real32_T rtb_Abs1;
  real32_T rtb_Cosine;
  real32_T rtb_Sine;
  uint32_T rtb_Sine_tmp;

  /* Abs: '<S61>/Abs' incorporates:
   *  Delay: '<S61>/Delay'
   */
  rtb_Abs = fabsf(rtDW.Delay_DSTATE_n);

  /* Abs: '<S61>/Abs1' incorporates:
   *  Delay: '<S61>/Delay1'
   */
  rtb_Abs1 = fabsf(rtDW.Delay1_DSTATE_n);

  /* Chart: '<S61>/NS_State_machine' */
  NS_State_machine();

  /* SwitchCase: '<S61>/Switch Case1' incorporates:
   *  Inport: '<S156>/Id'
   *  Inport: '<S158>/Id'
   */
  switch (rtDW.NS_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S61>/Ud_inject_1' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S155>/Sine_Cosine' */
    Sine_Cosine_b();

    /* End of Outputs for SubSystem: '<S155>/Sine_Cosine' */

    /* Merge: '<S61>/Merge' incorporates:
     *  Constant: '<S155>/Constant'
     *  Constant: '<S155>/Constant2'
     *  Fcn: '<S155>/1'
     */
    rtDW.Merge_p = 0.0F * rtDW.Cosine_g - 0.0F * rtDW.Sine_p;

    /* Merge: '<S61>/Merge1' incorporates:
     *  Constant: '<S155>/Constant'
     *  Constant: '<S155>/Constant2'
     *  Fcn: '<S155>/2'
     */
    rtDW.Merge1_o = 0.0F * rtDW.Sine_p + 0.0F * rtDW.Cosine_g;

    /* End of Outputs for SubSystem: '<S61>/Ud_inject_1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S61>/Ud_inject_2' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S156>/Sine_Cosine' */
    Sine_Cosine_i();

    /* End of Outputs for SubSystem: '<S156>/Sine_Cosine' */

    /* Merge: '<S61>/Merge' incorporates:
     *  Constant: '<S156>/Constant'
     *  Constant: '<S156>/Constant2'
     *  Fcn: '<S156>/1'
     */
    rtDW.Merge_p = HFI_Parameter.HFI_NS_V * rtDW.Id_j - 0.0F * rtDW.Sine_d;

    /* Merge: '<S61>/Merge1' incorporates:
     *  Constant: '<S156>/Constant'
     *  Constant: '<S156>/Constant2'
     *  Fcn: '<S156>/2'
     */
    rtDW.Merge1_o = HFI_Parameter.HFI_NS_V * rtDW.Sine_d + 0.0F * rtDW.Id_j;
    rtDW.Id_j = rtDW.Delay;

    /* End of Outputs for SubSystem: '<S61>/Ud_inject_2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S61>/Ud_inject_3' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S157>/Sine_Cosine' */
    Sine_Cosine_d();

    /* End of Outputs for SubSystem: '<S157>/Sine_Cosine' */

    /* Merge: '<S61>/Merge' incorporates:
     *  Constant: '<S157>/Constant'
     *  Constant: '<S157>/Constant2'
     *  Fcn: '<S157>/1'
     */
    rtDW.Merge_p = 0.0F * rtDW.Cosine_m - 0.0F * rtDW.Sine_a;

    /* Merge: '<S61>/Merge1' incorporates:
     *  Constant: '<S157>/Constant'
     *  Constant: '<S157>/Constant2'
     *  Fcn: '<S157>/2'
     */
    rtDW.Merge1_o = 0.0F * rtDW.Sine_a + 0.0F * rtDW.Cosine_m;

    /* End of Outputs for SubSystem: '<S61>/Ud_inject_3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S61>/Ud_inject_4' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    /* If: '<S164>/If1' incorporates:
     *  Constant: '<S164>/Angle_offset'
     *  Inport: '<S165>/In1'
     *  Sum: '<S164>/Subtract1'
     */
    if (rtDW.Delay1 + 3.14159274F > 6.28318548F) {
      /* Outputs for IfAction SubSystem: '<S164>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S166>/Action Port'
       */
      IfActionSubsystem2(rtDW.Delay1 + 3.14159274F, &rtDW.Merge1_hm);

      /* End of Outputs for SubSystem: '<S164>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S164>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S165>/Action Port'
       */
      rtDW.Merge1_hm = rtDW.Delay1 + 3.14159274F;

      /* End of Outputs for SubSystem: '<S164>/If Action Subsystem1' */
    }

    /* End of If: '<S164>/If1' */

    /* Outputs for Atomic SubSystem: '<S158>/Sine_Cosine' */
    Sine_Cosine_e();

    /* End of Outputs for SubSystem: '<S158>/Sine_Cosine' */

    /* Merge: '<S61>/Merge' incorporates:
     *  Constant: '<S158>/Constant'
     *  Constant: '<S158>/Constant2'
     *  Fcn: '<S158>/1'
     */
    rtDW.Merge_p = HFI_Parameter.HFI_NS_V * rtDW.Id - 0.0F * rtDW.Sine_n;

    /* Merge: '<S61>/Merge1' incorporates:
     *  Constant: '<S158>/Constant'
     *  Constant: '<S158>/Constant2'
     *  Fcn: '<S158>/2'
     */
    rtDW.Merge1_o = HFI_Parameter.HFI_NS_V * rtDW.Sine_n + 0.0F * rtDW.Id;
    rtDW.Id = rtDW.Delay;

    /* End of Outputs for SubSystem: '<S61>/Ud_inject_4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S61>/Ud_inject_5' incorporates:
     *  ActionPort: '<S159>/Action Port'
     */
    /* Lookup_n-D: '<S167>/Sine' incorporates:
     *  Delay: '<S57>/Delay1'
     *  Lookup_n-D: '<S167>/Cosine'
     */
    rtb_Sine_tmp = plook_u32f_evencka(rtDW.Delay1, 0.0F, 0.00153435534F, 4095U);
    rtb_Sine = rtConstP.pooled14[rtb_Sine_tmp];

    /* Lookup_n-D: '<S167>/Cosine' */
    rtb_Cosine = rtConstP.pooled18[rtb_Sine_tmp];

    /* Merge: '<S61>/Merge' incorporates:
     *  Constant: '<S159>/Constant'
     *  Constant: '<S159>/Constant2'
     *  Fcn: '<S159>/1'
     */
    rtDW.Merge_p = 0.0F * rtb_Cosine - 0.0F * rtb_Sine;

    /* Merge: '<S61>/Merge1' incorporates:
     *  Constant: '<S159>/Constant'
     *  Constant: '<S159>/Constant2'
     *  Fcn: '<S159>/2'
     */
    rtDW.Merge1_o = 0.0F * rtb_Sine + 0.0F * rtb_Cosine;

    /* If: '<S159>/If1' */
    if (rtb_Abs >= rtb_Abs1) {
      /* Outputs for IfAction SubSystem: '<S159>/Subsystem' incorporates:
       *  ActionPort: '<S168>/Action Port'
       */
      /* Merge: '<S159>/Merge1' incorporates:
       *  Inport: '<S168>/In1'
       */
      rtDW.Merge1_dg = rtDW.Delay1;

      /* End of Outputs for SubSystem: '<S159>/Subsystem' */
    } else {
      if (rtb_Abs < rtb_Abs1) {
        /* Outputs for IfAction SubSystem: '<S159>/Subsystem1' incorporates:
         *  ActionPort: '<S169>/Action Port'
         */
        /* If: '<S170>/If1' incorporates:
         *  Constant: '<S170>/Angle_offset'
         *  Sum: '<S170>/Subtract1'
         */
        if (rtDW.Delay1 + 3.14159274F > 6.28318548F) {
          /* Outputs for IfAction SubSystem: '<S170>/If Action Subsystem2' incorporates:
           *  ActionPort: '<S172>/Action Port'
           */
          IfActionSubsystem2(rtDW.Delay1 + 3.14159274F, &rtDW.Merge1_dg);

          /* End of Outputs for SubSystem: '<S170>/If Action Subsystem2' */
        } else {
          /* Outputs for IfAction SubSystem: '<S170>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S171>/Action Port'
           */
          /* Merge: '<S159>/Merge1' incorporates:
           *  Inport: '<S171>/In1'
           */
          rtDW.Merge1_dg = rtDW.Delay1 + 3.14159274F;

          /* End of Outputs for SubSystem: '<S170>/If Action Subsystem1' */
        }

        /* End of If: '<S170>/If1' */
        /* End of Outputs for SubSystem: '<S159>/Subsystem1' */
      }
    }

    /* End of If: '<S159>/If1' */
    /* End of Outputs for SubSystem: '<S61>/Ud_inject_5' */
    break;
  }

  /* End of SwitchCase: '<S61>/Switch Case1' */

  /* DataTypeConversion: '<S61>/Data Type Conversion' */
  rtDW.DataTypeConversion_k = rtDW.Merge1_dg;

  /* SignalConversion generated from: '<S61>/Ualpha' */
  rtDW.Merge_o = rtDW.Merge_p;

  /* SignalConversion generated from: '<S61>/Ubeta' */
  rtDW.Merge1_dq = rtDW.Merge1_o;

  /* SignalConversion generated from: '<S61>/IPD_Angle' */
  rtDW.Merge2_i = rtDW.Merge1_dg;

  /* Update for Delay: '<S61>/Delay' */
  rtDW.Delay_DSTATE_n = rtDW.Id_j;

  /* Update for Delay: '<S61>/Delay1' */
  rtDW.Delay1_DSTATE_n = rtDW.Id;
}

/* Output and update for atomic system: '<S65>/Angle_calibration' */
void Angle_calibration(void)
{
  /* If: '<S78>/If1' incorporates:
   *  Constant: '<S78>/Angle_offset'
   *  Sum: '<S78>/Subtract1'
   */
  if (rtDW.Add_l + -3.14159274F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    IfActionSubsystem2_k(rtDW.Add_l + -3.14159274F, &rtDW.Merge2_o);

    /* End of Outputs for SubSystem: '<S78>/If Action Subsystem2' */
  } else if (rtDW.Add_l + -3.14159274F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S81>/Action Port'
     */
    IfActionSubsystem3(rtDW.Add_l + -3.14159274F, &rtDW.Merge2_o);

    /* End of Outputs for SubSystem: '<S78>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    /* Merge: '<S58>/Merge2' incorporates:
     *  Inport: '<S79>/In1'
     */
    rtDW.Merge2_o = rtDW.Add_l + -3.14159274F;

    /* End of Outputs for SubSystem: '<S78>/If Action Subsystem1' */
  }

  /* End of If: '<S78>/If1' */
}

/* Output and update for atomic system: '<S66>/Angle_calibration' */
void Angle_calibration_h(void)
{
  /* If: '<S82>/If1' incorporates:
   *  Constant: '<S82>/Angle_offset'
   *  Inport: '<S83>/In1'
   *  Sum: '<S82>/Subtract1'
   */
  if (rtDW.Add_l + 3.14159274F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S82>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S84>/Action Port'
     */
    IfActionSubsystem2_k(rtDW.Add_l + 3.14159274F, &rtDW.Merge2_o);

    /* End of Outputs for SubSystem: '<S82>/If Action Subsystem2' */
  } else if (rtDW.Add_l + 3.14159274F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S82>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S85>/Action Port'
     */
    IfActionSubsystem3(rtDW.Add_l + 3.14159274F, &rtDW.Merge2_o);

    /* End of Outputs for SubSystem: '<S82>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S82>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    rtDW.Merge2_o = rtDW.Add_l + 3.14159274F;

    /* End of Outputs for SubSystem: '<S82>/If Action Subsystem1' */
  }

  /* End of If: '<S82>/If1' */
}

/* Output and update for atomic system: '<S58>/StartRUN_State_machine' */
void StartRUN_State_machine(void)
{
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  /* Chart: '<S58>/StartRUN_State_machine' incorporates:
   *  Constant: '<S58>/Const4'
   *  Constant: '<S58>/Const5'
   */
  if (rtDW.is_active_c6_Motor_Control == 0U) {
    rtDW.is_active_c6_Motor_Control = 1U;
    rtDW.is_c6_Motor_Control = IN_NS_2_RUN;
    rtDW.temporalCounter_i1 = 0U;
    rtDW.RUN_state = 1U;
    rtDW.NS_RUN_flag = 1.0;
  } else {
    switch (rtDW.is_c6_Motor_Control) {
     case IN_NS_2_RUN:
      rtDW.RUN_state = 1U;
      if ((rtDW.temporalCounter_i1 >= (uint32_T)ceil
           (HFI_Parameter.HFI_NS2RUN_Time / 0.0001 - 1.0E-12)) &&
          (rtDW.NS_RUN_flag == 1.0)) {
        rtDW.is_c6_Motor_Control = IN_Start_RUN;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.RUN_state = 2U;
        rtDW.Switch_flag = 1.0;
      }
      break;

     case IN_RUN:
      rtDW.RUN_state = 3U;
      break;

     default:
      /* case IN_Start_RUN: */
      rtDW.RUN_state = 2U;
      if ((rtDW.temporalCounter_i1 >= (uint32_T)ceil
           (HFI_Parameter.HFI_Switch_Time / 0.0001 - 1.0E-12)) &&
          (rtDW.Switch_flag == 1.0)) {
        rtDW.is_c6_Motor_Control = IN_RUN;
        rtDW.RUN_state = 3U;
      }
      break;
    }
  }

  /* End of Chart: '<S58>/StartRUN_State_machine' */
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

/* System initialize for action system: '<S40>/HFI_Function' */
void HFI_Function_Init(void)
{
  /* SystemInitialize for IfAction SubSystem: '<S57>/HFI' */
  /* InitializeConditions for DiscreteIntegrator: '<S127>/Integrator' */
  rtDW.Integrator_DSTATE_a = 1.0F;

  /* End of SystemInitialize for SubSystem: '<S57>/HFI' */
}

/* Outputs for action system: '<S40>/HFI_Function' */
void HFI_Function(void)
{
  real32_T DiscreteTimeIntegrator_c;
  real32_T rtb_Integrator_p;
  real32_T rtb_Produc3t;
  real32_T rtb_Product1_bq;
  real32_T rtb_Product1_f;
  real32_T rtb_Product1_lr;
  real32_T rtb_Product_e;
  real32_T rtb_Product_m;
  uint32_T rtb_Produc3t_tmp;
  int8_T rtAction;
  boolean_T rtb_NotEqual;

  /* Chart: '<S57>/HFI_State_machine' */
  HFI_State_machine();

  /* Delay: '<S57>/Delay' */
  rtDW.Delay = rtDW.Delay_DSTATE;

  /* Delay: '<S57>/Delay1' */
  rtDW.Delay1 = rtDW.Delay1_DSTATE;

  /* SwitchCase: '<S57>/Switch Case1' incorporates:
   *  Delay: '<S57>/Delay2'
   *  Inport: '<S58>/IPD_angle'
   */
  switch (rtDW.HFI_state) {
   case 1:
    rtAction = 0;
    break;

   case 2:
    rtAction = 1;
    break;

   case 3:
    rtAction = 2;
    break;

   default:
    rtAction = 3;
    break;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S57>/IPD' incorporates:
     *  ActionPort: '<S60>/Action Port'
     */
    IPD();

    /* End of Outputs for SubSystem: '<S57>/IPD' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S57>/NS' incorporates:
     *  ActionPort: '<S61>/Action Port'
     */
    NS();

    /* End of Outputs for SubSystem: '<S57>/NS' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S57>/HFI' incorporates:
     *  ActionPort: '<S58>/Action Port'
     */
    /* Product: '<S71>/Product1' incorporates:
     *  Constant: '<S71>/Const2'
     *  Delay: '<S71>/Delay'
     *  Memory: '<S71>/Memory'
     *  RelationalOperator: '<S71>/Relational Operator1'
     */
    rtb_Product1_bq = (real32_T)(rtDW.Add_l < 6.28318548F) * rtDW.Add_l;

    /* DataTypeConversion: '<S58>/Data Type Conversion' incorporates:
     *  Gain: '<S71>/A'
     *  Lookup_n-D: '<S71>/Sine'
     *  Product: '<S71>/Product1'
     */
    rtDW.DataTypeConversion = HFI_Parameter.HFI_Inj_HV *
      rtConstP.pooled14[plook_u32f_evencka(rtb_Product1_bq, 0.0F, 0.00153435534F,
      4095U)];

    /* DiscreteIntegrator: '<S58>/Discrete-Time Integrator' */
    DiscreteTimeIntegrator_c = 0.0001F * rtDW.DataTypeConversion +
      rtDW.DiscreteTimeIntegrator_DSTATE_i5;

    /* DiscreteIntegrator: '<S88>/Integrator' incorporates:
     *  Constant: '<S67>/Constant3'
     */
    if (rtDW.Integrator_PrevResetState != 0) {
      rtDW.Integrator_DSTATE = 0.0F;
    }

    /* Saturate: '<S67>/Saturation' incorporates:
     *  Constant: '<S58>/Const2'
     */
    rtb_Integrator_p = HFI_Parameter.HFI_bw_BPF / 2.0F +
      HFI_Parameter.HFI_Inj_HF;
    if (rtb_Integrator_p <= 2.22044605E-16F) {
      rtb_Integrator_p = 2.22044605E-16F;
    }

    /* End of Saturate: '<S67>/Saturation' */

    /* Gain: '<S67>/Hz->rad//s' */
    rtb_Integrator_p *= 6.28318548F;

    /* Product: '<S67>/Product' incorporates:
     *  DiscreteIntegrator: '<S88>/Integrator'
     *  Math: '<S67>/Math Function'
     */
    rtb_Product_m = rtb_Integrator_p * rtb_Integrator_p * rtDW.Integrator_DSTATE;

    /* DiscreteIntegrator: '<S89>/Integrator' incorporates:
     *  Constant: '<S67>/Constant2'
     */
    if (rtDW.Integrator_PrevResetState_a != 0) {
      rtDW.Integrator_DSTATE_p = 0.0F;
    }

    /* Product: '<S67>/Product1' incorporates:
     *  DiscreteIntegrator: '<S89>/Integrator'
     *  Gain: '<S67>/Gain'
     */
    rtb_Product1_f = 1.414F * rtb_Integrator_p * rtDW.Integrator_DSTATE_p;

    /* DiscreteIntegrator: '<S76>/Integrator' incorporates:
     *  Constant: '<S64>/Constant3'
     */
    if (rtDW.Integrator_PrevResetState_g != 0) {
      rtDW.Integrator_DSTATE_d = 0.0F;
    }

    /* Saturate: '<S64>/Saturation' incorporates:
     *  Constant: '<S58>/Const1'
     */
    rtb_Integrator_p = HFI_Parameter.HFI_Inj_HF - HFI_Parameter.HFI_bw_BPF /
      2.0F;
    if (rtb_Integrator_p <= 2.22044605E-16F) {
      rtb_Integrator_p = 2.22044605E-16F;
    }

    /* End of Saturate: '<S64>/Saturation' */

    /* Gain: '<S64>/Hz->rad//s' */
    rtb_Integrator_p *= 6.28318548F;

    /* Product: '<S64>/Product' incorporates:
     *  DiscreteIntegrator: '<S76>/Integrator'
     *  Math: '<S64>/Math Function'
     */
    rtb_Product_e = rtb_Integrator_p * rtb_Integrator_p *
      rtDW.Integrator_DSTATE_d;

    /* DiscreteIntegrator: '<S77>/Integrator' incorporates:
     *  Constant: '<S64>/Constant2'
     */
    if (rtDW.Integrator_PrevResetState_p != 0) {
      rtDW.Integrator_DSTATE_k = 0.0F;
    }

    /* Product: '<S64>/Product1' incorporates:
     *  DiscreteIntegrator: '<S77>/Integrator'
     *  Gain: '<S64>/Gain'
     */
    rtb_Product1_lr = 1.414F * rtb_Integrator_p * rtDW.Integrator_DSTATE_k;

    /* Delay: '<S58>/Delay2' */
    rtDW.Add_l = rtDW.Delay2_DSTATE_h;

    /* Saturate: '<S144>/Saturation' */
    if (rtDW.Add_l > 6.28218508F) {
      rtb_Integrator_p = 6.28218508F;
    } else if (rtDW.Add_l < 0.001F) {
      rtb_Integrator_p = 0.001F;
    } else {
      rtb_Integrator_p = rtDW.Add_l;
    }

    /* End of Saturate: '<S144>/Saturation' */

    /* Lookup_n-D: '<S144>/Sine' incorporates:
     *  Lookup_n-D: '<S144>/Cosine'
     *  Product: '<S124>/IProd Out'
     */
    rtb_Produc3t_tmp = plook_u32f_evencka(rtb_Integrator_p, 0.0F, 0.00153435534F,
      4095U);

    /* Sum: '<S64>/Sum' incorporates:
     *  Lookup_n-D: '<S144>/Cosine'
     *  Lookup_n-D: '<S144>/Sine'
     *  Product: '<S73>/Produc3t'
     *  Product: '<S73>/Product4'
     *  Sum: '<S73>/Add2'
     */
    rtb_Produc3t = ((Ibeta * rtConstP.pooled18[rtb_Produc3t_tmp] - Ialpha *
                     rtConstP.pooled14[rtb_Produc3t_tmp]) - rtb_Product_e) -
      rtb_Product1_lr;

    /* Sum: '<S67>/Sum' incorporates:
     *  MultiPortSwitch: '<S64>/Multiport Switch'
     */
    rtb_Product1_lr = (rtb_Produc3t - rtb_Product_m) - rtb_Product1_f;

    /* DiscreteIntegrator: '<S92>/Integrator' incorporates:
     *  Constant: '<S68>/Constant3'
     */
    if (rtDW.Integrator_PrevResetState_k != 0) {
      rtDW.Integrator_DSTATE_ph = 0.0F;
    }

    /* Product: '<S68>/Product' incorporates:
     *  DiscreteIntegrator: '<S92>/Integrator'
     */
    rtb_Integrator_p = rtDW.Integrator_DSTATE_ph * 394784.188F;

    /* DiscreteIntegrator: '<S93>/Integrator' incorporates:
     *  Constant: '<S68>/Constant2'
     */
    if (rtDW.Integrator_PrevResetState_h != 0) {
      rtDW.Integrator_DSTATE_i = 0.0F;
    }

    /* Sum: '<S68>/Sum' incorporates:
     *  Constant: '<S58>/Const'
     *  DiscreteIntegrator: '<S93>/Integrator'
     *  DotProduct: '<S58>/Dot Product'
     *  MultiPortSwitch: '<S67>/Multiport Switch'
     *  Product: '<S58>/Product'
     *  Product: '<S68>/Product1'
     */
    rtb_Product_m = (6.28318548F * HFI_Parameter.HFI_Inj_HF *
                     DiscreteTimeIntegrator_c * rtb_Product_m - rtb_Integrator_p)
      - rtDW.Integrator_DSTATE_i * 888.442444F;

    /* Sum: '<S136>/Sum' incorporates:
     *  Constant: '<S58>/Kp'
     *  DiscreteIntegrator: '<S127>/Integrator'
     *  Product: '<S132>/PProd Out'
     */
    rtb_Product_e = 2.0F * HFI_Parameter.HFI_PLL_Omga * HFI_Parameter.HFI_PLL_Xi
      * rtb_Integrator_p + rtDW.Integrator_DSTATE_a;

    /* DeadZone: '<S120>/DeadZone' */
    if (rtb_Product_e > 314159.25F) {
      rtb_Product1_f = rtb_Product_e - 314159.25F;
    } else if (rtb_Product_e >= -314159.25F) {
      rtb_Product1_f = 0.0F;
    } else {
      rtb_Product1_f = rtb_Product_e - -314159.25F;
    }

    /* End of DeadZone: '<S120>/DeadZone' */

    /* RelationalOperator: '<S118>/NotEqual' incorporates:
     *  Gain: '<S118>/ZeroGain'
     */
    rtb_NotEqual = (0.0F * rtb_Product_e != rtb_Product1_f);

    /* Signum: '<S118>/SignPreSat' */
    if (rtb_Product1_f < 0.0F) {
      rtb_Product1_f = -1.0F;
    } else if (rtb_Product1_f > 0.0F) {
      rtb_Product1_f = 1.0F;
    } else if (rtb_Product1_f == 0.0F) {
      rtb_Product1_f = 0.0F;
    } else {
      rtb_Product1_f = (rtNaNF);
    }

    /* End of Signum: '<S118>/SignPreSat' */

    /* DataTypeConversion: '<S118>/DataTypeConv1' */
    rtAction = (int8_T)rtb_Product1_f;

    /* Product: '<S124>/IProd Out' incorporates:
     *  Constant: '<S58>/Ki'
     */
    rtb_Integrator_p *= HFI_Parameter.HFI_PLL_Omga * HFI_Parameter.HFI_PLL_Omga;

    /* Saturate: '<S134>/Saturation' */
    if (rtb_Product_e > 314159.25F) {
      /* Saturate: '<S134>/Saturation' */
      rtb_Product_e = 314159.25F;
    } else {
      if (rtb_Product_e < -314159.25F) {
        /* Saturate: '<S134>/Saturation' */
        rtb_Product_e = -314159.25F;
      }
    }

    /* End of Saturate: '<S134>/Saturation' */

    /* UnitDelay: '<S69>/Unit Delay' */
    rtb_Product1_f = rtDW.UnitDelay_DSTATE_c;

    /* Sum: '<S69>/Add1' incorporates:
     *  Constant: '<S69>/Constant1'
     *  Product: '<S69>/Divide1'
     *  Sum: '<S69>/Add'
     */
    rtb_Product1_f += (rtb_Product_e - rtb_Product1_f) * SpeedFilter_Fn;

    /* Gain: '<S58>/freq <-- wm1' */
    rtDW.freqwm1 = 4.77464819F * rtb_Product1_f;

    /* DiscreteIntegrator: '<S58>/Discrete-Time Integrator1' */
    rtb_Product_e = 0.0001F * rtb_Product_e +
      rtDW.DiscreteTimeIntegrator1_DSTATE;

    /* Chart: '<S58>/StartRUN_State_machine' */
    StartRUN_State_machine();
    rtDW.IPD_angle = rtDW.Delay2_DSTATE;

    /* If: '<S58>/If2' incorporates:
     *  Delay: '<S57>/Delay2'
     *  Inport: '<S58>/IPD_angle'
     */
    if (rtDW.RUN_state < 3) {
      /* Outputs for IfAction SubSystem: '<S58>/HFI_Angle1' incorporates:
       *  ActionPort: '<S63>/Action Port'
       */
      /* Sum: '<S63>/Subtract' */
      rtDW.Subtract = rtDW.Add_l - rtDW.IPD_angle;

      /* End of Outputs for SubSystem: '<S58>/HFI_Angle1' */
    }

    /* End of If: '<S58>/If2' */

    /* If: '<S58>/If1' incorporates:
     *  Inport: '<S62>/Theta'
     */
    if ((rtDW.Subtract > 1.4F) && (rtDW.Subtract < 4.0F)) {
      /* Outputs for IfAction SubSystem: '<S58>/IPD_Angle' incorporates:
       *  ActionPort: '<S65>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S65>/Angle_calibration' */
      Angle_calibration();

      /* End of Outputs for SubSystem: '<S65>/Angle_calibration' */
      /* End of Outputs for SubSystem: '<S58>/IPD_Angle' */
    } else if ((rtDW.Subtract < -1.4F) && (rtDW.Subtract > -4.0F)) {
      /* Outputs for IfAction SubSystem: '<S58>/IPD_Angle1' incorporates:
       *  ActionPort: '<S66>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S66>/Angle_calibration' */
      Angle_calibration_h();

      /* End of Outputs for SubSystem: '<S66>/Angle_calibration' */
      /* End of Outputs for SubSystem: '<S58>/IPD_Angle1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S58>/HFI_Angle' incorporates:
       *  ActionPort: '<S62>/Action Port'
       */
      rtDW.Merge2_o = rtDW.Add_l;

      /* End of Outputs for SubSystem: '<S58>/HFI_Angle' */
    }

    /* End of If: '<S58>/If1' */

    /* Sum: '<S71>/Add' incorporates:
     *  Constant: '<S71>/Const1'
     */
    rtDW.Add_l = 6.28318548F * HFI_Parameter.HFI_Inj_HF / 10000.0F +
      rtb_Product1_bq;

    /* SignalConversion generated from: '<S58>/theta_est' */
    rtDW.Merge2_i = rtDW.Merge2_o;

    /* Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE_i5 = DiscreteTimeIntegrator_c;

    /* Update for DiscreteIntegrator: '<S88>/Integrator' incorporates:
     *  DiscreteIntegrator: '<S89>/Integrator'
     */
    rtDW.Integrator_DSTATE += 0.0001F * rtDW.Integrator_DSTATE_p;
    rtDW.Integrator_PrevResetState = 0;

    /* Update for DiscreteIntegrator: '<S89>/Integrator' */
    rtDW.Integrator_DSTATE_p += 0.0001F * rtb_Product1_lr;
    rtDW.Integrator_PrevResetState_a = 0;

    /* Update for DiscreteIntegrator: '<S76>/Integrator' incorporates:
     *  DiscreteIntegrator: '<S77>/Integrator'
     */
    rtDW.Integrator_DSTATE_d += 0.0001F * rtDW.Integrator_DSTATE_k;
    rtDW.Integrator_PrevResetState_g = 0;

    /* Update for DiscreteIntegrator: '<S77>/Integrator' */
    rtDW.Integrator_DSTATE_k += 0.0001F * rtb_Produc3t;
    rtDW.Integrator_PrevResetState_p = 0;

    /* Update for Delay: '<S58>/Delay2' incorporates:
     *  Constant: '<S58>/Constant1'
     *  Math: '<S58>/Math Function'
     */
    rtDW.Delay2_DSTATE_h = rt_modf_snf(rtb_Product_e, 6.28318548F);

    /* Update for DiscreteIntegrator: '<S92>/Integrator' incorporates:
     *  DiscreteIntegrator: '<S93>/Integrator'
     */
    rtDW.Integrator_DSTATE_ph += 0.0001F * rtDW.Integrator_DSTATE_i;
    rtDW.Integrator_PrevResetState_k = 0;

    /* Update for DiscreteIntegrator: '<S93>/Integrator' */
    rtDW.Integrator_DSTATE_i += 0.0001F * rtb_Product_m;
    rtDW.Integrator_PrevResetState_h = 0;

    /* Signum: '<S118>/SignPreIntegrator' */
    if (rtb_Integrator_p < 0.0F) {
      rtb_Product1_bq = -1.0F;
    } else if (rtb_Integrator_p > 0.0F) {
      rtb_Product1_bq = 1.0F;
    } else if (rtb_Integrator_p == 0.0F) {
      rtb_Product1_bq = 0.0F;
    } else {
      rtb_Product1_bq = (rtNaNF);
    }

    /* End of Signum: '<S118>/SignPreIntegrator' */

    /* Switch: '<S118>/Switch' incorporates:
     *  Constant: '<S118>/Constant1'
     *  DataTypeConversion: '<S118>/DataTypeConv2'
     *  Logic: '<S118>/AND3'
     *  RelationalOperator: '<S118>/Equal1'
     */
    if (rtb_NotEqual && (rtAction == (int8_T)rtb_Product1_bq)) {
      rtb_Integrator_p = 0.0F;
    }

    /* End of Switch: '<S118>/Switch' */

    /* Update for DiscreteIntegrator: '<S127>/Integrator' */
    rtDW.Integrator_DSTATE_a += 0.0001F * rtb_Integrator_p;

    /* Update for UnitDelay: '<S69>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_c = rtb_Product1_f;

    /* Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTATE = rtb_Product_e;

    /* End of Outputs for SubSystem: '<S57>/HFI' */
    break;
  }

  /* End of SwitchCase: '<S57>/Switch Case1' */
}

/* Update for action system: '<S40>/HFI_Function' */
void HFI_Function_Update(void)
{
  /* Update for Delay: '<S57>/Delay' */
  rtDW.Delay_DSTATE = Id_measured;

  /* Update for Delay: '<S57>/Delay1' */
  rtDW.Delay1_DSTATE = rtDW.Gain1;

  /* Update for Delay: '<S57>/Delay2' */
  rtDW.Delay2_DSTATE = rtDW.DataTypeConversion_k;
}

/* System initialize for atomic system: '<S36>/HF_Observer' */
void HF_Observer_Init(void)
{
  /* Start for If: '<S40>/If1' */
  rtDW.If1_ActiveSubsystem_i = -1;

  /* SystemInitialize for IfAction SubSystem: '<S40>/HFI_Function' */
  HFI_Function_Init();

  /* End of SystemInitialize for SubSystem: '<S40>/HFI_Function' */
}

/* Outputs for atomic system: '<S36>/HF_Observer' */
void HF_Observer(void)
{
  int8_T rtAction;

  /* If: '<S40>/If1' incorporates:
   *  Constant: '<S40>/HFI_Enalble'
   */
  rtAction = -1;
  if (HFI_Parameter.HFI_Fuc_Enalbe == 1) {
    rtAction = 0;
  }

  rtDW.If1_ActiveSubsystem_i = rtAction;
  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S40>/HFI_Function' incorporates:
     *  ActionPort: '<S57>/Action Port'
     */
    HFI_Function();

    /* End of Outputs for SubSystem: '<S40>/HFI_Function' */
  }

  /* End of If: '<S40>/If1' */
}

/* Update for atomic system: '<S36>/HF_Observer' */
void HF_Observer_Update(void)
{
  /* Update for If: '<S40>/If1' */
  if (rtDW.If1_ActiveSubsystem_i == 0) {
    /* Update for IfAction SubSystem: '<S40>/HFI_Function' incorporates:
     *  ActionPort: '<S57>/Action Port'
     */
    HFI_Function_Update();

    /* End of Update for SubSystem: '<S40>/HFI_Function' */
  }

  /* End of Update for If: '<S40>/If1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
