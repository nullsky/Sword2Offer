#include <iostream>
using namespace std;

/*
题目：反转链表
*/
struct ListNode
{
	int value;
	ListNode * pNext;
};
ListNode * ReverseList(ListNode * head);

/*
递归解法
*/
ListNode * ReverseList2(ListNode * node);

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
	node6->pNext = nullptr;

	ListNode * head = ReverseList2(node1);
	if (head)
		cout << head->value << endl;
	else
		cout << "链表为空" << endl;

	system("pause");
	return 0;
}

ListNode * ReverseList(ListNode * head)
{
	ListNode * pCur = head;
	ListNode * pBefore = nullptr;
	ListNode * pNext;

	while (pCur != nullptr)
	{
		pNext = pCur->pNext;
		pCur->pNext = pBefore;
		
		pBefore = pCur;
		pCur = pNext;
	}
	return pBefore;
}

ListNode * ReverseList2(ListNode * node)
{
	if (node->pNext == nullptr)
		return node;

	ListNode * head = ReverseList2(node->pNext);
	
	node->pNext = nullptr;

	ListNode * tmp = head;
	while (tmp->pNext != nullptr)
		tmp = tmp->pNext;
	tmp->pNext = node;

	return head;
}