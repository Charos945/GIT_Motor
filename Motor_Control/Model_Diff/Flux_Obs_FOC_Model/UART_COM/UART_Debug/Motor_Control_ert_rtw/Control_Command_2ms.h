/*
 * File: Control_Command_2ms.h
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Nov 16 10:26:25 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Control_Command_2ms_h_
#define RTW_HEADER_Control_Command_2ms_h_
#include <math.h>
#ifndef Motor_Control_COMMON_INCLUDES_
#define Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Motor_Control_COMMON_INCLUDES_ */

#include "Motor_Control_types.h"
#include "rt_nonfinite.h"

extern void Speed_PI_Disable(void);
extern void Speed_PI(void);
extern void SwitchCaseActionSubsystem(void);
extern void Control_Command_2ms_Init(void);
extern void Control_Command_2ms(void);
extern void Flux_weak_Disable(void);
extern void Flux_weak(void);
extern void Control_Command_2ms_o_Init(void);
extern void Control_Command_2ms_k(void);

#endif                                 /* RTW_HEADER_Control_Command_2ms_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
