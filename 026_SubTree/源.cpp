#include <iostream>
#include <cmath>
using namespace std;

/*
二叉树的子结构
解体步骤：
	1.找到与tree2根节点相等的节点
	2.判断是否相等
*/
struct BinTreeNode 
{
	double value;
	BinTreeNode * pLeft;
	BinTreeNode * pRight;
};

bool HasSubTree(BinTreeNode * pRoot1, BinTreeNode * pRoot2);
bool DoesTree1HasTree2(BinTreeNode * pTree1, BinTreeNode * pTree2);

int main()
{

	system("pause");
	return 0;
}

bool HasSubTree(BinTreeNode * pRoot1, BinTreeNode * pRoot2)
{
	bool result = false;
	if (pRoot1 != nullptr && pRoot2 != nullptr)
	{
		if (abs(pRoot1->value - pRoot2->value) < 1e-6)
			result = DoesTree1HasTree2(pRoot1, pRoot2);

		if (!result)
			result = HasSubTree(pRoot1->pLeft, pRoot2);

		if (!result)
			result = HasSubTree(pRoot1->pRight, pRoot2);
	}
	return result;
}

bool DoesTree1HasTree2(BinTreeNode * pTree1, BinTreeNode * pTree2)
{
	if (pTree2 == nullptr)
		return true;

	if (pTree1 == nullptr)
		return false;

	if (abs(pTree1->value - pTree2->value) >= 1e-6)
		return false;

	return DoesTree1HasTree2(pTree1->pLeft, pTree2->pLeft) &&
		DoesTree1HasTree2(pTree1->pRight, pTree2->pRight);
}