/*
 * File: Motor_Control.h
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 18 17:48:38 2021
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
  real32_T UnitDelay2;                 /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1;                 /* '<S2>/Unit Delay1' */
  real32_T UnitDelay3;                 /* '<S2>/Unit Delay3' */
  real32_T UnitDelay4;                 /* '<S2>/Unit Delay4' */
  real32_T Timer_Counter;              /* '<S9>/Timer_Counter' */
  real32_T Gain2;                      /* '<S9>/Gain2' */
  real32_T a;                          /* '<S9>/Divide1' */
  real32_T Merge2;                     /* '<S12>/Merge2' */
  real32_T Merge;                      /* '<S26>/Merge' */
  real32_T DiscreteTimeIntegrator;     /* '<S30>/Discrete-Time Integrator' */
  real32_T UnitDelay1_c;               /* '<S33>/Unit Delay1' */
  real32_T Merge2_f;                   /* '<S33>/Merge2' */
  real32_T Merge_g;                    /* '<S33>/Merge' */
  real32_T Merge1;                     /* '<S33>/Merge1' */
  real32_T Merge_c;                    /* '<S45>/Merge' */
  real32_T Merge1_h;                   /* '<S45>/Merge1' */
  real32_T Merge2_d;                   /* '<S45>/Merge2' */
  real32_T UnitDelay;                  /* '<S60>/Unit Delay' */
  real32_T Sine;                       /* '<S59>/Sine' */
  real32_T Cosine;                     /* '<S59>/Cosine' */
  real32_T speed_hat;                  /* '<S57>/Unit Delay' */
  real32_T UnitDelay2_DSTATE;          /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S2>/Unit Delay1' */
  real32_T UnitDelay3_DSTATE;          /* '<S2>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE;          /* '<S2>/Unit Delay4' */
  real32_T UnitDelay6_DSTATE;          /* '<S2>/Unit Delay6' */
  real32_T UnitDelay5_DSTATE;          /* '<S2>/Unit Delay5' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S30>/Discrete-Time Integrator' */
  real32_T UnitDelay1_DSTATE_d;        /* '<S33>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE_k;        /* '<S33>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_n;         /* '<S40>/Unit Delay' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S42>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S42>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S118>/Discrete-Time Integrator' */
  real32_T UnitDelay2_DSTATE_e;        /* '<S55>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE_j;        /* '<S56>/Unit Delay3' */
  real32_T UnitDelay_DSTATE_f;         /* '<S53>/Unit Delay' */
  real32_T UnitDelay_DSTATE_p;         /* '<S57>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_f;        /* '<S54>/Unit Delay1' */
  real32_T Integrator1_DSTATE;         /* '<S54>/Integrator1' */
  real32_T Integrator3_DSTATE;         /* '<S56>/Integrator3' */
  real32_T Integrator_DSTATE;          /* '<S53>/Integrator' */
  real32_T Integrator2_DSTATE;         /* '<S55>/Integrator2' */
  real32_T UnitDelay_DSTATE_h;         /* '<S60>/Unit Delay' */
  real32_T Integrator_DSTATE_d;        /* '<S95>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S49>/Discrete-Time Integrator' */
  real32_T Memory_PreviousInput;       /* '<S9>/Memory' */
  real32_T Memory1_PreviousInput;      /* '<S9>/Memory1' */
  real32_T Memory2_PreviousInput;      /* '<S9>/Memory2' */
  uint32_T temporalCounter_i1;         /* '<S33>/Chart' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S25>/Switch Case' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S30>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p;/* '<S118>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_pb;/* '<S49>/Discrete-Time Integrator' */
  uint8_T Merge1_a;                    /* '<S6>/Merge1' */
  uint8_T Integrator1_SYSTEM_ENABLE;   /* '<S54>/Integrator1' */
  uint8_T Integrator3_SYSTEM_ENABLE;   /* '<S56>/Integrator3' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S53>/Integrator' */
  uint8_T Integrator2_SYSTEM_ENABLE;   /* '<S55>/Integrator2' */
  uint8_T is_active_c3_Motor_Control;  /* '<S33>/Chart' */
  uint8_T is_c3_Motor_Control;         /* '<S33>/Chart' */
  boolean_T UnitDelay3_DSTATE_m;       /* '<S30>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_i;       /* '<S118>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_k;       /* '<S49>/Unit Delay3' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ACC_OMG_Trig_ZCE[3];      /* '<S7>/ACC_OMG' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: Cosine_table)
   * Referenced by:
   *   '<S46>/Cosine'
   *   '<S59>/Cosine'
   */
  real32_T pooled10[4096];

  /* Pooled Parameter (Expression: Sine_table)
   * Referenced by:
   *   '<S46>/Sine'
   *   '<S59>/Sine'
   */
  real32_T pooled12[4096];
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
                                        * '<S49>/Over_modulation'
                                        * '<S118>/Over_modulation'
                                        */
  uint8_T Angle;                       /* Referenced by: '<S2>/Select_Angle' */
  uint8_T TorqueMode;                  /* Referenced by: '<S2>/Control_Mode' */
} CTL_Parameter_type;

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

typedef struct OPL_Parameter_tag {
  real32_T OPL_Speed;                  /* Referenced by: '<S33>/Constant1' */
  real32_T OPL_Time;                   /* Referenced by:
                                        * '<S33>/Constant3'
                                        * '<S33>/Constant6'
                                        */
  real32_T OPL_Torque;                 /* Referenced by: '<S33>/Constant2' */
} OPL_Parameter_type;

typedef struct PI_Parameter_tag {
  real32_T ID_Ki;                      /* Referenced by: '<S49>/Ki' */
  real32_T ID_Kp;                      /* Referenced by: '<S49>/Kp' */
  real32_T IQ_Ki;                      /* Referenced by: '<S118>/Ki' */
  real32_T IQ_Kp;                      /* Referenced by: '<S118>/Kp' */
  real32_T Speed_Ki;                   /* Referenced by: '<S30>/Ki' */
  real32_T Speed_Kp;                   /* Referenced by: '<S30>/Kp' */
  real32_T Speed_PI_OutputMax;         /* Referenced by: '<S30>/Saturation' */
  real32_T Speed_PI_OutputMin;         /* Referenced by: '<S30>/Saturation' */
} PI_Parameter_type;

typedef struct SMO_Parameter_tag {
  real32_T SMO_K;                      /* Referenced by:
                                        * '<S53>/Gain4'
                                        * '<S54>/Gain6'
                                        * '<S56>/Gain10'
                                        */
  real32_T SMO_M;                      /* Referenced by: '<S55>/Gain9' */
  real32_T SMO_PLL_W;                  /* Referenced by:
                                        * '<S57>/Ki'
                                        * '<S57>/Kp'
                                        */
  uint8_T SMO_Theta_Enable;            /* Referenced by:
                                        * '<S26>/Flux_Enable'
                                        * '<S33>/Flux_Enable'
                                        */
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
extern real32_T Obs_Speed;             /* '<S2>/Unit Delay6' */
extern real32_T Obs_Theta;             /* '<S2>/Unit Delay5' */
extern real32_T Motor_Power;           /* '<S130>/Add1' */
extern real32_T Motor_Torque;          /* '<S131>/Add1' */
extern real32_T Hall_Angle;            /* '<S19>/Merge1' */
extern real32_T Hall_Speed;            /* '<S11>/Add1' */
extern real32_T Id_ref;                /* '<S4>/Constant' */
extern real32_T Iq_ref;                /* '<S25>/Merge' */
extern real32_T Vq_voltage;            /* '<S121>/Switch2' */
extern real32_T Id_measured;           /* '<S43>/Add1' */
extern real32_T Iq_measured;           /* '<S43>/Add2' */
extern real32_T V_alpha;               /* '<S39>/Add' */
extern real32_T V_beta;                /* '<S39>/Add3' */
extern real32_T Vd_voltage;            /* '<S52>/Switch2' */
extern real32_T Ialpha;                /* '<S48>/Gain2' */
extern real32_T Ibeta;                 /* '<S48>/Gain5' */

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
                                        *   '<S40>/Constant1'
                                        *   '<S11>/Constant1'
                                        */

/* Model entry point functions */
extern void Motor_Control_initialize(void);
extern void Motor_Control_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern CTL_Parameter_type CTL_Parameter;
extern Hall_Parameter_type Hall_Parameter;
extern OPL_Parameter_type OPL_Parameter;
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
 * Block '<S8>/DT2' : Unused code path elimination
 * Block '<S23>/Constant' : Unused code path elimination
 * Block '<S23>/Constant1' : Unused code path elimination
 * Block '<S23>/Difference_Wrap' : Unused code path elimination
 * Block '<S23>/Difference_to_Single' : Unused code path elimination
 * Block '<S23>/Difference_to_Single1' : Unused code path elimination
 * Block '<S23>/Gain' : Unused code path elimination
 * Block '<S24>/Add' : Unused code path elimination
 * Block '<S24>/Add1' : Unused code path elimination
 * Block '<S24>/Constant1' : Unused code path elimination
 * Block '<S24>/Divide1' : Unused code path elimination
 * Block '<S24>/Unit Delay' : Unused code path elimination
 * Block '<S23>/Position_Delay' : Unused code path elimination
 * Block '<S23>/Product' : Unused code path elimination
 * Block '<S23>/Product1' : Unused code path elimination
 * Block '<S23>/Scale_Input' : Unused code path elimination
 * Block '<S23>/Scope' : Unused code path elimination
 * Block '<S23>/Wrap_To_Pi' : Unused code path elimination
 * Block '<S30>/Scope' : Unused code path elimination
 * Block '<S35>/Scope' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Propagation' : Unused code path elimination
 * Block '<S57>/Scope' : Unused code path elimination
 * Block '<S59>/Scope' : Unused code path elimination
 * Block '<S39>/Scope' : Unused code path elimination
 * Block '<S42>/Scope' : Unused code path elimination
 * Block '<S42>/Scope1' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Propagation' : Unused code path elimination
 * Block '<S126>/Scope2' : Unused code path elimination
 * Block '<S33>/Scope' : Unused code path elimination
 * Block '<S33>/Scope1' : Unused code path elimination
 * Block '<S33>/Scope2' : Unused code path elimination
 * Block '<S33>/Scope3' : Unused code path elimination
 * Block '<S33>/Scope4' : Unused code path elimination
 * Block '<S46>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope2' : Unused code path elimination
 * Block '<S6>/Scope3' : Unused code path elimination
 * Block '<S6>/Scope4' : Unused code path elimination
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S10>/Gain5' : Eliminated nontunable gain of 1
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
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('FOC_Motor_Control/Motor_Control')    - opens subsystem FOC_Motor_Control/Motor_Control
 * hilite_system('FOC_Motor_Control/Motor_Control/Kp') - opens and selects block Kp
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
 * '<S31>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem/Hall_Spd'
 * '<S32>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem/Obs_Spd'
 * '<S33>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC'
 * '<S34>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Chart'
 * '<S35>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Clarke_Transform'
 * '<S36>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI'
 * '<S37>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO'
 * '<S38>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Hall_Angle'
 * '<S39>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Inverse_Park_Transform'
 * '<S40>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/LPF'
 * '<S41>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Obs_Angle'
 * '<S42>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/OpenLoop'
 * '<S43>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Park_Transform'
 * '<S44>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI'
 * '<S45>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM'
 * '<S46>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Sine_Cosine'
 * '<S47>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Subsystem'
 * '<S48>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Clarke_Transform/Clark1'
 * '<S49>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control'
 * '<S50>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Normal'
 * '<S51>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Over_M'
 * '<S52>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Saturation Dynamic'
 * '<S53>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/Equ1'
 * '<S54>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/Equ2'
 * '<S55>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/Equ3'
 * '<S56>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/Equ4'
 * '<S57>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL'
 * '<S58>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl'
 * '<S59>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/Sine_Cosine'
 * '<S60>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/SpeedToTheta'
 * '<S61>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/Subsystem1'
 * '<S62>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Anti-windup'
 * '<S63>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/D Gain'
 * '<S64>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Filter'
 * '<S65>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Filter ICs'
 * '<S66>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/I Gain'
 * '<S67>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Ideal P Gain'
 * '<S68>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Ideal P Gain Fdbk'
 * '<S69>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Integrator'
 * '<S70>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Integrator ICs'
 * '<S71>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/N Copy'
 * '<S72>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/N Gain'
 * '<S73>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/P Copy'
 * '<S74>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Parallel P Gain'
 * '<S75>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Reset Signal'
 * '<S76>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Saturation'
 * '<S77>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Saturation Fdbk'
 * '<S78>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Sum'
 * '<S79>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Sum Fdbk'
 * '<S80>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Tracking Mode'
 * '<S81>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Tracking Mode Sum'
 * '<S82>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Tsamp - Integral'
 * '<S83>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Tsamp - Ngain'
 * '<S84>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/postSat Signal'
 * '<S85>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/preSat Signal'
 * '<S86>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel'
 * '<S87>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S88>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S89>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/D Gain/Disabled'
 * '<S90>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Filter/Disabled'
 * '<S91>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Filter ICs/Disabled'
 * '<S92>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/I Gain/External Parameters'
 * '<S93>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Ideal P Gain/Passthrough'
 * '<S94>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Integrator/Discrete'
 * '<S96>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Integrator ICs/Internal IC'
 * '<S97>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/N Copy/Disabled wSignal Specification'
 * '<S98>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/N Gain/Disabled'
 * '<S99>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/P Copy/Disabled'
 * '<S100>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Parallel P Gain/External Parameters'
 * '<S101>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Reset Signal/Disabled'
 * '<S102>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Saturation/Enabled'
 * '<S103>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Saturation Fdbk/Disabled'
 * '<S104>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Sum/Sum_PI'
 * '<S105>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Sum Fdbk/Disabled'
 * '<S106>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Tracking Mode/Disabled'
 * '<S107>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Tsamp - Integral/Passthrough'
 * '<S109>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/postSat Signal/Forward_Path'
 * '<S111>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/PIDTheta_Ctrl/preSat Signal/Forward_Path'
 * '<S112>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/SpeedToTheta/RangeLimit'
 * '<S113>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/SpeedToTheta/RangeLimit/If Action Subsystem'
 * '<S114>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/SpeedToTheta/RangeLimit/If Action Subsystem1'
 * '<S115>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/SpeedToTheta/RangeLimit/If Action Subsystem2'
 * '<S116>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/Subsystem1/If Action Subsystem'
 * '<S117>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/HIGH_SMO/QPLL/Subsystem1/If Action Subsystem1'
 * '<S118>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control'
 * '<S119>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Normal'
 * '<S120>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Over_M'
 * '<S121>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Saturation Dynamic'
 * '<S122>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Disable_Motor'
 * '<S123>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Enable_Motor'
 * '<S124>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/N Sector  Caculate'
 * '<S125>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/T1 T2  Caculate'
 * '<S126>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Tcm calculate'
 * '<S127>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/XYZ Caculate'
 * '<S128>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/If Action Subsystem1'
 * '<S129>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/If Action Subsystem2'
 * '<S130>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/LPF'
 * '<S131>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/LPF1'
 * '<S132>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/Power_Cacl'
 * '<S133>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/Torque_Cacl'
 */
#endif                                 /* RTW_HEADER_Motor_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
