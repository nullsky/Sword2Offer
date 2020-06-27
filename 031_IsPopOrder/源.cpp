#include <iostream>
#include <stack>
using namespace std;

/*
题目：栈的压入、弹出序列
*/
bool IsPopOrder(const int* pPush, const int* pPop, int length);

int main()
{
	int arrPush[5] = { 1,2,3,4,5 };
	int arrPop[5] = { 4,3,2,1, 5};
	cout << IsPopOrder(arrPush, arrPop, 5) << endl;
	system("pause");
	return 0;
}

bool IsPopOrder(const int* pPush, const int* pPop, int length)
{
	if (pPush == nullptr || pPop == nullptr || length < 1)
		return false;

	stack<int> stkData;
	const int* pNextPush = pPush;
	const int* pNextPop = pPop;

	while (pNextPop - pPop < length)
	{
		while (stkData.empty() || *pNextPop != stkData.top())
		{
			if (pNextPush - pPush >= length)
				break;

			stkData.push(*pNextPush);
			pNextPush++;
		}

		if (stkData.top() != *pNextPop)
			break;

		stkData.pop();
		pNextPop++;
	}

	if (stkData.empty() && pNextPop - pPop == length)
		return true;
	
	return false;
}