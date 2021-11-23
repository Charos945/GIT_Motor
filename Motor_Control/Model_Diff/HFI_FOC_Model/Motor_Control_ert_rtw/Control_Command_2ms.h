/*
 * File: Control_Command_2ms.h
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 1.79
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Nov 23 17:08:07 2021
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
#ifndef Motor_Control_COMMON_INCLUDES_
#define Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Motor_Control_COMMON_INCLUDES_ */

#include "Motor_Control_types.h"

extern void Speed_PI_Init(void);
extern void Speed_PI_Disable(void);
extern void Speed_PI(void);
extern void SwitchCaseActionSubsystem(void);
extern void Control_Command_2ms_Init(void);
extern void Control_Command_2ms(void);
extern void Control_Command_2ms_o_Init(void);
extern void Control_Command_2ms_k(void);

#endif                                 /* RTW_HEADER_Control_Command_2ms_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
