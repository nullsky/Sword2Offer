#include <iostream>
using namespace std;

/*
题目1：顺时针打印矩阵
思路参考：https://blog.csdn.net/qq_31851531/article/details/96852426
*/

void PrintMatrixClockwisely(int ** matrix, int rows, int cols);
void PrintCircle(int ** matrix, int rows, int cols, int start);


/*
题目：输入一个n，在屏幕上打印出N*N的矩阵。

例如：输入一个3，则输出：
1 2 3
8 9 4
7 6 5
输入一个4，刚输出：
1  2  3  4
12 13 14  5
11 16 15  6
10  9  8  7
*/
void PrintMatrix(int n);
void CreateMatrix(int** matrix, int n, int start, int & val);

int main()
{
	int rows = 1;
	int cols = 1;
	int **matrix = new int *[rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = i * cols + j;
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	PrintMatrixClockwisely(matrix, rows, cols);

	cout << endl;
	cout << "############# 题目2 #############" << endl;
	PrintMatrix(4);
	system("pause");
	return 0;
}

/*
起点矩形(row, col)：(0, 0), (rows - 1, cols - 1)
中间点：(start, start), (rows - 1 - start, cols - 1 - start)
*/
void PrintMatrixClockwisely(int ** matrix, int rows, int cols)
{
	if (matrix == nullptr || rows < 1 || cols < 1)
		return;

	int start = 0;
	while (start <= rows - 1 - start && start <= cols - 1 - start)
	{
		PrintCircle(matrix, rows, cols, start);
		start++;
	}
}

void PrintCircle(int ** matrix, int rows, int cols, int start)
{
	int row, col;
	
	// 步骤1
	row = start, col = start;
	while (col <= cols - 1 - start)
	{
		cout << matrix[row][col] << "\t";
		col++;
	}

	// 步骤2
	row = start + 1, col = cols - 1 - start;
	while (row <= rows - 1 - start && start < rows - 1 - start)
	{
		cout << matrix[row][col] << "\t";
		row++;
	}

	// 步骤3
	row = rows - 1 - start, col = cols - 1 - start - 1;
	while (col >= start && start < rows - 1 - start && start < cols - 1 - start)
	{
		cout << matrix[row][col] << "\t";
		col--;
	}

	// 步骤4
	row = rows - 1 - start - 1, col = start;
	while (row > start && start < rows - 1 - start && start < cols - 1 - start)
	{
		cout << matrix[row][col] << "\t";
		row--;
	}
}

void PrintMatrix(int n) 
{
	if (n < 1)
		return;

	int ** matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

	int val = 0;
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		CreateMatrix(matrix, n, i, val);
	}

	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void CreateMatrix(int** matrix, int n, int start, int & val)
{
	int row, col;

	// 步骤1
	row = start, col = start;
	while (col <= n - 1 - start)
	{
		val++;
		matrix[row][col] = val;

		col++;
	}

	// 步骤2
	row = start + 1, col = n - 1 - start;
	while (row <= n - 1 - start && start < n - 1 - start)
	{
		val++;
		matrix[row][col] = val;
		row++;
	}

	// 步骤3
	row = n - 1 - start, col = n - 1 - start - 1;
	while (col >= start && start < n - 1 - start)
	{
		val++;
		matrix[row][col] = val;
		col--;
	}

	// 步骤4
	row = n - 1 - start - 1, col = start;
	while (row > start && start < n - 1 - start)
	{
		val++;
		matrix[row][col] = val;
		row--;
	}
}