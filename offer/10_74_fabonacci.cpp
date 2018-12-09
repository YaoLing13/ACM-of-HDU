#include <iostream>
#include <vector>
#include <cassert>

// 糟糕的方法 O(2^(N/2))<=T(N)<=O(2^N)
long fabonacciRecursive(int n)
{
    return n > 1 ? (fabonacciRecursive(n-1) + fabonacciRecursive(n - 2)) : n;
}

// O(N)
long fabonacciCircle(int n)
{
    std::vector<long> temp;
    temp.push_back(0);
    temp.push_back(1);
    long count = 2;
    while (n >= count)
    {
        temp.push_back(temp[count-1] + temp[count-2]);
        count ++;
    }
    return temp[n];
}

struct Matrix2By2
{
    Matrix2By2(long long m00 = 0, long long m01 = 0, long long m10 = 0, long long m11 = 0)
            : m_00(m00), m_01(m01), m_10(m10), m_11(m11)
    {}

    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

Matrix2By2 MatrixMultiply(const Matrix2By2& matrix1, const Matrix2By2& matrix2)
{
    return Matrix2By2(
            matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
            matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
            matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
            matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n)
{
    assert(n > 0);

    Matrix2By2 matrix;
    if(n == 1)
    {
        matrix = Matrix2By2(1, 1, 1, 0);
    }
    else if(n % 2 == 0)
    {
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    }
    else if(n % 2 == 1)
    {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }

    return matrix;
}



// O(logN)
long long fabonacciMatrix(int n)
{
    if(n < 2)
        return std::max(0, n);

    Matrix2By2 powerNumber = MatrixPower(n-1);
    return powerNumber.m_00;
}

int main(void)
{
    std::cout << "Recursive:" << fabonacciRecursive(3) << std::endl;
    std::cout << "Circle   :" << fabonacciCircle(3) << std::endl;
    std::cout << "Matrix   :" << fabonacciMatrix(3) << std::endl;
    return 0;
}