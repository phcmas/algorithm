/** 풍선 터뜨리기 **/
/* 해설을 보고 다시 구현한 풀이 */

#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> l_min (a.size(), INT_MAX); // l_min[i] = a[0] ~ a[i-1] 중 minimum 값
    vector<int> r_min (a.size(), INT_MAX); // r_min[i] = a[i+1] ~ a[a.size()-1] 중 minimum 값

    for (int i=1; i < a.size(); ++i) {
        l_min[i] = min (l_min[i-1], a[i-1]);
    }

    for (int i = a.size()-2; i >=0; --i) {
        r_min[i] = min (r_min[i+1], a[i+1]);
    }

    for (int i=1; i < a.size()-1; ++i) {
        if (l_min[i] < a[i] && r_min[i] < a[i]) continue;
        else answer++;
    }

    return answer+2;
}

int main() {
    vector<int> a {-16,27,65,-2,58,-92,-71,-68,-61,-33};
    int answer = solution(a);

    cout << answer << endl;
    return 0;
}