#include <string>
#include <vector>

using namespace std;

vector<string> getToken(const string &S) {
    vector<string> tokens;
    int start = 0;

    for (int i=0; i < S.length(); ++i) {
        char ith = S[i];
        if (ith == ' ') {
            tokens.push_back(S.substr(start, i-start));
            start = i+1;
        } else if (i == S.length()-1) {
            tokens.push_back(S.substr(start, i-start+1));
        }
    }

    return tokens;
}

bool isVowel (char word) {
    if (word == 'a' || word == 'e' || word == 'i' || word == 'o' || word =='u' ||
        word == 'A' || word == 'E' || word == 'I' || word == 'O' || word == 'U')
        return true;

    return false;
}

string toGoatLatin(string S) {
    vector<string> tokens = getToken(S);
    vector<string> goatLatin;
    string answer;

    for (int i=0; i < tokens.size(); ++i) {
        string ithToken = tokens[i];

        if (!isVowel(ithToken[0])) {
            char first = ithToken[0];
            ithToken.erase(ithToken.begin());
            ithToken = ithToken + first;
        }
        
        ithToken.append("ma");
        for (int j=0; j < i+1; ++j) {
            ithToken.append("a");
        }

        goatLatin.push_back(ithToken);
        
        if (i == tokens.size()-1) answer += ithToken;
        else answer += ithToken + " ";
    }

    return answer;
}


int main() {
    //string test = "I speak Goat Latin";
    string test = "The quick brown fox jumped over the lazy dog";
    string answer = toGoatLatin(test);

    return 0;
}








