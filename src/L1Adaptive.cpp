#include "../include/L1Adaptive.h"
#include "../include/CtrIncludes.h"
L1Adaptive::L1Adaptive(float A_ini,float B_ini,float C_ini,float P_ini,float Kg_ini,float Wc_ini,float Tao_ini,float T_ini,float Km_ini,char Type_ini)//
{
    //ctor
    A << A_ini;
    B << B_ini;
    C << C_ini;
    Wc = Wc_ini;
    T = T_ini;
    X << 0; //RealStates matrix
    Xest << 0; //Estimate States matrix
    U << 0; //Estimate States matrix
    Uad<< 0; //Estimate States matrix
    Um << 0; //Estimate States matrix
    Km << Km_ini; //Estimate States matrix
    Am = (A-B*Km);
    Temp = C.transpose()*Am.inverse()*B;
    Kg << -1/Temp.value();//Kg_ini;
    Ref<< 0; //Estimate States matrix
    // estimation parameters
    ThetaEst<<1;
    WEst<<1;
    SigmaEst<<1;

    RefErr<<0;
    StateErr<<0;
    Yest<<0;
    P << P_ini;
    Tao = Tao_ini;
    time = 0;
    AdaptiveType = Type_ini;
    // Projection value init
    ProjItemW<<1;
    ProjItemTheta<<0;
    ProjItemSigma<<0;
   // std::cout << "A\n" <<A << "\nB:\n"<<B << "\nC:\n" <<C << std::endl;
}

L1Adaptive::~L1Adaptive()
{
    //dtor
}
void L1Adaptive::GetU()
{
   Um = -Km.transpose()*X*WEst.inverse();// Get Um
   U = Um + Uad;// get U
}
void L1Adaptive::LowPassUad() //Wc/(s+Wc)
{
   // Get Uad
   if(AdaptiveType == 'P')
   {
       RefErr = Kg*Ref-ThetaEst.transpose()*X;
       Uad = Uad +(Wc*RefErr - Wc*Uad)*T;
   }
   if(AdaptiveType == 'I')
   {
       RefErr = (Kg*Ref-ThetaEst.transpose()*X-SigmaEst)*WEst.inverse();
       Uad = Uad +(Wc*RefErr - Wc*Uad)*T;
   }
   //Uad = RefErr;
}
void L1Adaptive::GetEstParas()
{
   StateErr = Xest - X;
    // 满足约束条件
    if(AdaptiveType == 'P')
    {
        ProjItemTheta   = -StateErr.transpose()*P*B*X;
        ThetaEst = ThetaEst + Tao*ProjItemTheta *T;//*T
    }

    if(AdaptiveType == 'I')
    {
        ProjItemW  = -StateErr.transpose()*P*B*Uad;
        WEst = WEst + Tao*ProjItemW*T;
        if(WEst.value()<0.5)
            WEst<<0.5;
        else if(WEst.value()>5)
            WEst<<5;

        ProjItemTheta  = -StateErr.transpose()*P*B*X;
        ThetaEst = ThetaEst + Tao*ProjItemTheta*T;

        ProjItemSigma  = -StateErr.transpose()*P*B;
        SigmaEst = SigmaEst + Tao*ProjItemSigma*T;
    }
    // 不满足约束条件
}
void L1Adaptive::RefModelStates()
{
    if(AdaptiveType == 'P')
    {
        Xest = Xest + (Am*Xest + B*(ThetaEst.transpose()*X+Uad))*T;
        Yest = C.transpose()*Xest;
    }
    if(AdaptiveType == 'I')
    {
        Xest = Xest + (Am*Xest + B*(ThetaEst.transpose()*X+WEst*Uad+SigmaEst))*T;
        Yest = C.transpose()*Xest;
    }
}

