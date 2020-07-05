#include <iostream>
#include <list>

using namespace std;
int number_of_test_case = 1;
int number_of_strings =3;
list<int> lengths; //string의 length를 모아놓은 배열
int cost[100];
int answer;
int length;

void swap(list<int>::iterator &iter0, list<int>::iterator &iter1) {
    list<int>::iterator temp = iter0;
    iter0 = iter1;
    iter1 = temp;
}

int MinimalCost() {
    list<int>::iterator iter0;
    list<int>::iterator iter1;
    int cost = 0;
    int result = 0;

    while (lengths.size() > 1) {
        list<int>::iterator iter = lengths.begin();
        iter0 = iter;
        iter1 = ++iter;
        if (*iter1 < *iter0) swap (iter0,iter1);
        ++iter;
        
        /* iter0 에는 최소값이, iter1 에는 두 번째 최소값을 세팅 */
        for (; iter != lengths.end(); ++iter) {
            if (*iter < *iter0) {
                iter1 = iter0;
                iter0 = iter;
            } else if (*iter < *iter1) {
                iter1 = iter;
            }
        }

        lengths.push_back(*iter0+*iter1);
        cost += *iter0 + *iter1;
        lengths.erase(iter0);
        lengths.erase(iter1);
    }

    return cost;
}

int main() {
    cin >> number_of_test_case;

    for (int i=0; i< number_of_test_case; ++i) {
        lengths.clear();
        cin >> number_of_strings;
        for (int j=0; j< number_of_strings; ++j) {
            cin >> length;
            lengths.push_back(length);
        }
        answer =  MinimalCost();
        cout << answer << endl;
    }

    return 0;
}