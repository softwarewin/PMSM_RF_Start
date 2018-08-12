#include "RL_Brain.h"
#include<iostream>
#include <conio.h>
#include <Eigen/Core>
#include "CtrIncludes.h"
using namespace std;
using namespace Eigen;
#define StatesNum 1000
#define ActionNum 5
float test1 = 1;

void QlearningTest(void)
{
    float error = 0;
    float errorInteg = 0;
    float errorDiff = 0;
    RL_Brain RL_QBrain(0.1,0.01,0.01,1000,3);
    //RL_learn;
    RL_QBrain.RL_learn(1,2,0.3,5,0);
    RL_QBrain.Choose_Action(3);
}
void L1AdaptiveTest(void)
{
   L1Adaptive L1Test(1,1,1,1,1,10000,0.001,0.0001,1,'I');//
   L1Test.Ref<<1000;
   L1Test.X<<100;
   L1Test.RefModelStates();
   L1Test.GetEstParas();
   L1Test.LowPassUad();
   L1Test.GetU();
   // C=A*B;
    std::cout << "A\n" <<L1Test.A << "\nB:\n"<<L1Test.B << "\nC:\n" <<L1Test.C << std::endl;
    std::cout << "StateErr\n" <<L1Test.StateErr << std::endl;
    std::cout << "U\n" <<L1Test.U << std::endl;
}
int main(void)
{
  //QlearningTest();
  L1AdaptiveTest();
  /* //18F11010
   int a0[8]={0xd0,0x47,0xe0,0x47,0xff,0x00,0x63,0x7d};

   //18F11110
   int b0[]={0xff,0x13,0x2f,0x79,0x7d,0x3e,0x61,0xff};
   //10F11210
   int c0[]={0x30,0xc0,0x82,0x00,0x8a,0xa0,0x88,0x00};

   int d0[]={0};
   //18F11310
   int e0[]={0x22,0x01,0x37,0x02,0x2c,0x74,0xfa,0x08};
   //18F11510
   int f0[]={0x9b,0x01,0x62,0x00,0xff,0xff,0x30,0x00};
   int g0[]={0};
   //18F11010
   std::cout << "转速:" <<(((a0[1]<<8)+a0[0])/8)<<"发动机冷却液温度: "<<(a0[7]-40)<<"进气温度: "<<(a0[6]-40)<<"\n"<< std::endl;
   //18F11110
   std::cout << "机油压力:" <<(b0[3]*4)<<"发电机温度: "<<(b0[4])<<"发电机控制器温度: "<<(b0[5])<<"\n"<< std::endl;
   //10F11210
   std::cout << "输出功率:" <<(c0[4]/2) <<"\n"<< std::endl;
   //18F11310
   std::cout << "发电机转矩:" <<((e0[1]<<8)+e0[0])<<"母线电压:" <<((e0[3]<<8)+e0[2])<<"母线电流:" <<(((e0[5]<<8)+e0[4])*0.05-1600)<<"发电机转速:" <<((e0[7]<<8)+e0[6])<<"\n"<< std::endl;
  //18F11510
   std::cout << "燃油消耗率:" <<(((f0[1]<<8)+f0[0])*0.05)<< "相对进气压力:"<< f0[6]*2<< "转矩补偿:"<< f0[7]<<"\n"<< std::endl;*/

    getch();
    return 0;
}
