#ifndef __sfbp_sfun_h__
#define __sfbp_sfun_h__

/* Include files */
#define S_FUNCTION_NAME                 sf_sfun
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "template_support_fcn_list.h"
#include "sfcdebug.h"

#define rtInf                           (mxGetInf())
#define rtMinusInf                      (-(mxGetInf()))
#define rtNaN                           (mxGetNaN())
#define rtIsNaN(X) ((int)mxIsNaN(X))
#define rtIsInf(X) ((int)mxIsInf(X))

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                      (MAX_uint8_T)

/* Variable Declarations */
extern uint8_T _sfEvent_;
extern uint32_T _sfbpMachineNumber_;
extern real_T _sfTime_;

/* Variable Definitions */

/* Function Declarations */
void sfbp_initializer(void);
void sfbp_terminator(void);

/* Function Definitions */

#endif

