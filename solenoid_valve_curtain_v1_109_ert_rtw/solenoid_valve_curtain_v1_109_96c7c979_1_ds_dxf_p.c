/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'solenoid_valve_curtain_v1_109/solenoid valve/Solver Configuration'.
 */

#include "ne_ds.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_sys_struct.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_dxf_p.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_externals.h"
#include "solenoid_valve_curtain_v1_109_96c7c979_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T solenoid_valve_curtain_v1_109_96c7c979_1_ds_dxf_p(const NeDynamicSystem *
  sys, const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[11] = { 0, 3, 3, 5, 7, 7, 7, 7, 7, 7, 7 };

  static int32_T _cg_const_2[7] = { 5, 7, 8, 5, 8, 7, 8 };

  (void)t1;
  out->mDXF_P.mNumCol = 10ULL;
  out->mDXF_P.mNumRow = 10ULL;
  out->mDXF_P.mJc[0] = _cg_const_1[0];
  out->mDXF_P.mJc[1] = _cg_const_1[1];
  out->mDXF_P.mJc[2] = _cg_const_1[2];
  out->mDXF_P.mJc[3] = _cg_const_1[3];
  out->mDXF_P.mJc[4] = _cg_const_1[4];
  out->mDXF_P.mJc[5] = _cg_const_1[5];
  out->mDXF_P.mJc[6] = _cg_const_1[6];
  out->mDXF_P.mJc[7] = _cg_const_1[7];
  out->mDXF_P.mJc[8] = _cg_const_1[8];
  out->mDXF_P.mJc[9] = _cg_const_1[9];
  out->mDXF_P.mJc[10] = _cg_const_1[10];
  out->mDXF_P.mIr[0] = _cg_const_2[0];
  out->mDXF_P.mIr[1] = _cg_const_2[1];
  out->mDXF_P.mIr[2] = _cg_const_2[2];
  out->mDXF_P.mIr[3] = _cg_const_2[3];
  out->mDXF_P.mIr[4] = _cg_const_2[4];
  out->mDXF_P.mIr[5] = _cg_const_2[5];
  out->mDXF_P.mIr[6] = _cg_const_2[6];
  (void)sys;
  (void)out;
  return 0;
}
