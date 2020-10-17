/* 문자열의 아름다움 */

#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(string s) {
    long long answer = 0;
    int f,se,be,e;
    bool s_found;

    for (int i = 0; i < s.length(); ++i) {
        char first = s[i];
        f = i;
        se = i;
        be = i;
        e = i;
        s_found = false;

        for (int j = i+1; j < s.length(); ++j) {
            char add = s[j];
            if (add != first) {
                be = j;
                e = j;
                if (!s_found) {
                    se = j;
                    s_found = true;
                }
                answer += e-f;
            } else {
                e = j;
                if (!s_found) se = j;
                answer += max (e-se, be-f);
            }
        }
    }

    return answer;
}

int main() {
    string s = "abbca";
    long long answer = solution(s);
    cout << answer << endl;
    return 0;
}