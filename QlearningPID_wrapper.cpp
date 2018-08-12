

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "../include/PID.h"
#include "../include/CtrIncludes.h"
#include "../include/RL_Brain.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
// float epsilon_ini, float L_R_ini, float gamma_ini,int StatesNum_ini,int ActionsNum_ini
float StatesNumAll = 1000;
float ActionsNum = 3;
float epsilon_ini = 0.1;
float L_R_ini = 0.01;
float gamma_ini = 0.01;
RL_Brain RL_QBrain(epsilon_ini,L_R_ini,gamma_ini,StatesNumAll, ActionsNum);

float error = 0;
float errorInteg = 0;
float errorDiff = 0;

float errorMax = 1;
float errorIntegMax = 10;
float errorDiffMax = 100;

float errorMin = -1;
float errorIntegMin = -10;
float errorDiffMin = -100;

float ErrorCatNum = 10;
float ErrorIntegCatNum = 10;
float ErrorDiffCatNum = 10;

float ErrorState = 0;
float ErrorIntegState = 0;
float ErrorDiffState = 0;

float dt = 1e-4;
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void QlearningPID_Outputs_wrapper(const real_T *Ref,
			const real_T *Out,
			real_T *u0,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// get states
error = Ref[0]-Out[0];
errorInteg = errorInteg + errorInteg*dt;
errorDiff = 0;
// calculate state num
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void QlearningPID_Update_wrapper(const real_T *Ref,
			const real_T *Out,
			const real_T *u0,
			real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
*/
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
