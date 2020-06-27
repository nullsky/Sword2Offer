#include <iostream>
using namespace std;

/*
题目：复杂链表的复制
思路：
	1.复制节点并链接在原节点之后
	2.初始化sibling节点指针
	3.分离出复制的节点
*/
struct ComplexListNode
{
	int val;
	ComplexListNode* next;
	ComplexListNode* sibling;
	ComplexListNode(int v)
	{
		val = v;
		next = nullptr;
		sibling = nullptr;
	}
};

ComplexListNode* CopyComplexList(ComplexListNode* head);

int main()
{

	system("pause");
	return 0;
}

ComplexListNode* CopyComplexList(ComplexListNode* head)
{
	if (head == nullptr)
		return nullptr;

	// 复制链接节点
	ComplexListNode* node = head;
	while (node != nullptr)
	{
		ComplexListNode* copyNode = new ComplexListNode(node->val);
		copyNode->next = node->next;
		node->next = copyNode;
		node = copyNode->next;
	}

	// 初始化sibling
	node = head;
	while (node != nullptr)
	{
		ComplexListNode* copyNode = node->next;
		if (node->sibling != nullptr)
			copyNode->sibling = node->sibling->next;
		node = copyNode->next;
	}

	// 分离出复制的链表
	ComplexListNode* newHead = head->next;
	ComplexListNode* copyNode = newHead;
	head->next = copyNode->next;
	node = head->next;
	while (node != nullptr)
	{
		copyNode->next = node->next;
		copyNode = copyNode->next;
		node->next = copyNode->next;
		node = node->next;
	}
	return newHead;
}