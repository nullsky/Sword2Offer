#include <iostream>
#include <vector>
using namespace std;

/*
题目：从根节点到叶节点路径，输出所有满足和为给定值的路径
前序遍历、递归
*/
struct BinTreeNode
{
	int val;
	BinTreeNode* left;
	BinTreeNode* right;
	BinTreeNode(int v, BinTreeNode* l = nullptr, BinTreeNode* r = nullptr)
		:val(v), left(l), right(r) {}
};
void PrintValidPath(BinTreeNode* root, int expectedSum);
void PrintValidPathCore(BinTreeNode* node, int expectedSum, vector<int>& path, int& sum);

int main()
{
	BinTreeNode * node1 = new BinTreeNode(4);
	BinTreeNode * node2 = new BinTreeNode(7);
	BinTreeNode * node3 = new BinTreeNode(5, node1, node2);
	BinTreeNode * node4 = new BinTreeNode(12);
	BinTreeNode * node5 = new BinTreeNode(10, node3, node4);
	PrintValidPath(node5, 12);
	system("pause");
	return 0;
}

void PrintValidPath(BinTreeNode* root, int expectedSum)
{
	if (root == nullptr)
		return;

	vector<int> path;
	int sum = 0;
	PrintValidPathCore(root, expectedSum, path, sum);
}

void PrintValidPathCore(BinTreeNode* node, int expectedSum, vector<int>& path, int& sum)
{
	path.push_back(node->val);
	sum += node->val;
	
	if (node->left == nullptr && node->right == nullptr && sum == expectedSum)
	{
		vector<int>::iterator it = path.begin();
		for(; it != path.end(); it++)
			cout << *it << "\t";
		cout << endl;
	}

	if (node->left != nullptr)
		PrintValidPathCore(node->left, expectedSum, path, sum);
	if (node->right != nullptr)
		PrintValidPathCore(node->right, expectedSum, path, sum);

	path.pop_back();
	sum -= node->val;
}