struct RL_Brain
{
    float Q_Chart[10][10][10][5]; // 5 types of controller component
                                  // 3 states,each state is divided into 10 category
                                  // 5000*4 = 20kbyte
                                  // e, e', Vq, Iq, w �ܼ��ĸ�״̬����������
                                  // v i w -> load ����������Լ�ģ�����ʵ��ϡ���� ���ⱻˢ��
};
