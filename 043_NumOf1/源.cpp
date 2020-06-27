#include <iostream>
using namespace std;

/*
题目：求1-n中十进制表示1的数量
*/
int CountOf1(int n);

int main()
{
	cout << CountOf1(12) << endl;
	system("pause");
	return 0;
}

int CountOf1(int n)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		// 数字i中1的个数
		int tmp = i;
		int tmpCnt = 0;
		while (tmp != 0)
		{
			if (tmp % 10 == 1)
				tmpCnt++;
			tmp /= 10;
		}
		cnt += tmpCnt;
	}
	return cnt;
}