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