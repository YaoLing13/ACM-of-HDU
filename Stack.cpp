/*
 * Discribe: Stack operate
 * Details: LIFO
 * Author: Yao Ling
 * Time: 2018-07-27
 */

#include <iostream>

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

    // init stack
    Node<int>* stack;    // stack
    Node<int>* temp;
    temp = NULL;
    for (int i = 1; i <= n; ++i) {
        stack = new Node<int>;
        stack->data = i;
        stack->next = NULL;
        if (i == 1)
        {
            stack->pre = NULL;
            bottom = stack;
            top = stack;
            std::cout << top->data << " ";
            continue;
        }
        temp = top;
        top->next = stack;
        top = top->next;
        top->pre = temp;
        std::cout << top->data << " ";
    }
    std::cout << std::endl;
    // print stack
    stack = top;
    for (int j = 1; j <= n; ++j) {
        if (!n)
        {
            std::cout << "stack length is 0! Can't output number" << std::endl;
            break;
        }
        std::cout << top->data << " ";
        top = top->pre;
    }
    std::cout << std::endl;

    return 1;
}

//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//class Stack
//{
//public:
//    void push(int x);
//    void init();
//    int pop();
//    struct stack
//    {
//        int num;
//        stack *next ,*pre;
//    }*head;
//};
////初始化栈顶
//void Stack::init()
//{
//    head=(struct stack *)malloc(sizeof(struct stack));
//    head->num=-1;
//    head->next=NULL;
//    head->pre=NULL;
//}
////入栈
//void Stack::push(int x)
//{
//    stack *p;
//    p=(struct stack *)malloc(sizeof(struct stack));
//    head->next=p;
//    p->pre=head;
//    head=p;
//    head->num=x;
//}
////出栈
//int Stack::pop()
//{
//    if(head->pre!=NULL)
//    {
//        int x=head->num;
//        head=head->pre;
//        head->next=NULL;
//        return x;
//
//    }
//    else
//    {
//        return 0x3fffffff;
//    }
//}
//int main()
//{
//    Stack s;
//    s.init();
//    while(true)
//    {
//        cout<<"向栈中添加元素请按1，取出栈顶元素请按2,退出请按3"<<endl;
//        int x;
//        cin>>x;
//        if(x==1)
//        {
//            int y;
//            cout<<"请输入入栈的元素:";
//            cin>>y;
//            s.push(y);
//            cout<<"入栈成功!!"<<endl;
//        }
//        if(x==2)
//        {
//            int top=s.pop();
//            if(top==0x3fffffff)
//            {
//                cout<<"当前栈为空"<<endl;
//            }
//            else
//            {
//                cout<<"当前栈顶元素为: "<<top<<endl;
//            }
//        }
//        if(x==3)
//        {
//            break;
//        }
//    }
//    return 0;
//}