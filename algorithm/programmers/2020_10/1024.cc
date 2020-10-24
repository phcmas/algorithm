/* 정수 삼각형 */

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








