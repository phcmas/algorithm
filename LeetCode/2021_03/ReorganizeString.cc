/* 767. Reorganize String */
/** Given a string S, check if the letters can be rearranged so that 
 *  two characters that are adjacent to each other are not the same.
 * 
 *  If possible, output any possible result.  If not possible, return the empty string.
 *  Example 1:
 *  Input: S = "aab"
 *  Output: "aba"
 * 
 *  Example 2:
 *  Input: S = "aaab"
 *  Output: ""
 *  
 *  Note: S will consist of lowercase letters and have length in range [1, 500]. **/

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int frequency[26];

void addString(string &S, char character) {
    if (frequency[character-'a'] > 0) {
        answer += character;
        frequency[character-'a']--;
    }
}

string reorganizeString(string S) {
    string answer;
    char max = 'a';
    set<char> others;

    for (char iter : S) {
        frequency[iter-'a']++;
        others.insert(iter);
        if (frequency[iter-'a'] > frequency[max-'a']) max = iter;
    }

    others.erase(max);

    while (!others.empty()) {
        char other = other.lower_bound(max);
        addString(max);
        addString(other);
    }

    

}

int main() {
    string S0 = "aab";
    string S1 = "aaab";

    string ans0 = reorganizeString(S0);
    string ans1 = reorganizeString(S1);

    cout << ans0 << endl;
    cout << ans1 << endl;

    return 0;
}