#include <iostream>
#include<windows.h>
#include<vector>
#include<cmath>

using namespace std;
using std::vector;

class Astar
{
public:
    struct MyPoint{
        int row;//��
        int col;
        int g,h,f;
        void GetF(){
            f = g + h;
        }
    };
    //����ö��
    enum Direct{
        p_up,p_down,p_left,p_right,p_leftup,p_leftdown,p_rightup,p_rightdown
    };
    //������ͼ�ڵ�
    struct PathNode{
        int     value;//
        bool    isroute;//�Ƿ������·���е�һ��
        bool    isfind;//�Ƿ��߹�
    };
    //���Ľڵ�����
    struct MyTreeNode{
        MyPoint pos;
        MyTreeNode* parent;
        vector<MyTreeNode*> child;//���ڴ���õ����Χ���е㣿����������������
    };

    int VerticalDist; //ÿ�����ڸ�ֱ�߾���10
    int ObliqueDist;  //ÿ�����ڸ�б�߾���14

    int ROW,COL;//��ͼ��������������
    int **map;//��ͼ����

    //����������ͼ
    PathNode **pathMap;
    MyPoint beginPoint;
    MyPoint endPoint;

    MyTreeNode* beginTreeNode;//�����б����ʼ�ڵ㣬����ʼ�ڵ�

    //����ָ�룺��ǰ�㡢̽·��
    MyTreeNode* pTemp;//��ǰ��
    MyTreeNode* pTempChild;//̽·��

    //�������飬�����ӽڵ�
    vector<MyTreeNode*> openTree;//�����б�

    vector<MyTreeNode*>::iterator minF_Iter;//���ڴ����Сfֵ���е�ĵ�����
    vector<MyTreeNode*>::iterator it;//���ڼ����ĵ�����

    //�õ��Ƿ���У����з���true
    bool isRoad(const MyPoint& point,PathNode **_pathMap){
        if(point.col <0 || point.col >= COL ||
           point.row <0 || point.row >= ROW
           )//������ͼ
           return false;
        if(1 == _pathMap[point.row][point.col].value)//�õ�Ϊ�ϰ�
            return false;
        if(_pathMap[point.row][point.col].isfind)//�õ��Ѿ��߹�
            return false;
        return true;
    }

    //�жϵ�(row,col)�Ƿ�Ϊ�ϰ���
    bool isBarrier(int row, int col, PathNode **_pathMap){
        if(col <0 || col >= COL ||
           row <0 || row >= ROW
           )//������ͼ
           return true;
        if(1 == _pathMap[row][col].value)//�õ�Ϊ�ϰ�
            return true;
        return false;
    }

    //����hֵ
    int GetH(const MyPoint& point,const MyPoint& endpos){
        int x = abs(point.col - endpos.col);//ȡˮƽ��������ֵ
        int y = abs(point.row - endpos.row);//ȡ��ֱ��������ֵ
        return (x + y)*VerticalDist;
    }

    void Init(int **_map,int height,int width,MyPoint _beginPoint,MyPoint _endPoint);
    void FindPath();

};
