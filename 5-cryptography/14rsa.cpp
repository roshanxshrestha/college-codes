#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate GCD of two numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate modular exponentiation
int modExp(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to generate public and private keys
void generateKeys(int p, int q, int &n, int &e, int &d)
{
    // Calculate n
    n = p * q;

    // Calculate phi(n)
    int phi = (p - 1) * (q - 1);

    // Choose e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    for (e = 2; e < phi; e++)
    {
        if (gcd(e, phi) == 1)
            break;
    }

    // Calculate d, the modular multiplicative inverse of e modulo phi(n)
    d = 0;
    int k = 1;
    while (true)
    {
        d = (1 + k * phi) / e;
        if ((d * e) % phi == 1)
            break;
        k++;
    }
}

// Function to encrypt a message
int encrypt(int m, int n, int e)
{
    return modExp(m, e, n);
}

// Function to decrypt a ciphertext
int decrypt(int c, int n, int d)
{
    return modExp(c, d, n);
}

int main()
{
    int p, q, n, e, d;
    int m;

    cout << "Enter a prime number p: ";
    cin >> p;
    cout << "Enter another prime number q: ";
    cin >> q;
    cout << "Enter a message to encrypt: ";
    cin >> m;

    generateKeys(p, q, n, e, d);

    int c = encrypt(m, n, e);
    int decrypted_m = decrypt(c, n, d);

    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "n = " << n << endl;
    cout << "e = " << e << endl;
    cout << "d = " << d << endl;
    cout << "Original message: " << m << endl;
    cout << "Encrypted message: " << c << endl;
    cout << "Decrypted message: " << decrypted_m << endl;

    return 0;
}
