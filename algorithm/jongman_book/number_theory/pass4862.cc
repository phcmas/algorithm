#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;
const int MAX_NUMBER = 10000000;
int number_of_test_case;
int number_of_factors;
int low;
int high;
int answer;
int minFactor[MAX_NUMBER+1];
int minFactorPower[MAX_NUMBER+1];
int numberOfFactors[MAX_NUMBER+1];

void Eratosthenes() {
    for (int i=2; i<=MAX_NUMBER; ++i) {
        minFactor[i] = i;
    }

    int max_sqrt = sqrt (MAX_NUMBER);

    for (int i=2; i<= max_sqrt; ++i) {
        if (minFactor[i] == i) {
            for (int j=i*i; j <= MAX_NUMBER; j+=i){
                if (minFactor[j] == j){
                    minFactor[j] = i;
                }
            }
        }
    }
}

void SetNumberOfFactors() {
    for (int i=2; i <= MAX_NUMBER; ++i) {
            int min_prime = minFactor[i];
            int power_of_min_prime = 1;
            
            if (minFactor[i/min_prime] == min_prime) power_of_min_prime = minFactorPower[i/min_prime]+1;

            minFactorPower[i] = power_of_min_prime;
            numberOfFactors[i] = (numberOfFactors[i/min_prime] / (power_of_min_prime)) * (power_of_min_prime+1);
    }
}


int main() {
    numberOfFactors[0] = 0;
    numberOfFactors[1] = 1;
    minFactor[0] = 0;
    minFactor[1] = 1;
    Eratosthenes();
    SetNumberOfFactors();

    cin >> number_of_test_case;

    for (int i=0; i< number_of_test_case; ++i) {
        answer = 0;
        cin >> number_of_factors >> low >>high;
        for (int j=low; j<=high; ++j) {
            if (numberOfFactors[j] == number_of_factors) answer++;
        }
        cout << answer << endl;
    }

    return 0;
}


















