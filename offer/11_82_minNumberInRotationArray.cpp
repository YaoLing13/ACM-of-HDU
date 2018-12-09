#include <iostream>
#include <vector>

int MinNuberInRotationArray(int* input, int start, int end)
{
    int mid = start;
    while(end-start > 1)
    {
        mid = start + ((end-start) >> 1);
        if(input[mid] <= input[start])
            end = mid;
        else if(input[mid] >= input[start])
            start = mid;
        MinNuberInRotationArray(input, start, end);
    }
    return input[mid];
}

int Min(int* input, int length)
{
    if(input == nullptr || length <= 0)
        throw std::logic_error("Invalid parameters");
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while (input[index1] >= input[index2])  //end <= start 恒成立
    {
        if(index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;
        if (input[indexMid] >= input[index1])
            index1 = indexMid;
        else if(input[indexMid] <= input[index2])
            index2 = indexMid;
    }
    return input[indexMid];
}


int MinInOrder(int* input, int index1, int index2)
{
    int result = input[index1];
    for (int i = index1+1; i <= index2; ++i) {
        if(result > input[i])
            result = input[i];
    }
    return result;
}

// 改进版:考虑 a[start] = a[mid] = a[end]的情况，这时候需要用顺序查找的方法
int Min_final(int* input, int length)
{
    if(input == nullptr || length <= 0)
        throw std::logic_error("Invalid parameters");
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while (input[index1] >= input[index2])  //end <= start 恒成立
    {
        if(index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;

        // 想的
        if(input[index1] == input[index2] && input[index1] == input[indexMid])
            return MinInOrder(input, index1, index2);

        if (input[indexMid] >= input[index1])
            index1 = indexMid;
        else if(input[indexMid] <= input[index2])
            index2 = indexMid;
    }
    return input[indexMid];
}



int main(void)
{
    int input[] = {1,2,3};
    int length = sizeof(input)/sizeof(input[0]);
    int minValue1 = MinNuberInRotationArray(input, 0, length-1);
    std::cout << "Recuise:" << minValue1 << std::endl;
    int minValue = Min(input, length-1);
    std::cout << "While  : " << minValue << std::endl;
    return 0;
}