/*
 * 题目: 定义一个函数,输入一个链表的头节点,翻转反转该链表并输出反转后链表的头节点
 * 思路: 时刻保存好当前节点的next节点
 */

#include <iostream>
#include "List.h"

// 输入: 1)空链表; 2)链表长度==1; 3)链表长度>1
ListNode* ReverseList(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;

    ListNode* pNode = pHead;
    ListNode* pNext = pNode->m_pNext;    // 节点反转前的下一个节点
    ListNode* pPre = nullptr;     // 节点反转前为本节点;
    if(pNext == nullptr)
        pPre = pHead;
    while(pNext != nullptr)
    {
        pNext = pNode->m_pNext; //该节点实际的下一个节点

        pNode->m_pNext = pPre;  //反转后节点的下一个节点

        pPre = pNode; //反转后下一个节点的上一个节点
        pNode = pNext; //反转后下一个节点
    }


    return pPre;
}

// ====================Test====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}

