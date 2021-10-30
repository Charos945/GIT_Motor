/*
 * File: Angle_Speed_100us.c
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

#include "Angle_Speed_100us.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Output and update for atomic system: '<S7>/Speed_cacl' */
void Speed_cacl(void)
{
  int32_T rtb_Wrap_To_Pi;
  real32_T rtb_UnitDelay_h;

  /* Gain: '<S8>/Wrap_To_Pi' incorporates:
   *  DataTypeConversion: '<S8>/Difference_to_Single1'
   *  Gain: '<S8>/Scale_Input'
   *  Inport: '<Root>/Angle_Theta'
   */
  rtb_Wrap_To_Pi = (int32_T)floorf(1.70891312E+8F * rtU.Angle_Theta) << 2;

  /* UnitDelay: '<S9>/Unit Delay' */
  rtb_UnitDelay_h = rtDW.UnitDelay_DSTATE_f;

  /* Sum: '<S9>/Add1' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S9>/Constant1'
   *  DataTypeConversion: '<S8>/Difference_to_Single'
   *  Delay: '<S8>/Position_Delay'
   *  Gain: '<S8>/Gain'
   *  Outport: '<Root>/Speed_Measured'
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product1'
   *  Product: '<S9>/Divide1'
   *  Sum: '<S8>/Difference_Wrap'
   *  Sum: '<S9>/Add'
   */
  rtY.Speed_Measured = ((real32_T)(rtb_Wrap_To_Pi - rtDW.Position_Delay_DSTATE) *
                        2.92583609E-5F * 9.54929638F * 0.25F - rtb_UnitDelay_h) *
    SpeedFilter_Fn + rtb_UnitDelay_h;

  /* Update for Delay: '<S8>/Position_Delay' */
  rtDW.Position_Delay_DSTATE = rtb_Wrap_To_Pi;

  /* Update for UnitDelay: '<S9>/Unit Delay' incorporates:
   *  Outport: '<Root>/Speed_Measured'
   */
  rtDW.UnitDelay_DSTATE_f = rtY.Speed_Measured;
}

/* Output and update for atomic system: '<S3>/Speed_Resolver' */
void Speed_Resolver(void)
{
  /* DataTypeConversion: '<S7>/DT2' incorporates:
   *  Inport: '<Root>/Angle_Theta'
   */
  rtDW.Direct_Angle = rtU.Angle_Theta;

  /* Outputs for Atomic SubSystem: '<S7>/Speed_cacl' */
  Speed_cacl();

  /* End of Outputs for SubSystem: '<S7>/Speed_cacl' */
}

/* Output and update for function-call system: '<S2>/Angle_Speed_100us' */
void Angle_Speed_100us(void)
{
  /* Outputs for Atomic SubSystem: '<S3>/Speed_Resolver' */
  Speed_Resolver();

  /* End of Outputs for SubSystem: '<S3>/Speed_Resolver' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
