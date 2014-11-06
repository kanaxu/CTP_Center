
#include "DataCenter.h"

//mex���������
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
    DataCenter &DCenter = DataCenter::GetInstance();
    if(nrhs == 0)
        mexErrMsgTxt("��������");
    int choise = (int)mxGetScalar(prhs[0]);
    switch(choise)
    {
        //�������ݿ�
        case 1:
        {
            if(1 == nrhs)
                DCenter.connect();
            else if(2 == nrhs)
                DCenter.connect(mxArrayToString(prhs[1]));
            else if(3 == nrhs)
                DCenter.connect(mxArrayToString(prhs[1]), mxArrayToString(prhs[2]));
            break;
        }
        case 2:
        {
            DCenter.disconnect();
            break;
        }
        case 3:
        {
            plhs[0] = DCenter.GetTick(prhs[1], prhs[2], prhs[3]);
            break;
        }

        default:
            mexPrintf("δ�ҵ�����\n");
            break;
    }
}