#include"jps.h"

//�ж��ھ����ͣ��Ƿ�������ھӺ�ǿ���ھ�
//��Σ���Ԫ��ͼ8λ�����Ƹ�ʽ(ʮ���Ʒ�Χ0-255)�����ڵ�λ��(0-8)�������ھӵ�λ��(0-8)
//��ǰ���ڵ�Ԫ��ͼ��4λ��
bool* Jps::Prune(short unitMap,char p,char n){
    static bool retType[2];//���ص�����
    char obstaclePos = 0;

 #if 0
    //��Ԫ��ͼԤ����
    char unitMapTmp =0;
    if(p ==0){//��Ԫ��ͼ˳ʱ��ת180��
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

    if(p == 5){//--------------------------------------���޸�
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

    //��ʼ���սڵ�
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

    //����������ͼ
    pathMap = new PathNode*[height];
    for(int i=0;i<height;i++){
        pathMap[i] = new PathNode[width];
        for(int j=0;j<width;j++){
            pathMap[i][j].isfind = false;
            pathMap[i][j].isroute = false;
            pathMap[i][j].value = test_map[i][j];
        }
    }

    //���ÿ�ʼ������
    startNode.row = 1;
    startNode.col = 0;

    endNode.row = 4;
    endNode.col = 14;

    //�ӿ�ʼ�������Ѱ������

}



//ֱ��Ծ
//��Σ�������ͼ����ǰ�ڵ㡢ֱ��Ծ����-x����ֵ��y����ֵ
//��������
Jps::PathNode Jps::JumpStraight(PathNode** _pathMap,PathNode currenNode,Direct dir){
    int delta_x = 0;
    int delta_y = 0;
    short unitMap = 0;
    char valueT = 0;//�洢������ͼ�е����ʱֵ�����������Ԫ��ͼֵ
    bool* nodeTyp;
    char parent;//��Ԫ��ͼ�У����ڵ�
    char neighbGroup[9] = {9,9,9,9,9,9,9,9,9};//��Ԫ��ͼ��,Ҫ̽����ھ��飬��ʼ��Ϊ��(0-8)��ֵ��Ϊ9�ĵ�Ϊ�����е�
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

    PathNode nodeTmp = currenNode;//��ָ��������Ѱ�ĵ�
    //��ָ��������Ѱ��֪���ҵ����㣬�������ϰ���򳬳���ͼ
    while(1){
        nodeTmp.row += delta_y;
        nodeTmp.col += delta_x;
        cout<<nodeTmp.row<<","<<nodeTmp.col<<endl;
        //�����Ѱ���յ�ͷ���
        if(nodeTmp.row == endNode.row &&
           nodeTmp.col == endNode.col) return nodeTmp;
        //�����Ѱ�㣬���ϰ�����߳��˵�ͼ�����ؿ�
        if(height <= nodeTmp.row || 0 > nodeTmp.row||
           width <= nodeTmp.col || 0 > nodeTmp.col ||
            1 == _pathMap[nodeTmp.row][nodeTmp.col].value
           ) return nullNode;

        //��ȡ��Ѱ����Χ3x3��Ԫ��ͼ�����ҵ��ھ���
        unitMap = 0;//��յ�Ԫ��ͼ
        for(int i=0; i<9; i++){//��ʼ���ھ���
            neighbGroup[i] = 9;
        }

        for(int i = 0;i <3; i++){
            for(int j= 0;j <3; j++){
                int row_t = nodeTmp.row +i-1;//��ȡ��Χ�ĵ�����
                int col_t = nodeTmp.col +j-1;
                if(height > row_t && 0 <= row_t &&
                    width > col_t && 0 <= col_t
                    ){//ȷ����Χ��û������ͼ
                    valueT = _pathMap[row_t][col_t].value;
                    unitMap = unitMap|valueT<<(i*3 +j);
                    if(1 != valueT){//��Ϊ�ϰ�
                        neighbGroup[i*3+j] = (i*3 +j);
                    }
                }
            }
        }//end-��ȡ��Ѱ����Χ3x3��Ԫ��ͼ�����ҵ��ھ���

        //��ȡ��ǰ��Ѱ����Χ������
        for(int i=0;i <9;i++){
            if(9 != neighbGroup[i] &&
               parent != neighbGroup[i] &&
               4 != neighbGroup[i]
               ){//����ھ����е㲻Ϊ����(9)����ǰ��Ѱ��(4)�����ڵ�
                nodeTyp = Prune(unitMap, parent, neighbGroup[i]);
                if(1 == nodeTyp[1]){//�������ǿ���ھӣ����ص�ǰ��Ѱ��
                    return nodeTmp;
                }

            }
        }//end-��ȡ��ǰ��Ѱ����Χ������


    }//while(o)-end
}


Jps::PathNode Jps::JumpOblique(PathNode** _pathMap,PathNode currenNode,Direct dir){
    int delta_x = 0;
    int delta_y = 0;
    short unitMap = 0;
    char valueT = 0;//�洢������ͼ�е����ʱֵ�����������Ԫ��ͼֵ
    bool* nodeTyp;
    char parent;//��Ԫ��ͼ�У����ڵ�
    char neighbGroup[9] = {9,9,9,9,9,9,9,9,9};//��Ԫ��ͼ��,Ҫ̽����ھ��飬��ʼ��Ϊ��(0-8)��ֵ��Ϊ9�ĵ�Ϊ�����е�
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

    PathNode nodeTmp = currenNode;//��ָ��������Ѱ�ĵ�
    //��ָ��������Ѱ��֪���ҵ����㣬�������ϰ���򳬳���ͼ
    while(1){
        nodeTmp.row += delta_y;
        nodeTmp.col += delta_x;
        cout<<nodeTmp.row<<","<<nodeTmp.col<<endl;
        //�����Ѱ���յ�ͷ���
        if(nodeTmp.row == endNode.row &&
           nodeTmp.col == endNode.col) return nodeTmp;
        //�����Ѱ�㣬���ϰ�����߳��˵�ͼ�����ؿ�
        if(height <= nodeTmp.row || 0 > nodeTmp.row||
           width <= nodeTmp.col || 0 > nodeTmp.col ||
            1 == _pathMap[nodeTmp.row][nodeTmp.col].value
           ) return nullNode;

        //��ȡ��Ѱ����Χ3x3��Ԫ��ͼ�����ҵ��ھ���
        unitMap = 0;//��յ�Ԫ��ͼ
        for(int i=0; i<9; i++){//��ʼ���ھ���
            neighbGroup[i] = 9;
        }

        for(int i = 0;i <3; i++){
            for(int j= 0;j <3; j++){
                int row_t = nodeTmp.row +i-1;//��ȡ��Χ�ĵ�����
                int col_t = nodeTmp.col +j-1;
                if(height > row_t && 0 <= row_t &&
                    width > col_t && 0 <= col_t
                    ){//ȷ����Χ��û������ͼ
                    valueT = _pathMap[row_t][col_t].value;
                    unitMap = unitMap|valueT<<(i*3 +j);
                    if(1 != valueT){//��Ϊ�ϰ�
                        neighbGroup[i*3+j] = (i*3 +j);
                    }
                }
            }
        }//end-��ȡ��Ѱ����Χ3x3��Ԫ��ͼ�����ҵ��ھ���

        //��ȡ��ǰ��Ѱ����Χ�����ͣ��������ǿ���ھӣ����ص�ǰ��Ѱ��
        for(int i=0;i <9;i++){
            if(9 != neighbGroup[i] &&
               parent != neighbGroup[i] &&
               4 != neighbGroup[i]
               ){//����ھ����е㲻Ϊ����(9)����ǰ��Ѱ��(4)�����ڵ�
                nodeTyp = Prune(unitMap, parent, neighbGroup[i]);
                if(1 == nodeTyp[1]){//�������ǿ���ھӣ����ص�ǰ��Ѱ��
                    return nodeTmp;
                }

            }
        }//end-��ȡ��ǰ��Ѱ����Χ������

        //����ǰ���ֱ�ߡ��档�ھӡ�����ֱ��Ծ����������ؿգ����ص�ǰ��
        PathNode jumpNode;//���ڱ���ֱ��Ծ�ķ��ؽڵ�
        for(int i=0;i <2; i++){
            jumpNode = JumpStraight(_pathMap, nodeTmp, straightDirs[i]);
            if(false == jumpNode.isnull) return nodeTmp;
        }


    }
}
