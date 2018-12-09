#include <iostream>

long sumNumberRecursive(long n)
{
    if(n == 1)
        return 1;
    else
        return sumNumberRecursive(n-1)+n;
}

long sumNumberCircle(long n)
{
    int sumValue = 0;
    while (n>0)
    {
        sumValue += n;
        --n;
    }
    return sumValue;
}

int main(void)
{
    //std::cout<< "Recursive:" << sumNumberRecursive(500000) << std::endl;  // 内存溢出
    std::cout<< "Circle   :" << sumNumberCircle(500000) << std::endl;
    return 0;
}