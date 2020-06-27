#include <iostream>
using namespace std;

/*
题目：合并有序链表
*/
struct ListNode
{
	int value;
	ListNode * pNext;
};
ListNode * MergeList(ListNode * head1, ListNode * head2);

/*
递归解法
*/
ListNode * MergeList_Recursive(ListNode * head1, ListNode * head2);

int main()
{
	ListNode * node1 = new ListNode;
	node1->value = 1;
	ListNode * node2 = new ListNode;
	node2->value = 2;
	ListNode * node3 = new ListNode;
	node3->value = 10;
	ListNode * node4 = new ListNode;
	node4->value = 4;
	ListNode * node5 = new ListNode;
	node5->value = 10;
	ListNode * node6 = new ListNode;
	node6->value = 11;
	node1->pNext = node2;
	node2->pNext = node3;
	node3->pNext = nullptr;
	node4->pNext = node5;
	node5->pNext = node6;
	node6->pNext = nullptr;

	ListNode * head = MergeList_Recursive(node1, node4);
	system("pause");
	return 0;
}

ListNode * MergeList(ListNode * head1, ListNode * head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;

	ListNode * head = nullptr;
	if (head1->value > head2->value)
	{
		head = head2;
		head2 = head2->pNext;
	}
	else
	{
		head = head1;
		head1 = head1->pNext;
	}
	ListNode * tmp = head;
	
	while (head1 != nullptr && head2 != nullptr)
	{
		if (head1->value > head2->value)
		{
			tmp->pNext = head2;
			head2 = head2->pNext;
			tmp = tmp->pNext;
		}
		else
		{
			tmp->pNext = head1;
			head1 = head1->pNext;
			tmp = tmp->pNext;
		}
	}
	
	if (head1 != nullptr)
		tmp->pNext = head1;
	if (head2 != nullptr)
		tmp->pNext = head2;
	
	return head;
}

ListNode * MergeList_Recursive(ListNode * head1, ListNode * head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;

	if (head1->value > head2->value)
	{
		head2->pNext = MergeList_Recursive(head1, head2->pNext);
		return head2;
	}
	else
	{
		head1->pNext = MergeList_Recursive(head1->pNext, head2);
		return head1;
	}
}