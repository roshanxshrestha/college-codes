#include <iostream>
#include <cmath>

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

int main()
{
    int p, g, a, b;
    cout << "Enter a prime number p: ";
    cin >> p;
    cout << "Enter a primitive root modulo p: ";
    cin >> g;
    cout << "Enter a secret integer for Alice: ";
    cin >> a;
    cout << "Enter a secret integer for Bob: ";
    cin >> b;

    int A = mod_pow(g, a, p);
    int B = mod_pow(g, b, p);

    cout << "Alice sends Bob: " << A << endl;
    cout << "Bob sends Alice: " << B << endl;

    int secret_key_Alice = mod_pow(B, a, p);
    int secret_key_Bob = mod_pow(A, b, p);

    if (secret_key_Alice == secret_key_Bob)
    {
        cout << "Shared secret key: " << secret_key_Alice << endl;
    }
    else
    {
        cout << "Error: Secret keys do not match!" << endl;
    }

    return 0;
}
