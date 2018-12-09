/*
 * Discribe: Stack operate
 * Details: LIFO
 * Author: Yao Ling
 * Time: 2018-07-27
 */

#include <iostream>

template <class T> class Node
{
private:
    T data; // data
    Node* pre;
    Node* next; // next node
    Node* top;
    Node* bottom;
    int len;

public:
    Node()  // Structure function
    {
        pre = NULL;
        next = NULL; // init
        top = NULL;
        bottom = NULL;
        len = 0;
    }
    ~Node(){}   //Destructure function

    void push(T t)
    {
        Node* temp = new Node<T>;
        temp->data = t;
        temp->next = NULL;

        if (!len)
        {
            ++len;
            temp->pre = NULL;
            bottom = temp;
            top = temp;
            return;
        }

        ++len;
        Node* tmp_node;
        tmp_node = NULL;
        tmp_node = top;
        top->next = temp;
        top = top->next;
        top->pre = tmp_node;

        return;
    }

    int size()
    {
        return len;
    }
    bool empty()
    {
        return !len;
    }

    T pop()
    {
        if (!len)
        {
            std::cout << "No data!!!" << std::endl;
            return 0;
        }
        --len;
        Node* temp;
        temp = top;
        top = top->pre;
        T tmp_data = temp->data;
        delete temp;
        return tmp_data;
    }

};

int main(int argc, char ** argv)
{
    char n;
    Node<char> S;
    n = std::cin.get();
    while(n != '\n')
    {
        switch (n){
            case '(':
                S.push(n);
                break;
            case '[':
                S.push(n);
                break;
            case '{':
                S.push(n);
                break;
            case ')':
                if( ( S.empty() ) || ( '(' != S.pop() ) )
                {
                    std::cout << "No match!!!!" << std::endl;
                    return -1;
                }
                break;
            case ']':
                if( ( S.empty() ) || ( '[' != S.pop() ) )
                {
                    std::cout << "No match!!!!" << std::endl;
                    return -1;
                }
                break;
            case '}':
                if( ( S.empty() ) || ( '{' != S.pop() ) )
                {
                    std::cout << "No match!!!!" << std::endl;
                    return -1;
                }
                break;
            default:
                break;
        }
        n = std::cin.get();
    }

    if (S.empty())
        std::cout << "Match!!!!" << std::endl;
    else
        std::cout << "No match!!!!" << std::endl;

    return 1;
}