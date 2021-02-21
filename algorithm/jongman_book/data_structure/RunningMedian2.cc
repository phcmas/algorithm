#include <queue>
#include <stdio.h>

using namespace std;

// 종만북에 나온 풀이.

int number_of_test_cases;
int N;
int a;
int b;

struct seqGenerator {
    int seq;
    
    seqGenerator() {
        seq = 1983;
    }
    int next() {
        int value = seq;
        seq = (seq * (long long)a + b) % 20090711;
        return value;
    }
};

int runningMedian() {
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    seqGenerator generator;

    int first_seq = generator.next();
    int result = first_seq % 20090711;
    maxHeap.push(first_seq);

    for (int i=1; i<N; ++i) {
        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(generator.next());
        } else {
            minHeap.push(generator.next());
        }

        int num1 = maxHeap.top();
        int num2 = minHeap.top();

        if (num2 < num1) {
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(num2);
            minHeap.push(num1);
        }

        result = (result+maxHeap.top()) % 20090711;
    }

    return result;
}


int main() {
    scanf("%d", &number_of_test_cases);
    seqGenerator generator;

    for (int i=0; i < number_of_test_cases; ++i) {
        scanf("%d %d %d", &N, &a, &b);

        if (i == number_of_test_cases-1) printf("%d", runningMedian());
        else printf("%d\n", runningMedian());
    }

    return 0;
}