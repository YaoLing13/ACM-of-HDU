/*
 * Discribe: half search
 * Author: Yao Ling
 * Time: 2018-08-01
 */

#include <iostream>
#include <algorithm>

//// 降序
//bool compare(int a, int b)
//{
//    return a>b;
//}

// 对数组的引用，对：int num[2] = {1,2}这种数组才可用，对int* num = new int[n]不可用
//template <typename T, int N>
//int half_search1(T (&input)[N], int x)
//{
//    std::cout << "Test" << std::endl;
//    for (int i = 0; i < N; ++i) {
//        std::cout << input[i] << " ";
//    }
//    std::cout << std::endl;
//}

// 版本一
// 结果： 找到中间偏前一个目标值
int half_search1(int* input, int l, int r, int x)
{
    int number = 0;
    int mid = (l+r)>>1;  // 中间
    if (input[mid] == x)
        number = mid;
    else if (input[mid] > x && mid > l)
        number = half_search1(input, l, mid-1, x);
    else if (input[mid] < x && mid < r)
        number = half_search1(input, mid+1, r, x);
    else
        number = -1;
    return number;
}

// 版本二： Fibonacci
// 思路：调整前、后区域的宽度，适当地加长(缩短)前（后）子向量
// 结果： 找到中间偏后一个目标值
int half_search2(int* input, int l, int r, int x)
{
    int number = 0;
    int mid = int((l+r)*0.618);  // 黄金比例切分向量
    if (input[mid] == x)
        number = mid;
    else if (input[mid] > x && mid > l)
        number = half_search2(input, l, mid-1, x);
    else if (input[mid] < x && mid < r)
        number = half_search2(input, mid+1, r, x);
    else
        number = -1;
    return number;
}

// 版本三
// 思路：统一沿两个方向深入所需要执行的比较次数，比如都统一为一次
// 结果： 找到最后一个目标值
int half_search3(int* input, int l, int r, int x)
{
    while((r-l) > 1)
    {
        int mid = (l + r) >> 1;
        (x < input[mid]) ? r=mid : l=mid;
    }
    return (x == input[l]) ? l : -1;
}

// 版本四
// 思路：统一沿两个方向深入所需要执行的比较次数，比如都统一为一次
// 结果： 找到第一个目标值
int half_search4(int* input, int l, int r, int x)
{
    while((r-l) > 1)
    {
        int mid = (l + r) >> 1;
        (x > input[mid]) ? l=mid : r=mid;
    }
    return (x == input[l]) ? l : -1;
}

// 版本五
// 思路：
// 结果:
int half_search5(int* input, int l, int r, const int& x)
{
    while(l < r)
    {
        int mid = (l + r) >> 1;
        (x < input[mid]) ? r=mid : l=mid+1;
    }
    return --l;
}


int main(int argc, char ** argv)
{
    int n = 0;
    std::cin >> n;
    if (!n)
        return -1;

    int aimNumber = 0;
    std::cin >> aimNumber;
    int* input = new int[n-1];
    // input array
    for (int i = 0; i < n; ++i) {
        std::cin >> input[i];
    }

    std::sort(input, input+n);  //默认为升序
    //std::sort(input, input+n, compare);   //降序
    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;

    int num = 0;

    // Way 1
    num = half_search1(input, 0, n-1, aimNumber);
    if (num < 0)
        std::cout << "way1: No element in array !!!"<< std::endl;
    else
        std::cout << "way1: " << num+1 << std::endl;

    // Way 2
    num = half_search2(input, 0, n-1, aimNumber);
    if (num < 0)
        std::cout << "way2: No element in array !!!"<< std::endl;
    else
        std::cout << "way2: " << num+1 << std::endl;

    // Way 3
    num = half_search3(input, 0, n-1, aimNumber);
    if (num < 0)
        std::cout << "way3: No element in array !!!"<< std::endl;
    else
        std::cout << "way3: " << num+1 << std::endl;

    // Way 4
    num = half_search4(input, 0, n-1, aimNumber);
    if (num < 0)
        std::cout << "way4: No element in array !!!"<< std::endl;
    else
        std::cout << "way4: " << num+1 << std::endl;

    // Way 5
    num = half_search5(input, 0, n-1, aimNumber);
    if (num < 0)
        std::cout << "way5: No element in array !!!"<< std::endl;
    else
        std::cout << "way5: " << num+1 << std::endl;

    return 1;
}
