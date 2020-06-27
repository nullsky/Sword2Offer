#include <iostream>
using namespace std;

/*
题目1：链表中的倒数第k个节点
思路：2个指针，间隔k-1，前面的指针指向尾节点，另一个就指向倒数第k个节点
时间复杂度：O(n) 空间复杂度：O(1)
*/
struct ListNode
{
	int value;
	ListNode * pNext;
};
ListNode * LastKNode(ListNode * head, int k);

/*
题目2：求链表的中间节点
*/
ListNode * GetMidNode(ListNode * head);

int main()
{
	ListNode * node1 = new ListNode;
	node1->value = 1;
	ListNode * node2 = new ListNode;
	node2->value = 2;
	ListNode * node3 = new ListNode;
	node3->value = 3;
	ListNode * node4 = new ListNode;
	node4->value = 4;
	ListNode * node5 = new ListNode;
	node5->value = 5;
	ListNode * node6 = new ListNode;
	node6->value = 6;
	node1->pNext = node2;
	node2->pNext = node3;
	node3->pNext = node4;
	node4->pNext = node5;
	node5->pNext = nullptr;
	node6->pNext = nullptr;

	ListNode * lastKNode = LastKNode(node1, 1);
	if (lastKNode)
		cout << lastKNode->value << endl;
	else
		cout << "不在范围。" << endl;

	cout << endl;
	ListNode * midNode = GetMidNode(node1);
	if (midNode)
		cout << midNode->value << endl;
	else
		cout << "list is null." << endl;

	system("pause");
	return 0;
}

ListNode * LastKNode(ListNode * head, int k)
{
	if (head == nullptr || k < 1)
		return nullptr;

	ListNode * pRes = head;
	ListNode * pTmp = head;

	int step = 0;
	while (pTmp->pNext != nullptr)
	{
		pTmp = pTmp->pNext;
		step++;
		if (step >= k)
			pRes = pRes->pNext;
	}

	if (step + 1 >= k)
		return pRes;
	else
		return nullptr;
}

ListNode * GetMidNode(ListNode * head)
{
	if (head == nullptr)
		return nullptr;

	ListNode * pForward = head;
	ListNode * pBack = head;
	while (pForward != nullptr && pForward->pNext != nullptr) /*必须判断 pNext!= nullptr,才表示尾节点*/
	{
		pForward = pForward->pNext;
		if (pForward->pNext != nullptr)	
			pForward = pForward->pNext;

		pBack = pBack->pNext;
	}
	return pBack;
}