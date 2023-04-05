#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to compute the mean of a given sequence
double compute_mean(const vector<double>& sequence)
{
    double sum = 0.0;
    for (const auto& x : sequence)
        sum += x;
    return sum / static_cast<double>(sequence.size());
}

// Function to compute the autocorrelation function of a given sequence
vector<double> compute_autocorrelation(const vector<double>& sequence)
{
    vector<double> autocorrelation(sequence.size());
    const double mean = compute_mean(sequence);

    for (int k = 0; k < static_cast<int>(sequence.size()); ++k)
    {
        double sum = 0.0;
        for (int i = 0; i < static_cast<int>(sequence.size()) - k; ++i)
            sum += (sequence[i] - mean) * (sequence[i + k] - mean);
        autocorrelation[k] = sum / (sequence.size() - k);
    }

    return autocorrelation;
}

// Function to check if the autocorrelation values are significant
bool is_significant(const vector<double>& autocorrelation, const double z)
{
    const int n = static_cast<int>(autocorrelation.size());

    // Compute the standard error
    double standard_error = 1.0 / sqrt(n);

    // Check if any autocorrelation value exceeds the critical value
    for (int k = 1; k < n; ++k)
    {
        const double autocorr = autocorrelation[k];
        const double upper_bound = z * standard_error;
        if (abs(autocorr) > upper_bound)
            return true;
    }

    return false;
}

// Main function
int main()
{
    // Get input sequence (10 numbers)
    vector<double> sequence(10);
    cout << "Enter 10 numbers: ";
    for (auto& x : sequence)
        cin >> x;

    // Compute the autocorrelation of the input sequence
    vector<double> autocorrelation = compute_autocorrelation(sequence);

    // Check if the autocorrelation values are significant
    const double z = 1.96;
    if (is_significant(autocorrelation, z))
        cout << "The autocorrelation values are significant." << endl;
    else
        cout << "The autocorrelation values are not significant." << endl;

    return 0;
}
