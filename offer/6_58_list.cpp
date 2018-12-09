#include <iostream>
#include <string>
#include <stack>

template <class T> class ListNode{
public:
    T data;
    ListNode* next;

    ListNode()
    {
        next = NULL;
    }
};

void printList(ListNode* head)
{
    // list is empty
    if(head == nullptr)
        return;

    ListNode* temp;
    std::stack<ListNode*> nodes;


    // 遍历一次链表，并将节点压入栈中
    temp = head;
    while (temp->next != nullptr)
    {
        nodes.push(temp);
        temp = temp->next;
    }

    // 开始打印
    while (!nodes.empty())   //一直在最后一个节点
    {
        temp = nodes.top(); // 获得栈的最顶端element
        std::cout << temp->data << " ";
        nodes.pop();    // 移除top element
    }

    return;
}

// 书籍的参考答案: 用栈基于循环实现
void printList2(ListNode* head)
{
    // 遍历一次链表，并将节点压入栈中
    std::stack<ListNode*> nodes;
    ListNode* temp = head;
    while (temp != nullptr)
    {
        nodes.push(temp);
        temp = temp->next;
    }

    // 开始打印
    while (!nodes.empty())   //一直在最后一个节点
    {
        temp = nodes.top(); // 获得栈的最顶端element
        std::cout << temp->data << " ";
        nodes.pop();    // 移除top element
    }

    return;
}

// 书籍的参考答案：递归
// 缺点：当链表很长时，到时函数调用的层级很深，从而可能导致函数调用栈溢出
void printList3(ListNode* head)
{
    if(head != nullptr)
    {
        if(head->next == nullptr)
            std::cout << head->data << " ";
        else
            printList3(head->next);
    }

    return;
}

int main()
{

}