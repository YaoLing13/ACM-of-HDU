#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <stack>

#define random(x) (rand()%x)


int basicIndex_right(std::vector<int>& input, int left, int right) {
    int temp = right;
    while (left < right) {
        while (left < right && input[left] <= input[temp])
            ++left;
        while (left < right && input[right] >= input[temp])
            --right;
        std::swap(input[left], input[right]);
    }
    std::swap(input[left], input[temp]);
    return left;
}

int basicIndex(std::vector<int>& input, int left, int right)
{
    // 三数取中法
    int temp;   //取最右边的数作为基准
    int mid = (left + right) >> 1;
    if(input[left] > input[right])  // left > right
    {
        if(input[left] > input[mid])    //left max
            temp = input[right] > input[mid] ? right : mid;
        else //mid max
            temp = left;
    }
    else  // right > left
    {
        if(input[right] > input[mid])   // right max
            temp = input[left] > input[mid] ? left : mid;
        else //mid max
            temp = right;
    }

    if(temp != right)
        std::swap(input[temp], input[right]);
    temp = right;
    while (left < right)
    {
        while (left < right && input[left] <= input[temp])
            ++left;
        while (left < right && input[right] >= input[temp])
            --right;
        std::swap(input[left], input[right]);
    }
    std::swap(input[right], input[temp]);
    return right;
}

int basicIndex_left(std::vector<int>& input, int left, int right)
{
    //int temp = left;    // 去最左侧数作为基准
    int temp;   //取最右边的数作为基准
    int mid = (left + right) >> 1;
    if(input[left] > input[right])  // left > right
    {
        if(input[left] > input[mid])    //left max
            temp = input[right] > input[mid] ? right : mid;
        else //mid max
            temp = left;
    }
    else  // right > left
    {
        if(input[right] > input[mid])   // right max
            temp = input[left] > input[mid] ? left : mid;
        else //mid max
            temp = right;
    }

    if(temp != left)
        std::swap(input[temp], input[left]);
    temp = left;
    while (left < right)
    {
        while (left < right && input[left] <= input[temp])
            ++left;
        while (left < right && input[right] >= input[temp])
            --right;
        std::swap(input[left], input[right]);
    }
    std::swap(input[left], input[temp]);
    return left;
}

std::vector<int> QuickSort(std::vector<int>& input, int left, int right)
{
    if(input.empty())
    {
        throw std::range_error("No element in vector");
    }

    if(left >= right)//表示已经完成一个组
    {
        return input;
    }

    int basicindex = basicIndex_right(input, left, right);
    input = QuickSort(input, left, basicindex-1);
    input = QuickSort(input, basicindex+1, right);

    return input;
}


std::vector<int> QuickSortStack(std::vector<int>& input, int left, int right)
{
    std::stack<int> s;
    s.push(left);
    s.push(right);
    while (!s.empty())
    {
        int right = s.top();    // 一次弹出一个子序列
        s.pop();
        int left = s.top();
        s.pop();

        int index = basicIndex_right(input, left, right);
        if((index - 1) > left)  // 左序列
        {
            s.push(left);
            s.push(index - 1);
        }
        if((index + 1) < right) // 右序列
        {
            s.push(index + 1);
            s.push(right);
        }
    }
    return input;
}

void QuickSortNotR(std::vector<int>& input, int left, int right)
{
    std::stack<int> s;
    s.push(left);
    s.push(right);//后入的right，所以要先拿right
    while(!s.empty())//栈不为空
    {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();

        int index = basicIndex_right(input,left,right);
        if((index - 1) > left)//左子序列
        {
            s.push(left);
            s.push(index - 1);
        }
        if(((index) + 1) < right)//右子序列
        {
            s.push(index + 1);
            s.push(right);
        }
    }
}

int main(void)
{
    std::vector<int> input;
    for (int i = 0; i < 10; ++i) {
        input.push_back(random(100));
    }

    std::cout << "Input : " ;
    for (int j = 0; j < input.size(); ++j) {
        std::cout << input[j] << " ";
    }
    std::cout << std::endl;

    std::vector<int> result = QuickSortStack(input, 0, input.size()-1);
    std::cout << "Output: " ;
    for (int j = 0; j < result.size(); ++j) {
        std::cout << result[j] << " ";
    }
//    std::cout << "Output: " ;
//    QuickSortNotR(input, 0, input.size()-1);
//    for (int j = 0; j < input.size(); ++j) {
//        std::cout << input[j] << " ";
//    }

    std::cout << std::endl;
    return 0;
}
