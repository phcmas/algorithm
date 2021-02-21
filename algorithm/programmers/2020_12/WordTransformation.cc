/* 단어 변환 2020_12_14*/
/* 두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.
 * 
 * 1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
 * 2. words에 있는 단어로만 변환할 수 있습니다.
 * 예를 들어 begin이 hit, target가 cog, words가 [hot,dot,dog,lot,log,cog]라면 hit -> hot -> dot -> dog -> cog와 같이 4단계를 거쳐 변환할 수 있습니다.
 * 
 * 두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 
 * target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.
 * 
 * 제한사항
 * 각 단어는 알파벳 소문자로만 이루어져 있습니다.
 * 각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
 * words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
 * begin과 target은 같지 않습니다.
 * 변환할 수 없는 경우에는 0를 return 합니다.
 * 
 * 입출력 예
 * begin	target	          words	                    return
 * hit	     cog	   [hot, dot, dog, lot, log, cog]	   4
 * hit	     cog	   [hot, dot, dog, lot, log]	       0
 * 
 * 입출력 예 설명
 * 예제 #1 문제에 나온 예와 같습니다.
 * 예제 #2 target인 cog는 words 안에 없기 때문에 변환할 수 없습니다. **/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> adj;

int makeGraph(string begin, string target, vector<string> &words) {
    int index = 0;
    int diffCount = 0;

    adj.clear();
    adj.resize(words.size()+1, vector<int>());

    for (int i = -1; i < (int)words.size(); ++i) {
        string current = (i == -1) ? begin : words[i];

        for (int j = i+1; j < words.size(); ++j) {
            diffCount = 0;

            for (int k = 0; k < current.size(); ++k) {
                if (current[k] != words[j][k]) diffCount++;
            }

            if (diffCount == 1) {
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }

            if (target == words[j]) index = j+1;
        }
    }

    return index;
}

int solution(string begin, string target, vector<string> words) {
    vector<int> distances;
    queue<int> queue;
    int targetIndex = makeGraph(begin, target, words);

    distances.resize(words.size()+1, -1);

    queue.push(0);
    distances[0] = 0;

    while (!queue.empty()) {
        int here = queue.front();
        queue.pop();

        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            if (distances[there] == -1) {
                queue.push(there);
                distances[there] = distances[here]+1;
            }
        }
    }

    return distances[targetIndex];
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words {"hot","dot","dog","lot","log","cog"};

    for (int i = -1; i < 0; ++i) {
        cout << "ss" << endl;
    }

    int answer = solution(begin, target, words);

    cout << answer << endl;

    return 0;
}


