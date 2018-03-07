#ifndef __c1_sfbp_h__
#define __c1_sfbp_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
typedef struct {
  real_T c1_Tmew;
  real_T c1_Tobs;
  real_T c1_Tobs1;
  real_T c1_Tobs1sum;
  real_T c1_Tobs2;
  real_T c1_Tobs2sum;
  real_T c1_Tobs3;
  real_T c1_Tobs3sum;
  real_T c1_Tobssum;
  real_T c1_bocher;
  real_T c1_kolzajv;
  real_T c1_osv_kan0;
  real_T c1_prihod;
  real_T c1_raspr;
  SimStruct *S;
  void *c1_testPointAddrMap[39];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c1_is_Istochnik;
  uint8_T c1_is_active_Istochnik;
  uint8_T c1_is_active_besknakop;
  uint8_T c1_is_active_c1_sfbp;
  uint8_T c1_is_active_evm_1;
  uint8_T c1_is_active_evm_2;
  uint8_T c1_is_active_evm_3;
  uint8_T c1_is_active_predvaritobrabotka;
  uint8_T c1_is_active_statistica1;
  uint8_T c1_is_active_statistica2;
  uint8_T c1_is_active_vetvlenie;
  uint8_T c1_is_besknakop;
  uint8_T c1_is_c1_sfbp;
  uint8_T c1_is_evm_1;
  uint8_T c1_is_evm_2;
  uint8_T c1_is_evm_3;
  uint8_T c1_is_predvaritobrabotka;
  uint8_T c1_is_statistica1;
  uint8_T c1_is_statistica2;
  uint8_T c1_is_vetvlenie;
  uint8_T c1_tp_Istochnik;
  uint8_T c1_tp_SMO;
  uint8_T c1_tp_besknakop;
  uint8_T c1_tp_beskonechnakopitel;
  uint8_T c1_tp_evm_1;
  uint8_T c1_tp_evm_2;
  uint8_T c1_tp_evm_3;
  uint8_T c1_tp_obrabotka;
  uint8_T c1_tp_obsluwivanie1;
  uint8_T c1_tp_obsluwivanie2;
  uint8_T c1_tp_obsluwivanie3;
  uint8_T c1_tp_predvaritobrabotka;
  uint8_T c1_tp_raspredelenie;
  uint8_T c1_tp_stat1;
  uint8_T c1_tp_stat2;
  uint8_T c1_tp_statistica1;
  uint8_T c1_tp_statistica2;
  uint8_T c1_tp_stopinng;
  uint8_T c1_tp_vetvlenie;
  uint8_T c1_tp_vhod;
  uint8_T c1_tp_vhod1;
  uint8_T c1_tp_vhod2;
  uint8_T c1_tp_vhod3;
  uint8_T c1_tp_vihod;
  uint8_T c1_tp_zaderwka;
  rtwCAPI_ModelMappingInfo c1_testPointMappingInfo;
  ChartInfoStruct chartInfo;
} SFc1_sfbpInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

extern void sf_c1_sfbp_get_check_sum(mxArray *plhs[]);
extern void c1_sfbp_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif

