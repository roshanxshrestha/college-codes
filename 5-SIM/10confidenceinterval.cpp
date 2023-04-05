#include <iostream>
#include <cmath>
using namespace std;

double z_value(double confidence_level);

int main() {
  int n = 0;
  double sample_mean, population_mean, sample_stddev, confidence_level, margin_of_error, lower_bound, upper_bound;

  // Input sample data
  double sum = 0;
  cout << "Enter sample size: ";
  cin >> n;
  double x;
  for (int i = 0; i < n; i++) {
    cout << "Enter data point " << i + 1 << ": ";
    cin >> x;
    sum += x;
  }
  sample_mean = sum / n;

  // Input population mean
  cout << "Enter population mean: ";
  cin >> population_mean;

  // Input sample standard deviation
  cout << "Enter sample standard deviation: ";
  cin >> sample_stddev;

  // Input confidence level
  cout << "Enter confidence level (as a decimal): ";
  cin >> confidence_level;

  // Calculate margin of error and bounds
  margin_of_error = sample_stddev / sqrt(n) * z_value(confidence_level);
  lower_bound = sample_mean - margin_of_error;
  upper_bound = sample_mean + margin_of_error;

  // Output results
  cout << "Sample mean: " << sample_mean << endl;
  cout << "Population mean: " << population_mean << endl;
  cout << "Sample standard deviation: " << sample_stddev << endl;
  cout << "Confidence level: " << confidence_level << endl;
  cout << "Margin of error: " << margin_of_error << endl;
  cout << "Lower bound: " << lower_bound << endl;
  cout << "Upper bound: " << upper_bound << endl;

  return 0;
}

// Function to calculate z-value given a confidence level
double z_value(double confidence_level) {
  if (confidence_level == 0.90) {
    return 1.645;
  } else if (confidence_level == 0.95) {
    return 1.96;
  } else if (confidence_level == 0.99) {
    return 2.576;
  } else {
    return 0;
  }
}
