/** 삼각 달팽이 2020_10_06 (문제는 프로그래머스 사이트 참고) **/

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    int direction = 0; // 0은 왼쪽 아래, 1은 오른쪽, 2는 왼쪽 위
    int height = 1; // 맨 위가 1, 맨 아래가 n
    int setted = 0; // 세팅이 완료된 개수
    int total = (n*(n+1))/2;
    int index = 0;
    int next_index = 0;
    vector<int> answer (total,-1);

    while (setted < total) {
        answer[index] = ++setted;
        if (direction == 0) {
            next_index = index+height;
            if (next_index > total-1 || answer[next_index] != -1) {
                direction++;
                index++;
            } else {
                index = next_index;
                height++;
            }
        } else if (direction == 1) {
            next_index = index+1;
            if (next_index > total-1 || answer[next_index] != -1) {
                direction++;
                index -= height;
                height--;
            } else {
                index = next_index;
            }
        } else {
            next_index = index-height;
            if (next_index < 0 || answer[next_index] != -1) {
                direction = 0;
                index += height;
                height++;
            } else {
                index = next_index;
                height--;
            }
        }
    }

    return answer;
}

int main() {
    int n=5;
    vector<int> answer = solution(n);

    for (int i=0; i< answer.size(); ++i) {
        cout << answer[i] << " ";
    }

    return 0;
}