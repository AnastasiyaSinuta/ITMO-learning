/*Лабораторная работа №3*/
#include <stdio.h>
int main()
{	
	int A[3][3] = { {96, 72, 38}, {11, 29, 25}, {47, 71, 34} };
	int sum = 0;
	for (int i = 0; i < 3; i++, sum = 0)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", A[i][j]);
			sum += A[i][j];
		}
		printf("%s %d \n", "	sum = ", sum);
	}
	printf("\n");

	for (int i = 1; i < 3; i++)
	{
		for (int m = 0; m < 3 - i; m++)
		{
			int sumj = 0;
			for (int j = 0; j < 3; j++) sumj += A[m][j];
			int sumk = 0;
			for (int k = 0; k < 3; k++) sumk += A[m + 1][k];
			if (sumj > sumk)
			{
				int tmp[3] = { 0, 0, 0 };
				for (int n = 0; n < 3; n++)
				{
					tmp[n] = A[m][n];
					A[m][n] = A[m + 1][n];
					A[m + 1][n] = tmp[n];
				}
			}
		}
	}

	sum = 0;
	for (int i = 0; i < 3; i++, sum = 0)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", A[i][j]);
			sum += A[i][j];
		}
		printf("%s %d \n", "	sum = ", sum);
	}
	return 0;
}