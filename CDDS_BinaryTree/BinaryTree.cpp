/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>
using namespace std;


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	TreeNode* temp = new TreeNode(a_nValue);
	TreeNode* comp = m_pRoot;
	if (m_pRoot == nullptr)
	{
		m_pRoot = temp;
	}
	while (comp != nullptr)
	{
		if (temp->GetData() > comp->GetData())
		{
			if (comp->GetRight() != nullptr)
			{
				comp = comp->GetRight();
			}
			else
			{
				comp->SetRight(temp);
				return;
			}
				
		}
		else if (temp->GetData() < comp->GetData())
		{
			if (comp->GetLeft() != nullptr)
			{
				comp = comp->GetLeft();
			}
			else
			{
				comp->SetLeft(temp);
				return;
			}
		}
		else
		{
			return;
		}
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{


	return false;
}

void BinaryTree::Remove(int a_nValue)
{
	TreeNode* temp = new TreeNode(a_nValue);
	TreeNode* comp = m_pRoot;
	TreeNode* p_comp = comp;
	if (m_pRoot == nullptr)
	{
		m_pRoot = temp;
	}
	while (comp != nullptr)
	{
		if (temp->GetData() > comp->GetData())
		{
			if (comp->GetRight() != nullptr)
			{
				p_comp = comp;
				comp = comp->GetRight();
			}
			else
			{
				return;
			}

		}
		else if (temp->GetData() < comp->GetData())
		{
			if (comp->GetLeft() != nullptr)
			{
				p_comp = comp;
				comp = comp->GetLeft();
			}
			else
			{
				return;
			}
		}
		else
		{
			if (comp->GetLeft == nullptr && comp->GetRight == nullptr)
			{
				//delete comp
				//remove reference from p_comp
			}
			return;
		}
	}
}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}