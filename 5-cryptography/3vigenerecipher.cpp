#include <iostream>
#include <string>

using namespace std;

string encrypt(string message, string key)
{
    string encrypted = "";
    int keyIndex = 0;
    for (int i = 0; i < message.length(); i++)
    {
        char currentChar = message[i];
        char keyChar = key[keyIndex];
        encrypted += (currentChar + keyChar) % 26 + 'A';
        keyIndex = (keyIndex + 1) % key.length();
    }
    return encrypted;
}

string decrypt(string encrypted, string key)
{
    string message = "";
    int keyIndex = 0;
    for (int i = 0; i < encrypted.length(); i++)
    {
        char currentChar = encrypted[i];
        char keyChar = key[keyIndex];
        message += (currentChar - keyChar + 26) % 26 + 'A';
        keyIndex = (keyIndex + 1) % key.length();
    }
    return message;
}

int main()
{
    string message, key;
    cout << "Enter message to encrypt: ";
    getline(cin, message);
    cout << "Enter key: ";
    getline(cin, key);
    string encrypted = encrypt(message, key);
    cout << "Encrypted message: " << encrypted << endl;
    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted message: " << decrypted << endl;
    return 0;
}
