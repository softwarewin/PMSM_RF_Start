struct RL_Brain
{
    float Q_Chart[10][10][10][5]; // 5 types of controller component
                                  // 3 states,each state is divided into 10 category
                                  // 5000*4 = 20kbyte
                                  // e, e', Vq, Iq, w 能检测的各状态变量和输入
                                  // v i w -> load 表和神经网络以及模型配合实现稀疏性 避免被刷新
};
