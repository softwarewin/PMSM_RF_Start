

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
float r = 0;
RL_Brain RL_QBrain(epsilon_ini,L_R_ini,gamma_ini,StatesNumAll, ActionsNum);
float ActionNum = 0;
float StateSeqAllPre = 0;

float StateSeqAll = 0;
float error = 0;
float errorInteg = 0;
float errorDiff = 0;
float error_pre = 0;

float errorMax = 1;
float errorIntegMax = 10;
float errorDiffMax = 100;

float errorMin = -1;
float errorIntegMin = -10;
float errorDiffMin = -100;

float errorCatNum = 10;
float errorIntegCatNum = 10;
float errorDiffCatNum = 10;

float errorState = 0;
float errorIntegState = 0;
float errorDiffState = 0;

float dt = 1e-4;
float Kp_ini = 1;
float Ki_ini = 1;
float Kd_ini = 1;
float T_ini = 1e-4;
PID PIDQlearning(Kp_ini,Ki_ini,Kd_ini,T_ini);
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void QlearningPID_Outputs_wrapper(const real_T *Ref,
			const real_T *Out,
			real_T *u0,
			real_T *ActionNumOut,
			real_T *StateSeqAllOut,
			real_T *errorStateOut,
			real_T *errorIntegStateOut,
			real_T *errorDiffStateOut,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// get states
error = Ref[0]-Out[0];
errorInteg = errorInteg + error*dt;
errorDiff = error - error_pre;
error_pre = error;
// calculate state num
errorState = RL_QBrain.StatesDiscretion(error,errorMin,errorMax,errorCatNum);
errorIntegState = RL_QBrain.StatesDiscretion(errorInteg,errorIntegMin,errorIntegMax,errorIntegCatNum);
errorDiffState = RL_QBrain.StatesDiscretion(errorDiff,errorDiffMin,errorDiffMax,errorDiffCatNum);
r = abs(errorDiff);//temp
StateSeqAll = errorDiffState*errorCatNum*errorIntegCatNum+errorIntegState*errorCatNum+errorState;
RL_QBrain.RL_learn(StateSeqAllPre,ActionNum,r,StateSeqAll,0);
StateSeqAllPre = StateSeqAll;
ActionNum = RL_QBrain.Choose_Action(StateSeqAll);
//u0 cat
if(ActionNum==0)
{
    PIDQlearning.Kp = 1;
    PIDQlearning.Ki = 1;
}
if(ActionNum==1)
{
    PIDQlearning.Kp = 5;
    PIDQlearning.Ki = 5;
}
if(ActionNum==2)
{
    PIDQlearning.Kp = 10;
    PIDQlearning.Ki = 10;
}
PIDQlearning.PIDCal(error);
u0[0]= PIDQlearning.Uout;
ActionNumOut[0] = ActionNum;
StateSeqAllOut[0] = StateSeqAll;
errorStateOut[0] = errorState;
errorIntegStateOut[0] = errorIntegState;
errorDiffStateOut[0] = errorDiffState;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void QlearningPID_Update_wrapper(const real_T *Ref,
			const real_T *Out,
			const real_T *u0,
			const real_T *ActionNumOut,
			const real_T *StateSeqAllOut,
			const real_T *errorStateOut,
			const real_T *errorIntegStateOut,
			const real_T *errorDiffStateOut,
			real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
*/
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
