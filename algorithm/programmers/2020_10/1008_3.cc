/**
어떤 문자열 x의 아름다움을 다음과 같이 정의합니다.

만약 x의 모든 글자가 전부 같다면, 0입니다.
그렇지 않다면, 서로 다른 글자가 위치해 있는 두 인덱스 i, j를 골랐을 때의 j-i 값들 중 최대값입니다.
예를 들어, 문자열 abbca의 아름다움은 3입니다. 인덱스 1(b)과 4(a)를 고르거나, 또는 0(a)과 3(c)를 고를 때 최대값이기 때문입니다.

영어 소문자로 이루어진 문자열 s가 매개변수로 주어집니다. s의 모든 부분문자열의 아름다움의 합을 return 하도록 solution 함수를 완성해주세요.**/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long beautiful (string s) {
    if (s.empty() || s.length() == 1) return 0;

    char start = s.front();
    char end = s.back();
    int first = 0;
    int second = 0;

    if (start != end) return s.length()-1;

    for (int i=s.length()-1; i>=0; --i) {
        if (s[i] != start) {
            first = i;
            break;
        }
    }

    for (int i=0; i < s.length(); ++i) {
        if (s[i] != end) {
            second = s.length()-i-1;
            break;
        }
    }

    return max(first, second);
}

long long solution(string s) {
    
}

int main() {
    string s = "baby";
    long long ret = solution (s);
    cout << ret << endl;
    return 0;
}