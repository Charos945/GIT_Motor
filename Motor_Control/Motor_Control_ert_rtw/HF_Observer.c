/*
 * File: HF_Observer.c
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

#include "HF_Observer.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Named constants for Chart: '<S208>/HFI_State_machine' */
#define IN_HFI_IPD                     ((uint8_T)1U)
#define IN_HFI_NS                      ((uint8_T)2U)
#define IN_HFI_RUN                     ((uint8_T)3U)

/* Named constants for Chart: '<S212>/NS_State_machine' */
#define IN_NS_1                        ((uint8_T)1U)
#define IN_NS_2                        ((uint8_T)2U)
#define IN_NS_3                        ((uint8_T)3U)
#define IN_NS_4                        ((uint8_T)4U)
#define IN_NS_5                        ((uint8_T)5U)

/* Named constants for Chart: '<S209>/StartRUN_State_machine' */
#define IN_NS_2_RUN                    ((uint8_T)1U)
#define IN_RUN                         ((uint8_T)2U)
#define IN_Start_RUN                   ((uint8_T)3U)

/* Output and update for atomic system: '<S208>/HFI_State_machine' */
void HFI_State_machine(void)
{
  if (rtDW.temporalCounter_i1_g < MAX_uint32_T) {
    rtDW.temporalCounter_i1_g++;
  }

  /* Chart: '<S208>/HFI_State_machine' incorporates:
   *  Constant: '<S208>/HFI_Enalble'
   */
  if (rtDW.is_active_c7_Motor_Control == 0U) {
    rtDW.is_active_c7_Motor_Control = 1U;
    rtDW.is_c7_Motor_Control = IN_HFI_IPD;
    rtDW.temporalCounter_i1_g = 0U;
    rtDW.HFI_state = 1U;
    rtDW.IPD_flag = 1.0;
  } else {
    switch (rtDW.is_c7_Motor_Control) {
     case IN_HFI_IPD:
      rtDW.HFI_state = 1U;
      if ((rtDW.temporalCounter_i1_g >= (uint32_T)ceil(HFI.IPD_Time / 0.0001 -
            1.0E-12)) && (HFI.Func_Enable == 1) && (rtDW.IPD_flag == 1.0)) {
        rtDW.is_c7_Motor_Control = IN_HFI_NS;
        rtDW.temporalCounter_i1_g = 0U;
        rtDW.HFI_state = 2U;
        rtDW.NS_flag = 1.0;
      }
      break;

     case IN_HFI_NS:
      rtDW.HFI_state = 2U;
      if ((rtDW.temporalCounter_i1_g >= (uint32_T)ceil(HFI.NS_Time / 0.0001 -
            1.0E-12)) && (rtDW.NS_flag == 1.0)) {
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

  /* End of Chart: '<S208>/HFI_State_machine' */
}

/* Output and update for atomic system: '<S211>/Sine_Cosine' */
void Sine_Cosine(void)
{
  uint32_T Gain1_e_tmp;

  /* Lookup_n-D: '<S246>/Cosine' incorporates:
   *  Lookup_n-D: '<S246>/Sine'
   *  Product: '<S245>/Product1'
   */
  Gain1_e_tmp = plook_u32f_evencka(rtDW.Product1, 0.0F, 0.00153435534F, 4095U);

  /* Gain: '<S247>/Gain1' incorporates:
   *  Lookup_n-D: '<S246>/Cosine'
   */
  rtDW.Gain1_e = rtConstP.pooled31[Gain1_e_tmp];

  /* Lookup_n-D: '<S246>/Sine' */
  rtDW.Sine_cu = rtConstP.pooled33[Gain1_e_tmp];
}

/* Output and update for action system: '<S208>/IPD' */
void IPD(void)
{
  real32_T rtb_Add;
  real32_T rtb_RMS;
  real32_T rtb_RMS1;
  real32_T rtb_RMS2;

  /* Product: '<S245>/Product1' incorporates:
   *  Constant: '<S245>/Const2'
   *  Delay: '<S245>/Delay'
   *  Memory: '<S245>/Memory'
   *  RelationalOperator: '<S245>/Relational Operator1'
   */
  rtDW.Product1 = (real32_T)(rtDW.Delay_DSTATE_a < 6.28318548F) *
    rtDW.Memory_PreviousInput_jp;

  /* Outputs for Atomic SubSystem: '<S211>/Sine_Cosine' */
  Sine_Cosine();

  /* End of Outputs for SubSystem: '<S211>/Sine_Cosine' */

  /* Merge: '<S208>/Merge' incorporates:
   *  Constant: '<S211>/Constant'
   *  Fcn: '<S211>/7'
   */
  rtDW.Merge_f = HFI.IPD_V * rtDW.Gain1_e;

  /* Merge: '<S208>/Merge1' incorporates:
   *  Constant: '<S211>/Constant'
   *  Fcn: '<S211>/8'
   */
  rtDW.Merge1_g = HFI.IPD_V * rtDW.Sine_cu;

  /* Sum: '<S245>/Add' incorporates:
   *  Constant: '<S245>/Const1'
   */
  rtb_Add = 0.000628318521F * HFI.IPD_F + rtDW.Product1;

  /* S-Function (sdspstatfcns): '<S247>/RMS' incorporates:
   *  Inport: '<Root>/Phase_CurrentABC'
   */
  rtDW.RMS_Iteration++;
  if (rtDW.RMS_Iteration > 1U) {
    rtDW.RMS_SqData += rtU.Phase_CurrentABC[0] * rtU.Phase_CurrentABC[0];
    rtb_RMS = (real32_T)sqrt(rtDW.RMS_SqData / (real32_T)rtDW.RMS_Iteration);
  } else {
    if (rtDW.RMS_Iteration == 0U) {
      rtDW.RMS_Iteration = 1U;
    }

    rtDW.RMS_SqData = rtU.Phase_CurrentABC[0] * rtU.Phase_CurrentABC[0];
    rtb_RMS = (real32_T)fabs(rtU.Phase_CurrentABC[0]);
  }

  /* End of S-Function (sdspstatfcns): '<S247>/RMS' */

  /* S-Function (sdspstatfcns): '<S247>/RMS1' incorporates:
   *  Inport: '<Root>/Phase_CurrentABC'
   */
  rtDW.RMS1_Iteration++;
  if (rtDW.RMS1_Iteration > 1U) {
    rtDW.RMS1_SqData += rtU.Phase_CurrentABC[1] * rtU.Phase_CurrentABC[1];
    rtb_RMS1 = (real32_T)sqrt(rtDW.RMS1_SqData / (real32_T)rtDW.RMS1_Iteration);
  } else {
    if (rtDW.RMS1_Iteration == 0U) {
      rtDW.RMS1_Iteration = 1U;
    }

    rtDW.RMS1_SqData = rtU.Phase_CurrentABC[1] * rtU.Phase_CurrentABC[1];
    rtb_RMS1 = (real32_T)fabs(rtU.Phase_CurrentABC[1]);
  }

  /* End of S-Function (sdspstatfcns): '<S247>/RMS1' */

  /* S-Function (sdspstatfcns): '<S247>/RMS2' incorporates:
   *  Inport: '<Root>/Phase_CurrentABC'
   */
  rtDW.RMS2_Iteration++;
  if (rtDW.RMS2_Iteration > 1U) {
    rtDW.RMS2_SqData += rtU.Phase_CurrentABC[2] * rtU.Phase_CurrentABC[2];
    rtb_RMS2 = (real32_T)sqrt(rtDW.RMS2_SqData / (real32_T)rtDW.RMS2_Iteration);
  } else {
    if (rtDW.RMS2_Iteration == 0U) {
      rtDW.RMS2_Iteration = 1U;
    }

    rtDW.RMS2_SqData = rtU.Phase_CurrentABC[2] * rtU.Phase_CurrentABC[2];
    rtb_RMS2 = (real32_T)fabs(rtU.Phase_CurrentABC[2]);
  }

  /* End of S-Function (sdspstatfcns): '<S247>/RMS2' */

  /* If: '<S247>/If1' */
  if ((rtb_RMS > rtb_RMS2) && (rtb_RMS2 > rtb_RMS1)) {
    /* Outputs for IfAction SubSystem: '<S247>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S249>/Action Port'
     */
    /* Merge: '<S247>/Merge' incorporates:
     *  Fcn: '<S249>/Fcn'
     */
    rtDW.Merge_c = (rtb_RMS2 - rtb_RMS1) / (rtb_RMS - rtb_RMS1) * 30.0F;

    /* End of Outputs for SubSystem: '<S247>/If Action Subsystem2' */
  } else if ((rtb_RMS2 > rtb_RMS) && (rtb_RMS > rtb_RMS1)) {
    /* Outputs for IfAction SubSystem: '<S247>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S248>/Action Port'
     */
    /* Merge: '<S247>/Merge' incorporates:
     *  Fcn: '<S248>/Fcn'
     */
    rtDW.Merge_c = (rtb_RMS2 - rtb_RMS) / (rtb_RMS2 - rtb_RMS1) * 30.0F + 30.0F;

    /* End of Outputs for SubSystem: '<S247>/If Action Subsystem1' */
  } else if ((rtb_RMS2 > rtb_RMS1) && (rtb_RMS1 > rtb_RMS)) {
    /* Outputs for IfAction SubSystem: '<S247>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S250>/Action Port'
     */
    /* Merge: '<S247>/Merge' incorporates:
     *  Fcn: '<S250>/Fcn'
     */
    rtDW.Merge_c = (rtb_RMS1 - rtb_RMS) / (rtb_RMS2 - rtb_RMS) * 30.0F + 60.0F;

    /* End of Outputs for SubSystem: '<S247>/If Action Subsystem3' */
  } else if ((rtb_RMS1 > rtb_RMS2) && (rtb_RMS2 > rtb_RMS)) {
    /* Outputs for IfAction SubSystem: '<S247>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S251>/Action Port'
     */
    /* Merge: '<S247>/Merge' incorporates:
     *  Fcn: '<S251>/Fcn'
     */
    rtDW.Merge_c = (rtb_RMS1 - rtb_RMS2) / (rtb_RMS1 - rtb_RMS) * 30.0F + 90.0F;

    /* End of Outputs for SubSystem: '<S247>/If Action Subsystem4' */
  } else if ((rtb_RMS1 > rtb_RMS) && (rtb_RMS > rtb_RMS2)) {
    /* Outputs for IfAction SubSystem: '<S247>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S252>/Action Port'
     */
    /* Merge: '<S247>/Merge' incorporates:
     *  Fcn: '<S252>/Fcn'
     */
    rtDW.Merge_c = (rtb_RMS - rtb_RMS2) / (rtb_RMS1 - rtb_RMS2) * 30.0F + 120.0F;

    /* End of Outputs for SubSystem: '<S247>/If Action Subsystem5' */
  } else {
    if ((rtb_RMS > rtb_RMS1) && (rtb_RMS1 > rtb_RMS2)) {
      /* Outputs for IfAction SubSystem: '<S247>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S253>/Action Port'
       */
      /* Merge: '<S247>/Merge' incorporates:
       *  Fcn: '<S253>/Fcn'
       */
      rtDW.Merge_c = (rtb_RMS - rtb_RMS1) / (rtb_RMS - rtb_RMS2) * 30.0F +
        150.0F;

      /* End of Outputs for SubSystem: '<S247>/If Action Subsystem6' */
    }
  }

  /* End of If: '<S247>/If1' */

  /* Gain: '<S247>/Gain1' */
  rtDW.Gain1_e = 0.0174532924F * rtDW.Merge_c;

  /* Update for Delay: '<S245>/Delay' */
  rtDW.Delay_DSTATE_a = rtb_Add;

  /* Update for Memory: '<S245>/Memory' */
  rtDW.Memory_PreviousInput_jp = rtb_Add;
}

/* Output and update for atomic system: '<S212>/NS_State_machine' */
void NS_State_machine(void)
{
  if (rtDW.temporalCounter_i1_m < MAX_uint32_T) {
    rtDW.temporalCounter_i1_m++;
  }

  /* Chart: '<S212>/NS_State_machine' */
  if (rtDW.is_active_c8_Motor_Control == 0U) {
    rtDW.is_active_c8_Motor_Control = 1U;
    rtDW.is_c8_Motor_Control = IN_NS_1;
    rtDW.temporalCounter_i1_m = 0U;
    rtDW.NS_state = 1U;
    rtDW.NS_1_flag = 1.0;
  } else {
    switch (rtDW.is_c8_Motor_Control) {
     case IN_NS_1:
      rtDW.NS_state = 1U;
      if ((rtDW.temporalCounter_i1_m >= (uint32_T)ceil(HFI.NS_Low_Time / 0.0001
            - 1.0E-12)) && (rtDW.NS_1_flag == 1.0)) {
        rtDW.is_c8_Motor_Control = IN_NS_2;
        rtDW.temporalCounter_i1_m = 0U;
        rtDW.NS_state = 2U;
        rtDW.NS_2_flag = 1.0;
      }
      break;

     case IN_NS_2:
      rtDW.NS_state = 2U;
      if ((rtDW.temporalCounter_i1_m >= (uint32_T)ceil(HFI.NS_Plus_Time / 0.0001
            - 1.0E-12)) && (rtDW.NS_2_flag == 1.0)) {
        rtDW.is_c8_Motor_Control = IN_NS_3;
        rtDW.temporalCounter_i1_m = 0U;
        rtDW.NS_state = 3U;
        rtDW.NS_3_flag = 1.0;
      }
      break;

     case IN_NS_3:
      rtDW.NS_state = 3U;
      if ((rtDW.temporalCounter_i1_m >= (uint32_T)ceil(HFI.NS_Low_Time / 0.0001
            - 1.0E-12)) && (rtDW.NS_3_flag == 1.0)) {
        rtDW.is_c8_Motor_Control = IN_NS_4;
        rtDW.temporalCounter_i1_m = 0U;
        rtDW.NS_state = 4U;
        rtDW.NS_4_flag = 1.0;
      }
      break;

     case IN_NS_4:
      rtDW.NS_state = 4U;
      if ((rtDW.temporalCounter_i1_m >= (uint32_T)ceil(HFI.NS_Plus_Time / 0.0001
            - 1.0E-12)) && (rtDW.NS_4_flag == 1.0)) {
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

  /* End of Chart: '<S212>/NS_State_machine' */
}

/* Output and update for atomic system: '<S255>/Sine_Cosine' */
void Sine_Cosine_n(void)
{
  uint32_T Cosine_f_tmp;

  /* Lookup_n-D: '<S260>/Cosine' incorporates:
   *  Delay: '<S208>/Delay1'
   *  Lookup_n-D: '<S260>/Sine'
   */
  Cosine_f_tmp = plook_u32f_evencka(rtDW.Delay1, 0.0F, 0.00153435534F, 4095U);

  /* Lookup_n-D: '<S260>/Cosine' */
  rtDW.Cosine_f = rtConstP.pooled31[Cosine_f_tmp];

  /* Lookup_n-D: '<S260>/Sine' */
  rtDW.Sine_j = rtConstP.pooled33[Cosine_f_tmp];
}

/* Output and update for atomic system: '<S256>/Sine_Cosine' */
void Sine_Cosine_l(void)
{
  uint32_T Id_j_tmp;

  /* Lookup_n-D: '<S261>/Cosine' incorporates:
   *  Delay: '<S208>/Delay1'
   *  Inport: '<S256>/Id'
   *  Lookup_n-D: '<S261>/Sine'
   */
  Id_j_tmp = plook_u32f_evencka(rtDW.Delay1, 0.0F, 0.00153435534F, 4095U);
  rtDW.Id_j = rtConstP.pooled31[Id_j_tmp];

  /* Lookup_n-D: '<S261>/Sine' */
  rtDW.Sine_b = rtConstP.pooled33[Id_j_tmp];
}

/* Output and update for atomic system: '<S257>/Sine_Cosine' */
void Sine_Cosine_d(void)
{
  uint32_T Cosine_tmp;

  /* Lookup_n-D: '<S262>/Cosine' incorporates:
   *  Delay: '<S208>/Delay1'
   *  Lookup_n-D: '<S262>/Sine'
   */
  Cosine_tmp = plook_u32f_evencka(rtDW.Delay1, 0.0F, 0.00153435534F, 4095U);

  /* Lookup_n-D: '<S262>/Cosine' */
  rtDW.Cosine = rtConstP.pooled31[Cosine_tmp];

  /* Lookup_n-D: '<S262>/Sine' */
  rtDW.Sine_i = rtConstP.pooled33[Cosine_tmp];
}

/* Output and update for atomic system: '<S258>/Sine_Cosine' */
void Sine_Cosine_d3(void)
{
  uint32_T Id_tmp;

  /* Lookup_n-D: '<S263>/Cosine' incorporates:
   *  Inport: '<S258>/Id'
   *  Lookup_n-D: '<S263>/Sine'
   *  Merge: '<S264>/Merge1'
   */
  Id_tmp = plook_u32f_evencka(rtDW.Merge1_ok, 0.0F, 0.00153435534F, 4095U);
  rtDW.Id = rtConstP.pooled31[Id_tmp];

  /* Lookup_n-D: '<S263>/Sine' */
  rtDW.Sine_g = rtConstP.pooled33[Id_tmp];
}

/*
 * Output and update for action system:
 *    '<S264>/If Action Subsystem2'
 *    '<S270>/If Action Subsystem2'
 */
void IfActionSubsystem2(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S266>/Subtract1' incorporates:
   *  Constant: '<S266>/2pi'
   */
  *rty_Out1 = rtu_In1 - 6.28318548F;
}

/* Output and update for action system: '<S208>/NS' */
void NS(void)
{
  real32_T rtb_Abs;
  real32_T rtb_Abs1;
  real32_T rtb_Cosine;
  real32_T rtb_Sine;
  uint32_T rtb_Sine_tmp;

  /* Abs: '<S212>/Abs' incorporates:
   *  Delay: '<S212>/Delay'
   */
  rtb_Abs = (real32_T)fabs(rtDW.Delay_DSTATE_hw);

  /* Abs: '<S212>/Abs1' incorporates:
   *  Delay: '<S212>/Delay1'
   */
  rtb_Abs1 = (real32_T)fabs(rtDW.Delay1_DSTATE_l);

  /* Chart: '<S212>/NS_State_machine' */
  NS_State_machine();

  /* SwitchCase: '<S212>/Switch Case1' incorporates:
   *  Inport: '<S256>/Id'
   *  Inport: '<S258>/Id'
   */
  switch (rtDW.NS_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S212>/Ud_inject_1' incorporates:
     *  ActionPort: '<S255>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S255>/Sine_Cosine' */
    Sine_Cosine_n();

    /* End of Outputs for SubSystem: '<S255>/Sine_Cosine' */

    /* Merge: '<S212>/Merge' incorporates:
     *  Constant: '<S255>/Constant'
     *  Constant: '<S255>/Constant2'
     *  Fcn: '<S255>/1'
     */
    rtDW.Merge_i = 0.0F * rtDW.Cosine_f - 0.0F * rtDW.Sine_j;

    /* Merge: '<S212>/Merge1' incorporates:
     *  Constant: '<S255>/Constant'
     *  Constant: '<S255>/Constant2'
     *  Fcn: '<S255>/2'
     */
    rtDW.Merge1_mx = 0.0F * rtDW.Sine_j + 0.0F * rtDW.Cosine_f;

    /* End of Outputs for SubSystem: '<S212>/Ud_inject_1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S212>/Ud_inject_2' incorporates:
     *  ActionPort: '<S256>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S256>/Sine_Cosine' */
    Sine_Cosine_l();

    /* End of Outputs for SubSystem: '<S256>/Sine_Cosine' */

    /* Merge: '<S212>/Merge' incorporates:
     *  Constant: '<S256>/Constant'
     *  Constant: '<S256>/Constant2'
     *  Fcn: '<S256>/1'
     */
    rtDW.Merge_i = HFI.NS_V * rtDW.Id_j - 0.0F * rtDW.Sine_b;

    /* Merge: '<S212>/Merge1' incorporates:
     *  Constant: '<S256>/Constant'
     *  Constant: '<S256>/Constant2'
     *  Fcn: '<S256>/2'
     */
    rtDW.Merge1_mx = HFI.NS_V * rtDW.Sine_b + 0.0F * rtDW.Id_j;
    rtDW.Id_j = rtDW.Delay;

    /* End of Outputs for SubSystem: '<S212>/Ud_inject_2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S212>/Ud_inject_3' incorporates:
     *  ActionPort: '<S257>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S257>/Sine_Cosine' */
    Sine_Cosine_d();

    /* End of Outputs for SubSystem: '<S257>/Sine_Cosine' */

    /* Merge: '<S212>/Merge' incorporates:
     *  Constant: '<S257>/Constant'
     *  Constant: '<S257>/Constant2'
     *  Fcn: '<S257>/1'
     */
    rtDW.Merge_i = 0.0F * rtDW.Cosine - 0.0F * rtDW.Sine_i;

    /* Merge: '<S212>/Merge1' incorporates:
     *  Constant: '<S257>/Constant'
     *  Constant: '<S257>/Constant2'
     *  Fcn: '<S257>/2'
     */
    rtDW.Merge1_mx = 0.0F * rtDW.Sine_i + 0.0F * rtDW.Cosine;

    /* End of Outputs for SubSystem: '<S212>/Ud_inject_3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S212>/Ud_inject_4' incorporates:
     *  ActionPort: '<S258>/Action Port'
     */
    /* If: '<S264>/If1' incorporates:
     *  Constant: '<S264>/Angle_offset'
     *  Inport: '<S265>/In1'
     *  Sum: '<S264>/Subtract1'
     */
    if (rtDW.Delay1 + 3.14159274F > 6.28318548F) {
      /* Outputs for IfAction SubSystem: '<S264>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S266>/Action Port'
       */
      IfActionSubsystem2(rtDW.Delay1 + 3.14159274F, &rtDW.Merge1_ok);

      /* End of Outputs for SubSystem: '<S264>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S264>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S265>/Action Port'
       */
      rtDW.Merge1_ok = rtDW.Delay1 + 3.14159274F;

      /* End of Outputs for SubSystem: '<S264>/If Action Subsystem1' */
    }

    /* End of If: '<S264>/If1' */

    /* Outputs for Atomic SubSystem: '<S258>/Sine_Cosine' */
    Sine_Cosine_d3();

    /* End of Outputs for SubSystem: '<S258>/Sine_Cosine' */

    /* Merge: '<S212>/Merge' incorporates:
     *  Constant: '<S258>/Constant'
     *  Constant: '<S258>/Constant2'
     *  Fcn: '<S258>/1'
     */
    rtDW.Merge_i = HFI.NS_V * rtDW.Id - 0.0F * rtDW.Sine_g;

    /* Merge: '<S212>/Merge1' incorporates:
     *  Constant: '<S258>/Constant'
     *  Constant: '<S258>/Constant2'
     *  Fcn: '<S258>/2'
     */
    rtDW.Merge1_mx = HFI.NS_V * rtDW.Sine_g + 0.0F * rtDW.Id;
    rtDW.Id = rtDW.Delay;

    /* End of Outputs for SubSystem: '<S212>/Ud_inject_4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S212>/Ud_inject_5' incorporates:
     *  ActionPort: '<S259>/Action Port'
     */
    /* Lookup_n-D: '<S267>/Sine' incorporates:
     *  Delay: '<S208>/Delay1'
     *  Lookup_n-D: '<S267>/Cosine'
     */
    rtb_Sine_tmp = plook_u32f_evencka(rtDW.Delay1, 0.0F, 0.00153435534F, 4095U);
    rtb_Sine = rtConstP.pooled33[rtb_Sine_tmp];

    /* Lookup_n-D: '<S267>/Cosine' */
    rtb_Cosine = rtConstP.pooled31[rtb_Sine_tmp];

    /* Merge: '<S212>/Merge' incorporates:
     *  Constant: '<S259>/Constant'
     *  Constant: '<S259>/Constant2'
     *  Fcn: '<S259>/1'
     */
    rtDW.Merge_i = 0.0F * rtb_Cosine - 0.0F * rtb_Sine;

    /* Merge: '<S212>/Merge1' incorporates:
     *  Constant: '<S259>/Constant'
     *  Constant: '<S259>/Constant2'
     *  Fcn: '<S259>/2'
     */
    rtDW.Merge1_mx = 0.0F * rtb_Sine + 0.0F * rtb_Cosine;

    /* If: '<S259>/If1' */
    if (rtb_Abs >= rtb_Abs1) {
      /* Outputs for IfAction SubSystem: '<S259>/Subsystem' incorporates:
       *  ActionPort: '<S268>/Action Port'
       */
      /* Merge: '<S259>/Merge1' incorporates:
       *  Inport: '<S268>/In1'
       */
      rtDW.Merge1_o = rtDW.Delay1;

      /* End of Outputs for SubSystem: '<S259>/Subsystem' */
    } else {
      if (rtb_Abs < rtb_Abs1) {
        /* Outputs for IfAction SubSystem: '<S259>/Subsystem1' incorporates:
         *  ActionPort: '<S269>/Action Port'
         */
        /* If: '<S270>/If1' incorporates:
         *  Constant: '<S270>/Angle_offset'
         *  Sum: '<S270>/Subtract1'
         */
        if (rtDW.Delay1 + 3.14159274F > 6.28318548F) {
          /* Outputs for IfAction SubSystem: '<S270>/If Action Subsystem2' incorporates:
           *  ActionPort: '<S272>/Action Port'
           */
          IfActionSubsystem2(rtDW.Delay1 + 3.14159274F, &rtDW.Merge1_o);

          /* End of Outputs for SubSystem: '<S270>/If Action Subsystem2' */
        } else {
          /* Outputs for IfAction SubSystem: '<S270>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S271>/Action Port'
           */
          /* Merge: '<S259>/Merge1' incorporates:
           *  Inport: '<S271>/In1'
           */
          rtDW.Merge1_o = rtDW.Delay1 + 3.14159274F;

          /* End of Outputs for SubSystem: '<S270>/If Action Subsystem1' */
        }

        /* End of If: '<S270>/If1' */
        /* End of Outputs for SubSystem: '<S259>/Subsystem1' */
      }
    }

    /* End of If: '<S259>/If1' */
    /* End of Outputs for SubSystem: '<S212>/Ud_inject_5' */
    break;
  }

  /* End of SwitchCase: '<S212>/Switch Case1' */

  /* DataTypeConversion: '<S212>/Data Type Conversion' */
  rtDW.DataTypeConversion = rtDW.Merge1_o;

  /* SignalConversion generated from: '<S212>/Ualpha' */
  rtDW.Merge_f = rtDW.Merge_i;

  /* SignalConversion generated from: '<S212>/Ubeta' */
  rtDW.Merge1_g = rtDW.Merge1_mx;

  /* SignalConversion generated from: '<S212>/IPD_Angle' */
  rtDW.Merge2_j = rtDW.Merge1_o;

  /* Update for Delay: '<S212>/Delay' */
  rtDW.Delay_DSTATE_hw = rtDW.Id_j;

  /* Update for Delay: '<S212>/Delay1' */
  rtDW.Delay1_DSTATE_l = rtDW.Id;
}

/* Output and update for atomic system: '<S216>/Angle_calibration' */
void Angle_calibration(void)
{
  /* If: '<S228>/If1' incorporates:
   *  Constant: '<S228>/Angle_offset'
   *  Sum: '<S228>/Subtract1'
   */
  if (rtDW.DataTypeConversion_m + -3.14159274F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S228>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S230>/Action Port'
     */
    IfActionSubsystem2_g(rtDW.DataTypeConversion_m + -3.14159274F,
                         &rtDW.Merge2_m);

    /* End of Outputs for SubSystem: '<S228>/If Action Subsystem2' */
  } else if (rtDW.DataTypeConversion_m + -3.14159274F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S228>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S231>/Action Port'
     */
    IfActionSubsystem3(rtDW.DataTypeConversion_m + -3.14159274F, &rtDW.Merge2_m);

    /* End of Outputs for SubSystem: '<S228>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S228>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S229>/Action Port'
     */
    /* Merge: '<S209>/Merge2' incorporates:
     *  Inport: '<S229>/In1'
     */
    rtDW.Merge2_m = rtDW.DataTypeConversion_m + -3.14159274F;

    /* End of Outputs for SubSystem: '<S228>/If Action Subsystem1' */
  }

  /* End of If: '<S228>/If1' */
}

/* Output and update for atomic system: '<S217>/Angle_calibration' */
void Angle_calibration_m(void)
{
  /* If: '<S232>/If1' incorporates:
   *  Constant: '<S232>/Angle_offset'
   *  Inport: '<S233>/In1'
   *  Sum: '<S232>/Subtract1'
   */
  if (rtDW.DataTypeConversion_m + 3.14159274F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S232>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S234>/Action Port'
     */
    IfActionSubsystem2_g(rtDW.DataTypeConversion_m + 3.14159274F, &rtDW.Merge2_m);

    /* End of Outputs for SubSystem: '<S232>/If Action Subsystem2' */
  } else if (rtDW.DataTypeConversion_m + 3.14159274F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S232>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S235>/Action Port'
     */
    IfActionSubsystem3(rtDW.DataTypeConversion_m + 3.14159274F, &rtDW.Merge2_m);

    /* End of Outputs for SubSystem: '<S232>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S232>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S233>/Action Port'
     */
    rtDW.Merge2_m = rtDW.DataTypeConversion_m + 3.14159274F;

    /* End of Outputs for SubSystem: '<S232>/If Action Subsystem1' */
  }

  /* End of If: '<S232>/If1' */
}

/* Output and update for atomic system: '<S209>/StartRUN_State_machine' */
void StartRUN_State_machine(void)
{
  if (rtDW.temporalCounter_i1_h < MAX_uint32_T) {
    rtDW.temporalCounter_i1_h++;
  }

  /* Chart: '<S209>/StartRUN_State_machine' */
  if (rtDW.is_active_c6_Motor_Control == 0U) {
    rtDW.is_active_c6_Motor_Control = 1U;
    rtDW.is_c6_Motor_Control = IN_NS_2_RUN;
    rtDW.temporalCounter_i1_h = 0U;
    rtDW.RUN_state = 1U;
    rtDW.NS_RUN_flag = 1.0;
  } else {
    switch (rtDW.is_c6_Motor_Control) {
     case IN_NS_2_RUN:
      rtDW.RUN_state = 1U;
      if ((rtDW.temporalCounter_i1_h >= (uint32_T)ceil(HFI.NS2RUN_Time / 0.0001
            - 1.0E-12)) && (rtDW.NS_RUN_flag == 1.0)) {
        rtDW.is_c6_Motor_Control = IN_Start_RUN;
        rtDW.temporalCounter_i1_h = 0U;
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
      if ((rtDW.temporalCounter_i1_h >= (uint32_T)ceil(HFI.Switch_Time / 0.0001
            - 1.0E-12)) && (rtDW.Switch_flag == 1.0)) {
        rtDW.is_c6_Motor_Control = IN_RUN;
        rtDW.RUN_state = 3U;
      }
      break;
    }
  }

  /* End of Chart: '<S209>/StartRUN_State_machine' */
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
    y = (real32_T)fmod(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > (real32_T)floor(u1))) {
      q = (real32_T)fabs(u0 / u1);
      yEq = !((real32_T)fabs(q - (real32_T)floor(q + 0.5F)) > FLT_EPSILON * q);
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

/* System initialize for action system: '<S190>/HFI_Function' */
void HFI_Function_Init(void)
{
  /* Start for SwitchCase: '<S208>/Switch Case1' */
  rtDW.SwitchCase1_ActiveSubsystem = -1;
}

/* Disable for action system: '<S190>/HFI_Function' */
void HFI_Function_Disable(void)
{
  /* Disable for SwitchCase: '<S208>/Switch Case1' */
  if (rtDW.SwitchCase1_ActiveSubsystem == 2) {
    /* Disable for DiscreteIntegrator: '<S220>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE_ai = rtDW.DiscreteTimeIntegrator_k;
  }

  rtDW.SwitchCase1_ActiveSubsystem = -1;

  /* End of Disable for SwitchCase: '<S208>/Switch Case1' */
}

/* Outputs for action system: '<S190>/HFI_Function' */
void HFI_Function(void)
{
  real32_T Kp5;
  real32_T rtb_Integrator_j;
  real32_T rtb_Produc3t;
  real32_T rtb_Product1_ij;
  real32_T rtb_Product1_jm;
  real32_T rtb_Product_l;
  real32_T rtb_Product_m;
  uint32_T rtb_Produc3t_tmp;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Delay: '<S208>/Delay' */
  rtDW.Delay = rtDW.Delay_DSTATE;

  /* Delay: '<S208>/Delay1' */
  rtDW.Delay1 = rtDW.Delay1_DSTATE;

  /* Chart: '<S208>/HFI_State_machine' */
  HFI_State_machine();

  /* SwitchCase: '<S208>/Switch Case1' incorporates:
   *  Delay: '<S208>/Delay2'
   *  Inport: '<S209>/IPD_angle'
   */
  rtPrevAction = rtDW.SwitchCase1_ActiveSubsystem;
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

  rtDW.SwitchCase1_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 2)) {
    /* Disable for DiscreteIntegrator: '<S220>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE_ai = rtDW.DiscreteTimeIntegrator_k;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S208>/IPD' incorporates:
     *  ActionPort: '<S211>/Action Port'
     */
    IPD();

    /* End of Outputs for SubSystem: '<S208>/IPD' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S208>/NS' incorporates:
     *  ActionPort: '<S212>/Action Port'
     */
    NS();

    /* End of Outputs for SubSystem: '<S208>/NS' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S208>/HFI' incorporates:
     *  ActionPort: '<S209>/Action Port'
     */
    /* DiscreteIntegrator: '<S238>/Integrator' incorporates:
     *  Constant: '<S218>/Constant3'
     */
    if (rtDW.Integrator_PrevResetState != 0) {
      rtDW.Integrator_DSTATE_p = 0.0F;
    }

    /* Saturate: '<S218>/Saturation' incorporates:
     *  Constant: '<S209>/Constant3'
     */
    if (HFI.LPF <= 2.22044605E-16F) {
      rtb_Product_l = 2.22044605E-16F;
    } else {
      rtb_Product_l = HFI.LPF;
    }

    /* End of Saturate: '<S218>/Saturation' */

    /* Gain: '<S218>/Hz->rad//s' */
    rtb_Integrator_j = 6.28318548F * rtb_Product_l;

    /* Product: '<S218>/Product' incorporates:
     *  DiscreteIntegrator: '<S238>/Integrator'
     *  Math: '<S218>/Math Function'
     */
    rtb_Product_m = rtb_Integrator_j * rtb_Integrator_j *
      rtDW.Integrator_DSTATE_p;

    /* DiscreteIntegrator: '<S239>/Integrator' incorporates:
     *  Constant: '<S218>/Constant2'
     */
    if (rtDW.Integrator_PrevResetState_n != 0) {
      rtDW.Integrator_DSTATE_n = 0.0F;
    }

    /* Product: '<S218>/Product1' incorporates:
     *  DiscreteIntegrator: '<S239>/Integrator'
     *  Gain: '<S218>/Gain'
     */
    rtb_Product1_jm = 1.414F * rtb_Integrator_j * rtDW.Integrator_DSTATE_n;

    /* DiscreteIntegrator: '<S226>/Integrator' incorporates:
     *  Constant: '<S215>/Constant3'
     */
    if (rtDW.Integrator_PrevResetState_p != 0) {
      rtDW.Integrator_DSTATE_f = 0.0F;
    }

    /* Saturate: '<S215>/Saturation' incorporates:
     *  Constant: '<S209>/Constant2'
     */
    if (HFI.HPF <= 2.22044605E-16F) {
      rtb_Product_l = 2.22044605E-16F;
    } else {
      rtb_Product_l = HFI.HPF;
    }

    /* End of Saturate: '<S215>/Saturation' */

    /* Gain: '<S215>/Hz->rad//s' */
    rtb_Integrator_j = 6.28318548F * rtb_Product_l;

    /* Product: '<S215>/Product' incorporates:
     *  DiscreteIntegrator: '<S226>/Integrator'
     *  Math: '<S215>/Math Function'
     */
    rtb_Product_l = rtb_Integrator_j * rtb_Integrator_j *
      rtDW.Integrator_DSTATE_f;

    /* DiscreteIntegrator: '<S227>/Integrator' incorporates:
     *  Constant: '<S215>/Constant2'
     */
    if (rtDW.Integrator_PrevResetState_h != 0) {
      rtDW.Integrator_DSTATE_e = 0.0F;
    }

    /* Product: '<S215>/Product1' incorporates:
     *  DiscreteIntegrator: '<S227>/Integrator'
     *  Gain: '<S215>/Gain'
     */
    rtb_Product1_ij = 1.414F * rtb_Integrator_j * rtDW.Integrator_DSTATE_e;

    /* Math: '<S209>/Math Function' incorporates:
     *  Constant: '<S209>/Constant1'
     *  DiscreteIntegrator: '<S209>/Discrete-Time Integrator1'
     */
    rtDW.DataTypeConversion_m = rt_modf_snf
      (rtDW.DiscreteTimeIntegrator1_DSTATE_j, 6.28318548F);

    /* Saturate: '<S244>/Saturation' */
    if (rtDW.DataTypeConversion_m > 6.28218508F) {
      rtb_Integrator_j = 6.28218508F;
    } else if (rtDW.DataTypeConversion_m < 0.002F) {
      rtb_Integrator_j = 0.002F;
    } else {
      rtb_Integrator_j = rtDW.DataTypeConversion_m;
    }

    /* End of Saturate: '<S244>/Saturation' */

    /* Lookup_n-D: '<S244>/Sine' incorporates:
     *  DiscreteTransferFcn: '<S209>/Low pass filter'
     *  Lookup_n-D: '<S244>/Cosine'
     */
    rtb_Produc3t_tmp = plook_u32f_evencka(rtb_Integrator_j, 0.0F, 0.00153435534F,
      4095U);

    /* Sum: '<S215>/Sum' incorporates:
     *  Lookup_n-D: '<S244>/Cosine'
     *  Lookup_n-D: '<S244>/Sine'
     *  Product: '<S223>/Produc3t'
     *  Product: '<S223>/Product4'
     *  Sum: '<S223>/Add2'
     */
    rtb_Produc3t = ((rtDW.Gain5 * rtConstP.pooled31[rtb_Produc3t_tmp] -
                     rtDW.Gain2_d * rtConstP.pooled33[rtb_Produc3t_tmp]) -
                    rtb_Product_l) - rtb_Product1_ij;

    /* Sum: '<S218>/Sum' incorporates:
     *  MultiPortSwitch: '<S215>/Multiport Switch'
     */
    rtb_Product1_ij = (rtb_Produc3t - rtb_Product_m) - rtb_Product1_jm;

    /* Saturate: '<S209>/Output limit' incorporates:
     *  MultiPortSwitch: '<S218>/Multiport Switch'
     */
    if (rtb_Product_m > 0.5F) {
      rtb_Product_l = 0.5F;
    } else if (rtb_Product_m < -0.5F) {
      rtb_Product_l = -0.5F;
    } else {
      rtb_Product_l = rtb_Product_m;
    }

    /* End of Saturate: '<S209>/Output limit' */

    /* DiscreteIntegrator: '<S243>/Integrator' incorporates:
     *  Constant: '<S219>/Constant2'
     */
    if (rtDW.Integrator_PrevResetState_j != 0) {
      rtDW.Integrator_DSTATE_d = 0.0F;
    }

    /* DiscreteIntegrator: '<S243>/Integrator' */
    rtb_Product_m = rtDW.Integrator_DSTATE_d;

    /* DiscreteIntegrator: '<S242>/Integrator' incorporates:
     *  Constant: '<S219>/Constant3'
     */
    if (rtDW.Integrator_PrevResetState_hd != 0) {
      rtDW.Integrator_DSTATE_dr = 0.0F;
    }

    /* Gain: '<S219>/Gain3' incorporates:
     *  DiscreteIntegrator: '<S242>/Integrator'
     */
    rtb_Integrator_j = 394784.188F * rtDW.Integrator_DSTATE_dr;

    /* Sum: '<S219>/Sum' incorporates:
     *  Constant: '<S209>/Const'
     *  DiscreteIntegrator: '<S209>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S243>/Integrator'
     *  DotProduct: '<S209>/Dot Product'
     *  Gain: '<S219>/Gain'
     *  Product: '<S209>/Product'
     */
    rtb_Product_l = (6.28318548F * HFI.Inj_HF *
                     rtDW.DiscreteTimeIntegrator_DSTATE_g * rtb_Product_l -
                     rtb_Integrator_j) - 888.442444F * rtDW.Integrator_DSTATE_d;

    /* DiscreteIntegrator: '<S220>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_k = rtDW.DiscreteTimeIntegrator_DSTATE_ai;

    /* Sum: '<S220>/Sum6' incorporates:
     *  Gain: '<S220>/Kp4'
     */
    rtb_Product1_jm = HFI.PI_Kp * rtb_Integrator_j +
      rtDW.DiscreteTimeIntegrator_k;

    /* Saturate: '<S220>/Saturation2' */
    if (rtb_Product1_jm > 628.318542F) {
      /* Saturate: '<S220>/Saturation2' */
      rtb_Product1_jm = 628.318542F;
    } else {
      if (rtb_Product1_jm < -628.318542F) {
        /* Saturate: '<S220>/Saturation2' */
        rtb_Product1_jm = -628.318542F;
      }
    }

    /* End of Saturate: '<S220>/Saturation2' */

    /* Gain: '<S220>/Kp5' */
    Kp5 = HFI.PI_Ki * rtb_Integrator_j;

    /* Chart: '<S209>/StartRUN_State_machine' */
    StartRUN_State_machine();
    rtDW.IPD_angle = rtDW.Delay2_DSTATE;

    /* If: '<S209>/If2' incorporates:
     *  Delay: '<S208>/Delay2'
     *  Inport: '<S209>/IPD_angle'
     */
    if (rtDW.RUN_state < 3) {
      /* Outputs for IfAction SubSystem: '<S209>/HFI_Angle1' incorporates:
       *  ActionPort: '<S214>/Action Port'
       */
      /* Sum: '<S214>/Subtract' */
      rtDW.Subtract_e = rtDW.DataTypeConversion_m - rtDW.IPD_angle;

      /* End of Outputs for SubSystem: '<S209>/HFI_Angle1' */
    }

    /* End of If: '<S209>/If2' */

    /* If: '<S209>/If1' incorporates:
     *  Inport: '<S213>/Theta'
     */
    if ((rtDW.Subtract_e > 1.4F) && (rtDW.Subtract_e < 4.0F)) {
      /* Outputs for IfAction SubSystem: '<S209>/IPD_Angle' incorporates:
       *  ActionPort: '<S216>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S216>/Angle_calibration' */
      Angle_calibration();

      /* End of Outputs for SubSystem: '<S216>/Angle_calibration' */
      /* End of Outputs for SubSystem: '<S209>/IPD_Angle' */
    } else if ((rtDW.Subtract_e < -1.4F) && (rtDW.Subtract_e > -4.0F)) {
      /* Outputs for IfAction SubSystem: '<S209>/IPD_Angle1' incorporates:
       *  ActionPort: '<S217>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S217>/Angle_calibration' */
      Angle_calibration_m();

      /* End of Outputs for SubSystem: '<S217>/Angle_calibration' */
      /* End of Outputs for SubSystem: '<S209>/IPD_Angle1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S209>/HFI_Angle' incorporates:
       *  ActionPort: '<S213>/Action Port'
       */
      rtDW.Merge2_m = rtDW.DataTypeConversion_m;

      /* End of Outputs for SubSystem: '<S209>/HFI_Angle' */
    }

    /* End of If: '<S209>/If1' */

    /* SignalConversion generated from: '<S209>/theta_est' */
    rtDW.Merge2_j = rtDW.Merge2_m;

    /* Product: '<S221>/Product1' incorporates:
     *  Constant: '<S221>/Const2'
     *  Delay: '<S221>/Delay'
     *  Memory: '<S221>/Memory'
     *  RelationalOperator: '<S221>/Relational Operator1'
     */
    rtb_Integrator_j = (real32_T)(rtDW.Delay_DSTATE_h < 6.28318548F) *
      rtDW.Memory_PreviousInput_j;

    /* DataTypeConversion: '<S209>/Data Type Conversion' incorporates:
     *  DiscreteTransferFcn: '<S209>/Low pass filter'
     *  Gain: '<S221>/A'
     *  Lookup_n-D: '<S221>/Sine'
     */
    rtDW.DataTypeConversion_m = HFI.Inj_HV *
      rtConstP.pooled33[plook_u32f_evencka(rtb_Integrator_j, 0.0F,
      0.00153435534F, 4095U)];

    /* Sum: '<S221>/Add' incorporates:
     *  Constant: '<S221>/Const1'
     */
    rtb_Integrator_j += 0.000628318521F * HFI.Inj_HF;

    /* Outport: '<Root>/HFI_Speed' incorporates:
     *  DiscreteTransferFcn: '<S209>/Low pass filter'
     *  Gain: '<S209>/freq <-- wm1'
     */
    rtY.HFI_Speed = 0.012487743F * rtDW.Lowpassfilter_states_n2 * 4.77464819F;

    /* Update for DiscreteIntegrator: '<S209>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE_g += 0.0001F * rtDW.DataTypeConversion_m;

    /* Update for DiscreteIntegrator: '<S238>/Integrator' incorporates:
     *  DiscreteIntegrator: '<S239>/Integrator'
     */
    rtDW.Integrator_DSTATE_p += 0.0001F * rtDW.Integrator_DSTATE_n;
    rtDW.Integrator_PrevResetState = 0;

    /* Update for DiscreteIntegrator: '<S239>/Integrator' */
    rtDW.Integrator_DSTATE_n += 0.0001F * rtb_Product1_ij;
    rtDW.Integrator_PrevResetState_n = 0;

    /* Update for DiscreteIntegrator: '<S226>/Integrator' incorporates:
     *  DiscreteIntegrator: '<S227>/Integrator'
     */
    rtDW.Integrator_DSTATE_f += 0.0001F * rtDW.Integrator_DSTATE_e;
    rtDW.Integrator_PrevResetState_p = 0;

    /* Update for DiscreteIntegrator: '<S227>/Integrator' */
    rtDW.Integrator_DSTATE_e += 0.0001F * rtb_Produc3t;
    rtDW.Integrator_PrevResetState_h = 0;

    /* Update for DiscreteIntegrator: '<S209>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTATE_j += 0.0001F * rtb_Product1_jm;

    /* Update for DiscreteIntegrator: '<S243>/Integrator' */
    rtDW.Integrator_DSTATE_d += 0.0001F * rtb_Product_l;
    rtDW.Integrator_PrevResetState_j = 0;

    /* Update for DiscreteIntegrator: '<S242>/Integrator' */
    rtDW.Integrator_DSTATE_dr += 0.0001F * rtb_Product_m;
    rtDW.Integrator_PrevResetState_hd = 0;

    /* Update for DiscreteIntegrator: '<S220>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE_ai += 0.0001F * Kp5;
    if (rtDW.DiscreteTimeIntegrator_DSTATE_ai >= 628.318542F) {
      rtDW.DiscreteTimeIntegrator_DSTATE_ai = 628.318542F;
    } else {
      if (rtDW.DiscreteTimeIntegrator_DSTATE_ai <= -628.318542F) {
        rtDW.DiscreteTimeIntegrator_DSTATE_ai = -628.318542F;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S220>/Discrete-Time Integrator' */

    /* Update for Delay: '<S221>/Delay' */
    rtDW.Delay_DSTATE_h = rtb_Integrator_j;

    /* Update for Memory: '<S221>/Memory' */
    rtDW.Memory_PreviousInput_j = rtb_Integrator_j;

    /* Update for DiscreteTransferFcn: '<S209>/Low pass filter' */
    rtDW.Lowpassfilter_states_n2 = rtb_Product1_jm - -0.987512231F *
      rtDW.Lowpassfilter_states_n2;

    /* End of Outputs for SubSystem: '<S208>/HFI' */
    break;
  }

  /* End of SwitchCase: '<S208>/Switch Case1' */
}

/* Update for action system: '<S190>/HFI_Function' */
void HFI_Function_Update(void)
{
  /* Update for Delay: '<S208>/Delay' */
  rtDW.Delay_DSTATE = rtDW.Add1;

  /* Update for Delay: '<S208>/Delay1' */
  rtDW.Delay1_DSTATE = rtDW.Gain1_e;

  /* Update for Delay: '<S208>/Delay2' */
  rtDW.Delay2_DSTATE = rtDW.DataTypeConversion;
}

/* System initialize for atomic system: '<S183>/HF_Observer' */
void HF_Observer_Init(void)
{
  /* Start for If: '<S190>/If1' */
  rtDW.If1_ActiveSubsystem_gn = -1;

  /* SystemInitialize for IfAction SubSystem: '<S190>/HFI_Function' */
  HFI_Function_Init();

  /* End of SystemInitialize for SubSystem: '<S190>/HFI_Function' */
}

/* Disable for atomic system: '<S183>/HF_Observer' */
void HF_Observer_Disable(void)
{
  /* Disable for If: '<S190>/If1' */
  if (rtDW.If1_ActiveSubsystem_gn == 0) {
    HFI_Function_Disable();
  }

  rtDW.If1_ActiveSubsystem_gn = -1;

  /* End of Disable for If: '<S190>/If1' */
}

/* Outputs for atomic system: '<S183>/HF_Observer' */
void HF_Observer(void)
{
  int8_T rtAction;
  int8_T rtPrevAction;

  /* If: '<S190>/If1' incorporates:
   *  Constant: '<S190>/HFI_Enalble'
   */
  rtPrevAction = rtDW.If1_ActiveSubsystem_gn;
  rtAction = -1;
  if (HFI.Func_Enable == 1) {
    rtAction = 0;
  }

  rtDW.If1_ActiveSubsystem_gn = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    HFI_Function_Disable();
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S190>/HFI_Function' incorporates:
     *  ActionPort: '<S208>/Action Port'
     */
    HFI_Function();

    /* End of Outputs for SubSystem: '<S190>/HFI_Function' */
  }

  /* End of If: '<S190>/If1' */
}

/* Update for atomic system: '<S183>/HF_Observer' */
void HF_Observer_Update(void)
{
  /* Update for If: '<S190>/If1' */
  if (rtDW.If1_ActiveSubsystem_gn == 0) {
    /* Update for IfAction SubSystem: '<S190>/HFI_Function' incorporates:
     *  ActionPort: '<S208>/Action Port'
     */
    HFI_Function_Update();

    /* End of Update for SubSystem: '<S190>/HFI_Function' */
  }

  /* End of Update for If: '<S190>/If1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
