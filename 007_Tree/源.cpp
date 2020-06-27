#include <iostream>
#include <exception>
using namespace std;

/*题目：输入二叉树的前序遍历和中序遍历，设不含重复元素，构建二叉树，输出头节点*/
struct BinTreeNode
{
	int value;
	BinTreeNode * left;
	BinTreeNode * right;
};

BinTreeNode * construct(int * preOrder, int * inOrder, int length);
BinTreeNode * constructCore(int * preStart, int * preEnd, int * inStart, int * inEnd);

int main()
{
	int preArr[8] = { 1,2,4,7,3,5,6,8 };
	int inArr[8] = { 4,7,2,1,5,3,8,6};

	BinTreeNode * tree = construct(preArr, inArr, 8);
	system("pause");
	return 0;
}

BinTreeNode * construct(int * preOrder, int * inOrder, int length)
{
	if (preOrder == nullptr || inOrder == nullptr || length <= 0)
		return nullptr;

	return constructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);

}

BinTreeNode * constructCore(int * preStart, int * preEnd, int * inStart, int * inEnd)
{
	if (preStart > preEnd || inStart > inEnd) return nullptr;

	BinTreeNode * tree = new BinTreeNode;
	tree->value = preStart[0];
	tree->left  = nullptr;
	tree->right = nullptr;

	int * tmp = inStart;
	int cnt = 0;
	while (tmp != inEnd)
	{
		if (*tmp != tree->value)
		{
			cnt++;
			tmp++;
		}
		else
			break;
	}
	if (*(inStart + cnt) != tree->value)	throw exception("Invalid Input");
	tree->left  = constructCore(preStart + 1, preStart + cnt, inStart, inStart + cnt - 1);
	tree->right = constructCore(preStart + cnt + 1, preEnd, inStart + cnt + 1, inEnd);
	return tree;
}
