/** 풍선 터뜨리기 2020_10_06 **/
/** 일렬로 나열된 n개의 풍선이 있습니다. 모든 풍선에는 서로 다른 숫자가 써져 있습니다. 당신은 다음 과정을 반복하면서 풍선들을 단 1개만 남을 때까지 계속 터트리려고 합니다.

임의의 인접한 두 풍선을 고른 뒤, 두 풍선 중 하나를 터트립니다.
터진 풍선으로 인해 풍선들 사이에 빈 공간이 생겼다면, 빈 공간이 없도록 풍선들을 중앙으로 밀착시킵니다.
여기서 조건이 있습니다. 인접한 두 풍선 중에서 번호가 더 작은 풍선을 터트리는 행위는 최대 1번만 할 수 있습니다. 즉, 어떤 시점에서 인접한 두 풍선 중 번호가 더 작은 풍선을 터트렸다면, 그 이후에는 인접한 두 풍선을 고른 뒤 번호가 더 큰 풍선만을 터트릴 수 있습니다.

당신은 어떤 풍선이 최후까지 남을 수 있는지 알아보고 싶습니다. 위에 서술된 조건대로 풍선을 터트리다 보면, 어떤 풍선은 최후까지 남을 수도 있지만, 어떤 풍선은 무슨 수를 쓰더라도 마지막까지 남기는 것이 불가능할 수도 있습니다.

일렬로 나열된 풍선들의 번호가 담긴 배열 a가 주어집니다. 위에 서술된 규칙대로 풍선들을 1개만 남을 때까지 터트렸을 때 최후까지 남기는 것이 가능한 풍선들의 개수를 return 하도록 solution 함수를 완성해주세요.

제한 사항
a의 길이는 1 이상 1,000,000 이하입니다.
a[i]는 i+1 번째 풍선에 써진 숫자를 의미합니다.
a의 모든 수는 -1,000,000,000 이상 1,000,000,000 이하인 정수입니다.
a의 모든 수는 서로 다릅니다.
입출력 예
a	result
[9,-1,-5]	3
[-16,27,65,-2,58,-92,-71,-68,-61,-33]	6
입출력 예 설명
입출력 예 #1

첫 번째 풍선(9가 써진 풍선)을 최후까지 남기는 방법은 다음과 같습니다.
[9, -1, -5] 에서 -1, -5가 써진 풍선을 고른 뒤, -1이 써진 풍선(번호가 더 큰 것)을 터트립니다.
[9, -5] 에서 9, -5가 써진 풍선을 고른 뒤, -5가 써진 풍선(번호가 더 작은 것)을 터트립니다.
두 번째 풍선(-1이 써진 풍선)을 최후까지 남기는 방법은 다음과 같습니다.
[9, -1, -5] 에서 9, -1이 써진 풍선을 고른 뒤, 9가 써진 풍선(번호가 더 큰 것)을 터트립니다.
[-1, -5] 에서 -1, -5가 써진 풍선을 고른 뒤, -5가 써진 풍선(번호가 더 작은 것)을 터트립니다.
세 번째 풍선(-5가 써진 풍선)을 최후까지 남기는 방법은 다음과 같습니다.
[9, -1, -5] 에서 9, -1이 써진 풍선을 고른 뒤, 9가 써진 풍선(번호가 더 큰 것)을 터트립니다.
[-1, -5] 에서 -1, -5가 써진 풍선을 고른 뒤, -1이 써진 풍선(번호가 더 큰 것)을 터트립니다.
3개의 풍선이 최후까지 남을 수 있으므로, 3을 return 해야 합니다.
입출력 예 #2

최후까지 남을 수 있는 풍선은 -16, -92, -71, -68, -61, -33이 써진 풍선으로 모두 6개입니다. */

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