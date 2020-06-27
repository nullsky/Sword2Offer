#include <iostream>
using namespace std;

/*
题目：将一棵二叉树转为排序的双向链表
二叉树的中序遍历
*/
struct BinTreeNode 
{
	int val;
	BinTreeNode* left;
	BinTreeNode* right;
	BinTreeNode(int v, BinTreeNode* l = nullptr, BinTreeNode* r = nullptr)
		:val(v), left(l), right(r) {}
};
BinTreeNode* Convert(BinTreeNode* root);

int main()
{
	BinTreeNode* node1 = new BinTreeNode(4);
	BinTreeNode* node2 = new BinTreeNode(8);
	BinTreeNode* node3 = new BinTreeNode(12);
	BinTreeNode* node4 = new BinTreeNode(16);
	BinTreeNode* node5 = new BinTreeNode(6, node1, node2);
	BinTreeNode* node6 = new BinTreeNode(14, node3, node4);
	BinTreeNode* node7 = new BinTreeNode(10, node5, node6);
	BinTreeNode* head = Convert(node7);
	system("pause");
	return 0;
}

BinTreeNode* Convert(BinTreeNode* root)
{
	if (root == nullptr)
		return nullptr;

	BinTreeNode* head;
	head = Convert(root->left);
	if (head == nullptr)
		head = root;
	else
	{
		BinTreeNode* node = head;
		while (node->right != nullptr)
			node = node->right;
		node->right = root;
		root->left = node;
	}
	BinTreeNode* right = Convert(root->right);
	root->right = right;
	if (right != nullptr) right->left = root;
	return head;
}