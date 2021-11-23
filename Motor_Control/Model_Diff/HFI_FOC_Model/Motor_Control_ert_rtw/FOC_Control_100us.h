/*
 * File: FOC_Control_100us.h
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

#ifndef RTW_HEADER_FOC_Control_100us_h_
#define RTW_HEADER_FOC_Control_100us_h_
#ifndef Motor_Control_COMMON_INCLUDES_
#define Motor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Motor_Control_COMMON_INCLUDES_ */

#include "Motor_Control_types.h"

/* Child system includes */
#include "HF_Observer.h"

extern void Over_M(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T
                   *rty_Out2);
extern void Normal(real32_T rtu_Bus_voltage, real32_T *rty_Out1, real32_T
                   *rty_Out2);
extern void Angle_set(void);
extern void Clarke_Transform(void);
extern void D_Current_PI(void);
extern void Inverse_Park_Transform(void);
extern void Park_Transform(void);
extern void Q_Current_PI(void);
extern void SVPWM(void);
extern void Set_Idq(void);
extern void Set_Idq1(void);
extern void Set_Idq_p(void);
extern void Sine_Cosine_m(void);
extern void FOC_Init(void);
extern void FOC(void);
extern void FOC_Control_100us_Init(void);
extern void FOC_Control_100us(void);

#endif                                 /* RTW_HEADER_FOC_Control_100us_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
