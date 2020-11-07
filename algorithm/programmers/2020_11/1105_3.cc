#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

const int maxLength = 500000;
vector<int> indices[maxLength];

int solution(vector<int> a) {
    int answer = 0;
    int selected = -2;
    vector<int> nums;

    for (int i = 0; i < maxLength; ++i) {
        indices[i].clear();
    }

    for (int i = 0; i < a.size(); ++i) {
        if (indices[a[i]].empty()) nums.push_back(a[i]);
        indices[a[i]].push_back(i);
    }

    for (int i = 0; i < nums.size(); ++i) {
        int setCount = 0;
        for (int j = 0; j < indices[nums[i]].size(); ++j) {
            int index = indices[nums[i]][j];
            if (index > 0 && a[index-1] != nums[i] && selected != index-1) {
                selected = index-1;
                setCount++;
            } else if (index < a.size()-1 && a[index+1] != nums[i] && selected != index+1) {
                selected = index+1;
                setCount++;
            }
        }

        answer = max(answer, 2 * setCount);
    }

    return answer;
}

int main() {
    //vector<int> a {5,2,3,3,5,3};
    //vector<int> a {0,3,3,0,7,2,0,2,2,0};
    vector<int> a {0};
    int answer = solution(a);

    cout << answer << endl;

    return 0;
}



