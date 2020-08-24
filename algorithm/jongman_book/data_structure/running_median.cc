#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>

// 처음 시도했던 풀이. 틀린 것으로 판명됨

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

int median(priority_queue<int> &pq) {
    vector<int> container;
    int result;
    int size = pq.size()/2;
    container.reserve(size);
    
    for (int i = 0; i < size; ++i) {
        container.push_back(pq.top());
        pq.pop();
    }

    result = pq.top();

    for (int i=0; i < container.size(); ++i) {
        pq.push(container[i]);
    }

    return result;
}

void removeSmallest(priority_queue<int> &pq) {
    vector<int> container;
    int size = pq.size()-1;
    container.reserve(size);

    for (int i=0; i < size; ++i) {
        container.push_back(pq.top());
        pq.pop();
    }

    pq.pop();

    for (int i=0; i <container.size() ; ++i) {
        pq.push(container[i]);
    }
}

int runningMedian() {
    int answer = 0;
    vector<int> medians;
    priority_queue<int> pq;
    seqGenerator generator;
    
    medians.reserve(N);

    if (N >= 1) {
        pq.push(generator.next());
        medians.push_back(median(pq));
    }

    if (N >= 2) {
        pq.push(generator.next());
        medians.push_back(median(pq));
    }
    
    pq.push(generator.next());

    for (int i=2; i< N; ++i) {
        medians.push_back(median(pq));
        pq.push(generator.next());
        
        if (i % 2 == 1) {
            pq.pop();
            removeSmallest(pq);
        }
    }

    for (int i=0; i <medians.size(); ++i) {
        answer += medians[0];
        answer %= 20090711;
    }
    
    return answer;
}

int main() {
    //scanf("%d", &number_of_test_cases);
    number_of_test_cases = 1;
    //seqGenerator generator;

    for (int i=0; i < number_of_test_cases; ++i) {
        //scanf("%d %d %d", &N, &a, &b);
        N=10;
        a=1;
        b=1;

        // for (int j=0; j<10; ++j){
        //     printf("%d\n", generator.next());
        // }

        if (i == number_of_test_cases-1) printf("%d", runningMedian());
        //else printf("%d\n", runningMedian());
    }

    return 0;
}
