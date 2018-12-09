#include <iostream>
#include <cstring>
#include <cmath>

// 方法1：负数会出现死循环
// 当负数右移时，并不是简单的把最高位右移，而是要保证移位前是负数，移位后还是负数，因此最高位还是1，所以会出现死循环
int NumberOf1_1(int n)
{
    int count = 0;
    while(n)
    {
        if(n & 1)
            ++count;
        n = n >> 1;
    }
    return count;
}

// 基于方法1改进
int NumberOf1_2(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n & flag)
            ++count;
        flag = flag << 1;
    }
    return count;
}

// 减少循环次数
int NumberOf1_3(int n)
{
    int count = 0;
    while(n)
    {
            ++count;
        n = (n-1) & n;
    }
    return count;
}

int M2N(int m, int n)
{
    int lap = m ^ n;
    int number = NumberOf1_3(lap);
    return number;
}

int Square2(int n)
{
    int count = n & (n-1);
    if(!count)
        return 1;
    else
        return 0;

}

int main(void)
{
    std::cout << M2N(10,13) << std::endl;
    return 0;
}