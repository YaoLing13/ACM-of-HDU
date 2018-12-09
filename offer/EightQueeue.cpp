#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;
//#define N 8
int a[9] = {0};
int cnt = 0;

//位置冲突算法
bool isConflict(int* a, int n)//a[]位置数组，n皇后个数
{
    int i = 0, j =0;
    i=n;
    //for (int i = 2; i <= n ; ++i)
	// {
        for (int j = 1; j <= i-1; ++j) {
            if ((a[i] == a[j]) || (abs(a[i] - a[j]) == i - j)) //1：在一行；2：在对角线上
                return false;
        }
    //}
    return true;
}

//八皇后问题：回溯算法（递归版）
void Queens8(int k, const int& N) //参数k：递归摆放第k个皇后
{
    int i = 0;
    if(k > N) //k>n：即k>8表示最后一个皇后摆放完毕
    {
        cout<<"第"<<++cnt<<"种情况：";
        for (i = 1; i <= N; ++i)
            cout<< a[i];//打印情况
       cout << endl;
    }
    else //8个皇后未全部摆放完毕
    {
        for (i = 1; i <=N ; ++i) //摆放第k个皇后时（转下一行）
        {//依次从列顶端开始搜索，一直到列底端，直到找到合适位置,如果未找到，自动返回上层递归(回溯)
            a[k] = i;
            if(isConflict(a,k))
                Queens8(k+1, N);   //不冲突,递归摆放下一个皇后
        }
    }
    return;
}

//主函数
int main()
{
    Queens8(1, 5);//参数1：表示摆放第1个皇后
    return 0;
}
