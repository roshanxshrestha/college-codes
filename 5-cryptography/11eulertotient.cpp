#include <iostream>

using namespace std;

int phi(int n)
{
    int result = n; // Initialize result as n

    // Consider all prime factors of n and subtract their multiples from result
    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
            {
                n /= p;
            }
            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n), add it to the result
    if (n > 1)
    {
        result -= result / n;
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "The value of Euler's totient function for " << n << " is " << phi(n) << endl;
    return 0;
}
