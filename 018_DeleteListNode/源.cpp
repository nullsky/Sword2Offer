#include <iostream>
using namespace std;

struct ListNode
{
	int value;
	ListNode * pNext;
	ListNode(int v)
	{
		value = v;
		pNext = nullptr;
	}
};

void DelteNode(ListNode ** head, ListNode * node);

int main()
{
	ListNode * p = new ListNode(1);
	ListNode * p1 = new ListNode(2);
	ListNode * p2 = new ListNode(3);
	p->pNext = p1;
	p1->pNext = p2;
	DelteNode(&p, p1);
	ListNode * phead = p;
	system("pause");
	return 0;
}

void DelteNode(ListNode ** head, ListNode * node)
{
	if (head == nullptr || (*head) == nullptr || node == nullptr)
		return;

	ListNode * toBeDelte = nullptr;
	if ((*head) == node)
	{
		toBeDelte = *head;
		*head = (*head)->pNext;
	}
	else if (node->pNext == nullptr)
	{
		ListNode * pNode = *head;
		while(pNode->pNext != nullptr && pNode->pNext != node)
		{
			pNode = pNode->pNext;
		}
		pNode->pNext = nullptr;
		toBeDelte = node;
	}
	else
	{
		toBeDelte = node->pNext;
		node->value = toBeDelte->value;
		node->pNext = toBeDelte->pNext;
	}

	if (toBeDelte)
	{
		delete toBeDelte;
		toBeDelte = nullptr;
	}
}