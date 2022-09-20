#include <stdio.h>
int main()
{
	float r, l, s;
	printf("Enter the radius = ");
	scanf_s("%f", &r);
	s = 3.14 * r * r;
	l = 2 * 3.14 * r;
	printf("square = %.2f\n", s);
	printf("length = %.2f\n", l);
	return 0;
}
