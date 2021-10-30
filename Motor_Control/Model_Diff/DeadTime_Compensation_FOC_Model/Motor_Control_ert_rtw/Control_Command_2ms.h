/*
 * File: Control_Command_2ms.h
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

#ifndef RTW_HEADER_Control_Command_2ms_h_
#define RTW_HEADER_Control_Command_2ms_h_
#ifndef Motor_Control_COMMON_INCLUDES_
#define Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Motor_Control_COMMON_INCLUDES_ */

#include "Motor_Control_types.h"

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
