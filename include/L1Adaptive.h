#ifndef L1ADAPTIVE_H
#define L1ADAPTIVE_H
#include "CtrIncludes.h"
#include "../Eigen/Core"
#include "../Eigen/LU"
using namespace std;
using namespace Eigen;

class L1Adaptive
{
    public:
        L1Adaptive(float A_ini,float B_ini,float C_ini,float P_ini,float Kg_ini,float Wc_ini,float Tao_ini,float T_ini,float Km, char Type_ini);//
        virtual ~L1Adaptive();
        //'I': Systems with Uncertain System Input Gain
        //'P':
        float T;
        float time;
        float Wc;
        float Tao;
        char AdaptiveType;
        //State matrix
        Matrix<float, 1, 1>  A; //A matrix
        Matrix<float, 1, 1>  B; //B matrix
        Matrix<float, 1, 1>  C; //C matrix

        Matrix<float, 1, 1>  X; //RealStates matrix
        Matrix<float, 1, 1>  Xest; //Estimate States matrix
        Matrix<float, 1, 1>  U; //Estimate States matrix
        Matrix<float, 1, 1>  Uad; //Estimate States matrix
        Matrix<float, 1, 1>  Um; //Estimate States matrix
        Matrix<float, 1, 1>  Km; //Estimate States matrix
        Matrix<float, 1, 1>  Kg; //Estimate States matrix
        Matrix<float, 1, 1>  Am; //Estimate States matrix
        Matrix<float, 1, 1>  Ref; //Estimate States matrix
        // estimate parameters
        Matrix<float, 1, 1>  ThetaEst;
        Matrix<float, 1, 1>  WEst; //A matrix
        Matrix<float, 1, 1>  SigmaEst; //A matrix

        Matrix<float, 1, 1>  RefErr;
        Matrix<float, 1, 1>  StateErr;
        // calculated projection value
        Matrix<float, 1, 1>  ProjItemW;
        Matrix<float, 1, 1>  ProjItemTheta;
        Matrix<float, 1, 1>  ProjItemSigma;

        Matrix<float, 1, 1>  Yest;
        Matrix<float, 1, 1>  P;
        Matrix<float, 1, 1>  Temp; //A matrix
        Matrix<float, 1, 1>  Uref; //A matrix
        // L1adaptive modules
        void RefModelStates();
        void GetEstParas();
        void LowPassUad();
        void GetU();
        // Motor Speed Control
    protected:

    private:
};

#endif // L1ADAPTIVE_H
