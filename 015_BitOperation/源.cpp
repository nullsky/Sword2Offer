#include <iostream>
using namespace std;

#define SOLUTION_3
/*
λ����
��Ŀ1������һ�����������������Ʊ�ʾ��1�ĸ���
*/
int numberOf1(int n);

/*
��Ŀ2���ж�һ�����Ƿ���2�������η�
*/
bool isPowerOf2(int n);

int main()
{
	int a;
	cin >> a;
	cout << "λ����\n��1���������"<<a<<"�Ķ����Ʊ�ʾ��1������:\t"<< numberOf1(a) << endl;
	cout << "16���Ʋ��룺" << hex << a << endl;
	
	cout << "��2���Ƿ���2�������η���\t" <<isPowerOf2(a) << endl;
	system("pause");
	return 0;
}

int numberOf1(int n)
{
	int num = 0;

#ifdef SOLUTION_1
	/*˼·1����nΪ����ʱ����ѭ��*/
	while (n)
	{
		if (n & 1)
			num++;
		n = n >> 1;
	}
#elif defined SOLUTION_2
	/*˼·2�����ı�ԭ��������1�������ڸ���������һ������� sizeof(int)x8 ��ѭ��*/
	int tmp = 1;
   	while (tmp)
	{
		if (n & tmp)
			num++;
		tmp = tmp << 1;
	}
#elif defined SOLUTION_3
	/*˼·3����һ��Ȼ����������Ѷ����Ʊ�ʾ������һ��1��Ϊ0*/
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
	/*2���������ݣ�������Ʊ�Ȼֻ��һ��1*/
	return ((n - 1) & n) == 0 ? true : false;
}