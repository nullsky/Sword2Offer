#include <iostream>
using namespace std;

/*给定一棵二叉树和一个节点，找出中序遍历的下一个节点*/
struct BinTreeNode
{
	char value;
	BinTreeNode * father;
	BinTreeNode * left;
	BinTreeNode * right;
};

BinTreeNode * findNext(BinTreeNode * pNode);

int main()
{
	BinTreeNode * root = new BinTreeNode;
	root->value = 'a';
	root->father = nullptr;
	root->left = nullptr;
	root->right = nullptr;

	BinTreeNode * node1 = new BinTreeNode;
	node1->value = 'b';
	node1->father = nullptr;
	node1->left = nullptr;
	node1->right = nullptr;

	BinTreeNode * node2 = new BinTreeNode;
	node2->value = 'c';
	node2->father = nullptr;
	node2->left = nullptr;
	node2->right = nullptr;

	root->left = node1;
	node1->father = root;
	node1->right = node2;
	node2->father = node1;
	BinTreeNode * node = findNext(node1);
	return 0;
}

BinTreeNode * findNext(BinTreeNode * pNode)
{
	if (pNode == nullptr)
		return nullptr;

	BinTreeNode * next = nullptr;

	if (pNode->right != nullptr)
	{
		BinTreeNode * pRight = pNode->right;
		while (pRight->left)
		{
			pRight = pRight->left;
		}
		next = pRight;
	}
	else if (pNode->father != nullptr)
	{
		BinTreeNode * pCur = pNode;
		BinTreeNode * pFather = pNode->father;
		while (pFather != nullptr && pFather->left != pCur)
		{
			pCur = pFather;
			pFather = pFather->father;
		}
		next = pFather;
	}
	return next;
}