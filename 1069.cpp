/*
 * Title: HDU ACM 1069
 * URL: http://acm.hdu.edu.cn/showproblem.php?pid=1069
 * method: DP 最大单减序列
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 200;

struct Block
{
    int x, y, high;
    int dp; //表示该箱子在最下面时的最大高度
}b[MAXN];   //相当于定义一个这种类型的数组

int cmp(Block a, Block b)
{
    if(a.x > b.x)
        return 1;
    else if(a.x==b.x && a.y>b.y)
        return 1;
    else
        return 0;
}

int main(void) {
    int n;
    int k, i, j, x, y, z;
    int iCase = 0;
    while (scanf("%d", &n) && n) {
        iCase ++;
        int k = 0;
        while(n--) {
            scanf("%d%d%d",&x,&y,&z);
            //把给出的block放置的所有可能放进block[]中，这样就可以解决有无限块的问题
            if(x == y) {
                if(y == z) { //3边相同
                    b[k].x = x; b[k].y = y; b[k].high = z; b[k].dp = b[k].high; k++;
                 }
                else { // x=y != z
                    b[k].x = x; b[k].y = y; b[k].high = z; b[k].dp = b[k].high; k++;
                    b[k].x = x; b[k].y = z; b[k].high = y; b[k].dp = b[k].high; k++;
                    b[k].x = z; b[k].y = y; b[k].high = x; b[k].dp = b[k].high; k++;
                }
            }
            else {
                if(y==z) { //三种放法
                    b[k].x=x;b[k].y=y;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=x;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=z;b[k].high=x;b[k].dp=b[k].high;k++;
                }
                else if(x==z) {
                    b[k].x=x;b[k].y=y;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=x;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=x;b[k].y=z;b[k].high=y;b[k].dp=b[k].high;k++;
                }
                else { //三个不等6种放法
                    b[k].x=x;b[k].y=y;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=x;b[k].high=z;b[k].dp=b[k].high;k++;
                    b[k].x=x;b[k].y=z;b[k].high=y;b[k].dp=b[k].high;k++;
                    b[k].x=z;b[k].y=x;b[k].high=y;b[k].dp=b[k].high;k++;
                    b[k].x=y;b[k].y=z;b[k].high=x;b[k].dp=b[k].high;k++;
                    b[k].x=z;b[k].y=y;b[k].high=x;b[k].dp=b[k].high;k++;
                }
            }
        }
        // DP
        // 1)先由大到小排个序
        sort(b, b+k, cmp);
        // 2)进行动态规划
        // 对于每个block，从后往前
        int max_height = 0;
        for (int l = 1; l < k; ++l) {
            for (int m = l-1; m >= 0; --m) {
                if(b[l].x < b[m].x && b[l].y < b[m].y)
                    b[l].dp = max(b[m].dp + b[l].high, b[l].dp);    //对于一个block,保留之前多个block相连的最大的
            }
            if (b[l].dp > max_height)
                max_height = b[l].dp;
        }

        printf("Case %d: maximum height = %d\n", iCase, max_height);
    }
    return 1;
}