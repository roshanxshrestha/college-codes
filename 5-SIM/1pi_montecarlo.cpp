#include <iostream>
#include <random>
using namespace std;
int main()
{
    // seed random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-1.0, 1.0);

    // number of darts thrown
    int num_darts = 3;

    // keep track of how many darts fall inside the circle
    int num_inside_circle = 0;

    // iterate through each dart
    for (int i = 0; i < num_darts; ++i) {
        // generate random x, y coordinates between -1 and 1
        double x = dis(gen);
        double y = dis(gen);

        // calculate distance from origin
        double distance = x*x + y*y;

        // if the dart is inside the circle (distance <= 1), increment counter
        if (distance <= 1) {
            num_inside_circle++;
        }

        // print x and y coordinates in each iteration
        cout << "x: " << x << ", y: " << y << endl;
    }

    // calculate pi using the formula for the area of a circle
    double pi = 4.0 * num_inside_circle / num_darts;

    // print estimated value of pi
    cout << "Estimated value of pi: " << pi << endl;

    return 0;
}
