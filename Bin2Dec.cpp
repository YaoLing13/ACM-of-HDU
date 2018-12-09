/*
 * Discribe: 二进制转换为十进制
 * Method: 栈
 * Author: Yaoling
 * Time: 2018-07-27
 */

#include <iostream>
#include <cmath>

template <class T> class Node
{
public:
    T data; // data
    Node* pre;
    Node* next; // next node
    Node()  // Structure function
    {
        pre = NULL;
        next = NULL; // init
    }
    ~Node(){}   //Destructure function
};

int main(int argc, char ** argv)
{
    int n;
    std::cin >> n;

    Node<int>* top; // stack top
    Node<int>* bottom;  // stack bottom
    top = NULL;
    bottom = NULL;

    Node<int>* stack;
    Node<int>* temp;
    temp = NULL;
    for (int i = 1; i <= n; ++i) {
        stack = new Node<int>;
        std::cin >> stack->data;
        stack->next = NULL;
        if (i == 1)
        {
            stack->pre = NULL;
            bottom = stack;
            top = stack;
            continue;
        }
        temp = top;
        top->next = stack;
        top = top->next;
        top->pre = temp;
    }

    stack = top;
    int decnum = 0;
    for (int j = n; j > 0; --j) {
        if (!n)
        {
            std::cout << "stack length is 0! Can't output number" << std::endl;
            break;
        }
        decnum += top->data * pow(2, j-1);
        top = top->pre;
    }

    std::cout << decnum << std::endl;

}