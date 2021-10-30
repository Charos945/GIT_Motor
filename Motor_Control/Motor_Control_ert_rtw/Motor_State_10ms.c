/*
 * File: Motor_State_10ms.c
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

#include "Motor_State_10ms.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Output and update for function-call system: '<S2>/Motor_State_10ms' */
void Motor_State_10ms(real32_T rtu_Id, real32_T rtu_Vd, real32_T rtu_Iq,
                      real32_T rtu_Vq)
{
  /* DiscreteTransferFcn: '<S6>/Low pass filter' */
  rtDW.Lowpassfilter = 0.012487743F * rtDW.Lowpassfilter_states;

  /* DiscreteTransferFcn: '<S6>/Low pass filter1' */
  rtDW.Lowpassfilter1 = 0.012487743F * rtDW.Lowpassfilter1_states;

  /* Update for DiscreteTransferFcn: '<S6>/Low pass filter' incorporates:
   *  Product: '<S284>/Product'
   *  Product: '<S284>/Product1'
   *  Sum: '<S284>/Add'
   */
  rtDW.Lowpassfilter_states = (rtu_Id * rtu_Vd + rtu_Iq * rtu_Vq) -
    -0.987512231F * rtDW.Lowpassfilter_states;

  /* Update for DiscreteTransferFcn: '<S6>/Low pass filter1' incorporates:
   *  Constant: '<S285>/Constant2'
   *  Product: '<S285>/Product1'
   *  Product: '<S285>/Product2'
   *  Product: '<S285>/Product3'
   *  Product: '<S285>/Product4'
   *  Sum: '<S285>/Subtract'
   */
  rtDW.Lowpassfilter1_states = (-0.00019999966F * rtu_Id * rtu_Iq + 0.0260812F *
    rtu_Iq) * 3.0F - -0.987512231F * rtDW.Lowpassfilter1_states;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
