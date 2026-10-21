/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration'.
 */

#include "ne_ds.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_sys_struct.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_exp.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_externals.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_exp(const
  NeDynamicSystem *sys, const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  out->mOBS_EXP.mX[0ULL] = 0.0;
  out->mOBS_EXP.mX[1ULL] = 0.0;
  out->mOBS_EXP.mX[2ULL] = 0.0;
  out->mOBS_EXP.mX[3ULL] = 0.0;
  out->mOBS_EXP.mX[4ULL] = 0.0;
  out->mOBS_EXP.mX[5ULL] = 0.0;
  out->mOBS_EXP.mX[6ULL] = 0.0;
  out->mOBS_EXP.mX[7ULL] = 0.0;
  out->mOBS_EXP.mX[8ULL] = 0.0;
  out->mOBS_EXP.mX[9ULL] = 0.0;
  out->mOBS_EXP.mX[10ULL] = 0.0;
  out->mOBS_EXP.mX[11ULL] = 0.0;
  out->mOBS_EXP.mX[12ULL] = 0.0;
  out->mOBS_EXP.mX[13ULL] = 0.0;
  out->mOBS_EXP.mX[14ULL] = 0.0;
  out->mOBS_EXP.mX[15ULL] = 0.0;
  out->mOBS_EXP.mX[16ULL] = 0.0;
  out->mOBS_EXP.mX[17ULL] = 0.0;
  out->mOBS_EXP.mX[18ULL] = 0.0;
  out->mOBS_EXP.mX[19ULL] = 0.0;
  out->mOBS_EXP.mX[20ULL] = 0.0;
  out->mOBS_EXP.mX[21ULL] = 0.0;
  out->mOBS_EXP.mX[22ULL] = 0.0;
  out->mOBS_EXP.mX[23ULL] = 0.0;
  out->mOBS_EXP.mX[24ULL] = 0.0;
  out->mOBS_EXP.mX[25ULL] = 0.0;
  out->mOBS_EXP.mX[26ULL] = 0.0;
  out->mOBS_EXP.mX[27ULL] = 0.0;
  out->mOBS_EXP.mX[28ULL] = 293.15;
  out->mOBS_EXP.mX[29ULL] = t1->mP_R.mX[2ULL];
  out->mOBS_EXP.mX[30ULL] = 0.0;
  out->mOBS_EXP.mX[31ULL] = t1->mP_R.mX[1ULL];
  out->mOBS_EXP.mX[32ULL] = t1->mP_R.mX[0ULL];
  out->mOBS_EXP.mX[33ULL] = 0.0;
  out->mOBS_EXP.mX[34ULL] = 0.0;
  out->mOBS_EXP.mX[35ULL] = 0.0;
  out->mOBS_EXP.mX[36ULL] = 0.0;
  (void)sys;
  (void)out;
  return 0;
}
