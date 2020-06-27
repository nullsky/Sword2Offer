#include <iostream>
#include <stack>
using namespace std;

/*
��Ŀ������min������ջ
˵����ʵ��һ��ջ��pop(),min(),push(),min����ջ����Сֵ
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