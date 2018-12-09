/*
 * HDU ACM 1025
 * 最长递增序列
 * 方法：动态规划+二分法
 * 1950也是同种方法
 */

#include <iostream>
#include <cstring>
#define N 500100
int rich[N];
int ind[N]; // 求X_i的最长子序列时，x_(i-1)的最长子序列

int binary(int len, int m)
{
    int l = 1;
    int r = len;
    int mid;
    while(l <= r)
    {
        mid = (l+r) >> 1;
        if (m >= ind[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}

int main()
{
    int n=0;
    while(scanf("%d",&n)!=EOF) { //n行
        int r,p;
        //初始化2个数组
        memset(rich, 0, sizeof(rich)); //或者memset(rich, 0, sizeof(rich[0]*N))
        memset(ind, 0, sizeof(ind));

        for (int i = 1; i <= n; ++i) {  //下标从1开始
            scanf("%d%d", &r, &p);
            rich[r] = p;
        }
        int len = 1;
        int tmp=0;
        ind[1] = rich[1];
        for (int j = 2; j <= n; ++j) {
            tmp = binary(len, rich[j]);
            ind[tmp] = rich[j];
            if (tmp > len) len++;
        }
        printf("Case %d:\n",++tmp);
        if(len==1) printf("My king, at most 1 road can be built.\n\n");
        else printf("My king, at most %d roads can be built.\n\n",len);
    }
}