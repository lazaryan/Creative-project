/* Include files */
#include "sfbp_sfun.h"
#include "c1_sfbp.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _sfbpMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void sfbp_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void sfbp_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_sfbp_method_dispatcher(SimStruct *simstructPtr, const char
 *chartName, int_T method, void *data)
{
  if(!strcmp_ignore_ws(chartName,"sfbp/Chart/ SFunction ")) {
    c1_sfbp_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_sfbp_process_check_sum_call( int nlhs, mxArray * plhs[], int
 nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"sf_get_check_sum")) return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if(nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if(!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3768593452U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1447921351U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(232119849U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1394916030U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1437538639U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2825455710U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3972602336U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2037064153U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 1:
        {
          extern void sf_c1_sfbp_get_check_sum(mxArray *plhs[]);
          sf_c1_sfbp_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    }else if(!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3856560790U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1027868561U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3786213508U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3589689415U);
    }else {
      return 0;
    }
  } else{
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2915000823U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2075403792U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1175490321U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2501488111U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_sfbp_autoinheritance_info( int nlhs, mxArray * plhs[], int nrhs,
 const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"get_autoinheritance_info")) return 0;
  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch(chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_sfbp_get_autoinheritance_info(void);
        plhs[0] = sf_c1_sfbp_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
void sfbp_debug_initialize(void)
{
  _sfbpMachineNumber_ = sf_debug_initialize_machine("sfbp","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_sfbpMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_sfbpMachineNumber_,0);
}

