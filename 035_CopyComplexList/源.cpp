#include <iostream>
using namespace std;

/*
��Ŀ����������ĸ���
˼·��
	1.���ƽڵ㲢������ԭ�ڵ�֮��
	2.��ʼ��sibling�ڵ�ָ��
	3.��������ƵĽڵ�
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

	// �������ӽڵ�
	ComplexListNode* node = head;
	while (node != nullptr)
	{
		ComplexListNode* copyNode = new ComplexListNode(node->val);
		copyNode->next = node->next;
		node->next = copyNode;
		node = copyNode->next;
	}

	// ��ʼ��sibling
	node = head;
	while (node != nullptr)
	{
		ComplexListNode* copyNode = node->next;
		if (node->sibling != nullptr)
			copyNode->sibling = node->sibling->next;
		node = copyNode->next;
	}

	// ��������Ƶ�����
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