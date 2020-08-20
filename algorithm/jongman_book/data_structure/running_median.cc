#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int number_of_test_cases;
int N;
int a;
int b;

struct seqGenerator {
    int seq;
    int order;
    
    seqGenerator() {
        order = 0;
        seq = 1983;
    }
    int next() {
        int value = seq;
        order++;
        seq = (seq*a + b) % 20090711;
        return value;
    }
};

int runningMedian() {
    priority_queue<int> pq;
    
    return 0;
}

int main() {
    //scanf("%d", &number_of_test_cases);
    number_of_test_cases = 1;

    for (int i=0; i < number_of_test_cases; ++i) {
        //scanf("%d %d %d", &N, &a, &b);
        N=1;
        a=1;
        b=1;

        if (i == number_of_test_cases-1) printf("%d", runningMedian());
        else printf("%d\n", runningMedian());
    }

    return 0;
}