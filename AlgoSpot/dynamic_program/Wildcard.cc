#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> SplitPattern (std::string &pattern) {
    int start_index = 0;
    bool split = false;
    std::vector<std::string> sub_patterns;

    for (int i=0; i< pattern.size(); ++i) {
        if (!split && pattern[i] != '*') {
            start_index =i;
            split = true;
        }
        
        if (split && (i == pattern.size()-1 || pattern[i+1] == '*')) {
            split = false;
            sub_patterns.push_back(pattern.substr(start_index, i-start_index+1));
        }
    }
    return sub_patterns;
}

bool IsSame (std::string sub_pattern, std::string sub_string) {
    if (sub_pattern.size() != sub_string.size()) return false;
    bool is_matched =true;
    
    for (int k=0; k < sub_string.size(); ++k){
        if (sub_pattern[k] != sub_string[k] && sub_pattern[k] != '?') {
            is_matched =false;
            break;
        }
    }
    return is_matched;
}

int FindSubString (std::string &string, std::string &sub_string, int start_index) {
    int end_index = -1;
    bool found = true;

    if (string.size() < sub_string.size()) return -1;

    for (int i=start_index; i< string.size(); ++i) {
        found = IsSame (sub_string, string.substr(i,sub_string.size()));
        if (found) return i+sub_string.size();
    }

    return -1;
}


bool PatternMatch (std::string &pattern, std::string &string) {
    int start_index =0;
    bool is_matched = true;
    std::string new_pattern;
    std::vector<std::string> sub_patterns;

    sub_patterns = SplitPattern(pattern);
    int i=0, j= sub_patterns.size();

    if (pattern.front() != '*' && pattern.back() != '*' && sub_patterns.size() ==1) {
        if (IsSame(pattern, string)) return true;
        else return false;
    } else if (pattern.front() != '*') { 
        if (IsSame(sub_patterns[0], string.substr(0,sub_patterns[0].size()))) {
            i++;
            start_index = sub_patterns[0].size();
        } else return false;
    } else if (pattern.back() != '*') {
        std::string &final_pattern = sub_patterns.back();
        if (IsSame(final_pattern, string.substr(string.size()-final_pattern.size(), final_pattern.size()))) {
            j--;
        } else return false;
    }

    for (; i < j; ++i) {
        start_index = FindSubString(string, sub_patterns[i], start_index);
        if (start_index == -1) {
            is_matched = false;
            break;
        }
    }

    return is_matched;
}

int main() {
    int number_of_test_case = 1;
    int number_of_strings = 1;
    std::string pattern;
    std::string string;
    std::vector<std::string> answers;

    std::cin >> number_of_test_case;

    for (int i=0; i< number_of_test_case; ++i) {
        std::cin >> pattern;
        std::cin >> number_of_strings;
        for (int j=0; j < number_of_strings; ++j) {
            std::cin >> string;
            if (PatternMatch(pattern, string)) {
                answers.push_back(string);
            }
        }
    }

    for (std::string &iter : answers) {
        std::cout << iter <<std::endl;
    }

    return 0;
}