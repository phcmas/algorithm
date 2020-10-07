#include <vector>
#include <stdio.h>
#include <set>
#include <math.h>
#include <cstring>

using namespace std;
int cache[366];
set<int> travelDays;
vector<int> ticketCosts;
int maxDay;

// leetcode discussion 에서 본 어떤 사람의 풀이

int dp (int day) {
    int &answer = cache[day];
    if (day > maxDay) return 0;
    if (answer != -1) return answer;

    if (travelDays.count(day)) {
        answer = min (dp(day+1)+ticketCosts[0], dp(day+7)+ticketCosts[1]);
        answer = min (answer, dp(day+30)+ticketCosts[2]);
        return answer;
    }
    
    return dp (day+1);
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    for (int &iter : days) {
        travelDays.insert(iter);
    }
    
    ticketCosts = costs;
    memset(cache, -1, sizeof(cache));
    maxDay = days.back();
    return dp(days.front());
}


int main() {
    vector<int> days {1,2,3,4,5,6,7,8,9,10,30,31};
    //vector<int> days {1,2};
    //vector<int> days {1,2};
    vector<int> costs {2,7,15};
    int ans = mincostTickets(days, costs);

    printf("%d\n", ans);
    return 0;
}