/*
 * File: Angle_Speed_100us.c
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

#include "Angle_Speed_100us.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Output and update for trigger system: '<S8>/ACC_OMG' */
void ACC_OMG(void)
{
  real32_T rtb_Gain3_m;
  real32_T rtb_dt1;

  /* Outputs for Triggered SubSystem: '<S8>/ACC_OMG' incorporates:
   *  TriggerPort: '<S64>/function'
   */
  /* Inport: '<Root>/Hall' */
  if ((((rtU.Hall[0] > 0) != (rtPrevZCX.ACC_OMG_Trig_ZCE[0] == POS_ZCSIG)) &&
       (rtPrevZCX.ACC_OMG_Trig_ZCE[0] != UNINITIALIZED_ZCSIG)) || (((rtU.Hall[1]
         > 0) != (rtPrevZCX.ACC_OMG_Trig_ZCE[1] == POS_ZCSIG)) &&
       (rtPrevZCX.ACC_OMG_Trig_ZCE[1] != UNINITIALIZED_ZCSIG)) || (((rtU.Hall[2]
         > 0) != (rtPrevZCX.ACC_OMG_Trig_ZCE[2] == POS_ZCSIG)) &&
       (rtPrevZCX.ACC_OMG_Trig_ZCE[2] != UNINITIALIZED_ZCSIG))) {
    /* Inport: '<S64>/Timer_Counter' incorporates:
     *  Inport: '<Root>/Timer_counter'
     */
    rtDW.Timer_Counter = rtU.Timer_counter;

    /* Gain: '<S64>/Gain3' */
    rtb_Gain3_m = Hall_Parameter.HaLL_Timer_T * rtDW.Timer_Counter;

    /* Sum: '<S64>/Add2' incorporates:
     *  Memory: '<S64>/Memory'
     */
    rtb_dt1 = rtb_Gain3_m - rtDW.Memory_PreviousInput;

    /* Gain: '<S64>/Gain2' incorporates:
     *  Constant: '<S64>/Constant6'
     *  Product: '<S64>/Divide'
     */
    rtDW.Gain2 = 1.04719758F / rtb_dt1;

    /* Product: '<S64>/Divide1' incorporates:
     *  Memory: '<S64>/Memory1'
     *  Memory: '<S64>/Memory2'
     *  Sum: '<S64>/Add1'
     *  Sum: '<S64>/Add4'
     */
    rtDW.a = (rtDW.Gain2 - rtDW.Memory1_PreviousInput) /
      (rtDW.Memory2_PreviousInput + rtb_dt1);

    /* Sum: '<S66>/Add1' incorporates:
     *  Constant: '<S66>/Constant1'
     *  Gain: '<S64>/Gain1'
     *  Product: '<S66>/Divide1'
     *  Sum: '<S66>/Add'
     *  UnitDelay: '<S66>/Unit Delay'
     */
    Hall_Speed += (95.4929657F * rtDW.Gain2 - Hall_Speed) * SpeedFilter_Fn;

    /* Outputs for Atomic SubSystem: '<S64>/Six_point' */
    /* SwitchCase: '<S67>/Switch Case2' incorporates:
     *  ArithShift: '<S64>/Shift Arithmetic'
     *  ArithShift: '<S64>/Shift Arithmetic1'
     *  ArithShift: '<S64>/Shift Arithmetic2'
     *  Constant: '<S64>/Constant1'
     *  Constant: '<S64>/Constant2'
     *  Sum: '<S64>/Add'
     */
    switch ((uint8_T)((uint32_T)(uint8_T)((uint32_T)(uint8_T)(rtU.Hall[1] << 1U)
              + rtU.Hall[0]) + (uint8_T)(rtU.Hall[2] << 2U))) {
     case 1:
      /* Outputs for IfAction SubSystem: '<S67>/Sector_1' incorporates:
       *  ActionPort: '<S68>/Action Port'
       */
      /* Merge: '<S67>/Merge2' incorporates:
       *  Constant: '<S68>/Constant'
       *  Constant: '<S68>/Constant1'
       *  Sum: '<S68>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector1 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S67>/Sector_1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S67>/Sector_2' incorporates:
       *  ActionPort: '<S69>/Action Port'
       */
      /* Merge: '<S67>/Merge2' incorporates:
       *  Constant: '<S69>/Constant1'
       *  Constant: '<S69>/Pi//3'
       *  Sum: '<S69>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector2 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S67>/Sector_2' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S67>/Sector_3' incorporates:
       *  ActionPort: '<S70>/Action Port'
       */
      /* Merge: '<S67>/Merge2' incorporates:
       *  Constant: '<S70>/Constant'
       *  Constant: '<S70>/Constant1'
       *  Sum: '<S70>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector3 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S67>/Sector_3' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S67>/Sector_4' incorporates:
       *  ActionPort: '<S71>/Action Port'
       */
      /* Merge: '<S67>/Merge2' incorporates:
       *  Constant: '<S71>/Constant'
       *  Constant: '<S71>/Constant1'
       *  Sum: '<S71>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector4 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S67>/Sector_4' */
      break;

     case 5:
      /* Outputs for IfAction SubSystem: '<S67>/Sector_5' incorporates:
       *  ActionPort: '<S72>/Action Port'
       */
      /* Merge: '<S67>/Merge2' incorporates:
       *  Constant: '<S72>/Constant'
       *  Constant: '<S72>/Constant1'
       *  Sum: '<S72>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector5 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S67>/Sector_5' */
      break;

     case 6:
      /* Outputs for IfAction SubSystem: '<S67>/Sector_6' incorporates:
       *  ActionPort: '<S73>/Action Port'
       */
      /* Merge: '<S67>/Merge2' incorporates:
       *  Constant: '<S73>/Constant'
       *  Constant: '<S73>/Constant1'
       *  Sum: '<S73>/Add'
       */
      rtDW.Merge2 = Hall_Parameter.HaLL_Sector6 + Hall_Parameter.HaLL_AngleShift;

      /* End of Outputs for SubSystem: '<S67>/Sector_6' */
      break;
    }

    /* End of SwitchCase: '<S67>/Switch Case2' */
    /* End of Outputs for SubSystem: '<S64>/Six_point' */

    /* Update for Memory: '<S64>/Memory' */
    rtDW.Memory_PreviousInput = rtb_Gain3_m;

    /* Update for Memory: '<S64>/Memory1' */
    rtDW.Memory1_PreviousInput = rtDW.Gain2;

    /* Update for Memory: '<S64>/Memory2' */
    rtDW.Memory2_PreviousInput = rtb_dt1;
  }

  rtPrevZCX.ACC_OMG_Trig_ZCE[0] = (ZCSigState)(rtU.Hall[0] > 0);
  rtPrevZCX.ACC_OMG_Trig_ZCE[1] = (ZCSigState)(rtU.Hall[1] > 0);
  rtPrevZCX.ACC_OMG_Trig_ZCE[2] = (ZCSigState)(rtU.Hall[2] > 0);

  /* End of Inport: '<Root>/Hall' */
  /* End of Outputs for SubSystem: '<S8>/ACC_OMG' */
}

/* Output and update for atomic system: '<S8>/ADC_IRQ' */
void ADC_IRQ(void)
{
  real32_T rtb_Add6;
  real32_T rtb_Gain3_g;

  /* Sum: '<S65>/Add6' incorporates:
   *  Inport: '<Root>/Timer_counter'
   */
  rtb_Add6 = rtU.Timer_counter - rtDW.Timer_Counter;

  /* Gain: '<S65>/Gain3' */
  rtb_Gain3_g = Hall_Parameter.HaLL_Timer_T * rtb_Add6;

  /* Sum: '<S74>/Subtract1' incorporates:
   *  Constant: '<S74>/Angle_offset'
   *  Gain: '<S65>/Gain2'
   *  Gain: '<S65>/Gain4'
   *  Math: '<S65>/Math Function1'
   *  Product: '<S65>/Product1'
   *  Product: '<S65>/Product2'
   *  Sum: '<S65>/Add7'
   *  Sum: '<S65>/Minus2'
   *
   * About '<S65>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Add6 = ((rtb_Gain3_g * rtb_Gain3_g * rtDW.a * 0.5F + rtDW.Gain2 * rtb_Add6
               * Hall_Parameter.HaLL_Timer_T) + rtDW.Merge2) +
    Hall_Parameter.HaLL_AngleShift;

  /* If: '<S74>/If1' incorporates:
   *  Inport: '<S75>/In1'
   */
  if (rtb_Add6 > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    /* Sum: '<S76>/Subtract1' incorporates:
     *  Constant: '<S76>/2pi'
     */
    rtDW.Merge1_i = rtb_Add6 - 6.28318548F;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem2' */
  } else if (rtb_Add6 < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    /* Sum: '<S77>/Subtract1' incorporates:
     *  Constant: '<S77>/Angle_offset'
     */
    rtDW.Merge1_i = rtb_Add6 + 6.28318548F;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    rtDW.Merge1_i = rtb_Add6;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem1' */
  }

  /* End of If: '<S74>/If1' */
}

/* Output and update for atomic system: '<S9>/Speed_cacl' */
void Speed_cacl(void)
{
  int32_T rtb_Wrap_To_Pi;

  /* Gain: '<S78>/Wrap_To_Pi' incorporates:
   *  DataTypeConversion: '<S78>/Difference_to_Single1'
   *  Gain: '<S78>/Scale_Input'
   *  Inport: '<Root>/Angle_Theta'
   */
  rtb_Wrap_To_Pi = (int32_T)floorf(1.70891312E+8F * rtU.Angle_Theta) << 2;

  /* Sum: '<S79>/Add1' incorporates:
   *  Constant: '<S78>/Constant'
   *  Constant: '<S78>/Constant1'
   *  Constant: '<S79>/Constant1'
   *  DataTypeConversion: '<S78>/Difference_to_Single'
   *  Delay: '<S78>/Position_Delay'
   *  Gain: '<S78>/Gain'
   *  Product: '<S78>/Product'
   *  Product: '<S78>/Product1'
   *  Product: '<S79>/Divide1'
   *  Sum: '<S78>/Difference_Wrap'
   *  Sum: '<S79>/Add'
   *  UnitDelay: '<S79>/Unit Delay'
   */
  rtDW.Add1 += ((real32_T)(rtb_Wrap_To_Pi - rtDW.Position_Delay_DSTATE) *
                1.46291804E-5F * 9.54929638F * 0.5F - rtDW.Add1) *
    SpeedFilter_Fn;

  /* Update for Delay: '<S78>/Position_Delay' */
  rtDW.Position_Delay_DSTATE = rtb_Wrap_To_Pi;
}

/* Output and update for action system: '<S3>/Speed_Resolver' */
void Speed_Resolver(void)
{
  /* Outputs for Atomic SubSystem: '<S9>/Speed_cacl' */
  Speed_cacl();

  /* End of Outputs for SubSystem: '<S9>/Speed_cacl' */

  /* Merge: '<S3>/Merge' incorporates:
   *  SignalConversion generated from: '<S9>/Speed_out'
   */
  rtDW.Merge = rtDW.Add1;

  /* Merge: '<S3>/Merge1' incorporates:
   *  DataTypeConversion: '<S9>/DT2'
   *  Inport: '<Root>/Angle_Theta'
   */
  rtDW.Merge1 = rtU.Angle_Theta;
}

/* Output and update for atomic system: '<S7>/Angle_calibration' */
void Angle_calibration(void)
{
  real32_T rtb_Subtract1_o;

  /* Sum: '<S10>/Subtract1' incorporates:
   *  Constant: '<S10>/Angle_offset'
   */
  rtb_Subtract1_o = rtDW.Angle_Theta + CTL_Parameter.Angle_offset;

  /* If: '<S10>/If1' */
  if (rtb_Subtract1_o > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    IfActionSubsystem2(rtb_Subtract1_o, &rtDW.Merge1_o);

    /* End of Outputs for SubSystem: '<S10>/If Action Subsystem2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* Merge: '<S10>/Merge1' incorporates:
     *  Inport: '<S12>/In1'
     */
    rtDW.Merge1_o = rtb_Subtract1_o;

    /* End of Outputs for SubSystem: '<S10>/If Action Subsystem1' */
  }

  /* End of If: '<S10>/If1' */
}

/* Output and update for action system: '<S3>/Resolver_Observer' */
void Resolver_Observer(void)
{
  /* Outputs for Atomic SubSystem: '<S7>/Resolver_Angle_cacl' */
  Resolver_Angle_cacl();

  /* End of Outputs for SubSystem: '<S7>/Resolver_Angle_cacl' */

  /* SignalConversion generated from: '<S7>/Obser_Speed' */
  rtDW.Merge = rtDW.LPF;

  /* Outputs for Atomic SubSystem: '<S7>/Angle_calibration' */
  Angle_calibration();

  /* End of Outputs for SubSystem: '<S7>/Angle_calibration' */

  /* SignalConversion generated from: '<S7>/Obser_Theta' */
  rtDW.Merge1 = rtDW.Merge1_o;
}

/* Output and update for function-call system: '<S2>/Angle_Speed_100us' */
void Angle_Speed_100us(void)
{
  /* Outputs for Triggered SubSystem: '<S8>/ACC_OMG' */
  ACC_OMG();

  /* End of Outputs for SubSystem: '<S8>/ACC_OMG' */

  /* Outputs for Atomic SubSystem: '<S8>/ADC_IRQ' */
  ADC_IRQ();

  /* End of Outputs for SubSystem: '<S8>/ADC_IRQ' */

  /* SwitchCase: '<S3>/Switch Case' incorporates:
   *  Constant: '<S2>/Select_Angle'
   */
  switch (CTL_Parameter.Angle) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S3>/Speed_Resolver' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    Speed_Resolver();

    /* End of Outputs for SubSystem: '<S3>/Speed_Resolver' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S3>/Resolver_Observer' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    Resolver_Observer();

    /* End of Outputs for SubSystem: '<S3>/Resolver_Observer' */
    break;
  }

  /* End of SwitchCase: '<S3>/Switch Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
