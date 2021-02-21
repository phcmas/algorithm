#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int number_of_test_cases;
int number_of_words;
vector<vector<bool>> adj (26, vector<bool>(26, false));
vector<bool> visited (26, false);
vector<string> words;
string temp;
string answer;

void dfs (int here, string &dfsOrder) {
    bool alreadyVisit = visited[here];
    visited[here] = true;

    for (int i=0; i < adj.size(); ++i) {
        if (adj[here][i] && !visited[i]) dfs (i, dfsOrder);
    }

    if (!alreadyVisit) dfsOrder += (char)(here + 'a');
}

void makeGraph (const vector<string> &words) {
    string word1;
    string word2;
    int len;

    for (int i=1; i< words.size(); ++i) {
        word1 = words[i-1];
        word2 = words[i];
        len = min (word1.length(), word2.length());

        for (int j=0; j < len; ++j) {
            if (word1[j] != word2[j]) {
                adj[word1[j]-'a'][word2[j]-'a'] = true;
                break;
            }
        }
    }
}

string orderOfAlphabet (const vector<string> &words) {
    string answer;

    makeGraph(words);

    for (int i=0; i < adj.size(); ++i) {
        for (int j=0; j < adj.size(); ++j) {
            if (adj[i][j] && adj[j][i]) return "INVALID HYPOTHESIS";
        }
    }

    for (int i=0; i < adj.size(); ++i) {
        string dfsOrder;
        dfs (i, dfsOrder);

        for (int j=0; j< dfsOrder.length(); ++j) {
            answer = dfsOrder[j] + answer;
        }
    }

    return answer;
}

void initialize() {
    adj.clear();
    visited.clear();
    words.clear();

    for (int i=0; i<26; ++i) {
        adj.push_back(vector<bool>(26, false));
        visited.push_back(false);
    }

}

int main() {
    cin >> number_of_test_cases;

    //number_of_test_cases = 1;
    //number_of_words = 5;

    //words.push_back("gg");
    //words.push_back("kia");
    //words.push_back("lotte");
    //words.push_back("lg");
    //words.push_back("hanwha");

    //words.push_back("dictionary");
    //words.push_back("english");
    //words.push_back("is");
    //words.push_back("ordered");
    //words.push_back("ordinary");
    //words.push_back("this");

    for (int i=0; i < number_of_test_cases; ++i) {
        cin >> number_of_words;
        initialize();

        for (int j=0; j < number_of_words; ++j) {
            cin >> temp;
            words.push_back(temp);
        }

        answer = orderOfAlphabet(words);
        cout << answer << endl;
    }

    return 0;
}