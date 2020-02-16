#include"astar.h"

//��ʼ��
void Astar::Init(int **_map,int height,int width,MyPoint _beginPoint,MyPoint _endPoint){
    map = _map;
    ROW = height;
    COL = width;

    VerticalDist = 10; //ÿ�����ڸ�ֱ�߾���10
    ObliqueDist = 14;  //ÿ�����ڸ�б�߾���14

    beginPoint = _beginPoint;
    endPoint = _endPoint;

    //����������ͼ
    pathMap = new PathNode*[ROW];
    for(int i=0;i<ROW;i++){
        pathMap[i] = new PathNode[COL];
        for(int j=0;j<COL;j++){
            pathMap[i][j].isfind = false;
            pathMap[i][j].isroute = false;
            pathMap[i][j].value = map[i][j];
        }
    }

    beginTreeNode = new MyTreeNode; //�����б����ʼ�ڵ�
    memset(beginTreeNode, 0, sizeof(MyTreeNode));
    //�����м������
    beginTreeNode->pos = beginPoint;
    //����߹�
    pathMap[beginTreeNode->pos.row][beginTreeNode->pos.col].isfind = true;

    pTemp = beginTreeNode;//��ʼ����ǰ���ڵ�Ϊ��ʼ�ڵ�
    pTempChild = NULL;//̽·��
}

//��ʼ���󣬻�ȡ·��
void Astar::FindPath(){
    while(1){
        //�ҳ�̽·����Χ8�����е㣬���浽�����б�
        for(int i=0;i<8;i++){
            bool canWalkObliquely = true;//б�Խ��Ƿ������
            pTempChild = new MyTreeNode;
            memset(pTempChild, 0, sizeof(MyTreeNode));
            pTempChild->pos = pTemp->pos;
            switch(i)
            {
            case p_up:
                pTempChild->pos.row = pTemp->pos.row -1;//ֻ���м�1
                pTempChild->pos.col = pTemp->pos.col;
                pTempChild->pos.g = pTemp->pos.g + VerticalDist;
                break;
            case p_down:
                pTempChild->pos.row = pTemp->pos.row +1;
                pTempChild->pos.col = pTemp->pos.col;
                pTempChild->pos.g = pTemp->pos.g + VerticalDist;
                break;
            case p_left:
                pTempChild->pos.row = pTemp->pos.row;//�в��䣬�м�1
                pTempChild->pos.col = pTemp->pos.col -1;
                pTempChild->pos.g = pTemp->pos.g + VerticalDist;
                break;
            case p_right:
                pTempChild->pos.row = pTemp->pos.row;//�в��䣬�м�1
                pTempChild->pos.col = pTemp->pos.col +1;
                pTempChild->pos.g = pTemp->pos.g + VerticalDist;
                break;
            case p_leftup:
                if(isBarrier(pTemp->pos.row -1, pTemp->pos.col, pathMap) ||//�жϵ�ǰ���ϱߵ��Ƿ�Ϊ�ϰ�
                    isBarrier(pTemp->pos.row, pTemp->pos.col -1, pathMap)   //�жϵ�ǰ����ߵ��Ƿ�Ϊ�ϰ�
                   ){//�ж�б���Ƿ����
                    canWalkObliquely = false;
                    break;
                   }
                pTempChild->pos.row = pTemp->pos.row -1;
                pTempChild->pos.col = pTemp->pos.col -1;
                pTempChild->pos.g = pTemp->pos.g + ObliqueDist;
                break;
            case p_leftdown:
                if(isBarrier(pTemp->pos.row +1, pTemp->pos.col, pathMap) ||//�жϵ�ǰ���±ߵ��Ƿ�Ϊ�ϰ�
                    isBarrier(pTemp->pos.row, pTemp->pos.col -1, pathMap)   //�жϵ�ǰ����ߵ��Ƿ�Ϊ�ϰ�
                   ){//�ж�б���Ƿ����
                    canWalkObliquely = false;
                    break;
                   }
                pTempChild->pos.row = pTemp->pos.row +1;
                pTempChild->pos.col = pTemp->pos.col -1;
                pTempChild->pos.g = pTemp->pos.g + ObliqueDist;
                break;
            case p_rightup:
                if(isBarrier(pTemp->pos.row -1, pTemp->pos.col, pathMap) ||//�жϵ�ǰ���ϱߵ��Ƿ�Ϊ�ϰ�
                    isBarrier(pTemp->pos.row, pTemp->pos.col +1, pathMap)   //�жϵ�ǰ���ұߵ��Ƿ�Ϊ�ϰ�
                   ){//�ж�б���Ƿ����
                    canWalkObliquely = false;
                    break;
                   }
                pTempChild->pos.row = pTemp->pos.row -1;
                pTempChild->pos.col = pTemp->pos.col +1;
                pTempChild->pos.g = pTemp->pos.g + ObliqueDist;
                break;
            case p_rightdown:
                if(isBarrier(pTemp->pos.row +1, pTemp->pos.col, pathMap) ||//�жϵ�ǰ���±ߵ��Ƿ�Ϊ�ϰ�
                    isBarrier(pTemp->pos.row, pTemp->pos.col +1, pathMap)   //�жϵ�ǰ���ұߵ��Ƿ�Ϊ�ϰ�
                   ){//�ж�б���Ƿ����
                    canWalkObliquely = false;
                    break;
                   }
                pTempChild->pos.row = pTemp->pos.row +1;
                pTempChild->pos.col = pTemp->pos.col +1;
                pTempChild->pos.g = pTemp->pos.g + ObliqueDist;
                break;
            }
            //���߾ͼ��뵱ǰ�ڵ���ӽڵ��飬�����뿪����openTree
            if(isRoad(pTempChild->pos, pathMap) && //�Ƿ����
               canWalkObliquely //�Խ��Ƿ����
               ){
                //����Ƿ��Ѿ��ڿ����б���
                bool isInOpenLst = false;
                for(it=openTree.begin();it != openTree.end();it++){
                    if( (*it)->pos.row == pTempChild->pos.row &&
                        (*it)->pos.col == pTempChild->pos.col
                       ){
                        isInOpenLst = true;
                        break;
                       }
                }
                if(isInOpenLst){
                    if( (*it)->pos.g > pTempChild->pos.g){
                        (*it)->pos.g = pTempChild->pos.g;//�����ǰ��gֵ���ڿ����б��ж�ӳ���gֵ�����޸�g
                        (*it)->pos.GetF();
                        (*it)->parent = pTemp;
                        pTemp->child.push_back(pTempChild);
                    }
                }
                if(isInOpenLst == false){
                    //����hֵ
                    pTempChild->pos.h = GetH(pTempChild->pos,endPoint);
                    //����fֵ
                    pTempChild->pos.GetF();
                    //����
                    pTemp->child.push_back(pTempChild);
                    pTempChild->parent = pTemp;
                    //��������
                    openTree.push_back(pTempChild);

                }
            }

        }//--end--�ҳ�̽·����Χ8�����е㣬���浽�����б�

        if(openTree.size() == 0) break;

        //�ҳ���ǰ����Χ��Сfֵ���е�
        it = openTree.begin();
        minF_Iter = it;
        //cout<<endl<<"�ڿ����б��еĵ�: ";
        for(it = openTree.begin();it != openTree.end();it++){
            //cout<<(*it)->pos.row<<","<<(*it)->pos.col<<" ";
            if( (*minF_Iter)->pos.f > (*it)->pos.f){
                minF_Iter = it;
            }
        }
        //system("pause");


        //����
        if((*minF_Iter)->pos.row == endPoint.row &&
           (*minF_Iter)->pos.col == endPoint.col
           )
            break;
        pTemp = (*minF_Iter);

        //����߹�
        pathMap[pTemp->pos.row][pTemp->pos.col].isfind = true;

        //����Сfֵ���е������(open_list)��ɾ��
        openTree.erase(minF_Iter);

    }//end--while(1)Ѱ·

    //·������
    MyTreeNode* node_line = (*minF_Iter);
    while(1){
        retPath.push_back(node_line);
        pathMap[node_line->pos.row][node_line->pos.col].isroute = true;
        node_line = node_line->parent;
        if(node_line == NULL) break;
    }
    cout<<endl;

}

void Astar::PrintRoute(){
    float routLength = 0;//·���ܳ���
    cout<<endl<<"route"<<"("<<retPath.size()<<"): ";
    for(it =retPath.begin();it != retPath.end(); it++){
        cout<<(*it)->pos.row<<","<<(*it)->pos.col<<" ";
        //����·�����Ȳ���ӡ
        if(it > retPath.begin()){
            int row_t = (*it)->pos.row,col_t = (*it)->pos.col;//��������
            int row_t_l = (*(it -1) )->pos.row,col_t_l = (*(it -1) )->pos.col;//�ϴ�����
            routLength += sqrt( pow( col_t - col_t_l,2) +pow( (row_t - row_t_l),2) );//pow�η�����
        }
    }
    cout<<endl;
    cout<<"routLength��"<<routLength;
}

void Astar::PrintRouteMap(){

    //��ӡ·�ߵ�ͼ
    cout << endl;
    for(int i=0;i < ROW;i++){
        for(int j=0;j < COL;j++){
            if(pathMap[i][j].isroute)
                cout<<"*";
            else cout<<pathMap[i][j].value;
        }
        cout<<endl;
    }

}
