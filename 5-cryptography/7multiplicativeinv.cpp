#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int findMultiplicativeInverse(int a, int m)
{
    int x, y;
    int gcd = gcdExtended(a, m, &x, &y);
    if (gcd != 1)
    {
        cout << "Multiplicative inverse does not exist." << endl;
        return -1;
    }
    else
    {
        int result = (x % m + m) % m;
        return result;
    }
}

int main()
{
    int a, m;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter the modulus: ";
    cin >> m;
    int inverse = findMultiplicativeInverse(a, m);
    if (inverse != -1)
    {
        cout << "The multiplicative inverse of " << a << " modulo " << m << " is " << inverse << endl;
    }
    return 0;
}
