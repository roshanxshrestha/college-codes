#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    int gcd_ab = gcd(a, b);
    if (gcd_ab == 1)
    {
        cout << a << " and " << b << " are relatively prime." << endl;
    }
    else
    {
        cout << a << " and " << b << " are not relatively prime." << endl;
    }
    return 0;
}
