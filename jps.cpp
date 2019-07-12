#include"jps.h"

//判断邻居类型，是否是最佳邻居和强迫邻居
//入参：单元地图8位二进制格式(十进制范围0-255)，父节点位置(0-8)、检测的邻居的位置(0-8)
//当前点在单元地图的4位置
bool* Jps::Prune(short unitMap,char p,char n){
    static bool retType[2];//返回的类型
    char obstaclePos = 0;

 #if 0
    //单元地图预处理
    char unitMapTmp =0;
    if(p ==0){//单元地图顺时针转180度
        unitMapTmp = unitMapTmp | (unitMap<<8 &(1<<8) );//0->8
        unitMapTmp = unitMapTmp | (unitMap<<6 &(1<<7) );//1->7
        unitMapTmp = unitMapTmp | (unitMap<<4 &(1<<6) );//2->6
        unitMapTmp = unitMapTmp | (unitMap<<2 &(1<<5) );//3->5
        unitMapTmp = unitMapTmp | (unitMap>>2 &(1<<3) );//5->3
        unitMapTmp = unitMapTmp | (unitMap>>4 &(1<<2) );//6->2
        unitMapTmp = unitMapTmp | (unitMap>>6 &(1<<1) );//7->1
        unitMapTmp = unitMapTmp | (unitMap>>8 &(1<<0) );//8->0
        p = 8;
    }
#endif // 0

    if(p == 0){
        if(n ==7 ||n ==5 || n ==8){
            retType[0] = true;
            retType[1] = false;
        }

        if(n ==2){
            obstaclePos = unitMap>>1 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==6){
            obstaclePos = unitMap>>3 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }

        if(n == 1||n ==3){
            retType[0] = false;
            retType[1] = false;
        }
    }

    if(p == 1){
        if(n ==7){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==6){
            obstaclePos = unitMap>>3 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==8){
            obstaclePos = unitMap>>5 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }

        if(n == 0||n ==2||n ==3||n ==5){
            retType[0] = false;
            retType[1] = false;
        }
    }

    if(p == 2){
        if(n ==7 ||n ==6 || n ==3){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==0){
            obstaclePos = unitMap>>1 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==8){
            obstaclePos = unitMap>>5 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }

        if(n == 1||n ==5){
            retType[0] = false;
            retType[1] = false;
        }
    }

    if(p == 3){
        if(n ==5){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==2){
            obstaclePos = unitMap>>1 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==8){
            obstaclePos = unitMap>>7 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n == 0||n ==1||n ==6||n ==7){
            retType[0] = false;
            retType[1] = false;
        }
    }

    if(p == 5){//--------------------------------------已修改
        if(n ==3){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==0){
            obstaclePos = unitMap>>1 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==6){
            obstaclePos = unitMap>>7 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }

        if(n == 1||n ==2||n ==7||n ==8){
            retType[0] = false;
            retType[1] = false;
        }
    }


    if(p == 6){
        if(n ==1 ||n ==2 || n ==5){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==0){
            obstaclePos = unitMap>>3 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==8){
            obstaclePos = unitMap>>7 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }

        if(n == 3||n ==7){
            retType[0] = false;
            retType[1] = false;
        }
    }

    if(p == 7){
        if(n ==1){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==0){
            obstaclePos = unitMap>>3 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==2){
            obstaclePos = unitMap>>5 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n == 3||n ==5||n ==6||n ==8){
            retType[0] = false;
            retType[1] = false;
        }

    }

    if(p == 8){
        if(n ==0 ||n ==1 || n ==3){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==2){
            obstaclePos = unitMap>>5 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==6){
            obstaclePos = unitMap>>7 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n == 5||n ==7){
            retType[0] = false;
            retType[1] = false;
        }
    }

    return retType;
}

void Jps::Init(){

    jumpPointTmp = new PathNode;
    memset(jumpPointTmp, 0, sizeof(PathNode));
    jumpPointTmp->row = 5;
    jumpPointTmp->col = 2;

    //cout<<jumpPointTmp->row<<jumpPointTmp->col;

    //初始化空节点
    nullNode.isnull = true;

    height = 8;
    width = 15;

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

    //建立辅助地图
    pathMap = new PathNode*[height];
    for(int i=0;i<height;i++){
        pathMap[i] = new PathNode[width];
        for(int j=0;j<width;j++){
            pathMap[i][j].isfind = false;
            pathMap[i][j].isroute = false;
            pathMap[i][j].value = test_map[i][j];
        }
    }

    //设置开始结束点
    startNode.row = 1;
    startNode.col = 0;

    endNode.row = 4;
    endNode.col = 14;

    //从开始点出发，寻找跳点

}



//直跳跃
//入参：辅助地图、当前节点、直跳跃方向-x方向值，y方向值
//返回跳点
Jps::PathNode Jps::JumpStraight(PathNode** _pathMap,PathNode currenNode,Direct dir){
    int delta_x = 0;
    int delta_y = 0;
    short unitMap = 0;
    char valueT = 0;//存储辅助地图中点的临时值，用于算出单元地图值
    bool* nodeTyp;
    char parent;//单元地图中，父节点
    char neighbGroup[9] = {9,9,9,9,9,9,9,9,9};//单元地图中,要探测的邻居组，初始化为非(0-8)的值，为9的点为不可行点
    switch(dir)
    {
    case p_up:
        delta_x = 0;
        delta_y = -1;
        parent = 7;
        break;
    case p_down:
        delta_x = 0;
        delta_y = 1;
        parent = 1;
        break;
    case p_left:
        delta_x = -1;
        delta_y = 0;
        parent = 5;
        break;
    case p_right:
        delta_x = 1;
        delta_y = 0;
        parent = 3;
        break;
    default:
        break;
    }

    PathNode nodeTmp = currenNode;//沿指定方向搜寻的点
    //沿指定方向搜寻，知道找到跳点，或碰到障碍物，或超出地图
    while(1){
        nodeTmp.row += delta_y;
        nodeTmp.col += delta_x;
        cout<<nodeTmp.row<<","<<nodeTmp.col<<endl;
        //如果搜寻到终点就返回
        if(nodeTmp.row == endNode.row &&
           nodeTmp.col == endNode.col) return nodeTmp;
        //如果搜寻点，是障碍物，或者出了地图，返回空
        if(height <= nodeTmp.row || 0 > nodeTmp.row||
           width <= nodeTmp.col || 0 > nodeTmp.col ||
            1 == _pathMap[nodeTmp.row][nodeTmp.col].value
           ) return nullNode;

        //获取搜寻点周围3x3单元地图，并找到邻居组
        unitMap = 0;//清空单元地图
        for(int i=0; i<9; i++){//初始化邻居组
            neighbGroup[i] = 9;
        }

        for(int i = 0;i <3; i++){
            for(int j= 0;j <3; j++){
                int row_t = nodeTmp.row +i-1;//获取周围的点坐标
                int col_t = nodeTmp.col +j-1;
                if(height > row_t && 0 <= row_t &&
                    width > col_t && 0 <= col_t
                    ){//确保周围点没超出地图
                    valueT = _pathMap[row_t][col_t].value;
                    unitMap = unitMap|valueT<<(i*3 +j);
                    if(1 != valueT){//不为障碍
                        neighbGroup[i*3+j] = (i*3 +j);
                    }
                }
            }
        }//end-获取搜寻点周围3x3单元地图，并找到邻居组

        //获取当前搜寻点周围点类型
        for(int i=0;i <9;i++){
            if(9 != neighbGroup[i] &&
               parent != neighbGroup[i] &&
               4 != neighbGroup[i]
               ){//如果邻居组中点不为：空(9)、当前搜寻点(4)、父节点
                nodeTyp = Prune(unitMap, parent, neighbGroup[i]);
                if(1 == nodeTyp[1]){//如果存在强迫邻居，返回当前搜寻点
                    return nodeTmp;
                }

            }
        }//end-获取当前搜寻点周围点类型


    }//while(o)-end
}


Jps::PathNode Jps::JumpOblique(PathNode** _pathMap,PathNode currenNode,Direct dir){
    int delta_x = 0;
    int delta_y = 0;
    short unitMap = 0;
    char valueT = 0;//存储辅助地图中点的临时值，用于算出单元地图值
    bool* nodeTyp;
    char parent;//单元地图中，父节点
    char neighbGroup[9] = {9,9,9,9,9,9,9,9,9};//单元地图中,要探测的邻居组，初始化为非(0-8)的值，为9的点为不可行点
    Direct straightDirs[2] = {p_up,p_up};
    switch(dir)
    {
    case p_leftup:
        delta_x = -1;
        delta_y = -1;
        parent = 8;
        straightDirs[0] = p_left;
        straightDirs[1] = p_up;
        break;
    case p_leftdown:
        delta_x = 1;
        delta_y = -1;
        parent = 2;
        straightDirs[0] = p_left;
        straightDirs[1] = p_down;
        break;
    case p_rightup:
        delta_x = -1;
        delta_y = 1;
        parent = 6;
        straightDirs[0] = p_right;
        straightDirs[1] = p_up;
        break;
    case p_rightdown:
        delta_x = 1;
        delta_y = 1;
        parent = 0;
        straightDirs[0] = p_right;
        straightDirs[1] = p_down;
        break;
    default:
        break;
    }

    PathNode nodeTmp = currenNode;//沿指定方向搜寻的点
    //沿指定方向搜寻，知道找到跳点，或碰到障碍物，或超出地图
    while(1){
        nodeTmp.row += delta_y;
        nodeTmp.col += delta_x;
        cout<<nodeTmp.row<<","<<nodeTmp.col<<endl;
        //如果搜寻到终点就返回
        if(nodeTmp.row == endNode.row &&
           nodeTmp.col == endNode.col) return nodeTmp;
        //如果搜寻点，是障碍物，或者出了地图，返回空
        if(height <= nodeTmp.row || 0 > nodeTmp.row||
           width <= nodeTmp.col || 0 > nodeTmp.col ||
            1 == _pathMap[nodeTmp.row][nodeTmp.col].value
           ) return nullNode;

        //获取搜寻点周围3x3单元地图，并找到邻居组
        unitMap = 0;//清空单元地图
        for(int i=0; i<9; i++){//初始化邻居组
            neighbGroup[i] = 9;
        }

        for(int i = 0;i <3; i++){
            for(int j= 0;j <3; j++){
                int row_t = nodeTmp.row +i-1;//获取周围的点坐标
                int col_t = nodeTmp.col +j-1;
                if(height > row_t && 0 <= row_t &&
                    width > col_t && 0 <= col_t
                    ){//确保周围点没超出地图
                    valueT = _pathMap[row_t][col_t].value;
                    unitMap = unitMap|valueT<<(i*3 +j);
                    if(1 != valueT){//不为障碍
                        neighbGroup[i*3+j] = (i*3 +j);
                    }
                }
            }
        }//end-获取搜寻点周围3x3单元地图，并找到邻居组

        //获取当前搜寻点周围点类型，如果存在强迫邻居，返回当前搜寻点
        for(int i=0;i <9;i++){
            if(9 != neighbGroup[i] &&
               parent != neighbGroup[i] &&
               4 != neighbGroup[i]
               ){//如果邻居组中点不为：空(9)、当前搜寻点(4)、父节点
                nodeTyp = Prune(unitMap, parent, neighbGroup[i]);
                if(1 == nodeTyp[1]){//如果存在强迫邻居，返回当前搜寻点
                    return nodeTmp;
                }

            }
        }//end-获取当前搜寻点周围点类型

        //往当前点的直线“真。邻居“，做直跳跃，如果不反回空，返回当前点
        PathNode jumpNode;//用于保存直跳跃的返回节点
        for(int i=0;i <2; i++){
            jumpNode = JumpStraight(_pathMap, nodeTmp, straightDirs[i]);
            if(false == jumpNode.isnull) return nodeTmp;
        }


    }
}
