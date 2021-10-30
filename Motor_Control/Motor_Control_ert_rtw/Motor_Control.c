/*
 * File: Motor_Control.c
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

#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Exported block signals */
real32_T Speed_RPM;                    /* '<S81>/Gain' */
real32_T Angle_Theta;                  /* '<S81>/Math Function' */

/* Exported block parameters */
HFI_STRUCT HFI = {
  0U,
  0U,
  12.0F,
  1000.0F,
  12.0F,
  500.0F,
  0.1F,
  12.0F,
  0.05F,
  0.001F,
  0.01F,
  0.5F,
  0.1F,
  6283.18555F,
  100.0F,
  950.0F,
  1050.0F,
  100.0F,
  5000.0F
} ;                                    /* Variable: HFI
                                        * Referenced by:
                                        *   '<S180>/HFI_Enalble'
                                        *   '<S186>/HFI_AngleEnable'
                                        *   '<S190>/HFI_Enalble'
                                        *   '<S208>/HFI_State_machine'
                                        *   '<S208>/HFI_Enalble'
                                        *   '<S209>/StartRUN_State_machine'
                                        *   '<S209>/Const'
                                        *   '<S209>/Constant2'
                                        *   '<S209>/Constant3'
                                        *   '<S209>/HFI_Enalble'
                                        *   '<S211>/Constant'
                                        *   '<S212>/NS_State_machine'
                                        *   '<S212>/HFI_Enalble'
                                        *   '<S220>/Kp4'
                                        *   '<S220>/Kp5'
                                        *   '<S221>/Const1'
                                        *   '<S221>/A'
                                        *   '<S245>/Const1'
                                        *   '<S256>/Constant'
                                        *   '<S258>/Constant'
                                        */

CTRLPARAMS_STRUCT ctrlParamsPI = {
  0.5F,
  0.00267F,
  0.0633F,
  1.5F,
  -1.5F,
  20.0F,
  0.528F,
  0.08F,
  13.8564062F,
  -13.8564062F,
  0.8F,
  0.0576F,
  13.8564062F,
  -13.8564062F
} ;                                    /* Variable: ctrlParamsPI
                                        * Referenced by:
                                        *   '<S181>/Ki'
                                        *   '<S181>/Kp'
                                        *   '<S181>/Saturation'
                                        *   '<S182>/Ki'
                                        *   '<S182>/Kp'
                                        *   '<S182>/Saturation'
                                        *   '<S203>/Ki'
                                        *   '<S203>/Kp'
                                        *   '<S203>/Saturation'
                                        *   '<S273>/Ki'
                                        *   '<S273>/Kp'
                                        *   '<S273>/Saturation'
                                        */

Hall_STRUCT Hall_Parameter = {
  1U,
  1U,
  0U,
  0.0F,
  0.0F,
  -0.0F,
  0.4e-5F,
  0.0F,
  1.04719758F,
  2.09439516F,
  3.14159274F,
  4.18879032F,
  5.23598766F
} ;                                    /* Variable: Hall_Parameter
                                        * Referenced by:
                                        *   '<S3>/Hall_Enalble'
                                        *   '<S5>/Hall_Enalble'
                                        *   '<S11>/Chart'
                                        *   '<S12>/Hall_Angle_Enable'
                                        *   '<S178>/Hall_Enalble'
                                        *   '<S143>/Gain3'
                                        *   '<S144>/Gain2'
                                        *   '<S144>/Gain3'
                                        *   '<S160>/Angle_offset'
                                        *   '<S164>/Duty'
                                        *   '<S165>/Duty'
                                        *   '<S154>/Constant'
                                        *   '<S154>/Constant1'
                                        *   '<S155>/Constant1'
                                        *   '<S155>/Pi//3'
                                        *   '<S156>/Constant'
                                        *   '<S156>/Constant1'
                                        *   '<S157>/Constant'
                                        *   '<S157>/Constant1'
                                        *   '<S158>/Constant'
                                        *   '<S158>/Constant1'
                                        *   '<S159>/Constant'
                                        *   '<S159>/Constant1'
                                        */

SMOParam_STRUCT SMO = {
  0U,
  0U,
  0.99F,
  -4.99999123e-6F,
  0.0249999985F,
  12.0F,
  18.0F,
  0.5F,
  0.2F,
  9.0F,
  0.0F
} ;                                    /* Variable: SMO
                                        * Referenced by:
                                        *   '<S3>/SMO_Enalble'
                                        *   '<S135>/Angle_offset'
                                        *   '<S137>/Gain2'
                                        *   '<S137>/Gain3'
                                        *   '<S138>/Constant'
                                        *   '<S138>/Constant1'
                                        *   '<S138>/Constant2'
                                        *   '<S138>/Constant3'
                                        *   '<S138>/Constant4'
                                        *   '<S138>/Constant5'
                                        */

CLParam_STRUCT CL_Param = {
  1U,
  1000.0F,
  1.0F,
  0.5F,
  0.1985F,
  2.0F,
  1000.0F,
  -1000.0F
} ;                                    /* Variable: CL_Param
                                        * Referenced by:
                                        *   '<S2>/Control_Mode'
                                        *   '<S4>/IQ_Command'
                                        */

OPLParam_STRUCT OPL_Param = {
  0U,
  0U,
  800.0F,
  0.5F,
  0.1F,
  5.0F,
  0.16F,
  800.0F,
  -800.0F
} ;                                    /* Variable: OPL_Param
                                        * Referenced by:
                                        *   '<S3>/State_machine'
                                        *   '<S3>/Iq_Command'
                                        *   '<S3>/OPL_Angle_Enable'
                                        *   '<S3>/OPL_Enable'
                                        *   '<S12>/Sensorless_Enable'
                                        *   '<S14>/OPL_SpeedRPM'
                                        *   '<S176>/Constant1'
                                        *   '<S177>/Constant1'
                                        *   '<S177>/Constant2'
                                        *   '<S177>/Iq_Command'
                                        */

Fluxweak_STRUCT Flux_weak = {
  0U,
  -4.0F,
  0.0F,
  0.05F,
  0.8F,
  10.0F
} ;                                    /* Variable: Flux_weak
                                        * Referenced by:
                                        *   '<S183>/Constant1'
                                        *   '<S207>/Ki'
                                        *   '<S207>/Kp'
                                        *   '<S207>/Saturation'
                                        */

FluxObsever_STRUCT FluxObsever = {
  1U,
  0U,
  1000.0F,
  10.0F
} ;                                    /* Variable: FluxObsever
                                        * Referenced by:
                                        *   '<S3>/Flux_Obsever'
                                        *   '<S12>/Sensorless_Enable1'
                                        *   '<S20>/Constant'
                                        *   '<S20>/Gain'
                                        */

Resolver_STRUCT Resolver_Parameter = {
  1U,
  0U,
  1U,
  0U,
  0.0F,
  1.02F
} ;                                    /* Variable: Resolver_Parameter
                                        * Referenced by:
                                        *   '<S3>/Dir_Angle_Enable'
                                        *   '<S3>/PLL_Enable'
                                        *   '<S12>/Resolver_Enable'
                                        *   '<S12>/Resolver_PLL_Enable'
                                        *   '<S80>/Angle_offset'
                                        */

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void rate_scheduler(void);
uint32_T plook_u32f_evencka(real32_T u, real32_T bp0, real32_T bpSpace, uint32_T
  maxIndex)
{
  real32_T fbpIndex;
  uint32_T bpIndex;

  /* Prelookup - Index only
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0U;
  } else {
    fbpIndex = (u - bp0) * (1.0F / bpSpace);
    if (fbpIndex < maxIndex) {
      bpIndex = (uint32_T)fbpIndex;
    } else {
      bpIndex = maxIndex;
    }
  }

  return bpIndex;
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.002s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }

  (rtM->Timing.TaskCounters.TID[2])++;
  if ((rtM->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.01s, 0.0s] */
    rtM->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function */
void Motor_Control_step(void)
{
  int32_T i;

  /* Outputs for Atomic SubSystem: '<Root>/Motor_Control' */
  /* UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2 = rtDW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1 = rtDW.UnitDelay1_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay4' */
  rtDW.UnitDelay4 = rtDW.UnitDelay4_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay3' */
  rtDW.UnitDelay3 = rtDW.UnitDelay3_DSTATE;

  /* S-Function (fcgen): '<S2>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S2>/Angle_Speed_100us'
   */
  Angle_Speed_100us();

  /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator2' */

  /* UnitDelay: '<S2>/Unit Delay5' incorporates:
   *  Outport: '<Root>/RUN_State'
   */
  rtY.RUN_State = rtDW.UnitDelay5_DSTATE;
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (fcgen): '<S2>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S2>/Control_Command_2ms'
     */
    Control_Command_2ms();

    /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator1' */
  }

  /* S-Function (fcgen): '<S2>/Function-Call Generator' incorporates:
   *  SubSystem: '<S2>/FOC_Control_100us'
   */
  FOC_Control_100us();

  /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator' */

  /* Outport: '<Root>/Id' incorporates:
   *  UnitDelay: '<S2>/Unit Delay6'
   */
  rtY.Id = rtDW.UnitDelay6_DSTATE;

  /* Outport: '<Root>/Vd' incorporates:
   *  UnitDelay: '<S2>/Unit Delay8'
   */
  rtY.Vd = rtDW.UnitDelay8_DSTATE;

  /* Outport: '<Root>/Iq' incorporates:
   *  UnitDelay: '<S2>/Unit Delay7'
   */
  rtY.Iq = rtDW.UnitDelay7_DSTATE;

  /* Outport: '<Root>/Vq' incorporates:
   *  UnitDelay: '<S2>/Unit Delay9'
   */
  rtY.Vq = rtDW.UnitDelay9_DSTATE;
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (fcgen): '<S2>/Function-Call Generator3' incorporates:
     *  SubSystem: '<S2>/Motor_State_10ms'
     */
    /* Outport: '<Root>/Id' incorporates:
     *  Outport: '<Root>/Iq'
     *  Outport: '<Root>/Vd'
     *  Outport: '<Root>/Vq'
     */
    Motor_State_10ms(rtY.Id, rtY.Vd, rtY.Iq, rtY.Vq);

    /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator3' */
  }

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE = rtDW.Gain2_d;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtDW.Gain5;

  /* Update for UnitDelay: '<S2>/Unit Delay4' */
  rtDW.UnitDelay4_DSTATE = rtDW.Add1_l;

  /* Update for UnitDelay: '<S2>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE = rtDW.Add2_f;

  /* Update for UnitDelay: '<S2>/Unit Delay5' */
  rtDW.UnitDelay5_DSTATE = rtDW.RUN_state;

  /* Update for UnitDelay: '<S2>/Unit Delay6' */
  rtDW.UnitDelay6_DSTATE = rtDW.Add1;

  /* Update for UnitDelay: '<S2>/Unit Delay8' */
  rtDW.UnitDelay8_DSTATE = rtDW.Saturation_l;

  /* Update for UnitDelay: '<S2>/Unit Delay7' */
  rtDW.UnitDelay7_DSTATE = rtDW.Add2;

  /* Update for UnitDelay: '<S2>/Unit Delay9' */
  rtDW.UnitDelay9_DSTATE = rtDW.Saturation_b;

  /* End of Outputs for SubSystem: '<Root>/Motor_Control' */

  /* Outport: '<Root>/Duty' */
  rtY.Duty = rtDW.Merge1_e;

  /* Outport: '<Root>/Gate' */
  for (i = 0; i < 6; i++) {
    rtY.Gate[i] = rtDW.Merge_gx[i];
  }

  /* End of Outport: '<Root>/Gate' */

  /* Outport: '<Root>/HFI_Theta' */
  rtY.HFI_Theta = rtDW.Merge2_j;

  /* Outport: '<Root>/FOC_Theta' */
  rtY.FOC_Theta = rtDW.Merge1;

  /* Outport: '<Root>/Force_Theta' */
  rtY.Force_Theta = rtDW.Merge_g;

  /* Outport: '<Root>/Ubeta_Ealpha' */
  rtY.Ubeta_Ealpha[0] = rtDW.SFunctionBuilder_o4;
  rtY.Ubeta_Ealpha[1] = rtDW.Ubeta;

  /* Outport: '<Root>/Speed_Mes' */
  rtY.Speed_Mes = rtDW.Merge;

  /* Outport: '<Root>/SMO_Angle' */
  rtY.SMO_Angle = rtDW.Merge1_a;

  /* Outport: '<Root>/Hall_Angle' */
  rtY.Hall_Angle = rtDW.Merge1_c;
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Outport: '<Root>/Motor_Power' */
    rtY.Motor_Power = rtDW.Lowpassfilter;

    /* Outport: '<Root>/Motor_Torque' */
    rtY.Motor_Torque = rtDW.Lowpassfilter1;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick0++;
  rate_scheduler();
}

/* Model initialize function */
void Motor_Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    rtPrevZCX.ACC_OMG_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
    rtPrevZCX.ACC_OMG_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
    rtPrevZCX.ACC_OMG_Trig_ZCE[2] = UNINITIALIZED_ZCSIG;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Motor_Control' */
    /* SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator2' incorporates:
     *  SubSystem: '<S2>/Angle_Speed_100us'
     */
    Angle_Speed_100us_Init();

    /* End of SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator2' */

    /* SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S2>/Control_Command_2ms'
     */
    Control_Command_2ms_Init();

    /* End of SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator1' */

    /* SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator' incorporates:
     *  SubSystem: '<S2>/FOC_Control_100us'
     */
    FOC_Control_100us_Init();

    /* End of SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator' */
    /* End of SystemInitialize for SubSystem: '<Root>/Motor_Control' */

    /* SystemInitialize for Outport: '<Root>/Duty' */
    rtY.Duty = rtDW.Merge1_e;

    /* SystemInitialize for Outport: '<Root>/Gate' */
    for (i = 0; i < 6; i++) {
      rtY.Gate[i] = rtDW.Merge_gx[i];
    }

    /* End of SystemInitialize for Outport: '<Root>/Gate' */

    /* SystemInitialize for Outport: '<Root>/HFI_Theta' */
    rtY.HFI_Theta = rtDW.Merge2_j;

    /* SystemInitialize for Outport: '<Root>/FOC_Theta' */
    rtY.FOC_Theta = rtDW.Merge1;

    /* SystemInitialize for Outport: '<Root>/Force_Theta' */
    rtY.Force_Theta = rtDW.Merge_g;

    /* SystemInitialize for Outport: '<Root>/Ubeta_Ealpha' incorporates:
     *  Inport: '<S10>/Ubeta'
     *  S-Function (SMO_Function): '<S138>/S-Function Builder'
     */
    rtY.Ubeta_Ealpha[0] = rtDW.SFunctionBuilder_o4;
    rtY.Ubeta_Ealpha[1] = rtDW.Ubeta;

    /* SystemInitialize for Outport: '<Root>/Speed_Mes' */
    rtY.Speed_Mes = rtDW.Merge;

    /* SystemInitialize for Outport: '<Root>/SMO_Angle' */
    rtY.SMO_Angle = rtDW.Merge1_a;

    /* SystemInitialize for Outport: '<Root>/Hall_Angle' */
    rtY.Hall_Angle = rtDW.Merge1_c;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
