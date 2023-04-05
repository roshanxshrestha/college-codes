// C program for Fixed point iteratin method
#include <stdio.h>
#include <math.h>
#define f(x) pow(x, 3) - 14 * x + 2
#define G(x) (x * x * x - 7 * x + 2) / (7)
#define e 0.001
int main()
{
	float x0, x1, f0, f1, Er;
	int i = 0;
	printf("Enter initial guess\n");
	scanf("%f", &x0);
	do
	{
		f0 = f(x0);
		x1 = G(x0);
		Er = (x1 - x0) / x1;
		i++;
		printf("no of iterations=%d", i);
		printf("Root=%f\n", x1);
		printf("value of function=%f\n", f1);
	} while (fabs(Er < e));
	return 0;
}
