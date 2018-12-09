#include<iostream>
#include <cstring>

using namespace std;

/*
 * 函数: 正数的任意整数相加
 */
/*
void addIncrement(char* &str1, int& p1, char* &str2, int& p2, char* &res, int& p, bool add_flag)
{
    int ntake = 0;
    if(add_flag)
    {
        //===
        while (p1 >= 0 && p2 >= 0)
        {
            int temp =str1[p1] - '0' + str2[p2] - '0'+ntake;
            ntake = 0;
            if (temp >= 10)
            {
                ntake = 1;
                temp -= 10;
            }
            res[p] += temp;
            p--;
            p1--;
            p2--;
        }
        //===
        if (p1 >= 0)
        {
            while (p1 >= 0)
            {
                int temp = str1[p1] - '0' + ntake;
                ntake = 0;
                if (temp >= 10)
                {
                    ntake = 1;
                    temp -= 10;
                }
                res[p] += temp;
                p--;
                p1--;
            }
        }
        //===
        if (p2 >= 0)
        {
            while (p2 >= 0)
            {
                int temp = str1[p2] - '0' + ntake;
                ntake = 0;
                if (temp >= 10)
                {
                    ntake = 1;
                    temp -= 10;
                }
                res[p] += temp;
                p--;
                p2--;
            }
        }
        res[p] += ntake;
    }


    return;
}
char *BigNunAdd(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = len1 > len2?len1 : len2;
    char *res = new char[len + 2];
    memset(res, '0', len + 2);
    res[len + 1] = '\0';

    int p1 = len1 - 1;
    int p2 = len2 - 1;
    int p = len;
    bool add_flag = false;
    add_flag = true;
    addIncrement(str1, p1, str2, p2, res, p, add_flag);

    //===
    return res;
}
int main()
{
    char *str1 = "2368488";
    char *str2 = "901124";
    char *res = BigNunAdd(str1, str2);
    if (res[0] != '0')
    {
        cout << str1 << "+" << str2 << "=:" << res << endl;
    }
    else
    {
        char *_res = res;
        _res++;
        cout << str1 << " + " << str2 << " = " << _res << endl;
    }
    delete[]res;
    return 0;
}
 */
/******** 以上为任意正整数相加程序  ********/


/*
 * 任意整数相加(有正有负)
 */
#include <string>
#include <iostream>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::max;

bool addchar(char lc, char rc, bool flag, char *result){
    //cout<<lc<<" "<<rc<<endl;
    bool isflag = false;
    int value  = (lc - '0')+(rc - '0');
    if(flag)
        value ++;

    if(value > 9){
        isflag = true;
        value -= 10;
    }

    *result = value + '0';
    return isflag;
}

bool subchar(char lc, char rc, bool flag, char *result){
    bool isflag = false;
    int value = (lc - '0') - (rc - '0');
    if(flag)
        value --;

    if(value < 0){
        isflag = true;
        value += 10;
    }

    *result = value + '0';
    return isflag;
}

void addstr(const string &lstr, const string &rstr, string &result){
    int i = lstr.size()-1;
    int j = rstr.size()-1;
    int k = result.size()-1;
    bool flag = false;

    while((i != -1) &&(j != -1)){
        flag = addchar(lstr[i], rstr[j], flag, &result[k]);
        i --;
        j --;
        k --;
    }

    if(j != -1){
        do{
            flag = addchar('0', rstr[j], flag, &result[k]);
            --k;
        }while(--j != -1);
    }

    if(i != -1){
        do{
            flag = addchar(lstr[i], '0', flag, &result[k]);
            --k;
        }while(--i != -1);
    }

    addchar('0', '0', flag, &result[k]);

}

void substr(const string &lstr, const string &rstr, string &result){
    int i = lstr.size() - 1;
    int j = rstr.size() - 1;
    int k = result.size() - 1 ;
    bool flag = false;

    while((j!=-1) && (i != -1)){
        flag = subchar(lstr[i], rstr[j], flag, &result[k]);
        --j;
        --i;
        --k;
    }

    while(i != -1){
        flag = subchar(lstr[i], '0', flag, &result[k]);
        --i;
        --k;
    }

}

int main(){
    string lstr, rstr;

    cout<<"input one number: ";
    cin>>lstr;
    cout<<endl<<"input the other number: ";
    cin>>rstr;

    if(lstr.empty() || rstr.empty())
        return -1;

    string result(1+ max(lstr.size(),rstr.size()), '0');

    bool rflag = false; //- or +
    if((lstr[0] == '-') && (rstr[0] == '-')){ // 两个负数相加,输出数据的时候才在结果前面加一个'-'
        //cout <<"- -"<<endl;
        rflag = true;
        lstr = lstr.substr(1);  //substr默认时的长度为从开始位置到尾
        rstr = rstr.substr(1);
        addstr(lstr, rstr, result);
    }else if((lstr[0] != '-') && (rstr[0]!='-')){ // 两个正数相加
        //cout <<"+ +"<<endl;
        rflag = false;
        addstr(lstr, rstr, result);
    }else if(lstr[0] == '-'){   // lstr是被减数
        //cout<<"- +"<<endl;
        if((lstr.size() - 1 > rstr.size())){    //lstr的位数比rstr的长
            rflag = true;
            substr(lstr.substr(1), rstr, result);
        }else if((lstr.size() -1 < rstr.size())){
            rflag = false;
            substr(rstr, lstr.substr(1), result);
        }else if(lstr[1] > rstr[0]){
            rflag = true;
            substr(lstr.substr(1), rstr, result);
        }else{
            rflag = false;
            substr(rstr, lstr.substr(1), result);
        }
    }else{
        //cout<<"+ -"<<endl;
        if((rstr.size() - 1 > lstr.size())){
            rflag = true;
            substr(rstr.substr(1), lstr, result);
        }else if((rstr.size() -1 < lstr.size())){
            rflag = false;
            substr(lstr, rstr.substr(1), result);
        }else if(rstr[1] > lstr[0]){
            rflag = true;
            substr(rstr.substr(1), lstr, result);
        }else{
            rflag = false;
            substr(lstr, rstr.substr(1), result);
        }
    }

    if(rflag)
        cout<<"-";
    int pos = result.find_first_not_of('0');
    if(pos != string::npos)
        cout<<result.substr(pos)<<endl;
    else
        cout<<'0'<<endl;
}