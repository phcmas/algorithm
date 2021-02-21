/* 정수 삼각형 2020_10_24 */
/** 문제 설명
 *  위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다. 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.
 *  삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.
 * 
 *  제한사항
 *  삼각형의 높이는 1 이상 500 이하입니다.
 *  삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.
 *  입출력 예
 *  triangle	result
 *  [[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]] **/

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int cache[500][500];

int maxSum(vector<vector<int> > &triangle, int height, int start) {
    int &ret = cache[height][start];
    int first, second;
    if (ret != -1) return ret;

    ret = triangle[height][start];
    if (triangle.size()-1 == height) return ret;

    first = maxSum(triangle, height+1, start);
    second = maxSum(triangle, height+1, start+1);
    ret += max(first, second);

    return ret;
}

int solution(vector<vector<int> > triangle) {
    int answer = 0;
    memset(cache, -1, sizeof(cache));

    answer = maxSum(triangle, 0, 0);
    return answer;
}

int main() {
    vector<vector<int> > triangle;
    vector<int> h0 {7};
    vector<int> h1 {3,8};
    vector<int> h2 {8,1,0};
    vector<int> h3 {2,7,4,4};
    vector<int> h4 {4,5,2,6,5};
    triangle.push_back(h0);
    triangle.push_back(h1);
    triangle.push_back(h2);
    triangle.push_back(h3);
    triangle.push_back(h4);

    int answer = solution(triangle);

    return 0;
}








