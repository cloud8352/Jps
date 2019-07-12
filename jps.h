#include <iostream>
#include<windows.h>
#include<vector>
#include<cmath>

using namespace std;

class Jps
{
public:

    //方向枚举
    enum Direct{
        p_up,p_down,p_left,p_right,p_leftup,p_leftdown,p_rightup,p_rightdown
    };

    //辅助地图节点
    struct PathNode{
        int row;//行
        int col;
        int g,h,f;
        void GetF(){
            f = g + h;
        }
        int     value;//
        bool    isroute;//是否是最短路径中的一点
        bool    isfind;//是否走过
        bool    isnull;//是否是空节点
        vector<PathNode*> keyNeighbours; //关键邻居节点
    };

    int height,width;

    PathNode** pathMap;//辅助地图
    PathNode startNode;
    PathNode endNode;

    PathNode nullNode;//空节点

    PathNode* jumpPointTmp;


    vector<PathNode*> jumpPointTree;//存放所有跳点

    bool* Prune(short unitMap,char p,char n);
    void Init();
    PathNode JumpStraight(PathNode** _pathMap,PathNode currenNode,Direct dir);


};
