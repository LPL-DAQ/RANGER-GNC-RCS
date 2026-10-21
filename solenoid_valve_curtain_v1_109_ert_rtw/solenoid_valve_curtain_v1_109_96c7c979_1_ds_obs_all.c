/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration'.
 */

#include "ne_ds.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_sys_struct.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_all.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_externals.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_all(const
  NeDynamicSystem *sys, const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  out->mOBS_ALL.mX[11ULL] = 0.0;
  out->mOBS_ALL.mX[15ULL] = t1->mX.mX[4ULL];
  out->mOBS_ALL.mX[21ULL] = -t1->mX.mX[5ULL];
  out->mOBS_ALL.mX[0ULL] = -t1->mX.mX[3ULL];
  out->mOBS_ALL.mX[1ULL] = 0.0;
  out->mOBS_ALL.mX[2ULL] = t1->mU.mX[0ULL];
  out->mOBS_ALL.mX[3ULL] = t1->mU.mX[0ULL];
  out->mOBS_ALL.mX[4ULL] = t1->mU.mX[0ULL];
  out->mOBS_ALL.mX[5ULL] = t1->mX.mX[3ULL];
  out->mOBS_ALL.mX[6ULL] = t1->mX.mX[3ULL];
  out->mOBS_ALL.mX[7ULL] = t1->mU.mX[0ULL];
  out->mOBS_ALL.mX[8ULL] = t1->mU.mX[0ULL];
  out->mOBS_ALL.mX[9ULL] = t1->mX.mX[3ULL];
  out->mOBS_ALL.mX[10ULL] = 0.0;
  out->mOBS_ALL.mX[12ULL] = 0.0;
  out->mOBS_ALL.mX[13ULL] = t1->mX.mX[1ULL];
  out->mOBS_ALL.mX[14ULL] = t1->mX.mX[4ULL];
  out->mOBS_ALL.mX[16ULL] = t1->mX.mX[1ULL];
  out->mOBS_ALL.mX[17ULL] = t1->mX.mX[1ULL] * 1000.0;
  out->mOBS_ALL.mX[18ULL] = t1->mX.mX[4ULL];
  out->mOBS_ALL.mX[19ULL] = t1->mX.mX[4ULL];
  out->mOBS_ALL.mX[20ULL] = t1->mX.mX[4ULL];
  out->mOBS_ALL.mX[22ULL] = 0.0;
  out->mOBS_ALL.mX[23ULL] = 0.0;
  out->mOBS_ALL.mX[24ULL] = 0.0;
  out->mOBS_ALL.mX[25ULL] = t1->mU.mX[0ULL];
  out->mOBS_ALL.mX[26ULL] = 0.0;
  out->mOBS_ALL.mX[27ULL] = t1->mX.mX[5ULL];
  out->mOBS_ALL.mX[28ULL] = 0.0;
  out->mOBS_ALL.mX[29ULL] = t1->mX.mX[0ULL];
  out->mOBS_ALL.mX[30ULL] = t1->mX.mX[4ULL];
  out->mOBS_ALL.mX[31ULL] = t1->mX.mX[2ULL] * 1000.0;
  out->mOBS_ALL.mX[32ULL] = t1->mX.mX[3ULL];
  out->mOBS_ALL.mX[33ULL] = t1->mX.mX[7ULL];
  out->mOBS_ALL.mX[34ULL] = 0.0;
  out->mOBS_ALL.mX[35ULL] = t1->mU.mX[0ULL];
  out->mOBS_ALL.mX[36ULL] = t1->mX.mX[8ULL];
  (void)sys;
  (void)out;
  return 0;
}
