#include <iostream>
#include <cstring>
#include <list>
#include <math.h>

using namespace std;
const int MAX_NUMBER = 10000000;
int minFactor[MAX_NUMBER+1];
int power[MAX_NUMBER+1];
//list<int> prime_factors;
int prime_factors[MAX_NUMBER];
int size_of_prime_factors = 0;
int number_of_test_cases;
int number_of_factors;
int low;
int high;
int answer;

void Eratosthenes() {
    for (int i=2; i<MAX_NUMBER; ++i) {
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

int NumberOfFactors(int number) {
    int result = 1;
    while (number > 1) {
        int min_factor = minFactor[number];
        if (power[min_factor] == 0){ 
            prime_factors[size_of_prime_factors] = min_factor;
        }
        power[min_factor]++;
        size_of_prime_factors++;
        number /= min_factor;
    }

    for (int i=0; i<size_of_prime_factors; ++i) {
        int prime_factor = prime_factors[i];
        result *= (power[prime_factor]+1);
        power[prime_factor] = 0;
    }

    //prime_factors.clear();
    size_of_prime_factors=0;

    return result;
}

int main() {
    minFactor[0] = minFactor[1]= -1;
    Eratosthenes();
    memset(power, 0, sizeof(power));
    
    cin >> number_of_test_cases;

    for (int i=0; i< number_of_test_cases; ++i) {
        answer =0;
        cin>> number_of_factors >> low >> high;
        for (int j=low; j<=high; ++j) {
            if (number_of_factors == NumberOfFactors(j)) answer++;
        }
        cout << answer << endl;
    }

    return 0;
}



















