/*
 * File: Motor_Control.h
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

#ifndef RTW_HEADER_Motor_Control_h_
#define RTW_HEADER_Motor_Control_h_
#ifndef Motor_Control_COMMON_INCLUDES_
#define Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Motor_Control_COMMON_INCLUDES_ */

#include "Motor_Control_types.h"

/* Child system includes */
#include "Angle_Speed_100us.h"
#include "Control_Command_2ms.h"
#include "FOC_Control_100us.h"
#include "Motor_State_10ms.h"
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
  dsp_simulink_MovingAverage obj;      /* '<S8>/Moving Average' */
  real_T CL_flag;                      /* '<S3>/State_machine' */
  real_T NS_RUN_flag;                  /* '<S209>/StartRUN_State_machine' */
  real_T Switch_flag;                  /* '<S209>/StartRUN_State_machine' */
  real_T NS_1_flag;                    /* '<S212>/NS_State_machine' */
  real_T NS_2_flag;                    /* '<S212>/NS_State_machine' */
  real_T NS_3_flag;                    /* '<S212>/NS_State_machine' */
  real_T NS_4_flag;                    /* '<S212>/NS_State_machine' */
  real_T IPD_flag;                     /* '<S208>/HFI_State_machine' */
  real_T NS_flag;                      /* '<S208>/HFI_State_machine' */
  real32_T Merge_p[6];                 /* '<S146>/Merge' */
  real32_T Merge_gx[6];                /* '<S147>/Merge' */
  real32_T DirectLookupTablenD2[6];    /* '<S151>/Direct Lookup Table (n-D)2' */
  real32_T UnitDelay2;                 /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1;                 /* '<S2>/Unit Delay1' */
  real32_T UnitDelay4;                 /* '<S2>/Unit Delay4' */
  real32_T UnitDelay3;                 /* '<S2>/Unit Delay3' */
  real32_T Lowpassfilter;              /* '<S6>/Low pass filter' */
  real32_T Lowpassfilter1;             /* '<S6>/Low pass filter1' */
  real32_T UnitDelay1_i;               /* '<S3>/Unit Delay1' */
  real32_T Merge;                      /* '<S12>/Merge' */
  real32_T Merge1;                     /* '<S12>/Merge1' */
  real32_T Direct_Angle;               /* '<S13>/DT2' */
  real32_T Speed_RPM_Filtered;         /* '<S175>/LPF' */
  real32_T LPF;                        /* '<S81>/LPF' */
  real32_T Sine;                       /* '<S86>/Sine' */
  real32_T Merge1_m;                   /* '<S80>/Merge1' */
  real32_T Merge_g;                    /* '<S14>/Merge' */
  real32_T Merge1_n;                   /* '<S14>/Merge1' */
  real32_T DiscreteTimeIntegrator1;    /* '<S176>/Discrete-Time Integrator1' */
  real32_T Subtract;                   /* '<S176>/Subtract' */
  real32_T Integrator;                 /* '<S22>/Integrator' */
  real32_T Integrator1;                /* '<S22>/Integrator1' */
  real32_T Sine_c;                     /* '<S24>/Sine' */
  real32_T DiscreteTimeIntegrator;     /* '<S10>/Discrete-Time Integrator' */
  real32_T Gain3;                      /* '<S10>/Gain3' */
  real32_T Ubeta;                      /* '<S10>/Ubeta' */
  real32_T UnitDelay2_k;               /* '<S10>/Unit Delay2' */
  real32_T SFunctionBuilder_o1;        /* '<S138>/S-Function Builder' */
  real32_T SFunctionBuilder_o2;        /* '<S138>/S-Function Builder' */
  real32_T SFunctionBuilder_o3;        /* '<S138>/S-Function Builder' */
  real32_T SFunctionBuilder_o4;        /* '<S138>/S-Function Builder' */
  real32_T SFunctionBuilder_o5;        /* '<S138>/S-Function Builder' */
  real32_T SFunctionBuilder_o6;        /* '<S138>/S-Function Builder' */
  real32_T DiscreteTimeIntegrator_a;   /* '<S137>/Discrete-Time Integrator' */
  real32_T Merge1_a;                   /* '<S135>/Merge1' */
  real32_T Merge1_n2;                  /* '<S146>/Merge1' */
  real32_T Merge1_e;                   /* '<S147>/Merge1' */
  real32_T Merge1_c;                   /* '<S160>/Merge1' */
  real32_T Timer_Counter;              /* '<S143>/Timer_Counter' */
  real32_T Gain2;                      /* '<S143>/Gain2' */
  real32_T a;                          /* '<S143>/Divide1' */
  real32_T Merge2;                     /* '<S149>/Merge2' */
  real32_T Saturation;                 /* '<S152>/Saturation' */
  real32_T FOC_Angle;                  /* '<S7>/Merge' */
  real32_T Merge_j;                    /* '<S4>/Merge' */
  real32_T Merge_d;                    /* '<S180>/Merge' */
  real32_T DiscreteTimeIntegrator_h;   /* '<S182>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_l;   /* '<S181>/Discrete-Time Integrator' */
  real32_T uDLookupTable4;             /* '<S185>/1-D Lookup Table4' */
  real32_T uDLookupTable5;             /* '<S185>/1-D Lookup Table5' */
  real32_T Merge_l;                    /* '<S184>/Merge' */
  real32_T Merge_p2;                   /* '<S189>/Merge' */
  real32_T Merge1_i;                   /* '<S189>/Merge1' */
  real32_T Merge_b;                    /* '<S183>/Merge' */
  real32_T Merge_m;                    /* '<S197>/Merge' */
  real32_T Merge1_f;                   /* '<S197>/Merge1' */
  real32_T DiscreteTimeIntegrator_p;   /* '<S273>/Discrete-Time Integrator' */
  real32_T Saturation_b;               /* '<S273>/Saturation' */
  real32_T Add1;                       /* '<S192>/Add1' */
  real32_T Add2;                       /* '<S192>/Add2' */
  real32_T Add1_l;                     /* '<S191>/Add1' */
  real32_T Delay;                      /* '<S208>/Delay' */
  real32_T Delay1;                     /* '<S208>/Delay1' */
  real32_T Merge_f;                    /* '<S208>/Merge' */
  real32_T Merge1_g;                   /* '<S208>/Merge1' */
  real32_T Merge2_j;                   /* '<S208>/Merge2' */
  real32_T DiscreteTimeIntegrator_k;   /* '<S220>/Discrete-Time Integrator' */
  real32_T IPD_angle;                  /* '<S209>/IPD_angle' */
  real32_T Merge2_m;                   /* '<S209>/Merge2' */
  real32_T Subtract_e;                 /* '<S214>/Subtract' */
  real32_T DataTypeConversion;         /* '<S212>/Data Type Conversion' */
  real32_T Merge_i;                    /* '<S212>/Merge' */
  real32_T Merge1_mx;                  /* '<S212>/Merge1' */
  real32_T Merge1_o;                   /* '<S259>/Merge1' */
  real32_T Merge1_ok;                  /* '<S264>/Merge1' */
  real32_T Sine_g;                     /* '<S263>/Sine' */
  real32_T Cosine;                     /* '<S262>/Cosine' */
  real32_T Sine_i;                     /* '<S262>/Sine' */
  real32_T Sine_b;                     /* '<S261>/Sine' */
  real32_T Cosine_f;                   /* '<S260>/Cosine' */
  real32_T Sine_j;                     /* '<S260>/Sine' */
  real32_T Product1;                   /* '<S245>/Product1' */
  real32_T Merge_c;                    /* '<S247>/Merge' */
  real32_T Sine_cu;                    /* '<S246>/Sine' */
  real32_T DiscreteTimeIntegrator_lp;  /* '<S207>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_ac;  /* '<S203>/Discrete-Time Integrator' */
  real32_T Saturation_l;               /* '<S203>/Saturation' */
  real32_T Gain2_d;                    /* '<S202>/Gain2' */
  real32_T Gain5;                      /* '<S202>/Gain5' */
  real32_T Cosine_n;                   /* '<S86>/Cosine' */
  real32_T Saturation_lm;              /* '<S66>/Saturation' */
  real32_T Divide;                     /* '<S136>/Divide' */
  real32_T DataTypeConversion_m;       /* '<S209>/Data Type Conversion' */
  real32_T Id;                         /* '<S258>/Id' */
  real32_T Id_j;                       /* '<S256>/Id' */
  real32_T Gain1_e;                    /* '<S247>/Gain1' */
  real32_T Add2_f;                     /* '<S191>/Add2' */
  real32_T UnitDelay2_DSTATE;          /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S2>/Unit Delay1' */
  real32_T UnitDelay4_DSTATE;          /* '<S2>/Unit Delay4' */
  real32_T UnitDelay3_DSTATE;          /* '<S2>/Unit Delay3' */
  real32_T UnitDelay6_DSTATE;          /* '<S2>/Unit Delay6' */
  real32_T UnitDelay8_DSTATE;          /* '<S2>/Unit Delay8' */
  real32_T UnitDelay7_DSTATE;          /* '<S2>/Unit Delay7' */
  real32_T UnitDelay9_DSTATE;          /* '<S2>/Unit Delay9' */
  real32_T Lowpassfilter_states;       /* '<S6>/Low pass filter' */
  real32_T Lowpassfilter1_states;      /* '<S6>/Low pass filter1' */
  real32_T UnitDelay1_DSTATE_p;        /* '<S3>/Unit Delay1' */
  real32_T LPF_states;                 /* '<S175>/LPF' */
  real32_T Integrator_DSTATE;          /* '<S118>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S81>/Discrete-Time Integrator' */
  real32_T LPF_states_i;               /* '<S81>/LPF' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S177>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S177>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S177>/Discrete-Time Integrator3' */
  real32_T DiscreteTimeIntegrator1_DSTATE_g;/* '<S176>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_DSTATE_j;/* '<S176>/Discrete-Time Integrator2' */
  real32_T UnitDelay_DSTATE;           /* '<S25>/Unit Delay' */
  real32_T Integrator_DSTATE_m;        /* '<S22>/Integrator' */
  real32_T Integrator1_DSTATE;         /* '<S22>/Integrator1' */
  real32_T Integrator_DSTATE_b;        /* '<S59>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_k;/* '<S10>/Discrete-Time Integrator' */
  real32_T UnitDelay2_DSTATE_p;        /* '<S10>/Unit Delay2' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S137>/Discrete-Time Integrator' */
  real32_T Lowpassfilter_states_n;     /* '<S148>/Low pass filter' */
  real32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S152>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S182>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_j;/* '<S181>/Discrete-Time Integrator' */
  real32_T UnitDelay2_DSTATE_d;        /* '<S183>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_l;        /* '<S183>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE_k0;/* '<S273>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE;               /* '<S208>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S208>/Delay1' */
  real32_T Delay2_DSTATE;              /* '<S208>/Delay2' */
  real32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S209>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE_p;        /* '<S238>/Integrator' */
  real32_T Integrator_DSTATE_n;        /* '<S239>/Integrator' */
  real32_T Integrator_DSTATE_f;        /* '<S226>/Integrator' */
  real32_T Integrator_DSTATE_e;        /* '<S227>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE_j;/* '<S209>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_d;        /* '<S243>/Integrator' */
  real32_T Integrator_DSTATE_dr;       /* '<S242>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_ai;/* '<S220>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_h;             /* '<S221>/Delay' */
  real32_T Lowpassfilter_states_n2;    /* '<S209>/Low pass filter' */
  real32_T Delay_DSTATE_hw;            /* '<S212>/Delay' */
  real32_T Delay1_DSTATE_l;            /* '<S212>/Delay1' */
  real32_T Delay_DSTATE_a;             /* '<S245>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S207>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_jc;/* '<S203>/Discrete-Time Integrator' */
  real32_T Memory_PreviousInput;       /* '<S143>/Memory' */
  real32_T Memory1_PreviousInput;      /* '<S143>/Memory1' */
  real32_T Memory2_PreviousInput;      /* '<S143>/Memory2' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S152>/Discrete-Time Integrator' */
  real32_T Memory_PreviousInput_j;     /* '<S221>/Memory' */
  real32_T Memory_PreviousInput_jp;    /* '<S245>/Memory' */
  real32_T RMS_SqData;                 /* '<S247>/RMS' */
  real32_T RMS1_SqData;                /* '<S247>/RMS1' */
  real32_T RMS2_SqData;                /* '<S247>/RMS2' */
  int32_T Position_Delay_DSTATE;       /* '<S175>/Position_Delay' */
  uint32_T temporalCounter_i1;         /* '<S3>/State_machine' */
  uint32_T temporalCounter_i1_i;       /* '<S11>/Chart' */
  uint32_T Speed_Control_PREV_T;       /* '<S150>/Speed_Control' */
  uint32_T temporalCounter_i1_h;       /* '<S209>/StartRUN_State_machine' */
  uint32_T temporalCounter_i1_m;       /* '<S212>/NS_State_machine' */
  uint32_T RMS_Iteration;              /* '<S247>/RMS' */
  uint32_T RMS1_Iteration;             /* '<S247>/RMS1' */
  uint32_T RMS2_Iteration;             /* '<S247>/RMS2' */
  uint32_T temporalCounter_i1_g;       /* '<S208>/HFI_State_machine' */
  int8_T If2_ActiveSubsystem;          /* '<S3>/If2' */
  int8_T If3_ActiveSubsystem;          /* '<S3>/If3' */
  int8_T If1_ActiveSubsystem_n;        /* '<S150>/If1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S4>/Switch Case' */
  int8_T If1_ActiveSubsystem_c;        /* '<S178>/If1' */
  int8_T If1_ActiveSubsystem_g;        /* '<S180>/If1' */
  int8_T If1_ActiveSubsystem_b;        /* '<S5>/If1' */
  int8_T If1_ActiveSubsystem_cy;       /* '<S189>/If1' */
  int8_T If1_ActiveSubsystem_gn;       /* '<S190>/If1' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S208>/Switch Case1' */
  int8_T Integrator_PrevResetState;    /* '<S238>/Integrator' */
  int8_T Integrator_PrevResetState_n;  /* '<S239>/Integrator' */
  int8_T Integrator_PrevResetState_p;  /* '<S226>/Integrator' */
  int8_T Integrator_PrevResetState_h;  /* '<S227>/Integrator' */
  int8_T Integrator_PrevResetState_j;  /* '<S243>/Integrator' */
  int8_T Integrator_PrevResetState_hd; /* '<S242>/Integrator' */
  uint8_T Motor_state;                 /* '<S3>/State_machine' */
  uint8_T RUN_state;                   /* '<S209>/StartRUN_State_machine' */
  uint8_T NS_state;                    /* '<S212>/NS_State_machine' */
  uint8_T HFI_state;                   /* '<S208>/HFI_State_machine' */
  uint8_T UnitDelay5_DSTATE;           /* '<S2>/Unit Delay5' */
  uint8_T is_active_c5_Motor_Control;  /* '<S3>/State_machine' */
  uint8_T is_c5_Motor_Control;         /* '<S3>/State_machine' */
  uint8_T is_active_c3_Motor_Control;  /* '<S11>/Chart' */
  uint8_T is_c3_Motor_Control;         /* '<S11>/Chart' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE;/* '<S152>/Discrete-Time Integrator' */
  uint8_T is_active_c6_Motor_Control;  /* '<S209>/StartRUN_State_machine' */
  uint8_T is_c6_Motor_Control;         /* '<S209>/StartRUN_State_machine' */
  uint8_T is_active_c8_Motor_Control;  /* '<S212>/NS_State_machine' */
  uint8_T is_c8_Motor_Control;         /* '<S212>/NS_State_machine' */
  uint8_T is_active_c7_Motor_Control;  /* '<S208>/HFI_State_machine' */
  uint8_T is_c7_Motor_Control;         /* '<S208>/HFI_State_machine' */
  boolean_T Merge_cb;                  /* '<S3>/Merge' */
  boolean_T UnitDelay3_DSTATE_k;       /* '<S152>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_k4;      /* '<S182>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_j;       /* '<S181>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_o;       /* '<S273>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_c;       /* '<S207>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_k2;      /* '<S203>/Unit Delay3' */
  boolean_T Speed_Control_RESET_ELAPS_T;/* '<S150>/Speed_Control' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ACC_OMG_Trig_ZCE[3];      /* '<S11>/ACC_OMG' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: uDLookupTable4_tableData
   * Referenced by: '<S185>/1-D Lookup Table4'
   */
  real32_T uDLookupTable4_tableData[201];

  /* Computed Parameter: uDLookupTable5_tableData
   * Referenced by: '<S185>/1-D Lookup Table5'
   */
  real32_T uDLookupTable5_tableData[201];

  /* Pooled Parameter (Expression: [0 0 0 1 1 0;0 1 1 0 0 0;0 1 0 0 0 1;1 0 0 0 1 0;1 0 1 0 0 0;0 0 0 1 0 1])
   * Referenced by:
   *   '<S166>/Direct Lookup Table (n-D)2'
   *   '<S167>/Direct Lookup Table (n-D)2'
   *   '<S151>/Direct Lookup Table (n-D)2'
   */
  real32_T pooled21[36];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S183>/Constant4'
   *   '<S22>/Integrator'
   *   '<S22>/Integrator1'
   *   '<S81>/Discrete-Time Integrator'
   *   '<S137>/Discrete-Time Integrator'
   *   '<S138>/Constant6'
   *   '<S176>/Discrete-Time Integrator1'
   *   '<S176>/Discrete-Time Integrator2'
   *   '<S177>/Discrete-Time Integrator1'
   *   '<S177>/Discrete-Time Integrator2'
   *   '<S177>/Discrete-Time Integrator3'
   *   '<S196>/Saturation'
   *   '<S24>/Saturation'
   *   '<S25>/Ts'
   *   '<S86>/Saturation'
   *   '<S142>/Saturation'
   *   '<S203>/Discrete-Time Integrator'
   *   '<S273>/Discrete-Time Integrator'
   *   '<S209>/Discrete-Time Integrator'
   *   '<S209>/Discrete-Time Integrator1'
   *   '<S59>/Integrator'
   *   '<S118>/Integrator'
   *   '<S152>/Discrete-Time Integrator'
   *   '<S207>/Discrete-Time Integrator'
   *   '<S220>/Discrete-Time Integrator'
   *   '<S226>/Integrator'
   *   '<S227>/Integrator'
   *   '<S238>/Integrator'
   *   '<S239>/Integrator'
   *   '<S242>/Integrator'
   *   '<S243>/Integrator'
   */
  real32_T pooled30;

  /* Pooled Parameter (Expression: Cosine_table)
   * Referenced by:
   *   '<S196>/Cosine'
   *   '<S24>/Cosine'
   *   '<S86>/Cosine'
   *   '<S142>/Cosine'
   *   '<S246>/Cosine'
   *   '<S244>/Cosine'
   *   '<S260>/Cosine'
   *   '<S261>/Cosine'
   *   '<S262>/Cosine'
   *   '<S263>/Cosine'
   *   '<S267>/Cosine'
   */
  real32_T pooled31[4096];

  /* Pooled Parameter (Expression: Sine_table)
   * Referenced by:
   *   '<S196>/Sine'
   *   '<S24>/Sine'
   *   '<S86>/Sine'
   *   '<S142>/Sine'
   *   '<S221>/Sine'
   *   '<S246>/Sine'
   *   '<S244>/Sine'
   *   '<S260>/Sine'
   *   '<S261>/Sine'
   *   '<S262>/Sine'
   *   '<S263>/Sine'
   *   '<S267>/Sine'
   */
  real32_T pooled33[4096];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Speed_target;               /* '<Root>/Speed_target' */
  real32_T Phase_CurrentABC[3];        /* '<Root>/Phase_CurrentABC' */
  real32_T Angle_Theta_e;              /* '<Root>/Angle_Theta' */
  real32_T Resolver_signal[2];         /* '<Root>/Resolver_SinCos' */
  uint8_T Hall_ABC[3];                 /* '<Root>/Hall' */
  real32_T Timer_Cnt;                  /* '<Root>/Timer_counter' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Ta;                         /* '<Root>/Ta' */
  real32_T Tb;                         /* '<Root>/Tb' */
  real32_T Tc;                         /* '<Root>/Tc' */
  real32_T Duty;                       /* '<Root>/Duty' */
  real32_T Gate[6];                    /* '<Root>/Gate' */
  uint8_T BLDC_State;                  /* '<Root>/BLDC_State' */
  real32_T HFI_Theta;                  /* '<Root>/HFI_Theta' */
  uint8_T RUN_State;                   /* '<Root>/RUN_State' */
  real32_T HFI_Speed;                  /* '<Root>/HFI_Speed' */
  real32_T FOC_Theta;                  /* '<Root>/FOC_Theta' */
  real32_T Force_Theta;                /* '<Root>/Force_Theta' */
  real32_T Ubeta_Ealpha[2];            /* '<Root>/Ubeta_Ealpha' */
  real32_T Wn_est;                     /* '<Root>/Wn_est' */
  real32_T Speed_Mes;                  /* '<Root>/Speed_Mes' */
  real32_T Id;                         /* '<Root>/Id' */
  real32_T SMO_Angle;                  /* '<Root>/SMO_Angle' */
  real32_T Iq;                         /* '<Root>/Iq' */
  real32_T Hall_Angle;                 /* '<Root>/Hall_Angle' */
  real32_T Hall_Speed;                 /* '<Root>/Hall_Speed' */
  real32_T Vd;                         /* '<Root>/Vd' */
  real32_T Vq;                         /* '<Root>/Vq' */
  real32_T Motor_Power;                /* '<Root>/Motor_Power' */
  real32_T Motor_Torque;               /* '<Root>/Motor_Torque' */
  real32_T Flux_Speed;                 /* '<Root>/Flux_Speed' */
  real32_T Flux_Angle;                 /* '<Root>/Flux_Angle' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    struct {
      uint8_T TID[3];
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
extern real32_T Speed_RPM;             /* '<S81>/Gain' */
extern real32_T Angle_Theta;           /* '<S81>/Math Function' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern HFI_STRUCT HFI;                 /* Variable: HFI
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
extern CTRLPARAMS_STRUCT ctrlParamsPI; /* Variable: ctrlParamsPI
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
extern Hall_STRUCT Hall_Parameter;     /* Variable: Hall_Parameter
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
extern SMOParam_STRUCT SMO;            /* Variable: SMO
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
extern CLParam_STRUCT CL_Param;        /* Variable: CL_Param
                                        * Referenced by:
                                        *   '<S2>/Control_Mode'
                                        *   '<S4>/IQ_Command'
                                        */
extern OPLParam_STRUCT OPL_Param;      /* Variable: OPL_Param
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
extern Fluxweak_STRUCT Flux_weak;      /* Variable: Flux_weak
                                        * Referenced by:
                                        *   '<S183>/Constant1'
                                        *   '<S207>/Ki'
                                        *   '<S207>/Kp'
                                        *   '<S207>/Saturation'
                                        */
extern FluxObsever_STRUCT FluxObsever; /* Variable: FluxObsever
                                        * Referenced by:
                                        *   '<S3>/Flux_Obsever'
                                        *   '<S12>/Sensorless_Enable1'
                                        *   '<S20>/Constant'
                                        *   '<S20>/Gain'
                                        */
extern Resolver_STRUCT Resolver_Parameter;/* Variable: Resolver_Parameter
                                           * Referenced by:
                                           *   '<S3>/Dir_Angle_Enable'
                                           *   '<S3>/PLL_Enable'
                                           *   '<S12>/Resolver_Enable'
                                           *   '<S12>/Resolver_PLL_Enable'
                                           *   '<S80>/Angle_offset'
                                           */

/* Model entry point functions */
extern void Motor_Control_initialize(void);
extern void Motor_Control_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S24>/Scope' : Unused code path elimination
 * Block '<S81>/Scope' : Unused code path elimination
 * Block '<S81>/Scope1' : Unused code path elimination
 * Block '<S81>/Scope2' : Unused code path elimination
 * Block '<S81>/Scope3' : Unused code path elimination
 * Block '<S81>/Scope4' : Unused code path elimination
 * Block '<S81>/Scope5' : Unused code path elimination
 * Block '<S81>/Scope6' : Unused code path elimination
 * Block '<S81>/Scope7' : Unused code path elimination
 * Block '<S86>/Scope' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S9>/Scope1' : Unused code path elimination
 * Block '<S142>/Scope' : Unused code path elimination
 * Block '<S10>/Gain5' : Unused code path elimination
 * Block '<S10>/LPF' : Unused code path elimination
 * Block '<S137>/Scope' : Unused code path elimination
 * Block '<S138>/Display' : Unused code path elimination
 * Block '<S10>/Scop  e3' : Unused code path elimination
 * Block '<S10>/Scop  e4' : Unused code path elimination
 * Block '<S10>/Scop  e5' : Unused code path elimination
 * Block '<S10>/Scope1' : Unused code path elimination
 * Block '<S10>/Scope2' : Unused code path elimination
 * Block '<S10>/Scope3' : Unused code path elimination
 * Block '<S10>/Scope5' : Unused code path elimination
 * Block '<S10>/Scope7' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<S3>/Scope3' : Unused code path elimination
 * Block '<S3>/Scope4' : Unused code path elimination
 * Block '<S3>/Scope5' : Unused code path elimination
 * Block '<S151>/Scope' : Unused code path elimination
 * Block '<S150>/Scope3' : Unused code path elimination
 * Block '<S152>/Scope' : Unused code path elimination
 * Block '<S148>/Scope' : Unused code path elimination
 * Block '<S143>/Scope1' : Unused code path elimination
 * Block '<S143>/Scope17' : Unused code path elimination
 * Block '<S143>/Scope2' : Unused code path elimination
 * Block '<S143>/Scope3' : Unused code path elimination
 * Block '<S143>/Scope4' : Unused code path elimination
 * Block '<S143>/Scope5' : Unused code path elimination
 * Block '<S149>/Scope' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S166>/Scope' : Unused code path elimination
 * Block '<S167>/Scope' : Unused code path elimination
 * Block '<S13>/Scope' : Unused code path elimination
 * Block '<S13>/Scope1' : Unused code path elimination
 * Block '<S175>/Scope1' : Unused code path elimination
 * Block '<S175>/Scope7' : Unused code path elimination
 * Block '<S14>/Scope3' : Unused code path elimination
 * Block '<S176>/Scope' : Unused code path elimination
 * Block '<S176>/Scope1' : Unused code path elimination
 * Block '<S176>/Scope2' : Unused code path elimination
 * Block '<S176>/Scope3' : Unused code path elimination
 * Block '<S178>/Scope2' : Unused code path elimination
 * Block '<S181>/Scope' : Unused code path elimination
 * Block '<S187>/Scope' : Unused code path elimination
 * Block '<S209>/Scope' : Unused code path elimination
 * Block '<S209>/Scope1' : Unused code path elimination
 * Block '<S209>/Scope10' : Unused code path elimination
 * Block '<S209>/Scope2' : Unused code path elimination
 * Block '<S209>/Scope3' : Unused code path elimination
 * Block '<S209>/Scope4' : Unused code path elimination
 * Block '<S209>/Scope5' : Unused code path elimination
 * Block '<S209>/Scope6' : Unused code path elimination
 * Block '<S209>/Scope7' : Unused code path elimination
 * Block '<S209>/Scope8' : Unused code path elimination
 * Block '<S209>/Scope9' : Unused code path elimination
 * Block '<S244>/Scope' : Unused code path elimination
 * Block '<S211>/Scope' : Unused code path elimination
 * Block '<S246>/Scope' : Unused code path elimination
 * Block '<S247>/Display1' : Unused code path elimination
 * Block '<S247>/Display2' : Unused code path elimination
 * Block '<S247>/Display3' : Unused code path elimination
 * Block '<S247>/Display6' : Unused code path elimination
 * Block '<S247>/Scope1' : Unused code path elimination
 * Block '<S247>/Scope2' : Unused code path elimination
 * Block '<S212>/Scope1' : Unused code path elimination
 * Block '<S260>/Scope' : Unused code path elimination
 * Block '<S261>/Scope' : Unused code path elimination
 * Block '<S262>/Scope' : Unused code path elimination
 * Block '<S263>/Scope' : Unused code path elimination
 * Block '<S267>/Scope' : Unused code path elimination
 * Block '<S276>/Scope2' : Unused code path elimination
 * Block '<S183>/Scope1' : Unused code path elimination
 * Block '<S183>/Scope2' : Unused code path elimination
 * Block '<S183>/Scope4' : Unused code path elimination
 * Block '<S183>/Scope6' : Unused code path elimination
 * Block '<S183>/Scope7' : Unused code path elimination
 * Block '<S196>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope2' : Unused code path elimination
 * Block '<S6>/Scope3' : Unused code path elimination
 * Block '<S6>/Scope4' : Unused code path elimination
 * Block '<S81>/pole pairs ' : Eliminated nontunable gain of 1
 * Block '<S10>/Gain2' : Eliminated nontunable gain of 1
 * Block '<S137>/Saturation' : Eliminated Saturate block
 * Block '<S143>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S143>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S143>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S144>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S226>/Saturation' : Eliminated Saturate block
 * Block '<S227>/Saturation' : Eliminated Saturate block
 * Block '<S238>/Saturation' : Eliminated Saturate block
 * Block '<S239>/Saturation' : Eliminated Saturate block
 * Block '<S242>/Saturation' : Eliminated Saturate block
 * Block '<S243>/Saturation' : Eliminated Saturate block
 * Block '<S220>/Zero-Order Hold' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('PMSM_FOC_Traction/Motor_Control')    - opens subsystem PMSM_FOC_Traction/Motor_Control
 * hilite_system('PMSM_FOC_Traction/Motor_Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PMSM_FOC_Traction'
 * '<S1>'   : 'PMSM_FOC_Traction/Motor_Control'
 * '<S2>'   : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion'
 * '<S3>'   : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us'
 * '<S4>'   : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Control_Command_2ms'
 * '<S5>'   : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us'
 * '<S6>'   : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Motor_State_10ms'
 * '<S7>'   : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Angle_Selector'
 * '<S8>'   : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER'
 * '<S9>'   : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer'
 * '<S10>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SMO'
 * '<S11>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle'
 * '<S12>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Speed_Angle_Selector'
 * '<S13>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Speed_Resolver'
 * '<S14>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Startup_OPL'
 * '<S15>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/State_machine'
 * '<S16>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Subsystem'
 * '<S17>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Subsystem1'
 * '<S18>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Angle_Selector/Subsystem'
 * '<S19>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Angle_Selector/Subsystem1'
 * '<S20>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12'
 * '<S21>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.6'
 * '<S22>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.9'
 * '<S23>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller'
 * '<S24>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Sine_Cosine'
 * '<S25>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/integrator'
 * '<S26>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Anti-windup'
 * '<S27>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/D Gain'
 * '<S28>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Filter'
 * '<S29>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Filter ICs'
 * '<S30>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/I Gain'
 * '<S31>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Ideal P Gain'
 * '<S32>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S33>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Integrator'
 * '<S34>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Integrator ICs'
 * '<S35>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/N Copy'
 * '<S36>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/N Gain'
 * '<S37>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/P Copy'
 * '<S38>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Parallel P Gain'
 * '<S39>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Reset Signal'
 * '<S40>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Saturation'
 * '<S41>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Saturation Fdbk'
 * '<S42>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Sum'
 * '<S43>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Sum Fdbk'
 * '<S44>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Tracking Mode'
 * '<S45>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Tracking Mode Sum'
 * '<S46>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Tsamp - Integral'
 * '<S47>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Tsamp - Ngain'
 * '<S48>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/postSat Signal'
 * '<S49>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/preSat Signal'
 * '<S50>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S51>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S52>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S53>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/D Gain/Disabled'
 * '<S54>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Filter/Disabled'
 * '<S55>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Filter ICs/Disabled'
 * '<S56>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/I Gain/External Parameters'
 * '<S57>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S58>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S59>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Integrator/Discrete'
 * '<S60>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S61>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S62>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/N Gain/Disabled'
 * '<S63>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/P Copy/Disabled'
 * '<S64>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S65>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Reset Signal/Disabled'
 * '<S66>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Saturation/Enabled'
 * '<S67>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S68>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Sum/Sum_PI'
 * '<S69>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S70>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S71>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S72>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S73>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S74>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S75>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S76>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/integrator/RangeLimit'
 * '<S77>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/integrator/RangeLimit/If Action Subsystem'
 * '<S78>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/integrator/RangeLimit/If Action Subsystem1'
 * '<S79>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Flux_OBSERVER/equ3.12/integrator/RangeLimit/If Action Subsystem2'
 * '<S80>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Angle_calibration'
 * '<S81>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl'
 * '<S82>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Angle_calibration/If Action Subsystem1'
 * '<S83>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Angle_calibration/If Action Subsystem2'
 * '<S84>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Angle_calibration/If Action Subsystem3'
 * '<S85>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller'
 * '<S86>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/Sine_Cosine'
 * '<S87>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Anti-windup'
 * '<S88>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/D Gain'
 * '<S89>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Filter'
 * '<S90>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Filter ICs'
 * '<S91>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/I Gain'
 * '<S92>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Ideal P Gain'
 * '<S93>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Ideal P Gain Fdbk'
 * '<S94>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Integrator'
 * '<S95>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Integrator ICs'
 * '<S96>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/N Copy'
 * '<S97>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/N Gain'
 * '<S98>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/P Copy'
 * '<S99>'  : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Parallel P Gain'
 * '<S100>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Reset Signal'
 * '<S101>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Saturation'
 * '<S102>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Saturation Fdbk'
 * '<S103>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Sum'
 * '<S104>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Sum Fdbk'
 * '<S105>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tracking Mode'
 * '<S106>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tracking Mode Sum'
 * '<S107>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tsamp - Integral'
 * '<S108>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tsamp - Ngain'
 * '<S109>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/postSat Signal'
 * '<S110>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/preSat Signal'
 * '<S111>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Anti-windup/Passthrough'
 * '<S112>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/D Gain/Disabled'
 * '<S113>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Filter/Disabled'
 * '<S114>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Filter ICs/Disabled'
 * '<S115>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/I Gain/Internal Parameters'
 * '<S116>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Ideal P Gain/Passthrough'
 * '<S117>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S118>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Integrator/Discrete'
 * '<S119>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Integrator ICs/Internal IC'
 * '<S120>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S121>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/N Gain/Disabled'
 * '<S122>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/P Copy/Disabled'
 * '<S123>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S124>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Reset Signal/Disabled'
 * '<S125>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Saturation/Passthrough'
 * '<S126>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Saturation Fdbk/Disabled'
 * '<S127>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Sum/Sum_PI'
 * '<S128>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Sum Fdbk/Disabled'
 * '<S129>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tracking Mode/Disabled'
 * '<S130>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S131>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tsamp - Integral/Passthrough'
 * '<S132>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S133>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/postSat Signal/Forward_Path'
 * '<S134>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/preSat Signal/Forward_Path'
 * '<S135>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SMO/Angle_calibration'
 * '<S136>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SMO/Delta_theta'
 * '<S137>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SMO/PLL_PI'
 * '<S138>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SMO/SMO_Fuction'
 * '<S139>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SMO/Angle_calibration/If Action Subsystem1'
 * '<S140>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SMO/Angle_calibration/If Action Subsystem2'
 * '<S141>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SMO/Angle_calibration/If Action Subsystem3'
 * '<S142>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SMO/Delta_theta/Sine_Cosine'
 * '<S143>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG'
 * '<S144>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ'
 * '<S145>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/Chart'
 * '<S146>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/Subsystem'
 * '<S147>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/Subsystem1'
 * '<S148>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/BLDC'
 * '<S149>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point'
 * '<S150>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/BLDC/Control'
 * '<S151>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/BLDC/Control/Commutation'
 * '<S152>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/BLDC/Control/Speed_Control'
 * '<S153>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/BLDC/Control/Commutation/Bit concatenate'
 * '<S154>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_1'
 * '<S155>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_2'
 * '<S156>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_3'
 * '<S157>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_4'
 * '<S158>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_5'
 * '<S159>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_6'
 * '<S160>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration'
 * '<S161>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration/If Action Subsystem1'
 * '<S162>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration/If Action Subsystem2'
 * '<S163>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration/If Action Subsystem3'
 * '<S164>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/Subsystem/Subsystem'
 * '<S165>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/Subsystem/Subsystem1'
 * '<S166>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/Subsystem/Subsystem/Commutation'
 * '<S167>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/Subsystem/Subsystem1/Commutation'
 * '<S168>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/Subsystem/Subsystem1/Commutation/Bit concatenate'
 * '<S169>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/Subsystem1/Subsystem'
 * '<S170>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/SpeedAndAngle/Subsystem1/Subsystem1'
 * '<S171>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Speed_Angle_Selector/Hall'
 * '<S172>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Speed_Angle_Selector/Resolver_Dir'
 * '<S173>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Speed_Angle_Selector/Resolver_PLL'
 * '<S174>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Speed_Angle_Selector/Sensorless'
 * '<S175>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Speed_Resolver/Speed_cacl'
 * '<S176>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Startup_OPL/Subsystem'
 * '<S177>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Angle_Speed_100us/Startup_OPL/Subsystem1'
 * '<S178>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Control_Command_2ms/Speed_PI'
 * '<S179>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Control_Command_2ms/Switch Case Action Subsystem'
 * '<S180>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Control_Command_2ms/Speed_PI/Speed_PI'
 * '<S181>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Control_Command_2ms/Speed_PI/Speed_PI/Speed_Control'
 * '<S182>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Control_Command_2ms/Speed_PI/Speed_PI/Speed_Control1'
 * '<S183>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC'
 * '<S184>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/Iq_selector'
 * '<S185>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/MTPA'
 * '<S186>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Angle_set'
 * '<S187>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Clarke_Transform'
 * '<S188>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/D_Current_PI'
 * '<S189>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Flux_weakening '
 * '<S190>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer'
 * '<S191>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Inverse_Park_Transform'
 * '<S192>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Park_Transform'
 * '<S193>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Q_Current_PI'
 * '<S194>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/SVPWM'
 * '<S195>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Set_Idq'
 * '<S196>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Sine_Cosine'
 * '<S197>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Subsystem1'
 * '<S198>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Angle_set/Subsystem'
 * '<S199>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Angle_set/Subsystem1'
 * '<S200>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Angle_set/Subsystem/Subsystem1'
 * '<S201>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Angle_set/Subsystem/Subsystem2'
 * '<S202>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Clarke_Transform/Clark1'
 * '<S203>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/D_Current_PI/ID_Control'
 * '<S204>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Flux_weakening /Subsystem'
 * '<S205>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Flux_weakening /Subsystem1'
 * '<S206>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Flux_weakening /Subsystem/Flux_weak'
 * '<S207>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Flux_weakening /Subsystem/Flux_weak/ID_Control'
 * '<S208>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function'
 * '<S209>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI'
 * '<S210>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI_State_machine'
 * '<S211>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD'
 * '<S212>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS'
 * '<S213>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HFI_Angle'
 * '<S214>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HFI_Angle1'
 * '<S215>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HPF'
 * '<S216>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle'
 * '<S217>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle1'
 * '<S218>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF1'
 * '<S219>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF2'
 * '<S220>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/PI Controller'
 * '<S221>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/Sine_function'
 * '<S222>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/StartRUN_State_machine'
 * '<S223>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/Subsystem'
 * '<S224>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HPF/Integrator (Discrete or Continuous)'
 * '<S225>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HPF/Integrator (Discrete or Continuous)1'
 * '<S226>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HPF/Integrator (Discrete or Continuous)/Discrete'
 * '<S227>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/HPF/Integrator (Discrete or Continuous)1/Discrete'
 * '<S228>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle/Angle_calibration'
 * '<S229>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle/Angle_calibration/If Action Subsystem1'
 * '<S230>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle/Angle_calibration/If Action Subsystem2'
 * '<S231>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle/Angle_calibration/If Action Subsystem3'
 * '<S232>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle1/Angle_calibration'
 * '<S233>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle1/Angle_calibration/If Action Subsystem1'
 * '<S234>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle1/Angle_calibration/If Action Subsystem2'
 * '<S235>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/IPD_Angle1/Angle_calibration/If Action Subsystem3'
 * '<S236>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF1/Integrator (Discrete or Continuous)'
 * '<S237>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF1/Integrator (Discrete or Continuous)1'
 * '<S238>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF1/Integrator (Discrete or Continuous)/Discrete'
 * '<S239>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF1/Integrator (Discrete or Continuous)1/Discrete'
 * '<S240>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF2/Integrator (Discrete or Continuous)'
 * '<S241>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF2/Integrator (Discrete or Continuous)1'
 * '<S242>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF2/Integrator (Discrete or Continuous)/Discrete'
 * '<S243>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/LPF2/Integrator (Discrete or Continuous)1/Discrete'
 * '<S244>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/HFI/Subsystem/Sine_Cosine'
 * '<S245>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/HF_Angle'
 * '<S246>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Sine_Cosine'
 * '<S247>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl'
 * '<S248>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem1'
 * '<S249>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem2'
 * '<S250>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem3'
 * '<S251>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem4'
 * '<S252>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem5'
 * '<S253>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/IPD/Theta_cacl/If Action Subsystem6'
 * '<S254>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/NS_State_machine'
 * '<S255>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_1'
 * '<S256>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_2'
 * '<S257>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_3'
 * '<S258>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_4'
 * '<S259>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5'
 * '<S260>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_1/Sine_Cosine'
 * '<S261>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_2/Sine_Cosine'
 * '<S262>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_3/Sine_Cosine'
 * '<S263>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_4/Sine_Cosine'
 * '<S264>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_4/Theta_limit'
 * '<S265>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_4/Theta_limit/If Action Subsystem1'
 * '<S266>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_4/Theta_limit/If Action Subsystem2'
 * '<S267>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Sine_Cosine'
 * '<S268>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Subsystem'
 * '<S269>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Subsystem1'
 * '<S270>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Subsystem1/Theta_limit'
 * '<S271>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Subsystem1/Theta_limit/If Action Subsystem1'
 * '<S272>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/HF_Observer/HFI_Function/NS/Ud_inject_5/Subsystem1/Theta_limit/If Action Subsystem2'
 * '<S273>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control'
 * '<S274>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/SVPWM/N Sector  Caculate'
 * '<S275>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/SVPWM/T1 T2  Caculate'
 * '<S276>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/SVPWM/Tcm calculate'
 * '<S277>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/SVPWM/XYZ Caculate'
 * '<S278>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Set_Idq/Set_Idq'
 * '<S279>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Set_Idq/Set_Idq1'
 * '<S280>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Subsystem1/If Action Subsystem1'
 * '<S281>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/FOC/Subsystem1/If Action Subsystem2'
 * '<S282>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/Iq_selector/Subsystem'
 * '<S283>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/FOC_Control_100us/Iq_selector/Subsystem1'
 * '<S284>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Motor_State_10ms/Power_Cacl'
 * '<S285>' : 'PMSM_FOC_Traction/Motor_Control/Motor_Control_Funtion/Motor_State_10ms/Torque_Cacl'
 */
#endif                                 /* RTW_HEADER_Motor_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
