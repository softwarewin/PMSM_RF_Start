#ifndef RL_BRAIN_H
#define RL_BRAIN_H


class RL_Brain
{
    public:
        // construction and deconstruction function
        RL_Brain(float epsilon_ini, float L_R_ini, float gamma_ini,int StatesNum,int ActionsNum);
        virtual ~RL_Brain();
        // learning process of the algorithm
        void RL_learn(int s,int a,float r,int s_,int terminal);
        // Choose an action
        int Choose_Action(int StateSeq);
        float Get_QtableValue(int x, int y);
        void Set_QtableValue(int x, int y, float QValue);
        float Get_ActionValueMax(int StateSeq);
        // hyper-parameters in the algorithm
        float epsilon;         // exploration rate
        float L_R;             // learning rate
        float gamma;           // reward decay
        float *Qtable;         // pointer to Qtable
        // Qtabel dimenstion
        int StatesNum;
        int ActionsNum;
        // processing value
        float Qpredict;
        float Qtarget;

    protected:

    private:
};

#endif // RL_BRAIN_H
