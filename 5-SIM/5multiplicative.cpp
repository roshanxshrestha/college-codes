#include <iostream>
#include <cmath>

using namespace std;

// Function to generate random numbers using the Multiplicative Congruential Method
void generateRandomNumbers(int a, int m, int seed, int numRandoms) {
    int x = seed;
    cout << "Random Numbers are \n";
    for (int i = 0; i < numRandoms; i++)
    {
        x = (a * x) % m;
        double randomNum = (double)x;
        cout << randomNum << endl;
    }
}

int main() {
    int a, m, seed, numRandoms;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of m: ";
    cin >> m;
    cout << "Enter the value of seed: ";
    cin >> seed;
    cout << "Enter the number of random numbers to generate: ";
    cin >> numRandoms;
    generateRandomNumbers(a, m, seed, numRandoms);
    return 0;
}
