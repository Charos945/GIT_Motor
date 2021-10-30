/*
 * File: Control_Command_2ms.c
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

#include "Control_Command_2ms.h"

/* Include model header file for global data */
#include "Motor_Control.h"
#include "Motor_Control_private.h"

/* System initialize for action system: '<S4>/Speed_PI' */
void Speed_PI_Init(void)
{
  /* Start for If: '<S178>/If1' */
  rtDW.If1_ActiveSubsystem_c = -1;

  /* SystemInitialize for IfAction SubSystem: '<S178>/Speed_PI' */
  /* Start for If: '<S180>/If1' */
  rtDW.If1_ActiveSubsystem_g = -1;

  /* End of SystemInitialize for SubSystem: '<S178>/Speed_PI' */
}

/* Disable for action system: '<S4>/Speed_PI' */
void Speed_PI_Disable(void)
{
  /* Disable for If: '<S178>/If1' */
  if (rtDW.If1_ActiveSubsystem_c == 0) {
    /* Disable for If: '<S180>/If1' */
    switch (rtDW.If1_ActiveSubsystem_g) {
     case 0:
      /* Disable for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_DSTATE_j = rtDW.DiscreteTimeIntegrator_l;
      break;

     case 1:
      /* Disable for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_DSTATE_a = rtDW.DiscreteTimeIntegrator_h;
      break;
    }

    rtDW.If1_ActiveSubsystem_g = -1;

    /* End of Disable for If: '<S180>/If1' */
  }

  rtDW.If1_ActiveSubsystem_c = -1;

  /* End of Disable for If: '<S178>/If1' */
}

/* Output and update for action system: '<S4>/Speed_PI' */
void Speed_PI(void)
{
  real32_T rtb_Saturation;
  real32_T rtb_currentControlError;
  real32_T tmp;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Sum: '<S178>/Add2' incorporates:
   *  Inport: '<Root>/Speed_target'
   */
  rtb_currentControlError = rtU.Speed_target - rtDW.Merge;

  /* If: '<S178>/If1' incorporates:
   *  Constant: '<S178>/Hall_Enalble'
   *  Outport: '<Root>/BLDC_State'
   */
  rtPrevAction = rtDW.If1_ActiveSubsystem_c;
  rtAction = -1;
  if ((Hall_Parameter.BLDC_Start != 1) || (rtY.BLDC_State == 3)) {
    rtAction = 0;
  }

  rtDW.If1_ActiveSubsystem_c = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S180>/If1' */
    switch (rtDW.If1_ActiveSubsystem_g) {
     case 0:
      /* Disable for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_DSTATE_j = rtDW.DiscreteTimeIntegrator_l;
      break;

     case 1:
      /* Disable for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_DSTATE_a = rtDW.DiscreteTimeIntegrator_h;
      break;
    }

    rtDW.If1_ActiveSubsystem_g = -1;

    /* End of Disable for If: '<S180>/If1' */
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S178>/Speed_PI' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    /* If: '<S180>/If1' incorporates:
     *  Constant: '<S180>/HFI_Enalble'
     *  Outport: '<Root>/RUN_State'
     */
    rtPrevAction = rtDW.If1_ActiveSubsystem_g;
    rtAction = -1;
    if ((rtY.RUN_State == 3) && (HFI.Func_Enable == 1)) {
      rtAction = 0;
    } else {
      if ((HFI.Func_Enable == 0) && ((rtDW.Motor_state != 2) &&
           (rtDW.Motor_state != 3))) {
        rtAction = 1;
      }
    }

    rtDW.If1_ActiveSubsystem_g = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */
        rtDW.DiscreteTimeIntegrator_DSTATE_j = rtDW.DiscreteTimeIntegrator_l;
        break;

       case 1:
        /* Disable for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
        rtDW.DiscreteTimeIntegrator_DSTATE_a = rtDW.DiscreteTimeIntegrator_h;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S180>/Speed_Control' incorporates:
       *  ActionPort: '<S181>/Action Port'
       */
      /* Switch: '<S181>/Switch' incorporates:
       *  Constant: '<S181>/Cons'
       *  UnitDelay: '<S181>/Unit Delay3'
       */
      if (rtDW.UnitDelay3_DSTATE_j) {
        tmp = rtb_currentControlError;
      } else {
        tmp = 0.0F;
      }

      /* End of Switch: '<S181>/Switch' */

      /* DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_l = rtDW.DiscreteTimeIntegrator_DSTATE_j;

      /* Sum: '<S181>/Add' incorporates:
       *  Constant: '<S181>/Kp'
       *  Product: '<S181>/Product'
       */
      rtb_currentControlError = ctrlParamsPI.speed_PI_Kp *
        rtb_currentControlError + rtDW.DiscreteTimeIntegrator_l;

      /* Saturate: '<S181>/Saturation' */
      if (rtb_currentControlError > ctrlParamsPI.speed_PI_OutputMax) {
        rtb_Saturation = ctrlParamsPI.speed_PI_OutputMax;
      } else if (rtb_currentControlError < ctrlParamsPI.speed_PI_OutputMin) {
        rtb_Saturation = ctrlParamsPI.speed_PI_OutputMin;
      } else {
        rtb_Saturation = rtb_currentControlError;
      }

      /* End of Saturate: '<S181>/Saturation' */

      /* Merge: '<S180>/Merge' incorporates:
       *  SignalConversion generated from: '<S181>/PI_Out'
       */
      rtDW.Merge_d = rtb_Saturation;

      /* Update for UnitDelay: '<S181>/Unit Delay3' incorporates:
       *  RelationalOperator: '<S181>/Relational Operator1'
       */
      rtDW.UnitDelay3_DSTATE_j = (rtb_currentControlError == rtb_Saturation);

      /* Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S181>/Ki'
       *  Product: '<S181>/Product1'
       */
      rtDW.DiscreteTimeIntegrator_DSTATE_j += ctrlParamsPI.speed_PI_Ki * tmp *
        0.002F;

      /* End of Outputs for SubSystem: '<S180>/Speed_Control' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S180>/Speed_Control1' incorporates:
       *  ActionPort: '<S182>/Action Port'
       */
      /* Switch: '<S182>/Switch' incorporates:
       *  Constant: '<S182>/Cons'
       *  UnitDelay: '<S182>/Unit Delay3'
       */
      if (rtDW.UnitDelay3_DSTATE_k4) {
        tmp = rtb_currentControlError;
      } else {
        tmp = 0.0F;
      }

      /* End of Switch: '<S182>/Switch' */

      /* DiscreteIntegrator: '<S182>/Discrete-Time Integrator' */
      rtDW.DiscreteTimeIntegrator_h = rtDW.DiscreteTimeIntegrator_DSTATE_a;

      /* Sum: '<S182>/Add' incorporates:
       *  Constant: '<S182>/Kp'
       *  Product: '<S182>/Product'
       */
      rtb_currentControlError = ctrlParamsPI.speed_PI_Kp *
        rtb_currentControlError + rtDW.DiscreteTimeIntegrator_h;

      /* Saturate: '<S182>/Saturation' */
      if (rtb_currentControlError > ctrlParamsPI.speed_PI_OutputMax) {
        rtb_Saturation = ctrlParamsPI.speed_PI_OutputMax;
      } else if (rtb_currentControlError < ctrlParamsPI.speed_PI_OutputMin) {
        rtb_Saturation = ctrlParamsPI.speed_PI_OutputMin;
      } else {
        rtb_Saturation = rtb_currentControlError;
      }

      /* End of Saturate: '<S182>/Saturation' */

      /* Merge: '<S180>/Merge' incorporates:
       *  SignalConversion generated from: '<S182>/PI_Out'
       */
      rtDW.Merge_d = rtb_Saturation;

      /* Update for UnitDelay: '<S182>/Unit Delay3' incorporates:
       *  RelationalOperator: '<S182>/Relational Operator1'
       */
      rtDW.UnitDelay3_DSTATE_k4 = (rtb_currentControlError == rtb_Saturation);

      /* Update for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S182>/Ki'
       *  Product: '<S182>/Product1'
       */
      rtDW.DiscreteTimeIntegrator_DSTATE_a += ctrlParamsPI.speed_PI_Ki * tmp *
        0.002F;

      /* End of Outputs for SubSystem: '<S180>/Speed_Control1' */
      break;
    }

    /* End of If: '<S180>/If1' */
    /* End of Outputs for SubSystem: '<S178>/Speed_PI' */
  }

  /* End of If: '<S178>/If1' */

  /* SignalConversion generated from: '<S178>/Iq_ref' */
  rtDW.Merge_j = rtDW.Merge_d;
}

/* Output and update for action system: '<S4>/Switch Case Action Subsystem' */
void SwitchCaseActionSubsystem(void)
{
  /* Inport: '<S179>/Iq_in' incorporates:
   *  Constant: '<S4>/IQ_Command'
   */
  rtDW.Merge_j = CL_Param.Current_IQref;
}

/* System initialize for function-call system: '<S2>/Control_Command_2ms' */
void Control_Command_2ms_Init(void)
{
  /* Start for SwitchCase: '<S4>/Switch Case' */
  rtDW.SwitchCase_ActiveSubsystem = -1;

  /* SystemInitialize for IfAction SubSystem: '<S4>/Speed_PI' */
  Speed_PI_Init();

  /* End of SystemInitialize for SubSystem: '<S4>/Speed_PI' */
}

/* Output and update for function-call system: '<S2>/Control_Command_2ms' */
void Control_Command_2ms(void)
{
  int8_T rtAction;
  int8_T rtPrevAction;

  /* SwitchCase: '<S4>/Switch Case' incorporates:
   *  Constant: '<S2>/Control_Mode'
   */
  rtPrevAction = rtDW.SwitchCase_ActiveSubsystem;
  switch (CL_Param.Mode) {
   case 1:
    rtAction = 0;
    break;

   case 2:
    rtAction = 1;
    break;

   default:
    rtAction = 2;
    break;
  }

  rtDW.SwitchCase_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    Speed_PI_Disable();
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S4>/Speed_PI' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    Speed_PI();

    /* End of Outputs for SubSystem: '<S4>/Speed_PI' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S4>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    SwitchCaseActionSubsystem();

    /* End of Outputs for SubSystem: '<S4>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
