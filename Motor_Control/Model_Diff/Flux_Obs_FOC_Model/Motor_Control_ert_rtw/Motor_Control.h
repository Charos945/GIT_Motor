/*
 * File: Motor_Control.h
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Nov 18 15:11:34 2021
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
  dsp_simulink_MovingAverage obj;      /* '<S59>/Moving Average' */
  real32_T UnitDelay2;                 /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1;                 /* '<S2>/Unit Delay1' */
  real32_T UnitDelay3;                 /* '<S2>/Unit Delay3' */
  real32_T UnitDelay4;                 /* '<S2>/Unit Delay4' */
  real32_T Timer_Counter;              /* '<S9>/Timer_Counter' */
  real32_T Gain2;                      /* '<S9>/Gain2' */
  real32_T a;                          /* '<S9>/Divide1' */
  real32_T Merge2;                     /* '<S12>/Merge2' */
  real32_T Merge;                      /* '<S27>/Merge' */
  real32_T DiscreteTimeIntegrator;     /* '<S35>/Discrete-Time Integrator' */
  real32_T Merge_c;                    /* '<S25>/Merge' */
  real32_T DiscreteTimeIntegrator_f;   /* '<S31>/Discrete-Time Integrator' */
  real32_T UnitDelay;                  /* '<S66>/Unit Delay' */
  real32_T Add1;                       /* '<S60>/Add1' */
  real32_T Merge2_f;                   /* '<S40>/Merge2' */
  real32_T Merge_g;                    /* '<S40>/Merge' */
  real32_T Merge1;                     /* '<S40>/Merge1' */
  real32_T Merge_c4;                   /* '<S51>/Merge' */
  real32_T Merge1_h;                   /* '<S51>/Merge1' */
  real32_T Merge2_d;                   /* '<S51>/Merge2' */
  real32_T Cosine;                     /* '<S52>/Cosine' */
  real32_T Sine;                       /* '<S52>/Sine' */
  real32_T UnitDelay2_DSTATE;          /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S2>/Unit Delay1' */
  real32_T UnitDelay3_DSTATE;          /* '<S2>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE;          /* '<S2>/Unit Delay4' */
  real32_T UnitDelay6_DSTATE;          /* '<S2>/Unit Delay6' */
  real32_T UnitDelay5_DSTATE;          /* '<S2>/Unit Delay5' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S35>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S31>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_c;         /* '<S60>/Unit Delay' */
  real32_T UnitDelay_DSTATE_p;         /* '<S66>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S63>/Integrator' */
  real32_T Integrator1_DSTATE;         /* '<S63>/Integrator1' */
  real32_T Integrator_DSTATE_e;        /* '<S100>/Integrator' */
  real32_T UnitDelay2_DSTATE_k;        /* '<S40>/Unit Delay2' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S48>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S48>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S121>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S55>/Discrete-Time Integrator' */
  real32_T Memory_PreviousInput;       /* '<S9>/Memory' */
  real32_T Memory1_PreviousInput;      /* '<S9>/Memory1' */
  real32_T Memory2_PreviousInput;      /* '<S9>/Memory2' */
  uint32_T temporalCounter_i1;         /* '<S40>/Chart' */
  int8_T If1_ActiveSubsystem;          /* '<S26>/If1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S35>/Discrete-Time Integrator' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S25>/Switch Case' */
  int8_T DiscreteTimeIntegrator_PrevResetState_h;/* '<S31>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p;/* '<S121>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_pb;/* '<S55>/Discrete-Time Integrator' */
  uint8_T Merge1_a;                    /* '<S6>/Merge1' */
  uint8_T is_active_c3_Motor_Control;  /* '<S40>/Chart' */
  uint8_T is_c3_Motor_Control;         /* '<S40>/Chart' */
  boolean_T UnitDelay3_DSTATE_c;       /* '<S35>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_m;       /* '<S31>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_i;       /* '<S121>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_k;       /* '<S55>/Unit Delay3' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ACC_OMG_Trig_ZCE[3];      /* '<S7>/ACC_OMG' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: Cosine_table)
   * Referenced by:
   *   '<S52>/Cosine'
   *   '<S65>/Cosine'
   */
  real32_T pooled6[4096];

  /* Pooled Parameter (Expression: Sine_table)
   * Referenced by:
   *   '<S52>/Sine'
   *   '<S65>/Sine'
   */
  real32_T pooled8[4096];
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
                                        * '<S34>/Over_modulation'
                                        * '<S55>/Over_modulation'
                                        * '<S121>/Over_modulation'
                                        */
  uint8_T Angle;                       /* Referenced by: '<S2>/Select_Angle' */
  uint8_T TorqueMode;                  /* Referenced by: '<S2>/Control_Mode' */
} CTL_Parameter_type;

typedef struct FluxWeak_Parameter_tag {
  real32_T FluxWeak_Idref_max;         /* Referenced by: '<S35>/Saturation' */
  real32_T FluxWeak_Idref_min;         /* Referenced by: '<S35>/Saturation' */
  real32_T FluxWeak_Ki;                /* Referenced by: '<S35>/Ki' */
  real32_T FluxWeak_Kp;                /* Referenced by: '<S35>/Kp' */
  uint8_T FluxWeak_Enable;             /* Referenced by: '<S4>/Constant1' */
} FluxWeak_Parameter_type;

typedef struct Flux_Parameter_tag {
  real32_T Flux_Gain;                  /* Referenced by:
                                        * '<S44>/Gain'
                                        * '<S44>/Gain1'
                                        * '<S44>/Gain2'
                                        * '<S44>/Gain3'
                                        */
  real32_T pll_omega;                  /* Referenced by: '<S61>/Constant' */
  real32_T pll_xi;                     /* Referenced by: '<S61>/Gain' */
  uint8_T Flux_Theta_Enable;           /* Referenced by:
                                        * '<S27>/Flux_Enable'
                                        * '<S40>/Flux_Enable'
                                        */
} Flux_Parameter_type;

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
  real32_T OPL_Speed;                  /* Referenced by: '<S40>/Constant1' */
  real32_T OPL_Time;                   /* Referenced by:
                                        * '<S40>/Constant3'
                                        * '<S40>/Constant6'
                                        */
  real32_T OPL_Torque;                 /* Referenced by: '<S40>/Constant2' */
} OPL_Parameter_type;

typedef struct PI_Parameter_tag {
  real32_T ID_Ki;                      /* Referenced by: '<S55>/Ki' */
  real32_T ID_Kp;                      /* Referenced by: '<S55>/Kp' */
  real32_T IQ_Ki;                      /* Referenced by: '<S121>/Ki' */
  real32_T IQ_Kp;                      /* Referenced by: '<S121>/Kp' */
  real32_T Speed_Ki;                   /* Referenced by: '<S31>/Ki' */
  real32_T Speed_Kp;                   /* Referenced by: '<S31>/Kp' */
  real32_T Speed_PI_OutputMax;         /* Referenced by: '<S31>/Saturation' */
  real32_T Speed_PI_OutputMin;         /* Referenced by: '<S31>/Saturation' */
} PI_Parameter_type;

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
extern real32_T Motor_Power;           /* '<S133>/Add1' */
extern real32_T Motor_Torque;          /* '<S134>/Add1' */
extern real32_T Hall_Angle;            /* '<S19>/Merge1' */
extern real32_T Hall_Speed;            /* '<S11>/Add1' */
extern real32_T Id_ref;                /* '<S26>/Merge' */
extern real32_T Iq_ref;                /* '<S26>/Merge1' */
extern real32_T Vq_voltage;            /* '<S124>/Switch2' */
extern real32_T Id_measured;           /* '<S49>/Add1' */
extern real32_T Iq_measured;           /* '<S49>/Add2' */
extern real32_T V_alpha;               /* '<S46>/Add' */
extern real32_T V_beta;                /* '<S46>/Add3' */
extern real32_T Vd_voltage;            /* '<S58>/Switch2' */
extern real32_T Ialpha;                /* '<S54>/Gain2' */
extern real32_T Ibeta;                 /* '<S54>/Gain5' */

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
                                        *   '<S60>/Constant1'
                                        */

/* Model entry point functions */
extern void Motor_Control_initialize(void);
extern void Motor_Control_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern CTL_Parameter_type CTL_Parameter;
extern FluxWeak_Parameter_type FluxWeak_Parameter;
extern Flux_Parameter_type Flux_Parameter;
extern Hall_Parameter_type Hall_Parameter;
extern OPL_Parameter_type OPL_Parameter;
extern PI_Parameter_type PI_Parameter;

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
 * Block '<S31>/Scope' : Unused code path elimination
 * Block '<S42>/Scope' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Propagation' : Unused code path elimination
 * Block '<S40>/Flux_Enable1' : Unused code path elimination
 * Block '<S59>/Atan2' : Unused code path elimination
 * Block '<S59>/Constant' : Unused code path elimination
 * Block '<S59>/Mod' : Unused code path elimination
 * Block '<S61>/Scope' : Unused code path elimination
 * Block '<S65>/Scope' : Unused code path elimination
 * Block '<S44>/Scope' : Unused code path elimination
 * Block '<S44>/Scope1' : Unused code path elimination
 * Block '<S46>/Scope' : Unused code path elimination
 * Block '<S48>/Scope' : Unused code path elimination
 * Block '<S48>/Scope1' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Propagation' : Unused code path elimination
 * Block '<S129>/Scope2' : Unused code path elimination
 * Block '<S40>/Scope' : Unused code path elimination
 * Block '<S40>/Scope1' : Unused code path elimination
 * Block '<S40>/Scope2' : Unused code path elimination
 * Block '<S40>/Scope3' : Unused code path elimination
 * Block '<S40>/Scope4' : Unused code path elimination
 * Block '<S52>/Scope' : Unused code path elimination
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
 * '<S26>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening '
 * '<S27>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem'
 * '<S28>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI'
 * '<S29>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Switch Case Action Subsystem'
 * '<S30>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI'
 * '<S31>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI/Speed_Control'
 * '<S32>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem'
 * '<S33>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem1'
 * '<S34>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem/Flux_weak'
 * '<S35>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem/Flux_weak/ID_Control'
 * '<S36>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem/Flux_weak/Normal'
 * '<S37>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem/Flux_weak/Over_M'
 * '<S38>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem/Hall_Spd'
 * '<S39>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem/Obs_Spd'
 * '<S40>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC'
 * '<S41>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Chart'
 * '<S42>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Clarke_Transform'
 * '<S43>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI'
 * '<S44>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer'
 * '<S45>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Hall_Angle'
 * '<S46>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Inverse_Park_Transform'
 * '<S47>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Obs_Angle'
 * '<S48>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/OpenLoop'
 * '<S49>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Park_Transform'
 * '<S50>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI'
 * '<S51>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM'
 * '<S52>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Sine_Cosine'
 * '<S53>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Subsystem'
 * '<S54>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Clarke_Transform/Clark1'
 * '<S55>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control'
 * '<S56>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Normal'
 * '<S57>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Over_M'
 * '<S58>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Saturation Dynamic'
 * '<S59>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER'
 * '<S60>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/LPF'
 * '<S61>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12'
 * '<S62>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.6'
 * '<S63>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.9'
 * '<S64>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller'
 * '<S65>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Sine_Cosine'
 * '<S66>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/integrator'
 * '<S67>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Anti-windup'
 * '<S68>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/D Gain'
 * '<S69>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Filter'
 * '<S70>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Filter ICs'
 * '<S71>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/I Gain'
 * '<S72>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Ideal P Gain'
 * '<S73>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S74>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Integrator'
 * '<S75>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Integrator ICs'
 * '<S76>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/N Copy'
 * '<S77>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/N Gain'
 * '<S78>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/P Copy'
 * '<S79>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Parallel P Gain'
 * '<S80>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Reset Signal'
 * '<S81>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Saturation'
 * '<S82>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Saturation Fdbk'
 * '<S83>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Sum'
 * '<S84>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Sum Fdbk'
 * '<S85>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Tracking Mode'
 * '<S86>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Tracking Mode Sum'
 * '<S87>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Tsamp - Integral'
 * '<S88>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Tsamp - Ngain'
 * '<S89>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/postSat Signal'
 * '<S90>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/preSat Signal'
 * '<S91>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S92>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S93>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S94>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/D Gain/Disabled'
 * '<S95>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Filter/Disabled'
 * '<S96>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Filter ICs/Disabled'
 * '<S97>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/I Gain/External Parameters'
 * '<S98>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S99>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S100>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Integrator/Discrete'
 * '<S101>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S102>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S103>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/N Gain/Disabled'
 * '<S104>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/P Copy/Disabled'
 * '<S105>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S106>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Reset Signal/Disabled'
 * '<S107>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Saturation/Enabled'
 * '<S108>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S109>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Sum/Sum_PI'
 * '<S110>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S111>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S112>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S113>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S114>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S115>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S116>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S117>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/integrator/RangeLimit'
 * '<S118>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/integrator/RangeLimit/If Action Subsystem'
 * '<S119>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/integrator/RangeLimit/If Action Subsystem1'
 * '<S120>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/OBSERVER/equ3.12/integrator/RangeLimit/If Action Subsystem2'
 * '<S121>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control'
 * '<S122>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Normal'
 * '<S123>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Over_M'
 * '<S124>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Saturation Dynamic'
 * '<S125>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Disable_Motor'
 * '<S126>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Enable_Motor'
 * '<S127>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/N Sector  Caculate'
 * '<S128>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/T1 T2  Caculate'
 * '<S129>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Tcm calculate'
 * '<S130>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/XYZ Caculate'
 * '<S131>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/If Action Subsystem1'
 * '<S132>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/If Action Subsystem2'
 * '<S133>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/LPF'
 * '<S134>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/LPF1'
 * '<S135>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/Power_Cacl'
 * '<S136>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/Torque_Cacl'
 */
#endif                                 /* RTW_HEADER_Motor_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
