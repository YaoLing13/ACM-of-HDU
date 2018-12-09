/*
 * 要求：定义一个赋值运算符函数
 * P25
 * 注意事项：
 * 1）是否把返回值的类型声明为该类型的引用，并在函数结束前返回返回实例自身的引用（*this）；
 * 2）是否把传入的参数的类型声明为常量引用；
 *    引用：避免再开个内存以及再调用一次复制构造函数
 *    常量：保证在函数内不会改变传入实例的状态
 * 3）是否释放实例自身已有的内存；
 *    如果在分配新内存前，忘记释放自身已有的空间，容易出现内存泄露。
 * 4）判断传入的参数和当前的实例(*this)是不是同一个实例。如果是，则不需要赋值，直接返回。
 *    如果事先不判断就进行赋值，那么在是否实例自身内存的时候会导致严重的问题。
 */

#include <iostream>
#include <cstring>

class Myclass
{
public:
    Myclass(char* pData = nullptr){}
    Myclass(const Myclass& str){}
    ~Myclass(void){}

//    Myclass& operator=(const Myclass &str)
//    {
//        if(this == &str)
//            return *this;
//
//        delete [] m_pData;
//        m_pData = nullptr;
//        m_pData = new char[std::strlen(str.m_pData) + 1];
//        strcpy(m_pData, str.m_pData);
//        return *this;
//    }

    //增加异常处理
    Myclass& operator=(const Myclass &str)
    {
        if(this != &str)
        {
            Myclass strTemp(str);

            char* pTemp = strTemp.m_pData;
            strTemp.m_pData = m_pData;
            m_pData = pTemp;
        }
        return *this;
    }

    void display()
    {
        for (int i = 0; i < std::strlen(this->m_pData); ++i) {
            std::cout << this->m_pData[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    char* m_pData;
};
