/*
 * File: SpeedAndAngle.h
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

#ifndef RTW_HEADER_SpeedAndAngle_h_
#define RTW_HEADER_SpeedAndAngle_h_
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

extern void ACC_OMG_Init(void);
extern void ACC_OMG(void);
extern void ADC_IRQ(void);
extern void SpeedAndAngle_Init(void);
extern void SpeedAndAngle(void);

#endif                                 /* RTW_HEADER_SpeedAndAngle_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
