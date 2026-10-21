/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_sys_struct.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_f.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_externals.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T solenoid_valve_curtain_v1_109_77b42695_1_ds_f(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t4, NeDsMethodOutput *out)
{
  real_T t3;
  real_T zc_int2;
  if (t4->mM.mX[1ULL] != 0) {
    t3 = (t4->mX.mX[1ULL] * 0.001 - 0.007940000000000001) * 1.0E+6 + t4->mX.mX
      [2ULL] * 500.0;
  } else if (t4->mM.mX[2ULL] != 0) {
    t3 = t4->mX.mX[1ULL] * 1000.0 + t4->mX.mX[2ULL] * 500.0;
  } else {
    t3 = 0.0;
  }

  if (t4->mM.mX[0ULL] != 0) {
    zc_int2 = (t4->mX.mX[1ULL] * 0.06689522874242489 + 0.18416238843463162) *
      (t4->mX.mX[1ULL] * 0.06689522874242489 + 0.18416238843463162);
    zc_int2 = -66.89522874242489 / (zc_int2 == 0.0 ? 1.0E-16 : zc_int2);
  } else {
    zc_int2 = -1972.3921508287676;
  }

  out->mF.mX[0ULL] = -0.0;
  out->mF.mX[1ULL] = -0.0;
  out->mF.mX[2ULL] = -0.0;
  out->mF.mX[3ULL] = -0.0;
  out->mF.mX[4ULL] = 0.0;
  out->mF.mX[5ULL] = -t3 / 5.0 + 3.09999;
  out->mF.mX[6ULL] = 0.0;
  out->mF.mX[7ULL] = -(t4->mX.mX[3ULL] * t4->mX.mX[3ULL] * zc_int2 * 0.5);
  out->mF.mX[8ULL] = -(t4->mX.mX[2ULL] * t4->mX.mX[3ULL] * zc_int2) /
    72.72727272727272;
  out->mF.mX[9ULL] = 0.0;
  (void)sys;
  (void)out;
  return 0;
}
