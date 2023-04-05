// C program for calculating derivative using forward difference formula
#include <stdio.h>
#include <math.h>
#define f(x) x *x
int main()
{
	float h, x, d;
	printf("Enter the value at which derivative is required\n");
	scanf("%f", &x);
	printf("enter the increment h\n");
	scanf("%f", &h);
	d = ((f(x + h)) - (f(x))) / h; // formula for forward diff-
	printf("value of Forward derivative=%f\n", d);
	return 0;
}