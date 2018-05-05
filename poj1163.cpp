/*
 * https://blog.csdn.net/baidu_28312631/article/details/47418773
 */

/*
 * 方法:递归
 * 时间复杂度:2^n
 * 空间复杂度: n(1+2n)/2
 */
//#include <iostream>
//#include <algorithm>
//#define MAX 101
//using namespace std;
//
//int D[MAX][MAX];
//int n;
//int MaxSum(int i, int j)
//{
//    if(i== n)
//        return D[i][j]; //i行j列
//    int x = MaxSum(i+1, j);
//    int y = MaxSum(i+1, j+1);
//    return max(x, y) + D[i][j];
//}
//
//int main(int argc, char ** argv)
//{
//    int i,j;
//    cin >> n;
//    for(i=1;i<=n;i++)
//        for(j=1;j<=i;j++)
//            cin >> D[i][j];
//    cout << MaxSum(1,1) << endl;
//}


/*
 * 方法:动态规划(递归)
 * 时间复杂度: n(n+1)/2
 * 空间复杂度: n(1+2n)/2
 */
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define MAX 101
//
//int D[MAX][MAX];
//int n;
//int maxSum[MAX][MAX];
//
//int MaxSum(int i, int j)
//{
//    if (maxSum[i][j] != -1)
//        return maxSum[i][j];
//    if (i == n)
//        maxSum[i][j] = D[i][j];
//    else
//    {
//        int x = MaxSum(i + 1, j);
//        int y = MaxSum(i+1, j+1);
//        maxSum[i][j]=max(x,y) + D[i][j];
//    }
//    return maxSum[i][j];
//}
//
//int main(int argc, char ** argv)
//{
//    int i,j;
//    cin >> n;
//    for (int i = 1; i <= n  ; ++i) {
//        for (int j = 0; j <= i ; ++j) {
//            cin >> D[i][j];
//            maxSum[i][j] = -1;  //初始化maxSum矩阵
//        }
//    }
//
//    cout << MaxSum(1,1) << endl;
//}

/*
 * 方法: 动态规划(递推)
 * 时间复杂度: n(n-1)/2
 * 空间复杂度: n*n
 */
//#include <iostream>
//#include <algorithm>
//using  namespace std;
//#define MAX 101
//
//int main(int argc, char ** argv)
//{
//    int D[MAX][MAX];
//    int n;
//    int i,j;
//    cin >> n;
//    int maxSum[n+1][n+1];
//    for (i = 1; i <= n; ++i) {
//        for (j = 1; j <= i; ++j) {
//            cin >> D[i][j];
//            maxSum[i][j] = 0;
//        }
//    }
//    for (j=1; j<=n; ++j)
//        maxSum[n][j] = D[n][j];
//    for (i = n-1; i >= 1; --i)
//        for (j = 1; j <= i; ++j)
//            maxSum[i][j] = D[i][j] + max(maxSum[i+1][j], maxSum[i+1][j+1]);
//
//    cout << maxSum[1][1] << endl;
//}

/*
 * 方法: 动态规划(递推)
 * 时间复杂度: n(n-1)/2
 * 空间复杂度:n
 */
#include <iostream>
#include <algorithm>
using  namespace std;
#define MAX 101

int main(int argc, char ** argv)
{
    int D[MAX][MAX];
    int n;
    int i,j;
    int *maxSum;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= i; ++j) {
            cin >> D[i][j];
        }
    }
    maxSum = D[n];  //maxSum指向第n行
    for (i = n-1; i >= 1; --i)
        for (j = 1; j <= i; ++j)
            maxSum[j] = D[i][j] + max(maxSum[j], maxSum[j+1]);
    cout << maxSum[1] << endl;
}