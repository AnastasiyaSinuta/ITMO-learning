#include <stdio.h>

int main()
{
	/*1. Определить, является ли число 32 степенью двойки*/
	int a = 32;
	if (a & (a - 1)) printf("No\n");
	else printf("Yes \n");

	/*2. Перевести букву "А" в нижний регистр и обратно*/
	char b = 'A';
	printf("%c\n", b);
	b = b | 32;
	printf("%c\n", b);
	b = b & '\xDF';
	printf("%c\n", b);

	/*3. Посчитать количество букв в аббревиатуре "ITMO"*/
	char mas[] = "ITMO";
	int count = 0;
	int i = 0;
	while (mas[i++]) count++;
	printf("%d\n", count);

	/*4. Перевести аббревиатуру "ITMO" в нижний регистр и напечатать последнюю букву*/
	i = 0;
	char mas1[] = "ITMO";
	while (mas1[i])
	{
		mas1[i] = mas1[i] | 32;
		i++;
	}
	printf("%c\n", mas1[3]);

	/*5. Напечатать перевернутую аббревиатуру "ITMO"*/
	i = 0;
	char mas2[] = "ITMO";
	char tmp;
	for (int i = 0, j = count - 1; i < count / 2; i++, j--)
	{
		tmp = mas2[i];
		mas2[i] = mas2[j];
		mas2[j] = tmp;
	}
	printf("%s\n", mas2);

	/*6. Заменить в аббревиатуре "ITMO" букву "T" на символ "#"*/
	i = 0;
	char mas3[] = "ITMO";
	while (mas3[i])
	{
		if (mas3[i] == 'T') mas3[i] = '#';
		i++;
	}
	printf("%s\n", mas3);
	return 0;
}
