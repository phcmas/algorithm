#include <iostream>
using namespace std;

const int EMPTY = -987654321;
int cache[50][50];
int size_of_board;
int number_of_test_cases;
int board[50];
int answer;

void InitializeCache() {
    for (int i=0; i<50; ++i) {
        for (int j=0; j<50; ++j) {
            cache[i][j] = EMPTY;
        }
    }
}

int max (int num1, int num2) {
    if (num1 > num2) return num1;
    else return num2;
}

int BiggestDifference (int left, int right) {
    if (left > right) return 0;

    int &ret = cache[left][right];
    if (ret != EMPTY) return ret;

    ret = board[left] - BiggestDifference(left+1,right);
    ret = max(ret, board[right] - BiggestDifference(left,right-1));

    if (right >= left+1) {
        ret = max(ret, -BiggestDifference(left+2, right));
        ret = max(ret, -BiggestDifference(left, right-2));
    }

    return ret;
}

int main() {
    cin >> number_of_test_cases;

    for (int i=0; i < number_of_test_cases; ++i) {
        InitializeCache();
        cin >> size_of_board;

        for (int j=0; j < size_of_board; ++j) {
            cin >> board[j];
        }
        answer = BiggestDifference(0, size_of_board-1);
        cout << answer << endl;
    }

    return 0;
}
