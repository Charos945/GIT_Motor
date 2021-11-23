/*
 * File: FOC_Motor_Control.h
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

#ifndef RTW_HEADER_FOC_Motor_Control_h_
#define RTW_HEADER_FOC_Motor_Control_h_
#ifndef FOC_Motor_Control_COMMON_INCLUDES_
#define FOC_Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FOC_Motor_Control_COMMON_INCLUDES_ */

#include "FOC_Motor_Control_types.h"

/* Child system includes */
#include "Angle_Speed_100us.h"
#include "Control_Command_2ms.h"
#include "FOC_Control_100us.h"
#include "SYM_State_10ms.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T NS_RUN_flag;                  /* '<S58>/StartRUN_State_machine' */
  real_T Switch_flag;                  /* '<S58>/StartRUN_State_machine' */
  real_T NS_1_flag;                    /* '<S61>/NS_State_machine' */
  real_T NS_2_flag;                    /* '<S61>/NS_State_machine' */
  real_T NS_3_flag;                    /* '<S61>/NS_State_machine' */
  real_T NS_4_flag;                    /* '<S61>/NS_State_machine' */
  real_T IPD_flag;                     /* '<S57>/HFI_State_machine' */
  real_T NS_flag;                      /* '<S57>/HFI_State_machine' */
  real32_T UnitDelay1;                 /* '<S2>/Unit Delay1' */
  real32_T UnitDelay4;                 /* '<S2>/Unit Delay4' */
  real32_T UnitDelay3;                 /* '<S2>/Unit Delay3' */
  real32_T UnitDelay2;                 /* '<S2>/Unit Delay2' */
  real32_T Direct_Angle;               /* '<S8>/DT2' */
  real32_T Add1;                       /* '<S24>/Add1' */
  real32_T Timer_Counter;              /* '<S9>/Timer_Counter' */
  real32_T Gain2;                      /* '<S9>/Gain2' */
  real32_T a;                          /* '<S9>/Divide1' */
  real32_T Merge2;                     /* '<S12>/Merge2' */
  real32_T Merge;                      /* '<S26>/Merge' */
  real32_T DiscreteTimeIntegrator;     /* '<S32>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_m;   /* '<S31>/Discrete-Time Integrator' */
  real32_T Merge_g;                    /* '<S47>/Merge' */
  real32_T Merge1;                     /* '<S47>/Merge1' */
  real32_T Merge1_k;                   /* '<S36>/Merge1' */
  real32_T Cosine;                     /* '<S46>/Cosine' */
  real32_T Sine;                       /* '<S46>/Sine' */
  real32_T Merge1_n;                   /* '<S45>/Merge1' */
  real32_T Merge_c;                    /* '<S44>/Merge' */
  real32_T Merge1_h;                   /* '<S44>/Merge1' */
  real32_T Merge2_d;                   /* '<S44>/Merge2' */
  real32_T Delay;                      /* '<S57>/Delay' */
  real32_T Delay1;                     /* '<S57>/Delay1' */
  real32_T Merge_o;                    /* '<S57>/Merge' */
  real32_T Merge1_dq;                  /* '<S57>/Merge1' */
  real32_T Merge2_i;                   /* '<S57>/Merge2' */
  real32_T DataTypeConversion;         /* '<S58>/Data Type Conversion' */
  real32_T freqwm1;                    /* '<S58>/freq <-- wm1' */
  real32_T IPD_angle;                  /* '<S58>/IPD_angle' */
  real32_T Merge2_o;                   /* '<S58>/Merge2' */
  real32_T Subtract;                   /* '<S63>/Subtract' */
  real32_T DataTypeConversion_k;       /* '<S61>/Data Type Conversion' */
  real32_T Merge_p;                    /* '<S61>/Merge' */
  real32_T Merge1_o;                   /* '<S61>/Merge1' */
  real32_T Merge1_dg;                  /* '<S159>/Merge1' */
  real32_T Merge1_hm;                  /* '<S164>/Merge1' */
  real32_T Cosine_a;                   /* '<S163>/Cosine' */
  real32_T Sine_n;                     /* '<S163>/Sine' */
  real32_T Cosine_m;                   /* '<S162>/Cosine' */
  real32_T Sine_a;                     /* '<S162>/Sine' */
  real32_T Cosine_f;                   /* '<S161>/Cosine' */
  real32_T Sine_d;                     /* '<S161>/Sine' */
  real32_T Cosine_g;                   /* '<S160>/Cosine' */
  real32_T Sine_p;                     /* '<S160>/Sine' */
  real32_T Product1;                   /* '<S145>/Product1' */
  real32_T Merge_l;                    /* '<S147>/Merge' */
  real32_T Sine_dg;                    /* '<S146>/Sine' */
  real32_T Add;                        /* '<S36>/Add' */
  real32_T Add_l;                      /* '<S71>/Add' */
  real32_T Gain1;                      /* '<S147>/Gain1' */
  real32_T UnitDelay1_DSTATE;          /* '<S2>/Unit Delay1' */
  real32_T UnitDelay4_DSTATE;          /* '<S2>/Unit Delay4' */
  real32_T UnitDelay3_DSTATE;          /* '<S2>/Unit Delay3' */
  real32_T UnitDelay6_DSTATE;          /* '<S2>/Unit Delay6' */
  real32_T UnitDelay2_DSTATE;          /* '<S2>/Unit Delay2' */
  real32_T UnitDelay5_DSTATE;          /* '<S2>/Unit Delay5' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S32>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_d;/* '<S31>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S173>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE;               /* '<S57>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S57>/Delay1' */
  real32_T Delay2_DSTATE;              /* '<S57>/Delay2' */
  real32_T DiscreteTimeIntegrator_DSTATE_i5;/* '<S58>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE;          /* '<S88>/Integrator' */
  real32_T Integrator_DSTATE_p;        /* '<S89>/Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S76>/Integrator' */
  real32_T Integrator_DSTATE_k;        /* '<S77>/Integrator' */
  real32_T Delay2_DSTATE_h;            /* '<S58>/Delay2' */
  real32_T Integrator_DSTATE_ph;       /* '<S92>/Integrator' */
  real32_T Integrator_DSTATE_i;        /* '<S93>/Integrator' */
  real32_T Integrator_DSTATE_a;        /* '<S127>/Integrator' */
  real32_T UnitDelay_DSTATE_c;         /* '<S69>/Unit Delay' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S58>/Discrete-Time Integrator1' */
  real32_T Delay_DSTATE_n;             /* '<S61>/Delay' */
  real32_T Delay1_DSTATE_n;            /* '<S61>/Delay1' */
  real32_T Delay_DSTATE_o;             /* '<S145>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S53>/Discrete-Time Integrator' */
  real32_T Memory_PreviousInput;       /* '<S9>/Memory' */
  real32_T Memory1_PreviousInput;      /* '<S9>/Memory1' */
  real32_T Memory2_PreviousInput;      /* '<S9>/Memory2' */
  real32_T Memory_PreviousInput_d3;    /* '<S145>/Memory' */
  real32_T RMS_SqData;                 /* '<S147>/RMS' */
  real32_T RMS1_SqData;                /* '<S147>/RMS1' */
  real32_T RMS2_SqData;                /* '<S147>/RMS2' */
  int32_T Position_Delay_DSTATE;       /* '<S23>/Position_Delay' */
  uint32_T temporalCounter_i1;         /* '<S58>/StartRUN_State_machine' */
  uint32_T temporalCounter_i1_a;       /* '<S61>/NS_State_machine' */
  uint32_T RMS_Iteration;              /* '<S147>/RMS' */
  uint32_T RMS1_Iteration;             /* '<S147>/RMS1' */
  uint32_T RMS2_Iteration;             /* '<S147>/RMS2' */
  uint32_T temporalCounter_i1_m;       /* '<S57>/HFI_State_machine' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S25>/Switch Case' */
  int8_T If1_ActiveSubsystem;          /* '<S30>/If1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S173>/Discrete-Time Integrator' */
  int8_T If1_ActiveSubsystem_i;        /* '<S40>/If1' */
  int8_T Integrator_PrevResetState;    /* '<S88>/Integrator' */
  int8_T Integrator_PrevResetState_a;  /* '<S89>/Integrator' */
  int8_T Integrator_PrevResetState_g;  /* '<S76>/Integrator' */
  int8_T Integrator_PrevResetState_p;  /* '<S77>/Integrator' */
  int8_T Integrator_PrevResetState_k;  /* '<S92>/Integrator' */
  int8_T Integrator_PrevResetState_h;  /* '<S93>/Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p;/* '<S53>/Discrete-Time Integrator' */
  uint8_T UnitDelay7;                  /* '<S2>/Unit Delay7' */
  uint8_T Merge1_a;                    /* '<S6>/Merge1' */
  uint8_T RUN_state;                   /* '<S58>/StartRUN_State_machine' */
  uint8_T NS_state;                    /* '<S61>/NS_State_machine' */
  uint8_T HFI_state;                   /* '<S57>/HFI_State_machine' */
  uint8_T UnitDelay7_DSTATE;           /* '<S2>/Unit Delay7' */
  uint8_T is_active_c6_FOC_Motor_Control;/* '<S58>/StartRUN_State_machine' */
  uint8_T is_c6_FOC_Motor_Control;     /* '<S58>/StartRUN_State_machine' */
  uint8_T is_active_c8_FOC_Motor_Control;/* '<S61>/NS_State_machine' */
  uint8_T is_c8_FOC_Motor_Control;     /* '<S61>/NS_State_machine' */
  uint8_T is_active_c7_FOC_Motor_Control;/* '<S57>/HFI_State_machine' */
  uint8_T is_c7_FOC_Motor_Control;     /* '<S57>/HFI_State_machine' */
  boolean_T UnitDelay3_DSTATE_l;       /* '<S32>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_a;       /* '<S31>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_i;       /* '<S173>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_k;       /* '<S53>/Unit Delay3' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ACC_OMG_Trig_ZCE[3];      /* '<S7>/ACC_OMG' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: Sine_table)
   * Referenced by:
   *   '<S46>/Sine'
   *   '<S71>/Sine'
   *   '<S146>/Sine'
   *   '<S144>/Sine'
   *   '<S160>/Sine'
   *   '<S161>/Sine'
   *   '<S162>/Sine'
   *   '<S163>/Sine'
   *   '<S167>/Sine'
   */
  real32_T pooled14[4096];

  /* Pooled Parameter (Expression: Cosine_table)
   * Referenced by:
   *   '<S46>/Cosine'
   *   '<S146>/Cosine'
   *   '<S144>/Cosine'
   *   '<S160>/Cosine'
   *   '<S161>/Cosine'
   *   '<S162>/Cosine'
   *   '<S163>/Cosine'
   *   '<S167>/Cosine'
   */
  real32_T pooled18[4096];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Speed_target;               /* '<Root>/Speed_target' */
  real32_T Torque_ref;                 /* '<Root>/Torque_ref' */
  real32_T Phase_CurrentABC[3];        /* '<Root>/Phase_CurrentABC' */
  real32_T Angle_Theta;                /* '<Root>/Angle_Theta' */
  real32_T Bus_Voltage;                /* '<Root>/Bus_Voltage' */
  uint8_T Start_Stop;                  /* '<Root>/Start_Stop' */
  real32_T Timer_counter;              /* '<Root>/Timer_counter' */
  uint8_T Hall[3];                     /* '<Root>/Hall' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Ta;                         /* '<Root>/Ta' */
  real32_T Tb;                         /* '<Root>/Tb' */
  real32_T Tc;                         /* '<Root>/Tc' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct CTL_Parameter_tag {
  boolean_T Over_modulation;           /* Referenced by:
                                        * '<S53>/Over_modulation'
                                        * '<S173>/Over_modulation'
                                        */
  uint8_T Angle;                       /* Referenced by: '<S2>/Select_Angle' */
  uint8_T TorqueMode;                  /* Referenced by: '<S2>/Control_Mode' */
} CTL_Parameter_type;

typedef struct HFI_Parameter_tag {
  real32_T HFI_IPD_F;                  /* Referenced by: '<S145>/Const1' */
  real32_T HFI_IPD_Time;               /* Referenced by: '<S57>/Constant' */
  real32_T HFI_IPD_V;                  /* Referenced by: '<S60>/Constant' */
  real32_T HFI_Inj_HF;                 /* Referenced by:
                                        * '<S58>/Const'
                                        * '<S58>/Const1'
                                        * '<S58>/Const2'
                                        * '<S71>/Const1'
                                        */
  real32_T HFI_Inj_HV;                 /* Referenced by: '<S71>/A' */
  real32_T HFI_NS2RUN_Time;            /* Referenced by: '<S58>/Const4' */
  real32_T HFI_NS_Low_Time;            /* Referenced by: '<S61>/Constant1' */
  real32_T HFI_NS_Time;                /* Referenced by: '<S57>/Constant1' */
  real32_T HFI_NS_V;                   /* Referenced by:
                                        * '<S156>/Constant'
                                        * '<S158>/Constant'
                                        */
  real32_T HFI_PLL_Omga;               /* Referenced by:
                                        * '<S58>/Ki'
                                        * '<S58>/Kp'
                                        */
  real32_T HFI_PLL_Xi;                 /* Referenced by: '<S58>/Kp' */
  real32_T HFI_Pulse_Time;             /* Referenced by: '<S61>/Constant2' */
  real32_T HFI_Switch_Time;            /* Referenced by: '<S58>/Const5' */
  real32_T HFI_bw_BPF;                 /* Referenced by:
                                        * '<S58>/Const1'
                                        * '<S58>/Const2'
                                        */
  uint8_T HFI_Fuc_Enalbe;              /* Referenced by:
                                        * '<S37>/HFI_AngleEnable'
                                        * '<S40>/HFI_Enalble'
                                        * '<S57>/HFI_Enalble'
                                        * '<S30>/HFI_Enalble'
                                        * '<S58>/HFI_Enalble'
                                        * '<S61>/HFI_Enalble'
                                        */
} HFI_Parameter_type;

typedef struct Hall_Parameter_tag {
  real32_T HaLL_AngleShift;            /* Referenced by:
                                        * '<S19>/Angle_offset'
                                        * '<S13>/Constant1'
                                        * '<S14>/Constant1'
                                        * '<S15>/Constant1'
                                        * '<S16>/Constant1'
                                        * '<S17>/Constant1'
                                        * '<S18>/Constant1'
                                        */
  real32_T HaLL_Sector1;               /* Referenced by: '<S13>/Constant' */
  real32_T HaLL_Sector2;               /* Referenced by: '<S14>/Pi//3' */
  real32_T HaLL_Sector3;               /* Referenced by: '<S15>/Constant' */
  real32_T HaLL_Sector4;               /* Referenced by: '<S16>/Constant' */
  real32_T HaLL_Sector5;               /* Referenced by: '<S17>/Constant' */
  real32_T HaLL_Sector6;               /* Referenced by: '<S18>/Constant' */
  real32_T HaLL_Timer_T;               /* Referenced by:
                                        * '<S9>/Gain3'
                                        * '<S10>/Gain2'
                                        * '<S10>/Gain3'
                                        */
} Hall_Parameter_type;

typedef struct PI_Parameter_tag {
  real32_T ID_Ki;                      /* Referenced by: '<S53>/Ki' */
  real32_T ID_Kp;                      /* Referenced by: '<S53>/Kp' */
  real32_T IQ_Ki;                      /* Referenced by: '<S173>/Ki' */
  real32_T IQ_Kp;                      /* Referenced by: '<S173>/Kp' */
  real32_T Speed_Ki;                   /* Referenced by:
                                        * '<S31>/Ki'
                                        * '<S32>/Ki'
                                        */
  real32_T Speed_Kp;                   /* Referenced by:
                                        * '<S31>/Kp'
                                        * '<S32>/Kp'
                                        */
  real32_T Speed_PI_OutputMax;         /* Referenced by:
                                        * '<S31>/Saturation'
                                        * '<S32>/Saturation'
                                        */
  real32_T Speed_PI_OutputMin;         /* Referenced by:
                                        * '<S31>/Saturation'
                                        * '<S32>/Saturation'
                                        */
} PI_Parameter_type;

typedef struct SMO_Parameter_tag {
  uint8_T SMO_Theta_Enable;            /* Referenced by: '<S26>/Flux_Enable' */
} SMO_Parameter_type;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Zero-crossing (trigger) state */
extern PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T Obs_Speed;             /* '<S2>/Unit Delay6' */
extern real32_T Obs_Theta;             /* '<S2>/Unit Delay5' */
extern real32_T Motor_Power;           /* '<S189>/Add1' */
extern real32_T Motor_Torque;          /* '<S190>/Add1' */
extern real32_T Hall_Angle;            /* '<S19>/Merge1' */
extern real32_T Hall_Speed;            /* '<S11>/Add1' */
extern real32_T Id_ref;                /* '<S4>/Constant' */
extern real32_T Iq_ref;                /* '<S25>/Merge' */
extern real32_T Vq_voltage;            /* '<S176>/Switch2' */
extern real32_T Id_measured;           /* '<S42>/Add1' */
extern real32_T Iq_measured;           /* '<S42>/Add2' */
extern real32_T V_alpha;               /* '<S41>/Add1' */
extern real32_T V_beta;                /* '<S41>/Add2' */
extern real32_T Id2;                   /* '<S158>/Id' */
extern real32_T Id1;                   /* '<S156>/Id' */
extern real32_T Vd_voltage;            /* '<S56>/Switch2' */
extern real32_T Ialpha;                /* '<S52>/Gain2' */
extern real32_T Ibeta;                 /* '<S52>/Gain5' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T SpeedFilter_Fn;        /* Variable: SpeedFilter_Fn
                                        * Referenced by:
                                        *   '<S11>/Constant1'
                                        *   '<S24>/Constant1'
                                        *   '<S69>/Constant1'
                                        */

/* Model entry point functions */
extern void FOC_Motor_Control_initialize(void);
extern void FOC_Motor_Control_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern CTL_Parameter_type CTL_Parameter;
extern HFI_Parameter_type HFI_Parameter;
extern Hall_Parameter_type Hall_Parameter;
extern PI_Parameter_type PI_Parameter;
extern SMO_Parameter_type SMO_Parameter;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<S3>/Scope3' : Unused code path elimination
 * Block '<S9>/Scope1' : Unused code path elimination
 * Block '<S9>/Scope17' : Unused code path elimination
 * Block '<S9>/Scope2' : Unused code path elimination
 * Block '<S9>/Scope3' : Unused code path elimination
 * Block '<S9>/Scope4' : Unused code path elimination
 * Block '<S9>/Scope5' : Unused code path elimination
 * Block '<S12>/Scope' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S23>/Scope' : Unused code path elimination
 * Block '<S31>/Scope' : Unused code path elimination
 * Block '<S38>/Scope' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Propagation' : Unused code path elimination
 * Block '<S58>/Scope' : Unused code path elimination
 * Block '<S58>/Scope1' : Unused code path elimination
 * Block '<S58>/Scope10' : Unused code path elimination
 * Block '<S58>/Scope2' : Unused code path elimination
 * Block '<S58>/Scope4' : Unused code path elimination
 * Block '<S58>/Scope5' : Unused code path elimination
 * Block '<S58>/Scope6' : Unused code path elimination
 * Block '<S58>/Scope7' : Unused code path elimination
 * Block '<S58>/Scope8' : Unused code path elimination
 * Block '<S58>/Scope9' : Unused code path elimination
 * Block '<S144>/Scope' : Unused code path elimination
 * Block '<S60>/Scope' : Unused code path elimination
 * Block '<S146>/Scope' : Unused code path elimination
 * Block '<S147>/Display1' : Unused code path elimination
 * Block '<S147>/Display2' : Unused code path elimination
 * Block '<S147>/Display3' : Unused code path elimination
 * Block '<S147>/Display6' : Unused code path elimination
 * Block '<S147>/Scope1' : Unused code path elimination
 * Block '<S147>/Scope2' : Unused code path elimination
 * Block '<S61>/Scope' : Unused code path elimination
 * Block '<S61>/Scope1' : Unused code path elimination
 * Block '<S160>/Scope' : Unused code path elimination
 * Block '<S161>/Scope' : Unused code path elimination
 * Block '<S162>/Scope' : Unused code path elimination
 * Block '<S163>/Scope' : Unused code path elimination
 * Block '<S167>/Scope' : Unused code path elimination
 * Block '<S42>/Scope' : Unused code path elimination
 * Block '<S42>/Scope1' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Propagation' : Unused code path elimination
 * Block '<S181>/Scope2' : Unused code path elimination
 * Block '<S36>/Scope1' : Unused code path elimination
 * Block '<S36>/Scope2' : Unused code path elimination
 * Block '<S36>/Scope3' : Unused code path elimination
 * Block '<S36>/Scope5' : Unused code path elimination
 * Block '<S46>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope2' : Unused code path elimination
 * Block '<S6>/Scope3' : Unused code path elimination
 * Block '<S6>/Scope4' : Unused code path elimination
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S10>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S76>/Saturation' : Eliminated Saturate block
 * Block '<S77>/Saturation' : Eliminated Saturate block
 * Block '<S88>/Saturation' : Eliminated Saturate block
 * Block '<S89>/Saturation' : Eliminated Saturate block
 * Block '<S92>/Saturation' : Eliminated Saturate block
 * Block '<S93>/Saturation' : Eliminated Saturate block
 * Block '<S2>/RT1' : Eliminated since input and output rates are identical
 * Block '<S2>/RT2' : Eliminated since input and output rates are identical
 * Block '<S2>/RT3' : Eliminated since input and output rates are identical
 * Block '<S2>/RT4' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FOC_Motor_Control'
 * '<S1>'   : 'FOC_Motor_Control/Motor_Control'
 * '<S2>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function'
 * '<S3>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us'
 * '<S4>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms'
 * '<S5>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us'
 * '<S6>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms'
 * '<S7>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle'
 * '<S8>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Speed_Resolver'
 * '<S9>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG'
 * '<S10>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ'
 * '<S11>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/LPF'
 * '<S12>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point'
 * '<S13>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_1'
 * '<S14>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_2'
 * '<S15>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_3'
 * '<S16>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_4'
 * '<S17>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_5'
 * '<S18>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_6'
 * '<S19>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration'
 * '<S20>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration/If Action Subsystem1'
 * '<S21>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration/If Action Subsystem2'
 * '<S22>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration/If Action Subsystem3'
 * '<S23>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Speed_Resolver/Speed_cacl'
 * '<S24>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Speed_Resolver/Speed_cacl/LPF'
 * '<S25>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms'
 * '<S26>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem'
 * '<S27>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI'
 * '<S28>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Switch Case Action Subsystem'
 * '<S29>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI'
 * '<S30>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI/Speed_Control'
 * '<S31>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI/Speed_Control/Speed_Control'
 * '<S32>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI/Speed_Control/Speed_Control1'
 * '<S33>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI/Speed_Control/Speed_Control2'
 * '<S34>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem/Hall_Spd'
 * '<S35>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem/Obs_Spd'
 * '<S36>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC'
 * '<S37>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Angle_set'
 * '<S38>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Clarke_Transform'
 * '<S39>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI'
 * '<S40>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer'
 * '<S41>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Inverse_Park_Transform'
 * '<S42>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Park_Transform'
 * '<S43>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI'
 * '<S44>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM'
 * '<S45>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Set_Idq'
 * '<S46>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Sine_Cosine'
 * '<S47>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Subsystem1'
 * '<S48>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Angle_set/Subsystem'
 * '<S49>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Angle_set/Subsystem1'
 * '<S50>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Angle_set/Subsystem/Subsystem1'
 * '<S51>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Angle_set/Subsystem/Subsystem2'
 * '<S52>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Clarke_Transform/Clark1'
 * '<S53>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control'
 * '<S54>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Normal'
 * '<S55>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Over_M'
 * '<S56>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Saturation Dynamic'
 * '<S57>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function'
 * '<S58>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI'
 * '<S59>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI_State_machine'
 * '<S60>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD'
 * '<S61>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS'
 * '<S62>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HFI_Angle'
 * '<S63>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HFI_Angle1'
 * '<S64>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HPF'
 * '<S65>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle'
 * '<S66>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle1'
 * '<S67>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF'
 * '<S68>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF1'
 * '<S69>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF2'
 * '<S70>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl'
 * '<S71>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/Sine_function'
 * '<S72>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/StartRUN_State_machine'
 * '<S73>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/Subsystem'
 * '<S74>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HPF/Integrator (Discrete or Continuous)'
 * '<S75>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HPF/Integrator (Discrete or Continuous)1'
 * '<S76>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HPF/Integrator (Discrete or Continuous)/Discrete'
 * '<S77>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HPF/Integrator (Discrete or Continuous)1/Discrete'
 * '<S78>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle/Angle_calibration'
 * '<S79>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle/Angle_calibration/If Action Subsystem1'
 * '<S80>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle/Angle_calibration/If Action Subsystem2'
 * '<S81>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle/Angle_calibration/If Action Subsystem3'
 * '<S82>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle1/Angle_calibration'
 * '<S83>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle1/Angle_calibration/If Action Subsystem1'
 * '<S84>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle1/Angle_calibration/If Action Subsystem2'
 * '<S85>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle1/Angle_calibration/If Action Subsystem3'
 * '<S86>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF/Integrator (Discrete or Continuous)'
 * '<S87>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF/Integrator (Discrete or Continuous)1'
 * '<S88>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF/Integrator (Discrete or Continuous)/Discrete'
 * '<S89>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF/Integrator (Discrete or Continuous)1/Discrete'
 * '<S90>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF1/Integrator (Discrete or Continuous)'
 * '<S91>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF1/Integrator (Discrete or Continuous)1'
 * '<S92>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF1/Integrator (Discrete or Continuous)/Discrete'
 * '<S93>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF1/Integrator (Discrete or Continuous)1/Discrete'
 * '<S94>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Anti-windup'
 * '<S95>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/D Gain'
 * '<S96>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Filter'
 * '<S97>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Filter ICs'
 * '<S98>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/I Gain'
 * '<S99>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Ideal P Gain'
 * '<S100>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Ideal P Gain Fdbk'
 * '<S101>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Integrator'
 * '<S102>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Integrator ICs'
 * '<S103>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/N Copy'
 * '<S104>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/N Gain'
 * '<S105>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/P Copy'
 * '<S106>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Parallel P Gain'
 * '<S107>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Reset Signal'
 * '<S108>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Saturation'
 * '<S109>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Saturation Fdbk'
 * '<S110>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Sum'
 * '<S111>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Sum Fdbk'
 * '<S112>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Tracking Mode'
 * '<S113>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Tracking Mode Sum'
 * '<S114>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Tsamp - Integral'
 * '<S115>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Tsamp - Ngain'
 * '<S116>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/postSat Signal'
 * '<S117>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/preSat Signal'
 * '<S118>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel'
 * '<S119>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S120>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S121>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/D Gain/Disabled'
 * '<S122>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Filter/Disabled'
 * '<S123>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Filter ICs/Disabled'
 * '<S124>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/I Gain/External Parameters'
 * '<S125>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Ideal P Gain/Passthrough'
 * '<S126>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Ideal P Gain Fdbk/Disabled'
 * '<S127>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Integrator/Discrete'
 * '<S128>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Integrator ICs/Internal IC'
 * '<S129>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/N Copy/Disabled wSignal Specification'
 * '<S130>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/N Gain/Disabled'
 * '<S131>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/P Copy/Disabled'
 * '<S132>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Parallel P Gain/External Parameters'
 * '<S133>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Reset Signal/Disabled'
 * '<S134>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Saturation/Enabled'
 * '<S135>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Saturation Fdbk/Disabled'
 * '<S136>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Sum/Sum_PI'
 * '<S137>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Sum Fdbk/Disabled'
 * '<S138>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Tracking Mode/Disabled'
 * '<S139>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Tracking Mode Sum/Passthrough'
 * '<S140>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Tsamp - Integral/Passthrough'
 * '<S141>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/Tsamp - Ngain/Passthrough'
 * '<S142>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/postSat Signal/Forward_Path'
 * '<S143>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PIDTheta_Ctrl/preSat Signal/Forward_Path'
 * '<S144>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/Subsystem/Sine_Cosine'
 * '<S145>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/HF_Angle'
 * '<S146>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Sine_Cosine'
 * '<S147>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl'
 * '<S148>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem1'
 * '<S149>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem2'
 * '<S150>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem3'
 * '<S151>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem4'
 * '<S152>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem5'
 * '<S153>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem6'
 * '<S154>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/NS_State_machine'
 * '<S155>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_1'
 * '<S156>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_2'
 * '<S157>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_3'
 * '<S158>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_4'
 * '<S159>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5'
 * '<S160>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_1/Sine_Cosine'
 * '<S161>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_2/Sine_Cosine'
 * '<S162>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_3/Sine_Cosine'
 * '<S163>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_4/Sine_Cosine'
 * '<S164>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_4/Theta_limit'
 * '<S165>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_4/Theta_limit/If Action Subsystem1'
 * '<S166>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_4/Theta_limit/If Action Subsystem2'
 * '<S167>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Sine_Cosine'
 * '<S168>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Subsystem'
 * '<S169>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Subsystem1'
 * '<S170>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Subsystem1/Theta_limit'
 * '<S171>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Subsystem1/Theta_limit/If Action Subsystem1'
 * '<S172>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Subsystem1/Theta_limit/If Action Subsystem2'
 * '<S173>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control'
 * '<S174>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Normal'
 * '<S175>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Over_M'
 * '<S176>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Saturation Dynamic'
 * '<S177>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Disable_Motor'
 * '<S178>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Enable_Motor'
 * '<S179>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/N Sector  Caculate'
 * '<S180>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/T1 T2  Caculate'
 * '<S181>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Tcm calculate'
 * '<S182>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/XYZ Caculate'
 * '<S183>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Set_Idq/Set_Idq'
 * '<S184>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Set_Idq/Set_Idq1'
 * '<S185>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Subsystem1/If Action Subsystem1'
 * '<S186>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Subsystem1/If Action Subsystem2'
 * '<S187>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/If Action Subsystem1'
 * '<S188>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/If Action Subsystem2'
 * '<S189>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/LPF'
 * '<S190>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/LPF1'
 * '<S191>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/Power_Cacl'
 * '<S192>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/Torque_Cacl'
 */
#endif                                 /* RTW_HEADER_FOC_Motor_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
