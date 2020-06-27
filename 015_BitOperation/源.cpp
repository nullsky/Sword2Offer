#include <iostream>
using namespace std;

#define SOLUTION_3
/*
位运算
题目1：输入一个整数，输出其二进制表示的1的个数
*/
int numberOf1(int n);

/*
题目2：判断一个数是否是2的整数次方
*/
bool isPowerOf2(int n);

int main()
{
	int a;
	cin >> a;
	cout << "位运算\n题1：输出整数"<<a<<"的二进制表示的1的数量:\t"<< numberOf1(a) << endl;
	cout << "16进制补码：" << hex << a << endl;
	
	cout << "题2：是否是2的整数次方：\t" <<isPowerOf2(a) << endl;
	system("pause");
	return 0;
}

int numberOf1(int n)
{
	int num = 0;

#ifdef SOLUTION_1
	/*思路1：当n为负数时，死循环*/
	while (n)
	{
		if (n & 1)
			num++;
		n = n >> 1;
	}
#elif defined SOLUTION_2
	/*思路2：不改变原数，左移1。适用于负数，但是一定会进行 sizeof(int)x8 次循环*/
	int tmp = 1;
   	while (tmp)
	{
		if (n & tmp)
			num++;
		tmp = tmp << 1;
	}
#elif defined SOLUTION_3
	/*思路3：减一，然后与操作，把二进制表示的最右一个1变为0*/
	while (n)
	{
		n = (n - 1) & n;
		num++;
	}
#endif
	
	return num;
}

bool isPowerOf2(int n)
{
	/*2的整数次幂，其二进制必然只有一个1*/
	return ((n - 1) & n) == 0 ? true : false;
}