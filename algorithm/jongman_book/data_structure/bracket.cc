#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

int number_of_test_case;
string brackets;
stack<char> left_brackets;
bool is_matched;
unordered_map<char,char> matched_pair;
const char l1 = '(';
const char l2 = '{';
const char l3 = '[';
const char r1 = ')';
const char r2 = '}';
const char r3 = ']';

void initialize() {
    matched_pair[l1] = r1;
    matched_pair[l2] = r2;
    matched_pair[l3] = r3;
}

bool isPair(char left_bracket, char right_bracket) {
    return matched_pair.at(left_bracket) == right_bracket ? true : false;
}

bool isLeft(char bracket) {
    return bracket == l1 || bracket == l2 || bracket ==l3;
}

bool isMatched(string brackets) {
    for (int i=0; i < brackets.size(); ++i) {
        char bracket = brackets[i];
        if (isLeft(bracket)) {
            left_brackets.push(bracket);
        } else {
            char left_bracket = left_brackets.top();
            if (isPair(left_bracket, bracket)) {
                left_brackets.pop();
                continue;
            }
            else return false;
        }
    }

    return true;
}

int main() {
    
    cin >> number_of_test_case;
    initialize();

    for (int i=0; i < number_of_test_case; ++i) {
        cin >> brackets;        
        is_matched = isMatched(brackets);
        
        if (is_matched) cout << "YES" <<endl;
        else cout << "NO" <<endl;
    }

    return 0;
}
