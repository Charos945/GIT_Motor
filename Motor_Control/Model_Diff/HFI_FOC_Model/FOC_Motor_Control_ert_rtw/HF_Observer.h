/*
 * File: HF_Observer.h
 *
 * Code generated for Simulink model 'FOC_Motor_Control'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Nov 22 17:45:55 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HF_Observer_h_
#define RTW_HEADER_HF_Observer_h_
#include <float.h>
#include <math.h>
#ifndef FOC_Motor_Control_COMMON_INCLUDES_
#define FOC_Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* FOC_Motor_Control_COMMON_INCLUDES_ */

#include "FOC_Motor_Control_types.h"

/* Child system includes */
#include "rt_sys_HF_Observer_37.h"
#include "rt_sys_HF_Observer_38.h"
#include "rt_nonfinite.h"

extern void IfActionSubsystem2(real32_T rtu_In1, real32_T *rty_Out1);
extern void HFI_State_machine(void);
extern void Sine_Cosine(void);
extern void IPD(void);
extern void NS_State_machine(void);
extern void Sine_Cosine_b(void);
extern void Sine_Cosine_i(void);
extern void Sine_Cosine_d(void);
extern void Sine_Cosine_e(void);
extern void NS(void);
extern void Angle_calibration(void);
extern void Angle_calibration_h(void);
extern void StartRUN_State_machine(void);
extern void HFI_Function_Init(void);
extern void HFI_Function_Update(void);
extern void HFI_Function(void);
extern void HF_Observer_Init(void);
extern void HF_Observer_Update(void);
extern void HF_Observer(void);

#endif                                 /* RTW_HEADER_HF_Observer_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
