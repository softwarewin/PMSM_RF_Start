#include "../include/MPC.h"
#include "../include/CtrIncludes.h"
MPC::MPC(int PredictLength_ini,int ControlLength_ini,int Xnum_ini,int Unum_ini,int Udnum_ini,int Ynum_ini)
{
    int i,j;
    //ctor
    PredictLength = PredictLength_ini;
    Xnum = Xnum_ini;
    Ynum = Ynum_ini;
    Unum =  Unum_ini;
    Udnum = Udnum_ini;
    XPredSeq = MatrixXf::Zero(PredictLength_ini*Xnum,1);
    Useq = MatrixXf::Zero(ControlLength_ini*Xnum,1);
    // State Matrix
    A = MatrixXf::Zero(Xnum,Xnum);
    Bu = MatrixXf::Zero(Xnum,Unum);
    Bd = MatrixXf::Zero(Xnum,Udnum);
    Cc = MatrixXf::Zero(Ynum,Xnum);

    Yp = MatrixXf::Zero(Ynum*PredictLength,1);
    DeltaX = MatrixXf::Zero(Xnum,1);
    //==========Prediction Matrix=====================
    // Initial Sx Matrix
    TempMatrix = MatrixXf::Zero(Ynum,Xnum);
    Sx = MatrixXf::Zero(Ynum*PredictLength,Xnum);
    for(i=0;i<PredictLength;i++)
    {
        TempMatrix = Cc*A;
        Sx.block(0, 0, (i+1)*Ynum-1, Xnum-1) = TempMatrix;
        for(j=1;j<=i;j++)
        {
           TempMatrix = TempMatrix*A;
           Sx.block(i*Ynum, 0, (i+1)*Ynum-1, Xnum-1) = Sx.block(i*Ynum, 0, (i+1)*Ynum-1, Xnum-1) + TempMatrix;
        }
    }
    // Initial I Matrix
    Ix = MatrixXf::Zero(Ynum*PredictLength,Xnum);
    for(i=0;i<PredictLength;i++)
    {
      Ix.block(i*Ynum, 0, (i+1)*Ynum-1, Ynum-1)= MatrixXf::Identity(Ynum,Ynum);
    }
    // Initial Sd Matrix
    TempMatrix = MatrixXf::Zero(Ynum,Udnum);
    Sd = MatrixXf::Zero(Ynum*PredictLength,Udnum);
    for(i=0;i<PredictLength;i++)
    {
        TempMatrix = Cc*Bd;
        Sd.block(0, 0, (i+1)*Ynum-1, Udnum-1) = TempMatrix;
        for(j=1;j<=i;j++)
        {
           TempMatrix = TempMatrix*A;
           Sd.block(i*Ynum, 0, (i+1)*Ynum-1, Udnum-1) = Sd.block(i*Ynum, 0, (i+1)*Ynum-1, Udnum-1) + TempMatrix;
        }
    }
    // Initial Su Matrix
}
// discrete statefunction prediction
void MPC::MPC_Prediction_DiscreteStates()
{
    int i=0;
    //Ynum = 1;
    TempMatrix = MatrixXf::Zero(Ynum,Xnum);
    for(i=0;i<PredictLength;i++)
    {
        Yp.block(i*Ynum, 0, (i+1)*Ynum-1, 0)=Sx.block(i*Ynum, 0, (i+1)*Ynum-1, 0)*DeltaX(0, Xnum-1)
        +Ix.block(i*Ynum, 0, (i+1)*Ynum-1, Ynum-1)*Yc(0, Ynum-1)
        +Sd.block(i*Ynum, 0, (i+1)*Ynum-1, Udnum-1)*DeltaD(0, Udnum-1)
        +Su*DeltaU(0, Unum-1);
    }

}
MPC::~MPC()
{
    //dtor
}
