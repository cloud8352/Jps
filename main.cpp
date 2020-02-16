#include <iostream> //"#"����Ԥ��������
#include<cstring>
#include<fstream>//��дͷ�ļ�
#include<time.h>
#include<windows.h>
#include"astar.h"
#include"jps.h"
using namespace std;    //ʹ��standard�����ռ�


int main(){
    system("mode con cols=120 lines=600");
    //��row����col
    int height = 400;
    int width = 400;

    int start_x =1,start_y =1;
    int end_x   =6,end_y  =395;
    cout<<"��ͼ�ߴ磨height*width��: "<<height<<"*"<<width;
    cout<<endl<<"��ʼ�㣨y��x����"<<start_y<<","<<start_x<<endl;
    cout<<"�����㣨y��x����"<<end_y<<","<<end_x<<endl;

    time_t time_start_ms,time_end_ms;//ʱ���¼ms

    //��ȡ��ͼ
    string filepath="map/map400x400.txt";
    ifstream fin(filepath.c_str());
    if(!fin) {cout<<endl<<"�ļ�������"<<endl; system("pause");}

    int **pMap;//��ͼ��άָ������
    pMap = new int* [height];
    for(int i=0;i < height;i++){
        pMap[i] = new int[width];
        for(int j=0;j < width;j++){
            char c;
            fin>>c;
            if('.' == c) pMap[i][j] = 0;
            else pMap[i][j] = 1;
            //cout<<pMap[i][j];
        }
        //cout<<endl;
    }

    Astar::MyPoint startPoint = {start_y,start_x};
    Astar::MyPoint endPoint = {end_y, end_x};

    Astar astar;

    time_start_ms = clock();//a��Ѱ·��ʼʱ��

    astar.Init(pMap, height, width, startPoint, endPoint);

    astar.FindPath();

    time_end_ms = clock();//a��Ѱ·����ʱ��
    cout<<"a��Ѱ·ʹ��ʱ�䣺"<<difftime(time_end_ms, time_start_ms)<<"ms";

    astar.PrintRoute();

    system("pause");

    //JPS
    cout<<"------------JPS---------------"<<"\n";
    Jps jps;
    Jps::PathNode jStart = {start_y,start_x};
    Jps::PathNode jEnd = {end_y, end_x};

    time_start_ms = clock();//JpsPruneѰ·��ʼʱ��

    jps.Init(pMap, height, width);

    jps.FindPath(jStart, jEnd);

    time_end_ms = clock();//JpsPruneѰ·����ʱ��
    cout<<"JpsѰ·ʹ��ʱ�䣺"<<difftime(time_end_ms, time_start_ms)<<"ms";
    jps.PrintRoute();

    system("pause");
    return 0;
}
