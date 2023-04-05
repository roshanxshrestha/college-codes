//C program for calculating derivative using central difference formula
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) x*x
int main()
{
	float h,x,d;
	printf("Enter the value at which derivative is required\n");
	scanf("%f",&x);
	printf("inter the increment h\n");
	scanf("%f",&h);
	d=((f(x+h))-(f(x-h)))/2*h; // Formula for central diff
	printf("value of derivative=%f\n",d);
	return 0;
}
