#include <iostream>

#define UNUSED(x) (void)x

bool g_InvalidInput = false;

// method 1
double PowerWithUnsignedExponent_1(double base, unsigned int exponent)
{
    double result = 1.0;
    for(int i=1; i <= exponent; ++i)
    {
        result *= base;
    }

    return result;
}

// method 2
double PowerWithUnsignedExponent_2(double base, unsigned int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent_2(base, exponent >> 1);
    result *= result;
    if(exponent&0x1 != 0)
        result *= base;
    return result;
}


double Power(double base, int exponent)
{
    g_InvalidInput = false;
    if(base==0.0 && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);

    double result = PowerWithUnsignedExponent_2(base, absExponent);
    if(exponent < 0)
        result = 1.0/result;

    return result;
}

int main(int argc, char ** argv)
{
    UNUSED(argv);
    UNUSED(argc);
    std::cout << "Power(3,-3): " << Power(3,-3) << std::endl;
    std::cout << "Power(3, 3): " << Power(3, 3) << std::endl;
}
