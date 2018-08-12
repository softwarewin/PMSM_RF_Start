

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
#include "include/PID.h"
#include "include/CtrIncludes.h"
#include "include/L1Adaptive.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
L1Adaptive L1Test(1,1,1,1,1,2000,1000,0.0001,10,'I');
//A_ini,B_ini,C_ini,P_ini,Kg_ini,float Wc_ini,float Tao_ini,float T_ini,
//float Km_ini.char Type_ini
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void L1AdaptiveTest_Outputs_wrapper(const real_T *u0,
			const real_T *u1,
			const real_T *u2,
			real_T *Iref,
			real_T *Xest,
			real_T *Uad,
			real_T *Um,
			real_T *RefErr,
			real_T *ThetaEst,
			real_T *StateErr,
			real_T *X,
			real_T *Uref,
			real_T *AdaItem,
			real_T *West,
			real_T *SigmaEst,
			const real_T *xD,
			const real_T  *Rx, const int_T  p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
//This sample sets the output equal to the input
      //Iref[0] = PID.Kp; 
      L1Test.Ref<<u0[0];//
      L1Test.X<<u1[0];//
      L1Test.GetEstParas();
      L1Test.LowPassUad();
      L1Test.GetU();
      L1Test.RefModelStates();
      Iref[0] = L1Test.U.value();
      Xest[0] = L1Test.Xest.value();
      Uad[0] = L1Test.Uad.value();
      Um[0] = L1Test.Um.value();
      RefErr[0] = L1Test.RefErr.value();
      ThetaEst[0] = L1Test.ThetaEst.value();
      StateErr[0] = L1Test.StateErr.value();
      X[0] = L1Test.X.value();
      Uref[0] = L1Test.A.value();
      West[0] = L1Test.WEst.value();
      SigmaEst[0] = L1Test.SigmaEst.value();
      AdaItem[0] = L1Test.Am.value();
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void L1AdaptiveTest_Update_wrapper(const real_T *u0,
			const real_T *u1,
			const real_T *u2,
			const real_T *Iref,
			const real_T *Xest,
			const real_T *Uad,
			const real_T *Um,
			const real_T *RefErr,
			const real_T *ThetaEst,
			const real_T *StateErr,
			const real_T *X,
			const real_T *Uref,
			const real_T *AdaItem,
			const real_T *West,
			const real_T *SigmaEst,
			real_T *xD,
			const real_T  *Rx,  const int_T  p_width0)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
