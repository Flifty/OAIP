#include<stdio.h>
#include<math.h>
int main()
{
	float x1, x2, x3, y1, y2, y3, a, b, c;
	printf("x1=");
	scanf_s("%f", &x1);
	printf("x2=");
	scanf_s("%f", &x2);
	printf("x3=");
	scanf_s("%f", &x3);
	printf("y1=");
	scanf_s("%f", &y1);
	printf("y2=");
	scanf_s("%f", &y2);
	printf("y3=");
	scanf_s("%f", &y3);
	a = sqrt(x1 * x1 + y1 * y1);
	b = sqrt(x2 * x2 + y2 * y2);
	c = sqrt(x3 * x3 + y3 * y3);
	if (a < b && a < c)
	{
		printf("point A is closer");
		return 0;
	}
	if (b < a && b < c)
	{
		printf("point B is closer");
		return 0;
	}
	if (c < a && c < b)
	{
		printf("point C is closer");
		return 0;
	}
	return 0;
}
