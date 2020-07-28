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
    input_signals.push(head);

    while (sum >= k || tail < n) {
        if (sum == k) count++;

        if (head_index == tail_index) {
            head = input_signals.front();
            tail = head;
        }

        if (sum >= k) {
            head = input_signals.front();
            input_signals.pop();
            sum -= head;
            head_index++;
        } else if (sum < k) {
            tail = generator.next();
            sum += tail;
            tail_index++;
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