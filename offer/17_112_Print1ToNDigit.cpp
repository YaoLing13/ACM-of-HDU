#include <iostream>
#include <cstring>

/*
 * 函数: 实现在数字的字符串number增加1
 * 输入: 字符串(引用)
 * 输出: 完成增加1-true, 未完成增加1-false
 */
bool Incrememt(char*& number)
{
    bool isOverflow = false; // 是否完成加1
    int nTakeOver = 0;  // 到10进位
    int nLength = strlen(number);
    for (int i = nLength - 1; i >= 0; --i) {
        int nSum = number[i] - '0' + nTakeOver; //进一位
        if(i == nLength - 1)   // 从个位数开始
            nSum ++;
        if(nSum >= 10)
        {
            if(i == 0) //到达第一位,且nsum==10
                isOverflow = true; //到达最高位,循环终止
            else
            {
                nSum -= 10; // 0-9
                nTakeOver = 1;  //进位
                number[i] = '0' + nSum; //加1
            }
        }
        else
        {
            number[i] = '0' + nSum; // 加1
            break;
        }
    }
    return isOverflow;
}

/*
 * 函数: 打印字符串数字
 * 输入: 字符串(引用)
 * 输出: void
 */
void PrintNumber(char*& number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i) {
        if(isBeginning0 && number[i] != '0')    //找到第i个非零最高位,然后从这一位开始输出
            isBeginning0 = false;
        if(!isBeginning0) // 找到了
        {
            printf("%c", number[i]);    //输出这个数字的每一位
        }
    }
    printf("\n");
}

/*
 * 函数: 打印1到n位数
 * 输入: n(引用)
 * 输出: void
 * 注意: 需要考虑n很大的情况,超出一般的数据类型范围,例如long long等
 */
void Print(int n)
{
    if(n <= 0 )
        throw std::logic_error("Invalid input!!!");

    char* number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';   // 字符串最后一位是'\0'

    while(!Incrememt(number))
        PrintNumber(number);

    delete[] number;
    return;
}


/*
 * 方法2: 将问题转换为数字排列的解法,使用递归
 */

void Print1ToMaxOfNDigitsRecursively(char* &number, int length, int index)
{
    if (index == length - 1)    //个位数,递归结束
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index+1);
    }

    return;
}

// index表示数字的第index位
void Print1ToMaxOfNDigitsRecursively_self(char* &number, int length, int index)
{
    if(index == length - 1) //到达最后一位,递归终止条件
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0 ; i < 10 ; ++i) {
        number[index+1] = '0' + i;  //每一位都是0-9
        Print1ToMaxOfNDigitsRecursively_self(number, length, index+1);
    }

}


void Print1ToMaxOfNDigitsRecursively_self1(char* &number, int length, int index)
{
    if(index == length - 1) //到达最后一位,递归终止条件
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        number[index+1] = i + '0';
        Print1ToMaxOfNDigitsRecursively_self1(number, length, index+1);
    }
}

void Print1ToMaxOfNDigits(int n)
{
    if(n <= 0)
        return;

    char* number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    for (int i = 0; i < 10; ++i) {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively_self1(number, n, 0);
    }


    delete[] number;
    return;
}

// 119
// 任意整数相加
void add_number(char* number1, char* number2)
{
    int len1 = std::strlen(number1) - 1; //number1的长度,除去'\0'
    int len2 = std::strlen(number2) - 2; //同上
    int len = std::max(len1, len2);
    char* res = new char[len + 2];  //一位是\0, 一位用于进位
    memset(res,'0', len+1);
    res[len+1] = '\0';

    if(len1 >0 && len2 > 0) //两个数都存在
    {

        for (int i = len-1 ; i > 0 ; --i) {
            if(number1[i] + number2[i] > '9') //需要进位
            {
                res[i] = res[i] + ((number1[i] + number2[i]) - '9' - 1);
                res[i-1] += 1;
            }
        }
    }

}

int main(int argc, char ** argv)
{
    Print1ToMaxOfNDigits(3);
    return 1;
}