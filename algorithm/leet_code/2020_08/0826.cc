#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> fizzBuzz(int n) {
    bool multipleOfThree = false;
    bool multipleOfFive = false;
    vector<string> answer;
    answer.resize(n);

    for (int i=1; i <= n ; ++i) {
        multipleOfThree = (i%3 == 0);
        multipleOfFive = (i%5 == 0);
        
        if (multipleOfThree && multipleOfFive) {
            answer[i-1] = "FizzBuzz";
        } else if (multipleOfThree){
            answer[i-1] = "Fizz";
        } else if (multipleOfFive) {
            answer[i-1] = "Buzz";
        } else {
            answer[i-1] = to_string(i);
        }
    }

    return answer;
}

int main() {

    vector<string> answer = fizzBuzz(15);

    for (string &iter : answer) {
        cout << iter << endl;
    }

    return 0;
}