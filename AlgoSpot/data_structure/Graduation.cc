#include <iostream>
#include <cstring>

using namespace std;

// 내가 처음 풀었을 때 코드. 알고리즘 자체는 수학적으로 타당하지만 무한정 재귀를 호출하면서 stack overflow 가 터진 것으로 예상

const int IMPOSSIBLE = 99999;
int number_of_test_cases=1;
int n=3; // 전공 과목 수
int k=3; // 졸업을 위해 들어야할 과목 수
int m=3; // 학기의 수
int l=3; // 한 학기 최대로 들을 수 있는 과목 수
int prerequisites[12]; // 선수 과목 비트마스크
int lecture[10];  // 각 학기 개설과목 비트마스크 
int cache[12][(1<<12)-1][10]; // DP를 위한 cache
int number_of_prerequisite;
int number_of_opening_lectures;
int temp;
int answer;

int min (int a, int b) { return a>b ? b : a; }
int bitindex(int num) {
    // 2의 거듭 제곱 꼴의 숫자에서 몇 번째 비트가 1인지 알려주는 함수
    int index = 0;
    while (num != 1) {
        num = num >> 1;
        index++;
    }
    return index;
}
int numberOfbits(int num) {
    if (num ==0) return 0;
    return num%2 + numberOfbits(num/2);
}

// 들어야할 과목 수, 아직 수강하지 않은 과목 정보, 현재 학기가 주어질 때, 이 순간부터 졸업까지 참석해야하는 최소 학기 수
int MinimumSemester (int number_of_subjects_to_take, int remaining_subjects, int current_semester) {
    // 기저 경우에 대한 return 반환
    int &ret = cache[number_of_subjects_to_take][remaining_subjects][current_semester];
    if (ret !=-1) return ret;
    if (number_of_subjects_to_take == 0) return 0;
    if (current_semester == m && number_of_subjects_to_take >0) return IMPOSSIBLE;

    // 지금 학기를 휴학한다고 했을 때 값을 저장.
    ret = MinimumSemester(number_of_subjects_to_take, remaining_subjects, current_semester+1);
    int possible_lectures_to_take =  (remaining_subjects & lecture[current_semester]);
    int iter = 0;
    int current_lecture = 0;
    int prerequisite = 0;
    int new_remaining_subjects = 0;
    int new_number_of_subjects_to_take = 0;
    bool possible;

    // 이번 학기 수강 가능한 모든 subset을 탐색하면서 ret 값을 변경
    for (int subset = possible_lectures_to_take; subset; subset = ((subset-1)&possible_lectures_to_take)) {
        if (numberOfbits(subset) >l) continue;
        
        new_remaining_subjects = remaining_subjects;
        new_number_of_subjects_to_take = number_of_subjects_to_take;
        possible = true;
        iter = subset;
        while (iter > 0) {
            current_lecture = iter & -iter;
            prerequisite = prerequisites[ bitindex (current_lecture)];
            if ((prerequisite & remaining_subjects) != 0) {
                possible = false;
                break;
            } 
            new_number_of_subjects_to_take--;
            new_remaining_subjects &= ~current_lecture;
            iter &= ~current_lecture;
        }
        
        if (!possible) continue;
        ret = min (ret, 1+MinimumSemester(new_number_of_subjects_to_take, new_remaining_subjects, current_semester+1));
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

        answer = MinimumSemester(k, (1<<n) -1 , 0);
        if (answer >= IMPOSSIBLE) cout << "IMPOSSIBLE" <<endl;
        else cout << answer << endl;
    }

    return 0;
}





