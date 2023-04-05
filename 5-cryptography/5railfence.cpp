#include <iostream>
#include <string>
using namespace std;

string encryptRailFence(string plaintext, int key)
{
    string ciphertext;
    int n = plaintext.length();
    int cycle = 2 * (key - 1);

    for (int i = 0; i < key; i++)
    {
        for (int j = i; j < n; j += cycle)
        {
            ciphertext += plaintext[j];
            if (i > 0 && i < key - 1 && j + cycle - 2 * i < n)
            {
                ciphertext += plaintext[j + cycle - 2 * i];
            }
        }
    }

    return ciphertext;
}

string decryptRailFence(string ciphertext, int key)
{
    string plaintext;
    int n = ciphertext.length();
    int cycle = 2 * (key - 1);
    int pos;

    for (int i = 0; i < n; i++)
    {
        pos = i % cycle;
        if (pos < key)
        {
            plaintext += ciphertext[i + cycle - 2 * pos];
        }
        else
        {
            plaintext += ciphertext[i - cycle + 2 * (key - pos - 1)];
        }
    }

    return plaintext;
}

int main()
{
    string plaintext, ciphertext, decryptedtext;
    int key;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter key: ";
    cin >> key;

    ciphertext = encryptRailFence(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    decryptedtext = decryptRailFence(ciphertext, key);
    cout << "Decrypted text: " << plaintext << endl;

    return 0;
}
