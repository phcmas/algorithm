#include <iostream>
#include <cstring>

using namespace std;    

const int IMPOSSIBLE = 99999;
int number_of_test_cases=1;
int n=4; // 전공 과목 수
int k=4; // 졸업을 위해 들어야할 과목 수
int m=4; // 학기의 수
int l=4; // 한 학기 최대로 들을 수 있는 과목 수
int prerequisites[12]; // 선수 과목 비트마스크
int lecture[10];  // 각 학기 개설과목 비트마스크 
int cache[(1<<12)-1][10]; // DP를 위한 cache
int number_of_prerequisite;
int number_of_opening_lectures;
int temp;
int answer;

int min (int a, int b) { return a>b ? b : a;}
int bitcount(int num) {
    if (num == 0) return 0;
    return num % 2 + bitcount(num/2);
}

// 수강한 과목과 현재 학기가 주어졌을 때, 이 상태에서 졸업을 위해 다녀야하는 최소 학기의 수
int MinimumSemester(int taken, int semester) {
    if (bitcount(taken) >= k) return 0;
    if (semester == m) return IMPOSSIBLE;

    int &ret = cache[taken][semester];
    if (ret != -1) return ret;

    ret = MinimumSemester(taken, semester+1);
    int possible_lecture = (~taken & lecture[semester]);

    for (int i=0; i < n; ++i) {
        temp = prerequisites[i];
        if ((possible_lecture &(1<<i)) && (taken & temp) != temp) {
            possible_lecture &= ~(1<<i);
        }
    }

    for (int subset = possible_lecture; subset>0; subset = ((subset-1)&possible_lecture)) {
        if (bitcount(subset) > l) continue;
        ret = min (ret, 1 + MinimumSemester((taken | subset), semester+1));
    }

    return ret;
}

int main () {
    cin >> number_of_test_cases;

    for (int i=0; i < number_of_test_cases; ++i){
        memset (prerequisites, 0, sizeof(prerequisites));
        memset (lecture, 0, sizeof(lecture));
        memset (cache, -1, sizeof(cache));

        cin >> n >> k >>m >> l;
        for (int j=0; j < n; ++j) {
            cin >> number_of_prerequisite;
            for (int p=0; p < number_of_prerequisite; ++p) {
                cin >> temp;
                prerequisites[j] |= (1 << temp);
            }
        }
        
        for (int j=0; j < m; ++j) {
            cin >> number_of_opening_lectures;
            for (int p=0; p < number_of_opening_lectures; ++p) {
                cin >> temp;
                lecture[j] |= (1 << temp);
            }
        }

        answer = MinimumSemester(0, 0);
        if (answer >= IMPOSSIBLE) cout << "IMPOSSIBLE" <<endl;
        else cout << answer << endl;
    }

    return 0;
}