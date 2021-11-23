/*
 * File: Angle_Speed_100us.c
 *
 * Code generated for Simulink model 'FOC_Motor_Control'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Nov 22 17:45:55 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Angle_Speed_100us.h"

/* Include model header file for global data */
#include "FOC_Motor_Control.h"
#include "FOC_Motor_Control_private.h"

/* Output and update for trigger system: '<S7>/ACC_OMG' */
void ACC_OMG(void)
{
  real32_T rtb_Gain3_m;
  real32_T rtb_dt1;

  /* Outputs for Triggered SubSystem: '<S7>/ACC_OMG' incorporates:
   *  TriggerPort: '<S9>/function'
   */
  /* Inport: '<Root>/Hall' */
  if ((((rtU.Hall[0] > 0) != (rtPrevZCX.ACC_OMG_Trig_ZCE[0] == POS_ZCSIG)) &&
       (rtPrevZCX.ACC_OMG_Trig_ZCE[0] != UNINITIALIZED_ZCSIG)) || (((rtU.Hall[1]
         > 0) != (rtPrevZCX.ACC_OMG_Trig_ZCE[1] == POS_ZCSIG)) &&
       (rtPrevZCX.ACC_OMG_Trig_ZCE[1] != UNINITIALIZED_ZCSIG)) || (((rtU.Hall[2]
         > 0) != (rtPrevZCX.ACC_OMG_Trig_ZCE[2] == POS_ZCSIG)) &&
       (rtPrevZCX.ACC_OMG_Trig_ZCE[2] != UNINITIALIZED_ZCSIG))) {
    /* Inport: '<S9>/Timer_Counter' incorporates:
     *  Inport: '<Root>/Timer_counter'
     */
    rtDW.Timer_Counter = rtU.Timer_counter;

    /* Gain: '<S9>/Gain3' */
    rtb_Gain3_m = Hall_Parameter.HaLL_Timer_T * rtDW.Timer_Counter;

    /* Sum: '<S9>/Add2' incorporates:
     *  Memory: '<S9>/Memory'
     */
    rtb_dt1 = rtb_Gain3_m - rtDW.Memory_PreviousInput;

    /* Gain: '<S9>/Gain2' incorporates:
     *  Constant: '<S9>/Constant6'
     *  Product: '<S9>/Divide'
     */
    rtDW.Gain2 = 1.04719758F / rtb_dt1;

    /* Product: '<S9>/Divide1' incorporates:
     *  Memory: '<S9>/Memory1'
     *  Memory: '<S9>/Memory2'
     *  Sum: '<S9>/Add1'
     *  Sum: '<S9>/Add4'
     */
    rtDW.a = (rtDW.Gain2 - rtDW.Memory1_PreviousInput) /
      (rtDW.Memory2_PreviousInput + rtb_dt1);

    /* Sum: '<S11>/Add1' incorporates:
     *  Constant: '<S11>/Constant1'
     *  Gain: '<S9>/Gain1'
     *  Product: '<S11>/Divide1'
     *  Sum: '<S11>/Add'
     *  UnitDelay: '<S11>/Unit Delay'
     */
    Hall_Speed += (95.4929657F * rtDW.Gain2 - Hall_Speed) * SpeedFilter_Fn;

    /* Outputs for Atomic SubSystem: '<S9>/Six_point' */
    /* SwitchCase: '<S12>/Switch Case2' incorporates:
     *  ArithShift: '<S9>/Shift Arithmetic'
     *  ArithShift: '<S9>/Shift Arithmetic1'
     *  ArithShift: '<S9>/Shift Arithmetic2'
     *  Constant: '<S9>/Constant1'
     *  Constant: '<S9>/Constant2'
     *  Sum: '<S9>/Add'
     */
    switch ((uint8_T)((uint32_T)(uint8_T)((uint32_T)(uint8_T)(rtU.Hall[1] << 1U)
              + rtU.Hall[0]) + (uint8_T)(rtU.Hall[2] << 2U))) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S12>/Sector_1' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* Merge: '<S12>/Merge2' incorporates:
       *  Constant: '<S13>/Constant'
       *  Constant: '<S13>/Constant1'
       *  Sum: '<S13>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector1 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S12>/Sector_1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S12>/Sector_2' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* Merge: '<S12>/Merge2' incorporates:
       *  Constant: '<S14>/Constant1'
       *  Constant: '<S14>/Pi//3'
       *  Sum: '<S14>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector2 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S12>/Sector_2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S12>/Sector_3' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* Merge: '<S12>/Merge2' incorporates:
       *  Constant: '<S15>/Constant'
       *  Constant: '<S15>/Constant1'
       *  Sum: '<S15>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector3 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S12>/Sector_3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S12>/Sector_4' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      /* Merge: '<S12>/Merge2' incorporates:
       *  Constant: '<S16>/Constant'
       *  Constant: '<S16>/Constant1'
       *  Sum: '<S16>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector4 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S12>/Sector_4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S12>/Sector_5' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      /* Merge: '<S12>/Merge2' incorporates:
       *  Constant: '<S17>/Constant'
       *  Constant: '<S17>/Constant1'
       *  Sum: '<S17>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector5 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S12>/Sector_5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S12>/Sector_6' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* Merge: '<S12>/Merge2' incorporates:
       *  Constant: '<S18>/Constant'
       *  Constant: '<S18>/Constant1'
       *  Sum: '<S18>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector6 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S12>/Sector_6' */
      break;
    }

    /* End of SwitchCase: '<S12>/Switch Case2' */
    /* End of Outputs for SubSystem: '<S9>/Six_point' */

    /* Update for Memory: '<S9>/Memory' */
    rtDW.Memory_PreviousInput = rtb_Gain3_m;

    /* Update for Memory: '<S9>/Memory1' */
    rtDW.Memory1_PreviousInput = rtDW.Gain2;

    /* Update for Memory: '<S9>/Memory2' */
    rtDW.Memory2_PreviousInput = rtb_dt1;
  }

  rtPrevZCX.ACC_OMG_Trig_ZCE[0] = (ZCSigState)(rtU.Hall[0] > 0);
  rtPrevZCX.ACC_OMG_Trig_ZCE[1] = (ZCSigState)(rtU.Hall[1] > 0);
  rtPrevZCX.ACC_OMG_Trig_ZCE[2] = (ZCSigState)(rtU.Hall[2] > 0);

  /* End of Inport: '<Root>/Hall' */
  /* End of Outputs for SubSystem: '<S7>/ACC_OMG' */
}

/* Output and update for atomic system: '<S7>/ADC_IRQ' */
void ADC_IRQ(void)
{
  real32_T rtb_Add6;
  real32_T rtb_Gain3_g;

  /* Sum: '<S10>/Add6' incorporates:
   *  Inport: '<Root>/Timer_counter'
   */
  rtb_Add6 = rtU.Timer_counter - rtDW.Timer_Counter;

  /* Gain: '<S10>/Gain3' */
  rtb_Gain3_g = Hall_Parameter.HaLL_Timer_T * rtb_Add6;

  /* Sum: '<S19>/Subtract1' incorporates:
   *  Constant: '<S19>/Angle_offset'
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Gain4'
   *  Math: '<S10>/Math Function1'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/Product2'
   *  Sum: '<S10>/Add7'
   *  Sum: '<S10>/Minus2'
   *
   * About '<S10>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Add6 = ((rtb_Gain3_g * rtb_Gain3_g * rtDW.a * 0.5F + rtDW.Gain2 * rtb_Add6
               * Hall_Parameter.HaLL_Timer_T) + rtDW.Merge2) +
    Hall_Parameter.HaLL_AngleShift;

  /* If: '<S19>/If1' */
  if (rtb_Add6 > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    IfActionSubsystem2_k(rtb_Add6, &Hall_Angle);

    /* End of Outputs for SubSystem: '<S19>/If Action Subsystem2' */
  } else if (rtb_Add6 < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    IfActionSubsystem3(rtb_Add6, &Hall_Angle);

    /* End of Outputs for SubSystem: '<S19>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* Merge: '<S19>/Merge1' incorporates:
     *  Inport: '<S20>/In1'
     */
    Hall_Angle = rtb_Add6;

    /* End of Outputs for SubSystem: '<S19>/If Action Subsystem1' */
  }

  /* End of If: '<S19>/If1' */
}

/* Output and update for atomic system: '<S8>/Speed_cacl' */
void Speed_cacl(void)
{
  int32_T rtb_Wrap_To_Pi;

  /* Gain: '<S23>/Wrap_To_Pi' incorporates:
   *  DataTypeConversion: '<S23>/Difference_to_Single1'
   *  Gain: '<S23>/Scale_Input'
   *  Inport: '<Root>/Angle_Theta'
   */
  rtb_Wrap_To_Pi = (int32_T)floorf(1.70891312E+8F * rtU.Angle_Theta) << 2;

  /* Sum: '<S24>/Add1' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S23>/Constant1'
   *  Constant: '<S24>/Constant1'
   *  DataTypeConversion: '<S23>/Difference_to_Single'
   *  Delay: '<S23>/Position_Delay'
   *  Gain: '<S23>/Gain'
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product1'
   *  Product: '<S24>/Divide1'
   *  Sum: '<S23>/Difference_Wrap'
   *  Sum: '<S24>/Add'
   *  UnitDelay: '<S24>/Unit Delay'
   */
  rtDW.Add1 += ((real32_T)(rtb_Wrap_To_Pi - rtDW.Position_Delay_DSTATE) *
                1.46291804E-5F * 9.54929638F * 0.5F - rtDW.Add1) *
    SpeedFilter_Fn;

  /* Update for Delay: '<S23>/Position_Delay' */
  rtDW.Position_Delay_DSTATE = rtb_Wrap_To_Pi;
}

/* Output and update for action system: '<S3>/Speed_Resolver' */
void Speed_Resolver(void)
{
  /* DataTypeConversion: '<S8>/DT2' incorporates:
   *  Inport: '<Root>/Angle_Theta'
   */
  rtDW.Direct_Angle = rtU.Angle_Theta;

  /* Outputs for Atomic SubSystem: '<S8>/Speed_cacl' */
  Speed_cacl();

  /* End of Outputs for SubSystem: '<S8>/Speed_cacl' */
}

/* Output and update for function-call system: '<S2>/Angle_Speed_100us' */
void Angle_Speed_100us(void)
{
  /* Outputs for Triggered SubSystem: '<S7>/ACC_OMG' */
  ACC_OMG();

  /* End of Outputs for SubSystem: '<S7>/ACC_OMG' */

  /* Outputs for Atomic SubSystem: '<S7>/ADC_IRQ' */
  ADC_IRQ();

  /* End of Outputs for SubSystem: '<S7>/ADC_IRQ' */

  /* SwitchCase: '<S3>/Switch Case' incorporates:
   *  Constant: '<S2>/Select_Angle'
   */
  if (CTL_Parameter.Angle == 1) {
    /* Outputs for IfAction SubSystem: '<S3>/Speed_Resolver' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    Speed_Resolver();

    /* End of Outputs for SubSystem: '<S3>/Speed_Resolver' */
  }

  /* End of SwitchCase: '<S3>/Switch Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
