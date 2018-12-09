#include <iostream>

/*
 * 字符串所有字符匹配整个模式
 * '.'表示任意一个字符
 * '*'表示它前面的字符可以出现任意次
 * match函数是调用函数
 * matchCore函数是实际实现函数
 */

bool matchCore(char* str, char* patten)
{
    if(*str == '\0' && *patten == '\0') //完成匹配
        return true;
    if(*str != '\0' && *patten == '\0') //patten < str
        return false;

    if(*(patten+1) == '*')
    {
        if(*patten == *str || (*patten == '.' && *str != '\0')) // 首个字符串匹配完成
            return matchCore(str+1, patten+2) || matchCore(str+1, patten) || matchCore(str, patten+2);
        else
            return matchCore(str, patten+2);
    }
    if(*str == *patten || (*patten == '.' && *str != '\0'))
        return matchCore(str+1, patten+1);

    return false;
}

bool match(char* str, char* patten)
{
    if(str == nullptr || patten == nullptr) // 输入不符合要求,返回false
        return false;

    return matchCore(str, patten);
}

int main(int argc, char* argv[])
{

}