/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration'.
 */

#include "ne_ds.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_sys_struct.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_log.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_externals.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T solenoid_valve_curtain_v1_109_96c7c979_1_ds_log(const NeDynamicSystem
  *sys, const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  out->mLOG.mX[11ULL] = t1->mX.mX[4ULL];
  out->mLOG.mX[17ULL] = -t1->mX.mX[5ULL];
  out->mLOG.mX[28ULL] = t1->mX.mX[3ULL] * t1->mX.mX[3ULL] * 72.72727272727272;
  out->mLOG.mX[0ULL] = -t1->mX.mX[3ULL];
  out->mLOG.mX[1ULL] = t1->mU.mX[0ULL];
  out->mLOG.mX[2ULL] = t1->mU.mX[0ULL];
  out->mLOG.mX[3ULL] = t1->mU.mX[0ULL];
  out->mLOG.mX[4ULL] = t1->mX.mX[3ULL];
  out->mLOG.mX[5ULL] = t1->mX.mX[3ULL];
  out->mLOG.mX[6ULL] = t1->mU.mX[0ULL];
  out->mLOG.mX[7ULL] = t1->mU.mX[0ULL];
  out->mLOG.mX[8ULL] = t1->mX.mX[3ULL];
  out->mLOG.mX[9ULL] = t1->mX.mX[1ULL];
  out->mLOG.mX[10ULL] = t1->mX.mX[4ULL];
  out->mLOG.mX[12ULL] = t1->mX.mX[1ULL];
  out->mLOG.mX[13ULL] = t1->mX.mX[1ULL] * 1000.0;
  out->mLOG.mX[14ULL] = t1->mX.mX[4ULL];
  out->mLOG.mX[15ULL] = t1->mX.mX[4ULL];
  out->mLOG.mX[16ULL] = t1->mX.mX[4ULL];
  out->mLOG.mX[18ULL] = t1->mU.mX[0ULL];
  out->mLOG.mX[19ULL] = t1->mX.mX[5ULL];
  out->mLOG.mX[20ULL] = t1->mX.mX[0ULL];
  out->mLOG.mX[21ULL] = t1->mX.mX[4ULL];
  out->mLOG.mX[22ULL] = t1->mX.mX[2ULL] * 1000.0;
  out->mLOG.mX[23ULL] = t1->mX.mX[3ULL];
  out->mLOG.mX[24ULL] = t1->mX.mX[7ULL];
  out->mLOG.mX[25ULL] = t1->mU.mX[0ULL];
  out->mLOG.mX[26ULL] = t1->mU.mX[0ULL];
  out->mLOG.mX[27ULL] = t1->mX.mX[8ULL];
  out->mLOG.mX[29ULL] = t1->mX.mX[6ULL];
  out->mLOG.mX[30ULL] = t1->mX.mX[9ULL];
  (void)sys;
  (void)out;
  return 0;
}
