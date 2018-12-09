#include <iostream>
#include <vector>
#include <map>

int coutCore(std::vector<long long> vecdata)
{
    int num = 0;
    for (int i = 0; i < vecdata.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (vecdata[i] > vecdata[j])
                num += 1;
        }
        for (int j = i+1; j < vecdata.size(); ++j) {
            if(vecdata[i] < vecdata[j])
                num +=1;
        }
    }
    return num;
}

void count(std::vector<long long> vecdata)
{
    int index = 0;
    long long min_cout = 1000000000 ;
    int temp;
    for (int i = 0; i < vecdata.size(); ++i) {
        temp = vecdata[i];
        vecdata[i] = 0;
        if(coutCore(vecdata)<min_cout)
        {
            min_cout = coutCore(vecdata);
            index = i;
        }
        vecdata[i] = temp;

    }
    std::cout << index << " " << min_cout << std::endl;
}

int main(void)
{
    int n;
    std::cin >> n;
    while (n<=0)
        std::cin >> n;

    std::vector<long long> vecdata;
    vecdata.resize(0);
    long long m;
    for (int i = 0; i < n; ++i) {
        std::cin >> m;
        vecdata.push_back(m);
    }
    count(vecdata);
    return 0;
}

/*
void value(int* input, int n)
{
    int* visited = new int[n];
    memset(visited, 0, n);
    int t;
    int x;
    int count_baoxiangguai = 0;
    int baoxiang = 0;
    int putongbox = 0;
    for (int i = 1; i <= n; ++i) {
        t = input[2*i-1];
        x = input[2*i];

        if(i == 1)  //第一个可能是宝箱怪也可能是普通的
        {
            count_baoxiangguai += 1;
            visited[i] = 1; //可能是宝箱怪也可能是普通的
            count_baoxiangguai += 1;
            visited[x] = 1; //第x可能是宝箱怪也可能是普通的
        }
        else
        {
            if(visited[i] == 1)
            {
                count_baoxiangguai += 1;
                visited[x] = 1; //第x可能是宝箱怪也可能是普通的
            }
            else
            {
                if(t == 1)
                {
                    baoxiang += 1;
                    visited[x] = 2;
                }
                if(t == 2)
                {
                    putongbox += 1;
                    visited[x] = 3;
                }

            }
        }

    }
    if(count_baoxiangguai == n)
    {
        std::cout << 0 << " " << 1 << std::endl;
        return;
    }
    else
    {
        std::cout << putongbox << " " << baoxiang << std::endl;
        return;
    }

}

int main(void)
{
    int n;
    std::cin >> n;
    if(n<=0)
        return 0;
    int* input = new int[2*n+1];
    input[0] = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> input[2*i-1];
        std::cin >> input[2*i];
    }

    value(input, n);
    return 0;
}
 */