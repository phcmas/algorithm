/* 쿼드 압축후 개수 세기 2020_10_08 */
/** 0과 1로 이루어진 2n x 2n 크기의 2차원 정수 배열 arr이 있습니다. 당신은 이 arr을 쿼드 트리와 같은 방식으로 압축하고자 합니다. 구체적인 방식은 다음과 같습니다.
 *  당신이 압축하고자 하는 특정 영역을 S라고 정의합니다.
 *  만약 S 내부에 있는 모든 수가 같은 값이라면, S를 해당 수 하나로 압축시킵니다.
 *  그렇지 않다면, S를 정확히 4개의 균일한 정사각형 영역(입출력 예를 참고해주시기 바랍니다.)으로 쪼갠 뒤, 각 정사각형 영역에 대해 같은 방식의 압축을 시도합니다.
 *  arr이 매개변수로 주어집니다. 위와 같은 방식으로 arr을 압축했을 때, 배열에 최종적으로 남는 0의 개수와 1의 개수를 배열에 담아서 return 하도록 solution 함수를 완성해주세요.
 * 
 *  제한사항
 *  arr의 행의 개수는 1 이상 1024 이하이며, 2의 거듭 제곱수 형태를 하고 있습니다. 즉, arr의 행의 개수는 1, 2, 4, 8, ..., 1024 중 하나입니다.
 *  arr의 각 행의 길이는 arr의 행의 개수와 같습니다. 즉, arr은 정사각형 배열입니다.
 *  arr의 각 행에 있는 모든 값은 0 또는 1 입니다.
 * 
 *  입출력 예
 *  arr	result
 *  [[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]]	[4,9]
 *  [[1,1,1,1,1,1,1,1],[0,1,1,1,1,1,1,1],[0,0,0,0,1,1,1,1],[0,1,0,0,1,1,1,1],[0,0,0,0,0,0,1,1],[0,0,0,0,0,0,0,1],[0,0,0,0,1,0,0,1],[0,0,0,0,1,1,1,1]]	[10,15]
 *  입출력 예 설명
 * 
 *  입출력 예 #1
 *  최종 압축 결과에 0이 4개, 1이 9개 있으므로, [4,9]를 return 해야 합니다.
 *  입출력 예 #2
 *  최종 압축 결과에 0이 10개, 1이 15개 있으므로, [10,15]를 return 해야 합니다. **/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> merge (vector<vector<int>> &arr, int startX, int endX, int startY, int endY) {
    // leftTop : x 좌표, rightBottom : y 좌표
    vector<int> answer (2, -1);
    int zeroCount = 0;
    int oneCount = 0;
    
    if (startX == endX && startY == endY) {
        if (arr[startX-1][startY-1] == 0) zeroCount++;
        if (arr[startX-1][startY-1] == 1) oneCount++;
        answer[0] = zeroCount;
        answer[1] = oneCount;
        return answer;
    }

    vector<int> first = merge (arr, startX, (startX+endX)/2, startY, (startY+endY)/2);
    vector<int> second = merge (arr, (startX+endX)/2+1, endX, startY, (startY+endY)/2);
    vector<int> third = merge (arr, startX, (startX+endX)/2, (startY+endY)/2+1, endY);
    vector<int> fourth = merge (arr, (startX+endX)/2+1, endX, (startY+endY)/2+1, endY);

    if (first == second && first == third && first == fourth) {
        if (first[0] == 1 && first[1] == 0) {
            answer[0] = 1;
            answer[1] = 0;
            return answer;
        } else if (first[0] == 0 && first[1] == 1) {
            answer[0] = 0;
            answer[1] = 1;
            return answer;
        }
    }

    answer[0] = first[0] + second[0] + third[0] + fourth[0];
    answer[1] = first[1] + second[1] + third[1] + fourth[1];

    return answer;
}

vector<int> solution(vector<vector<int>> arr) {
    return merge(arr, 1, arr.size(), 1, arr.size());
}

int main() {
    vector<vector<int>> arr;
    vector<int> a {1,1,0,0};
    vector<int> b {1,0,0,0};
    vector<int> c {1,0,0,1};
    vector<int> d {1,1,1,1};
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    arr.push_back(d);
    vector<int> answer = solution(arr);

    cout << answer[0] << endl;
    cout << answer[1] << endl;

    return 0;
}