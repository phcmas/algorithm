#include <iostream>
#include <cstring>

using namespace std;
int number_of_test_cases;
int number_of_sushi;
int n;
int total_budget;
int cache[201];
int price[20];
int preference[20];
int answer;

int max (int a, int b) {
    if (a>b) return a;
    else return b;
}

int BiggestPreference() {
    for (int budget=1; budget <= total_budget; ++budget) {
        int &ret = cache[budget%201];

        for (int i=0; i< number_of_sushi; ++i) {
            if (budget < price[i]) continue;
            ret = max (ret, preference[i]+cache[(budget-price[i])%201]);
        }
    }

    return cache[total_budget%201];
}

int main() {
    cin >> number_of_test_cases;

    for (int i=0; i < number_of_test_cases; ++i) {
        memset(cache,0,sizeof(cache));
        cin >> number_of_sushi >> total_budget;
        total_budget = total_budget /100;

        for (int j=0; j < number_of_sushi; ++j) {
            cin >> price[j] >> preference[j];
            price[j] = price[j] / 100;
        }
        answer = BiggestPreference();
        cout << answer << endl;
    }

    return 0;
}



