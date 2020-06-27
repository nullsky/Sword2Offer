#include <iostream>
using namespace std;

/*
题目：求含环链表的入口节点
*/
struct ListNode
{
	int value;
	ListNode * pNext;
};
ListNode * GetEntryNode(ListNode * head);
ListNode * IsMeet(ListNode * head);

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
	node5->pNext = node6;
	node6->pNext = node3;

	ListNode * pEntry = GetEntryNode(node1);
	if (pEntry)
		cout << pEntry->value << endl;
	else
		cout << "链表不含环" << endl;

	system("pause");
	return 0;
}

ListNode * GetEntryNode(ListNode * head)
{
	if (head == nullptr)
		return nullptr;

	// 1 判环
	ListNode * meetNode = IsMeet(head);
	if (meetNode == nullptr)
		return nullptr;

	// 2 计算环包含的节点数
	int cnt = 1;
	ListNode * temp = meetNode;
	while (temp->pNext != meetNode)
	{
		cnt++;
		temp = temp->pNext;
	}

	// 3 求入口节点
	ListNode * pForward = head;
	ListNode * pBack = head;
	for (int i = 0; i < cnt; i++)
		pForward = pForward->pNext;
	while (pForward != pBack)
	{
		pForward = pForward->pNext;
		pBack = pBack->pNext;
	}
	return pBack;
}

ListNode * IsMeet(ListNode * head)
{
	if (head == nullptr)
		return nullptr;

	ListNode * pForward = head;
	ListNode * pBack = head;
	do {
		pForward = pForward->pNext;
		if (pForward != nullptr)
			pForward = pForward->pNext;
		pBack = pBack->pNext;		
	} while (pForward != nullptr && pForward != pBack);

	return pForward;

}
