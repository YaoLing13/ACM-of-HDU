#include <iostream>
#include <exception>
#include <stdexcept>

/*
 * 函数: 计算数值的整数次方
 * 输入: 基数base,指数exponent(>0,<0,=0)
 * 输出: base的exponent次方
 */
double Power(double base, int exponent)
{
    if (base == 0)
        throw std::logic_error("Can't compute exponent of zero!!!");
    if(exponent == 0)
        return 1.0;

    if(exponent > 0)
    {
        double result_value = 1.0;
        for (int i = 0; i < exponent; ++i) {
            result_value *= base;
        }
        return result_value;
    }
    if(exponent < 0)
    {
        double result_value = 1.0;
        for (int i = 0; i < abs(exponent); ++i) {
            result_value *= base;
        }
        return 1/result_value;
    }
}

int main()
{
    std::cout << "Power(2,-5): " << Power(2,-5) << std::endl;
    std::cout << "Power(2, 5): " << Power(2, 5) << std::endl;
    return 0;
}