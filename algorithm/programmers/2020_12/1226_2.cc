/* 입국 심사 */
/** n명이 입국심사를 위해 줄을 서서 기다리고 있습니다. 각 입국심사대에 있는 심사관마다 심사하는데 걸리는 시간은 다릅니다.
 *  처음에 모든 심사대는 비어있습니다. 한 심사대에서는 동시에 한 명만 심사를 할 수 있습니다. 가장 앞에 서 있는 사람은 비어 있는 심사대로 가서 심사를 받을 수 있습니다. 
 *  하지만 더 빨리 끝나는 심사대가 있으면 기다렸다가 그곳으로 가서 심사를 받을 수도 있습니다.
 *  모든 사람이 심사를 받는데 걸리는 시간을 최소로 하고 싶습니다.
 *  입국심사를 기다리는 사람 수 n, 각 심사관이 한 명을 심사하는데 걸리는 시간이 담긴 배열 times가 매개변수로 주어질 때, 
 *  모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 return 하도록 solution 함수를 작성해주세요.
 *  
 *  제한사항
 *  입국심사를 기다리는 사람은 1명 이상 1,000,000,000명 이하입니다.
 *  각 심사관이 한 명을 심사하는데 걸리는 시간은 1분 이상 1,000,000,000분 이하입니다.
 *  심사관은 1명 이상 100,000명 이하입니다.
 * 
 * 입출력 예
 * n	times	return
 * 6	[7, 10]	28
 * 
 * 입출력 예 설명
 * 가장 첫 두 사람은 바로 심사를 받으러 갑니다.
 * 7분이 되었을 때, 첫 번째 심사대가 비고 3번째 사람이 심사를 받습니다.
 * 10분이 되었을 때, 두 번째 심사대가 비고 4번째 사람이 심사를 받습니다.
 * 14분이 되었을 때, 첫 번째 심사대가 비고 5번째 사람이 심사를 받습니다.
 * 20분이 되었을 때, 두 번째 심사대가 비지만 6번째 사람이 그곳에서 심사를 받지 않고 1분을 더 기다린 후에 첫 번째 심사대에서 심사를 받으면 28분에 모든 사람의 심사가 끝납니다. **/

/* 다른 사람의 풀이를 보고 더 짧게 구현 */

#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left;
    long long right;
    long long middle;
    long long count;
    long long minTime;

    if (times.empty()) return 0;

    minTime = times[0];
    for (int i = 1; i < times.size(); ++i) {
        if (times[0] < minTime) minTime = times[i];
    }

    left = minTime;
    right = minTime * (long long)n;

    while (left <= right) {
        middle = (left + right) / 2;
        count = 0;

        for (int i = 0; i < times.size(); ++i) {
            count += middle/(long long)times[i];
        }

        if (count >= n) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    return left;
}

int main() {
    vector<int> times1 {7, 10};
    int n1 = 6;
    long long answer1 = solution(n1, times1);

    vector<int> times2 {1,1,1000};
    int n2 = 1000;
    long long answer2 = solution(n2, times2);

    vector<int> times3 {6,10};
    int n3 = 6;
    long long answer3 = solution(n3, times3);

    vector<int> times4 {3,4,10};
    int n4 = 11;
    long long answer4 = solution(n4, times4);

    cout << answer1 << endl;
    cout << answer2 << endl;
    cout << answer3 << endl;
    cout << answer4 << endl;
    return 0;
}
