/*
 * 字符串的全排列
 */

#include <iostream>
#include <cstring>

bool IsSwap(char* pBegin, char* pEnd)    //这部分是重点！！
{  
    char* p;  
    for (p=pBegin; p<pEnd; p++)  
    {  
        if (*p == *pEnd)  
            return false;  
    }  
    return true;  
}  


void StringPermutationCore(char* pStr, char* start)
{
    if( *start == '\0')
    {
        printf("%s\n", pStr);
    }

    for (char* pCh = start;*pCh != '\0'; ++pCh) {

	if (!IsSwap(start, pCh))
		continue;
        char temp = *start;
        *start = *pCh;
        *pCh = temp;

        StringPermutationCore(pStr, start+1);

        temp = *start;
        *start = *pCh;
        *pCh = temp;
    }
}

void StringPermutation(char* pStr)
{
    if(pStr == nullptr) // 字符串为空
        return;

    StringPermutationCore(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
    if(*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for(char* pCh = pBegin; *pCh != '\0'; ++ pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr, pBegin+1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

void Permutation(char* pStr)
{
    if(pStr == nullptr)
        return;

    Permutation(pStr, pStr);
}

// ====================���Դ���====================
void Test(char* pStr)
{
    if(pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    StringPermutation(pStr);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(nullptr);

    char string1[] = "";
    Test(string1);

    char string2[] = "aa";
    Test(string2);

    char string3[] = "abaa";
    Test(string3);

    //char string4[] = "abcd";
    //Test(string4);

    return 0;
}
