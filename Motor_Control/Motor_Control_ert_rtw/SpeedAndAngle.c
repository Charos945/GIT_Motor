/*
 * File: SpeedAndAngle.c
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

#include "SpeedAndAngle.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Named constants for Chart: '<S11>/Chart' */
#define IN_BLDC_RUN                    ((uint8_T)1U)
#define IN_BLDC_State                  ((uint8_T)2U)
#define IN_BLDC_Switch                 ((uint8_T)3U)

/* System initialize for trigger system: '<S11>/ACC_OMG' */
void ACC_OMG_Init(void)
{
  /* Start for If: '<S150>/If1' */
  rtDW.If1_ActiveSubsystem_n = -1;
}

/* Output and update for trigger system: '<S11>/ACC_OMG' */
void ACC_OMG(void)
{
  real_T tmp_1;
  int32_T i;
  int32_T tableOffset;
  real32_T DiscreteTimeIntegrator_j;
  real32_T rtb_Sum;
  real32_T tmp_0;
  uint32_T Speed_Control_ELAPS_T;
  uint16_T tmp;
  int8_T rtAction;

  /* Outputs for Triggered SubSystem: '<S11>/ACC_OMG' incorporates:
   *  TriggerPort: '<S143>/function'
   */
  /* Inport: '<Root>/Hall' */
//  if ((((rtU.Hall_ABC[0] > 0) != (rtPrevZCX.ACC_OMG_Trig_ZCE[0] == POS_ZCSIG)) &&
//       (rtPrevZCX.ACC_OMG_Trig_ZCE[0] != UNINITIALIZED_ZCSIG)) ||
//      (((rtU.Hall_ABC[1] > 0) != (rtPrevZCX.ACC_OMG_Trig_ZCE[1] == POS_ZCSIG)) &&
//       (rtPrevZCX.ACC_OMG_Trig_ZCE[1] != UNINITIALIZED_ZCSIG)) ||
//      (((rtU.Hall_ABC[2] > 0) != (rtPrevZCX.ACC_OMG_Trig_ZCE[2] == POS_ZCSIG)) &&
//       (rtPrevZCX.ACC_OMG_Trig_ZCE[2] != UNINITIALIZED_ZCSIG))) {
    /* Gain: '<S88>/Gain' */
    tmp = (uint16_T)((uint32_T)(uint16_T)((uint32_T)(uint16_T)(rtU.Hall_ABC[0] <<
      2) + (rtU.Hall_ABC[1] << 1)) + rtU.Hall_ABC[2]);

    /* LookupNDDirect: '<S151>/Direct Lookup Table (n-D)2' incorporates:
     *  Bias: '<S151>/Bias'
     *  DataTypeConversion: '<S151>/Data Type Conversion'
     *  Gain: '<S153>/Gain'
     *
     * About '<S151>/Direct Lookup Table (n-D)2':
     *  2-dimensional Direct Look-Up returning a Column,
     *  which is contiguous for column-major array
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    if ((real_T)tmp + -1.0 > 5.0) {
      tmp_1 = 5.0;
    } else if ((real_T)tmp + -1.0 < 0.0) {
      tmp_1 = 0.0;
    } else {
      tmp_1 = (real_T)tmp + -1.0;
    }

    tableOffset = (int32_T)tmp_1 * 6;
    for (i = 0; i < 6; i++) {
      /* LookupNDDirect: '<S151>/Direct Lookup Table (n-D)2'
       *
       * About '<S151>/Direct Lookup Table (n-D)2':
       *  2-dimensional Direct Look-Up returning a Column,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtDW.DirectLookupTablenD2[i] = rtConstP.pooled21[i + tableOffset];
    }

    /* Outputs for Atomic SubSystem: '<S143>/Six_point' */
    /* SwitchCase: '<S149>/Switch Case2' incorporates:
     *  ArithShift: '<S143>/Shift Arithmetic'
     *  ArithShift: '<S143>/Shift Arithmetic1'
     *  ArithShift: '<S143>/Shift Arithmetic2'
     *  Constant: '<S143>/Constant1'
     *  Constant: '<S143>/Constant2'
     *  Sum: '<S143>/Add'
     */
    switch ((uint8_T)((uint32_T)(uint8_T)((uint32_T)(uint8_T)(rtU.Hall_ABC[1] <<
               1U) + rtU.Hall_ABC[0]) + (uint8_T)(rtU.Hall_ABC[2] << 2U))) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S149>/Sector_1' incorporates:
       *  ActionPort: '<S154>/Action Port'
       */
      /* Merge: '<S149>/Merge2' incorporates:
       *  Constant: '<S154>/Constant'
       *  Constant: '<S154>/Constant1'
       *  Sum: '<S154>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.Sector_1 + Hall_Parameter.shift;

      /* End of Outputs for SubSystem: '<S149>/Sector_1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S149>/Sector_2' incorporates:
       *  ActionPort: '<S155>/Action Port'
       */
      /* Merge: '<S149>/Merge2' incorporates:
       *  Constant: '<S155>/Constant1'
       *  Constant: '<S155>/Pi//3'
       *  Sum: '<S155>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.Sector_2 + Hall_Parameter.shift;

      /* End of Outputs for SubSystem: '<S149>/Sector_2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S149>/Sector_3' incorporates:
       *  ActionPort: '<S156>/Action Port'
       */
      /* Merge: '<S149>/Merge2' incorporates:
       *  Constant: '<S156>/Constant'
       *  Constant: '<S156>/Constant1'
       *  Sum: '<S156>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.Sector_3 + Hall_Parameter.shift;

      /* End of Outputs for SubSystem: '<S149>/Sector_3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S149>/Sector_4' incorporates:
       *  ActionPort: '<S157>/Action Port'
       */
      /* Merge: '<S149>/Merge2' incorporates:
       *  Constant: '<S157>/Constant'
       *  Constant: '<S157>/Constant1'
       *  Sum: '<S157>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.Sector_4 + Hall_Parameter.shift;

      /* End of Outputs for SubSystem: '<S149>/Sector_4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S149>/Sector_5' incorporates:
       *  ActionPort: '<S158>/Action Port'
       */
      /* Merge: '<S149>/Merge2' incorporates:
       *  Constant: '<S158>/Constant'
       *  Constant: '<S158>/Constant1'
       *  Sum: '<S158>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.Sector_5 + Hall_Parameter.shift;

      /* End of Outputs for SubSystem: '<S149>/Sector_5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S149>/Sector_6' incorporates:
       *  ActionPort: '<S159>/Action Port'
       */
      /* Merge: '<S149>/Merge2' incorporates:
       *  Constant: '<S159>/Constant'
       *  Constant: '<S159>/Constant1'
       *  Sum: '<S159>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.Sector_6 + Hall_Parameter.shift;

      /* End of Outputs for SubSystem: '<S149>/Sector_6' */
      break;
    }

    /* End of SwitchCase: '<S149>/Switch Case2' */
    /* End of Outputs for SubSystem: '<S143>/Six_point' */

    /* Sum: '<S150>/Sum' incorporates:
     *  Constant: '<S148>/T3'
     *  DiscreteTransferFcn: '<S148>/Low pass filter'
     *  Gain: '<S150>/rad//s->rpm'
     */
    rtb_Sum = 1000.0F - 0.012487743F * rtDW.Lowpassfilter_states_n * 9.54929638F;

    /* If: '<S150>/If1' incorporates:
     *  Outport: '<Root>/BLDC_State'
     */
    rtAction = -1;
    if (rtY.BLDC_State == 3) {
      rtAction = 0;
      if (0 != rtDW.If1_ActiveSubsystem_n) {
        rtDW.Speed_Control_RESET_ELAPS_T = true;

        /* Enable for IfAction SubSystem: '<S150>/Speed_Control' incorporates:
         *  ActionPort: '<S152>/Action Port'
         */
        /* Enable for If: '<S150>/If1' incorporates:
         *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
         */
        rtDW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 1U;

        /* End of Enable for SubSystem: '<S150>/Speed_Control' */
      }

      /* Outputs for IfAction SubSystem: '<S150>/Speed_Control' incorporates:
       *  ActionPort: '<S152>/Action Port'
       */
      if (rtDW.Speed_Control_RESET_ELAPS_T) {
        Speed_Control_ELAPS_T = 0U;
      } else {
        Speed_Control_ELAPS_T = rtM->Timing.clockTick0 -
          rtDW.Speed_Control_PREV_T;
      }

      rtDW.Speed_Control_PREV_T = rtM->Timing.clockTick0;
      rtDW.Speed_Control_RESET_ELAPS_T = false;

      /* Switch: '<S152>/Switch' incorporates:
       *  Constant: '<S152>/Cons'
       *  UnitDelay: '<S152>/Unit Delay3'
       */
      if (rtDW.UnitDelay3_DSTATE_k) {
        tmp_0 = rtb_Sum;
      } else {
        tmp_0 = 0.0F;
      }

      /* End of Switch: '<S152>/Switch' */

      /* DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
      if (rtDW.DiscreteTimeIntegrator_SYSTEM_ENABLE != 0) {
        /* DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
        DiscreteTimeIntegrator_j = rtDW.DiscreteTimeIntegrator_DSTATE_n;
      } else {
        /* DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
        DiscreteTimeIntegrator_j = 0.0001F * (real32_T)Speed_Control_ELAPS_T
          * rtDW.DiscreteTimeIntegrator_PREV_U +
          rtDW.DiscreteTimeIntegrator_DSTATE_n;
      }

      /* End of DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */

      /* Sum: '<S152>/Add' incorporates:
       *  Constant: '<S152>/Kp'
       *  Product: '<S152>/Product'
       */
      rtb_Sum = 0.7476F * rtb_Sum + DiscreteTimeIntegrator_j;

      /* Saturate: '<S152>/Saturation' */
      if (rtb_Sum > 4200.0F) {
        /* Saturate: '<S152>/Saturation' */
        rtDW.Saturation = 4200.0F;
      } else if (rtb_Sum < 0.0F) {
        /* Saturate: '<S152>/Saturation' */
        rtDW.Saturation = 0.0F;
      } else {
        /* Saturate: '<S152>/Saturation' */
        rtDW.Saturation = rtb_Sum;
      }

      /* End of Saturate: '<S152>/Saturation' */

      /* Update for UnitDelay: '<S152>/Unit Delay3' incorporates:
       *  RelationalOperator: '<S152>/Relational Operator1'
       */
      rtDW.UnitDelay3_DSTATE_k = (rtb_Sum == rtDW.Saturation);

      /* Update for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S152>/Ki'
       *  Product: '<S152>/Product1'
       */
      rtDW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 0U;
      rtDW.DiscreteTimeIntegrator_DSTATE_n = DiscreteTimeIntegrator_j;
      rtDW.DiscreteTimeIntegrator_PREV_U = 17.72F * tmp_0;

      /* End of Outputs for SubSystem: '<S150>/Speed_Control' */
    }

    rtDW.If1_ActiveSubsystem_n = rtAction;

    /* End of If: '<S150>/If1' */

    /* Inport: '<S143>/Timer_Counter' incorporates:
     *  Inport: '<Root>/Timer_counter'
     */
    rtDW.Timer_Counter = rtU.Timer_Cnt;

    /* Gain: '<S143>/Gain3' */
    rtb_Sum = Hall_Parameter.Timer_frequency * rtDW.Timer_Counter;

    /* Sum: '<S143>/Add2' incorporates:
     *  Memory: '<S143>/Memory'
     */
    DiscreteTimeIntegrator_j = rtb_Sum - rtDW.Memory_PreviousInput;

    /* Gain: '<S143>/Gain2' incorporates:
     *  Constant: '<S143>/Constant6'
     *  Product: '<S143>/Divide'
     */
    rtDW.Gain2 = 1.04719758F / DiscreteTimeIntegrator_j;

    /* Product: '<S143>/Divide1' incorporates:
     *  Memory: '<S143>/Memory1'
     *  Memory: '<S143>/Memory2'
     *  Sum: '<S143>/Add1'
     *  Sum: '<S143>/Add4'
     */
    rtDW.a = (rtDW.Gain2 - rtDW.Memory1_PreviousInput) /
      (rtDW.Memory2_PreviousInput + DiscreteTimeIntegrator_j);

    /* Outport: '<Root>/Hall_Speed' incorporates:
     *  Gain: '<S143>/Gain1'
     */
    rtY.Hall_Speed = 9.54929638F * rtDW.Gain2;

    /* Update for DiscreteTransferFcn: '<S148>/Low pass filter' */
    rtDW.Lowpassfilter_states_n = rtDW.Gain2 - -0.987512231F *
      rtDW.Lowpassfilter_states_n;

    /* Update for If: '<S150>/If1' */
    if (rtDW.If1_ActiveSubsystem_n == 0) {
      /* Update for IfAction SubSystem: '<S150>/Speed_Control' incorporates:
       *  ActionPort: '<S152>/Action Port'
       */
      rtDW.Speed_Control_PREV_T = rtM->Timing.clockTick0;
      rtDW.Speed_Control_RESET_ELAPS_T = false;

      /* End of Update for SubSystem: '<S150>/Speed_Control' */
    }

    /* End of Update for If: '<S150>/If1' */

    /* Update for Memory: '<S143>/Memory' */
    rtDW.Memory_PreviousInput = rtb_Sum;

    /* Update for Memory: '<S143>/Memory1' */
    rtDW.Memory1_PreviousInput = rtDW.Gain2;

    /* Update for Memory: '<S143>/Memory2' */
    rtDW.Memory2_PreviousInput = DiscreteTimeIntegrator_j;
 // }

  rtPrevZCX.ACC_OMG_Trig_ZCE[0] = (ZCSigState)(rtU.Hall_ABC[0] > 0);
  rtPrevZCX.ACC_OMG_Trig_ZCE[1] = (ZCSigState)(rtU.Hall_ABC[1] > 0);
  rtPrevZCX.ACC_OMG_Trig_ZCE[2] = (ZCSigState)(rtU.Hall_ABC[2] > 0);

  /* End of Inport: '<Root>/Hall' */
  /* End of Outputs for SubSystem: '<S11>/ACC_OMG' */
}

/* Output and update for atomic system: '<S11>/ADC_IRQ' */
void ADC_IRQ(void)
{
  real32_T rtb_Add6;
  real32_T rtb_Gain3_p;

  /* Sum: '<S144>/Add6' incorporates:
   *  Inport: '<Root>/Timer_counter'
   */
  rtb_Add6 = rtU.Timer_Cnt - rtDW.Timer_Counter;

  /* Gain: '<S144>/Gain3' */
  rtb_Gain3_p = Hall_Parameter.Timer_frequency * rtb_Add6;

  /* Sum: '<S160>/Subtract1' incorporates:
   *  Constant: '<S160>/Angle_offset'
   *  Gain: '<S144>/Gain2'
   *  Gain: '<S144>/Gain4'
   *  Math: '<S144>/Math Function1'
   *  Product: '<S144>/Product1'
   *  Product: '<S144>/Product2'
   *  Sum: '<S144>/Add7'
   *  Sum: '<S144>/Minus2'
   *
   * About '<S144>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Add6 = ((rtb_Gain3_p * rtb_Gain3_p * rtDW.a * 0.5F + rtDW.Gain2 * rtb_Add6
               * Hall_Parameter.Timer_frequency) + rtDW.Merge2) +
    Hall_Parameter.shift;

  /* If: '<S160>/If1' */
  if (rtb_Add6 > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S162>/Action Port'
     */
    IfActionSubsystem2_g(rtb_Add6, &rtDW.Merge1_c);

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem2' */
  } else if (rtb_Add6 < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S163>/Action Port'
     */
    IfActionSubsystem3(rtb_Add6, &rtDW.Merge1_c);

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S161>/Action Port'
     */
    /* Merge: '<S160>/Merge1' incorporates:
     *  Inport: '<S161>/In1'
     */
    rtDW.Merge1_c = rtb_Add6;

    /* End of Outputs for SubSystem: '<S160>/If Action Subsystem1' */
  }

  /* End of If: '<S160>/If1' */
}

/* System initialize for action system: '<S3>/SpeedAndAngle' */
void SpeedAndAngle_Init(void)
{
  /* SystemInitialize for Triggered SubSystem: '<S11>/ACC_OMG' */
  ACC_OMG_Init();

  /* End of SystemInitialize for SubSystem: '<S11>/ACC_OMG' */
}

/* Output and update for action system: '<S3>/SpeedAndAngle' */
void SpeedAndAngle(void)
{
  real_T tmp_0;
  int32_T i;
  int32_T i_0;
  uint16_T tmp;
  boolean_T sf_internal_predicateOutput;

  /* Chart: '<S11>/Chart' incorporates:
   *  Outport: '<Root>/BLDC_State'
   */
  if (rtDW.temporalCounter_i1_i < MAX_uint32_T) {
    rtDW.temporalCounter_i1_i++;
  }

  if (rtDW.is_active_c3_Motor_Control == 0U) {
    rtDW.is_active_c3_Motor_Control = 1U;
    rtDW.is_c3_Motor_Control = IN_BLDC_State;
    rtDW.temporalCounter_i1_i = 0U;
    rtY.BLDC_State = 1U;
  } else {
    switch (rtDW.is_c3_Motor_Control) {
     case IN_BLDC_RUN:
      if (rtDW.temporalCounter_i1_i >= (uint32_T)ceil
          (Hall_Parameter.BLDC_Start_Time / 0.0001 - 1.0E-12)) {
        sf_internal_predicateOutput = (rtY.BLDC_State == 2);
      } else {
        sf_internal_predicateOutput = false;
      }

      if (sf_internal_predicateOutput) {
        rtDW.is_c3_Motor_Control = IN_BLDC_Switch;
        rtY.BLDC_State = 3U;
      } else {
        rtY.BLDC_State = 2U;
      }
      break;

     case IN_BLDC_State:
      if (rtDW.temporalCounter_i1_i >= (uint32_T)ceil
          (Hall_Parameter.BLDC_Start_Time / 0.0001 - 1.0E-12)) {
        sf_internal_predicateOutput = (rtY.BLDC_State == 1);
      } else {
        sf_internal_predicateOutput = false;
      }

      if (sf_internal_predicateOutput) {
        rtDW.is_c3_Motor_Control = IN_BLDC_RUN;
        rtDW.temporalCounter_i1_i = 0U;
        rtY.BLDC_State = 2U;
      } else {
        rtY.BLDC_State = 1U;
      }
      break;

     default:
      /* case IN_BLDC_Switch: */
      rtY.BLDC_State = 3U;
      break;
    }
  }

  /* End of Chart: '<S11>/Chart' */

  /* Outputs for Triggered SubSystem: '<S11>/ACC_OMG' */
 // ACC_OMG();

  /* End of Outputs for SubSystem: '<S11>/ACC_OMG' */

  /* If: '<S146>/If1' incorporates:
   *  Outport: '<Root>/BLDC_State'
   */
  if (rtY.BLDC_State == 1) {
    /* Outputs for IfAction SubSystem: '<S146>/Subsystem' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    for (i_0 = 0; i_0 < 6; i_0++) {
      /* Merge: '<S146>/Merge' incorporates:
       *  LookupNDDirect: '<S166>/Direct Lookup Table (n-D)2'
       *
       * About '<S166>/Direct Lookup Table (n-D)2':
       *  2-dimensional Direct Look-Up returning a Column,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      rtDW.Merge_p[i_0] = rtConstP.pooled21[i_0 + 6];
    }

    /* Merge: '<S146>/Merge1' incorporates:
     *  Constant: '<S164>/Duty'
     */
    rtDW.Merge1_n2 = Hall_Parameter.Start_duty * 4200.0F;

    /* End of Outputs for SubSystem: '<S146>/Subsystem' */
  } else {
    if (rtY.BLDC_State == 2) {
      /* Outputs for IfAction SubSystem: '<S146>/Subsystem1' incorporates:
       *  ActionPort: '<S165>/Action Port'
       */
      /* Gain: '<S168>/Gain' incorporates:
       *  Inport: '<Root>/Hall'
       */
      tmp = (uint16_T)((uint32_T)(uint16_T)((uint32_T)(uint16_T)(rtU.Hall_ABC[0]
        << 2) + (rtU.Hall_ABC[1] << 1)) + rtU.Hall_ABC[2]);

      /* LookupNDDirect: '<S167>/Direct Lookup Table (n-D)2' incorporates:
       *  Bias: '<S167>/Bias'
       *  DataTypeConversion: '<S167>/Data Type Conversion'
       *  Gain: '<S168>/Gain'
       *
       * About '<S167>/Direct Lookup Table (n-D)2':
       *  2-dimensional Direct Look-Up returning a Column,
       *  which is contiguous for column-major array
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      if ((real_T)tmp + -1.0 > 5.0) {
        tmp_0 = 5.0;
      } else if ((real_T)tmp + -1.0 < 0.0) {
        tmp_0 = 0.0;
      } else {
        tmp_0 = (real_T)tmp + -1.0;
      }

      i = (int32_T)tmp_0 * 6;
      for (i_0 = 0; i_0 < 6; i_0++) {
        /* Merge: '<S146>/Merge' incorporates:
         *  LookupNDDirect: '<S167>/Direct Lookup Table (n-D)2'
         *
         * About '<S167>/Direct Lookup Table (n-D)2':
         *  2-dimensional Direct Look-Up returning a Column,
         *  which is contiguous for column-major array
         *     Remove protection against out-of-range input in generated code: 'off'
         */
        rtDW.Merge_p[i_0] = rtConstP.pooled21[i_0 + i];
      }

      /* Merge: '<S146>/Merge1' incorporates:
       *  Constant: '<S165>/Duty'
       */
      rtDW.Merge1_n2 = Hall_Parameter.Start_duty * 4200.0F;

      /* End of Outputs for SubSystem: '<S146>/Subsystem1' */
    }
  }

  /* End of If: '<S146>/If1' */

  /* If: '<S147>/If1' incorporates:
   *  Outport: '<Root>/BLDC_State'
   */
  if ((rtY.BLDC_State == 1) || (rtY.BLDC_State == 2)) {
    /* Outputs for IfAction SubSystem: '<S147>/Subsystem' incorporates:
     *  ActionPort: '<S169>/Action Port'
     */
    for (i = 0; i < 6; i++) {
      /* Merge: '<S147>/Merge' incorporates:
       *  Inport: '<S169>/In1'
       */
      rtDW.Merge_gx[i] = rtDW.Merge_p[i];
    }

    /* Merge: '<S147>/Merge1' incorporates:
     *  Inport: '<S169>/In2'
     */
    rtDW.Merge1_e = rtDW.Merge1_n2;

    /* End of Outputs for SubSystem: '<S147>/Subsystem' */
  } else {
    if (rtY.BLDC_State == 3) {
      /* Outputs for IfAction SubSystem: '<S147>/Subsystem1' incorporates:
       *  ActionPort: '<S170>/Action Port'
       */
      for (i = 0; i < 6; i++) {
        /* Merge: '<S147>/Merge' incorporates:
         *  Inport: '<S170>/In1'
         */
        rtDW.Merge_gx[i] = rtDW.DirectLookupTablenD2[i];
      }

      /* Merge: '<S147>/Merge1' incorporates:
       *  Inport: '<S170>/In2'
       */
      rtDW.Merge1_e = rtDW.Saturation;

      /* End of Outputs for SubSystem: '<S147>/Subsystem1' */
    }
  }

  /* End of If: '<S147>/If1' */

  /* Outputs for Atomic SubSystem: '<S11>/ADC_IRQ' */
 // ADC_IRQ();

  /* End of Outputs for SubSystem: '<S11>/ADC_IRQ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
