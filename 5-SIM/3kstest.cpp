#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

double normalCDF(double x, double mu, double sigma)
{
    return 0.5 * (1 + erf((x - mu) / (sigma * sqrt(2))));
}

double ksTest(vector<double> x, double mu, double sigma)
{
    sort(x.begin(), x.end());
    double Dplus = 0, Dminus = 0;
    for (int i = 0; i < x.size(); i++)
    {
        double Fn = static_cast<double>(i + 1) / x.size();
        double F = normalCDF((x[i] - mu) / sigma, 0, 1);
        Dplus = max(Dplus, Fn - F);
        Dminus = max(Dminus, F - Fn);
    }
    return max(Dplus, Dminus);
}

int main()
{
    vector<double> x;
    x.push_back(0.1);
    x.push_back(-1.2);
    x.push_back(0.5);
    x.push_back(1.3);
    x.push_back(-0.4);
    x.push_back(0.6);
    x.push_back(2.0);
    x.push_back(-0.7);
    x.push_back(-0.2);
    x.push_back(1.1);
    double mu = 0, sigma = 1;
    double testStat = ksTest(x, mu, sigma);
    double alpha = 0.05;
    int df = x.size() - 1;
    double critValue = 1.36 / sqrt(x.size());
    double pValue = 2 * (1 - normalCDF(abs(testStat), 0, 1));
    cout << "KS test statistic: " << testStat << endl;
    cout << "Critical value: " << critValue << endl;
    cout << "P-value: " << pValue << endl;
    if (testStat > critValue)
    {
        cout << "Reject the null hypothesis (not normal)" << endl;
    }
    else
    {
        cout << "Accept the null hypothesis (normal)" << endl;
    }
    return 0;
}
