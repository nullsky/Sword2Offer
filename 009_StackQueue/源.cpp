#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*用2个栈实现队列*/
template<typename T>
class CQueue
{
public:
	CQueue() {}
	~CQueue() {}
	
	void push(T value);
	T pop();

private:
	stack<T> m_stack1;
	stack<T> m_stack2;
};

/*用2个队列实现栈*/
template<typename T>
class CStack
{
public:
	CStack() {}
	~CStack() {}

	void push(T value);
	T pop();

private:
	queue<T> m_que1;
	queue<T> m_que2;
};

int main()
{
	CQueue<int> que;
	que.push(100);
	que.push(50);
	que.push(10);
	que.push(1);

	cout << que.pop() << "\t" << que.pop() << "\t" << que.pop() << endl;	/*先计算表达式的值（受编译器影响），
																		然后参数从右向左压栈*/
	CStack<int> stack;
	stack.push(1);
	stack.push(10);
	stack.push(100);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;

	return 0;
}

template<typename T>
void CQueue<T>::push(T value)
{
	m_stack1.push(value);
}

template<typename T>
T CQueue<T>::pop()
{
	if (m_stack2.empty())
	{
		while (!m_stack1.empty())
		{
			T & value = m_stack1.top();
			m_stack1.pop();
			m_stack2.push(value);
		}
	}
	
	if(m_stack2.empty())
	{
		throw exception("queue is empty");
	}

	T v = m_stack2.top();
	m_stack2.pop();
	return v;
}

template<typename T>
void CStack<T>::push(T value)
{
	if (m_que1.empty() && m_que2.empty())
		m_que1.push(value);
	else if (m_que1.empty())
		m_que2.push(value);
	else
		m_que1.push(value);
}

template<typename T>
T CStack<T>::pop()
{
	if (m_que1.empty() && m_que2.empty())
		throw exception("stack is empty");

	T res;
	if (m_que1.empty())
	{
		while (m_que2.size() > 1)
		{
			T & v = m_que2.front();
			m_que2.pop();
			m_que1.push(v);
		}
		res = m_que2.front();
		m_que2.pop();
	}
	else
	{
		while (m_que1.size() > 1)
		{
			T & v = m_que1.front();
			m_que1.pop();
			m_que2.push(v);
		}
		res = m_que1.front();
		m_que1.pop();
	}
	return res;
}