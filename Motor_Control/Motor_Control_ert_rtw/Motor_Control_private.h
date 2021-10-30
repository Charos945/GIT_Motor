/*
 * File: Motor_Control_private.h
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

#ifndef RTW_HEADER_Motor_Control_private_h_
#define RTW_HEADER_Motor_Control_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern void SMO_Function_Start_wrapper(void);
  extern void SMO_Function_Outputs_wrapper(const real32_T *Ialpha,
    const real32_T *Ibeta,
    const real32_T *Valpha,
    const real32_T *Vbeta,
    const real32_T *Est_we,
    const real32_T *A,
    const real32_T *B,
    const real32_T *C,
    const real32_T *k,
    const real32_T *m,
    const real32_T *tao,
    const real32_T *Ts,
    real32_T *Est_Ialpha,
    real32_T *Est_Ibeta,
    real32_T *Est_Ealpha,
    real32_T *Est_Ebeta,
    real32_T *Zalpha,
    real32_T *Zbeta);
  extern void SMO_Function_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern real32_T rt_modf_snf(real32_T u0, real32_T u1);
extern uint32_T plook_u32f_evencka(real32_T u, real32_T bp0, real32_T bpSpace,
  uint32_T maxIndex);

#endif                                 /* RTW_HEADER_Motor_Control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
