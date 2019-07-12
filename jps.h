#include <iostream>
#include<windows.h>
#include<vector>
#include<cmath>

using namespace std;

class Jps
{
public:

    //����ö��
    enum Direct{
        p_up,p_down,p_left,p_right,p_leftup,p_leftdown,p_rightup,p_rightdown
    };

    //������ͼ�ڵ�
    struct PathNode{
        int row;//��
        int col;
        int g,h,f;
        void GetF(){
            f = g + h;
        }
        int     value;//
        bool    isroute;//�Ƿ������·���е�һ��
        bool    isfind;//�Ƿ��߹�
        bool    isnull;//�Ƿ��ǿսڵ�
        vector<PathNode*> keyNeighbours; //�ؼ��ھӽڵ�
    };

    int height,width;

    PathNode** pathMap;//������ͼ
    PathNode startNode;
    PathNode endNode;

    PathNode nullNode;//�սڵ�

    PathNode* jumpPointTmp;


    vector<PathNode*> jumpPointTree;//�����������

    bool* Prune(short unitMap,char p,char n);
    void Init();
    PathNode JumpStraight(PathNode** _pathMap,PathNode currenNode,Direct dir);


};
