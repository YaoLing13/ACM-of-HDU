#include <iostream>
#include <vector>
#include <set>
#include <exception>
#include <stdexcept>

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

//BinaryTreeNode* ConstructCore(std::vector<int>& preorder, std::vector<int>& inorder)
//{
//    if((preorder.empty() || inorder.empty()) || (preorder.size() == 0 && inorder.size() == 0))
//        return nullptr;
//
//    int rootValue = preorder[0];
//    BinaryTreeNode* root = new BinaryTreeNode(); // 创建一个根节点
//    root->left = nullptr;
//    root->right = nullptr;
//
//    std::vector<BinaryTreeNode*> preleftTree(0);
//    std::vector<BinaryTreeNode*> prerightTree(0);
//    std::vector<BinaryTreeNode*> inleftTree(0);
//    std::vector<BinaryTreeNode*> inrightTree(0);
//
//    BinaryTreeNode* tempNode;
//    int i = 0;
//    while (inorder[i] != rootValue)
//    {
//        tempNode->m_nValue = preorder[i+1];
//        tempNode->left = nullptr;
//        tempNode->right = nullptr;
//        preleftTree.push_back(tempNode);   // 获得前序遍历时的左子树
//        tempNode->m_nValue = inorder[i];
//        inleftTree.push_back(tempNode);       // 获得中序遍历时的左子树
//        ++i;
//    }
//    ++i; // 获得右子树的第一个元素序号
//    for ( ;i < preorder.size(); ++i) {
//        tempNode->m_nValue = preorder[i];
//        tempNode->left = nullptr;
//        tempNode->right = nullptr;
//        prerightTree.push_back(tempNode);    // 获得前序遍历时的右子树
//        tempNode->m_nValue = inorder[i];
//        inrightTree.push_back(tempNode);      // 获得中序遍历时的右子树
//    }
//
//
//    // 前序遍历：根节点->左节点->右节点
//    // 有左子树和右子树都有值
//    if(preleftTree.size()!= 0 && prerightTree.size()!= 0)
//    {
//        root->left = ConstructCore(preleftTree, inleftTree); // 前序遍历中，根节点的左节点是左子树的第一个值（左子树的第一个值是左子树的根）
//        root->right = ConstructCore(preleftTree, inrightTree);// 前序遍历中，根节点的右节点是右子树的第一个值（右子树的第一个值是右子树的根）
//        return root;
//    }
//    if(preleftTree.size()!= 0 && prerightTree.size()== 0)
//    {
//        root->left = ConstructCore(preleftTree, inleftTree); // 前序遍历中，根节点的左节点是左子树的第一个值（左子树的第一个值是左子树的根）
//        root->right = nullptr;// 前序遍历中，根节点的右节点是右子树的第一个值（右子树的第一个值是右子树的根）
//        return root;
//    }
//    if(preleftTree.size()== 0 && prerightTree.size()!= 0)
//    {
//        root->left = nullptr; // 前序遍历中，根节点的左节点是左子树的第一个值（左子树的第一个值是左子树的根）
//        root->right = ConstructCore(preleftTree, inrightTree);// 前序遍历中，根节点的右节点是右子树的第一个值（右子树的第一个值是右子树的根）
//        return root;
//    }
//}

BinaryTreeNode* ConstructCore(std::vector<int>& preorder, std::vector<int>& inorder)
{
    if(preorder.empty() || inorder.empty())
        return nullptr;

    int rootValue = preorder[0];
    auto* root = new BinaryTreeNode(); // 创建一个根节点
    root->left = nullptr;
    root->right = nullptr;

    std::vector<int> preleftTree(0);
    std::vector<int> prerightTree(0);
    std::vector<int> inleftTree(0);
    std::vector<int> inrightTree(0);

    int i = 0;
    while (inorder[i] != rootValue)
    {
        preleftTree.push_back(preorder[i+1]);   // 获得前序遍历时的左子树
        inleftTree.push_back(inorder[i]);       // 获得中序遍历时的左子树
        ++i;
    }
    ++i; // 获得右子树的第一个元素序号
    for ( ;i < preorder.size(); ++i) {
        prerightTree.push_back(preorder[i]);    // 获得前序遍历时的右子树
        inrightTree.push_back(inorder[i]);      // 获得中序遍历时的右子树
    }


    // 前序遍历：根节点->左节点->右节点
    // 有左子树和右子树都有值
    if(!preleftTree.empty() && !prerightTree.empty())
    {
        root->left = ConstructCore(preleftTree, inleftTree); // 前序遍历中，根节点的左节点是左子树的第一个值（左子树的第一个值是左子树的根）
        root->right = ConstructCore(preleftTree, inrightTree);// 前序遍历中，根节点的右节点是右子树的第一个值（右子树的第一个值是右子树的根）
        return root;
    }
    if(!preleftTree.empty() && prerightTree.empty())
    {
        // 构建左子树
        root->left = ConstructCore(preleftTree, inleftTree); // 前序遍历中，根节点的左节点是左子树的第一个值（左子树的第一个值是左子树的根）
        return root;
    }
    if(preleftTree.empty() && !prerightTree.empty())
    {
        // 构建右子树
        root->right = ConstructCore(preleftTree, inrightTree);// 前序遍历中，根节点的右节点是右子树的第一个值（右子树的第一个值是右子树的根）
        return root;
    }
}


BinaryTreeNode* ConstructCore1(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    // 前序遍历中第一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->left = root->right = nullptr;

    if (startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)   // only one node
            return root;
        else
        {
            std::logic_error ex("Invalid input.");
            throw std::exception(ex);
        }
    }

    // 在中序遍历序列中找到根节点
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
        std::logic_error ex("Invalid input.");
        throw std::exception(ex);
    }
        // throw std::exception("Invalid input."); 在linux的gcc下不能编译通过

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;

    if (leftLength > 0)
    {
        // 构建左子树
        root->left = ConstructCore1(startInorder+1, leftPreorderEnd, startInorder, rootInorder-1);

    }
    if(leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->right = ConstructCore1(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
    }

    return root;
}
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;

    return ConstructCore1(preorder, preorder+length-1, inorder, inorder+length-1);
}


/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/
#include <exception>
#include <cstdio>
#include <stdexcept>
struct BinaryTreeNode
{
    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
};
void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is nullptr.\n");

        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}
void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;

    return ConstructCore(preorder, preorder + length - 1,
                         inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore
        (
                int* startPreorder, int* endPreorder,
                int* startInorder, int* endInorder
        )
{
    // ǰ���������еĵ�һ�������Ǹ�������ֵ
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
        {
            std::logic_error ex("XXXXX");
            throw std::exception(ex);
        }
    }

    // �������������ҵ���������ֵ
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
        std::logic_error ex("XXXXX");
        throw std::exception(ex);
    }


    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        // ����������
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
                                      startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // ����������
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
                                       rootInorder + 1, endInorder);
    }

    return root;
}

// ====================���Դ���====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

// ��ͨ������
//              1
//           /     \
//          2       3
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// ���н��㶼û�����ӽ���
//            1
//           /
//          2
//         /
//        3
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

// ���н��㶼û�����ӽ���
//            1
//             \
//              2
//               \
//                3
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// ����ֻ��һ������
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// ��ȫ������
//              1
//           /     \
//          2       3
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// ������ָ��
void Test6()
{
    Test("Test6", nullptr, nullptr, 0);
}

// �������������в�ƥ��
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
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

