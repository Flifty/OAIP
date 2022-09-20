#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "rus");
	int a;
	printf("Введите номер семестра:");
	scanf_s("%d", &a);
	if (a == 1)
	{
		printf("Информатика, ин. язык");
		return 0;
	}
	if (a == 2)
	{
		printf("Информатика, ин. язык");
		return 0;
	}
	if (a == 3)
	{
		printf("Культурология, математика, ин. язык");
		return 0;
	}
	if (a == 4)
	{
		printf("Культурология, математика, ин. язык");
		return 0;
	}
	return 0;
}
