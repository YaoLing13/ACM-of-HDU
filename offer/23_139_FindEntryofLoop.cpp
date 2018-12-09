/*
 * 题目: 如果一个链表中包含环,找出环的入口节点
 * 思路: 定义2个指针: fast一次走2步,slow一次走1步
 */

#include <iostream>
#include "List.h"

// 输入提醒:1)空链表;2)链表中无环;3)有环

// 1.判断链表中是否有环, 返回相遇的节点
ListNode* MeetingNode(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;

    ListNode* pNodefast;
    ListNode* pNodeslow;

    pNodefast = pHead;
    pNodeslow = pHead;
    int count = 0;
    while(pNodefast->m_pNext != nullptr && pNodefast->m_pNext->m_pNext != nullptr)
    {
        pNodefast = pNodefast->m_pNext->m_pNext;
        pNodeslow = pNodeslow->m_pNext;
        if(pNodefast == pNodeslow)  // 2指针相遇
            return pNodefast;
    }
    return nullptr;
}
// 2.如果有环,再输出环入口位置
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* meetingNode = MeetingNode(pHead);
    if(meetingNode == nullptr)  // 链表为空或没有环
        return nullptr;

    ListNode* tempNode = meetingNode->m_pNext;
    int count = 1;  //环中节点数量
    while(tempNode != meetingNode) //计算环中节点数量
    {
        ++count;
        tempNode = tempNode->m_pNext;
    }

    ListNode* pNodefast = pHead;
    int index = 1;  //fast提前走的数量
    while(index <= count)
    {
        ++index;
        pNodefast = pNodefast->m_pNext;
    }
    ListNode* pNodeslow = pHead;
    while(pNodefast != pNodeslow)
    {
        pNodefast = pNodefast->m_pNext;
        pNodeslow = pNodeslow->m_pNext;
    }
    return pNodeslow;
}



// ==================== Test Code ====================
void Test(char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop
void Test3()
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
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
void Test4()
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
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
void Test5()
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
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop
void Test6()
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

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}