#ifndef MPC_H
#define MPC_H
#include "CtrIncludes.h"
#include "../Eigen/Core"
#include "../Eigen/LU"
using namespace std;
using namespace Eigen;
//discrete MPC
class MPC
{
    public:
        MPC(int PredictLength_ini,int ControlLength_ini,int XNum_ini,int Unum_ini,int Udnum_int,int Ynum_ini);
        virtual ~MPC();

        int PredictLength;
        int ControlLength;
        int Xnum;
        int Ynum;
        int Udnum;
        int Unum;

        MatrixXf TempMatrix;
        MatrixXf XPredSeq;
        MatrixXf Useq;
        // ÀëÉ¢×´Ì¬¿Õ¼äÄ£ÐÍ
        MatrixXf A;
        MatrixXf Bu;
        MatrixXf Bd;
        MatrixXf Cc;
        //Prediction Matrix
        MatrixXf Sx;
        MatrixXf Ix;
        MatrixXf Sd;
        MatrixXf Su;
        // Prediction Output
        MatrixXf Yp;
        // states
        MatrixXf DeltaX;
        MatrixXf DeltaD;
        MatrixXf DeltaU;
        MatrixXf Yc;


        void UpdateStates();
        void MPC_Prediction_DiscreteStates();
        void OptimalSoving();

    protected:

    private:
};

#endif // MPC_H
