#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double lambda, mu;
    cout << "Enter arrival rate: ";
    cin >> lambda;
    cout << "Enter service rate: ";
    cin >> mu;

    double rho = lambda / mu;
    double Lq = pow(rho, 2) / (1 - rho) * (1 - (1 - rho));
    double L = Lq + rho;
    double Wq = Lq / lambda;
    double W = Wq + (1 / mu);
    double P0 = 1 - rho;

    cout << "Utilization factor (rho): " << rho << endl;
    cout << "Expected number of customers in queue (Lq): " << Lq << endl;
    cout << "Expected number of customers in system (L): " << L << endl;
    cout << "Expected waiting time in queue (Wq): " << Wq << endl;
    cout << "Expected waiting time in system (W): " << W << endl;
    cout << "Probability of 0 customers in system (P0): " << P0 << endl;

    for (int n = 1; n < 2; n++) {
        double Pn = pow(rho, n) * P0;
        cout << "Probability of " << n << " customers in system (Pn): " << Pn << endl;
    }

    return 0;
}
