#include <iostream>
#include <cstring>
#include <cmath>
int CutLine(int length)
{
    if(length <= 0)
        return 0;
    if(length == 1)
        return 1;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    // length flag
    int* legth_array = new int[length+1];
    std::memset(legth_array, 0, length+1);

    legth_array[1] = 1;
    legth_array[2] = 2;
    legth_array[3] = 3;

    int max_value = 0;
    for (int i = 4; i < length+1; ++i) {
        max_value = 0;
        for (int j = 1; j <= i/2; ++j) {
            max_value = std::max(max_value, legth_array[j]*legth_array[i-j]);
        }
        legth_array[i] = max_value;
    }
    int result_value = legth_array[length];
    delete[] legth_array;
    return result_value;
}

// 尽可能多地剪长度为3的绳子，当剩下长度为4时，
int CutLine_greedy(int length)
{
    if(length <= 0)
        return 0;
    if(length == 1)
        return 1;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    int timeOf3 = length / 3;

    if(length - timeOf3*3 == 1)
        timeOf3 -= 1;

    int timeOf2 = (length - timeOf3 * 3) / 2;
    return (int)(pow(3, timeOf3)) * (int)(pow(2, timeOf2));


}

int main(void)
{
    std::cout << CutLine_greedy(8) << std::endl;
    return 0;
}