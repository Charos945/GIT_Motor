/*
 * File: Angle_Speed_100us.h
 *
 * Code generated for Simulink model 'Motor_Control'.
 *
 * Model version                  : 3.5
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sun Sep  5 09:33:37 2021
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
#include <float.h>
#include <math.h>
#ifndef Motor_Control_COMMON_INCLUDES_
#define Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Motor_Control_COMMON_INCLUDES_ */

#include "Motor_Control_types.h"

/* Child system includes */
#include "Resolver_Angle_cacl.h"
#include "SpeedAndAngle.h"
#include "rt_sys_HF_Observer_37.h"
#include "rt_sys_HF_Observer_38.h"
#include "rt_nonfinite.h"

extern void Angle_Selector(void);
extern void Angle_calibration_e(void);
extern void Sine_Cosine_lc(void);
extern void Delta_theta(void);
extern void SMO_Disable(void);
extern void SMO_l(void);
extern void Sine_Cosine_h(void);
extern void Flux_OBSERVER_Init(void);
extern void Flux_OBSERVER_Disable(void);
extern void Flux_OBSERVER(void);
extern void Startup_OPL(void);
extern void Angle_calibration_a(void);
extern void Resolver_Observer(void);
extern void Speed_cacl(void);
extern void Speed_Resolver(void);
extern void State_machine(void);
extern void Angle_Speed_100us_Init(void);
extern void Angle_Speed_100us(void);

#endif                                 /* RTW_HEADER_Angle_Speed_100us_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
