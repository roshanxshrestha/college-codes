#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr)); // seed the random number generator
    const int numSteps = 10;        // number of steps to take
    int position = 0;               // starting position
    for (int i = 0; i < numSteps; i++)
    {
        int step = std::rand() % 2 == 0 ? 1 : -1; // take a step to the left or right with equal probability
        position += step;
        std::cout << "Step " << i + 1 << ": " << step << ", position: " << position << std::endl;
    }
    return 0;
}
