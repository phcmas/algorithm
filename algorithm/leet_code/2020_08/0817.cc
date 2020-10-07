#include <vector>
using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
    vector<int> answer;
    int turn =0;
    int distributedCandies = 0;
    int num;
    int remainingCandies;
    int ithCandies;
    answer.resize(num_people);

    while (true) {
        if ((turn+1) * num_people * ((turn+1) * num_people +1) / 2 > candies) {
            distributedCandies = turn * num_people * (turn * num_people +1) / 2;
            break;
        }
        turn++;
    }

    num = turn * num_people *(turn-1)/2;

    for (int i=0; i < num_people; ++i) {
        answer[i] = num + turn *(i+1);
    }

    remainingCandies = candies - distributedCandies;

    for (int i=0; i < num_people; ++i) {
        ithCandies = turn * num_people + i+1;
        if (remainingCandies >= ithCandies) {
            answer[i] += ithCandies;
            remainingCandies -= ithCandies;
        } else {
            answer[i] += remainingCandies;
            break;
        }
    }

    return answer;
}

int main() {
    vector<int> answer = distributeCandies(10,3);

    return 0;
}