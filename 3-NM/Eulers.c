// Euler's method to solve ODE//
#include <stdio.h>
#include <math.h>
#define f(x, y) 2 * y / x
int main()
{
	float x, xp, x0, y0, y, h;
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
		y = y + f(x, y) * h;
	}
	printf("Function value at x=%f is %f\n", xp, y);
	return 0;
}
