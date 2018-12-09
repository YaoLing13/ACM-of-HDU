#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
    int N = 0;
    int M = 0;
    cin >> N;
    cin >> M;

    int map[M+1][M+1];
    int result[M+1][M+1];
    memset(map, 0, sizeof(map));
    memset(result, 0, sizeof(result));
    for (int i = 1; i < M+1; ++i) {
        for (int j = 1; j < M+1; ++j) {
            cin >> map[i][j];
        }
    }

    int minvalue = 100000;
    for (int i = 1; i < M+1; ++i) {
        minvalue = 100000;
        for (int j = 0; j < M+1; ++j) {
            if (i != j)
            {
                minvalue = min(minvalue, map[i][j]+ minvalue);
                map[i][j] = minvalue;
            }
        }
    }


    //output
    for (int i = 1; i < M+1; ++i) {
        for (int j = 1; j < M+1; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

}

///*
// * Title: 动态规划之钢条切割问题
// * URL: https://blog.csdn.net/a45872055555/article/details/29428507
// * method: DP
// */
//
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//int main(void) {
//    int n = 0;
//    cin >> n;
//
//    int money_value[n+1];
//    memset(money_value, 0, sizeof(money_value));
//    int pi[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
//
//    for (int i = 1; i <= n; ++i) {
//        int profit = 0;
//        for (int j = 1; j <=i ; ++j) {
//            if (j<11)
//                profit=max(profit, pi[j] + money_value[i-j]);
//        }
//        money_value[i] = profit;
//    }
//    cout << money_value[n] << endl;
//    return 1;
//}