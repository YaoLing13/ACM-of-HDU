#include <iostream>
#include <string>
#include <vector>

//int main(void)
//{
//    char str1[] = "hello";
//    char str2[] = "hello";
//    char* str3 = "hello";
//    char* str4 = "hello";
//
//
//    std::cout << "str1:" << &str1 << std::endl;
//    std::cout << "str2:" << &str2 << std::endl;
//    std::cout << "str3:" << &str3 << std::endl;
//    std::cout << "str4:" << &str4 << std::endl;
//    std::cout << std::endl;
//
//    if(str1 == str2)
//        std::cout << "str1 and str2 are same" << std::endl;
//    else
//        std::cout << "str1 and str2 are not same" << std::endl;
//
//    if(str3 == str4)
//        std::cout << "str3 and str4 are same" << std::endl;
//    else
//        std::cout << "str3 and str4 are not same" << std::endl;
//
//    return 0;
//}

void ReplaceBlank(char* input, int& length)
{
    if(input == nullptr || length == 0)
        return;

    int count = 0;
    int i = 0;
    while(input[i] != '\0')
    {
        if(input[i] == ' ')
            count += 1;
        i++;
    }
    if(count == 0)
        return;

    int newLength = length + count*2;
    int origalLenght = length;

    while (newLength > origalLenght && origalLenght >= 0)
    {
        if(input[origalLenght] != ' ')    // 不是空格
        {
            input[newLength--] = input[origalLenght--];
        }
        else    //是空格，替换
        {
            input[newLength--] = '0';
            input[newLength--] = '2';
            input[newLength--] = '%';
            --origalLenght;
        }
    }
    std::cout << input << std::endl;
    return;
}

void InsertNumber(int num1[], int num1Length, int num2[], int num2Length)
{
    int ori1Length = num1Length-1;
    int ori2Length = num2Length-1;

    int newLength;
    newLength = num1Length + num2Length;
    std::cout << "New Length:" << newLength << std::endl;

    if((num1 == nullptr || num1Length == 0) && (num2 == nullptr || num2Length == 0))
        return;
    else if(num1 == nullptr || num1Length == 0)
    {
        num1 = num2;
        for (int i = 0; i < newLength; ++i) {
            std::cout << num1[i] << " ";
        }
        return;
    }
    else if(num2 == nullptr || num2Length == 0)
    {
        for (int i = 0; i < newLength; ++i) {
            std::cout << num1[i] << " ";
        }
        return;
    }


    newLength -= 1;
    while(newLength >= 0 && (ori1Length >= 0 || ori2Length >= 0) )
    {
        if ( (num1[ori1Length] > num2[ori2Length] && ori1Length >= 0) || ori2Length < 0)
            num1[newLength--] = num1[ori1Length--];
        else
            num1[newLength--] = num2[ori2Length--];
    }

    for (int i = 0; i < num1Length + num2Length; ++i) {
        std::cout << num1[i] << " ";
    }
}

int main()
{
//    char str[50] = " we are happy   a! ";
//    int legth = 20;
//    ReplaceBlank(str, legth);


    int num1[50] = {0, 2, 6, 9};
    int num2[4] = {0, 6, 7, 8};
    int l1 = 4;
    int l2 = 4;
    InsertNumber(num1, l1, num2, l2);
//
//    int num1[50] = {1, 2};
//    int num2[] = {};
//    int l1 = 2;
//    int l2 = 0;
//
//    int num1[] = {};
//    int num2[3] = {2, 3, 4};
//    int l1 = 0;
//    int l2 = 3;
//
//    int num1[] = {};
//    int num2[] = {};
//    int l1 = 0;
//    int l2 = 0;
//

    return 0;
}