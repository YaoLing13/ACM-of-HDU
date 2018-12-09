/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

#pragma once

struct BinaryTreeNode 
{
    int                    m_nValue; 
    BinaryTreeNode*        m_pLeft;  
    BinaryTreeNode*        m_pRight; 
};

//__declspec( dllexport )
BinaryTreeNode* CreateBinaryTreeNode(int value);
//__declspec( dllexport )
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
//__declspec( dllexport )
void PrintTreeNode(const BinaryTreeNode* pNode);
//__declspec( dllexport )
void PrintTree(const BinaryTreeNode* pRoot);
//__declspec( dllexport )
void DestroyTree(BinaryTreeNode* pRoot);
