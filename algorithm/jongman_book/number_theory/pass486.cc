#include <iostream>
#include <cstring>
#include <list>
#include <math.h>

using namespace std;
const int MAX_N = 10000001;
int minFactor[MAX_N];
int power[MAX_N];
list<int> prime_factors;
int number_of_test_cases;
int number;
int low;
int high;
int answer;

void Eratosthenes() {
    for (int i=2; i<MAX_N; ++i) {
        minFactor[i] = i;
    }

    int sqrt_max = sqrt(MAX_N);

    for (int i=2; i<=sqrt_max; ++i) {
        if (minFactor[i] == i) {
            for (int j=i*i; j<sqrt_max; j+=i){
                if (minFactor[j]=j){
                    minFactor[j]=i;
                }
            }
        }
    }


}

int NumberOfFactors() {

}

int main() {
    minFactor[0] = minFactor[1]= -1;
    cin >> number_of_test_cases;

    for (int i=0; i< number_of_test_cases; ++i) {
        cin>> number >> low >> high;
        answer = NumberOfFactors();
        cout << answer << endl;
    }

    return 0;
}