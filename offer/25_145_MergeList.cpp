/*
 * 题目: 输入2个递增排序的链表,合并这2个链表并使新链表中的节点仍然是递增排序的.
 */

#include <iostream>
#include "List.h"

// 输入: 1) 两个空链表; 2)链表１为空；　３）链表2为空; 4)２个链表不为空
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;

    ListNode* pMergeNode = nullptr;

    if(pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergeNode = pHead1;
        pMergeNode->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergeNode = pHead2;
        pMergeNode->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }

    return  pMergeNode;
}

// ====================Test====================
ListNode* Test(char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode* pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);

    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// ÁœžöÁŽ±íÖÐÓÐÖØžŽµÄÊý×Ö
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// ÁœžöÁŽ±í¶ŒÖ»ÓÐÒ»žöÊý×Ö
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// Ò»žöÁŽ±íÎª¿ÕÁŽ±í
// list1: 1->3->5
// list2: ¿ÕÁŽ±í
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, nullptr);

    DestroyList(pMergedHead);
}

// ÁœžöÁŽ±í¶ŒÎª¿ÕÁŽ±í
// list1: ¿ÕÁŽ±í
// list2: ¿ÕÁŽ±í
void Test5()
{
    ListNode* pMergedHead = Test("Test5", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}


