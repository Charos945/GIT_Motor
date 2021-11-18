/*
 * File: Resolver_Angle_cacl.h
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

#ifndef RTW_HEADER_Resolver_Angle_cacl_h_
#define RTW_HEADER_Resolver_Angle_cacl_h_
#include <float.h>
#include <math.h>
#ifndef FOC_Motor_Control_COMMON_INCLUDES_
#define FOC_Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FOC_Motor_Control_COMMON_INCLUDES_ */

#include "FOC_Motor_Control_types.h"
#include "rt_nonfinite.h"

extern void Sine_Cosine_b(void);
extern void Resolver_Angle_cacl(void);

#endif                                 /* RTW_HEADER_Resolver_Angle_cacl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */