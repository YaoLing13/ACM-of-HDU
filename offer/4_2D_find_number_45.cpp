/*
 * 在一个二维数组中，每一行都是从左到右递增，从上到下递增
 * 输入一个二维数组和整数，判断数组中是否含有该整数
4 4
1 2 8 9
2 4 9 12
4 7 10 13
6 8 11 15
 */

#include <iostream>
#include <vector>

bool find_number_1(std::vector<int>& matrix, int row, int col, int number)
{
    // 判断矩阵是否有值
    if(matrix.empty()|| row < 0 || col < 0 || (row == 0 && col == 0))
        return false;

    // 以角点开始查找
    int nrow = 0;
    int ncol = col - 1;
    while (nrow < row && ncol >= 0)
    {
        if (matrix[row*nrow + ncol] == number)
        {
            std::cout << "Row:" << nrow+1 << " Col:" << ncol+1 << std::endl;
            return true;
        }
        else if(matrix[row*nrow + ncol] > number)   // right top > number
        {
            ncol --;
        }
        else    // right top < number
        {
            nrow ++;
        }
    }
    return false;
}

bool find_number_2(std::vector<int>& matrix, int row, int col, int number)
{
    // 判断矩阵是否有值
    if(matrix.empty()|| row < 0 || col < 0 || (row == 0 && col == 0))
        return false;

    // 以左下角为起点开始找
    int nrow = row - 1;
    int ncol = 0;
    while(nrow >=0 && ncol < col)
    {
        if (matrix[row*nrow + ncol] == number)
        {
            std::cout << "Row:" << nrow+1 << " Col:" << ncol+1 << std::endl;
            return true;
        }
        else if(matrix[row*nrow + ncol] < number)
            ncol ++;
        else
            nrow --;
    }
    return false;
}

int main(void)
{
    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::vector<int> input;
    int temp;
    for (int i = 0; i < m*n; ++i) {
        std::cin >> temp;
        input.push_back(temp);
    }

    int aim_number;
    std::cin >> aim_number;

    if(find_number_2(input, n, m, aim_number))
        std::cout << "Find!" << std::endl;
    else
        std::cout << "No find!" << std::endl;
    return 0;
}
