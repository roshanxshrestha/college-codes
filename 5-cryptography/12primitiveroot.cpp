#include <iostream>
#include <vector>

using namespace std;

int mod_pow(int base, int exponent, int modulus)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

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

bool is_primitive_root(int g, int p)
{
    int phi = p - 1;
    vector<int> factors;
    int n = phi;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        factors.push_back(n);
    }
    for (int i = 0; i < factors.size(); i++)
    {
        if (mod_pow(g, phi / factors[i], p) == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int p, g;
    cout << "Enter a prime number p: ";
    cin >> p;
    cout << "Enter an integer g: ";
    cin >> g;
    if (is_primitive_root(g, p))
    {
        cout << g << " is a primitive root of " << p << endl;
    }
    else
    {
        cout << g << " is not a primitive root of " << p << endl;
    }
    return 0;
}
