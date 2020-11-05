#include <vector>
#include <string>
#include <iostream>

using namespace std;

string toBinary(int num) {
    string answer;

    if (num == 0) return "0";
    
    while (num != 0) {
        answer = to_string(num % 2) + answer;
        num = num/2;
    }

    return answer;
}

vector<int> solution(string s) {
    int count = 0;
    int numOfZeroes = 0;
    vector<int> answer;
    string binary = s;

    while (binary.length() != 1) {
        int erasedCount = 0;
        for (int i = 0; i < binary.length(); ++i) {
            if (binary[i] == '0') erasedCount++;
        }

        numOfZeroes += erasedCount;
        binary = toBinary(binary.length()- erasedCount);
        count++;
    }

    answer.push_back(count);
    answer.push_back(numOfZeroes);

    return answer;
}

int main() {
    //string s = "01110";
    //string s = "110010101001";
    string s = "1111111";
    vector<int> answer = solution(s);

    cout << answer[0] << endl;
    cout << answer[1] << endl;

    return 0;
}




