#include "RL_Brain.h"
#include<iostream>
#include <conio.h>
using namespace std;
#define StatesNum 1000
#define ActionNum 5
int main(void)
{
    //float *ArrayP = new float[StatesNum][ActionNum];
    RL_Brain RL_Brain_1(1,2,3,StatesNum,ActionNum);//,ArrayP
    cout<<RL_Brain_1.gamma<<endl;
    cout<<RL_Brain_1.Get_QtableValue(2, 9)<<endl;
    //getch();
    //delete &RL_Brain_1;
    return 0;
}
