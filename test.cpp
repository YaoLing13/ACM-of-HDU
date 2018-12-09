#include "string.h"
#include <iostream>
#include "queue.h"
using namespace std;

struct Pos
{
    int x;
    int y;
};

queue::queue<Pos> posqueue;

int main(void)
{

    Pos tem;
    tem.x = 1;
    tem.y = 1;
    posqueue.push(tem);


    tem.x = 2;
    tem.y = 2;
    posqueue.push(tem);
    tem.x = 3;
    tem.y = 3;
    posqueue.push(tem);
    tem.x = 4;
    tem.y = 4;
    posqueue.push(tem);
    tem.x = 5;
    tem.y = 5;
    posqueue.push(tem);
    cout << "queue size: " << posqueue.len << endl;

    tem = posqueue.pop();
    tem = posqueue.pop();
    tem = posqueue.pop();
    tem = posqueue.pop();
    tem = posqueue.pop();
    cout << "queue size: " << posqueue.len << endl;
    cout << "tem data: x-" << tem.x << " y-" << tem.y << endl;
    tem = posqueue.pop();
    return 0;
}

//struct PointPos
//{
//    int point_ix;
//    int point_iy;
//    int point_iz;
//};
//
//void show(int &xx, int &yy)
//{
//    PointPos pointpos[xx][yy];
//    memset(pointpos, 0, sizeof(pointpos));
//    for (int i = 0; i < xx; ++i) {
//        for (int j = 0; j < yy; ++j) {
//            std::cout << pointpos[i][j].point_ix << "_" << pointpos[i][j].point_iy << "_" << pointpos[i][j].point_iz << "  ";
//        }
//        std::cout << std::endl;
//    }
//}
//
//int main(void)
//{
//    int ixx = 60;
//    int iyy = 80;
//    show(ixx, iyy);
//    return 0;
//}