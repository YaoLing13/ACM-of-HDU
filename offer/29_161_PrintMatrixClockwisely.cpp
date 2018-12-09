
/*
 * 题目: 输入一个矩阵,按照从外向里以顺时针的顺序一次打印每一个和数字
 */

#include <iostream>
#include <cstring>
#include <cmath>

void printNumber(int number)
{
    printf("%d\t", number);
}

void PrintMatrixIncircle(int** numbers, int columns, int rows, int start)
{
    int endX = columns - 1 -start;
    int endY = rows - 1 - start;

    //从左到右打印一行
    for (int i = start; i <= endX ; ++i) {
        int number = numbers[start][i];
        printNumber(number);
    }

    //从上到下打印一列
    if(start < endY)
    {
        for (int i = start+1; i <= endY; ++i) {
            int number = numbers[i][endX];
            printNumber(number);
        }
    }

    //从右到左打印一行
    if(start < endX && start < endY)
    {
        for (int i = endX - 1; i >= start ; --i) {
            int number = numbers[endY][i];
            printNumber(number);
        }
    }

    // 从下到上打印一列
    if(start < endX && start < endY - 1)
    {
        for (int i = endY - 1; i >= start+1 ; --i) {
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
    if(numbers == nullptr || columns <= 0 || rows <= 0)
        return;

    int start = 0; //相当于 第几圈+1

    while(columns > start * 2 && rows > start * 2)
    {
        PrintMatrixIncircle(numbers, columns, rows, start);
        ++start;
    }
}


void loopMatrixCore(int* &numbers, int cols, int rows, int start, int& number)
{
    int endX = cols - 1 - start;    //本圈的endX
    int endY = rows - 1 - start;    //本圈的endY

    //从左往右打印
    for (int i = start; i <= endX ; ++i) {

    }


}

int* loopMatrix(int cols, int rows)
{
    int* numbers = new int[cols*rows];
    memset(numbers, 0, cols*rows);
    int start = 0;
    int number = 1;
    while(cols > start*2 && rows > start*2)
    {

        ++start; //新一圈的开始位置
    }

}

// ====================Test====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintMatrixClockwisely(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}

int main(int argc, char* argv[])
{
    /*
    1
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}