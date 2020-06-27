#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

/*
题目：输入流中数据的中位数
思路：
	1.将数据存在一个最大堆和一个最小堆中
	2.用vector结合push_heap\pop_heap,实现堆
	3.第一个数据放在最小堆中，则原数据个数是奇数时，新增数字，添加在最大堆
*/
template<typename T>
class DynamicArray
{
public:
	void Insert(T num)
	{
		int size = m_max.size() + m_min.size();
		if ((size & 1) == 0)
		{
			if (!m_max.empty() && num < m_max[0])
			{
				m_max.push_back(num);
				push_heap(m_max.begin(), m_max.end(), less<T>());
				num = m_max[0];
				pop_heap(m_max.begin(), m_max.end(), less<T>());
				m_max.pop_back();
			}
			m_min.push_back(num);
			push_heap(m_min.begin(), m_min.end(), greater<T>());
		}
		else
		{
			if (!m_min.empty() && num > m_min[0])
			{
				m_min.push_back(num);
				push_heap(m_min.begin(), m_min.end(), greater<T>());
				num = m_min[0];
				pop_heap(m_min.begin(), m_min.end(), greater<T>());
				m_min.pop_back();
			}
			m_max.push_back(num);
			push_heap(m_max.begin(), m_max.end(), less<T>());
		}
	}

	T GetMid()
	{
		int size = m_max.size() + m_min.size();
		if ((size & 1) == 0)
			return (m_min[0] + m_max[0]) / 2;
		else
			return m_min[0];
	}
private:
	vector<T> m_max;
	vector<T> m_min;
};

int main()
{
	DynamicArray<int> nums;
	int num;
	while (cin >> num)
	{
		nums.Insert(num);
		cout <<"\t" << nums.GetMid() << endl;
	}
	system("pause");
	return 0;
}