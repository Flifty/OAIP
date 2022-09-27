#include <stdio.h>
int main()
{
	int a;
	for (int a = 1000; a < 10000; a++)
	{
		if (a % 2 == 0 && a % 7 == 0 && a % 11 == 0 && (a / 1000 + (a / 100 - a / 1000 * 10) + (a / 10 - a / 100 *10) + (a - a / 10 * 10)) == 30)
		{
			printf("Number:%d\n", a);
		}
	}
	return 0;
} 
