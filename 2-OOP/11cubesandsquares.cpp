//11. C++ code to implement the inline functions for square and cubes
#include <iostream>
using namespace std;

// Program to create functions using inline...
inline double square(int n)
{
	return n*n;
}

inline float cube(int n)
{
	return n*n*n;
}

int main()
{
	cout<<"\n SQUARE IS  = "<< square(12);
	cout<<"\n CUBE IS = "<< cube(12)<<"\n";
	return 0;
}

