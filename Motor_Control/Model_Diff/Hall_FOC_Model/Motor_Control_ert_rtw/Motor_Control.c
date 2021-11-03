/*
 * File: Motor_Control.c
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Nov  1 17:42:50 2021
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
real32_T Motor_Power;                  /* '<S164>/Add1' */
real32_T Motor_Torque;                 /* '<S165>/Add1' */
real32_T Id_ref;                       /* '<S81>/Merge' */
real32_T Iq_ref;                       /* '<S81>/Merge1' */
real32_T Vq_voltage;                   /* '<S155>/Switch2' */
real32_T Id_measured;                  /* '<S99>/Add1' */
real32_T Iq_measured;                  /* '<S99>/Add2' */
real32_T V_alpha;                      /* '<S98>/Add' */
real32_T V_beta;                       /* '<S98>/Add3' */
real32_T Vd_voltage;                   /* '<S128>/Switch2' */
real32_T Ialpha;                       /* '<S103>/Gain2' */
real32_T Ibeta;                        /* '<S103>/Gain5' */

/* Exported block parameters */
real32_T Dead_Time = 0.0F;             /* Variable: Dead_Time
                                        * Referenced by: '<S92>/IdRef2'
                                        */
real32_T SpeedFilter_Fn = 0.3F;        /* Variable: SpeedFilter_Fn
                                        * Referenced by:
                                        *   '<S66>/Constant1'
                                        *   '<S79>/Constant1'
                                        */
uint8_T Dead_Com_Enable = 0U;          /* Variable: Dead_Com_Enable
                                        * Referenced by: '<S92>/Constant3'
                                        */
uint8_T FF_Enable = 0U;                /* Variable: FF_Enable
                                        * Referenced by: '<S92>/Constant1'
                                        */

/* Exported data definition */

/* Definition for custom storage class: Struct */
CTL_Parameter_type CTL_Parameter = {
  /* Angle_offset */
  0.1985F,

  /* Over_modulation */
  0,

  /* Angle */
  1U,

  /* TorqueMode */
  0U
};

FluxWeak_Parameter_type FluxWeak_Parameter = {
  /* FluxWeak_Idref_max */
  0.0F,

  /* FluxWeak_Idref_min */
  -200.0F,

  /* FluxWeak_Ki */
  50.0F,

  /* FluxWeak_Kp */
  1.2F,

  /* FluxWeak_Enable */
  0U
};

Hall_Parameter_type Hall_Parameter = {
  /* HaLL_AngleShift */
  -0.25F,

  /* HaLL_Sector1 */
  5.236F,

  /* HaLL_Sector2 */
  1.0472F,

  /* HaLL_Sector3 */
  0.0F,

  /* HaLL_Sector4 */
  3.1415F,

  /* HaLL_Sector5 */
  4.1888F,

  /* HaLL_Sector6 */
  2.0944F,

  /* HaLL_Timer_T */
  1.0E-5F
};

Harmonic_Com_type Harmonic_Com = {
  /* Harmonic_Id5th_Ki */
  32.0F,

  /* Harmonic_Id5th_Kp */
  1.2F,

  /* Harmonic_Id5th_Max */
  60.0F,

  /* Harmonic_Id5th_Min */
  -60.0F,

  /* Harmonic_Id7th_Ki */
  24.0F,

  /* Harmonic_Id7th_Kp */
  0.8F,

  /* Harmonic_Id7th_Max */
  60.0F,

  /* Harmonic_Id7th_Min */
  -60.0F,

  /* Harmonic_Iq5th_Ki */
  32.0F,

  /* Harmonic_Iq5th_Kp */
  1.2F,

  /* Harmonic_Iq5th_Max */
  60.0F,

  /* Harmonic_Iq5th_Min */
  -60.0F,

  /* Harmonic_Iq7th_Ki */
  24.0F,

  /* Harmonic_Iq7th_Kp */
  0.8F,

  /* Harmonic_Iq7th_Max */
  60.0F,

  /* Harmonic_Iq7th_Min */
  -60.0F,

  /* Harmonic_Com_Enable */
  0U
};

PI_Parameter_type PI_Parameter = {
  /* ID_Ki */
  0.8F,

  /* ID_Kp */
  3.2F,

  /* IQ_Ki */
  0.32F,

  /* IQ_Kp */
  3.3F,

  /* Speed_Ki */
  0.633F,

  /* Speed_Kp */
  0.0267F,

  /* Speed_PI_OutputMax */
  5.0F,

  /* Speed_PI_OutputMin */
  -5.0F
};

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
  /* Outputs for Atomic SubSystem: '<Root>/Motor_Control' */
  /* S-Function (fcgen): '<S2>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S2>/Angle_Speed_100us'
   */
  Angle_Speed_100us();

  /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator2' */

  /* UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2 = rtDW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1 = rtDW.UnitDelay1_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay3' */
  rtDW.UnitDelay3 = rtDW.UnitDelay3_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay4' */
  rtDW.UnitDelay4 = rtDW.UnitDelay4_DSTATE;
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (fcgen): '<S2>/Function-Call Generator3' incorporates:
     *  SubSystem: '<S2>/SYM_State_10ms'
     */
    SYM_State_10ms();

    /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator3' */
  }

  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (fcgen): '<S2>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S2>/Control_Command_2ms'
     */
    Control_Command_2ms_k();

    /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator1' */
  }

  /* S-Function (fcgen): '<S2>/Function-Call Generator' incorporates:
   *  SubSystem: '<S2>/FOC_Control_100us'
   */
  FOC_Control_100us();

  /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator' */

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE = Id_measured;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtDW.Add;

  /* Update for UnitDelay: '<S2>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE = Iq_measured;

  /* Update for UnitDelay: '<S2>/Unit Delay4' */
  rtDW.UnitDelay4_DSTATE = rtDW.Add1_a;

  /* End of Outputs for SubSystem: '<Root>/Motor_Control' */

  /* Outport: '<Root>/Ta' */
  rtY.Ta = rtDW.Merge_c4;

  /* Outport: '<Root>/Tb' */
  rtY.Tb = rtDW.Merge1_h;

  /* Outport: '<Root>/Tc' */
  rtY.Tc = rtDW.Merge2_d;
  rate_scheduler();
}

/* Model initialize function */
void Motor_Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtPrevZCX.ACC_OMG_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
  rtPrevZCX.ACC_OMG_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
  rtPrevZCX.ACC_OMG_Trig_ZCE[2] = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Motor_Control' */
  /* SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/Control_Command_2ms'
   */
  Control_Command_2ms_o_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Motor_Control' */

  /* SystemInitialize for Outport: '<Root>/Ta' */
  rtY.Ta = rtDW.Merge_c4;

  /* SystemInitialize for Outport: '<Root>/Tb' */
  rtY.Tb = rtDW.Merge1_h;

  /* SystemInitialize for Outport: '<Root>/Tc' */
  rtY.Tc = rtDW.Merge2_d;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
