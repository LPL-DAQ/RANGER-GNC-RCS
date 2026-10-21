/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_sys_struct.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_dxf.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_externals.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T solenoid_valve_curtain_v1_109_77b42695_1_ds_dxf(const NeDynamicSystem
  *sys, const NeDynamicSystemInput *t21, NeDsMethodOutput *out)
{
  real_T intermediate_der14;
  real_T t13;
  real_T t7;
  real_T t9;
  if (t21->mM.mX[0ULL] != 0) {
    t7 = (t21->mX.mX[1ULL] * 0.06689522874242489 + 0.18416238843463162) *
      (t21->mX.mX[1ULL] * 0.06689522874242489 + 0.18416238843463162);
    t13 = -66.89522874242489 / (t7 == 0.0 ? 1.0E-16 : t7);
  } else {
    t13 = -1972.3921508287676;
  }

  if (t21->mM.mX[1ULL] != 0) {
    t7 = 1000.0;
  } else {
    t7 = t21->mM.mX[2ULL] != 0 ? 1000.0 : 0.0;
  }

  if (t21->mM.mX[1ULL] != 0) {
    intermediate_der14 = 500.0;
  } else {
    intermediate_der14 = t21->mM.mX[2ULL] != 0 ? 500.0 : 0.0;
  }

  if (t21->mM.mX[0ULL] != 0) {
    t9 = (t21->mX.mX[1ULL] * 0.06689522874242489 + 0.18416238843463162) *
      (t21->mX.mX[1ULL] * 0.06689522874242489 + 0.18416238843463162) *
      (t21->mX.mX[1ULL] * 0.06689522874242489 + 0.18416238843463162) *
      (t21->mX.mX[1ULL] * 0.06689522874242489 + 0.18416238843463162);
    t9 = (t21->mX.mX[1ULL] * 0.06689522874242489 + 0.18416238843463162) *
      (66.89522874242489 / (t9 == 0.0 ? 1.0E-16 : t9)) * 0.13379045748484977;
  } else {
    t9 = 0.0;
  }

  out->mDXF.mX[0ULL] = -t7 / 5.0;
  out->mDXF.mX[1ULL] = -(t21->mX.mX[3ULL] * t21->mX.mX[3ULL] * t9 * 0.5);
  out->mDXF.mX[2ULL] = -(t21->mX.mX[2ULL] * t21->mX.mX[3ULL] * t9) /
    72.72727272727272;
  out->mDXF.mX[3ULL] = -intermediate_der14 / 5.0;
  t9 = -(t21->mX.mX[3ULL] * t13);
  out->mDXF.mX[4ULL] = t9 / 72.72727272727272;
  out->mDXF.mX[6ULL] = -(t21->mX.mX[2ULL] * t13) / 72.72727272727272;
  out->mDXF.mX[5ULL] = t9;
  (void)sys;
  (void)out;
  return 0;
}
