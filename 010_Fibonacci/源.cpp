#include <iostream>
using namespace std;

/*
求Fibonacci数列的第n项, 
f(0) = 0, n = 0
f(1) = 1, n = 1
...
f(n) = f(n-2) + f(n - 1), n > 1
三种实现方法，建议数列数据结构使用 long long，
应用：青蛙跳台阶
*/
int FibonacciNum1(int n);	/*循环实现*/
int FibonacciNum2(int n);	/*递归实现*/

struct Matrix_2x2
{
	Matrix_2x2() {}
	Matrix_2x2(int M00, int M01, int M10, int M11)
	{
		M[0] = M00; M[1] = M01; M[2] = M10; M[3] = M11;
	}

	int M[4];
	Matrix_2x2 operator*(const Matrix_2x2 & B)
	{
		Matrix_2x2 C;
		C.M[0] = this->M[0] * B.M[0] + this->M[1] * B.M[2];
		C.M[1] = this->M[0] * B.M[1] + this->M[1] * B.M[3];
		C.M[2] = this->M[2] * B.M[0] + this->M[3] * B.M[2];
		C.M[3] = this->M[2] * B.M[1] + this->M[3] * B.M[3];
		return C;
	}
};
Matrix_2x2 MMultiply(int n); 
int FibonacciNum3(int n);	/*数学方法：O(logn)*/

int main()
{
	cout << FibonacciNum1(45) << endl;
	cout << FibonacciNum2(10) << endl;
	cout << FibonacciNum3(30) << endl;
	system("pause");
	return 0;
}

int FibonacciNum1(int n)
{
	if (n < 0) return -1;
 	if (n == 0) return 0;
	if (n == 1) return 1;

	int f_n_2 = 0;
	int f_n_1 = 1;
	int f_n;
	for (int i = 2; i <= n; i++)
	{
		f_n = f_n_2 + f_n_1;
		f_n_2 = f_n_1;
		f_n_1 = f_n;
	}
	return f_n;
}

int FibonacciNum2(int n)
{
	if (n < 0) return -1;
	if (n == 0)	return 0;
	if (n == 1) return 1;

	return FibonacciNum2(n - 2) + FibonacciNum2(n - 1);
}

Matrix_2x2 MMultiply(int n)
{
	if (n == 1)
		return Matrix_2x2(1, 1, 1, 0);

	if (n % 2 == 0)
		return MMultiply(n / 2) * MMultiply(n / 2);
	else
		return MMultiply((n - 1) / 2) * MMultiply((n - 1) / 2) * Matrix_2x2(1, 1, 1, 0);
}

int FibonacciNum3(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	Matrix_2x2 m = MMultiply(n - 1);
	return m.M[0];
}