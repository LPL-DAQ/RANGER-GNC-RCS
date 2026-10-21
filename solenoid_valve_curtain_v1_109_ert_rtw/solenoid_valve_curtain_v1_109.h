/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: solenoid_valve_curtain_v1_109.h
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

#ifndef solenoid_valve_curtain_v1_109_h_
#define solenoid_valve_curtain_v1_109_h_
#ifndef solenoid_valve_curtain_v1_109_COMMON_INCLUDES_
#define solenoid_valve_curtain_v1_109_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "nesl_rtw_rtp.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_gateway.h"
#include "nesl_rtw.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_gateway.h"
#endif                      /* solenoid_valve_curtain_v1_109_COMMON_INCLUDES_ */

#include <string.h>
#include <float.h>
#include <math.h>
#include "rt_matrixlib.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_1_1_1[4];               /* '<S23>/INPUT_1_1_1' */
  real_T STATE_1[13];                  /* '<S23>/STATE_1' */
  real_T INPUT_1_1_1_c[4];             /* '<S14>/INPUT_1_1_1' */
  real_T STATE_1_c[13];                /* '<S14>/STATE_1' */
  real_T OUTPUT_1_0[2];                /* '<S14>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_o[2];              /* '<S23>/OUTPUT_1_0' */
  real_T TransportDelay_RWORK[2049];   /* '<Root>/Transport Delay' */
  real_T TransportDelay1_RWORK[2049];  /* '<Root>/Transport Delay1' */
  real_T Gain;                         /* '<S5>/Gain' */
  real_T RTP_1;                        /* '<S19>/RTP_1' */
  real_T Gain9;                        /* '<S4>/Gain9' */
  real_T RTP_1_i;                      /* '<S10>/RTP_1' */
  real_T AngularAccleration;           /* '<Root>/Ixxp' */
  real_T Vel;                          /* '<Root>/Accel>Vel' */
  real_T Mdot;                         /* '<Root>/Mdot' */
  real_T valve_cw;                     /* '<Root>/MATLAB Function' */
  real_T valve_ccw;                    /* '<Root>/MATLAB Function' */
  real_T INPUT_1_1_1_SimscapeInternalDis;/* '<S23>/INPUT_1_1_1' */
  real_T INPUT_1_1_1_SimscapeInternalFir;/* '<S23>/INPUT_1_1_1' */
  real_T INPUT_1_1_1_SimscapeInternalD_p;/* '<S14>/INPUT_1_1_1' */
  real_T INPUT_1_1_1_SimscapeInternalF_e;/* '<S14>/INPUT_1_1_1' */
  real_T STATE_1_Discrete;             /* '<S23>/STATE_1' */
  real_T STATE_1_JacobElems;           /* '<S23>/STATE_1' */
  real_T STATE_1_ZcValueStore;         /* '<S23>/STATE_1' */
  real_T STATE_1_Discrete_c;           /* '<S14>/STATE_1' */
  real_T STATE_1_JacobElems_h;         /* '<S14>/STATE_1' */
  real_T STATE_1_ZcValueStore_l;       /* '<S14>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S14>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_JacobElems;        /* '<S14>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_ZcValueStore;      /* '<S14>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_Discrete_d;        /* '<S23>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_JacobElems_f;      /* '<S23>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_ZcValueStore_h;    /* '<S23>/OUTPUT_1_0' */
  real_T valve_state;                  /* '<Root>/MATLAB Function' */
  real_T pulse_timer;                  /* '<Root>/MATLAB Function' */
  real_T total;                        /* '<Root>/AC' */
  real_T prev_cw;                      /* '<Root>/AC' */
  real_T prev_ccw;                     /* '<Root>/AC' */
  void *TransportDelay_PWORK[2];       /* '<Root>/Transport Delay' */
  void *TransportDelay1_PWORK[2];      /* '<Root>/Transport Delay1' */
  void* RTP_1_RtpManager;              /* '<S19>/RTP_1' */
  void* RTP_1_DiagMgr;                 /* '<S19>/RTP_1' */
  void* STATE_1_Simulator;             /* '<S23>/STATE_1' */
  void* STATE_1_SimData;               /* '<S23>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S23>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S23>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S23>/STATE_1' */
  void* SINK_1_RtwLogger;              /* '<S23>/SINK_1' */
  void* SINK_1_RtwLogBuffer;           /* '<S23>/SINK_1' */
  void* SINK_1_RtwLogFcnManager;       /* '<S23>/SINK_1' */
  void* SINK_1_InstRtwLogger;          /* '<S23>/SINK_1' */
  void* SINK_1_InstRtwLogBuffer;       /* '<S23>/SINK_1' */
  void* RTP_1_RtpManager_d;            /* '<S10>/RTP_1' */
  void* RTP_1_DiagMgr_p;               /* '<S10>/RTP_1' */
  void* STATE_1_Simulator_b;           /* '<S14>/STATE_1' */
  void* STATE_1_SimData_f;             /* '<S14>/STATE_1' */
  void* STATE_1_DiagMgr_n;             /* '<S14>/STATE_1' */
  void* STATE_1_ZcLogger_o;            /* '<S14>/STATE_1' */
  void* STATE_1_TsInfo_b;              /* '<S14>/STATE_1' */
  void* SINK_1_RtwLogger_n;            /* '<S14>/SINK_1' */
  void* SINK_1_RtwLogBuffer_d;         /* '<S14>/SINK_1' */
  void* SINK_1_RtwLogFcnManager_e;     /* '<S14>/SINK_1' */
  void* SINK_1_InstRtwLogger_n;        /* '<S14>/SINK_1' */
  void* SINK_1_InstRtwLogBuffer_a;     /* '<S14>/SINK_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S14>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S14>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S14>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S14>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S14>/OUTPUT_1_0' */
  void* OUTPUT_1_0_Simulator_a;        /* '<S23>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData_n;          /* '<S23>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr_f;          /* '<S23>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger_c;         /* '<S23>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo_h;           /* '<S23>/OUTPUT_1_0' */
  int_T TransportDelay_IWORK[4];       /* '<Root>/Transport Delay' */
  int_T STATE_1_Modes[3];              /* '<S23>/STATE_1' */
  int_T TransportDelay1_IWORK[4];      /* '<Root>/Transport Delay1' */
  int_T STATE_1_Modes_o[3];            /* '<S14>/STATE_1' */
  int_T STATE_1_SwtgCoeffs;            /* '<S23>/STATE_1' */
  int_T STATE_1_SwtgCoeffs_k;          /* '<S14>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S14>/OUTPUT_1_0' */
  int_T OUTPUT_1_0_SwtgCoeffs;         /* '<S14>/OUTPUT_1_0' */
  int_T OUTPUT_1_0_Modes_k;            /* '<S23>/OUTPUT_1_0' */
  int_T OUTPUT_1_0_SwtgCoeffs_d;       /* '<S23>/OUTPUT_1_0' */
  int32_T STATE_1_MASS_MATRIX_PR;      /* '<S23>/STATE_1' */
  int32_T STATE_1_MASS_MATRIX_PR_m;    /* '<S14>/STATE_1' */
  uint8_T STATE_1_ZcSignalDir;         /* '<S23>/STATE_1' */
  uint8_T STATE_1_ZcStateStore;        /* '<S23>/STATE_1' */
  uint8_T STATE_1_ZcSignalDir_f;       /* '<S14>/STATE_1' */
  uint8_T STATE_1_ZcStateStore_c;      /* '<S14>/STATE_1' */
  uint8_T OUTPUT_1_0_ZcSignalDir;      /* '<S14>/OUTPUT_1_0' */
  uint8_T OUTPUT_1_0_ZcStateStore;     /* '<S14>/OUTPUT_1_0' */
  uint8_T OUTPUT_1_0_ZcSignalDir_p;    /* '<S23>/OUTPUT_1_0' */
  uint8_T OUTPUT_1_0_ZcStateStore_p;   /* '<S23>/OUTPUT_1_0' */
  boolean_T RTP_1_SetParametersNeeded; /* '<S19>/RTP_1' */
  boolean_T STATE_1_FirstOutput;       /* '<S23>/STATE_1' */
  boolean_T RTP_1_SetParametersNeeded_d;/* '<S10>/RTP_1' */
  boolean_T STATE_1_FirstOutput_h;     /* '<S14>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S14>/OUTPUT_1_0' */
  boolean_T OUTPUT_1_0_FirstOutput_i;  /* '<S23>/OUTPUT_1_0' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T solenoid_valve_curtain_v1_109so;/* '<S23>/INPUT_1_1_1' */
  real_T solenoid_valve_curtain_v1_109_b[10];/* '<S23>/STATE_1' */
  real_T solenoid_valve_curtain_v1_109So;/* '<S14>/INPUT_1_1_1' */
  real_T solenoid_valve_curtain_v1_109_l[10];/* '<S14>/STATE_1' */
  real_T VelPos_CSTATE;                /* '<Root>/Vel>Pos' */
  real_T AccelVel_CSTATE;              /* '<Root>/Accel>Vel' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T solenoid_valve_curtain_v1_109so;/* '<S23>/INPUT_1_1_1' */
  real_T solenoid_valve_curtain_v1_109_b[10];/* '<S23>/STATE_1' */
  real_T solenoid_valve_curtain_v1_109So;/* '<S14>/INPUT_1_1_1' */
  real_T solenoid_valve_curtain_v1_109_l[10];/* '<S14>/STATE_1' */
  real_T VelPos_CSTATE;                /* '<Root>/Vel>Pos' */
  real_T AccelVel_CSTATE;              /* '<Root>/Accel>Vel' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T solenoid_valve_curtain_v1_109so;/* '<S23>/INPUT_1_1_1' */
  boolean_T solenoid_valve_curtain_v1_109_b[10];/* '<S23>/STATE_1' */
  boolean_T solenoid_valve_curtain_v1_109So;/* '<S14>/INPUT_1_1_1' */
  boolean_T solenoid_valve_curtain_v1_109_l[10];/* '<S14>/STATE_1' */
  boolean_T VelPos_CSTATE;             /* '<Root>/Vel>Pos' */
  boolean_T AccelVel_CSTATE;           /* '<Root>/Accel>Vel' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
} XDis;

/* Mass Matrix (global) */
typedef struct {
  int_T ir[13];
  int_T jc[26];
  real_T pr[13];
} MassMatrix;

#ifndef ODE14X_INTG
#define ODE14X_INTG

/* ODE14X Integration Data */
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
} ODE14X_IntgData;

#endif

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  int_T massMatrixType;
  int_T massMatrixNzMax;
  int_T *massMatrixIr;
  int_T *massMatrixJc;
  real_T *massMatrixPr;
  real_T odeX0[25];
  real_T odeF0[25];
  real_T odeX1START[25];
  real_T odeF1[25];
  real_T odeDELTA[25];
  real_T odeE[4*25];
  real_T odeFAC[25];
  real_T odeDFDX[25*25];
  real_T odeW[25*25];
  int_T odePIVOTS[25];
  real_T odeXTMP[25];
  real_T odeZTMP[25];
  real_T odeMASSMATRIX_M[13];
  real_T odeMASSMATRIX_M1[13];
  real_T odeEDOT[4*25];
  real_T odeXDOT[25];
  real_T odeFMXDOT[25];
  ODE14X_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Disabled states (default storage) */
extern XDis rtXDis;

/* Block signals and states (default storage) */
extern DW rtDW;

/* global MassMatrix */
extern MassMatrix rtMassMatrix;

/* Model entry point functions */
extern void solenoid_valve_curtain_v1_109_initialize(void);
extern void solenoid_valve_curtain_v1_109_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Actuation Count' : Unused code path elimination
 * Block '<Root>/Fuel Used' : Unused code path elimination
 * Block '<Root>/Gain1' : Unused code path elimination
 * Block '<Root>/Gain4' : Unused code path elimination
 * Block '<Root>/Gain5' : Unused code path elimination
 * Block '<Root>/Omega actual' : Unused code path elimination
 * Block '<Root>/Ref vs Actual Position' : Unused code path elimination
 * Block '<Root>/Ref vs Actual Velocity' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S4>/Display1' : Unused code path elimination
 * Block '<S4>/Scope1' : Unused code path elimination
 * Block '<S4>/Scope2' : Unused code path elimination
 * Block '<S4>/Valve Scope1' : Unused code path elimination
 * Block '<Root>/Valve State' : Unused code path elimination
 * Block '<S5>/Display' : Unused code path elimination
 * Block '<S5>/Scope3' : Unused code path elimination
 * Block '<S5>/Scope4' : Unused code path elimination
 * Block '<S5>/Valve Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'solenoid_valve_curtain_v1_109'
 * '<S1>'   : 'solenoid_valve_curtain_v1_109/AC'
 * '<S2>'   : 'solenoid_valve_curtain_v1_109/Generate Trace'
 * '<S3>'   : 'solenoid_valve_curtain_v1_109/MATLAB Function'
 * '<S4>'   : 'solenoid_valve_curtain_v1_109/Solenoid Valve'
 * '<S5>'   : 'solenoid_valve_curtain_v1_109/solenoid valve'
 * '<S6>'   : 'solenoid_valve_curtain_v1_109/Solenoid Valve/MATLAB Function3'
 * '<S7>'   : 'solenoid_valve_curtain_v1_109/Solenoid Valve/PS-Simulink Converter1'
 * '<S8>'   : 'solenoid_valve_curtain_v1_109/Solenoid Valve/PS-Simulink Converter4'
 * '<S9>'   : 'solenoid_valve_curtain_v1_109/Solenoid Valve/Simulink-PS Converter3'
 * '<S10>'  : 'solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1'
 * '<S11>'  : 'solenoid_valve_curtain_v1_109/Solenoid Valve/PS-Simulink Converter1/EVAL_KEY'
 * '<S12>'  : 'solenoid_valve_curtain_v1_109/Solenoid Valve/PS-Simulink Converter4/EVAL_KEY'
 * '<S13>'  : 'solenoid_valve_curtain_v1_109/Solenoid Valve/Simulink-PS Converter3/EVAL_KEY'
 * '<S14>'  : 'solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1/EVAL_KEY'
 * '<S15>'  : 'solenoid_valve_curtain_v1_109/solenoid valve/MATLAB Function1'
 * '<S16>'  : 'solenoid_valve_curtain_v1_109/solenoid valve/PS-Simulink Converter2'
 * '<S17>'  : 'solenoid_valve_curtain_v1_109/solenoid valve/PS-Simulink Converter3'
 * '<S18>'  : 'solenoid_valve_curtain_v1_109/solenoid valve/Simulink-PS Converter1'
 * '<S19>'  : 'solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration'
 * '<S20>'  : 'solenoid_valve_curtain_v1_109/solenoid valve/PS-Simulink Converter2/EVAL_KEY'
 * '<S21>'  : 'solenoid_valve_curtain_v1_109/solenoid valve/PS-Simulink Converter3/EVAL_KEY'
 * '<S22>'  : 'solenoid_valve_curtain_v1_109/solenoid valve/Simulink-PS Converter1/EVAL_KEY'
 * '<S23>'  : 'solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* solenoid_valve_curtain_v1_109_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
