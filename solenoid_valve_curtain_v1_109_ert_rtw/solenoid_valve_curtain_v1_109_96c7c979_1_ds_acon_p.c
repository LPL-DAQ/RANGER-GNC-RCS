/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration'.
 */

#include "ne_ds.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_sys_struct.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_acon_p.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_externals.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T solenoid_valve_curtain_v1_109_96c7c979_1_ds_acon_p(const NeDynamicSystem
  *sys, const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_2[18] = { 5, 2, 5, 6, 8, 1, 6, 4, 5, 4, 9, 5, 7, 3, 8,
    0, 5, 9 };

  static int32_T _cg_const_1[11] = { 0, 1, 1, 4, 5, 7, 9, 11, 13, 15, 18 };

  (void)t1;
  out->mACON_P.mNumCol = 10ULL;
  out->mACON_P.mNumRow = 10ULL;
  out->mACON_P.mJc[0] = _cg_const_1[0];
  out->mACON_P.mJc[1] = _cg_const_1[1];
  out->mACON_P.mJc[2] = _cg_const_1[2];
  out->mACON_P.mJc[3] = _cg_const_1[3];
  out->mACON_P.mJc[4] = _cg_const_1[4];
  out->mACON_P.mJc[5] = _cg_const_1[5];
  out->mACON_P.mJc[6] = _cg_const_1[6];
  out->mACON_P.mJc[7] = _cg_const_1[7];
  out->mACON_P.mJc[8] = _cg_const_1[8];
  out->mACON_P.mJc[9] = _cg_const_1[9];
  out->mACON_P.mJc[10] = _cg_const_1[10];
  out->mACON_P.mIr[0] = _cg_const_2[0];
  out->mACON_P.mIr[1] = _cg_const_2[1];
  out->mACON_P.mIr[2] = _cg_const_2[2];
  out->mACON_P.mIr[3] = _cg_const_2[3];
  out->mACON_P.mIr[4] = _cg_const_2[4];
  out->mACON_P.mIr[5] = _cg_const_2[5];
  out->mACON_P.mIr[6] = _cg_const_2[6];
  out->mACON_P.mIr[7] = _cg_const_2[7];
  out->mACON_P.mIr[8] = _cg_const_2[8];
  out->mACON_P.mIr[9] = _cg_const_2[9];
  out->mACON_P.mIr[10] = _cg_const_2[10];
  out->mACON_P.mIr[11] = _cg_const_2[11];
  out->mACON_P.mIr[12] = _cg_const_2[12];
  out->mACON_P.mIr[13] = _cg_const_2[13];
  out->mACON_P.mIr[14] = _cg_const_2[14];
  out->mACON_P.mIr[15] = _cg_const_2[15];
  out->mACON_P.mIr[16] = _cg_const_2[16];
  out->mACON_P.mIr[17] = _cg_const_2[17];
  (void)sys;
  (void)out;
  return 0;
}
