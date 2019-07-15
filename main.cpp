#include <iostream> //"#"����Ԥ��������
#include"astar.h"
#include"jps.h"
using namespace std;    //ʹ��standard�����ռ�


int main(){
    //��row����col
    int height = 8;
    int width = 15;
    int test_map[height][width] = {
        {0,0,1,1,0,0,0,0,0,0,0,1,1,0,1},
        {0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,1,1,0,0,1,1,0,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0,1,1,0,0,0},
        {0,0,1,1,0,0,1,1,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,1,1,0,0,1,0,1,0,0},
        {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,1,1,0,0,0,0,0,0,0}

    };

    //��ͼת���ɶ�άָ��
    int **a;
    a = new int* [height];
    for(int i=0;i < height;i++){
        a[i] = new int[width];
        for(int j=0;j < width;j++){
            a[i][j] = test_map[i][j];
        }
    }

    Astar::MyPoint startPoint = {1,1};
    Astar::MyPoint endPoint = {6,14};

    Astar astar;
    astar.Init(a, height, width, startPoint, endPoint);

    astar.FindPath();


    //JPS
    cout<<endl<<"--------Jps::Prune test---------"<<"\n";
    Jps jps;
    bool* type;
    char unitMapArray[3][3] = {
        {1,0,1},
        {1,0,0},
        {1,0,1}
    };
    short unitMap = 0x0000;
    for(int i=0;i <3;i++){
        for(int j=0;j <3;j++){
            cout<<(int)unitMapArray[i][j];
            unitMap = unitMap|(unitMapArray[i][j]<<(i*3+j));
        }
        cout<<endl;
    }

    cout<<"unitMap = "<<(int)unitMap<<endl;
    type = jps.Prune(unitMap,7,1);
    cout<<type[0]<<"-"<<type[1]<<endl;
    cout<<"-----------------------------"<<"\n";

    cout<<"-----Jps::JumpStraight() test-----"<<"\n";
    jps.Init();
    Jps::PathNode jumpNode;
    jumpNode = jps.JumpStraight(jps.pathMap,jps.startNode,Jps::p_left);
    cout<<"jumpNode.isnull: "<<jumpNode.isnull<<endl;
    cout<<"jumpNode.row,jumpNode.col: "<<jumpNode.row<<","<<jumpNode.col<<endl;

    cout<<"-----------------------------"<<"\n";

    cout<<"-----Jps::JumpStraight() test-----"<<"\n";
    jumpNode = jps.JumpOblique(jps.pathMap,jps.startNode,Jps::p_rightdown);
    cout<<"jumpNode.isnull: "<<jumpNode.isnull<<endl;
    cout<<"jumpNode.row,jumpNode.col: "<<jumpNode.row<<","<<jumpNode.col<<endl;

    cout<<"-----------------------------"<<"\n";

    jps.FindPath();


    system("pause");
    return 0;
}
