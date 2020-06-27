#include <iostream>
using namespace std;

/*
��Ŀ1�������еĵ�����k���ڵ�
˼·��2��ָ�룬���k-1��ǰ���ָ��ָ��β�ڵ㣬��һ����ָ������k���ڵ�
ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O(1)
*/
struct ListNode
{
	int value;
	ListNode * pNext;
};
ListNode * LastKNode(ListNode * head, int k);

/*
��Ŀ2����������м�ڵ�
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
		cout << "���ڷ�Χ��" << endl;

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
	while (pForward != nullptr && pForward->pNext != nullptr) /*�����ж� pNext!= nullptr,�ű�ʾβ�ڵ�*/
	{
		pForward = pForward->pNext;
		if (pForward->pNext != nullptr)	
			pForward = pForward->pNext;

		pBack = pBack->pNext;
	}
	return pBack;
}