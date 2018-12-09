#include <iostream>
#include <vector>
#include <stdexcept>

#define random(x) (rand()%x)

/**** 归并排序 ****/

// 1 递归方法
void Merge(std::vector<int>& input, std::vector<int>& reg, int left,int right)
{
    if(left>=right)
        return;

    int mid = left + ((right - left) >> 1);

    // 归（分）
    Merge(input, reg, left, mid);
    Merge(input, reg, mid+1, right);

    // 并
    int i=left,j=mid + 1;
    int k=left;
    // 将2个序列的元素分布进行比较
    while (i <= mid && j<=right)
        reg[k++] = input[i] > input[j] ? input[j++] : input[i++];

    // 左序列数据没有用完
    while (i <= mid)
        reg[k++] = input[i++];
    // 右序列没有用完
    while (j <= right)
        reg[k++] = input[j++];


    // 赋值给input
    for (int l = left; l <= right; ++l) {
        input[l] = reg[l];
    }
}
std::vector<int> MergeSort_Recursive(std::vector<int>& input)
{
    std::vector<int> reg(input.size());
    Merge(input, reg, 0, input.size()-1);
    return input;
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

    std::vector<int> result = MergeSort_Recursive(input);
    std::cout << "Output: " ;
    for (int j = 0; j < result.size(); ++j) {
        std::cout << result[j] << " ";
    }

    std::cout << std::endl;
    return 0;
}