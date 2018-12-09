#include <iostream>
#include <cstring>
#include <algorithm>


struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void DeleteNode_self(ListNode** pListHead, ListNode* pToBeDelelete)
{
    if(pListHead == nullptr)
        return;
    ListNode* pNext = *pListHead;
    if(pNext == pToBeDelelete)
    {
        *pListHead = (*pListHead)->m_pNext;
        delete pNext;
    }
    while (pNext != nullptr)
    {
        if(pNext->m_pNext == pToBeDelelete)
        {
            if(pNext->m_pNext != nullptr)
            {
                ListNode* temp_node = pNext->m_pNext;
                if(pNext->m_pNext->m_pNext == nullptr)
                {
                    delete temp_node;
                    pNext->m_pNext->m_pNext = nullptr;
                    return;
                } else
                {
                    pNext->m_pNext = pNext->m_pNext->m_pNext;
                    delete temp_node;
                    return;
                }
            }
            else
            {
                ListNode* temp_node = pNext->m_pNext;
                pNext->m_pNext = nullptr;
                delete temp_node;
            }

        }
    }
}

void DeleteNode(ListNode** pListHead, ListNode* pToBeDelelete)
{
    if(!pListHead || !pToBeDelelete)
        return;;

    // 要删除的节点不是尾节点
    if(pToBeDelelete->m_pNext != nullptr)
    {
        ListNode* pNext = pToBeDelelete->m_pNext;
        pToBeDelelete->m_nValue = pNext->m_nValue;
        pToBeDelelete->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = nullptr;
    }

    //链表只有一个节点,删除头节点,也是尾节点
    else if(*pListHead == pToBeDelelete)
    {
        delete pToBeDelelete;
        pToBeDelelete = nullptr;
        *pListHead = nullptr;
    }

    //链表中有多个节点,删除尾节点
    else
    {
        ListNode* pNode = *pListHead;
        while (pNode->m_pNext != pToBeDelelete)
        {
            pNode = pNode->m_pNext;
        }

        pNode->m_pNext = nullptr;
        delete pToBeDelelete;
        pToBeDelelete = nullptr;
    }

}

/*
 * 删除链表中的重复节点
 * 注意事项: 需要全面考虑重复节点在链表不同情况的处理办法
 */
    void DeleteDuplication(ListNode** pHead) // 传入指向pHead的指针
// ListNode** pHead, 是由于pHead是局部变量，出了函数还是没变，所以要是需要出了函数依然改变，那么就需要传入指向pHead的指针，也就是ListNode**了
{
    if(pHead == nullptr || *pHead == nullptr)   //
        return;

    ListNode* pPreNode = nullptr; // 初始化指向上一个节点的变量
    ListNode* pNode = *pHead; // 从头节点开始
    while(pNode != nullptr)
    {
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        if(pNext != nullptr && pNext->m_nValue == pNode->m_nValue) // 重复节点
            needDelete = true; //需要删除

        if(!needDelete) // 不需要删除,跳到下一个节点,重复
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }
        else //需要删除
        {
            int value = pNode->m_nValue;
            ListNode* pToBeDel = pNode;
            while(pToBeDel != nullptr && pToBeDel->m_nValue == value) // 一直出现重复节点
            {
                pNext = pToBeDel->m_pNext;

                delete pToBeDel;
                pToBeDel = nullptr;

                pToBeDel = pNext;
            }

            if(pPreNode == nullptr) // 将头节点删除了,那么头节点需要更新
                *pHead = pNext;
            else
                pPreNode->m_pNext = pNext; // 上一节点变量指向本节点
            pNode = pNext;//本节点指向下一节点,循环判断,直至本节点为nullptr
        }
    }
}

int main(void)
{

}


