#include <iostream>
using namespace std;

struct BinTreeNode
{
	int val;
	BinTreeNode* left;
	BinTreeNode* right;
};

/*
题目1：镜像二叉树
*/
void MirrorBinTree(BinTreeNode* root);

/*
题目2：判断二叉树是否对称
*/
bool IsSymmetricalTree(BinTreeNode* root);
bool IsMirrorTree1AndTree2(BinTreeNode* tree1, BinTreeNode* tree2);

int main()
{

	system("pause");
	return 0;
}

void MirrorBinTree(BinTreeNode* root)
{
	if (root == nullptr)
		return;

	BinTreeNode* left = root->left;
	BinTreeNode* right = root->right;

	root->left = right;
	root->right = left;
	MirrorBinTree(root->left);
	MirrorBinTree(root->right);
}

bool IsSymmetricalTree(BinTreeNode* root)
{
	if (root == nullptr)
		return true;

	return IsMirrorTree1AndTree2(root->left, root->right);
}

bool IsMirrorTree1AndTree2(BinTreeNode* tree1, BinTreeNode* tree2)
{
	if (tree1 == nullptr && tree2 == nullptr)
		return true;
	else if (tree1 != nullptr && tree2 != nullptr)
	{
		if (tree1->val != tree2->val)
			return false;
		return IsMirrorTree1AndTree2(tree1->left, tree2->right) &&
			IsMirrorTree1AndTree2(tree1->right, tree2->left);
	}
	else
		return false;
}
