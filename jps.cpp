#include"jps.h"


//�ж��ھ����ͣ��Ƿ�������ھӺ�ǿ���ھ�
//��Σ���Ԫ��ͼ8λ�����Ƹ�ʽ(ʮ���Ʒ�Χ0-255)�����ڵ�λ��(0-8)�������ھӵ�λ��(0-8)
//��ǰ���ڵ�Ԫ��ͼ�����ģ�4��λ��
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

    if(p == 5){
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

void Jps::Init(int **_map,int _height,int _width){

    //��ʼ���սڵ�
    nullNode.isnull = true;

    height = _height;
    width = _width;

    //����������ͼ
    pathMap = new PathNode**[height];
    for(int i=0;i<height;i++){
        pathMap[i] = new PathNode*[width];
        for(int j=0;j<width;j++){
            pathMap[i][j] = new PathNode;
            memset(pathMap[i][j],0, sizeof(PathNode));
            pathMap[i][j]->row = i;
            pathMap[i][j]->col = j;
            pathMap[i][j]->isfind = false;
            pathMap[i][j]->isroute = false;
            pathMap[i][j]->value = _map[i][j];
        }
    }

}



//ֱ��Ծ
//��Σ�������ͼ����ǰ�ڵ㡢ֱ��Ծ����-x����ֵ��y����ֵ
//��������
Jps::PathNode Jps::JumpStraight(PathNode*** _pathMap,PathNode currenNode,Direct dir){
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
        //cout<<"ֱ��Ծ��"<<nodeTmp.row<<","<<nodeTmp.col<<endl;
        //�����Ѱ���յ�ͷ���
        if(nodeTmp.row == endNode.row &&
           nodeTmp.col == endNode.col) return nodeTmp;
        //�����Ѱ�㣬���ϰ�����߳��˵�ͼ�����ؿ�
        if(height <= nodeTmp.row || 0 > nodeTmp.row||
           width <= nodeTmp.col || 0 > nodeTmp.col ||
            1 == _pathMap[nodeTmp.row][nodeTmp.col]->value
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
                    valueT = _pathMap[row_t][col_t]->value;
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


Jps::PathNode Jps::JumpOblique(PathNode*** _pathMap,PathNode currenNode,Direct dir){
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
        delta_x = -1;
        delta_y = 1;
        parent = 2;
        straightDirs[0] = p_left;
        straightDirs[1] = p_down;
        break;
    case p_rightup:
        delta_x = 1;
        delta_y = -1;
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
        //cout<<"б��Ծ��"<<nodeTmp.row<<","<<nodeTmp.col<<endl;
        //�����Ѱ���յ�ͷ���
        if(nodeTmp.row == endNode.row &&
           nodeTmp.col == endNode.col) return nodeTmp;
        //�����Ѱ�㣬���ϰ�����߳��˵�ͼ�����ؿ�
        if(height <= nodeTmp.row || 0 > nodeTmp.row||
           width <= nodeTmp.col || 0 > nodeTmp.col ||
            1 == _pathMap[nodeTmp.row][nodeTmp.col]->value
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
                    valueT = _pathMap[row_t][col_t]->value;
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


vector<Jps::PathNode> Jps::FindPath(PathNode _startNode,PathNode _endNode){
    //���ÿ�ʼ������
    startNode = _startNode;
    endNode = _endNode;

    vector<Direct> jumpDirs;//��ŵ�ǰ��Ҫ��Ծ�ķ���
    vector<Direct>::iterator dirsIt;//���ڼ����������ĵ�����
    PathNode jumpNode;//���ص�����
    bool* nodeTyp;//���ص��ھ�����

    PathNode currentNode;//��ǰ�ڵ�
    vector<PathNode> openTree;//�����б��ر��б����ø�����ͼ�����isfind����ά����
    vector<PathNode>::iterator it;//���ڵ���
    vector<PathNode>::iterator minF_iter;//�����Сfֵ�ڵ�

    currentNode =  startNode;//��ǰ��Ϊ��ʼ��
    pathMap[currentNode.row][currentNode.col]->isfind = true;

    //��ʼ���������˸�����
    for(int i=0;i <8;i++){
        jumpDirs.push_back( (Direct)i);
    }

    //Ѱ·
    while(1){

        //���õ�ǰ�㣬�Լ�parent���������С��档�ھӡ�������Ծ
        for(dirsIt = jumpDirs.begin();dirsIt != jumpDirs.end(); dirsIt++){
            //cout<<"����"<<(*dirsIt)<<" "<<endl;
            if( *(dirsIt) == p_up|| *(dirsIt) == p_down|| *(dirsIt) == p_left|| *(dirsIt) == p_right){
                jumpNode = JumpStraight(pathMap, currentNode, (*dirsIt) );
            }
            if( *(dirsIt) == p_leftup|| *(dirsIt) == p_leftdown|| *(dirsIt) == p_rightup|| *(dirsIt) == p_rightdown){
                jumpNode = JumpOblique(pathMap, currentNode, (*dirsIt) );
            }

            //������ص�����Ч�ڵ㣬�Ҳ��ڹر��б��У�δ�ҹ���
            if(false == jumpNode.isnull && false == pathMap[jumpNode.row][jumpNode.col]->isfind){

                jumpNode.g = pathMap[currentNode.row][currentNode.col]->g +GetDis( currentNode, jumpNode);
                //����õ��Ѿ��ڿ����б��У��Ƚ�gֵ��ȡgֵ��С�ĵ�����ԣ��������ٴμ��뿪���б�
                if(pathMap[jumpNode.row][jumpNode.col]->inopen){
                    if(pathMap[jumpNode.row][jumpNode.col]->g > jumpNode.g){
                        pathMap[jumpNode.row][jumpNode.col]->g = jumpNode.g;
                        pathMap[jumpNode.row][jumpNode.col]->GetF();

                        pathMap[jumpNode.row][jumpNode.col]->parent = pathMap[currentNode.row][currentNode.col];
                    }

                }
                //������ڿ����б���
                if(false == pathMap[jumpNode.row][jumpNode.col]->inopen){
                    jumpNode.h = GetH(jumpNode, endNode);
                    jumpNode.GetF();
                    jumpNode.inopen = true;

                    //��̽�����뿪���б�
                    openTree.push_back(jumpNode);
                    //���¸�����ͼ�ж�Ӧ̽���Ľڵ�����
                    pathMap[jumpNode.row][jumpNode.col]->g = jumpNode.g;
                    pathMap[jumpNode.row][jumpNode.col]->h = jumpNode.h;
                    pathMap[jumpNode.row][jumpNode.col]->f = jumpNode.f;
                    pathMap[jumpNode.row][jumpNode.col]->parent = pathMap[currentNode.row][currentNode.col];
                    pathMap[jumpNode.row][jumpNode.col]->inopen = jumpNode.inopen;
                }


                //system("pause");

            }


        }

        if(openTree.size() == 0) break;
        //����һ��
        minF_iter = openTree.begin();
        //cout<<endl<<"����һ��"<<endl;
        for(it =openTree.begin();it !=openTree.end(); it++){
            //cout<<(*it).row<<","<<(*it).col<<endl;
            if(pathMap[(*it).row][(*it).col]->f < pathMap[(*minF_iter).row][(*minF_iter).col]->f){
                minF_iter = it;
            }
        }

        //cout<<endl<<"�ҵ�����һ��: ";
        //cout<<(*minF_iter).row<<","<<(*minF_iter).col<<endl;

#if 0   //����
        cout<<endl<<"�ҵ�����һ��: ";
        cout<<(*minF_iter).row<<","<<(*minF_iter).col<<endl;
        cout<<"�˽ڵ㸸�ڵ����꣺";
        PathNode tmp = { (*minF_iter).row,(*minF_iter).col};
        while(NULL != pathMap[tmp.row][tmp.col]->parent){
            int t_row = tmp.row,t_col = tmp.col;
            tmp.row = pathMap[t_row][t_col]->parent->row;
            tmp.col = pathMap[t_row][t_col]->parent->col;
            cout<<tmp.row<<","<<tmp.col<<" ";
        }
        cout<<endl;
#endif


        currentNode = (*minF_iter);

        pathMap[currentNode.row][currentNode.col]->isfind = true;

        if(currentNode.row == endNode.row && currentNode.col == endNode.col) break;

        openTree.erase(minF_iter);

        //��ȡ��ǰ�ڵ㼴��Ҫ��Ѱ�ķ���jumpDirs
        jumpDirs.clear();
        int delta_y = currentNode.row - pathMap[currentNode.row][currentNode.col]->parent->row;
        int delta_x = currentNode.col - pathMap[currentNode.row][currentNode.col]->parent->col;
        char p;//��Ԫ��ͼ�и���
        short unitMap = 0;
        char neighbGroup[9] = {9,9,9,9,9,9,9,9,9};//��Ԫ��ͼ��,Ҫ̽����ھ��飬��ʼ��Ϊ��(0-8)��ֵ��Ϊ9�ĵ�Ϊ�����е�

        if(0 > delta_y && 0 ==delta_x) p = 7;//��Ѱ����Ϊ��
        if(0 < delta_y && 0 ==delta_x) p = 1;//��Ѱ����Ϊ��
        if(0 == delta_y && 0 >delta_x) p = 5;//��Ѱ����Ϊ��
        if(0 == delta_y && 0 <delta_x) p = 3;//��Ѱ����Ϊ��

        if(0 > delta_y && 0 >delta_x) p = 8;//��Ѱ����Ϊ����
        if(0 < delta_y && 0 >delta_x) p = 2;//��Ѱ����Ϊ����
        if(0 > delta_y && 0 <delta_x) p = 6;//��Ѱ����Ϊ����
        if(0 < delta_y && 0 <delta_x) p = 0;//

        //��ȡ��Ѱ����Χ3x3��Ԫ��ͼ�����ҵ��ھ���

        for(int i = 0;i <3; i++){
            for(int j= 0;j <3; j++){
                int row_t = currentNode.row +i-1;//��ȡ��Χ�ĵ�����
                int col_t = currentNode.col +j-1;
                if(height > row_t && 0 <= row_t &&
                    width > col_t && 0 <= col_t
                    ){//ȷ����Χ��û������ͼ
                    int valueT = pathMap[row_t][col_t]->value;
                    unitMap = unitMap|valueT<<(i*3 +j);
                    if(1 != valueT){//��Ϊ�ϰ�
                        neighbGroup[i*3+j] = (i*3 +j);
                    }
                }
            }
        }//end-��ȡ��Ѱ����Χ3x3��Ԫ��ͼ�����ҵ��ھ���

        //��ȡ��ǰ��Ѱ����Χ�����ͣ�����ֵ̽�ⷽ����
        for(int i=0;i <9;i++){
            if(9 != neighbGroup[i] &&
               p != neighbGroup[i] &&
               4 != neighbGroup[i]
               ){//����ھ����е㲻Ϊ����(9)����ǰ��Ѱ��(4)�����ڵ�
                nodeTyp = Prune(unitMap, p, neighbGroup[i]);
                if(1 == nodeTyp[0]){//������ڹؼ��ھӣ�����̽�ⷽ�����м��뵱ǰ����
                    if(1==i) jumpDirs.push_back(p_up);
                    if(7==i) jumpDirs.push_back(p_down);
                    if(3==i) jumpDirs.push_back(p_left);
                    if(5==i) jumpDirs.push_back(p_right);

                    if(0==i) jumpDirs.push_back(p_leftup);
                    if(6==i) jumpDirs.push_back(p_leftdown);
                    if(2==i) jumpDirs.push_back(p_rightup);
                    if(8==i) jumpDirs.push_back(p_rightdown);

                }

            }
        }//end-��ȡ��ǰ��Ѱ����Χ�����ͣ�����ֵ̽�ⷽ����

        //system("pause");

    }

    //����·��
    vector<PathNode> retPathTmp;
    PathNode nodeTmp = endNode;
    while(1){
        int row_t = nodeTmp.row;
        int col_t = nodeTmp.col;
        retPathTmp.push_back(nodeTmp);
        if(NULL == pathMap[nodeTmp.row][nodeTmp.col]->parent) break;
        nodeTmp.row = pathMap[row_t][col_t]->parent->row;
        nodeTmp.col = pathMap[row_t][col_t]->parent->col;
    }
    //��·������Ϊ�ӿ�ʼ�������˳��
    for(it =retPathTmp.end()-1;it != retPathTmp.begin() -1; it--){
        retPath.push_back(*it);
    }

    vector<PathNode>().swap(retPathTmp);//�ͷ��ڴ�
    return retPath;


}

void Jps::PrintRoute(){
    vector<PathNode>::iterator it;//���ڵ���
    float routLength = 0;//·���ܳ���
    cout<<endl<<"route"<<"("<<retPath.size()<<"): ";
    for(it =retPath.begin();it != retPath.end(); it++){
        cout<<(*it).row<<","<<(*it).col<<" ";
        //����·������
        if(it > retPath.begin()){
            int row_t = (*it).row,col_t = (*it).col;//��������
            int row_t_l = (*(it -1) ).row,col_t_l = (*(it -1) ).col;//�ϴ�����
            routLength += sqrt( pow( col_t - col_t_l,2) +pow( (row_t - row_t_l),2) );//pow�η�����
        }
    }
    cout<<endl;
    cout<<"routLength��"<<routLength;

}


