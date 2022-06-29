/*Лабораторная работа №2 - Численные массивы*/
#include <stdio.h>
#include <locale.h>
int main()
{	
	/*Часть 1 - Сортировка пузырьком*/
	setlocale(LC_ALL, "Rus");
	printf("Часть 1 - Сортировка пузырьком\n");
	int mas[] = { -2, -1, 1024, 255 };
	printf("Исходный массив:");
	for (int i = 0; i < 4; i++) printf("%d ", mas[i]);
	printf("\n");
	int fl = 0;
	int count_change = 0;
	int count_passes = 0;
	int i = 0;
	for (int j = 3; j >= 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (mas[i] >= mas[i + 1])
			{

				int tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				count_change = count_change + 1;
				fl = fl + 1;
			}
			count_passes = count_passes + 1;
		}
		if (fl == 0) break;
		fl = 0;
	}
	printf("Отсортированный массив:");
	for (int i = 0; i < 4; i++) printf("%d ", mas[i]);
	printf("\n");
	printf("\n%s %d", "Количество обменов:", count_change);
	printf("\n%s %d \n", "Количество проходов:", count_passes);
	printf("\n");
	/*Часть 2 - Двухмерный массив*/
	printf("Часть 2 - Двухмерный массив\n");
	int mas1[3][3] = { {16, 24, 30}, {43, 7, 63}, {73, 82, 132} };
	printf("Дана матрица:\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", mas1[i][j]);
		}
		printf("\n");
	}
	
	printf("\nЗадача 1 - определить минимальный элемент и указать его координаты\n");
	int min = mas1[0][0];
	int min_index_i = 0;
	int min_index_j = 0;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (mas1[i][j] < min)
			{
				min = mas1[i][j];
				min_index_i = i;
				min_index_j = j;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				mas1[i][j] = mas1[min_index_i][min_index_j];
			}
		}
	}
	printf("%s %d\n%s %d %d\n", "Минимальный элемент:", min, "Координаты минимального элемента:", min_index_i, min_index_j);

	printf("\nЗадача 2 - проставить минимальный элемент по главной диагонали\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", mas1[i][j]);
		}
		printf("\n");
	}

	printf("\nЗадача 3 - Записать сумму элементов из первой строки в правый верхний угол матрицы, а сумму элементов последней строки в левый нижний угол матрицы\n");
	int mas2[3][3] = { {16, 24, 30}, {43, 7, 63}, {73, 82, 132} };
	int line = 3;
	int column = 3;
	int sum_first_line = 0;
	int sum_last_line = 0;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (i == 0) sum_first_line += mas2[i][j];
			if (i == line - 1) sum_last_line += mas2[i][j];
		}
	}
	
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (i == 0 && j == column - 1) mas2[i][j] = sum_first_line;
			if (i == line - 1 && j == 0) mas2[i][j] = sum_last_line;
			printf("%d ", mas2[i][j]);
		}
		printf("\n");
	}

	printf("\nЗадача 4 - поменять строки местами\n");
	int mas3[3][3] = { {16, 24, 30}, {43, 7, 63}, {73, 82, 132} };
	int linee = 3;
	int columnn = 3;
	int mass[] = { 0, 0, 0 };
	int line1 = 0;
	int line2 = 2;
	for (int k = 0; k < columnn; k++)
	{
		mass[k] = mas3[line1][k];
		mas3[line1][k] = mas3[line2][k];
		mas3[line2][k] = mass[k];
	}
	for (int i = 0; i < linee; i++)
	{
		for (int j = 0; j < columnn; j++)
		{
			printf("%d ", mas3[i][j]);

		}
		printf("\n");
	}
}