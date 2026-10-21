/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: solenoid_valve_curtain_v1_109.c
 *
 * Code generated for Simulink model 'solenoid_valve_curtain_v1_109'.
 *
 * Model version                  : 2.4
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Tue Oct 20 20:09:21 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "solenoid_valve_curtain_v1_109.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "math.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Continuous states */
X rtX;

/* Disabled State Vector */
XDis rtXDis;

/* Block signals and states (default storage) */
DW rtDW;

/* Mass Matrices */
MassMatrix rtMassMatrix;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                 /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
  ;
static void MATLABFunction3(real_T rtu_A_actual_m2, real_T rtu_P0_Pa, real_T
  *rty_mdot_slugs);

/* private model entry point functions */
extern void solenoid_valve_curtain_v1_109_derivatives(void);
extern void solenoid_valve_curtain_v1_109_forcingfunction(void);
extern void solenoid_valve_curtain_v1_109_massmatrix(void);
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
real_T rtNaN = -(real_T)NAN;
real_T rtInf = (real_T)INFINITY;
real_T rtMinusInf = -(real_T)INFINITY;
real32_T rtNaNF = -(real32_T)NAN;
real32_T rtInfF = (real32_T)INFINITY;
real32_T rtMinusInfF = -(real32_T)INFINITY;

/* Return rtInf needed by the generated code. */
static real_T rtGetInf(void)
{
  return rtInf;
}

/* Get rtInfF needed by the generated code. */
static real32_T rtGetInfF(void)
{
  return rtInfF;
}

/* Return rtMinusInf needed by the generated code. */
static real_T rtGetMinusInf(void)
{
  return rtMinusInf;
}

/* Return rtMinusInfF needed by the generated code. */
static real32_T rtGetMinusInfF(void)
{
  return rtMinusInfF;
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)isinf(value);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)isinf(value);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 * (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 * (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                 /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;
  real_T* tBuf = uBuf + bufSz;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

/* ForcingFunction for root system: '<Root>' */
void solenoid_valve_curtain_v1_109_forcingfunction(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  XDot *_rtXdot;
  char *msg;
  char *msg_0;
  real_T tmp_0[4];
  real_T tmp_3[4];
  real_T time;
  real_T time_0;
  real_T time_tmp;
  int32_T tmp_2;
  int_T tmp_1[2];
  int_T tmp_4[2];
  boolean_T tmp;
  _rtXdot = ((XDot *) rtM->derivs);

  /* ForcingFunction for SimscapeInputBlock: '<S23>/INPUT_1_1_1' */
  _rtXdot->solenoid_valve_curtain_v1_109so = (rtDW.Gain -
    rtX.solenoid_valve_curtain_v1_109so) * 1000.0;

  /* ForcingFunction for SimscapeExecutionBlock: '<S23>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S14>/STATE_1'
   */
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time_tmp = rtM->Timing.t[0];
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 10;
  simulationData->mData->mContStates.mX = &rtX.solenoid_valve_curtain_v1_109_b[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 3;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
  simulationData->mData->mSwitchingCoeffs.mN = 0;
  simulationData->mData->mSwitchingCoeffs.mX = &rtDW.STATE_1_SwtgCoeffs;
  simulationData->mData->mJacobianElems.mN = 0;
  simulationData->mData->mJacobianElems.mX = &rtDW.STATE_1_JacobElems;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&rtM->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = rtDW.INPUT_1_1_1[0];
  tmp_0[1] = rtDW.INPUT_1_1_1[1];
  tmp_0[2] = rtDW.INPUT_1_1_1[2];
  tmp_0[3] = rtDW.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 10;
  simulationData->mData->mDx.mX = &_rtXdot->solenoid_valve_curtain_v1_109_b[0];
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_FORCINGFUNCTION, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(rtM, msg);
    }
  }

  /* End of ForcingFunction for SimscapeExecutionBlock: '<S23>/STATE_1' */

  /* ForcingFunction for SimscapeInputBlock: '<S14>/INPUT_1_1_1' */
  _rtXdot->solenoid_valve_curtain_v1_109So = (rtDW.Gain9 -
    rtX.solenoid_valve_curtain_v1_109So) * 1000.0;

  /* ForcingFunction for SimscapeExecutionBlock: '<S14>/STATE_1' */
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData_f;
  time_0 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 10;
  simulationData->mData->mContStates.mX = &rtX.solenoid_valve_curtain_v1_109_l[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete_c;
  simulationData->mData->mModeVector.mN = 3;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes_o[0];
  simulationData->mData->mSwitchingCoeffs.mN = 0;
  simulationData->mData->mSwitchingCoeffs.mX = &rtDW.STATE_1_SwtgCoeffs_k;
  simulationData->mData->mJacobianElems.mN = 0;
  simulationData->mData->mJacobianElems.mX = &rtDW.STATE_1_JacobElems_h;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&rtM->solverInfo);
  tmp_4[0] = 0;
  tmp_3[0] = rtDW.INPUT_1_1_1_c[0];
  tmp_3[1] = rtDW.INPUT_1_1_1_c[1];
  tmp_3[2] = rtDW.INPUT_1_1_1_c[2];
  tmp_3[3] = rtDW.INPUT_1_1_1_c[3];
  tmp_4[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_3[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_4[0];
  simulationData->mData->mDx.mN = 10;
  simulationData->mData->mDx.mX = &_rtXdot->solenoid_valve_curtain_v1_109_l[0];
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr_n;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator_b,
    NESL_SIM_FORCINGFUNCTION, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(rtM, msg_0);
    }
  }

  /* ForcingFunction for Integrator: '<Root>/Vel>Pos' */
  _rtXdot->VelPos_CSTATE = rtDW.Vel;

  /* ForcingFunction for Integrator: '<Root>/Accel>Vel' */
  _rtXdot->AccelVel_CSTATE = rtDW.AngularAccleration;

  /* ForcingFunction for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = rtDW.Mdot;
}

/* MassMatrix for root system: '<Root>' */
void solenoid_valve_curtain_v1_109_massmatrix(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  char *msg;
  char *msg_0;
  real_T tmp_0[4];
  real_T tmp_5[4];
  real_T time;
  real_T time_0;
  real_T time_tmp;
  real_T *tmp_2;
  real_T *tmp_3;
  real_T *tmp_7;
  int32_T tmp_4;
  int_T tmp_1[2];
  int_T tmp_6[2];
  boolean_T tmp;

  /* MassMatrix for SimscapeExecutionBlock: '<S23>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S14>/STATE_1'
   */
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time_tmp = rtM->Timing.t[0];
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 10;
  simulationData->mData->mContStates.mX = &rtX.solenoid_valve_curtain_v1_109_b[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 3;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
  simulationData->mData->mSwitchingCoeffs.mN = 0;
  simulationData->mData->mSwitchingCoeffs.mX = &rtDW.STATE_1_SwtgCoeffs;
  simulationData->mData->mJacobianElems.mN = 0;
  simulationData->mData->mJacobianElems.mX = &rtDW.STATE_1_JacobElems;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&rtM->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = rtDW.INPUT_1_1_1[0];
  tmp_0[1] = rtDW.INPUT_1_1_1[1];
  tmp_0[2] = rtDW.INPUT_1_1_1[2];
  tmp_0[3] = rtDW.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  tmp_2 = rtM->massMatrixPr;
  tmp_3 = double_pointer_shift(tmp_2, rtDW.STATE_1_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 4;
  simulationData->mData->mMassMatrixPr.mX = tmp_3;
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_4 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_MASSMATRIX, simulationData, diagnosticManager);
  if (tmp_4 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(rtM, msg);
    }
  }

  /* End of MassMatrix for SimscapeExecutionBlock: '<S23>/STATE_1' */

  /* MassMatrix for SimscapeExecutionBlock: '<S14>/STATE_1' */
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData_f;
  time_0 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 10;
  simulationData->mData->mContStates.mX = &rtX.solenoid_valve_curtain_v1_109_l[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete_c;
  simulationData->mData->mModeVector.mN = 3;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes_o[0];
  simulationData->mData->mSwitchingCoeffs.mN = 0;
  simulationData->mData->mSwitchingCoeffs.mX = &rtDW.STATE_1_SwtgCoeffs_k;
  simulationData->mData->mJacobianElems.mN = 0;
  simulationData->mData->mJacobianElems.mX = &rtDW.STATE_1_JacobElems_h;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&rtM->solverInfo);
  tmp_6[0] = 0;
  tmp_5[0] = rtDW.INPUT_1_1_1_c[0];
  tmp_5[1] = rtDW.INPUT_1_1_1_c[1];
  tmp_5[2] = rtDW.INPUT_1_1_1_c[2];
  tmp_5[3] = rtDW.INPUT_1_1_1_c[3];
  tmp_6[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_5[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_6[0];
  tmp_7 = rtM->massMatrixPr;
  tmp_3 = double_pointer_shift(tmp_7, rtDW.STATE_1_MASS_MATRIX_PR_m);
  simulationData->mData->mMassMatrixPr.mN = 4;
  simulationData->mData->mMassMatrixPr.mX = tmp_3;
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr_n;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_4 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator_b,
    NESL_SIM_MASSMATRIX, simulationData, diagnosticManager);
  if (tmp_4 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(rtM, msg_0);
    }
  }
}

void local_evaluateMassMatrix(RTWSolverInfo *si, real_T *Mdest )
{
  /* Refresh global mass matrix */
  solenoid_valve_curtain_v1_109_massmatrix();

  /* Copy the mass matrix from system to the destination, if needed. */
  if (Mdest != rtsiGetSolverMassMatrixPr(si)) {
    real_T *Msrc = rtsiGetSolverMassMatrixPr(si);
    int_T nzmax = rtsiGetSolverMassMatrixNzMax(si);
    (void) memcpy(Mdest, Msrc,
                  (uint_T)nzmax*sizeof(real_T));
  }
}

void local_evaluateFminusMv(RTWSolverInfo *si, const real_T *v, real_T *fminusMv
  )
{
  /* Refresh forcing function */
  rtsiSetdX(si,fminusMv);
  solenoid_valve_curtain_v1_109_forcingfunction();

  /* Refresh global mass matrix */
  solenoid_valve_curtain_v1_109_massmatrix();

  /* Form f - M*v */
  {
    real_T *elptr = rtsiGetSolverMassMatrixPr(si);
    int_T *iptr = rtsiGetSolverMassMatrixIr(si);
    int_T *jc = rtsiGetSolverMassMatrixJc(si);
    int_T nx = 25;
    int_T col,row;
    for (col = 0; col < nx; col++) {
      for (row = jc[col]; row < jc[col+1]; row++) {
        fminusMv[*iptr++] -= (*v) * (*elptr++);
      }

      v++;
    }
  }
}

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *v, const real_T
                  *Fty, real_T *fac, real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 25;
  real_T *x = rtsiGetContStates(si);
  boolean_T *xdis = rtsiGetContStateDisabledPtr(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Zero column j of dFdy if state j is currently disabled. */
    if (xdis[j]) {
      (void) memset(p, 0,
                    (uint_T)nx*sizeof(p[0]));
      continue;
    }

    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    solenoid_valve_curtain_v1_109_step();
    local_evaluateFminusMv(si,v,p );
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14X fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  boolean_T *xdis = rtsiGetContStateDisabledPtr(si);
  int_T *Mpattern_ir = rtsiGetSolverMassMatrixIr(si);
  int_T *Mpattern_jc = rtsiGetSolverMassMatrixJc(si);
  real_T *M = id->M;
  real_T *M1 = id->M1;
  real_T *xdot = id->xdot;
  real_T *Edot = id->Edot;
  real_T *fminusMxdot = id->fminusMxdot;
  int_T col,row,rowidx;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 25;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  local_evaluateMassMatrix(si,M );
  rtsiSetdX(si, xdot);
  solenoid_valve_curtain_v1_109_derivatives();

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  solenoid_valve_curtain_v1_109_forcingfunction();

  /* Form fminusMxdot = f(x) - M(x)*xdot, d(fminusMxdot)/dx = df/dx - d(Mv)/dx */
  (void) memcpy(fminusMxdot, f0,
                (uint_T)nx*sizeof(real_T));
  for (col = 0; col < nx; col++) {
    for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
      real_T m_row_col = M[rowidx];
      row = Mpattern_ir[rowidx];
      fminusMxdot[row] -= m_row_col*xdot[col];
    }
  }

  local_numjac(si,x0,xdot,fminusMxdot,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*(uint_T)nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (col = 0, p = W; col < nx; col++, p += nx) {
      if (xdis[col]) {
        (void) memset(p, 0,
                      (uint_T)nx*sizeof(p[0]));
        p[col] = 1.0;
      } else {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          p[row] += m_row_col;
        }
      }
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      solenoid_valve_curtain_v1_109_step();
      solenoid_valve_curtain_v1_109_forcingfunction();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= m_row_col*xtmp[col];
        }
      }

      /* rhs = rhs - (Mtmp - M)*ztmp*h */
      local_evaluateMassMatrix(si,M1 );
      for (i = 0; i < rtsiGetSolverMassMatrixNzMax(si); i++) {
        M1[i] -= M[i];
      }

      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M1[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= hN*m_row_col*ztmp[col];
        }
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        solenoid_valve_curtain_v1_109_step();
        solenoid_valve_curtain_v1_109_forcingfunction();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (col = 0; col < nx; col++) {
            for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx
                 ++) {
              real_T m_row_col = M[rowidx];
              row = Mpattern_ir[rowidx];
              Delta[row] -= m_row_col*xtmp[col];
            }
          }
        }

        /* For state-dep.,  Mdel = M(ttmp,ytmp) - M */
        solenoid_valve_curtain_v1_109_step();
        local_evaluateMassMatrix(si,M1 );
        for (i = 0; i < rtsiGetSolverMassMatrixNzMax(si); i++) {
          M1[i] -= M[i];
        }

        /* rhs = rhs - Mdel*ztmp*h */
        for (col = 0; col < nx; col++) {
          for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++)
          {
            real_T m_row_col = M1[rowidx];
            row = Mpattern_ir[rowidx];
            Delta[row] -= hN*m_row_col*ztmp[col];
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }

    /* Extrapolate the derivative */
    for (i = 0; i < nx; i++) {
      xdot[i] = (x1[i] - x1start[i])/hN;
    }

    (void) memcpy(&(Edot[nx*j]), xdot,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        xdot[i] = Edot[nx*k+i] + coef*(Edot[nx*k+i] - Edot[nx*(k-1)+i]);
      }

      (void) memcpy(&(Edot[nx*(k-1)]), xdot,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* Extrapolated xdot */
  (void) memcpy(xdot, Edot,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S4>/MATLAB Function3'
 *    '<S5>/MATLAB Function1'
 */
static void MATLABFunction3(real_T rtu_A_actual_m2, real_T rtu_P0_Pa, real_T
  *rty_mdot_slugs)
{
  *rty_mdot_slugs = 0.9 * rtu_A_actual_m2 * rtu_P0_Pa * 0.002294709449415926 /
    0.4536 / 32.174;
}

/* Model step function */
void solenoid_valve_curtain_v1_109_step(void)
{
  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  {
    NeParameterBundle expl_temp;
    NeParameterBundle expl_temp_0;
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diag;
    NeuDiagnosticTree *diagTree;
    NeuDiagnosticTree *diagTree_0;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    NeuDiagnosticTree *diagnosticTree_2;
    char *msg;
    char *msg_0;
    char *msg_1;
    char *msg_2;
    char *msg_3;
    char *msg_4;
    real_T tmp_5[17];
    real_T tmp_7[17];
    real_T tmp_0[4];
    real_T tmp_3[4];
    real_T tmp[3];
    real_T tmp_2[3];
    real_T Nogasleaking;
    real_T TransportDelay;
    real_T TransportDelay1;
    real_T time;
    real_T time_0;
    real_T time_1;
    real_T time_2;
    real_T time_3;
    real_T time_4;
    real_T time_5;
    real_T time_6;
    real_T u0;
    int_T tmp_6[3];
    int_T tmp_8[3];
    int_T tmp_1[2];
    int_T tmp_4[2];
    int_T i;
    boolean_T first_output;
    boolean_T tmp_9;

    /* TransportDelay: '<Root>/Transport Delay' */
    TransportDelay = rt_TDelayInterpolate(rtM->Timing.t[0] - 0.005,
      rtDW.TransportDelay_RWORK[0],(real_T *)rtDW.TransportDelay_PWORK[0],
      rtDW.TransportDelay_IWORK[3],&rtDW.TransportDelay_IWORK[2],
      rtDW.TransportDelay_IWORK[0],rtDW.TransportDelay_IWORK[1],0.0,true,false);

    /* Gain: '<S5>/Gain' */
    rtDW.Gain = 24.0 * TransportDelay;

    /* SimscapeInputBlock: '<S23>/INPUT_1_1_1' */
    if (rtDW.INPUT_1_1_1_SimscapeInternalFir == 0.0) {
      rtDW.INPUT_1_1_1_SimscapeInternalFir = 1.0;
      rtX.solenoid_valve_curtain_v1_109so = rtDW.Gain;
    }

    rtDW.INPUT_1_1_1[0] = rtX.solenoid_valve_curtain_v1_109so;
    rtDW.INPUT_1_1_1[1] = (rtDW.Gain - rtX.solenoid_valve_curtain_v1_109so) *
      1000.0;
    rtDW.INPUT_1_1_1[2] = 0.0;
    rtDW.INPUT_1_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S23>/INPUT_1_1_1' */
    tmp_9 = (rtmIsMajorTimeStep(rtM) &&
             rtM->Timing.TaskCounters.TID[1] == 0);
    if (tmp_9) {
      /* SimscapeRtp: '<S19>/RTP_1' incorporates:
       *  Constant: '<S5>/Subsystem_around_RTP_926E7261_i'
       *  Constant: '<S5>/Subsystem_around_RTP_926E7261_vel'
       *  Constant: '<S5>/Subsystem_around_RTP_926E7261_x'
       */
      if (rtDW.RTP_1_SetParametersNeeded) {
        tmp[0] = 0.0;
        tmp[1] = 0.0;
        tmp[2] = 7.94;
        diag = (NeuDiagnosticManager *)rtDW.RTP_1_DiagMgr;
        diagTree = neu_diagnostic_manager_get_initial_tree(diag);
        expl_temp.mRealParameters.mN = 3;
        expl_temp.mRealParameters.mX = &tmp[0];
        expl_temp.mLogicalParameters.mN = 0;
        expl_temp.mLogicalParameters.mX = NULL;
        expl_temp.mIntegerParameters.mN = 0;
        expl_temp.mIntegerParameters.mX = NULL;
        expl_temp.mIndexParameters.mN = 0;
        expl_temp.mIndexParameters.mX = NULL;
        first_output = nesl_rtp_manager_set_rtps((NeslRtpManager *)
          rtDW.RTP_1_RtpManager, rtM->Timing.t[0], expl_temp, diag);
        if (!first_output) {
          first_output = error_buffer_is_empty(rtmGetErrorStatus(rtM));
          if (first_output) {
            msg = rtw_diagnostics_msg(diagTree);
            rtmSetErrorStatus(rtM, msg);
          }
        }
      }

      rtDW.RTP_1_SetParametersNeeded = false;

      /* End of SimscapeRtp: '<S19>/RTP_1' */
    }

    /* SimscapeExecutionBlock: '<S23>/STATE_1' incorporates:
     *  Clock: '<Root>/Clock1'
     *  SimscapeExecutionBlock: '<S14>/OUTPUT_1_0'
     *  SimscapeExecutionBlock: '<S14>/STATE_1'
     *  SimscapeExecutionBlock: '<S23>/OUTPUT_1_0'
     *  SimscapeRtp: '<S10>/RTP_1'
     */
    simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
    TransportDelay = rtM->Timing.t[0];
    time = TransportDelay;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 10;
    simulationData->mData->mContStates.mX =
      &rtX.solenoid_valve_curtain_v1_109_b[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 3;
    simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
    simulationData->mData->mSwitchingCoeffs.mN = 0;
    simulationData->mData->mSwitchingCoeffs.mX = &rtDW.STATE_1_SwtgCoeffs;
    simulationData->mData->mJacobianElems.mN = 0;
    simulationData->mData->mJacobianElems.mX = &rtDW.STATE_1_JacobElems;
    first_output = false;
    simulationData->mData->mFoundZcEvents = first_output;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
    first_output = false;
    simulationData->mData->mIsSolverAssertCheck = first_output;
    simulationData->mData->mIsSolverCheckingCIC = false;
    first_output = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
    simulationData->mData->mIsComputingJacobian = first_output;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&rtM->solverInfo);
    tmp_1[0] = 0;
    tmp_0[0] = rtDW.INPUT_1_1_1[0];
    tmp_0[1] = rtDW.INPUT_1_1_1[1];
    tmp_0[2] = rtDW.INPUT_1_1_1[2];
    tmp_0[3] = rtDW.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    simulationData->mData->mInputValues.mN = 4;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 2;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    simulationData->mData->mOutputs.mN = 13;
    simulationData->mData->mOutputs.mX = &rtDW.STATE_1[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    Nogasleaking = rtM->Timing.t[0];
    time_0 = Nogasleaking;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diag = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diag);
    i = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
      NESL_SIM_OUTPUTS, simulationData, diag);
    if (i != 0) {
      first_output = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (first_output) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg_0);
      }
    }

    /* End of SimscapeExecutionBlock: '<S23>/STATE_1' */

    /* TransportDelay: '<Root>/Transport Delay1' */
    TransportDelay1 = rt_TDelayInterpolate(rtM->Timing.t[0] - 0.005,
      rtDW.TransportDelay1_RWORK[0],(real_T *)rtDW.TransportDelay1_PWORK[0],
      rtDW.TransportDelay1_IWORK[3],&rtDW.TransportDelay1_IWORK[2],
      rtDW.TransportDelay1_IWORK[0],rtDW.TransportDelay1_IWORK[1],0.0,true,false);

    /* Gain: '<S4>/Gain9' */
    rtDW.Gain9 = 24.0 * TransportDelay1;

    /* SimscapeInputBlock: '<S14>/INPUT_1_1_1' */
    if (rtDW.INPUT_1_1_1_SimscapeInternalF_e == 0.0) {
      rtDW.INPUT_1_1_1_SimscapeInternalF_e = 1.0;
      rtX.solenoid_valve_curtain_v1_109So = rtDW.Gain9;
    }

    rtDW.INPUT_1_1_1_c[0] = rtX.solenoid_valve_curtain_v1_109So;
    rtDW.INPUT_1_1_1_c[1] = (rtDW.Gain9 - rtX.solenoid_valve_curtain_v1_109So) *
      1000.0;
    rtDW.INPUT_1_1_1_c[2] = 0.0;
    rtDW.INPUT_1_1_1_c[3] = 0.0;

    /* End of SimscapeInputBlock: '<S14>/INPUT_1_1_1' */
    if (tmp_9) {
      /* SimscapeRtp: '<S10>/RTP_1' incorporates:
       *  Constant: '<S4>/Subsystem_around_RTP_731D9D8D_i'
       *  Constant: '<S4>/Subsystem_around_RTP_731D9D8D_vel'
       *  Constant: '<S4>/Subsystem_around_RTP_731D9D8D_x'
       */
      if (rtDW.RTP_1_SetParametersNeeded_d) {
        tmp_2[0] = 0.0;
        tmp_2[1] = 0.0;
        tmp_2[2] = 7.94;
        diag = (NeuDiagnosticManager *)rtDW.RTP_1_DiagMgr_p;
        diagTree_0 = neu_diagnostic_manager_get_initial_tree(diag);
        expl_temp_0.mRealParameters.mN = 3;
        expl_temp_0.mRealParameters.mX = &tmp_2[0];
        expl_temp_0.mLogicalParameters.mN = 0;
        expl_temp_0.mLogicalParameters.mX = NULL;
        expl_temp_0.mIntegerParameters.mN = 0;
        expl_temp_0.mIntegerParameters.mX = NULL;
        expl_temp_0.mIndexParameters.mN = 0;
        expl_temp_0.mIndexParameters.mX = NULL;
        first_output = nesl_rtp_manager_set_rtps((NeslRtpManager *)
          rtDW.RTP_1_RtpManager_d, TransportDelay, expl_temp_0, diag);
        if (!first_output) {
          first_output = error_buffer_is_empty(rtmGetErrorStatus(rtM));
          if (first_output) {
            msg_1 = rtw_diagnostics_msg(diagTree_0);
            rtmSetErrorStatus(rtM, msg_1);
          }
        }
      }

      rtDW.RTP_1_SetParametersNeeded_d = false;
    }

    /* SimscapeExecutionBlock: '<S14>/STATE_1' */
    simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData_f;
    time_1 = TransportDelay;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 10;
    simulationData->mData->mContStates.mX =
      &rtX.solenoid_valve_curtain_v1_109_l[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete_c;
    simulationData->mData->mModeVector.mN = 3;
    simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes_o[0];
    simulationData->mData->mSwitchingCoeffs.mN = 0;
    simulationData->mData->mSwitchingCoeffs.mX = &rtDW.STATE_1_SwtgCoeffs_k;
    simulationData->mData->mJacobianElems.mN = 0;
    simulationData->mData->mJacobianElems.mX = &rtDW.STATE_1_JacobElems_h;
    first_output = false;
    simulationData->mData->mFoundZcEvents = first_output;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
    first_output = false;
    simulationData->mData->mIsSolverAssertCheck = first_output;
    simulationData->mData->mIsSolverCheckingCIC = false;
    first_output = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
    simulationData->mData->mIsComputingJacobian = first_output;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&rtM->solverInfo);
    tmp_4[0] = 0;
    tmp_3[0] = rtDW.INPUT_1_1_1_c[0];
    tmp_3[1] = rtDW.INPUT_1_1_1_c[1];
    tmp_3[2] = rtDW.INPUT_1_1_1_c[2];
    tmp_3[3] = rtDW.INPUT_1_1_1_c[3];
    tmp_4[1] = 4;
    simulationData->mData->mInputValues.mN = 4;
    simulationData->mData->mInputValues.mX = &tmp_3[0];
    simulationData->mData->mInputOffsets.mN = 2;
    simulationData->mData->mInputOffsets.mX = &tmp_4[0];
    simulationData->mData->mOutputs.mN = 13;
    simulationData->mData->mOutputs.mX = &rtDW.STATE_1_c[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_2 = Nogasleaking;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_2;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diag = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr_n;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diag);
    i = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator_b,
      NESL_SIM_OUTPUTS, simulationData, diag);
    if (i != 0) {
      first_output = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (first_output) {
        msg_2 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(rtM, msg_2);
      }
    }

    /* SimscapeExecutionBlock: '<S14>/OUTPUT_1_0' */
    simulationData = (NeslSimulationData *)rtDW.OUTPUT_1_0_SimData;
    time_3 = TransportDelay;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_3;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &rtDW.OUTPUT_1_0_Modes;
    simulationData->mData->mSwitchingCoeffs.mN = 0;
    simulationData->mData->mSwitchingCoeffs.mX = &rtDW.OUTPUT_1_0_SwtgCoeffs;
    simulationData->mData->mJacobianElems.mN = 0;
    simulationData->mData->mJacobianElems.mX = &rtDW.OUTPUT_1_0_JacobElems;
    first_output = false;
    simulationData->mData->mFoundZcEvents = first_output;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
    first_output = false;
    simulationData->mData->mIsSolverAssertCheck = first_output;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&rtM->solverInfo);
    tmp_6[0] = 0;
    tmp_5[0] = rtDW.INPUT_1_1_1_c[0];
    tmp_5[1] = rtDW.INPUT_1_1_1_c[1];
    tmp_5[2] = rtDW.INPUT_1_1_1_c[2];
    tmp_5[3] = rtDW.INPUT_1_1_1_c[3];
    tmp_6[1] = 4;
    memcpy(&tmp_5[4], &rtDW.STATE_1_c[0], 13U * sizeof(real_T));
    tmp_6[2] = 17;
    simulationData->mData->mInputValues.mN = 17;
    simulationData->mData->mInputValues.mX = &tmp_5[0];
    simulationData->mData->mInputOffsets.mN = 3;
    simulationData->mData->mInputOffsets.mX = &tmp_6[0];
    simulationData->mData->mOutputs.mN = 2;
    simulationData->mData->mOutputs.mX = &rtDW.OUTPUT_1_0[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_4 = Nogasleaking;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_4;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diag = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diag);
    i = ne_simulator_method((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator,
      NESL_SIM_OUTPUTS, simulationData, diag);
    if (i != 0) {
      first_output = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (first_output) {
        msg_3 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(rtM, msg_3);
      }
    }

    /* SimscapeExecutionBlock: '<S23>/OUTPUT_1_0' */
    simulationData = (NeslSimulationData *)rtDW.OUTPUT_1_0_SimData_n;
    time_5 = TransportDelay;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_5;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.OUTPUT_1_0_Discrete_d;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &rtDW.OUTPUT_1_0_Modes_k;
    simulationData->mData->mSwitchingCoeffs.mN = 0;
    simulationData->mData->mSwitchingCoeffs.mX = &rtDW.OUTPUT_1_0_SwtgCoeffs_d;
    simulationData->mData->mJacobianElems.mN = 0;
    simulationData->mData->mJacobianElems.mX = &rtDW.OUTPUT_1_0_JacobElems_f;
    first_output = false;
    simulationData->mData->mFoundZcEvents = first_output;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
    first_output = false;
    simulationData->mData->mIsSolverAssertCheck = first_output;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&rtM->solverInfo);
    tmp_8[0] = 0;
    tmp_7[0] = rtDW.INPUT_1_1_1[0];
    tmp_7[1] = rtDW.INPUT_1_1_1[1];
    tmp_7[2] = rtDW.INPUT_1_1_1[2];
    tmp_7[3] = rtDW.INPUT_1_1_1[3];
    tmp_8[1] = 4;
    memcpy(&tmp_7[4], &rtDW.STATE_1[0], 13U * sizeof(real_T));
    tmp_8[2] = 17;
    simulationData->mData->mInputValues.mN = 17;
    simulationData->mData->mInputValues.mX = &tmp_7[0];
    simulationData->mData->mInputOffsets.mN = 3;
    simulationData->mData->mInputOffsets.mX = &tmp_8[0];
    simulationData->mData->mOutputs.mN = 2;
    simulationData->mData->mOutputs.mX = &rtDW.OUTPUT_1_0_o[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    simulationData->mData->mDstateHasChanged = false;
    time_6 = Nogasleaking;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_6;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mHadEvents = false;
    diag = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr_f;
    diagnosticTree_2 = neu_diagnostic_manager_get_initial_tree(diag);
    i = ne_simulator_method((NeslSimulator *)rtDW.OUTPUT_1_0_Simulator_a,
      NESL_SIM_OUTPUTS, simulationData, diag);
    if (i != 0) {
      first_output = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (first_output) {
        msg_4 = rtw_diagnostics_msg(diagnosticTree_2);
        rtmSetErrorStatus(rtM, msg_4);
      }
    }

    /* Saturate: '<S5>/No gas leaking ' */
    u0 = rtDW.OUTPUT_1_0_o[1];
    if (u0 > 0.0) {
      u0 = 0.0;
    } else if (u0 < -100.0) {
      u0 = -100.0;
    }

    /* Gain: '<S5>/Curtain area' incorporates:
     *  Abs: '<S5>/Lift'
     *  Saturate: '<S5>/No gas leaking '
     */
    u0 = 0.00249364 * fabs(u0);

    /* Saturate: '<S5>/Orifice limit' */
    if (u0 > 4.94832E-5) {
      u0 = 4.94832E-5;
    }

    /* MATLAB Function: '<S5>/MATLAB Function1' incorporates:
     *  Constant: '<S5>/P0_Pa'
     *  Saturate: '<S5>/Orifice limit'
     */
    MATLABFunction3(u0, 405067.15, &TransportDelay1);

    /* Gain: '<Root>/Gain7' incorporates:
     *  Gain: '<S5>/F_actual_lbf'
     */
    Nogasleaking = 2091.31 * TransportDelay1 * 0.4166666666666667;

    /* Saturate: '<S4>/No gas leaking' */
    u0 = rtDW.OUTPUT_1_0[1];
    if (u0 > 0.0) {
      u0 = 0.0;
    } else if (u0 < -100.0) {
      u0 = -100.0;
    }

    /* Gain: '<S4>/Curtain area1' incorporates:
     *  Abs: '<S4>/Lift1'
     *  Saturate: '<S4>/No gas leaking'
     */
    u0 = 0.00249364 * fabs(u0);

    /* Saturate: '<S4>/Orifice limit1' */
    if (u0 > 4.94832E-5) {
      u0 = 4.94832E-5;
    }

    /* MATLAB Function: '<S4>/MATLAB Function3' incorporates:
     *  Constant: '<S4>/P0_Pa'
     *  Saturate: '<S4>/Orifice limit1'
     */
    MATLABFunction3(u0, 405067.15, &TransportDelay1);

    /* Gain: '<Root>/Ixxp' incorporates:
     *  Gain: '<Root>/Gain6'
     *  Gain: '<S4>/Thrust Isp*g0'
     *  Sum: '<Root>/Add'
     */
    rtDW.AngularAccleration = (Nogasleaking - 2091.31 * TransportDelay1 *
      0.4166666666666667) * 0.0792743044456845;

    /* MATLAB Function: '<Root>/Generate Trace' */
    if (TransportDelay < 1.0) {
      TransportDelay1 = 0.0;
      TransportDelay = 0.0;
    } else if (TransportDelay <= 11.0) {
      TransportDelay1 = (TransportDelay - 1.0) * 18.0;
      TransportDelay = 18.0;
    } else {
      TransportDelay1 = 180.0;
      TransportDelay = 0.0;
    }

    /* End of MATLAB Function: '<Root>/Generate Trace' */

    /* Integrator: '<Root>/Accel>Vel' */
    rtDW.Vel = rtX.AccelVel_CSTATE;
    if (tmp_9) {
      /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
       *  Gain: '<Root>/Gain2'
       *  Gain: '<Root>/Gain3'
       *  Integrator: '<Root>/Vel>Pos'
       */
      TransportDelay1 = (0.017453292519943295 * TransportDelay - rtDW.Vel) *
        0.477 + (0.017453292519943295 * TransportDelay1 - rtX.VelPos_CSTATE);
      if (rtDW.pulse_timer > 0.0) {
        rtDW.pulse_timer -= 0.005;
      } else if (rtDW.valve_state == 0.0) {
        if (TransportDelay1 > 0.02) {
          rtDW.valve_state = 1.0;
          rtDW.pulse_timer = 0.1;
        } else if (TransportDelay1 < -0.02) {
          rtDW.valve_state = -1.0;
          rtDW.pulse_timer = 0.1;
        }
      } else if (rtDW.valve_state == 1.0) {
        if (TransportDelay1 < 0.01) {
          rtDW.valve_state = 0.0;
        }
      } else if ((rtDW.valve_state == -1.0) && (TransportDelay1 > -0.01)) {
        rtDW.valve_state = 0.0;
      }

      rtDW.valve_cw = (rtDW.valve_state == 1.0);
      rtDW.valve_ccw = (rtDW.valve_state == -1.0);

      /* End of MATLAB Function: '<Root>/MATLAB Function' */

      /* MATLAB Function: '<Root>/AC' */
      if (((rtDW.valve_cw == 1.0) && (rtDW.prev_cw == 0.0)) || ((rtDW.valve_ccw ==
            1.0) && (rtDW.prev_ccw == 0.0))) {
        rtDW.total++;
      }

      rtDW.prev_cw = rtDW.valve_cw;
      rtDW.prev_ccw = rtDW.valve_ccw;

      /* End of MATLAB Function: '<Root>/AC' */
    }

    /* Gain: '<Root>/Mdot' incorporates:
     *  Abs: '<Root>/Abs'
     */
    rtDW.Mdot = 0.0028364588884960693 * TransportDelay;
  }

  if (rtmIsMajorTimeStep(rtM)) {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    real_T tmp_0[4];
    real_T tmp_2[4];
    real_T time;
    real_T time_0;
    real_T time_tmp;
    int_T tmp_1[2];
    int_T tmp_3[2];
    int_T i;
    boolean_T tmp;

    /* Update for TransportDelay: '<Root>/Transport Delay' incorporates:
     *  SimscapeExecutionBlock: '<S23>/STATE_1'
     */
    if (rtDW.TransportDelay_IWORK[1] < rtDW.TransportDelay_IWORK[3] - 1) {
      rtDW.TransportDelay_IWORK[1]++;
    } else {
      rtDW.TransportDelay_IWORK[1] = 0;
    }

    if (rtDW.TransportDelay_IWORK[0] == rtDW.TransportDelay_IWORK[1]) {
      if (rtDW.TransportDelay_IWORK[0] < rtDW.TransportDelay_IWORK[3] - 1) {
        rtDW.TransportDelay_IWORK[0]++;
      } else {
        rtDW.TransportDelay_IWORK[0] = 0;
      }
    }

    ((real_T *)rtDW.TransportDelay_PWORK[0])[rtDW.TransportDelay_IWORK[1]] =
      rtDW.valve_cw;
    time_tmp = rtM->Timing.t[0];
    ((real_T *)rtDW.TransportDelay_PWORK[0])[rtDW.TransportDelay_IWORK[1] +
      rtDW.TransportDelay_IWORK[3]] = time_tmp;

    /* End of Update for TransportDelay: '<Root>/Transport Delay' */

    /* Update for SimscapeExecutionBlock: '<S23>/STATE_1' */
    simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
    time = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 10;
    simulationData->mData->mContStates.mX =
      &rtX.solenoid_valve_curtain_v1_109_b[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 3;
    simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
    simulationData->mData->mSwitchingCoeffs.mN = 0;
    simulationData->mData->mSwitchingCoeffs.mX = &rtDW.STATE_1_SwtgCoeffs;
    simulationData->mData->mJacobianElems.mN = 0;
    simulationData->mData->mJacobianElems.mX = &rtDW.STATE_1_JacobElems;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&rtM->solverInfo);
    tmp_1[0] = 0;
    tmp_0[0] = rtDW.INPUT_1_1_1[0];
    tmp_0[1] = rtDW.INPUT_1_1_1[1];
    tmp_0[2] = rtDW.INPUT_1_1_1[2];
    tmp_0[3] = rtDW.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    simulationData->mData->mInputValues.mN = 4;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 2;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
      NESL_SIM_UPDATE, simulationData, diagnosticManager);
    if (i != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    /* Update for TransportDelay: '<Root>/Transport Delay1' */
    if (rtDW.TransportDelay1_IWORK[1] < rtDW.TransportDelay1_IWORK[3] - 1) {
      rtDW.TransportDelay1_IWORK[1]++;
    } else {
      rtDW.TransportDelay1_IWORK[1] = 0;
    }

    if (rtDW.TransportDelay1_IWORK[0] == rtDW.TransportDelay1_IWORK[1]) {
      if (rtDW.TransportDelay1_IWORK[0] < rtDW.TransportDelay1_IWORK[3] - 1) {
        rtDW.TransportDelay1_IWORK[0]++;
      } else {
        rtDW.TransportDelay1_IWORK[0] = 0;
      }
    }

    ((real_T *)rtDW.TransportDelay1_PWORK[0])[rtDW.TransportDelay1_IWORK[1]] =
      rtDW.valve_ccw;
    ((real_T *)rtDW.TransportDelay1_PWORK[0])[rtDW.TransportDelay1_IWORK[1] +
      rtDW.TransportDelay1_IWORK[3]] = time_tmp;

    /* End of Update for TransportDelay: '<Root>/Transport Delay1' */

    /* Update for SimscapeExecutionBlock: '<S14>/STATE_1' */
    simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData_f;
    time_0 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 10;
    simulationData->mData->mContStates.mX =
      &rtX.solenoid_valve_curtain_v1_109_l[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete_c;
    simulationData->mData->mModeVector.mN = 3;
    simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes_o[0];
    simulationData->mData->mSwitchingCoeffs.mN = 0;
    simulationData->mData->mSwitchingCoeffs.mX = &rtDW.STATE_1_SwtgCoeffs_k;
    simulationData->mData->mJacobianElems.mN = 0;
    simulationData->mData->mJacobianElems.mX = &rtDW.STATE_1_JacobElems_h;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&rtM->solverInfo);
    tmp_3[0] = 0;
    tmp_2[0] = rtDW.INPUT_1_1_1_c[0];
    tmp_2[1] = rtDW.INPUT_1_1_1_c[1];
    tmp_2[2] = rtDW.INPUT_1_1_1_c[2];
    tmp_2[3] = rtDW.INPUT_1_1_1_c[3];
    tmp_3[1] = 4;
    simulationData->mData->mInputValues.mN = 4;
    simulationData->mData->mInputValues.mX = &tmp_2[0];
    simulationData->mData->mInputOffsets.mN = 2;
    simulationData->mData->mInputOffsets.mX = &tmp_3[0];
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr_n;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator_b,
      NESL_SIM_UPDATE, simulationData, diagnosticManager);
    if (i != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(rtM, msg_0);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S14>/STATE_1' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      rtM->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void solenoid_valve_curtain_v1_109_derivatives(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  XDot *_rtXdot;
  char *msg;
  char *msg_0;
  real_T tmp_0[4];
  real_T tmp_3[4];
  real_T time;
  real_T time_0;
  real_T time_tmp;
  int32_T tmp_2;
  int_T tmp_1[2];
  int_T tmp_4[2];
  boolean_T tmp;
  _rtXdot = ((XDot *) rtM->derivs);

  /* Derivatives for SimscapeInputBlock: '<S23>/INPUT_1_1_1' */
  _rtXdot->solenoid_valve_curtain_v1_109so = (rtDW.Gain -
    rtX.solenoid_valve_curtain_v1_109so) * 1000.0;

  /* Derivatives for SimscapeExecutionBlock: '<S23>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S14>/STATE_1'
   */
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
  time_tmp = rtM->Timing.t[0];
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 10;
  simulationData->mData->mContStates.mX = &rtX.solenoid_valve_curtain_v1_109_b[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 3;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes[0];
  simulationData->mData->mSwitchingCoeffs.mN = 0;
  simulationData->mData->mSwitchingCoeffs.mX = &rtDW.STATE_1_SwtgCoeffs;
  simulationData->mData->mJacobianElems.mN = 0;
  simulationData->mData->mJacobianElems.mX = &rtDW.STATE_1_JacobElems;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&rtM->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = rtDW.INPUT_1_1_1[0];
  tmp_0[1] = rtDW.INPUT_1_1_1[1];
  tmp_0[2] = rtDW.INPUT_1_1_1[2];
  tmp_0[3] = rtDW.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 10;
  simulationData->mData->mDx.mX = &_rtXdot->solenoid_valve_curtain_v1_109_b[0];
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
    NESL_SIM_DERIVATIVES, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(rtM, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S23>/STATE_1' */

  /* Derivatives for SimscapeInputBlock: '<S14>/INPUT_1_1_1' */
  _rtXdot->solenoid_valve_curtain_v1_109So = (rtDW.Gain9 -
    rtX.solenoid_valve_curtain_v1_109So) * 1000.0;

  /* Derivatives for SimscapeExecutionBlock: '<S14>/STATE_1' */
  simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData_f;
  time_0 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 10;
  simulationData->mData->mContStates.mX = &rtX.solenoid_valve_curtain_v1_109_l[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete_c;
  simulationData->mData->mModeVector.mN = 3;
  simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes_o[0];
  simulationData->mData->mSwitchingCoeffs.mN = 0;
  simulationData->mData->mSwitchingCoeffs.mX = &rtDW.STATE_1_SwtgCoeffs_k;
  simulationData->mData->mJacobianElems.mN = 0;
  simulationData->mData->mJacobianElems.mX = &rtDW.STATE_1_JacobElems_h;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mHadEvents = false;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(rtM);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&rtM->solverInfo);
  tmp_4[0] = 0;
  tmp_3[0] = rtDW.INPUT_1_1_1_c[0];
  tmp_3[1] = rtDW.INPUT_1_1_1_c[1];
  tmp_3[2] = rtDW.INPUT_1_1_1_c[2];
  tmp_3[3] = rtDW.INPUT_1_1_1_c[3];
  tmp_4[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_3[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_4[0];
  simulationData->mData->mDx.mN = 10;
  simulationData->mData->mDx.mX = &_rtXdot->solenoid_valve_curtain_v1_109_l[0];
  diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr_n;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator_b,
    NESL_SIM_DERIVATIVES, simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
    if (tmp) {
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(rtM, msg_0);
    }
  }

  /* Derivatives for Integrator: '<Root>/Vel>Pos' */
  _rtXdot->VelPos_CSTATE = rtDW.Vel;

  /* Derivatives for Integrator: '<Root>/Accel>Vel' */
  _rtXdot->AccelVel_CSTATE = rtDW.AngularAccleration;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = rtDW.Mdot;
}

/* Model initialize function */
void solenoid_valve_curtain_v1_109_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&rtM->solverInfo, (boolean_T**)
      &rtM->contStateDisabled);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetSolverMassMatrixIr(&rtM->solverInfo, rtMassMatrix.ir);
    rtsiSetSolverMassMatrixJc(&rtM->solverInfo, rtMassMatrix.jc);
    rtsiSetSolverMassMatrixPr(&rtM->solverInfo, rtMassMatrix.pr);
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&rtM->solverInfo, false);
  rtsiSetIsContModeFrozen(&rtM->solverInfo, false);
  rtM->intgData.x0 = rtM->odeX0;
  rtM->intgData.f0 = rtM->odeF0;
  rtM->intgData.x1start = rtM->odeX1START;
  rtM->intgData.f1 = rtM->odeF1;
  rtM->intgData.Delta = rtM->odeDELTA;
  rtM->intgData.E = rtM->odeE;
  rtM->intgData.fac = rtM->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = rtM->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(rtM->odeFAC)/sizeof(real_T)); i++) {
      f[i] = 1.5e-8;
    }
  }

  rtM->intgData.DFDX = rtM->odeDFDX;
  rtM->intgData.W = rtM->odeW;
  rtM->intgData.pivots = rtM->odePIVOTS;
  rtM->intgData.xtmp = rtM->odeXTMP;
  rtM->intgData.ztmp = rtM->odeZTMP;
  rtM->intgData.M = rtM->odeMASSMATRIX_M;
  rtM->intgData.M1 = rtM->odeMASSMATRIX_M1;
  rtM->intgData.xdot = rtM->odeXDOT;
  rtM->intgData.Edot = rtM->odeEDOT;
  rtM->intgData.fminusMxdot = rtM->odeFMXDOT;
  rtM->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&rtM->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&rtM->solverInfo, 1);
  rtM->contStates = ((X *) &rtX);
  rtM->contStateDisabled = ((XDis *) &rtXDis);
  rtM->Timing.tStart = (0.0);
  rtM->massMatrixType = ((ssMatrixType)3);
  rtM->massMatrixNzMax = (13);
  rtM->massMatrixIr = (rtMassMatrix.ir);
  rtM->massMatrixJc = (rtMassMatrix.jc);
  rtM->massMatrixPr = (rtMassMatrix.pr);
  rtsiSetSolverMassMatrixType(&rtM->solverInfo, (ssMatrixType)3);
  rtsiSetSolverMassMatrixNzMax(&rtM->solverInfo, 13);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode14x");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.005;

  /* Root-level init GlobalMassMatrixPr offset */
  {
    rtDW.STATE_1_MASS_MATRIX_PR = 1;   /* '<S23>/STATE_1' */
    rtDW.STATE_1_MASS_MATRIX_PR_m = 6; /* '<S14>/STATE_1' */
  }

  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeModelParameters modelParameters_2;
    NeslRtpManager *manager;
    NeslRtpManager *manager_0;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp_0;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    NeuDiagnosticTree *diagnosticTree_2;
    char *msg;
    char *msg_0;
    char *msg_1;
    char *msg_2;
    real_T fixedStepSize;
    real_T tmp_7;
    int_T i;
    int_T startIdx;
    int_T tmp_3;
    int_T tmp_4;
    int_T tmp_5;
    int_T tmp_6;
    boolean_T tmp;
    boolean_T tmp_2;

    /* Start for TransportDelay: '<Root>/Transport Delay' incorporates:
     *  TransportDelay: '<Root>/Transport Delay1'
     * */
    rtDW.TransportDelay_RWORK[0] = 0.0;
    rtDW.TransportDelay_IWORK[0] = 0;
    rtDW.TransportDelay_IWORK[1] = 0;
    rtDW.TransportDelay_IWORK[2] = 0;
    rtDW.TransportDelay_IWORK[3] = 1024;
    rtDW.TransportDelay_PWORK[0] = &rtDW.TransportDelay_RWORK[1];
    ((real_T *)rtDW.TransportDelay_PWORK[0])[0] = 0.0;
    tmp_7 = rtM->Timing.t[0];
    ((real_T *)rtDW.TransportDelay_PWORK[0])[rtDW.TransportDelay_IWORK[3]] =
      tmp_7;

    /* Start for SimscapeRtp: '<S19>/RTP_1' */
    manager_0 = nesl_lease_rtp_manager(
      "solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration_1", 0);
    manager = manager_0;
    tmp = pointer_is_null(manager_0);
    if (tmp) {
      solenoid_valve_curtain_v1_109_96c7c979_1_gateway();
      manager = nesl_lease_rtp_manager(
        "solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration_1", 0);
    }

    rtDW.RTP_1_RtpManager = (void *)manager;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.RTP_1_DiagMgr = (void *)diagnosticManager;
    rtDW.RTP_1_SetParametersNeeded = true;

    /* End of Start for SimscapeRtp: '<S19>/RTP_1' */

    /* Start for SimscapeExecutionBlock: '<S23>/STATE_1' */
    tmp_0 = nesl_lease_simulator(
      "solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration_1", 0,
      0);
    rtDW.STATE_1_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(rtDW.STATE_1_Simulator);
    if (tmp) {
      solenoid_valve_curtain_v1_109_96c7c979_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration_1", 0,
        0);
      rtDW.STATE_1_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mFixedStepSize = 0.001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_ON;
    modelParameters.mRTWModifiedTimeStamp = 7.14452925E+8;
    modelParameters.mZcDisabled = true;
    modelParameters.mUseModelRefSolver = false;
    tmp = false;
    if (tmp) {
      fixedStepSize = (rtInf);
    } else {
      fixedStepSize = 0.005;
    }

    modelParameters.mFixedStepSize = fixedStepSize;
    tmp = false;
    modelParameters.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters.mIsUsingODEN = tmp;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    startIdx = nesl_initialize_simulator((NeslSimulator *)rtDW.STATE_1_Simulator,
      &modelParameters, diagnosticManager);
    if (startIdx != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S23>/STATE_1' */

    /* Start for TransportDelay: '<Root>/Transport Delay1' */
    rtDW.TransportDelay1_RWORK[0] = 0.0;
    rtDW.TransportDelay1_IWORK[0] = 0;
    rtDW.TransportDelay1_IWORK[1] = 0;
    rtDW.TransportDelay1_IWORK[2] = 0;
    rtDW.TransportDelay1_IWORK[3] = 1024;
    rtDW.TransportDelay1_PWORK[0] = &rtDW.TransportDelay1_RWORK[1];
    ((real_T *)rtDW.TransportDelay1_PWORK[0])[0] = 0.0;
    ((real_T *)rtDW.TransportDelay1_PWORK[0])[rtDW.TransportDelay1_IWORK[3]] =
      tmp_7;

    /* Start for SimscapeRtp: '<S10>/RTP_1' */
    manager_0 = nesl_lease_rtp_manager(
      "solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1_1", 0);
    manager = manager_0;
    tmp = pointer_is_null(manager_0);
    if (tmp) {
      solenoid_valve_curtain_v1_109_77b42695_1_gateway();
      manager = nesl_lease_rtp_manager(
        "solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1_1",
        0);
    }

    rtDW.RTP_1_RtpManager_d = (void *)manager;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.RTP_1_DiagMgr_p = (void *)diagnosticManager;
    rtDW.RTP_1_SetParametersNeeded_d = true;

    /* End of Start for SimscapeRtp: '<S10>/RTP_1' */

    /* Start for SimscapeExecutionBlock: '<S14>/STATE_1' */
    tmp_0 = nesl_lease_simulator(
      "solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1_1", 0,
      0);
    rtDW.STATE_1_Simulator_b = (void *)tmp_0;
    tmp = pointer_is_null(rtDW.STATE_1_Simulator_b);
    if (tmp) {
      solenoid_valve_curtain_v1_109_77b42695_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1_1",
        0, 0);
      rtDW.STATE_1_Simulator_b = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.STATE_1_SimData_f = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.STATE_1_DiagMgr_n = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mFixedStepSize = 0.001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_ON;
    modelParameters_0.mRTWModifiedTimeStamp = 7.14452925E+8;
    modelParameters_0.mZcDisabled = true;
    modelParameters_0.mUseModelRefSolver = false;
    tmp = false;
    if (tmp) {
      fixedStepSize = (rtInf);
    } else {
      fixedStepSize = 0.005;
    }

    modelParameters_0.mFixedStepSize = fixedStepSize;
    tmp = false;
    modelParameters_0.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_0.mIsUsingODEN = tmp;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr_n;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    startIdx = nesl_initialize_simulator((NeslSimulator *)
      rtDW.STATE_1_Simulator_b, &modelParameters_0, diagnosticManager);
    if (startIdx != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(rtM, msg_0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S14>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S14>/OUTPUT_1_0' */
    tmp_0 = nesl_lease_simulator(
      "solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1_1", 1,
      0);
    rtDW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(rtDW.OUTPUT_1_0_Simulator);
    if (tmp) {
      solenoid_valve_curtain_v1_109_77b42695_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1_1",
        1, 0);
      rtDW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_1.mSolverAbsTol = 0.001;
    modelParameters_1.mSolverRelTol = 0.001;
    modelParameters_1.mVariableStepSolver = false;
    modelParameters_1.mIsUsingODEN = false;
    modelParameters_1.mFixedStepSize = 0.001;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_ON;
    modelParameters_1.mRTWModifiedTimeStamp = 7.14452925E+8;
    modelParameters_1.mZcDisabled = true;
    modelParameters_1.mUseModelRefSolver = false;
    tmp = false;
    if (tmp) {
      fixedStepSize = (rtInf);
    } else {
      fixedStepSize = 0.005;
    }

    modelParameters_1.mFixedStepSize = fixedStepSize;
    tmp = false;
    modelParameters_1.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_1.mIsUsingODEN = tmp;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    startIdx = nesl_initialize_simulator((NeslSimulator *)
      rtDW.OUTPUT_1_0_Simulator, &modelParameters_1, diagnosticManager);
    if (startIdx != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp) {
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(rtM, msg_1);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S14>/OUTPUT_1_0' */

    /* Start for SimscapeExecutionBlock: '<S23>/OUTPUT_1_0' */
    tmp_0 = nesl_lease_simulator(
      "solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration_1", 1,
      0);
    rtDW.OUTPUT_1_0_Simulator_a = (void *)tmp_0;
    tmp = pointer_is_null(rtDW.OUTPUT_1_0_Simulator_a);
    if (tmp) {
      solenoid_valve_curtain_v1_109_96c7c979_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration_1", 1,
        0);
      rtDW.OUTPUT_1_0_Simulator_a = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.OUTPUT_1_0_SimData_n = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.OUTPUT_1_0_DiagMgr_f = (void *)diagnosticManager;
    modelParameters_2.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_2.mSolverAbsTol = 0.001;
    modelParameters_2.mSolverRelTol = 0.001;
    modelParameters_2.mVariableStepSolver = false;
    modelParameters_2.mIsUsingODEN = false;
    modelParameters_2.mFixedStepSize = 0.001;
    modelParameters_2.mStartTime = 0.0;
    modelParameters_2.mLoadInitialState = false;
    modelParameters_2.mUseSimState = false;
    modelParameters_2.mLinTrimCompile = false;
    modelParameters_2.mLoggingMode = SSC_LOGGING_ON;
    modelParameters_2.mRTWModifiedTimeStamp = 7.14452925E+8;
    modelParameters_2.mZcDisabled = true;
    modelParameters_2.mUseModelRefSolver = false;
    tmp = false;
    if (tmp) {
      fixedStepSize = (rtInf);
    } else {
      fixedStepSize = 0.005;
    }

    modelParameters_2.mFixedStepSize = fixedStepSize;
    tmp = false;
    modelParameters_2.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_2.mIsUsingODEN = tmp;
    modelParameters_2.mLoadInitialState = false;
    modelParameters_2.mUseSimState = false;
    modelParameters_2.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.OUTPUT_1_0_DiagMgr_f;
    diagnosticTree_2 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    startIdx = nesl_initialize_simulator((NeslSimulator *)
      rtDW.OUTPUT_1_0_Simulator_a, &modelParameters_2, diagnosticManager);
    if (startIdx != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp) {
        msg_2 = rtw_diagnostics_msg(diagnosticTree_2);
        rtmSetErrorStatus(rtM, msg_2);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S23>/OUTPUT_1_0' */

    /* InitializeConditions for TransportDelay: '<Root>/Transport Delay' */
    rtDW.TransportDelay_IWORK[0] = 0;
    rtDW.TransportDelay_IWORK[1] = 0;
    rtDW.TransportDelay_IWORK[2] = 0;
    ((real_T *)rtDW.TransportDelay_PWORK[0])[rtDW.TransportDelay_IWORK[1]] = 0.0;
    ((real_T *)rtDW.TransportDelay_PWORK[0])[rtDW.TransportDelay_IWORK[1] +
      rtDW.TransportDelay_IWORK[3]] = tmp_7;

    /* InitializeConditions for SimscapeExecutionBlock: '<S23>/STATE_1' */
    tmp = false;
    tmp_2 = false;
    if (tmp_2 || tmp) {
      startIdx = strcmp(rtsiGetSolverName(&rtM->solverInfo), "daessc");
      i = strcmp(rtsiGetSolverName(&rtM->solverInfo), "ode14x");
      tmp_3 = strcmp(rtsiGetSolverName(&rtM->solverInfo), "ode15s");
      tmp_4 = strcmp(rtsiGetSolverName(&rtM->solverInfo), "ode1be");
      tmp_5 = strcmp(rtsiGetSolverName(&rtM->solverInfo), "ode23t");
      tmp_6 = strcmp(rtsiGetSolverName(&rtM->solverInfo), "odeN");
      if ((boolean_T)((startIdx != 0) & (i != 0) & (tmp_3 != 0) & (tmp_4 != 0) &
                      (tmp_5 != 0) & (tmp_6 != 0))) {
        rtmSetErrorStatus(rtM,
                          "Detected inconsistent solvers in the model reference hierarchy. Model built with ode14x requires one of {daessc, ode14x, ode15s, ode1be, ode23t, odeN} solvers to run. Use one of the required solvers in the top model.");
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S23>/STATE_1' */

    /* InitializeConditions for TransportDelay: '<Root>/Transport Delay1' */
    rtDW.TransportDelay1_IWORK[0] = 0;
    rtDW.TransportDelay1_IWORK[1] = 0;
    rtDW.TransportDelay1_IWORK[2] = 0;
    ((real_T *)rtDW.TransportDelay1_PWORK[0])[rtDW.TransportDelay1_IWORK[1]] =
      0.0;
    ((real_T *)rtDW.TransportDelay1_PWORK[0])[rtDW.TransportDelay1_IWORK[1] +
      rtDW.TransportDelay1_IWORK[3]] = tmp_7;

    /* InitializeConditions for SimscapeExecutionBlock: '<S14>/STATE_1' */
    tmp = false;
    tmp_2 = false;
    if (tmp_2 || tmp) {
      startIdx = strcmp(rtsiGetSolverName(&rtM->solverInfo), "daessc");
      i = strcmp(rtsiGetSolverName(&rtM->solverInfo), "ode14x");
      tmp_3 = strcmp(rtsiGetSolverName(&rtM->solverInfo), "ode15s");
      tmp_4 = strcmp(rtsiGetSolverName(&rtM->solverInfo), "ode1be");
      tmp_5 = strcmp(rtsiGetSolverName(&rtM->solverInfo), "ode23t");
      tmp_6 = strcmp(rtsiGetSolverName(&rtM->solverInfo), "odeN");
      if ((boolean_T)((startIdx != 0) & (i != 0) & (tmp_3 != 0) & (tmp_4 != 0) &
                      (tmp_5 != 0) & (tmp_6 != 0))) {
        rtmSetErrorStatus(rtM,
                          "Detected inconsistent solvers in the model reference hierarchy. Model built with ode14x requires one of {daessc, ode14x, ode15s, ode1be, ode23t, odeN} solvers to run. Use one of the required solvers in the top model.");
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S14>/STATE_1' */

    /* InitializeConditions for Integrator: '<Root>/Vel>Pos' */
    rtX.VelPos_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<Root>/Accel>Vel' */
    rtX.AccelVel_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    rtX.Integrator_CSTATE = 0.0;

    /* Root-level InitSystemMatrices */
    {
      static int_T modelMassMatrixIr[13] = { 0, 3, 2, 1, 4, 11, 13, 14, 12, 15,
        22, 23, 24 };

      static int_T modelMassMatrixJc[26] = { 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5,
        6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 11, 12, 13 };

      static real_T modelMassMatrixPr[13] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

      (void) memcpy(rtMassMatrix.ir, modelMassMatrixIr,
                    13*sizeof(int_T));
      (void) memcpy(rtMassMatrix.jc, modelMassMatrixJc,
                    26*sizeof(int_T));
      (void) memcpy(rtMassMatrix.pr, modelMassMatrixPr,
                    13*sizeof(real_T));
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
