#include <iostream>
#include<windows.h>
#include<vector>
#include<cmath>

using namespace std;
using std::vector;

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
        bool    inopen;
        bool    isnull;//�Ƿ��ǿսڵ�
        PathNode* parent;//���ڵ�
        vector<PathNode*> keyNeighbours; //�ؼ��ھӽڵ�
    };

    int height,width;

    PathNode*** pathMap;//������ͼ
    PathNode startNode;
    PathNode endNode;

    PathNode nullNode;//�սڵ�

    vector<PathNode> retPath;//��������·��

    //��������ֱ�߾���
    int GetDis(const PathNode& startNode,const PathNode& endNode){
        int dis = sqrt( pow( (endNode.col -startNode.col),2) +pow( (endNode.row -startNode.row),2) )*10;//pow�η�����
        return dis;
    }
    //����hֵ
    int GetH(const PathNode& startNode,const PathNode& endNode){
        int x = abs(startNode.col - endNode.col);//ȡˮƽ��������ֵ
        int y = abs(startNode.row - endNode.row);//ȡ��ֱ��������ֵ
        return (x + y)*10;
    }


    bool* Prune(short unitMap,char p,char n);
    void Init(int **_map,int _height,int _width);
    PathNode JumpStraight(PathNode*** _pathMap,PathNode currenNode,Direct dir);
    PathNode JumpOblique(PathNode*** _pathMap,PathNode currenNode,Direct dir);
    vector<PathNode> FindPath(PathNode _startNode,PathNode _endNode);
    void PrintRoute();

};
