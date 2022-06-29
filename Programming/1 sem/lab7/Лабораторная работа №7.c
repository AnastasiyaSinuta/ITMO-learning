#include <stdio.h>
#include <malloc.h>
void ff1(int**, int);
int ff2(void(*)(int**, int),int**,int);
int* ppArr;
int main()
{
	int dim2 = 10;
	void (*pff1)(int**, int);
	pff1 = ff1;
	int (*pff2)(void(*)(int**, int), int**, int);
	pff2 = ff2;
	printf("%d \n", pff2(pff1, &ppArr, dim2));
	free(ppArr);
	return 0;
}
void ff1(int** pInt, int dim1)
{
	*(pInt)=(int*)malloc(dim1 * sizeof(int));
}
int ff2(void(*pff1)(int**, int), int**pArr, int dim2)
{
	pff1(pArr, dim2);
	for (int i = 0; i < 10; i++)
		ppArr[i] = i * i + 1;
	return ppArr[8];
}