#include <stdio.h>
int main()
{
	int f = 0, f1 = 1, f2 = 1, n;
	printf("n = ");
	scanf_s("%d", &n);
	while (f < n)
	{
		f = f1 + f2;
		f2 = f1;
		f1 = f;
	}
	if (n == f)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	return 0;
}
