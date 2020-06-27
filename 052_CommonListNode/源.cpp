#include <iostream>
using namespace std;

/*
题目：寻找链表的第一个公共节点
找规律，相同节点之后的后续节点均相同
*/
struct Node
{
	int v;
	Node* next;
	Node(int a, Node* n) :v(a), next(n) {}
};

Node* theFirstCommonNode(Node* list1, Node* list2);

int main()
{
	Node* node1 = new Node(0, nullptr);
	Node* node2 = new Node(1, node1);
	Node* node3 = new Node(3, node2);
	Node* node4 = new Node(0, nullptr);
	Node* res = theFirstCommonNode(node4, nullptr);
	system("pause");
	return 0;
}

Node* theFirstCommonNode(Node* list1, Node* list2)
{
	int len1 = 0, len2 = 0;

	Node * head = list1;
	while (head != nullptr)
	{
		len1++;
		head = head->next;
	}

	head = list2;
	while (head != nullptr)
	{
		len2++;
		head = head->next;
	}

	int delta = len1 - len2;
	if (delta > 0)
	{
		for (int i = 0; i < delta; i++)
			list1 = list1->next;
	}
	else
	{
		for (int i = delta; i < 0; i++)
			list2 = list2->next;
	}

	while (list1 != nullptr && list2 != nullptr && (list1->next != list2->next || list1->v != list2->v))
	{
		list1 = list1->next;
		list2 = list2->next;
	}
	return list1;
}
