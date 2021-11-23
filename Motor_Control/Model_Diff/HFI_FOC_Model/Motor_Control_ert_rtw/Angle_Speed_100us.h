/*
 * File: Angle_Speed_100us.h
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

#ifndef RTW_HEADER_Angle_Speed_100us_h_
#define RTW_HEADER_Angle_Speed_100us_h_
#include <math.h>
#ifndef Motor_Control_COMMON_INCLUDES_
#define Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Motor_Control_COMMON_INCLUDES_ */

#include "Motor_Control_types.h"

/* Child system includes */
#include "rt_sys_HF_Observer_37.h"
#include "rt_sys_HF_Observer_38.h"

extern void ACC_OMG(void);
extern void ADC_IRQ(void);
extern void Speed_cacl(void);
extern void Speed_Resolver(void);
extern void Angle_Speed_100us(void);

#endif                                 /* RTW_HEADER_Angle_Speed_100us_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
