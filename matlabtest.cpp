#include"mex.h"
//#include "matrix.h"
void mexFunction(int nlhs,mxArray*plhs[],int nrhs, const mxArray *prhs[])
{
    float i;
    float m = 0;
    float n = 0;
    i=mxGetScalar(prhs[1]);
    if(i==1)
    {
        mexPrintf("hello,world!\n");
        m = 100;
        n = 1000;
    }
    else
    {
       mexPrintf("´ó¼ÒºÃ!\n");
       m = 1;
       n = 2;
    }
    plhs[0] = mxCreateDoubleScalar(m);
    plhs[1] = mxCreateDoubleScalar(n);
    nlhs = 2;
}
// output to matlab
// out = cell(1,2)
// [out{:}] = matlabtest(200,100)
