/*
 * File: Motor_Control.c
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

#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Exported block signals */
real32_T Motor_Power;                  /* '<S60>/Add1' */
real32_T Motor_Torque;                 /* '<S61>/Add1' */
real32_T Id_ref;                       /* '<S4>/Constant' */
real32_T Iq_ref;                       /* '<S10>/Merge' */
real32_T Vq_voltage;                   /* '<S51>/Switch2' */
real32_T Id_measured;                  /* '<S20>/Add1' */
real32_T Iq_measured;                  /* '<S20>/Add2' */
real32_T V_alpha;                      /* '<S19>/Add' */
real32_T V_beta;                       /* '<S19>/Add3' */
real32_T Vd_voltage;                   /* '<S48>/Switch2' */
real32_T Ialpha;                       /* '<S24>/Gain2' */
real32_T Ibeta;                        /* '<S24>/Gain5' */

/* Exported block parameters */
real32_T Dead_Time = 2.5E-6F;          /* Variable: Dead_Time
                                        * Referenced by: '<S15>/IdRef2'
                                        */
real32_T SpeedFilter_Fn = 0.2F;        /* Variable: SpeedFilter_Fn
                                        * Referenced by: '<S9>/Constant1'
                                        */

/* Exported data definition */

/* Definition for custom storage class: Struct */
CTL_Parameter_type CTL_Parameter = {
  /* TorqueMode */
  0U
};

PI_Parameter_type PI_Parameter = {
  /* ID_Ki */
  48.0F,

  /* ID_Kp */
  0.84F,

  /* IQ_Ki */
  48.0F,

  /* IQ_Kp */
  1.869F,

  /* Speed_Ki */
  10.809F,

  /* Speed_Kp */
  0.08F,

  /* Speed_PI_OutputMax */
  700.0F,

  /* Speed_PI_OutputMin */
  -700.0F
};

/* Block signals and states (default storage) */
DW rtDW;

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
  if ((rtM->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [0.002s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }

  (rtM->Timing.TaskCounters.TID[2])++;
  if ((rtM->Timing.TaskCounters.TID[2]) > 199) {/* Sample time: [0.01s, 0.0s] */
    rtM->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function */
void Motor_Control_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Motor_Control' */
  /* UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2 = rtDW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1 = rtDW.UnitDelay1_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay3' */
  rtDW.UnitDelay3 = rtDW.UnitDelay3_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay4' */
  rtDW.UnitDelay4 = rtDW.UnitDelay4_DSTATE;

  /* S-Function (fcgen): '<S2>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S2>/Angle_Speed_100us'
   */
  Angle_Speed_100us();

  /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator2' */
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
  rtDW.UnitDelay1_DSTATE = Vd_voltage;

  /* Update for UnitDelay: '<S2>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE = Iq_measured;

  /* Update for UnitDelay: '<S2>/Unit Delay4' */
  rtDW.UnitDelay4_DSTATE = Vq_voltage;

  /* End of Outputs for SubSystem: '<Root>/Motor_Control' */

  /* Outport: '<Root>/Ta' */
  rtY.Ta = rtDW.Merge;

  /* Outport: '<Root>/Tb' */
  rtY.Tb = rtDW.Merge1;

  /* Outport: '<Root>/Tc' */
  rtY.Tc = rtDW.Merge2;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 5.0E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick0++;
  rate_scheduler();
}

/* Model initialize function */
void Motor_Control_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Motor_Control' */
  /* SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/Control_Command_2ms'
   */
  Control_Command_2ms_o_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Motor_Control' */

  /* SystemInitialize for Outport: '<Root>/Ta' */
  rtY.Ta = rtDW.Merge;

  /* SystemInitialize for Outport: '<Root>/Tb' */
  rtY.Tb = rtDW.Merge1;

  /* SystemInitialize for Outport: '<Root>/Tc' */
  rtY.Tc = rtDW.Merge2;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */