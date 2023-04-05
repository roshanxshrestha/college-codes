#include <iostream>

// Generates a sequence of pseudo-random numbers using the linear congruential method
void linearCongruential(int seed, int a, int c, int m, int n)
{
    std:: cout << "Random Numbers are\n";
    for (int i = 0; i < n; i++)
    {
        seed = (a * seed + c) % m;
        std::cout << seed  << std::endl;
    }
}

int main()
{
    int seed, a, c, m, n;

    std::cout << "Enter the seed value: ";
    std::cin >> seed;

    std::cout << "Enter the value of a: ";
    std::cin >> a;

    std::cout << "Enter the value of c: ";
    std::cin >> c;

    std::cout << "Enter the value of m: ";
    std::cin >> m;

    std::cout << "Enter the number of iterations: ";
    std::cin >> n;

    linearCongruential(seed, a, c, m, n);

    return 0;
}
