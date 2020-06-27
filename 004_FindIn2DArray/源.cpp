#include <iostream>
using namespace std;

bool find(int * matrix, int rows, int cols, int num)
{
	if (matrix == nullptr || rows <= 0 || cols <= 0)
		return false;

	int row = 0;
	int col = cols - 1;
	while (row < rows && col >= 0)
	{
		if (num < matrix[row * cols + col])
			col--;
		else if (num > matrix[row * cols + col])
			row++;
		else
			return true;
	}
	return false;
}

int main()
{
	int matrix[] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	cout << find(matrix, 4, 4, 7) << endl;
	
	char * str1 = "hello world";
	char * str2 = "hello world";
	cout << *str1 << "\t" << *str2;

	system("pause");
	return 0;
}
