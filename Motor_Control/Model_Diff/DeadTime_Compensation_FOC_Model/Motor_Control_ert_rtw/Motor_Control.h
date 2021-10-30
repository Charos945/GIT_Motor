/*
 * File: Motor_Control.h
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

#ifndef RTW_HEADER_Motor_Control_h_
#define RTW_HEADER_Motor_Control_h_
#ifndef Motor_Control_COMMON_INCLUDES_
#define Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Motor_Control_COMMON_INCLUDES_ */

#include "Motor_Control_types.h"

/* Child system includes */
#include "Angle_Speed_100us.h"
#include "Control_Command_2ms.h"
#include "FOC_Control_100us.h"
#include "SYM_State_10ms.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Step;                         /* '<S15>/Step' */
  real32_T Merge_p[3];                 /* '<S27>/Merge' */
  real32_T UnitDelay2;                 /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1;                 /* '<S2>/Unit Delay1' */
  real32_T UnitDelay3;                 /* '<S2>/Unit Delay3' */
  real32_T UnitDelay4;                 /* '<S2>/Unit Delay4' */
  real32_T Direct_Angle;               /* '<S7>/DT2' */
  real32_T DiscreteTimeIntegrator;     /* '<S14>/Discrete-Time Integrator' */
  real32_T Merge;                      /* '<S22>/Merge' */
  real32_T Merge1;                     /* '<S22>/Merge1' */
  real32_T Merge2;                     /* '<S22>/Merge2' */
  real32_T Merge2_n;                   /* '<S32>/Merge2' */
  real32_T Fcn;                        /* '<S28>/Fcn' */
  real32_T Fcn1;                       /* '<S28>/Fcn1' */
  real32_T Add3;                       /* '<S15>/Add3' */
  real32_T Add4;                       /* '<S15>/Add4' */
  real32_T UnitDelay2_DSTATE;          /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S2>/Unit Delay1' */
  real32_T UnitDelay3_DSTATE;          /* '<S2>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE;          /* '<S2>/Unit Delay4' */
  real32_T UnitDelay_DSTATE_f;         /* '<S9>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S14>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S49>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S46>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_p;         /* '<S31>/Unit Delay' */
  real32_T UnitDelay_DSTATE_n;         /* '<S30>/Unit Delay' */
  int32_T Position_Delay_DSTATE;       /* '<S8>/Position_Delay' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S10>/Switch Case' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S49>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_pb;/* '<S46>/Discrete-Time Integrator' */
  uint8_T Merge1_a;                    /* '<S6>/Merge1' */
  boolean_T UnitDelay3_DSTATE_m;       /* '<S14>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_i;       /* '<S49>/Unit Delay3' */
  boolean_T UnitDelay3_DSTATE_k;       /* '<S46>/Unit Delay3' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: atan_table)
   * Referenced by:
   *   '<S35>/1-D Lookup Table4'
   *   '<S38>/1-D Lookup Table4'
   *   '<S39>/1-D Lookup Table4'
   */
  real32_T pooled7[4097];

  /* Expression: Cosine_table
   * Referenced by: '<S23>/Cosine'
   */
  real32_T Cosine_tableData[4096];

  /* Expression: Sine_table
   * Referenced by: '<S23>/Sine'
   */
  real32_T Sine_tableData[4096];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Speed_target;               /* '<Root>/Speed_target' */
  real32_T Torque_ref;                 /* '<Root>/Torque_ref' */
  real32_T Phase_CurrentABC[3];        /* '<Root>/Phase_CurrentABC' */
  real32_T Angle_Theta;                /* '<Root>/Angle_Theta' */
  real32_T Bus_Voltage;                /* '<Root>/Bus_Voltage' */
  uint8_T Start_Stop;                  /* '<Root>/Start_Stop' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Ta;                         /* '<Root>/Ta' */
  real32_T Tb;                         /* '<Root>/Tb' */
  real32_T Tc;                         /* '<Root>/Tc' */
  real32_T Speed_Measured;             /* '<Root>/Speed_Measured' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct CTL_Parameter_tag {
  uint8_T TorqueMode;                  /* Referenced by: '<S2>/Control_Mode' */
} CTL_Parameter_type;

typedef struct PI_Parameter_tag {
  real32_T ID_Ki;                      /* Referenced by: '<S46>/Ki' */
  real32_T ID_Kp;                      /* Referenced by: '<S46>/Kp' */
  real32_T IQ_Ki;                      /* Referenced by: '<S49>/Ki' */
  real32_T IQ_Kp;                      /* Referenced by: '<S49>/Kp' */
  real32_T Speed_Ki;                   /* Referenced by: '<S14>/Ki' */
  real32_T Speed_Kp;                   /* Referenced by: '<S14>/Kp' */
  real32_T Speed_PI_OutputMax;         /* Referenced by: '<S14>/Saturation' */
  real32_T Speed_PI_OutputMin;         /* Referenced by: '<S14>/Saturation' */
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
    uint32_T clockTick0;
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

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
extern real32_T Motor_Power;           /* '<S60>/Add1' */
extern real32_T Motor_Torque;          /* '<S61>/Add1' */
extern real32_T Id_ref;                /* '<S4>/Constant' */
extern real32_T Iq_ref;                /* '<S10>/Merge' */
extern real32_T Vq_voltage;            /* '<S51>/Switch2' */
extern real32_T Id_measured;           /* '<S20>/Add1' */
extern real32_T Iq_measured;           /* '<S20>/Add2' */
extern real32_T V_alpha;               /* '<S19>/Add' */
extern real32_T V_beta;                /* '<S19>/Add3' */
extern real32_T Vd_voltage;            /* '<S48>/Switch2' */
extern real32_T Ialpha;                /* '<S24>/Gain2' */
extern real32_T Ibeta;                 /* '<S24>/Gain5' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T Dead_Time;             /* Variable: Dead_Time
                                        * Referenced by: '<S15>/IdRef2'
                                        */
extern real32_T SpeedFilter_Fn;        /* Variable: SpeedFilter_Fn
                                        * Referenced by: '<S9>/Constant1'
                                        */

/* Model entry point functions */
extern void Motor_Control_initialize(void);
extern void Motor_Control_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern CTL_Parameter_type CTL_Parameter;
extern PI_Parameter_type PI_Parameter;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S16>/Scope' : Unused code path elimination
 * Block '<S15>/Constant3' : Unused code path elimination
 * Block '<S26>/Scope2' : Unused code path elimination
 * Block '<S26>/Scope3' : Unused code path elimination
 * Block '<S35>/Scope' : Unused code path elimination
 * Block '<S38>/Scope' : Unused code path elimination
 * Block '<S39>/Scope' : Unused code path elimination
 * Block '<S25>/Scope' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/Scope' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Propagation' : Unused code path elimination
 * Block '<S56>/Scope2' : Unused code path elimination
 * Block '<S15>/Scope3' : Unused code path elimination
 * Block '<S23>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope2' : Unused code path elimination
 * Block '<S6>/Scope3' : Unused code path elimination
 * Block '<S6>/Scope4' : Unused code path elimination
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
 * '<S7>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Speed_Resolver'
 * '<S8>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Speed_Resolver/Speed_cacl'
 * '<S9>'   : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Angle_Speed_100us/Speed_Resolver/Speed_cacl/LPF'
 * '<S10>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms'
 * '<S11>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI'
 * '<S12>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Switch Case Action Subsystem'
 * '<S13>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI'
 * '<S14>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/Control_Command_2ms/Control_Command_2ms/Speed_PI/Speed_PI/Speed_Control'
 * '<S15>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC'
 * '<S16>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Clarke_Transform'
 * '<S17>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation'
 * '<S18>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI'
 * '<S19>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Inverse_Park_Transform'
 * '<S20>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Park_Transform'
 * '<S21>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI'
 * '<S22>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM'
 * '<S23>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Sine_Cosine'
 * '<S24>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Clarke_Transform/Clark1'
 * '<S25>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation'
 * '<S26>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal'
 * '<S27>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem'
 * '<S28>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Uabc_alphabeta'
 * '<S29>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/Angle_calibration'
 * '<S30>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/LPF'
 * '<S31>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/LPF1'
 * '<S32>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan'
 * '<S33>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/Angle_calibration/If Action Subsystem1'
 * '<S34>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/Angle_calibration/If Action Subsystem2'
 * '<S35>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan/If Action Subsystem10'
 * '<S36>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan/If Action Subsystem11'
 * '<S37>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan/If Action Subsystem12'
 * '<S38>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan/If Action Subsystem8'
 * '<S39>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/IsTheta_Cal/atan/If Action Subsystem9'
 * '<S40>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem'
 * '<S41>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem1'
 * '<S42>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem2'
 * '<S43>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem3'
 * '<S44>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem4'
 * '<S45>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/DT_Compensation/DT_Compensation/Subsystem/Subsystem5'
 * '<S46>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control'
 * '<S47>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Normal'
 * '<S48>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/D_Current_PI/ID_Control/Saturation Dynamic'
 * '<S49>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control'
 * '<S50>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Normal'
 * '<S51>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/Q_Current_PI/IQ_Control/Saturation Dynamic'
 * '<S52>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Disable_Motor'
 * '<S53>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Enable_Motor'
 * '<S54>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/N Sector  Caculate'
 * '<S55>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/T1 T2  Caculate'
 * '<S56>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/Tcm calculate'
 * '<S57>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/FOC_Control_100us/FOC/SVPWM/XYZ Caculate'
 * '<S58>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/If Action Subsystem1'
 * '<S59>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/If Action Subsystem2'
 * '<S60>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/LPF'
 * '<S61>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/LPF1'
 * '<S62>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/Power_Cacl'
 * '<S63>'  : 'FOC_Motor_Control/Motor_Control/Motor_Control_Function/SYM_State_10ms/Torque_Cacl'
 */
#endif                                 /* RTW_HEADER_Motor_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
