//4.Pass by reference for swapping the values of two variables
#include<iostream>
using namespace std;
void swap (int &, int &);
int main()
{
    int a=5, b=10;
    cout<<"Before Swapping: a="<<a<<"and b="<<b<<endl;
    swap(a,b);   //call by reference
    cout<<"After Swapping: a="<<a<<"and b="<<b<<endl;
    return 0;
}
void swap(int &x, int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}
