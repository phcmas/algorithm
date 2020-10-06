#include <vector>
using namespace std;


vector<int> getRow(int rowIndex) {
    if (rowIndex == 0) return vector<int> {1};

    vector<int> answer {1};
    vector<int> prevRow = getRow(rowIndex-1);

    for (int i=0; i< rowIndex-1; ++i) {
        answer.push_back(prevRow[i]+prevRow[i+1]);
    }

    answer.push_back(1);
    return answer;
}


int main() {
    vector<int> answer1 = getRow(0);
    vector<int> answer2 = getRow(1);
    vector<int> answer3 = getRow(3);
    vector<int> answer4 = getRow(4);
    return 0;
}