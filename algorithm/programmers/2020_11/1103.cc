/* 단속카메라 */

#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int minRight = INT_MIN;
    sort(routes.begin(), routes.end());

    for (int i = 0; i < routes.size(); ++i) {
        if (minRight < routes[i][0]) {
            answer++;
            minRight = routes[i][1];
        } 

        minRight = min (minRight, routes[i][1]);
    }

    return answer;
}

int main() {
    vector<int> route1 {-20,15};
    vector<int> route2 {-14,-5};
    vector<int> route3 {-18,-13};
    vector<int> route4 {-5,-3};

    vector<vector<int>> routes {route1, route2, route3, route4};

    int answer = solution(routes);

    cout << answer << endl;

    return 0;
}




