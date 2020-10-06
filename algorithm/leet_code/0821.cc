#include <queue>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
    vector<int> answer;
    answer.reserve(A.size());

    for (int i=0; i < A.size(); ++i) {
        if (A[i] % 2 == 0) {
            answer.push_back(A[i]);
        }
    }

    for (int i=0; i < A.size(); ++i) {
        if (A[i] % 2 == 1) {
            answer.push_back(A[i]);
        }
    }

    return answer;

}


int main() {

    return 0;
}