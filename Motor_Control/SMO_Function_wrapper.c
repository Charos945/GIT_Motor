
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "SMO_Function.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void SMO_Function_Outputs_wrapper(const real32_T *Ialpha,
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
			real32_T *Zbeta)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */

real32_T Ialphaerr=0;
real32_T Ibetaerr=0;

Ialphaerr=Est_ialpha_last-Ialpha[0];
Ibetaerr=Est_ibeta_last-Ibeta[0];
if(Ialphaerr>tao[0])Zalpha[0]=1;
else if(Ialphaerr<-tao[0])Zalpha[0]=-1;
else Zalpha[0]=Ialphaerr/tao[0];

if(Ibetaerr>tao[0])Zbeta[0]=1;
else if(Ibetaerr<-tao[0])Zbeta[0]=-1;
else Zbeta[0]=Ibetaerr/tao[0];

// real32_T Est_ialpha_last   x5
// real32_T Est_Ealpha_last   x7
// real32_T Est_ibeta_last    x6
// real32_T Est_Ebeta_last   x8
// real32_T Est_iaplha_now    x1
// real32_T Est_Ealpha_now   x3
// real32_T Est_ibeta_now    x2
// real32_T Est_Ebeta_now    x4
//Ialpha[0]  u1
//Ibeta[0]   u2
//Valpha[0]  u3
//Vbeta[0]   u4
//Est_we[0]  u5        
Est_iaplha_now=A[0]*Est_ialpha_last-B[0]*Est_we[0]*Est_ibeta_last+C[0]*(Valpha[0]-Est_Ealpha_last)-C[0]*k[0]*Zalpha[0];
Est_ibeta_now=A[0]*Est_ibeta_last+B[0]*Est_we[0]*Est_ialpha_last+C[0]*(Vbeta[0]-Est_Ebeta_last)-C[0]*k[0]*Zbeta[0];
Est_Ealpha_now=Est_Ealpha_last-Ts[0]*Est_we[0]*Est_Ebeta_last+C[0]*m[0]*Zalpha[0];
Est_Ebeta_now=Est_Ebeta_last+Ts[0]*Est_we[0]*Est_Ealpha_last+C[0]*m[0]*Zbeta[0];
Est_ialpha_last=Est_iaplha_now;
Est_ibeta_last=Est_ibeta_now;
Est_Ealpha_last=Est_Ealpha_now;
Est_Ebeta_last=Est_Ebeta_now;
Est_Ialpha[0]=Est_iaplha_now;
Est_Ibeta[0]=Est_ibeta_now;
Est_Ealpha[0]=Est_Ealpha_now;
Est_Ebeta[0]=Est_Ebeta_now;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


