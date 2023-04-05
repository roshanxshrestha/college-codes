#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n = 5;
  double sample_mean, population_mean = 80, bias, point_estimate;

  // Input sample data
  double sum = 0;
  for (int i = 0; i < n; i++) {
    double x;
    cout << "Enter data point " << i + 1 << ": ";
    cin >> x;
    sum += x;
  }
  sample_mean = sum / n;

//   // Calculate sample variance
//   sum = 0;
//   for (int i = 0; i < n; i++) {
//     double x;
//     cout << "Enter data point " << i + 1 << ": ";
//     cin >> x;
//     sum += pow(x - sample_mean, 2);
//   }
//   sample_variance = sum / (n - 1);

  // Calculate point estimate and bias
  point_estimate = sample_mean;
  bias = point_estimate - population_mean;

  // Output results
  cout << "Sample mean: " << sample_mean << endl;
//   cout << "Sample variance: " << sample_variance << endl;
  cout << "Point estimate: " << point_estimate << endl;
  cout << "Bias: " << bias << endl;

  return 0;
}
