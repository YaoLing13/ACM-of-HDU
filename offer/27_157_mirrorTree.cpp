
/*
 * 题目: 输入一棵树,该函数输出它的镜像树
 */

#include <iostream>
#include <stack>
#include <BinaryTree.h>


// 输入:1)空; 2)正常
void MirrorRecursively(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
        return;

    // 左/右节点换位置
    BinaryTreeNode* tempNode;
    tempNode = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = tempNode;

    if(pNode->m_pLeft != nullptr)
        MirrorRecursively(pNode->m_pLeft);
    if(pNode->m_pRight != nullptr)
        MirrorRecursively(pNode->m_pRight);
}


// 将左右节点压入一个堆栈中,然后分别处理
void MirrorIteratively(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
        return;

    std::stack<BinaryTreeNode*> stackTreeNode;
    stackTreeNode.push(pNode); // 压入第一个根节点
    BinaryTreeNode* tempNode;
    while (!stackTreeNode.empty())
    {
        pNode = stackTreeNode.top();
        stackTreeNode.pop();
        tempNode = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = tempNode;

        if(pNode->m_pLeft != nullptr)
            stackTreeNode.push(pNode->m_pLeft);
        if(pNode->m_pRight != nullptr)
            stackTreeNode.push(pNode->m_pRight);
    }
    return;
}

// ====================TEST====================
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    printf("=====Test1 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    PrintTree(pNode8);

    printf("=====Test1: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test1: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// ²âÊÔ¶þ²æÊ÷£º³öÒ¶×ÓœáµãÖ®Íâ£¬×óÓÒµÄœáµã¶ŒÓÐÇÒÖ»ÓÐÒ»žö×ó×Óœáµã
//            8
//          7
//        6
//      5
//    4
void Test2()
{
    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, pNode7, nullptr);
    ConnectTreeNodes(pNode7, pNode6, nullptr);
    ConnectTreeNodes(pNode6, pNode5, nullptr);
    ConnectTreeNodes(pNode5, pNode4, nullptr);

    PrintTree(pNode8);

    printf("=====Test2: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test2: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// ²âÊÔ¶þ²æÊ÷£º³öÒ¶×ÓœáµãÖ®Íâ£¬×óÓÒµÄœáµã¶ŒÓÐÇÒÖ»ÓÐÒ»žöÓÒ×Óœáµã
//            8
//             7
//              6
//               5
//                4
void Test3()
{
    printf("=====Test3 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, nullptr, pNode7);
    ConnectTreeNodes(pNode7, nullptr, pNode6);
    ConnectTreeNodes(pNode6, nullptr, pNode5);
    ConnectTreeNodes(pNode5, nullptr, pNode4);

    PrintTree(pNode8);

    printf("=====Test3: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test3: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// ²âÊÔ¿Õ¶þ²æÊ÷£ºžùœáµãÎª¿ÕÖžÕë
void Test4()
{
    printf("=====Test4 starts:=====\n");
    BinaryTreeNode* pNode = nullptr;

    PrintTree(pNode);

    printf("=====Test4: MirrorRecursively=====\n");
    MirrorRecursively(pNode);
    PrintTree(pNode);

    printf("=====Test4: MirrorIteratively=====\n");
    MirrorIteratively(pNode);
    PrintTree(pNode);
}

// ²âÊÔÖ»ÓÐÒ»žöœáµãµÄ¶þ²æÊ÷
void Test5()
{
    printf("=====Test5 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

    PrintTree(pNode8);

    printf("=====Test4: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test4: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);
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