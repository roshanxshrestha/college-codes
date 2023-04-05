//Langrange's Interpolation//
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	float x[10],y[10],v,val=0,a;
	int i,j,n;
	printf("Number of points:");
	scanf("%d",&n);
	printf("Enter the values of x:\n");
	for(i=1;i<=n;i++)
	scanf("%f",&x[i]);
	printf("Enter the values of f(x):\n");
	for(i=1;i<=n;i++)
	scanf("%f",&y[i]);
	printf("Enter the value of x where the functional value is determined:\n");
	scanf("%f",&a);
	for(i=1;i<=n;i++)
	{
	v=y[i];
	for(j=1;j<=n;j++)
	{
		if(j!=i)
		v=v*(a-x[j])/(x[i]-x[j]);
	}
	val=val+v;
}
printf("Interpolated value=%f",val);
return 0;
}
