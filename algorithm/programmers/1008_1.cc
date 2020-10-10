#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int solution(int n) {
    int num = n;
    int answer = 0;
    vector<int> nums;

    while (num >0) {
        nums.push_back(num%3);
        num /= 3;
    }

    for (int i=0; i < nums.size(); ++i) {
        answer += (pow(3,nums.size()-1-i) *nums[i]);
    }

    return answer;
}


int main() {
    int n=125;
    int answer = solution(n);
    cout << answer << endl;
    return 0;
}