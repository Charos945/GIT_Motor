/*
 * File: Angle_Speed_100us.h
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

#ifndef RTW_HEADER_Angle_Speed_100us_h_
#define RTW_HEADER_Angle_Speed_100us_h_
#include <math.h>
#ifndef FOC_Motor_Control_COMMON_INCLUDES_
#define FOC_Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FOC_Motor_Control_COMMON_INCLUDES_ */

#include "FOC_Motor_Control_types.h"

/* Child system includes */
#include "Resolver_Angle_cacl.h"
#include "rt_sys_FOC_Control_100us_2.h"

extern void ACC_OMG(void);
extern void ADC_IRQ(void);
extern void Speed_cacl(void);
extern void Speed_Resolver(void);
extern void Angle_calibration(void);
extern void Resolver_Observer(void);
extern void Angle_Speed_100us(void);

#endif                                 /* RTW_HEADER_Angle_Speed_100us_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
