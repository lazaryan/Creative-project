/* Include files */
#include "sfbp_sfun.h"
#include "c1_sfbp.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "sfbp_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_event_event                  (0)
#define c1_IN_NO_ACTIVE_CHILD           (0)
#define c1_IN_SMO                       (1)
#define c1_IN_zaderwka                  (3)
#define c1_IN_vihod                     (2)
#define c1_IN_stopinng                  (1)
#define c1_IN_beskonechnakopitel        (1)
#define c1_IN_vhod                      (2)
#define c1_IN_obrabotka                 (1)
#define c1_IN_raspredelenie             (1)
#define c1_IN_vhod1                     (2)
#define c1_IN_obsluwivanie1             (1)
#define c1_IN_vhod2                     (2)
#define c1_IN_obsluwivanie2             (1)
#define c1_IN_vhod3                     (2)
#define c1_IN_obsluwivanie3             (1)
#define c1_IN_stat1                     (1)
#define c1_IN_stat2                     (1)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_sfbpInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_sfbp(void);
static void initialize_params_c1_sfbp(void);
static void enable_c1_sfbp(void);
static void disable_c1_sfbp(void);
static void finalize_c1_sfbp(void);
static void sf_c1_sfbp(void);
static int32_T c1__s32_div__(int32_T c1_b, int32_T c1_c);
static real_T *c1_ver_per(void);
static real_T *c1_total_time(void);
static real_T *c1_n3(void);
static real_T *c1_n2(void);
static real_T *c1_n1(void);
static real_T *c1_kol_otkaz(void);
static real_T *c1_kol_z1(void);
static real_T *c1_kol_z2(void);
static real_T *c1_kol_z3(void);
static real_T *c1_svzsevm1(void);
static real_T *c1_svzsevm2(void);
static real_T *c1_svzsevm3(void);
static real_T *c1_svzskan(void);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);

/* Function Definitions */
static void initialize_c1_sfbp(void)
{
  chartInstance.c1_tp_SMO = 0;
  chartInstance.c1_is_active_Istochnik = 0;
  chartInstance.c1_is_Istochnik = 0;
  chartInstance.c1_tp_Istochnik = 0;
  chartInstance.c1_tp_stopinng = 0;
  chartInstance.c1_tp_vihod = 0;
  chartInstance.c1_tp_zaderwka = 0;
  chartInstance.c1_is_active_besknakop = 0;
  chartInstance.c1_is_besknakop = 0;
  chartInstance.c1_tp_besknakop = 0;
  chartInstance.c1_tp_beskonechnakopitel = 0;
  chartInstance.c1_is_active_evm_1 = 0;
  chartInstance.c1_is_evm_1 = 0;
  chartInstance.c1_tp_evm_1 = 0;
  chartInstance.c1_tp_obsluwivanie1 = 0;
  chartInstance.c1_tp_vhod1 = 0;
  chartInstance.c1_is_active_evm_2 = 0;
  chartInstance.c1_is_evm_2 = 0;
  chartInstance.c1_tp_evm_2 = 0;
  chartInstance.c1_tp_obsluwivanie2 = 0;
  chartInstance.c1_tp_vhod2 = 0;
  chartInstance.c1_is_active_evm_3 = 0;
  chartInstance.c1_is_evm_3 = 0;
  chartInstance.c1_tp_evm_3 = 0;
  chartInstance.c1_tp_obsluwivanie3 = 0;
  chartInstance.c1_tp_vhod3 = 0;
  chartInstance.c1_is_active_predvaritobrabotka = 0;
  chartInstance.c1_is_predvaritobrabotka = 0;
  chartInstance.c1_tp_predvaritobrabotka = 0;
  chartInstance.c1_tp_obrabotka = 0;
  chartInstance.c1_tp_vhod = 0;
  chartInstance.c1_is_active_statistica1 = 0;
  chartInstance.c1_is_statistica1 = 0;
  chartInstance.c1_tp_statistica1 = 0;
  chartInstance.c1_tp_stat1 = 0;
  chartInstance.c1_is_active_statistica2 = 0;
  chartInstance.c1_is_statistica2 = 0;
  chartInstance.c1_tp_statistica2 = 0;
  chartInstance.c1_tp_stat2 = 0;
  chartInstance.c1_is_active_vetvlenie = 0;
  chartInstance.c1_is_vetvlenie = 0;
  chartInstance.c1_tp_vetvlenie = 0;
  chartInstance.c1_tp_raspredelenie = 0;
  chartInstance.c1_is_active_c1_sfbp = 0;
  chartInstance.c1_is_c1_sfbp = 0;
  chartInstance.c1_Tmew = 0.0;
  chartInstance.c1_bocher = 0.0;
  chartInstance.c1_kolzajv = 0.0;
  chartInstance.c1_prihod = 0.0;
  chartInstance.c1_Tobs = 0.0;
  chartInstance.c1_Tobs1 = 0.0;
  chartInstance.c1_Tobs2 = 0.0;
  chartInstance.c1_Tobs3 = 0.0;
  chartInstance.c1_osv_kan0 = 0.0;
  chartInstance.c1_raspr = 0.0;
  chartInstance.c1_Tobs1sum = 0.0;
  chartInstance.c1_Tobs2sum = 0.0;
  chartInstance.c1_Tobs3sum = 0.0;
  chartInstance.c1_Tobssum = 0.0;
  if(!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c1_ver_per() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 2) != 0)) {
    *c1_total_time() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 3) != 0)) {
    *c1_n3() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 4) != 0)) {
    *c1_n2() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 5) != 0)) {
    *c1_n1() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 6) != 0)) {
    *c1_kol_otkaz() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 7) != 0)) {
    *c1_kol_z1() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 8) != 0)) {
    *c1_kol_z2() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 9) != 0)) {
    *c1_kol_z3() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 10) != 0)) {
    *c1_svzsevm1() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 11) != 0)) {
    *c1_svzsevm2() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 12) != 0)) {
    *c1_svzsevm3() = 0.0;
  }
  if(!(cdrGetOutputPortReusable(chartInstance.S, 13) != 0)) {
    *c1_svzskan() = 0.0;
  }
}

static void initialize_params_c1_sfbp(void)
{
}

static void enable_c1_sfbp(void)
{
}

static void disable_c1_sfbp(void)
{
}

static void finalize_c1_sfbp(void)
{
}

static void sf_c1_sfbp(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tmew, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_bocher, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_kolzajv, 25U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_prihod, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs1, 20U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs2, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs3, 22U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_osv_kan0, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_ver_per(), 16U);
  _SFD_DATA_RANGE_CHECK(*c1_total_time(), 14U);
  _SFD_DATA_RANGE_CHECK(*c1_n3(), 24U);
  _SFD_DATA_RANGE_CHECK(*c1_n2(), 21U);
  _SFD_DATA_RANGE_CHECK(*c1_n1(), 13U);
  _SFD_DATA_RANGE_CHECK(*c1_kol_otkaz(), 5U);
  _SFD_DATA_RANGE_CHECK(*c1_kol_z1(), 0U);
  _SFD_DATA_RANGE_CHECK(*c1_kol_z2(), 23U);
  _SFD_DATA_RANGE_CHECK(*c1_kol_z3(), 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_raspr, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs1sum, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs2sum, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs3sum, 19U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobssum, 26U);
  _SFD_DATA_RANGE_CHECK(*c1_svzsevm1(), 17U);
  _SFD_DATA_RANGE_CHECK(*c1_svzsevm2(), 12U);
  _SFD_DATA_RANGE_CHECK(*c1_svzsevm3(), 3U);
  _SFD_DATA_RANGE_CHECK(*c1_svzskan(), 7U);
  {
    uint8_T c1_previousEvent;
    c1_previousEvent = _sfEvent_;
    _sfEvent_ = c1_event_event;
    _SFD_CE_CALL(EVENT_ENTER_BROADCAST_FUNCTION_TAG,c1_event_event);
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
    if(chartInstance.c1_is_active_c1_sfbp == 0) {
      _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
      chartInstance.c1_is_active_c1_sfbp = 1;
      _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
      chartInstance.c1_is_c1_sfbp = (uint8_T)c1_IN_SMO;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,21);
      chartInstance.c1_tp_SMO = 1;
      chartInstance.c1_is_active_evm_1 = 1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,16);
      chartInstance.c1_tp_evm_1 = 1;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,60);
      chartInstance.c1_Tobs1 = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs1, 20U);
      *c1_kol_z1() = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_kol_z1(), 0U);
      chartInstance.c1_Tobs1sum = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs1sum, 18U);
      chartInstance.c1_is_evm_1 = (uint8_T)c1_IN_vhod1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
      chartInstance.c1_tp_vhod1 = 1;
      chartInstance.c1_is_active_Istochnik = 1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,19);
      chartInstance.c1_tp_Istochnik = 1;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,43);
      chartInstance.c1_kolzajv = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_kolzajv, 25U);
      chartInstance.c1_Tmew = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tmew, 10U);
      chartInstance.c1_prihod = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_prihod, 2U);
      chartInstance.c1_is_Istochnik = (uint8_T)c1_IN_zaderwka;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
      chartInstance.c1_tp_zaderwka = 1;
      chartInstance.c1_is_active_predvaritobrabotka = 1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
      chartInstance.c1_tp_predvaritobrabotka = 1;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,10);
      chartInstance.c1_Tobs = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs, 15U);
      chartInstance.c1_Tobssum = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobssum, 26U);
      chartInstance.c1_is_predvaritobrabotka = (uint8_T)c1_IN_vhod;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
      chartInstance.c1_tp_vhod = 1;
      chartInstance.c1_is_active_besknakop = 1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
      chartInstance.c1_tp_besknakop = 1;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,4);
      chartInstance.c1_bocher = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_bocher, 8U);
      chartInstance.c1_is_besknakop = (uint8_T)c1_IN_beskonechnakopitel;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
      chartInstance.c1_tp_beskonechnakopitel = 1;
      chartInstance.c1_is_active_vetvlenie = 1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,3);
      chartInstance.c1_tp_vetvlenie = 1;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,51);
      *c1_kol_otkaz() = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_kol_otkaz(), 5U);
      *c1_n1() = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_n1(), 13U);
      *c1_n2() = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_n2(), 21U);
      *c1_n3() = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_n3(), 24U);
      chartInstance.c1_raspr = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_raspr, 4U);
      chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_raspredelenie;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
      chartInstance.c1_tp_raspredelenie = 1;
      chartInstance.c1_is_active_evm_2 = 1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,14);
      chartInstance.c1_tp_evm_2 = 1;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,54);
      chartInstance.c1_Tobs2 = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs2, 1U);
      *c1_kol_z2() = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_kol_z2(), 23U);
      chartInstance.c1_Tobs2sum = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs2sum, 6U);
      chartInstance.c1_is_evm_2 = (uint8_T)c1_IN_vhod2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,24);
      chartInstance.c1_tp_vhod2 = 1;
      chartInstance.c1_is_active_statistica2 = 1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
      chartInstance.c1_tp_statistica2 = 1;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
      *c1_ver_per() = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_ver_per(), 16U);
      chartInstance.c1_is_statistica2 = (uint8_T)c1_IN_stat2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,22);
      chartInstance.c1_tp_stat2 = 1;
      chartInstance.c1_is_active_statistica1 = 1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,7);
      chartInstance.c1_tp_statistica1 = 1;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,58);
      *c1_total_time() = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_total_time(), 14U);
      chartInstance.c1_is_statistica1 = (uint8_T)c1_IN_stat1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
      chartInstance.c1_tp_stat1 = 1;
      (*c1_total_time())++;
      _SFD_DATA_RANGE_CHECK(*c1_total_time(), 14U);
      chartInstance.c1_is_active_evm_3 = 1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,15);
      chartInstance.c1_tp_evm_3 = 1;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,61);
      *c1_kol_z3() = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_kol_z3(), 11U);
      chartInstance.c1_Tobs3 = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs3, 22U);
      chartInstance.c1_Tobs3sum = 0.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs3sum, 19U);
      chartInstance.c1_is_evm_3 = (uint8_T)c1_IN_vhod3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,23);
      chartInstance.c1_tp_vhod3 = 1;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,21);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,16);
      switch(chartInstance.c1_is_evm_1) {
       case c1_IN_obsluwivanie1:
        CV_STATE_EVAL(16,0,1);
        {
          real_T c1_sf_d0;
          real_T c1_sf_d1;
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,20);
          if(CV_TRANSITION_EVAL(20U,
            (int32_T)_SFD_CCP_CALL(20,0,(chartInstance.c1_Tobs1 > 0.0))) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,20);
            chartInstance.c1_tp_obsluwivanie1 = 0;
            chartInstance.c1_is_evm_1 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,20);
            chartInstance.c1_Tobs1--;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs1, 20U);
            c1_sf_d0 = chartInstance.c1_Tobs1;
            sf_mex_printf("%s =\\n", "Tobs1");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d0);
            chartInstance.c1_is_evm_1 = (uint8_T)c1_IN_obsluwivanie1;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,20);
            chartInstance.c1_tp_obsluwivanie1 = 1;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,27);
            chartInstance.c1_tp_obsluwivanie1 = 0;
            chartInstance.c1_is_evm_1 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,20);
            (*c1_kol_z1())++;
            _SFD_DATA_RANGE_CHECK(*c1_kol_z1(), 0U);
            c1_sf_d1 = *c1_kol_z1();
            sf_mex_printf("%s =\\n", "kol_z1");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d1);
            chartInstance.c1_is_evm_1 = (uint8_T)c1_IN_vhod1;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,10);
            chartInstance.c1_tp_vhod1 = 1;
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,20);
        }
        break;
       case c1_IN_vhod1:
        CV_STATE_EVAL(16,0,2);
        {
          real_T c1_sf_d2;
          real_T c1_sf_d3;
          real_T c1_sf_d4;
          real_T c1_sf_d5;
          real_T c1_sf_d6;
          real_T c1_sf_d7;
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,10);
          if(CV_TRANSITION_EVAL(42U, (int32_T)_SFD_CCP_CALL(42,0,(*c1_n1() >
              0.0))) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,42);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,22);
            if(CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2,0,((*c1_n1() +
                 *c1_n2()) + *c1_n3() < 25.0))) != 0) {
              if(sf_debug_transition_conflict_check_enabled()) {
                unsigned int transitionList[2];
                unsigned int numTransitions=1;
                transitionList[0] = 2;
                sf_debug_transition_conflict_check_begin();
                if((*c1_n1() + *c1_n2()) + *c1_n3() >= 25.0) {
                  transitionList[numTransitions] = 57;
                  numTransitions++;
                }
                sf_debug_transition_conflict_check_end();
                if(numTransitions>1) {
                  _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
                }
              }
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,36);
              chartInstance.c1_tp_vhod1 = 0;
              chartInstance.c1_is_evm_1 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG,10);
              (*c1_n1())--;
              _SFD_DATA_RANGE_CHECK(*c1_n1(), 13U);
              c1_sf_d2 = *c1_n1();
              sf_mex_printf("%s =\\n", "n1");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d2);
              chartInstance.c1_Tobs1 = 33.0;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs1, 20U);
              c1_sf_d3 = chartInstance.c1_Tobs1;
              sf_mex_printf("%s =\\n", "Tobs1");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d3);
              chartInstance.c1_Tobs1sum += chartInstance.c1_Tobs1;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs1sum, 18U);
              c1_sf_d4 = chartInstance.c1_Tobs1sum;
              sf_mex_printf("%s =\\n", "Tobs1sum");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d4);
              chartInstance.c1_is_evm_1 = (uint8_T)c1_IN_obsluwivanie1;
              _SFD_CS_CALL(STATE_ACTIVE_TAG,20);
              chartInstance.c1_tp_obsluwivanie1 = 1;
            } else if(CV_TRANSITION_EVAL(57U,
              (int32_T)_SFD_CCP_CALL(57,0,((*c1_n1() + *c1_n2()) + *c1_n3() >=
                25.0))) != 0) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,57);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,36);
              chartInstance.c1_tp_vhod1 = 0;
              chartInstance.c1_is_evm_1 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG,10);
              (*c1_n1())--;
              _SFD_DATA_RANGE_CHECK(*c1_n1(), 13U);
              c1_sf_d5 = *c1_n1();
              sf_mex_printf("%s =\\n", "n1");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d5);
              chartInstance.c1_Tobs1 = 25.0;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs1, 20U);
              c1_sf_d6 = chartInstance.c1_Tobs1;
              sf_mex_printf("%s =\\n", "Tobs1");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d6);
              chartInstance.c1_Tobs1sum += chartInstance.c1_Tobs1;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs1sum, 18U);
              c1_sf_d7 = chartInstance.c1_Tobs1sum;
              sf_mex_printf("%s =\\n", "Tobs1sum");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d7);
              chartInstance.c1_is_evm_1 = (uint8_T)c1_IN_obsluwivanie1;
              _SFD_CS_CALL(STATE_ACTIVE_TAG,20);
              chartInstance.c1_tp_obsluwivanie1 = 1;
            }
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
        }
        break;
       default:
        CV_STATE_EVAL(16,0,0);
        break;
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,16);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,19);
      switch(chartInstance.c1_is_Istochnik) {
       case c1_IN_stopinng:
        CV_STATE_EVAL(19,0,1);
        break;
       case c1_IN_vihod:
        CV_STATE_EVAL(19,0,2);
        {
          real_T c1_sf_d8;
          real_T c1_sf_d9;
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,11);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,18);
          if(CV_TRANSITION_EVAL(1U,
            (int32_T)_SFD_CCP_CALL(1,0,(chartInstance.c1_kolzajv == 500.0))) !=
           0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
            chartInstance.c1_tp_vihod = 0;
            chartInstance.c1_is_Istochnik = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
            sf_mex_import(sf_mex_evalin(0, 1U, "round(unifrnd(5,15))"), "ml",
             &c1_sf_d8, 0, 0U, 0, 0);
            chartInstance.c1_Tmew = c1_sf_d8;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tmew, 10U);
            chartInstance.c1_prihod = 0.0;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_prihod, 2U);
            chartInstance.c1_is_Istochnik = (uint8_T)c1_IN_stopinng;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,17);
            chartInstance.c1_tp_stopinng = 1;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,40);
            chartInstance.c1_tp_vihod = 0;
            chartInstance.c1_is_Istochnik = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
            sf_mex_import(sf_mex_evalin(0, 1U, "round(unifrnd(5,15))"), "ml",
             &c1_sf_d9, 0, 0U, 0, 0);
            chartInstance.c1_Tmew = c1_sf_d9;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tmew, 10U);
            chartInstance.c1_prihod = 0.0;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_prihod, 2U);
            chartInstance.c1_is_Istochnik = (uint8_T)c1_IN_zaderwka;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
            chartInstance.c1_tp_zaderwka = 1;
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
        }
        break;
       case c1_IN_zaderwka:
        CV_STATE_EVAL(19,0,3);
        {
          real_T c1_sf_d10;
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,8);
          if(CV_TRANSITION_EVAL(6U,
            (int32_T)_SFD_CCP_CALL(6,0,(chartInstance.c1_Tmew > 0.0))) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,6);
            chartInstance.c1_tp_zaderwka = 0;
            chartInstance.c1_is_Istochnik = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,8);
            chartInstance.c1_Tmew--;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tmew, 10U);
            c1_sf_d10 = chartInstance.c1_Tmew;
            sf_mex_printf("%s =\\n", "Tmew");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d10);
            chartInstance.c1_is_Istochnik = (uint8_T)c1_IN_zaderwka;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,8);
            chartInstance.c1_tp_zaderwka = 1;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,33);
            chartInstance.c1_tp_zaderwka = 0;
            chartInstance.c1_is_Istochnik = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,8);
            chartInstance.c1_is_Istochnik = (uint8_T)c1_IN_vihod;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
            chartInstance.c1_tp_vihod = 1;
            chartInstance.c1_prihod = 1.0;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_prihod, 2U);
            chartInstance.c1_kolzajv++;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_kolzajv, 25U);
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
        }
        break;
       default:
        CV_STATE_EVAL(19,0,0);
        break;
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,19);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,6);
      switch(chartInstance.c1_is_predvaritobrabotka) {
       case c1_IN_obrabotka:
        CV_STATE_EVAL(6,0,1);
        {
          real_T c1_sf_d11;
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,2);
          if(CV_TRANSITION_EVAL(32U,
            (int32_T)_SFD_CCP_CALL(32,0,(chartInstance.c1_Tobs > 0.0))) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,32);
            chartInstance.c1_tp_obrabotka = 0;
            chartInstance.c1_is_predvaritobrabotka =
              (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
            chartInstance.c1_Tobs--;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs, 15U);
            c1_sf_d11 = chartInstance.c1_Tobs;
            sf_mex_printf("%s =\\n", "Tobs");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d11);
            chartInstance.c1_is_predvaritobrabotka = (uint8_T)c1_IN_obrabotka;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
            chartInstance.c1_tp_obrabotka = 1;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,16);
            chartInstance.c1_tp_obrabotka = 0;
            chartInstance.c1_is_predvaritobrabotka =
              (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
            chartInstance.c1_osv_kan0 = 1.0;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_osv_kan0, 9U);
            chartInstance.c1_is_predvaritobrabotka = (uint8_T)c1_IN_vhod;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,4);
            chartInstance.c1_tp_vhod = 1;
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
        }
        break;
       case c1_IN_vhod:
        CV_STATE_EVAL(6,0,2);
        {
          real_T c1_sf_d12;
          real_T c1_sf_d13;
          real_T c1_sf_d14;
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,4);
          if(CV_TRANSITION_EVAL(3U,
            (int32_T)_SFD_CCP_CALL(3,0,(chartInstance.c1_bocher > 0.0))) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,25);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,53);
            chartInstance.c1_tp_vhod = 0;
            chartInstance.c1_is_predvaritobrabotka =
              (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,4);
            sf_mex_import(sf_mex_evalin(0, 1U, "round(unifrnd(7,13))"), "ml",
             &c1_sf_d14, 0, 0U, 0, 0);
            chartInstance.c1_Tobs = c1_sf_d14;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs, 15U);
            c1_sf_d12 = chartInstance.c1_Tobs;
            sf_mex_printf("%s =\\n", "Tobs");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d12);
            chartInstance.c1_Tobssum += chartInstance.c1_Tobs;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobssum, 26U);
            c1_sf_d13 = chartInstance.c1_Tobssum;
            sf_mex_printf("%s =\\n", "Tobssum");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d13);
            chartInstance.c1_bocher--;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_bocher, 8U);
            chartInstance.c1_is_predvaritobrabotka = (uint8_T)c1_IN_obrabotka;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
            chartInstance.c1_tp_obrabotka = 1;
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
        }
        break;
       default:
        CV_STATE_EVAL(6,0,0);
        break;
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,12);
      {
        real_T c1_sf_d15;
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,5);
        if(CV_TRANSITION_EVAL(35U,
          (int32_T)_SFD_CCP_CALL(35,0,(chartInstance.c1_prihod == 1.0))) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,35);
          chartInstance.c1_tp_beskonechnakopitel = 0;
          chartInstance.c1_is_besknakop = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,5);
          chartInstance.c1_bocher++;
          _SFD_DATA_RANGE_CHECK(chartInstance.c1_bocher, 8U);
          c1_sf_d15 = chartInstance.c1_bocher;
          sf_mex_printf("%s =\\n", "bocher");
          sf_mex_call("disp", 0U, 1U, 6, c1_sf_d15);
          chartInstance.c1_is_besknakop = (uint8_T)c1_IN_beskonechnakopitel;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,5);
          chartInstance.c1_tp_beskonechnakopitel = 1;
        }
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,3);
      {
        real_T c1_sf_d16;
        real_T c1_sf_d17;
        real_T c1_sf_d18;
        real_T c1_sf_d19;
        real_T c1_sf_d20;
        real_T c1_sf_d21;
        real_T c1_sf_d22;
        real_T c1_sf_d23;
        real_T c1_sf_d24;
        real_T c1_sf_d25;
        real_T c1_sf_d26;
        real_T c1_sf_d27;
        real_T c1_sf_d28;
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,13);
        if(CV_TRANSITION_EVAL(7U,
          (int32_T)_SFD_CCP_CALL(7,0,(chartInstance.c1_osv_kan0 == 1.0))) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,7);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,37);
          if(CV_TRANSITION_EVAL(46U, (_SFD_CCP_CALL(46,0,(*c1_n1() == 10.0)) !=
             0) && (_SFD_CCP_CALL(46,1,(*c1_n2() == 10.0)) != 0) &&
            (_SFD_CCP_CALL(46,2,(
               *c1_n3() == 10.0)) != 0)) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,46);
            chartInstance.c1_tp_raspredelenie = 0;
            chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
            chartInstance.c1_osv_kan0 = 0.0;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_osv_kan0, 9U);
            (*c1_kol_otkaz())++;
            _SFD_DATA_RANGE_CHECK(*c1_kol_otkaz(), 5U);
            c1_sf_d16 = *c1_kol_otkaz();
            sf_mex_printf("%s =\\n", "kol_otkaz");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d16);
            chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_raspredelenie;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
            chartInstance.c1_tp_raspredelenie = 1;
            goto label_1;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,28);
            if(CV_TRANSITION_EVAL(39U, (_SFD_CCP_CALL(39,0,(*c1_n2() ==
                 *c1_n3())) != 0) && (_SFD_CCP_CALL(39,1,(*c1_n1() == *c1_n2()))
               != 0))
             != 0) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,39);
              if(CV_TRANSITION_EVAL(59U,
                (_SFD_CCP_CALL(59,0,(chartInstance.c1_raspr >
                   (real_T)c1__s32_div__(1, 3))) != 0) && (_SFD_CCP_CALL(59,1,(
                   chartInstance.c1_raspr <= (real_T)c1__s32_div__(2, 3))) !=
                 0)) != 0) {
                if(sf_debug_transition_conflict_check_enabled()) {
                  unsigned int transitionList[3];
                  unsigned int numTransitions=1;
                  transitionList[0] = 59;
                  sf_debug_transition_conflict_check_begin();
                  if((chartInstance.c1_raspr > (real_T)c1__s32_div__(2, 3)) &&
                   (chartInstance.c1_raspr <= 1.0)) {
                    transitionList[numTransitions] = 44;
                    numTransitions++;
                  }
                  if((chartInstance.c1_raspr >= 0.0) && (chartInstance.c1_raspr
                    <= (real_T)c1__s32_div__(1, 3))) {
                    transitionList[numTransitions] = 31;
                    numTransitions++;
                  }
                  sf_debug_transition_conflict_check_end();
                  if(numTransitions>1) {
                    _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
                  }
                }
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,59);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,11);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,23);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,17);
                chartInstance.c1_tp_raspredelenie = 0;
                chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
                _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
                chartInstance.c1_osv_kan0 = 0.0;
                _SFD_DATA_RANGE_CHECK(chartInstance.c1_osv_kan0, 9U);
                sf_mex_import(sf_mex_evalin(0, 1U, "unifrnd(0,1)"), "ml",
                 &c1_sf_d26, 0, 0U, 0, 0);
                chartInstance.c1_raspr = c1_sf_d26;
                _SFD_DATA_RANGE_CHECK(chartInstance.c1_raspr, 4U);
                c1_sf_d17 = chartInstance.c1_raspr;
                sf_mex_printf("%s =\\n", "raspr");
                sf_mex_call("disp", 0U, 1U, 6, c1_sf_d17);
                (*c1_n3())++;
                _SFD_DATA_RANGE_CHECK(*c1_n3(), 24U);
                c1_sf_d18 = *c1_n3();
                sf_mex_printf("%s =\\n", "n3");
                sf_mex_call("disp", 0U, 1U, 6, c1_sf_d18);
                chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_raspredelenie;
                _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
                chartInstance.c1_tp_raspredelenie = 1;
                goto label_1;
              } else if(CV_TRANSITION_EVAL(44U,
                (_SFD_CCP_CALL(44,0,(chartInstance.c1_raspr >
                   (real_T)c1__s32_div__(2, 3))) != 0) && (_SFD_CCP_CALL(44,1,(
                   chartInstance.c1_raspr <= 1.0)) != 0)) != 0) {
                if(sf_debug_transition_conflict_check_enabled()) {
                  unsigned int transitionList[2];
                  unsigned int numTransitions=1;
                  transitionList[0] = 44;
                  sf_debug_transition_conflict_check_begin();
                  if((chartInstance.c1_raspr >= 0.0) && (chartInstance.c1_raspr
                    <= (real_T)c1__s32_div__(1, 3))) {
                    transitionList[numTransitions] = 31;
                    numTransitions++;
                  }
                  sf_debug_transition_conflict_check_end();
                  if(numTransitions>1) {
                    _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
                  }
                }
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,44);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,38);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,30);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,17);
                chartInstance.c1_tp_raspredelenie = 0;
                chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
                _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
                chartInstance.c1_osv_kan0 = 0.0;
                _SFD_DATA_RANGE_CHECK(chartInstance.c1_osv_kan0, 9U);
                sf_mex_import(sf_mex_evalin(0, 1U, "unifrnd(0,1)"), "ml",
                 &c1_sf_d27, 0, 0U, 0, 0);
                chartInstance.c1_raspr = c1_sf_d27;
                _SFD_DATA_RANGE_CHECK(chartInstance.c1_raspr, 4U);
                c1_sf_d19 = chartInstance.c1_raspr;
                sf_mex_printf("%s =\\n", "raspr");
                sf_mex_call("disp", 0U, 1U, 6, c1_sf_d19);
                (*c1_n2())++;
                _SFD_DATA_RANGE_CHECK(*c1_n2(), 21U);
                c1_sf_d20 = *c1_n2();
                sf_mex_printf("%s =\\n", "n2");
                sf_mex_call("disp", 0U, 1U, 6, c1_sf_d20);
                chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_raspredelenie;
                _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
                chartInstance.c1_tp_raspredelenie = 1;
                goto label_1;
              } else if(CV_TRANSITION_EVAL(31U,
                (_SFD_CCP_CALL(31,0,(chartInstance.c1_raspr >= 0.0)) != 0) &&
                (_SFD_CCP_CALL(31,1,(chartInstance.
                   c1_raspr <= (real_T)c1__s32_div__(1, 3))) != 0)) != 0) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,31);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,26);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,13);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,17);
                chartInstance.c1_tp_raspredelenie = 0;
                chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
                _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
                chartInstance.c1_osv_kan0 = 0.0;
                _SFD_DATA_RANGE_CHECK(chartInstance.c1_osv_kan0, 9U);
                sf_mex_import(sf_mex_evalin(0, 1U, "unifrnd(0,1)"), "ml",
                 &c1_sf_d28, 0, 0U, 0, 0);
                chartInstance.c1_raspr = c1_sf_d28;
                _SFD_DATA_RANGE_CHECK(chartInstance.c1_raspr, 4U);
                c1_sf_d21 = chartInstance.c1_raspr;
                sf_mex_printf("%s =\\n", "raspr");
                sf_mex_call("disp", 0U, 1U, 6, c1_sf_d21);
                (*c1_n1())++;
                _SFD_DATA_RANGE_CHECK(*c1_n1(), 13U);
                c1_sf_d22 = *c1_n1();
                sf_mex_printf("%s =\\n", "n1");
                sf_mex_call("disp", 0U, 1U, 6, c1_sf_d22);
                chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_raspredelenie;
                _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
                chartInstance.c1_tp_raspredelenie = 1;
                goto label_1;
              }
            }
          }
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,24);
          if(CV_TRANSITION_EVAL(12U, (_SFD_CCP_CALL(12,0,(*c1_n1() < *c1_n3()))
             != 0) && (_SFD_CCP_CALL(12,1,(*c1_n1() <= *c1_n2())) != 0))
           != 0) {
            if(sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[3];
              unsigned int numTransitions=1;
              transitionList[0] = 12;
              sf_debug_transition_conflict_check_begin();
              if((*c1_n2() < *c1_n1()) && (*c1_n2() <= *c1_n3())) {
                transitionList[numTransitions] = 9;
                numTransitions++;
              }
              if((*c1_n3() <= *c1_n1()) && (*c1_n3() < *c1_n2())) {
                transitionList[numTransitions] = 15;
                numTransitions++;
              }
              sf_debug_transition_conflict_check_end();
              if(numTransitions>1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,12);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,26);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,13);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,17);
            chartInstance.c1_tp_raspredelenie = 0;
            chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
            chartInstance.c1_osv_kan0 = 0.0;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_osv_kan0, 9U);
            (*c1_n1())++;
            _SFD_DATA_RANGE_CHECK(*c1_n1(), 13U);
            c1_sf_d23 = *c1_n1();
            sf_mex_printf("%s =\\n", "n1");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d23);
            chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_raspredelenie;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
            chartInstance.c1_tp_raspredelenie = 1;
          } else if(CV_TRANSITION_EVAL(9U, (_SFD_CCP_CALL(9,0,(*c1_n2() <
               *c1_n1())) != 0) && (_SFD_CCP_CALL(9,1,(*c1_n2() <= *c1_n3())) !=
             0)
            ) != 0) {
            if(sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[2];
              unsigned int numTransitions=1;
              transitionList[0] = 9;
              sf_debug_transition_conflict_check_begin();
              if((*c1_n3() <= *c1_n1()) && (*c1_n3() < *c1_n2())) {
                transitionList[numTransitions] = 15;
                numTransitions++;
              }
              sf_debug_transition_conflict_check_end();
              if(numTransitions>1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,9);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,38);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,30);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,17);
            chartInstance.c1_tp_raspredelenie = 0;
            chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
            chartInstance.c1_osv_kan0 = 0.0;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_osv_kan0, 9U);
            (*c1_n2())++;
            _SFD_DATA_RANGE_CHECK(*c1_n2(), 21U);
            c1_sf_d24 = *c1_n2();
            sf_mex_printf("%s =\\n", "n2");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d24);
            chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_raspredelenie;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
            chartInstance.c1_tp_raspredelenie = 1;
          } else if(CV_TRANSITION_EVAL(15U, (_SFD_CCP_CALL(15,0,(*c1_n3() <=
               *c1_n1())) != 0) && (_SFD_CCP_CALL(15,1,(*c1_n3() < *c1_n2()))
             != 0)) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,15);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,11);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,23);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,17);
            chartInstance.c1_tp_raspredelenie = 0;
            chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
            chartInstance.c1_osv_kan0 = 0.0;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_osv_kan0, 9U);
            (*c1_n3())++;
            _SFD_DATA_RANGE_CHECK(*c1_n3(), 24U);
            c1_sf_d25 = *c1_n3();
            sf_mex_printf("%s =\\n", "n3");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d25);
            chartInstance.c1_is_vetvlenie = (uint8_T)c1_IN_raspredelenie;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
            chartInstance.c1_tp_raspredelenie = 1;
          }
          label_1:;
        }
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,14);
      switch(chartInstance.c1_is_evm_2) {
       case c1_IN_obsluwivanie2:
        CV_STATE_EVAL(14,0,1);
        {
          real_T c1_sf_d29;
          real_T c1_sf_d30;
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,18);
          if(CV_TRANSITION_EVAL(41U,
            (int32_T)_SFD_CCP_CALL(41,0,(chartInstance.c1_Tobs2 > 0.0))) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,41);
            chartInstance.c1_tp_obsluwivanie2 = 0;
            chartInstance.c1_is_evm_2 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,18);
            chartInstance.c1_Tobs2--;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs2, 1U);
            c1_sf_d29 = chartInstance.c1_Tobs2;
            sf_mex_printf("%s =\\n", "Tobs2");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d29);
            chartInstance.c1_is_evm_2 = (uint8_T)c1_IN_obsluwivanie2;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,18);
            chartInstance.c1_tp_obsluwivanie2 = 1;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,5);
            chartInstance.c1_tp_obsluwivanie2 = 0;
            chartInstance.c1_is_evm_2 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,18);
            (*c1_kol_z2())++;
            _SFD_DATA_RANGE_CHECK(*c1_kol_z2(), 23U);
            c1_sf_d30 = *c1_kol_z2();
            sf_mex_printf("%s =\\n", "kol_z2");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d30);
            chartInstance.c1_is_evm_2 = (uint8_T)c1_IN_vhod2;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,24);
            chartInstance.c1_tp_vhod2 = 1;
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,18);
        }
        break;
       case c1_IN_vhod2:
        CV_STATE_EVAL(14,0,2);
        {
          real_T c1_sf_d31;
          real_T c1_sf_d32;
          real_T c1_sf_d33;
          real_T c1_sf_d34;
          real_T c1_sf_d35;
          real_T c1_sf_d36;
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,24);
          if(CV_TRANSITION_EVAL(45U, (int32_T)_SFD_CCP_CALL(45,0,(*c1_n2() >
              0.0))) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,45);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,49);
            if(CV_TRANSITION_EVAL(55U, (int32_T)_SFD_CCP_CALL(55,0,((*c1_n1() +
                 *c1_n2()) + *c1_n3() < 25.0))) != 0) {
              if(sf_debug_transition_conflict_check_enabled()) {
                unsigned int transitionList[2];
                unsigned int numTransitions=1;
                transitionList[0] = 55;
                sf_debug_transition_conflict_check_begin();
                if((*c1_n1() + *c1_n2()) + *c1_n3() >= 25.0) {
                  transitionList[numTransitions] = 21;
                  numTransitions++;
                }
                sf_debug_transition_conflict_check_end();
                if(numTransitions>1) {
                  _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
                }
              }
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,55);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,8);
              chartInstance.c1_tp_vhod2 = 0;
              chartInstance.c1_is_evm_2 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG,24);
              (*c1_n2())--;
              _SFD_DATA_RANGE_CHECK(*c1_n2(), 21U);
              c1_sf_d31 = *c1_n2();
              sf_mex_printf("%s =\\n", "n2");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d31);
              chartInstance.c1_Tobs2 = 33.0;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs2, 1U);
              c1_sf_d32 = chartInstance.c1_Tobs2;
              sf_mex_printf("%s =\\n", "Tobs2");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d32);
              chartInstance.c1_Tobs2sum += chartInstance.c1_Tobs2;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs2sum, 6U);
              c1_sf_d33 = chartInstance.c1_Tobs2sum;
              sf_mex_printf("%s =\\n", "Tobs2sum");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d33);
              chartInstance.c1_is_evm_2 = (uint8_T)c1_IN_obsluwivanie2;
              _SFD_CS_CALL(STATE_ACTIVE_TAG,18);
              chartInstance.c1_tp_obsluwivanie2 = 1;
            } else if(CV_TRANSITION_EVAL(21U,
              (int32_T)_SFD_CCP_CALL(21,0,((*c1_n1() + *c1_n2()) + *c1_n3() >=
                25.0))) != 0) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,21);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,8);
              chartInstance.c1_tp_vhod2 = 0;
              chartInstance.c1_is_evm_2 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG,24);
              (*c1_n2())--;
              _SFD_DATA_RANGE_CHECK(*c1_n2(), 21U);
              c1_sf_d34 = *c1_n2();
              sf_mex_printf("%s =\\n", "n2");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d34);
              chartInstance.c1_Tobs2 = 25.0;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs2, 1U);
              c1_sf_d35 = chartInstance.c1_Tobs2;
              sf_mex_printf("%s =\\n", "Tobs2");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d35);
              chartInstance.c1_Tobs2sum += chartInstance.c1_Tobs2;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs2sum, 6U);
              c1_sf_d36 = chartInstance.c1_Tobs2sum;
              sf_mex_printf("%s =\\n", "Tobs2sum");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d36);
              chartInstance.c1_is_evm_2 = (uint8_T)c1_IN_obsluwivanie2;
              _SFD_CS_CALL(STATE_ACTIVE_TAG,18);
              chartInstance.c1_tp_obsluwivanie2 = 1;
            }
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,24);
        }
        break;
       default:
        CV_STATE_EVAL(14,0,0);
        break;
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,14);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,22);
      if(CV_TRANSITION_EVAL(50U, (int32_T)_SFD_CCP_CALL(50,0,(((*c1_kol_z1() +
            *c1_kol_z2()) + *c1_kol_z3()) + *c1_kol_otkaz() == 500.0)))
       != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,50);
        *c1_ver_per() = *c1_kol_otkaz() / chartInstance.c1_kolzajv;
        _SFD_DATA_RANGE_CHECK(*c1_ver_per(), 16U);
        *c1_svzskan() = chartInstance.c1_Tobssum / chartInstance.c1_kolzajv;
        _SFD_DATA_RANGE_CHECK(*c1_svzskan(), 7U);
        *c1_svzsevm1() = chartInstance.c1_Tobs1sum / *c1_kol_z1();
        _SFD_DATA_RANGE_CHECK(*c1_svzsevm1(), 17U);
        *c1_svzsevm2() = chartInstance.c1_Tobs2sum / *c1_kol_z2();
        _SFD_DATA_RANGE_CHECK(*c1_svzsevm2(), 12U);
        *c1_svzsevm3() = chartInstance.c1_Tobs3sum / *c1_kol_z3();
        _SFD_DATA_RANGE_CHECK(*c1_svzsevm3(), 3U);
        chartInstance.c1_tp_stat2 = 0;
        chartInstance.c1_is_statistica2 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,22);
        chartInstance.c1_is_statistica2 = (uint8_T)c1_IN_stat2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,22);
        chartInstance.c1_tp_stat2 = 1;
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,22);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,7);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,9);
      if(CV_TRANSITION_EVAL(48U, (int32_T)_SFD_CCP_CALL(48,0,(((*c1_kol_z1() +
            *c1_kol_z2()) + *c1_kol_z3()) + *c1_kol_otkaz() < 500.0)))
       != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,48);
        chartInstance.c1_tp_stat1 = 0;
        chartInstance.c1_is_statistica1 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,9);
        chartInstance.c1_is_statistica1 = (uint8_T)c1_IN_stat1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,9);
        chartInstance.c1_tp_stat1 = 1;
        (*c1_total_time())++;
        _SFD_DATA_RANGE_CHECK(*c1_total_time(), 14U);
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,15);
      switch(chartInstance.c1_is_evm_3) {
       case c1_IN_obsluwivanie3:
        CV_STATE_EVAL(15,0,1);
        {
          real_T c1_sf_d37;
          real_T c1_sf_d38;
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
          if(CV_TRANSITION_EVAL(34U,
            (int32_T)_SFD_CCP_CALL(34,0,(chartInstance.c1_Tobs3 > 0.0))) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,34);
            chartInstance.c1_tp_obsluwivanie3 = 0;
            chartInstance.c1_is_evm_3 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
            chartInstance.c1_Tobs3--;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs3, 22U);
            c1_sf_d37 = chartInstance.c1_Tobs3;
            sf_mex_printf("%s =\\n", "Tobs3");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d37);
            chartInstance.c1_is_evm_3 = (uint8_T)c1_IN_obsluwivanie3;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
            chartInstance.c1_tp_obsluwivanie3 = 1;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,29);
            chartInstance.c1_tp_obsluwivanie3 = 0;
            chartInstance.c1_is_evm_3 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
            (*c1_kol_z3())++;
            _SFD_DATA_RANGE_CHECK(*c1_kol_z3(), 11U);
            c1_sf_d38 = *c1_kol_z3();
            sf_mex_printf("%s =\\n", "kol_z3");
            sf_mex_call("disp", 0U, 1U, 6, c1_sf_d38);
            chartInstance.c1_is_evm_3 = (uint8_T)c1_IN_vhod3;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,23);
            chartInstance.c1_tp_vhod3 = 1;
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
        }
        break;
       case c1_IN_vhod3:
        CV_STATE_EVAL(15,0,2);
        {
          real_T c1_sf_d39;
          real_T c1_sf_d40;
          real_T c1_sf_d41;
          real_T c1_sf_d42;
          real_T c1_sf_d43;
          real_T c1_sf_d44;
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,23);
          if(CV_TRANSITION_EVAL(47U, (int32_T)_SFD_CCP_CALL(47,0,(*c1_n3() >
              0.0))) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,47);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,14);
            if(CV_TRANSITION_EVAL(56U, (int32_T)_SFD_CCP_CALL(56,0,((*c1_n1() +
                 *c1_n2()) + *c1_n3() < 25.0))) != 0) {
              if(sf_debug_transition_conflict_check_enabled()) {
                unsigned int transitionList[2];
                unsigned int numTransitions=1;
                transitionList[0] = 56;
                sf_debug_transition_conflict_check_begin();
                if((*c1_n1() + *c1_n2()) + *c1_n3() >= 25.0) {
                  transitionList[numTransitions] = 19;
                  numTransitions++;
                }
                sf_debug_transition_conflict_check_end();
                if(numTransitions>1) {
                  _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
                }
              }
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,56);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,52);
              chartInstance.c1_tp_vhod3 = 0;
              chartInstance.c1_is_evm_3 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG,23);
              (*c1_n3())--;
              _SFD_DATA_RANGE_CHECK(*c1_n3(), 24U);
              c1_sf_d39 = *c1_n3();
              sf_mex_printf("%s =\\n", "n3");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d39);
              chartInstance.c1_Tobs3 = 33.0;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs3, 22U);
              c1_sf_d40 = chartInstance.c1_Tobs3;
              sf_mex_printf("%s =\\n", "Tobs3");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d40);
              chartInstance.c1_Tobs3sum += chartInstance.c1_Tobs3;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs3sum, 19U);
              c1_sf_d41 = chartInstance.c1_Tobs3sum;
              sf_mex_printf("%s =\\n", "Tobs3sum");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d41);
              chartInstance.c1_is_evm_3 = (uint8_T)c1_IN_obsluwivanie3;
              _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
              chartInstance.c1_tp_obsluwivanie3 = 1;
            } else if(CV_TRANSITION_EVAL(19U,
              (int32_T)_SFD_CCP_CALL(19,0,((*c1_n1() + *c1_n2()) + *c1_n3() >=
                25.0))) != 0) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,19);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,52);
              chartInstance.c1_tp_vhod3 = 0;
              chartInstance.c1_is_evm_3 = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG,23);
              (*c1_n3())--;
              _SFD_DATA_RANGE_CHECK(*c1_n3(), 24U);
              c1_sf_d42 = *c1_n3();
              sf_mex_printf("%s =\\n", "n3");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d42);
              chartInstance.c1_Tobs3 = 25.0;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs3, 22U);
              c1_sf_d43 = chartInstance.c1_Tobs3;
              sf_mex_printf("%s =\\n", "Tobs3");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d43);
              chartInstance.c1_Tobs3sum += chartInstance.c1_Tobs3;
              _SFD_DATA_RANGE_CHECK(chartInstance.c1_Tobs3sum, 19U);
              c1_sf_d44 = chartInstance.c1_Tobs3sum;
              sf_mex_printf("%s =\\n", "Tobs3sum");
              sf_mex_call("disp", 0U, 1U, 6, c1_sf_d44);
              chartInstance.c1_is_evm_3 = (uint8_T)c1_IN_obsluwivanie3;
              _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
              chartInstance.c1_tp_obsluwivanie3 = 1;
            }
          }
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,23);
        }
        break;
       default:
        CV_STATE_EVAL(15,0,0);
        break;
      }
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,15);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,21);
    }
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG,c1_event_event);
    _sfEvent_ = c1_previousEvent;
  }
}

static int32_T c1__s32_div__(int32_T c1_b, int32_T c1_c)
{
  if(c1_c == 0) {
    sf_debug_overflow_detection(1);
  }
  if((c1_c == -1) && (c1_b < -2147483647)) {
    sf_debug_overflow_detection(0);
  }
  return c1_b / c1_c;
}

static real_T *c1_ver_per(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
}

static real_T *c1_total_time(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
}

static real_T *c1_n3(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
}

static real_T *c1_n2(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
}

static real_T *c1_n1(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
}

static real_T *c1_kol_otkaz(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 6);
}

static real_T *c1_kol_z1(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 7);
}

static real_T *c1_kol_z2(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 8);
}

static real_T *c1_kol_z3(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 9);
}

static real_T *c1_svzsevm1(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 10);
}

static real_T *c1_svzsevm2(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 11);
}

static real_T *c1_svzsevm3(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 12);
}

static real_T *c1_svzskan(void)
{
  return (real_T *)ssGetOutputPortSignal(chartInstance.S, 13);
}

static void init_test_point_addr_map(void)
{
  chartInstance.c1_testPointAddrMap[0] = &chartInstance.c1_Tmew;
  chartInstance.c1_testPointAddrMap[1] = &chartInstance.c1_bocher;
  chartInstance.c1_testPointAddrMap[2] = &chartInstance.c1_kolzajv;
  chartInstance.c1_testPointAddrMap[3] = &chartInstance.c1_prihod;
  chartInstance.c1_testPointAddrMap[4] = &chartInstance.c1_Tobs;
  chartInstance.c1_testPointAddrMap[5] = &chartInstance.c1_Tobs1;
  chartInstance.c1_testPointAddrMap[6] = &chartInstance.c1_Tobs2;
  chartInstance.c1_testPointAddrMap[7] = &chartInstance.c1_Tobs3;
  chartInstance.c1_testPointAddrMap[8] = &chartInstance.c1_osv_kan0;
  chartInstance.c1_testPointAddrMap[9] = &chartInstance.c1_raspr;
  chartInstance.c1_testPointAddrMap[10] = &chartInstance.c1_Tobs1sum;
  chartInstance.c1_testPointAddrMap[11] = &chartInstance.c1_Tobs2sum;
  chartInstance.c1_testPointAddrMap[12] = &chartInstance.c1_Tobs3sum;
  chartInstance.c1_testPointAddrMap[13] = &chartInstance.c1_Tobssum;
  chartInstance.c1_testPointAddrMap[14] = &chartInstance.c1_tp_SMO;
  chartInstance.c1_testPointAddrMap[15] = &chartInstance.c1_tp_Istochnik;
  chartInstance.c1_testPointAddrMap[16] = &chartInstance.c1_tp_stopinng;
  chartInstance.c1_testPointAddrMap[17] = &chartInstance.c1_tp_vihod;
  chartInstance.c1_testPointAddrMap[18] = &chartInstance.c1_tp_zaderwka;
  chartInstance.c1_testPointAddrMap[19] = &chartInstance.c1_tp_besknakop;
  chartInstance.c1_testPointAddrMap[20] =
    &chartInstance.c1_tp_beskonechnakopitel;
  chartInstance.c1_testPointAddrMap[21] = &chartInstance.c1_tp_evm_1;
  chartInstance.c1_testPointAddrMap[22] = &chartInstance.c1_tp_obsluwivanie1;
  chartInstance.c1_testPointAddrMap[23] = &chartInstance.c1_tp_vhod1;
  chartInstance.c1_testPointAddrMap[24] = &chartInstance.c1_tp_evm_2;
  chartInstance.c1_testPointAddrMap[25] = &chartInstance.c1_tp_obsluwivanie2;
  chartInstance.c1_testPointAddrMap[26] = &chartInstance.c1_tp_vhod2;
  chartInstance.c1_testPointAddrMap[27] = &chartInstance.c1_tp_evm_3;
  chartInstance.c1_testPointAddrMap[28] = &chartInstance.c1_tp_obsluwivanie3;
  chartInstance.c1_testPointAddrMap[29] = &chartInstance.c1_tp_vhod3;
  chartInstance.c1_testPointAddrMap[30] =
    &chartInstance.c1_tp_predvaritobrabotka;
  chartInstance.c1_testPointAddrMap[31] = &chartInstance.c1_tp_obrabotka;
  chartInstance.c1_testPointAddrMap[32] = &chartInstance.c1_tp_vhod;
  chartInstance.c1_testPointAddrMap[33] = &chartInstance.c1_tp_statistica1;
  chartInstance.c1_testPointAddrMap[34] = &chartInstance.c1_tp_stat1;
  chartInstance.c1_testPointAddrMap[35] = &chartInstance.c1_tp_statistica2;
  chartInstance.c1_testPointAddrMap[36] = &chartInstance.c1_tp_stat2;
  chartInstance.c1_testPointAddrMap[37] = &chartInstance.c1_tp_vetvlenie;
  chartInstance.c1_testPointAddrMap[38] = &chartInstance.c1_tp_raspredelenie;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c1_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c1_testPointMappingInfo;
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c1_sfbp_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4024604724U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2097244867U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2849548453U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3103549820U);
}

mxArray *sf_c1_sfbp_get_autoinheritance_info(void)
{
  const char *autoinheritanceInfoStructFieldNames[] =
  {"checksum","inputTypes","inputComplexities","parameterTypes","parameterComplexities","outputSizes","outputTypes","outputComplexities"};
  mxArray *mxAutoinheritanceInfo = NULL;
  mxArray *mxChecksum = NULL;
  mxArray *mxInputTypes = NULL;
  mxArray *mxInputComplexities = NULL;
  mxArray *mxParameterTypes = NULL;
  mxArray *mxParameterComplexities = NULL;
  mxArray *mxOutputSizes = NULL;
  mxArray *mxOutputTypes = NULL;
  mxArray *mxOutputComplexities = NULL;

  mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,
   sizeof(autoinheritanceInfoStructFieldNames)/sizeof(char *),
   autoinheritanceInfoStructFieldNames);

  mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
  ((real_T *)mxGetPr((mxChecksum)))[0] = (real_T)(0U);
  ((real_T *)mxGetPr((mxChecksum)))[1] = (real_T)(0U);
  ((real_T *)mxGetPr((mxChecksum)))[2] = (real_T)(0U);
  ((real_T *)mxGetPr((mxChecksum)))[3] = (real_T)(0U);

  mxInputTypes = mxCreateDoubleMatrix(1,0,mxREAL);
  mxInputComplexities = mxCreateDoubleMatrix(1,0,mxREAL);

  mxParameterTypes = mxCreateDoubleMatrix(1,0,mxREAL);
  mxParameterComplexities = mxCreateDoubleMatrix(1,0,mxREAL);

  mxOutputSizes = mxCreateDoubleMatrix(2,13,mxREAL);
  mxOutputTypes = mxCreateDoubleMatrix(1,13,mxREAL);
  mxOutputComplexities = mxCreateDoubleMatrix(1,13,mxREAL);
  ((real_T *)mxGetPr((mxOutputSizes)))[0] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[1] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[0] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[0] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[2] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[3] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[1] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[1] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[4] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[5] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[2] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[2] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[6] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[7] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[3] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[3] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[8] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[9] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[4] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[4] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[10] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[11] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[5] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[5] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[12] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[13] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[6] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[6] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[14] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[15] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[7] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[7] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[16] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[17] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[8] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[8] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[18] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[19] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[9] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[9] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[20] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[21] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[10] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[10] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[22] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[23] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[11] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[11] = (real_T)(0U);
  ((real_T *)mxGetPr((mxOutputSizes)))[24] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputSizes)))[25] = (real_T)(1U);
  ((real_T *)mxGetPr((mxOutputTypes)))[12] = (real_T)(10U);
  ((real_T *)mxGetPr((mxOutputComplexities)))[12] = (real_T)(0U);

  mxSetFieldByNumber(mxAutoinheritanceInfo,0,0,mxChecksum);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,1,mxInputTypes);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,2,mxInputComplexities);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,3,mxParameterTypes);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,4,mxParameterComplexities);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,5,mxOutputSizes);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,6,mxOutputTypes);
  mxSetFieldByNumber(mxAutoinheritanceInfo,0,7,mxOutputComplexities);

  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S)
{
  if(ssIsFirstInitCond(S)) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_sfbpMachineNumber_,
         1,
         25,
         62,
         27,
         1,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting(_sfbpMachineNumber_,chartInstance.chartNumber,0);
          sf_debug_set_chart_event_thresholds(_sfbpMachineNumber_,
           chartInstance.chartNumber,
           1,
           1,
           1);

          _SFD_SET_DATA_PROPS(10,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"Tmew",0);
          _SFD_SET_DATA_PROPS(8,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"bocher",0);
          _SFD_SET_DATA_PROPS(25,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"kolzajv",0);
          _SFD_SET_DATA_PROPS(2,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"prihod",0);
          _SFD_SET_DATA_PROPS(15,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"Tobs",0);
          _SFD_SET_DATA_PROPS(20,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"Tobs1",0);
          _SFD_SET_DATA_PROPS(1,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"Tobs2",0);
          _SFD_SET_DATA_PROPS(22,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"Tobs3",0);
          _SFD_SET_DATA_PROPS(9,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"osv_kan0",0);
          _SFD_SET_DATA_PROPS(16,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"ver_per",0);
          _SFD_SET_DATA_PROPS(14,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"total_time",0);
          _SFD_SET_DATA_PROPS(24,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"n3",0);
          _SFD_SET_DATA_PROPS(21,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"n2",0);
          _SFD_SET_DATA_PROPS(13,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"n1",0);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"kol_otkaz",0);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"kol_z1",0);
          _SFD_SET_DATA_PROPS(23,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"kol_z2",0);
          _SFD_SET_DATA_PROPS(11,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"kol_z3",0);
          _SFD_SET_DATA_PROPS(4,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"raspr",0);
          _SFD_SET_DATA_PROPS(18,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"Tobs1sum",0);
          _SFD_SET_DATA_PROPS(6,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"Tobs2sum",0);
          _SFD_SET_DATA_PROPS(19,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"Tobs3sum",0);
          _SFD_SET_DATA_PROPS(26,0,0,0,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"Tobssum",0);
          _SFD_SET_DATA_PROPS(17,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"svzsevm1",0);
          _SFD_SET_DATA_PROPS(12,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"svzsevm2",0);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"svzsevm3",0);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0.0,1.0,0,"svzskan",0);
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(21,1,0);
          _SFD_STATE_INFO(19,0,1);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(12,0,1);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(16,0,1);
          _SFD_STATE_INFO(20,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(14,0,1);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(24,0,0);
          _SFD_STATE_INFO(15,0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(6,0,1);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(7,0,1);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(1,0,1);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(13,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,21);
          _SFD_ST_SUBSTATE_COUNT(21,9);
          _SFD_ST_SUBSTATE_INDEX(21,0,16);
          _SFD_ST_SUBSTATE_INDEX(21,1,19);
          _SFD_ST_SUBSTATE_INDEX(21,2,6);
          _SFD_ST_SUBSTATE_INDEX(21,3,12);
          _SFD_ST_SUBSTATE_INDEX(21,4,3);
          _SFD_ST_SUBSTATE_INDEX(21,5,14);
          _SFD_ST_SUBSTATE_INDEX(21,6,1);
          _SFD_ST_SUBSTATE_INDEX(21,7,7);
          _SFD_ST_SUBSTATE_INDEX(21,8,15);
          _SFD_ST_SUBSTATE_COUNT(16,2);
          _SFD_ST_SUBSTATE_INDEX(16,0,20);
          _SFD_ST_SUBSTATE_INDEX(16,1,10);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(19,3);
          _SFD_ST_SUBSTATE_INDEX(19,0,17);
          _SFD_ST_SUBSTATE_INDEX(19,1,11);
          _SFD_ST_SUBSTATE_INDEX(19,2,8);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(6,2);
          _SFD_ST_SUBSTATE_INDEX(6,0,2);
          _SFD_ST_SUBSTATE_INDEX(6,1,4);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(12,1);
          _SFD_ST_SUBSTATE_INDEX(12,0,5);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(3,1);
          _SFD_ST_SUBSTATE_INDEX(3,0,13);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,2);
          _SFD_ST_SUBSTATE_INDEX(14,0,18);
          _SFD_ST_SUBSTATE_INDEX(14,1,24);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(24,0);
          _SFD_ST_SUBSTATE_COUNT(1,1);
          _SFD_ST_SUBSTATE_INDEX(1,0,22);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(7,1);
          _SFD_ST_SUBSTATE_INDEX(7,0,9);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(15,2);
          _SFD_ST_SUBSTATE_INDEX(15,0,0);
          _SFD_ST_SUBSTATE_INDEX(15,1,23);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(23,0);
        }
        _SFD_CV_INIT_CHART(1,0,0,0);
        {
          _SFD_CV_INIT_STATE(21,9,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(19,3,1,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(12,1,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(16,2,1,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(14,2,1,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(24,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(15,2,1,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(6,2,1,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(7,1,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(1,1,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(3,1,0,0,0,0,NULL,NULL);
        }
        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {7};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {13};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {10};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(35,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {9};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {7};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(32,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {2,15};
          static unsigned int sEndGuardMap[] = {11,23};
          static int sPostFixPredicateTree[] = {0,1,-3};
          _SFD_CV_INIT_TRANS(44,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {12};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {2,11};
          static unsigned int sEndGuardMap[] = {7,17};
          static int sPostFixPredicateTree[] = {0,1,-3};
          _SFD_CV_INIT_TRANS(9,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {2,11};
          static unsigned int sEndGuardMap[] = {7,17};
          static int sPostFixPredicateTree[] = {0,1,-3};
          _SFD_CV_INIT_TRANS(12,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {2,12};
          static unsigned int sEndGuardMap[] = {8,17};
          static int sPostFixPredicateTree[] = {0,1,-3};
          _SFD_CV_INIT_TRANS(15,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {2,15};
          static unsigned int sEndGuardMap[] = {11,25};
          static int sPostFixPredicateTree[] = {0,1,-3};
          _SFD_CV_INIT_TRANS(59,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {2,12};
          static unsigned int sEndGuardMap[] = {8,18};
          static int sPostFixPredicateTree[] = {0,1,-3};
          _SFD_CV_INIT_TRANS(39,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {2,12,22};
          static unsigned int sEndGuardMap[] = {8,18,28};
          static int sPostFixPredicateTree[] = {0,1,-3,2,-3};
          _SFD_CV_INIT_TRANS(46,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(51,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {5};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(42,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {12};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(60,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {8};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(20,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {13};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(57,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(53,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(54,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {5};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(45,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {12};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(55,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {13};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(21,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {8};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(41,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {5};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(47,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {12};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(56,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {13};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(19,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {8};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(34,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(61,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(58,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {35};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(48,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {36};
          static int sPostFixPredicateTree[] = {0};
          _SFD_CV_INIT_TRANS(50,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = {2,14};
          static unsigned int sEndGuardMap[] = {10,24};
          static int sPostFixPredicateTree[] = {0,1,-3};
          _SFD_CV_INIT_TRANS(31,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,&(sPostFixPredicateTree[0]));
        }
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);

        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);

        _SFD_TRANS_COV_WTS(18,0,0,0,2);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(18,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           2,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(33,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(33,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(43,0,0,0,3);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(43,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           3,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(6,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {7};
          _SFD_TRANS_COV_MAPS(6,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(40,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(40,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(1,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {13};
          _SFD_TRANS_COV_MAPS(1,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(4,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(4,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(35,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {10};
          _SFD_TRANS_COV_MAPS(35,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(3,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {9};
          _SFD_TRANS_COV_MAPS(3,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(16,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(16,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(10,0,0,0,2);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(10,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           2,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(32,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {7};
          _SFD_TRANS_COV_MAPS(32,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(11,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(11,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(38,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(38,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(44,0,2,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {2,15};
          static unsigned int sEndGuardMap[] = {11,23};
          _SFD_TRANS_COV_MAPS(44,
           0,NULL,NULL,
           2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(7,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {12};
          _SFD_TRANS_COV_MAPS(7,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(9,0,2,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {2,11};
          static unsigned int sEndGuardMap[] = {7,17};
          _SFD_TRANS_COV_MAPS(9,
           0,NULL,NULL,
           2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(12,0,2,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {2,11};
          static unsigned int sEndGuardMap[] = {7,17};
          _SFD_TRANS_COV_MAPS(12,
           0,NULL,NULL,
           2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(15,0,2,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {2,12};
          static unsigned int sEndGuardMap[] = {8,17};
          _SFD_TRANS_COV_MAPS(15,
           0,NULL,NULL,
           2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(59,0,2,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {2,15};
          static unsigned int sEndGuardMap[] = {11,25};
          _SFD_TRANS_COV_MAPS(59,
           0,NULL,NULL,
           2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(39,0,2,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {2,12};
          static unsigned int sEndGuardMap[] = {8,18};
          _SFD_TRANS_COV_MAPS(39,
           0,NULL,NULL,
           2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(26,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(26,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(46,0,3,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {2,12,22};
          static unsigned int sEndGuardMap[] = {8,18,28};
          _SFD_TRANS_COV_MAPS(46,
           0,NULL,NULL,
           3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(51,0,0,0,5);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(51,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           5,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(37,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(37,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(23,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(23,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(13,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(13,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(30,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(30,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(17,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(17,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(42,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {5};
          _SFD_TRANS_COV_MAPS(42,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(2,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {12};
          _SFD_TRANS_COV_MAPS(2,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(60,0,0,0,3);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(60,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           3,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(20,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {8};
          _SFD_TRANS_COV_MAPS(20,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(57,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {13};
          _SFD_TRANS_COV_MAPS(57,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(27,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(27,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(22,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(22,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(53,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(53,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(54,0,0,0,3);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(54,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           3,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(45,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {5};
          _SFD_TRANS_COV_MAPS(45,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(49,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(49,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(55,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {12};
          _SFD_TRANS_COV_MAPS(55,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(21,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {13};
          _SFD_TRANS_COV_MAPS(21,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(41,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {8};
          _SFD_TRANS_COV_MAPS(41,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(5,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(5,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(47,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {5};
          _SFD_TRANS_COV_MAPS(47,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(14,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(14,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(56,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {12};
          _SFD_TRANS_COV_MAPS(56,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(19,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {13};
          _SFD_TRANS_COV_MAPS(19,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(34,0,1,0,1);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {8};
          _SFD_TRANS_COV_MAPS(34,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(29,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(29,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(61,0,0,0,3);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(61,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           3,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(24,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(24,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(58,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(58,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(48,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {35};
          _SFD_TRANS_COV_MAPS(48,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(0,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(50,0,1,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {1};
          static unsigned int sEndGuardMap[] = {36};
          _SFD_TRANS_COV_MAPS(50,
           0,NULL,NULL,
           1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(36,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(36,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(31,0,2,0,0);
        if(chartAlreadyPresent==0)
        {
          static unsigned int sStartGuardMap[] = {2,14};
          static unsigned int sEndGuardMap[] = {10,24};
          _SFD_TRANS_COV_MAPS(31,
           0,NULL,NULL,
           2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(25,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(25,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(52,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(52,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(8,0,0,0,1);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(8,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL);
        }
        _SFD_TRANS_COV_WTS(28,0,0,0,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(28,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL,
           0,NULL,NULL);
        }
        _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance.c1_Tmew);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance.c1_bocher);
        _SFD_SET_DATA_VALUE_PTR(25U, &chartInstance.c1_kolzajv);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance.c1_prihod);
        _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance.c1_Tobs);
        _SFD_SET_DATA_VALUE_PTR(20U, &chartInstance.c1_Tobs1);
        _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance.c1_Tobs2);
        _SFD_SET_DATA_VALUE_PTR(22U, &chartInstance.c1_Tobs3);
        _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance.c1_osv_kan0);
        _SFD_SET_DATA_VALUE_PTR(16U, c1_ver_per());
        _SFD_SET_DATA_VALUE_PTR(14U, c1_total_time());
        _SFD_SET_DATA_VALUE_PTR(24U, c1_n3());
        _SFD_SET_DATA_VALUE_PTR(21U, c1_n2());
        _SFD_SET_DATA_VALUE_PTR(13U, c1_n1());
        _SFD_SET_DATA_VALUE_PTR(5U, c1_kol_otkaz());
        _SFD_SET_DATA_VALUE_PTR(0U, c1_kol_z1());
        _SFD_SET_DATA_VALUE_PTR(23U, c1_kol_z2());
        _SFD_SET_DATA_VALUE_PTR(11U, c1_kol_z3());
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance.c1_raspr);
        _SFD_SET_DATA_VALUE_PTR(18U, &chartInstance.c1_Tobs1sum);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance.c1_Tobs2sum);
        _SFD_SET_DATA_VALUE_PTR(19U, &chartInstance.c1_Tobs3sum);
        _SFD_SET_DATA_VALUE_PTR(26U, &chartInstance.c1_Tobssum);
        _SFD_SET_DATA_VALUE_PTR(17U, c1_svzsevm1());
        _SFD_SET_DATA_VALUE_PTR(12U, c1_svzsevm2());
        _SFD_SET_DATA_VALUE_PTR(3U, c1_svzsevm3());
        _SFD_SET_DATA_VALUE_PTR(7U, c1_svzskan());
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_sfbpMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c1_sfbp(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S);
  initialize_c1_sfbp();
  initialize_params_c1_sfbp();
}

static void sf_opaque_enable_c1_sfbp(void *chartInstanceVar)
{
  enable_c1_sfbp();
}

static void sf_opaque_disable_c1_sfbp(void *chartInstanceVar)
{
  disable_c1_sfbp();
}

static void sf_opaque_gateway_c1_sfbp(void *chartInstanceVar)
{
  sf_c1_sfbp();
}

static void sf_opaque_terminate_c1_sfbp(void *chartInstanceVar)
{
  finalize_c1_sfbp();
}

static void mdlProcessParameters_c1_sfbp(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    ssUpdateDlgParamAsRunTimeParam(S, i);
  }
  initialize_params_c1_sfbp();
}

static void mdlSetWorkWidths_c1_sfbp(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("sfbp",1);
    int_T chartIsMultiInstanced =
      (int_T)sf_is_chart_multi_instanced("sfbp",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    if(chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,"sfbp",1,13);
    }
    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
    if (!sf_is_chart_instance_optimized_out("sfbp",1)) {
      int dtId;
      char *chartInstanceTypedefName =
        sf_chart_instance_typedef_name("sfbp",1);
      dtId = ssRegisterDataType(S, chartInstanceTypedefName);
      if (dtId == INVALID_DTYPE_ID ) return;
      /* Register the size of the udt */
      if (!ssSetDataTypeSize(S, dtId, 8)) return;
      if(!ssSetNumDWork(S,1)) return;
      ssSetDWorkDataType(S, 0, dtId);
      ssSetDWorkWidth(S, 0, 1);
      ssSetDWorkName(S, 0, "ChartInstance"); /*optional name, less than 16 chars*/
      sf_set_rtw_identifier(S);
    }
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(4024604724U));
  ssSetChecksum1(S,(2097244867U));
  ssSetChecksum2(S,(2849548453U));
  ssSetChecksum3(S,(3103549820U));

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_sfbp(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "sfbp", 1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_sfbp(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c1_sfbp;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c1_sfbp;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c1_sfbp;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c1_sfbp;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c1_sfbp;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_sfbp;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_sfbp;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_sfbp;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */

  if(!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
  }
}

void c1_sfbp_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_sfbp(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_sfbp(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_sfbp(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c1_sfbp_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  {"real_T", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0},
  {"uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0}
};

static real_T fixPtSlopeBiasVals[2] = {
  0,
  1
};

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  {NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0}
};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  {rtwCAPI_SCALAR, 0, 2}
};

static const uint_T dimensionArray[] = {
  1, 1
};

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, contextTid, mode */
  {&sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0, 0}
};

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  {0, 0,"StateflowChart/Tmew", "Tmew", 0, 0, 0, 0, 0},
  {1, 0,"StateflowChart/bocher", "bocher", 0, 0, 0, 0, 0},
  {2, 0,"StateflowChart/kolzajv", "kolzajv", 0, 0, 0, 0, 0},
  {3, 0,"StateflowChart/prihod", "prihod", 0, 0, 0, 0, 0},
  {4, 0,"StateflowChart/Tobs", "Tobs", 0, 0, 0, 0, 0},
  {5, 0,"StateflowChart/Tobs1", "Tobs1", 0, 0, 0, 0, 0},
  {6, 0,"StateflowChart/Tobs2", "Tobs2", 0, 0, 0, 0, 0},
  {7, 0,"StateflowChart/Tobs3", "Tobs3", 0, 0, 0, 0, 0},
  {8, 0,"StateflowChart/osv_kan0", "osv_kan0", 0, 0, 0, 0, 0},
  {9, 0,"StateflowChart/raspr", "raspr", 0, 0, 0, 0, 0},
  {10, 0,"StateflowChart/Tobs1sum", "Tobs1sum", 0, 0, 0, 0, 0},
  {11, 0,"StateflowChart/Tobs2sum", "Tobs2sum", 0, 0, 0, 0, 0},
  {12, 0,"StateflowChart/Tobs3sum", "Tobs3sum", 0, 0, 0, 0, 0},
  {13, 0,"StateflowChart/Tobssum", "Tobssum", 0, 0, 0, 0, 0},
  {14, 0, "StateflowChart/SMO", "SMO", 0, 1, 0, 0, 0},
  {15, 0, "StateflowChart/SMO.Istochnik", "Istochnik", 0, 1, 0, 0, 0},
  {16, 0, "StateflowChart/SMO.Istochnik.stopinng", "stopinng", 0, 1, 0, 0, 0},
  {17, 0, "StateflowChart/SMO.Istochnik.vihod", "vihod", 0, 1, 0, 0, 0},
  {18, 0, "StateflowChart/SMO.Istochnik.zaderwka", "zaderwka", 0, 1, 0, 0, 0},
  {19, 0, "StateflowChart/SMO.besknakop", "besknakop", 0, 1, 0, 0, 0},
  {20, 0, "StateflowChart/SMO.besknakop.beskonechnakopitel",
    "beskonechnakopitel", 0, 1, 0, 0, 0},
  {21, 0, "StateflowChart/SMO.evm_1", "evm_1", 0, 1, 0, 0, 0},
  {22, 0, "StateflowChart/SMO.evm_1.obsluwivanie1", "obsluwivanie1", 0, 1, 0, 0,
    0},
  {23, 0, "StateflowChart/SMO.evm_1.vhod1", "vhod1", 0, 1, 0, 0, 0},
  {24, 0, "StateflowChart/SMO.evm_2", "evm_2", 0, 1, 0, 0, 0},
  {25, 0, "StateflowChart/SMO.evm_2.obsluwivanie2", "obsluwivanie2", 0, 1, 0, 0,
    0},
  {26, 0, "StateflowChart/SMO.evm_2.vhod2", "vhod2", 0, 1, 0, 0, 0},
  {27, 0, "StateflowChart/SMO.evm_3", "evm_3", 0, 1, 0, 0, 0},
  {28, 0, "StateflowChart/SMO.evm_3.obsluwivanie3", "obsluwivanie3", 0, 1, 0, 0,
    0},
  {29, 0, "StateflowChart/SMO.evm_3.vhod3", "vhod3", 0, 1, 0, 0, 0},
  {30, 0, "StateflowChart/SMO.predvaritobrabotka", "predvaritobrabotka", 0, 1,
    0, 0, 0},
  {31, 0, "StateflowChart/SMO.predvaritobrabotka.obrabotka", "obrabotka", 0, 1,
    0, 0, 0},
  {32, 0, "StateflowChart/SMO.predvaritobrabotka.vhod", "vhod", 0, 1, 0, 0, 0},
  {33, 0, "StateflowChart/SMO.statistica1", "statistica1", 0, 1, 0, 0, 0},
  {34, 0, "StateflowChart/SMO.statistica1.stat1", "stat1", 0, 1, 0, 0, 0},
  {35, 0, "StateflowChart/SMO.statistica2", "statistica2", 0, 1, 0, 0, 0},
  {36, 0, "StateflowChart/SMO.statistica2.stat2", "stat2", 0, 1, 0, 0, 0},
  {37, 0, "StateflowChart/SMO.vetvlenie", "vetvlenie", 0, 1, 0, 0, 0},
  {38, 0, "StateflowChart/SMO.vetvlenie.raspredelenie", "raspredelenie", 0, 1,
    0, 0, 0}
};

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                   /* Block signals Array  */
    39                                  /* Num Block IO signals */
  },

  /* parameter tuning */
  {
    NULL,                               /* Block parameters Array    */
    0,                                  /* Num block parameters      */
    NULL,                               /* Variable parameters Array */
    0                                   /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                               /* Block States array        */
    0                                   /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                        /* Data Type Map            */
    dimensionMap,                       /* Data Dimension Map       */
    fixedPointMap,                      /* Fixed Point Map          */
    NULL,                               /* Structure Element map    */
    sampleTimeMap,                      /* Sample Times Map         */
    dimensionArray                      /* Dimension Array          */
  },

  /* Target type */
  "float"
};

static void init_test_point_mapping_info(SimStruct *S) {
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;

  init_test_point_addr_map();
  testPointMappingInfo = get_test_point_mapping_info();
  testPointAddrMap = get_test_point_address_map();

  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);

  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}

