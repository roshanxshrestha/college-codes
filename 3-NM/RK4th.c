// R-K 4th order method to solve ODE//
#include <stdio.h>
#include <math.h>
#define f(x, y) 2 * y / x
int main()
{
	float x, xp, x0, y0, y, h, m1, m2, m3, m4;
	printf("Enter initial values of x and y\n");
	scanf("%f%f", &x0, &y0);
	printf("Enter x at which function to be evaluated\n");
	scanf("%f", &xp);
	printf("Enter the step size\n");
	scanf("%f", &h);
	y = y0;
	x = x0;
	for (x = x0; x < xp; x = x + h)
	{
		m1 = f(x, y);
		m2 = f(x + (h / 2), y + (h * m1 / 2));
		m3 = f(x + (h / 2), y + (h * m2 / 2));
		m4 = f(x + h, y + h * m3);
		y = y + h / 6 * (m1 + 2 * m2 + 2 * m3 + m4);
	}
	printf("Function value at x=%f is %f\n", xp, y);
	return 0;
}
