#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*
题目：分层打印二叉树
方法：bfs,通过队列实现
*/
struct BinTreeNode
{
	int val;
	BinTreeNode* pLeft;
	BinTreeNode* pRight;
	BinTreeNode(int v, BinTreeNode* left = nullptr, BinTreeNode* right = nullptr)
	{
		val = v;
		pLeft = left;
		pRight = right;
	}
};
void PrintBinTree(BinTreeNode * root);

/*
变形：分行从上到下打印二叉树
*/
void PrintBinTree2(BinTreeNode* root);

/*
变形：之字形从上到下打印
*/
void PrintBinTree3(BinTreeNode* root);

int main()
{
/*测试用例：
			8
	6				10
5		7		9		11
*/
	BinTreeNode * node1 = new BinTreeNode(5);
	BinTreeNode * node2 = new BinTreeNode(7);
	BinTreeNode * node3 = new BinTreeNode(6, node1, node2);
	BinTreeNode * node4 = new BinTreeNode(9);
	BinTreeNode * node5 = new BinTreeNode(11);
	BinTreeNode * node6 = new BinTreeNode(10, node4, node5);
	BinTreeNode * node7 = new BinTreeNode(8, node3, node6);

	PrintBinTree3(node7);
	system("pause");
	return 0;
}

void PrintBinTree(BinTreeNode * root)
{
	if (root == nullptr)
		return;

	queue<BinTreeNode*> que;
	que.push(root);
	while (!que.empty())
	{
		BinTreeNode * node = que.front();
		que.pop();

		cout << node->val << "\t";
		
		if (node->pLeft)
			que.push(node->pLeft);
		if (node->pRight)
			que.push(node->pRight);
	}
}

void PrintBinTree2(BinTreeNode* root)
{
	if (root == nullptr)
		return;

	queue<BinTreeNode*> que;
	que.push(root);
	int nextCnt = 0;
	int toBePrint = 1;
	while (!que.empty())
	{
		BinTreeNode* node = que.front();
		que.pop();
		cout << node->val << "\t";

		if (node->pLeft)
		{
			que.push(node->pLeft);
			nextCnt++;
		}
		if (node->pRight)
		{
			que.push(node->pRight);
			nextCnt++;
		}

		toBePrint--;
		if (toBePrint == 0)
		{
			cout << "\n";
			toBePrint = nextCnt;
			nextCnt = 0;
		}
	}
}

void PrintBinTree3(BinTreeNode* root)
{
	if (root == nullptr)
		return;

	stack<BinTreeNode*> stk[2];
	int index = 0;
	stk[index].push(root);
	int toBePrint = 1;
	int nextCnt = 0;
	while (!stk[index].empty())
	{
		BinTreeNode* node = stk[index].top();
		stk[index].pop();
		cout << node->val << "\t";

		if (index == 0)
		{
			if (node->pLeft)
			{
				stk[1].push(node->pLeft);
				nextCnt++;
			}
			if (node->pRight)
			{
				stk[1].push(node->pRight);
				nextCnt++;
			}
		}
		else
		{
			if (node->pRight)
			{
				stk[0].push(node->pRight);
				nextCnt++;
			}
			if (node->pLeft)
			{
				stk[0].push(node->pLeft);
				nextCnt++;
			}			
		}

		toBePrint--;
		if (toBePrint == 0)
		{
			cout << endl;
			toBePrint = nextCnt;
			nextCnt = 0;
			index = 1 - index;
		}
	}
}
