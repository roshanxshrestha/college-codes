#include <iostream>
#include <cmath>

using namespace std;

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
void generateKeys(int p, int g, int &a, int &h)
{
    // Choose a random integer a between 1 and p-2
    a = rand() % (p - 2) + 1;

    // Calculate h = g^a (mod p)
    h = modExp(g, a, p);
}

// Function to encrypt a message
void encrypt(int m, int p, int g, int h, int &c1, int &c2)
{
    // Choose a random integer k between 1 and p-2
    int k = rand() % (p - 2) + 1;

    // Calculate c1 = g^k (mod p)
    c1 = modExp(g, k, p);

    // Calculate c2 = m * h^k (mod p)
    c2 = (m * modExp(h, k, p)) % p;
}

// Function to decrypt a ciphertext
int decrypt(int c1, int c2, int p, int a)
{
    // Calculate h^k = (c1^a)^-1 (mod p)
    int hk = modExp(c1, a, p);
    hk = modExp(hk, p - 2, p);

    // Calculate m = c2 * h^k (mod p)
    int m = (c2 * hk) % p;

    return m;
}

int main()
{
    int p, g, a, h, m, c1, c2;

    // Enter the prime number p and generator g
    cout << "Enter the prime number p: ";
    cin >> p;
    cout << "Enter the generator g: ";
    cin >> g;

    // Generate public and private keys
    generateKeys(p, g, a, h);
    cout << "Public key: (" << p << ", " << g << ", " << h << ")" << endl;
    cout << "Private key: " << a << endl;

    // Enter the message to be encrypted
    cout << "Enter the message to be encrypted: ";
    cin >> m;

    // Encrypt the message
    encrypt(m, p, g, h, c1, c2);
    cout << "Ciphertext: (" << c1 << ", " << c2 << ")" << endl;

    // Decrypt the ciphertext
    int decrypted = decrypt(c1, c2, p, a);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
