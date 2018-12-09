/*
 * 埃拉托斯特尼筛法: 要得到自然数n以内的全部素数，
 *               必须把 小于等于根号n 的所有素数的倍数剔除，剩下的就是素数.
 * 使用 std::set 实现.
 */

#include <iostream>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

void SelectPrimeNumber( int n)
{
    if(n <= 1)
        return;
    set<int> s;
    s.erase(s.begin(), s.end());    // 清空

    for (int j = 2; j <= n ; ++j) {
        s.insert(j);
    }

    int m;
    for (int i = 2; i <= sqrt(n) ; ++i) {   // 2-sqrt(n)
        if(s.find(i) != s.end())
        {
            m= 2*i; //m是i的倍数
            while(m <= n)
            {
                s.erase(m);
                m += i; //更新m,使之成为下一个m的倍数
            }
        }
    }

    set<int>::iterator iter;
    iter = s.begin();
    int count = 0;
    while(iter != s.end())
    {
        count ++ ;
        cout << setw(5) << *iter;
        iter ++;
        if(count % 10 == 0)
            cout << endl;
    }
    cout << endl;
    return;
}

int main()
{
    SelectPrimeNumber(300);
}

