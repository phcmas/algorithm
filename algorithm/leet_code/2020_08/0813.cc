#include <queue>
#include <string>

using namespace std;

class CombinationIterator {
public:
    vector<string> combinations;
    
    CombinationIterator(string characters, int combinationLength) {
        priority_queue<string> pq;
        setCombination(pq, "", characters, combinationLength);
        int pq_size = pq.size();
        combinations.resize(pq_size);

        for (int i = 0; i< pq_size; ++i) {
            combinations[i] = pq.top();
            pq.pop();
        }
    }
    
    void setCombination(priority_queue<string> &pq, string combination, string characters, int combinationLength) {
        if (combination.length() == combinationLength) {
            pq.push(combination);
            return;
        }

        for (int i=0; i < characters.length(); ++i) {
            if (combination.length() + characters.length()-i >= combinationLength) {
                setCombination(pq, combination + characters[i], characters.substr(i+1, characters.length()-i-1), combinationLength);
            }
        }
    }

    string next() {
        string next = combinations.back();
        combinations.pop_back();
        return next;
    }
    
    bool hasNext() {
        return combinations.size() > 0;
    }
};


int main() {
    CombinationIterator test ("abc",2);
    string first = test.next();
    bool f1 = test.hasNext();
    
    string s = test.next();
    bool s1 = test.hasNext();

    string t = test.next();
    bool t1 = test.hasNext();

    return 0;
}












