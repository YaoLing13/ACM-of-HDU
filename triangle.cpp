/*
 * Title: 动态规划之三角形求解
 * URL: https://blog.csdn.net/a45872055555/article/details/29427929
 * method: DP
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;
    int number[n][n];   // 存入三角形数据
    memset(number, 0, sizeof(number));  // init

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> number[i][j];
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0)
                number[i][j] = number[i-1][j] + number[i][j];
            else
                number[i][j] = max(number[i-1][j], number[i-1][j-1]) + number[i][j] ;
        }
    }

    int temp = 0;
    for (int k = 0; k < n; ++k) {
        temp = max(temp, number[n-1][k]);
    }
    cout << "Max Value: " << temp << endl;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout << number[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 1;
}