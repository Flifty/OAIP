#include<stdio.h>
int main()
{
	float a, b, c, d;
	printf("Enter a\n");
	scanf_s("%f", &a);
	printf("Enter b\n");
	scanf_s("%f", &b);
	printf("Enter c\n");
	scanf_s("%f", &c);
	if (a > b && a > c)
	{
		d = a;
		printf("d = %f", d);
		return 0;
	}
	if (b > a && b > c)
	{
		d = b;
		printf("d = %f", d);
		return 0;
	}
	if (c > a && c > b)
	{
		d = c;
		printf("d = %f", d);
		return 0;
	}
	return 0;
}
