/*
HDU1069Monkey and Banana
题目：给出一些长方体，然后让你把他堆成塔，
要求下面的塔的要比上面的塔大（长和宽），
而且每一种长方体的数量都是无限的。

此题目考察到动态规划里的最长有序子序列，

*/
#include<stdio.h>
#include<algorithm>
const int MAXN=200;
using namespace std;
struct Block
{
    int x,y,high;
    int dp;//该箱子在最下面时的最大高度
}b[MAXN];

bool cmp(Block a,Block b)//用sort函数排序，先按x后按y升序
{
    if(a.x<b.x) return 1;
    else if(a.x==b.x&&a.y<b.y)  return 1;
    else return 0;
}
int main()
{
    int n,i,x,y,z,j,k;
    int iCase=0;
    while(scanf("%d",&n),n)
    {
        iCase++;
        k=0;
        while(n--)
        {
            scanf("%d%d%d",&x,&y,&z);
            //把给出的block放置的所有可能放进block[]中，这样就可以解决有无限块的问题
            if(x==y)
            {
                if(y==z)//三个相等，放一个就够了
                {
                    b[k].x=x;b[k].y=y;b[k].high=z;b[k].dp=b[k].high;k++;
                }
                else  //x==y!=z时三种放法
                {
                    b[k].x=x;b[k].y=y;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=z;b[k].y=y;b[k].high=x;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=z;b[k].high=x;b[k].dp=b[k].high;k++;
                }
            }
            else
            {
                if(y==z)//三种放法
                {
                    b[k].x=x;b[k].y=y;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=x;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=z;b[k].high=x;b[k].dp=b[k].high;k++;
                }
                else if(x==z)
                {
                    b[k].x=x;b[k].y=y;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=x;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=x;b[k].y=z;b[k].high=y;b[k].dp=b[k].high;k++;
                }
                else//三个不等6种放法
                {
                    b[k].x=x;b[k].y=y;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=x;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=x;b[k].y=z;b[k].high=y;b[k].dp=b[k].high;k++;
                    b[k].x=z;b[k].y=x;b[k].high=y;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=z;b[k].high=x;b[k].dp=b[k].high;k++;
                    b[k].x=z;b[k].y=y;b[k].high=x;b[k].dp=b[k].high;k++;
                }
            }
        }
        sort(b,b+k,cmp);
        int maxh=0;
        for(i=1;i<k;i++)
        {
            for(j=0;j<i;j++)
                if(b[i].x>b[j].x&&b[i].y>b[j].y)
                    b[i].dp=max(b[j].dp+b[i].high,b[i].dp);
            if(b[i].dp>maxh)maxh=b[i].dp;
        }
        printf("Case %d: maximum height = %d\n",iCase,maxh);
    }
    return 0;
}