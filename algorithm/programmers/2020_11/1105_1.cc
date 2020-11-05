#include <vector>
#include <string>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int size = a.size();
    int answer = 0;

    for (int i = 0; i < size; ++i) {
        answer += a[i] * b[i];
    }

    return answer;
}

int main() {

    return 0;
}

