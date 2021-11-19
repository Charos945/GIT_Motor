/*
 * File: Motor_Control.c
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

#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* Exported block signals */
real32_T Obs_Speed;                    /* '<S2>/Unit Delay6' */
real32_T Obs_Theta;                    /* '<S2>/Unit Delay5' */
real32_T Motor_Power;                  /* '<S189>/Add1' */
real32_T Motor_Torque;                 /* '<S190>/Add1' */
real32_T Hall_Angle;                   /* '<S19>/Merge1' */
real32_T Hall_Speed;                   /* '<S11>/Add1' */
real32_T Id_ref;                       /* '<S4>/Constant' */
real32_T Iq_ref;                       /* '<S25>/Merge' */
real32_T Vq_voltage;                   /* '<S176>/Switch2' */
real32_T Id_measured;                  /* '<S42>/Add1' */
real32_T Iq_measured;                  /* '<S42>/Add2' */
real32_T V_alpha;                      /* '<S41>/Add1' */
real32_T V_beta;                       /* '<S41>/Add2' */
real32_T Vd_voltage;                   /* '<S56>/Switch2' */
real32_T Ialpha;                       /* '<S52>/Gain2' */
real32_T Ibeta;                        /* '<S52>/Gain5' */

/* Exported block parameters */
real32_T SpeedFilter_Fn = 0.3F;        /* Variable: SpeedFilter_Fn
                                        * Referenced by:
                                        *   '<S11>/Constant1'
                                        *   '<S69>/Constant1'
                                        */

/* Exported data definition */

/* Definition for custom storage class: Struct */
CTL_Parameter_type CTL_Parameter = {
  /* Over_modulation */
  0,

  /* Angle */
  1U,

  /* TorqueMode */
  0U
};

HFI_Parameter_type HFI_Parameter = {
  /* HFI_IPD_F */
  1000.0F,

  /* HFI_IPD_Time */
  0.1F,

  /* HFI_IPD_V */
  1.0F,

  /* HFI_Inj_HF */
  1000.0F,

  /* HFI_Inj_HV */
  2.0F,

  /* HFI_NS2RUN_Time */
  0.1F,

  /* HFI_NS_Low_Time */
  0.01F,

  /* HFI_NS_Time */
  0.05F,

  /* HFI_NS_V */
  1.0F,

  /* HFI_PLL_Omga */
  50.0F,

  /* HFI_PLL_Xi */
  0.707F,

  /* HFI_Pulse_Time */
  0.001F,

  /* HFI_Switch_Time */
  0.1F,

  /* HFI_bw_BPF */
  100.0F,

  /* HFI_Fuc_Enalbe */
  1U
};

Hall_Parameter_type Hall_Parameter = {
  /* HaLL_AngleShift */
  0.85F,
  3.14159274F,
  5.23598766F,
  4.18879032F,
1.04719758F,
2.09439516F,
0.0F,
  /* HaLL_Timer_T */
  5E-5F
};

PI_Parameter_type PI_Parameter = {
    /* ID_Ki */
  0.8F,

  /* ID_Kp */
  1.32F,

  /* IQ_Ki */
  0.32F,

  /* IQ_Kp */
  1.33F,

  /* Speed_Ki */
  0.00633F,

  /* Speed_Kp */
  0.000267F,

  /* Speed_PI_OutputMax */
  15.0F,

  /* Speed_PI_OutputMin */
  -15.0F
};

SMO_Parameter_type SMO_Parameter = {
  /* SMO_Theta_Enable */
  0U
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

  /* UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1 = rtDW.UnitDelay1_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay4' */
  rtDW.UnitDelay4 = rtDW.UnitDelay4_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay3' */
  rtDW.UnitDelay3 = rtDW.UnitDelay3_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay6' */
  Obs_Speed = rtDW.UnitDelay6_DSTATE;

  /* UnitDelay: '<S2>/Unit Delay7' */
  rtDW.UnitDelay7 = rtDW.UnitDelay7_DSTATE;
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (fcgen): '<S2>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S2>/Control_Command_2ms'
     */
    Control_Command_2ms_k();

    /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator1' */
  }

  /* UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2 = rtDW.UnitDelay2_DSTATE;
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (fcgen): '<S2>/Function-Call Generator3' incorporates:
     *  SubSystem: '<S2>/SYM_State_10ms'
     */
    SYM_State_10ms();

    /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator3' */
  }

  /* S-Function (fcgen): '<S2>/Function-Call Generator' incorporates:
   *  SubSystem: '<S2>/FOC_Control_100us'
   */
  FOC_Control_100us();

  /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator' */

  /* UnitDelay: '<S2>/Unit Delay5' */
  Obs_Theta = rtDW.UnitDelay5_DSTATE;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = Vd_voltage;

  /* Update for UnitDelay: '<S2>/Unit Delay4' */
  rtDW.UnitDelay4_DSTATE = Vq_voltage;

  /* Update for UnitDelay: '<S2>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE = Iq_measured;

  /* Update for UnitDelay: '<S2>/Unit Delay6' */
  rtDW.UnitDelay6_DSTATE = rtDW.freqwm1;

  /* Update for UnitDelay: '<S2>/Unit Delay7' */
  rtDW.UnitDelay7_DSTATE = rtDW.RUN_state;

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE = Id_measured;

  /* Update for UnitDelay: '<S2>/Unit Delay5' */
  rtDW.UnitDelay5_DSTATE = rtDW.Merge2_i;

  /* End of Outputs for SubSystem: '<Root>/Motor_Control' */

  /* Outport: '<Root>/Ta' */
  rtY.Ta = rtDW.Merge_c;

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

  /* SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator' incorporates:
   *  SubSystem: '<S2>/FOC_Control_100us'
   */
  FOC_Control_100us_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator' */
  /* End of SystemInitialize for SubSystem: '<Root>/Motor_Control' */

  /* SystemInitialize for Outport: '<Root>/Ta' */
  rtY.Ta = rtDW.Merge_c;

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
