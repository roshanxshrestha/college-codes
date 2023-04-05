#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (isPrime(n))
        cout << n << " is a prime number" << endl;
    else
        cout << n << " is a composite number" << endl;

    return 0;
}
