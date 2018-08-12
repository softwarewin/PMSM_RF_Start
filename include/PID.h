#ifndef PID_H
#define PID_H


class PID
{
    public:
        PID(float Kp_ini,float Ki_ini,float Kd_ini,float T_ini);
        virtual ~PID();
        void PIDCal(float Error);
        // PID parameters
        float Kp;
        float Ki;
        float Kd;
        float T;
        float IntPart;
        float Uout;
    protected:

    private:
};

#endif // PID_H
