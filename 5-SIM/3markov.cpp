#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define the weather states and transition probabilities
const vector<string> WEATHER_STATES = {"sunny", "cloudy", "rainy"};
const map<string, vector<double>> TRANSITIONS = {
    {"sunny", {0.7, 0.2, 0.1}},
    {"cloudy", {0.3, 0.4, 0.3}},
    {"rainy", {0.2, 0.3, 0.5}}
};

// Function to randomly choose a state based on transition probabilities
string getNextState(string currentState) {
    vector<double> probs = TRANSITIONS.at(currentState);
    double r = (double) rand() / RAND_MAX;
    double acc = 0.0;
    for (int i = 0; i < probs.size(); i++) {
        acc += probs[i];
        if (r < acc) {
            return WEATHER_STATES[i];
        }
    }
    return currentState;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Start with a random initial state
    string currentState = WEATHER_STATES[rand() % 3];
    cout << "Starting weather: " << currentState << endl;

    // Predict the weather for the next 7 days
    for (int i = 0; i < 7; i++) {
        currentState = getNextState(currentState);
        cout << "Day " << i+1 << " weather: " << currentState << endl;
    }

    return 0;
}
