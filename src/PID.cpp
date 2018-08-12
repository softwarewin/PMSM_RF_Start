#include "../include/PID.h"

PID::PID(float Kp_ini,float Ki_ini,float Kd_ini,float T_ini)
{
    //ctor
    Kp = Kp_ini;
    Ki = Ki_ini;
    Kd = Kd_ini;
    T = T_ini;
    IntPart = 0;
}

PID::~PID()
{
    //dtor
}

void PID::PIDCal(float Error)
{
    IntPart += Error*T;
    Uout = Kp*Error + Ki*IntPart;
}
