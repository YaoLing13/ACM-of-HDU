/*
 * 一、射线法
       从需要判断的点向任意方向引一条射线，计算与多边形交点的个数，如果是偶数或0，则点在多边形外，如果是奇数，则点在多边形内，若点在多边形的边上，则需要做特殊判断。
二、代码思路
       1、从需要判断的点向x轴负方向引一条射线，判断多边形的每一条边与这条射线是否有交点。需判断的点为point p, 多边形顶点存在vector<point> vPoint中，射线为 y = p.y。
       2、对每一条边的两个顶点分别记为vPoint[i]和vPoint[j]，（vPoint[i].y < p.y && vPoint[j].y >= y） || （vPoint[i].y >= y && vPoint[j].y < y）保证了射线在多边形这条边的y值范围内，vPoint[i].x <= p.x || vPoint[i] <= p.x删掉了一些肯定在需判断的点右边的多边形的边。
       3、vPoint[i]和vPoint[j]这两个顶点构成的边上y = p.y的点的x值可以通过公式x = vPoint[i].x + （y - vPoint[i].y） / （vPoint[j].y - vPoint[i].y） * （vPoint[j].x - vPoint[i].x）计算得.
       4、若计算出的x等于p.x，那么需判断的点就在多边形的边上；若计算出的x小于p.x，说明多边形的边在需判断的点的左边，该点引出的射线与多边形的边有交点；若大于，则没有交点。
       5、用bool值变量inside来进行异或操作，每有一个交点，值就发生变化。
 */

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef struct point
{
    double x, y;
};
int count;  //与多边形交点个数
//判断点是否在多边形内（以该点为起点沿x轴负方向做一条射线）
bool isPointInPolygon(point p, vector<point> vPoint)
{
    int i, j = vPoint.size() - 1;
    bool inside = false;
    double x = p.x;
    double y = p.y;
    for(i = 0; i < vPoint.size(); i++)
    {
        if(((vPoint[i].y < y && vPoint[j].y >= y) || (vPoint[i].y >= y && vPoint[j].y < y)) && (vPoint[i].x <= x || vPoint[j].x <= x))
        {
            double dTmp = vPoint[i].x + (y - vPoint[i].y) / (vPoint[j].y - vPoint[i].y) * (vPoint[j].x - vPoint[i].x);
            bool bTmp;
            if(dTmp == x)  //点在多边形的边上，也算在多边形内
            {
                count = 1;
                return true;
            }
            else
                bTmp = (dTmp < x);
            inside ^= bTmp;
            if(bTmp)
                count++;
        }
        j = i;
    }
    return inside;
}
int main()
{
    int n, i;
    point p;
    vector<point> vPoint;
    scanf("%d", &n);  //输入多边形点的个数
    for(i = 0; i < n; i++)
    {
        scanf("%lf %lf", &p.x, &p.y);  //输入多边形的顶点
        vPoint.push_back(p);
    }
    scanf("%lf %lf", &p.x, &p.y);  //输入需要判断的点
    count = 0;
    if(isPointInPolygon(p, vPoint))
        printf("Yes！\n");
    else
        printf("No!\n");
    printf("%d\n", count);  //输出与多边形交点的个数
    return 0;
}