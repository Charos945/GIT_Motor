/*
 * File: FOC_Motor_Control.h
 *
 * Code generated for Simulink model 'FOC_Motor_Control'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Nov 15 13:44:38 2021
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
  real32_T Merge_p[3];                 /* '<S110>/Merge' */
  real32_T UnitDelay2;                 /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1;                 /* '<S2>/Unit Delay1' */
  real32_T UnitDelay3;                 /* '<S2>/Unit Delay3' */
  real32_T UnitDelay4;                 /* '<S2>/Unit Delay4' */
  real32_T Merge;                      /* '<S3>/Merge' */
  real32_T Merge1;                     /* '<S3>/Merge1' */
  real32_T Merge1_o;                   /* '<S10>/Merge1' */
  real32_T Add1;                       /* '<S79>/Add1' */
  real32_T Timer_Counter;              /* '<S64>/Timer_Counter' */
  real32_T Gain2;                      /* '<S64>/Gain2' */
  real32_T a;                          /* '<S64>/Divide1' */
  real32_T Merge2;                     /* '<S67>/Merge2' */
  real32_T Merge_h;                    /* '<S82>/Merge' */
  real32_T DiscreteTimeIntegrator;     /* '<S90>/Discrete-Time Integrator' */
  real32_T Merge_c;                    /* '<S80>/Merge' */
  real32_T DiscreteTimeIntegrator_f;   /* '<S86>/Discrete-Time Integrator' */
  real32_T Merge_g;                    /* '<S95>/Merge' */
  real32_T Constant3;                  /* '<S95>/Constant3' */
  real32_T Merge_c4;                   /* '<S105>/Merge' */
  real32_T Merge1_h;                   /* '<S105>/Merge1' */
  real32_T Merge2_d;                   /* '<S105>/Merge2' */
  real32_T UnitDelay;                  /* '<S140>/Unit Delay' */
  real32_T Sine;                       /* '<S139>/Sine' */
  real32_T Merge2_n;                   /* '<S115>/Merge2' */
  real32_T Fcn;                        /* '<S111>/Fcn' */
  real32_T Fcn1;                       /* '<S111>/Fcn1' */
  real32_T Speed_RPM;                  /* '<S11>/Gain' */
  real32_T Angle_Theta;                /* '<S11>/Math Function' */
  real32_T LPF;                        /* '<S11>/LPF' */
  real32_T Add3;                       /* '<S95>/Add3' */
  real32_T Add4;                       /* '<S95>/Add4' */
  real32_T Add1_n;                     /* '<S134>/Add1' */
  real32_T UnitDelay2_DSTATE;          /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S2>/Unit Delay1' */
  real32_T UnitDelay3_DSTATE;          /* '<S2>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE;          /* '<S2>/Unit Delay4' */
  real32_T UnitDelay6_DSTATE;          /* '<S2>/Unit Delay6' */
  real32_T UnitDelay5_DSTATE;          /* '<S2>/Unit Delay5' */
  real32_T UnitDelay4_DSTATE_j;        /* '<S11>/Unit Delay4' */
  real32_T Integrator_DSTATE;          /* '<S47>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S11>/Discrete-Time Integrator' */
  real32_T LPF_states;                 /* '<S11>/LPF' */
  real32_T DiscreteTimeIntegrator_DSTATE_l;/* '<S90>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S86>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S195>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_j;         /* '<S140>/Unit Delay' */
  real32_T Integrator_DSTATE_f;        /* '<S174>/Integrator' */
  real32_T UnitDelay_DSTATE_c;         /* '<S134>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S129>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_p;         /* '<S114>/Unit Delay' */
  real32_T UnitDelay_DSTATE_n;         /* '<S113>/Unit Delay' */
  real32_T Memory_PreviousInput;       /* '<S64>/Memory' */
  real32_T Memory1_PreviousInput;      /* '<S64>/Memory1' */
  real32_T Memory2_PreviousInput;      /* '<S64>/Memory2' */
  int32_T Position_Delay_DSTATE;       /* '<S78>/Position_Delay' */
  int8_T If1_ActiveSubsystem;          /* '<S81>/If1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S90>/Discrete-Time Integrator' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S80>/Switch Case' */
  int8_T DiscreteTimeIntegrator_PrevResetState_h;/* '<S86>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_p;/* '<S195>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_pb;/* '<S129>/Discrete-Time Integrator' */
  uint8_T Merge1_a;                    /* '<S6>/Merge1' */
  boolean_T UnitDelay3_DSTATE_c;       /* '<S90>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_m;       /* '<S86>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_i;       /* '<S195>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_k;       /* '<S129>/Unit Delay3' */
  boolean_T Flux_observer_MODE;        /* '<S99>/Flux_observer' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ACC_OMG_Trig_ZCE[3];      /* '<S8>/ACC_OMG' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: atan_table)
   * Referenced by:
   *   '<S118>/1-D Lookup Table4'
   *   '<S121>/1-D Lookup Table4'
   *   '<S122>/1-D Lookup Table4'
   */
  real32_T pooled6[4097];

  /* Pooled Parameter (Expression: Cosine_table)
   * Referenced by:
   *   '<S106>/Cosine'
   *   '<S15>/Cosine'
   *   '<S139>/Cosine'
   */
  real32_T pooled29[4096];

  /* Pooled Parameter (Expression: Sine_table)
   * Referenced by:
   *   '<S106>/Sine'
   *   '<S15>/Sine'
   *   '<S139>/Sine'
   */
  real32_T pooled31[4096];
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
  real32_T Angle_offset;               /* Referenced by: '<S10>/Angle_offset' */
  boolean_T Over_modulation;           /* Referenced by:
                                        * '<S89>/Over_modulation'
                                        * '<S129>/Over_modulation'
                                        * '<S195>/Over_modulation'
                                        */
  uint8_T Angle;                       /* Referenced by: '<S2>/Select_Angle' */
  uint8_T TorqueMode;                  /* Referenced by: '<S2>/Control_Mode' */
} CTL_Parameter_type;

typedef struct FluxWeak_Parameter_tag {
  real32_T FluxWeak_Idref_max;         /* Referenced by: '<S90>/Saturation' */
  real32_T FluxWeak_Idref_min;         /* Referenced by: '<S90>/Saturation' */
  real32_T FluxWeak_Ki;                /* Referenced by: '<S90>/Ki' */
  real32_T FluxWeak_Kp;                /* Referenced by: '<S90>/Kp' */
  uint8_T FluxWeak_Enable;             /* Referenced by: '<S4>/Constant1' */
} FluxWeak_Parameter_type;

typedef struct Flux_Parameter_tag {
  real32_T Gamma;                      /* Referenced by:
                                        * '<S137>/Gain'
                                        * '<S137>/Gain1'
                                        */
  real32_T pll_omega;                  /* Referenced by: '<S135>/Constant' */
  real32_T pll_xi;                     /* Referenced by: '<S135>/Gain' */
  uint8_T Flux_Theta_Enable;           /* Referenced by:
                                        * '<S82>/Flux_Enable'
                                        * '<S95>/Flux_Enable'
                                        */
} Flux_Parameter_type;

typedef struct Hall_Parameter_tag {
  real32_T HaLL_AngleShift;            /* Referenced by:
                                        * '<S74>/Angle_offset'
                                        * '<S68>/Constant1'
                                        * '<S69>/Constant1'
                                        * '<S70>/Constant1'
                                        * '<S71>/Constant1'
                                        * '<S72>/Constant1'
                                        * '<S73>/Constant1'
                                        */
  real32_T HaLL_Sector1;               /* Referenced by: '<S68>/Constant' */
  real32_T HaLL_Sector2;               /* Referenced by: '<S69>/Pi//3' */
  real32_T HaLL_Sector3;               /* Referenced by: '<S70>/Constant' */
  real32_T HaLL_Sector4;               /* Referenced by: '<S71>/Constant' */
  real32_T HaLL_Sector5;               /* Referenced by: '<S72>/Constant' */
  real32_T HaLL_Sector6;               /* Referenced by: '<S73>/Constant' */
  real32_T HaLL_Timer_T;               /* Referenced by:
                                        * '<S64>/Gain3'
                                        * '<S65>/Gain2'
                                        * '<S65>/Gain3'
                                        */
} Hall_Parameter_type;

typedef struct PI_Parameter_tag {
  real32_T ID_Ki;                      /* Referenced by: '<S129>/Ki' */
  real32_T ID_Kp;                      /* Referenced by: '<S129>/Kp' */
  real32_T IQ_Ki;                      /* Referenced by: '<S195>/Ki' */
  real32_T IQ_Kp;                      /* Referenced by: '<S195>/Kp' */
  real32_T Speed_Ki;                   /* Referenced by: '<S86>/Ki' */
  real32_T Speed_Kp;                   /* Referenced by: '<S86>/Kp' */
  real32_T Speed_PI_OutputMax;         /* Referenced by: '<S86>/Saturation' */
  real32_T Speed_PI_OutputMin;         /* Referenced by: '<S86>/Saturation' */
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
extern real32_T Motor_Power;           /* '<S207>/Add1' */
extern real32_T Motor_Torque;          /* '<S208>/Add1' */
extern real32_T Hall_Angle;            /* '<S74>/Merge1' */
extern real32_T Hall_Speed;            /* '<S66>/Add1' */
extern real32_T Id_ref;                /* '<S81>/Merge' */
extern real32_T Iq_ref;                /* '<S81>/Merge1' */
extern real32_T Vq_voltage;            /* '<S198>/Switch2' */
extern real32_T Id_measured;           /* '<S103>/Add1' */
extern real32_T Iq_measured;           /* '<S103>/Add2' */
extern real32_T V_alpha;               /* '<S101>/Add' */
extern real32_T V_beta;                /* '<S101>/Add3' */
extern real32_T ObserverOmega;         /* '<S181>/Saturation' */
extern real32_T Vd_voltage;            /* '<S132>/Switch2' */
extern real32_T Ialpha;                /* '<S107>/Gain2' */
extern real32_T Ibeta;                 /* '<S107>/Gain5' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T Dead_Time;             /* Variable: Dead_Time
                                        * Referenced by: '<S95>/IdRef2'
                                        */
extern real32_T SpeedFilter_Fn;        /* Variable: SpeedFilter_Fn
                                        * Referenced by:
                                        *   '<S66>/Constant1'
                                        *   '<S79>/Constant1'
                                        *   '<S134>/Constant1'
                                        */
extern uint8_T Dead_Com_Enable;        /* Variable: Dead_Com_Enable
                                        * Referenced by: '<S95>/Constant3'
                                        */

/* Model entry point functions */
extern void FOC_Motor_Control_initialize(void);
extern void FOC_Motor_Control_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern CTL_Parameter_type CTL_Parameter;
extern FluxWeak_Parameter_type FluxWeak_Parameter;
extern Flux_Parameter_type Flux_Parameter;
extern Hall_Parameter_type Hall_Parameter;
extern PI_Parameter_type PI_Parameter;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S11>/Scope1' : Unused code path elimination
 * Block '<S11>/Scope2' : Unused code path elimination
 * Block '<S11>/Scope3' : Unused code path elimination
 * Block '<S11>/Scope4' : Unused code path elimination
 * Block '<S11>/Scope5' : Unused code path elimination
 * Block '<S11>/Scope6' : Unused code path elimination
 * Block '<S11>/Scope7' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S7>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<S3>/Scope3' : Unused code path elimination
 * Block '<S64>/Scope1' : Unused code path elimination
 * Block '<S64>/Scope17' : Unused code path elimination
 * Block '<S64>/Scope2' : Unused code path elimination
 * Block '<S64>/Scope3' : Unused code path elimination
 * Block '<S64>/Scope4' : Unused code path elimination
 * Block '<S64>/Scope5' : Unused code path elimination
 * Block '<S67>/Scope' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S78>/Scope' : Unused code path elimination
 * Block '<S86>/Scope' : Unused code path elimination
 * Block '<S96>/Scope' : Unused code path elimination
 * Block '<S109>/Scope2' : Unused code path elimination
 * Block '<S109>/Scope3' : Unused code path elimination
 * Block '<S118>/Scope' : Unused code path elimination
 * Block '<S121>/Scope' : Unused code path elimination
 * Block '<S122>/Scope' : Unused code path elimination
 * Block '<S108>/Scope' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Propagation' : Unused code path elimination
 * Block '<S95>/Flux_Enable1' : Unused code path elimination
 * Block '<S135>/Scope' : Unused code path elimination
 * Block '<S139>/Scope' : Unused code path elimination
 * Block '<S101>/Scope' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S198>/Data Type Propagation' : Unused code path elimination
 * Block '<S203>/Scope2' : Unused code path elimination
 * Block '<S95>/Scope' : Unused code path elimination
 * Block '<S95>/Scope2' : Unused code path elimination
 * Block '<S95>/Scope3' : Unused code path elimination
 * Block '<S106>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope2' : Unused code path elimination
 * Block '<S6>/Scope3' : Unused code path elimination
 * Block '<S6>/Scope4' : Unused code path elimination
 * Block '<S11>/pole pairs ' : Eliminated nontunable gain of 1
 * Block '<S64>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S64>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S64>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S65>/Gain5' : Eliminated nontunable gain of 1
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
 * '<S7>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer'
 * '<S8>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle'
 * '<S9>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Speed_Resolver'
 * '<S10>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Angle_calibration'
 * '<S11>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl'
 * '<S12>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Angle_calibration/If Action Subsystem1'
 * '<S13>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Angle_calibration/If Action Subsystem2'
 * '<S14>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller'
 * '<S15>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/Sine_Cosine'
 * '<S16>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Anti-windup'
 * '<S17>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/D Gain'
 * '<S18>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Filter'
 * '<S19>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Filter ICs'
 * '<S20>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/I Gain'
 * '<S21>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Ideal P Gain'
 * '<S22>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Ideal P Gain Fdbk'
 * '<S23>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Integrator'
 * '<S24>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Integrator ICs'
 * '<S25>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/N Copy'
 * '<S26>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/N Gain'
 * '<S27>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/P Copy'
 * '<S28>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Parallel P Gain'
 * '<S29>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Reset Signal'
 * '<S30>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Saturation'
 * '<S31>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Saturation Fdbk'
 * '<S32>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Sum'
 * '<S33>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Sum Fdbk'
 * '<S34>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tracking Mode'
 * '<S35>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tracking Mode Sum'
 * '<S36>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tsamp - Integral'
 * '<S37>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tsamp - Ngain'
 * '<S38>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/postSat Signal'
 * '<S39>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/preSat Signal'
 * '<S40>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Anti-windup/Passthrough'
 * '<S41>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/D Gain/Disabled'
 * '<S42>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Filter/Disabled'
 * '<S43>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Filter ICs/Disabled'
 * '<S44>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/I Gain/Internal Parameters'
 * '<S45>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Ideal P Gain/Passthrough'
 * '<S46>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Integrator/Discrete'
 * '<S48>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Integrator ICs/Internal IC'
 * '<S49>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S50>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/N Gain/Disabled'
 * '<S51>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/P Copy/Disabled'
 * '<S52>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S53>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Reset Signal/Disabled'
 * '<S54>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Saturation/Passthrough'
 * '<S55>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Saturation Fdbk/Disabled'
 * '<S56>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Sum/Sum_PI'
 * '<S57>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Sum Fdbk/Disabled'
 * '<S58>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tracking Mode/Disabled'
 * '<S59>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tsamp - Integral/Passthrough'
 * '<S61>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/postSat Signal/Forward_Path'
 * '<S63>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Resolver_Observer/Resolver_Angle_cacl/PID Controller/preSat Signal/Forward_Path'
 * '<S64>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG'
 * '<S65>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ'
 * '<S66>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/LPF'
 * '<S67>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point'
 * '<S68>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_1'
 * '<S69>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_2'
 * '<S70>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_3'
 * '<S71>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_4'
 * '<S72>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_5'
 * '<S73>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ACC_OMG/Six_point/Sector_6'
 * '<S74>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration'
 * '<S75>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration/If Action Subsystem1'
 * '<S76>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration/If Action Subsystem2'
 * '<S77>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/SpeedAndAngle/ADC_IRQ/HallAngle_calibration/If Action Subsystem3'
 * '<S78>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Speed_Resolver/Speed_cacl'
 * '<S79>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Speed_Resolver/Speed_cacl/LPF'
 * '<S80>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms'
 * '<S81>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening '
 * '<S82>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem'
 * '<S83>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI'
 * '<S84>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Switch Case Action Subsystem'
 * '<S85>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI'
 * '<S86>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI/Speed_Control'
 * '<S87>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem'
 * '<S88>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem1'
 * '<S89>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem/Flux_weak'
 * '<S90>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem/Flux_weak/ID_Control'
 * '<S91>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem/Flux_weak/Normal'
 * '<S92>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Flux_weakening /Subsystem/Flux_weak/Over_M'
 * '<S93>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem/Hall_Spd'
 * '<S94>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Subsystem/Obs_Spd'
 * '<S95>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC'
 * '<S96>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Clarke_Transform'
 * '<S97>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation'
 * '<S98>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI'
 * '<S99>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer'
 * '<S100>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Hall_Angle'
 * '<S101>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Inverse_Park_Transform'
 * '<S102>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Obs_Angle'
 * '<S103>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Park_Transform'
 * '<S104>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI'
 * '<S105>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM'
 * '<S106>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Sine_Cosine'
 * '<S107>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Clarke_Transform/Clark1'
 * '<S108>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation'
 * '<S109>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal'
 * '<S110>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem'
 * '<S111>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Uabc_alphabeta'
 * '<S112>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/Angle_calibration'
 * '<S113>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/LPF'
 * '<S114>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/LPF1'
 * '<S115>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan'
 * '<S116>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/Angle_calibration/If Action Subsystem1'
 * '<S117>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/Angle_calibration/If Action Subsystem2'
 * '<S118>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan/If Action Subsystem10'
 * '<S119>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan/If Action Subsystem11'
 * '<S120>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan/If Action Subsystem12'
 * '<S121>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan/If Action Subsystem8'
 * '<S122>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan/If Action Subsystem9'
 * '<S123>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem'
 * '<S124>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem1'
 * '<S125>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem2'
 * '<S126>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem3'
 * '<S127>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem4'
 * '<S128>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem5'
 * '<S129>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control'
 * '<S130>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Normal'
 * '<S131>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Over_M'
 * '<S132>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Saturation Dynamic'
 * '<S133>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer'
 * '<S134>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/LPF'
 * '<S135>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12'
 * '<S136>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.6'
 * '<S137>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.9'
 * '<S138>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller'
 * '<S139>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Sine_Cosine'
 * '<S140>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/integrator'
 * '<S141>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Anti-windup'
 * '<S142>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/D Gain'
 * '<S143>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Filter'
 * '<S144>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Filter ICs'
 * '<S145>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/I Gain'
 * '<S146>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Ideal P Gain'
 * '<S147>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S148>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Integrator'
 * '<S149>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Integrator ICs'
 * '<S150>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/N Copy'
 * '<S151>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/N Gain'
 * '<S152>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/P Copy'
 * '<S153>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Parallel P Gain'
 * '<S154>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Reset Signal'
 * '<S155>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Saturation'
 * '<S156>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Saturation Fdbk'
 * '<S157>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Sum'
 * '<S158>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Sum Fdbk'
 * '<S159>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Tracking Mode'
 * '<S160>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Tracking Mode Sum'
 * '<S161>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Tsamp - Integral'
 * '<S162>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Tsamp - Ngain'
 * '<S163>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/postSat Signal'
 * '<S164>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/preSat Signal'
 * '<S165>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S166>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S167>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S168>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/D Gain/Disabled'
 * '<S169>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Filter/Disabled'
 * '<S170>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Filter ICs/Disabled'
 * '<S171>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/I Gain/External Parameters'
 * '<S172>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S173>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S174>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Integrator/Discrete'
 * '<S175>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S176>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S177>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/N Gain/Disabled'
 * '<S178>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/P Copy/Disabled'
 * '<S179>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S180>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Reset Signal/Disabled'
 * '<S181>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Saturation/Enabled'
 * '<S182>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S183>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Sum/Sum_PI'
 * '<S184>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S185>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S186>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S187>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S188>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S189>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S190>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S191>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/integrator/RangeLimit'
 * '<S192>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/integrator/RangeLimit/If Action Subsystem'
 * '<S193>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/integrator/RangeLimit/If Action Subsystem1'
 * '<S194>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Flux_Observer/Flux_observer/equ3.12/integrator/RangeLimit/If Action Subsystem2'
 * '<S195>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control'
 * '<S196>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Normal'
 * '<S197>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Over_M'
 * '<S198>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Saturation Dynamic'
 * '<S199>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Disable_Motor'
 * '<S200>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Enable_Motor'
 * '<S201>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/N Sector  Caculate'
 * '<S202>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/T1 T2  Caculate'
 * '<S203>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Tcm calculate'
 * '<S204>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/XYZ Caculate'
 * '<S205>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/If Action Subsystem1'
 * '<S206>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/If Action Subsystem2'
 * '<S207>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/LPF'
 * '<S208>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/LPF1'
 * '<S209>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/Power_Cacl'
 * '<S210>' : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/Torque_Cacl'
 */
#endif                                 /* RTW_HEADER_FOC_Motor_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
