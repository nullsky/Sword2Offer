#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int value;
	ListNode * next;
};

/*添加节点*/
void addTail(ListNode ** pHead, int value);
/*删除节点*/
void removeNode(ListNode ** pHead, int value);
/*从尾到头打印*/
void printBack(ListNode * pHead);
/*链表反转*/
void reserve(ListNode ** pHead);

int main()
{
	ListNode * pHead = nullptr;
	addTail(&pHead, 8);
	addTail(&pHead, 42);
	addTail(&pHead, 1);
	addTail(&pHead, 10);
	removeNode(&pHead, 42);
	printBack(pHead);

	cout << endl;
	reserve(&pHead);
	printBack(pHead);

	system("pause");
	return 0;
}

void addTail(ListNode ** pHead, int value)
{
	ListNode * pNew = new ListNode;
	pNew->value = value;
	pNew->next = nullptr;

	if (*pHead == nullptr)
		*pHead = pNew;
	else
	{
		ListNode * pNode = *pHead;
		while (pNode->next != nullptr)
		{
			pNode = pNode->next;
		}
		pNode->next = pNew;
	}
}

void removeNode(ListNode ** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode * pToBeDelte = nullptr;
	if ((*pHead)->value == value)
	{
		pToBeDelte = *pHead;
		*pHead = (*pHead)->next;
	}
	else
	{
		ListNode * pNode = *pHead;
		while (pNode->next != nullptr && pNode->next->value != value)
		{
			pNode = pNode->next;
		}
		
		if (pNode->next != nullptr && pNode->next->value == value)
		{
			pToBeDelte = pNode->next;
			pNode->next = pNode->next->next;
		}
	}
	if (pToBeDelte != nullptr)
	{
		delete pToBeDelte;
		pToBeDelte = nullptr;
	}
}

void printBack(ListNode * pHead)
{
#if 0
	/*使用栈*/
	stack<ListNode*> nodes;

	ListNode * pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->next;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		cout << pNode->value << "\t";
		nodes.pop();
	}
#endif

	/*使用递归*/
	if (pHead == nullptr)
		return;

	printBack(pHead->next);
	cout << pHead->value << "\t";
}

void reserve(ListNode ** pHead)
{
	if (*pHead == nullptr || (*pHead)->next == nullptr)
		return;

	ListNode * pPre;
	ListNode * pNext;
	ListNode * pNode = (*pHead)->next;

	(*pHead)->next = nullptr;
	pPre = (*pHead);
	while (pNode->next != nullptr)
	{
		pNext = pNode->next;
		pNode->next = pPre;

		pPre = pNode;
		pNode = pNext;
	}
	pNode->next = pPre;
	(*pHead) = pNode;
}