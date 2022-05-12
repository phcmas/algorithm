#include <iostream>
#include <cstring>

using namespace std;

const int MAX_BUDGET = 10000000;
int number_of_test_cases;
int number_of_sushi;
int total_budget;
int price[20];
int preference[20];
int cache[MAX_BUDGET+1];
int answer;

int max (int a, int b) {
    if (a>b) return a;
    else return b;
}

int BiggestPreference(int budget) {
    int &ret = cache[budget];
    if (ret != -1) return ret;
    ret =0;

    for (int i=0; i < number_of_sushi; ++i) {
        if (budget < price[i]) continue;
        ret = max(ret,  preference[i]+BiggestPreference(budget-price[i]));
    }

    return ret;
}

int main() {
    cin >> number_of_test_cases;

    for (int i=0; i < number_of_test_cases; ++i) {
        memset(cache,-1,sizeof(cache));
        cin >> number_of_sushi >> total_budget;
        total_budget = total_budget/100;

        for (int j=0; j<number_of_sushi; ++j) {
            cin >> price[j] >> preference[j];
            price[j] = price[j] /100;
        }

        answer = BiggestPreference(total_budget);
        cout << answer << endl;
    }

    return 0;
}
