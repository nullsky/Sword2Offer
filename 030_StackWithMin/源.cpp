#include <iostream>
#include <stack>
using namespace std;

/*
题目：包含min函数的栈
说明：实现一个栈，pop(),min(),push(),min返回栈的最小值
*/
template<typename T>
struct StackWithMin
{
	stack<T> m_data;
	stack<T> m_min;

	void push(T val)
	{
		T min;
		if (m_min.empty())
			min = val;
		else
			min = m_min.top();
		min = min > val ? val : min;
		m_min.push(min);
		m_data.push(val);
	}

	void pop()
	{
		if (m_data.empty())
			return;
		m_data.pop();
		m_min.pop();
	}

	T min()
	{
		if (m_min.empty())
			return T();
		return m_min.top();
	}
};

int main()
{
	StackWithMin<int> stk;
	stk.push(3);
	stk.push(4);
	stk.push(0);
	stk.pop();
	stk.pop();
	stk.pop();

	cout << stk.min() << endl;

	system("pause");
	return 0;
}