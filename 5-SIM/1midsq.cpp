#include <iostream>
#include <cmath>

// Returns the middle digits of a number
int getMiddleDigits(int num, int numDigits)
{
    int numShift = (numDigits - 4) / 2;
    return (num / (int)pow(10, numShift)) % (int)pow(10, 4);
}

// Generates a sequence of pseudo-random numbers using the mid-square method
void midSquare(int seed, int numDigits, int n)
{
    for (int i = 0; i < n; i++)
    {
        int sq = seed * seed;
        int middle = getMiddleDigits(sq, numDigits);
        seed = middle;
        std::cout << seed << std::endl;
    }
}

int main()
{
    int seed, numDigits, n;

    // Take input from user
    std::cout << "Enter seed value: ";
    std::cin >> seed;
    std::cout << "Enter number of digits in seed: ";
    std::cin >> numDigits;
    std::cout << "Enter number of iterations: ";
    std::cin >> n;

    midSquare(seed, numDigits, n);
    return 0;
}
