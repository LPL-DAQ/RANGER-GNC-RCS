/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'solenoid_valve_curtain_v1_109/Solenoid Valve/Solver Configuration1'.
 */

#include "ne_ds.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_sys_struct.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_il.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_externals.h"
#include "solenoid_valve_curtain_v1_109_77b42695_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_il(const NeDynamicSystem
  *sys, const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static boolean_T _cg_const_1[37] = { true, true, false, false, false, true,
    true, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, true, true, true, true,
    true, true, true, true, true, false, true };

  (void)t1;
  out->mOBS_IL.mX[0] = _cg_const_1[0];
  out->mOBS_IL.mX[1] = _cg_const_1[1];
  out->mOBS_IL.mX[2] = _cg_const_1[2];
  out->mOBS_IL.mX[3] = _cg_const_1[3];
  out->mOBS_IL.mX[4] = _cg_const_1[4];
  out->mOBS_IL.mX[5] = _cg_const_1[5];
  out->mOBS_IL.mX[6] = _cg_const_1[6];
  out->mOBS_IL.mX[7] = _cg_const_1[7];
  out->mOBS_IL.mX[8] = _cg_const_1[8];
  out->mOBS_IL.mX[9] = _cg_const_1[9];
  out->mOBS_IL.mX[10] = _cg_const_1[10];
  out->mOBS_IL.mX[11] = _cg_const_1[11];
  out->mOBS_IL.mX[12] = _cg_const_1[12];
  out->mOBS_IL.mX[13] = _cg_const_1[13];
  out->mOBS_IL.mX[14] = _cg_const_1[14];
  out->mOBS_IL.mX[15] = _cg_const_1[15];
  out->mOBS_IL.mX[16] = _cg_const_1[16];
  out->mOBS_IL.mX[17] = _cg_const_1[17];
  out->mOBS_IL.mX[18] = _cg_const_1[18];
  out->mOBS_IL.mX[19] = _cg_const_1[19];
  out->mOBS_IL.mX[20] = _cg_const_1[20];
  out->mOBS_IL.mX[21] = _cg_const_1[21];
  out->mOBS_IL.mX[22] = _cg_const_1[22];
  out->mOBS_IL.mX[23] = _cg_const_1[23];
  out->mOBS_IL.mX[24] = _cg_const_1[24];
  out->mOBS_IL.mX[25] = _cg_const_1[25];
  out->mOBS_IL.mX[26] = _cg_const_1[26];
  out->mOBS_IL.mX[27] = _cg_const_1[27];
  out->mOBS_IL.mX[28] = _cg_const_1[28];
  out->mOBS_IL.mX[29] = _cg_const_1[29];
  out->mOBS_IL.mX[30] = _cg_const_1[30];
  out->mOBS_IL.mX[31] = _cg_const_1[31];
  out->mOBS_IL.mX[32] = _cg_const_1[32];
  out->mOBS_IL.mX[33] = _cg_const_1[33];
  out->mOBS_IL.mX[34] = _cg_const_1[34];
  out->mOBS_IL.mX[35] = _cg_const_1[35];
  out->mOBS_IL.mX[36] = _cg_const_1[36];
  (void)sys;
  (void)out;
  return 0;
}
