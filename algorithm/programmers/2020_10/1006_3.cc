/** 풍선 터뜨리기 **/
/** 맞는 답은 나오지만 시간이 엄청 오래걸리는 풀이 ㅜㅠ **/

#include <vector>
#include <set>
#include <list>
#include <iostream>

using namespace std;

list<int> eraseList (list<int> b, int index) {
    list<int> c = b;
    list<int>::iterator it = c.begin();

    c.erase(next(it,index));
    return c;
}

void possibleRemaining(list<int> b, set<int> &answers, bool removeSmaller) {
    list<int>::iterator it, next_it;
    int index = 0;
    int smaller, bigger;

    if (b.size() == 1) {
        answers.insert(b.front());
        return;
    }

    for (it = b.begin(); index < b.size()-1; ++it) {
        next_it = next(it);
        
        if (*it < *next_it) {
            smaller = index;
            bigger = index+1;
        } else {
            smaller = index+1;
            bigger = index;
        }

        if (removeSmaller) {
            possibleRemaining(eraseList(b, smaller), answers, false);
            possibleRemaining(eraseList(b, bigger), answers, true);
        } else {
            possibleRemaining(eraseList(b, bigger), answers, false);
        }

        index++;
    }

}

int solution(vector<int> a) {
    list<int> b;
    set<int> answers;

    if (a.empty()) return 0;

    for (int i=0; i< a.size(); ++i) {
        b.push_back(a[i]);
    }
    possibleRemaining(b, answers, true);
    
    return answers.size();
}

int main() {
    vector<int> a {-16,27,65,-2,58,-92,-71,-68,-61,-33};
    int answer = solution(a);

    cout << answer << endl;
    return 0;
}