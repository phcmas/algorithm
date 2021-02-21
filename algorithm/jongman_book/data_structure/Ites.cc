#include <iostream>
#include <list>

using namespace std;

const long mod = 4294967296;
list<int> input_signal;
int k = 8791;
int n = 20;
int number_of_test_cases = 1;
int answer;

void generateInputSignal() {
    long num = 1983;
    long signal;

    for (int i=0; i < n; ++i) {
        signal = num % 10000 + 1;
        input_signal.push_back(signal);
        num = (num *214013 + 2531011) % mod;
    }
}

int numberOfInterval() {
    int count = 0;
    int temp;
    list<int>::iterator first = input_signal.begin();

    while (first != input_signal.end()) {
        temp = 0;
        for (list<int>::iterator iter = first; iter != input_signal.end(); ++iter) {
            temp += *iter;
            if (temp == k) {count++; break;}
            if (temp > k) break;
        }  
        first++;
    }
    return count;
}

int main() {

    cin >> number_of_test_cases;

    for (int i=0; i< number_of_test_cases; ++i) {
        cin >> k >> n;
        input_signal.clear();
        generateInputSignal();
        answer = numberOfInterval();
        cout << answer << endl;
    }

    return 0;
}




