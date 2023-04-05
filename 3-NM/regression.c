//Fitting the curve of the type y=a+bx//
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i,n;
	float x,y,a,b,sumx,sumy,sumxy,sumxsq,denom;
	printf("enter the value of n\n");
	scanf("%d",&n);
	sumxsq=0;
	sumx=0;
	sumy=0;
	sumxy=0;
	for(i=1;i<=n;i++)
	{
		printf("give the value of x\n");
		scanf("%f",&x);
		printf("give the value of y\n");
		scanf("%f",&y);
		sumx=sumx+x;
		sumxsq=sumxsq+x*x;
		sumy=sumy+y;
		sumxy=sumxy+x*y;
	}
		denom=n*sumxsq-sumx*sumx;
		a=(sumy*sumxsq-sumx*sumxy)/denom;
		b=(n*sumxy-sumx*sumy)/denom;
		printf("the value of a0 is %f\n",a);
		printf("the value of a1 is %f\n",b);
	return 0;
}
