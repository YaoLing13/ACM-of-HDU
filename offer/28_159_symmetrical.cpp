
/*
 * 题目: 判断一棵二叉树是不是对称的
 */

#include <iostream>
#include <stack>
#include <BinaryTree.h>

// 递归
bool isSymmetricalcoreRecursizely(BinaryTreeNode* pNode1, BinaryTreeNode* pNode2)
{
    if(pNode1 == nullptr && pNode2 == nullptr)
        return true;

    if((pNode1 == nullptr && pNode2 != nullptr) || (pNode1 != nullptr && pNode2 == nullptr))
        return false;

    if(pNode1->m_nValue != pNode2->m_nValue)
        return false;

    return isSymmetricalcoreRecursizely(pNode1->m_pLeft, pNode2->m_pRight)&&
            isSymmetricalcoreRecursizely(pNode1->m_pRight, pNode2->m_pLeft); //两个子树都需要判断
}

// 循环-迭代
bool isSymmetricalcoreIteratively(BinaryTreeNode* pNode1, BinaryTreeNode* pNode2)
{
    if(pNode1 == nullptr && pNode2 == nullptr)
        return true;

    std::stack<BinaryTreeNode*> stackTreeNode;
    stackTreeNode.push(pNode1);
    stackTreeNode.push(pNode2);
    BinaryTreeNode* tempNode1;
    BinaryTreeNode* tempNode2;
    while(!stackTreeNode.empty())
    {
        tempNode1 = stackTreeNode.top();
        stackTreeNode.pop();
        tempNode2 = stackTreeNode.top();
        stackTreeNode.pop();

        if((tempNode1 == nullptr && tempNode2 != nullptr) || (tempNode1 != nullptr && tempNode2 == nullptr))
            return false;
        if(tempNode1->m_nValue != tempNode2->m_nValue)
            return false;
        if(tempNode1->m_pLeft != nullptr || tempNode2->m_pRight != nullptr) {
            stackTreeNode.push(tempNode1->m_pLeft);
            stackTreeNode.push(tempNode2->m_pRight);
        }
        if(tempNode1->m_pRight != nullptr || tempNode2->m_pLeft != nullptr) {
            stackTreeNode.push(tempNode1->m_pRight);
            stackTreeNode.push(tempNode2->m_pLeft);
        }
    }
    return true;
}

bool isSymmetrical(BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
        return isSymmetricalcoreIteratively(pNode->m_pLeft, pNode->m_pRight);
    return true;
}


// ====================Test====================
void Test(char* testName, BinaryTreeNode* pRoot, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isSymmetrical(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      6
//       5 7    7 5
void Test1()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, pNode52);

    Test("Test1", pNode8, true);

    DestroyTree(pNode8);
}

//            8
//        6      9
//       5 7    7 5
void Test2()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode8, pNode61, pNode9);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode9, pNode72, pNode52);

    Test("Test2", pNode8, false);

    DestroyTree(pNode8);
}

//            8
//        6      6
//       5 7    7
void Test3()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, nullptr);

    Test("Test3", pNode8, false);

    DestroyTree(pNode8);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, nullptr, pNode42);
    ConnectTreeNodes(pNode41, pNode21, nullptr);
    ConnectTreeNodes(pNode42, nullptr, pNode22);
    ConnectTreeNodes(pNode21, pNode11, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode12);

    Test("Test4", pNode5, true);

    DestroyTree(pNode5);
}


//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
void Test5()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, nullptr, pNode42);
    ConnectTreeNodes(pNode41, pNode6, nullptr);
    ConnectTreeNodes(pNode42, nullptr, pNode22);
    ConnectTreeNodes(pNode6, pNode11, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode12);

    Test("Test5", pNode5, false);

    DestroyTree(pNode5);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
void Test6()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, nullptr, pNode42);
    ConnectTreeNodes(pNode41, pNode21, nullptr);
    ConnectTreeNodes(pNode42, nullptr, pNode22);
    ConnectTreeNodes(pNode21, nullptr, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode12);

    Test("Test6", pNode5, false);

    DestroyTree(pNode5);
}

// Ö»ÓÐÒ»žöœáµã
void Test7()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test7", pNode1, true);

    DestroyTree(pNode1);
}

// Ã»ÓÐœáµã
void Test8()
{
    Test("Test8", nullptr, true);
}

// ËùÓÐœáµã¶ŒÓÐÏàÍ¬µÄÖµ£¬Ê÷¶Ô³Æ
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
void Test9()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode21, pNode22);
    ConnectTreeNodes(pNode21, pNode31, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, nullptr, pNode42);
    ConnectTreeNodes(pNode41, nullptr, nullptr);
    ConnectTreeNodes(pNode42, nullptr, nullptr);

    Test("Test9", pNode1, true);

    DestroyTree(pNode1);
}

// ËùÓÐœáµã¶ŒÓÐÏàÍ¬µÄÖµ£¬Ê÷²»¶Ô³Æ
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
void Test10()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode21, pNode22);
    ConnectTreeNodes(pNode21, pNode31, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, pNode42, nullptr);
    ConnectTreeNodes(pNode41, nullptr, nullptr);
    ConnectTreeNodes(pNode42, nullptr, nullptr);

    Test("Test10", pNode1, false);

    DestroyTree(pNode1);
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
    Test8();
    Test9();
    Test10();

    return 1;
}