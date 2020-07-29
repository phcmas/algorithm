#include <iostream>
#include <queue>

using namespace std;
int number_of_test_cases;
const long mod = 4294967296;
int k;
int n;
int answer;

struct singalGenerator {
   long num = 1983;
   long signal;

   int next() { 
       signal = num % 10000 +1;
       num = (num *214013 + 2531011) % mod;
       return signal;
    }
};

int numberOfIntervals () {
    singalGenerator generator;
    queue<int> input_signals;
    int sum = 0;
    int count = 0;

    int head = generator.next();
    int tail = head;
    int head_index = 0;
    int tail_index = 0; // tail_index >= head_index 여야함.

    while (sum >= k || tail < n) {
        if (sum == k) count++;

        if (sum < k || head_index == tail_index) {
            tail = generator.next();
            input_signals.push(tail);
            sum += tail;
            tail_index++;
        }

        if (sum >= k) {
            head = input_signals.front();
            input_signals.pop();
            sum -= head;
            head_index++;
        }

    }

    return count;
}

int main() {
    cin >> number_of_test_cases;

    for (int i=0; i< number_of_test_cases; ++i) {
        cin >> k >> n;
        answer = numberOfIntervals();
        cout << answer << endl;
    }

    return 0;
}
