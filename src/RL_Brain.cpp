#include "RL_Brain.h"
#include<iostream>
#include <algorithm>
using namespace std;
RL_Brain::RL_Brain(float epsilon_ini, float L_R_ini, float gamma_ini,int StatesNum_ini,int ActionsNum_ini)//,float *Qtable_ini
{
    int i;
    //ctor
    RL_Brain::epsilon = epsilon_ini;
    RL_Brain::L_R = L_R_ini;
    RL_Brain::gamma = gamma_ini;
    // construct an Qtable and initial it
    RL_Brain::Qtable = new float[StatesNum_ini*ActionsNum_ini];
    for(i=0;i<StatesNum_ini*ActionsNum_ini;i++)
        RL_Brain::Qtable[i] = -10.0;
    RL_Brain::StatesNum = StatesNum_ini;
    RL_Brain::ActionsNum = ActionsNum_ini;
}
RL_Brain::~RL_Brain()
{
    delete RL_Brain::Qtable;
    cout<<"RL_Brain deleted"<<endl;//dtor
}
// Update Qtable
void RL_Brain::Set_QtableValue(int x, int y, float QValue)
{
    *((RL_Brain::Qtable)+x*(RL_Brain::ActionsNum)+y) = QValue;
}
// learning
void RL_Brain::RL_learn(int s,int a,float r,int s_,int terminal)
{
    float QValue = 0;
    RL_Brain::Qpredict = RL_Brain::Get_QtableValue(s, a); //Q(s,a)
    if(terminal == 1)
        RL_Brain::Qtarget = r + RL_Brain::gamma * RL_Brain::Get_ActionValueMax(s_); //max Q(s',a)
    else
        RL_Brain::Qtarget = r;
    QValue = RL_Brain::Qpredict + RL_Brain::L_R*(RL_Brain::Qtarget - RL_Brain::Qpredict);
    RL_Brain::Set_QtableValue(s, a, QValue);
}
// choose action
int RL_Brain::Choose_Action(int StateSeq)
{
    int i;
    int MaxNum = 0;
    float ValueMax = 0;
    float TempQValue;
    // get action with maximum Q value
    for(i=0;i<RL_Brain::ActionsNum;i++)
    {
        TempQValue = RL_Brain::Get_QtableValue(StateSeq, i);
        if(ValueMax<TempQValue)
        {
           ValueMax = TempQValue;
           MaxNum = i;
        }
    }
    return(MaxNum);
}
// get Q table value
float RL_Brain::Get_QtableValue(int x, int y)
{
    return(*((RL_Brain::Qtable)+x*(RL_Brain::ActionsNum)+y));
}

float RL_Brain::Get_ActionValueMax(int StateSeq)
{
    int i;
    float ValueMax = 0;
    float TempQValue;
    for(i=0;i<RL_Brain::ActionsNum;i++)
    {
        TempQValue = RL_Brain::Get_QtableValue(StateSeq, i);
        if(ValueMax<TempQValue)
            ValueMax = TempQValue;
    }
    return(ValueMax);
}
