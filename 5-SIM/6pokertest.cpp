#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int data[] = {1, 3, 4, 5, 6, 2, 7, 8, 4, 9, 10, 2, 6, 1, 7, 8};
    int n = sizeof(data)/sizeof(int);
    int k = 4; // group length
    int m = pow(2, k); // number of possible combinations
int* freq = new int[m](); // dynamically allocate array and initialize all elements to 0

// count frequency of each combination
for(int i=0; i<n-k+1; i++) {
    int index = 0;
    for(int j=0; j<k; j++) {
        index += data[i+j] * pow(2, j);
    }
    freq[index]++; //array to store frequency of each combination
    
    // count frequency of each combination
    for(int i=0; i<n-k+1; i++) {
        int index = 0;
        for(int j=0; j<k; j++) {
            index += data[i+j] * pow(2, j);
        }
        freq[index]++;
    }

    
    // calculate expected frequency of each combination
    double expected = (double)(n-k+1) / m;
    
    // calculate chi-squared statistic
    double chi_squared = 0;
    for(int i=0; i<m; i++) {
        chi_squared += pow(freq[i] - expected, 2) / expected;
    }
    
    // calculate degrees of freedom
    int df = m - 1;
    
    // check whether sequence is random or not
    double threshold = 16.919; // threshold for 95% confidence level and df=15
    if(chi_squared < threshold) {
        cout << "Sequence is likely to be random" << endl;
    } else {
        cout << "Sequence is not random" << endl;
    }
    
    return 0;
}
delete[] freq;
}