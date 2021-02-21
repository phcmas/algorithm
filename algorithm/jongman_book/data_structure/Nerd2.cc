// 종만북에 나온 풀이 구현

#include <stdio.h>
#include <map>

using namespace std;
int number_of_test_cases;
int number_of_people;
int problem[100001];
int ramen[100001];
map<int,int> coords;
int answer;

// 기존의 coords에 있는 점들 중, (x,y)를 dominate 하는 점이 있는지 확인
bool isDominated(int x, int y) {
    map<int,int>::iterator it = coords.lower_bound(x);
    if (it == coords.end()) return false;

    return y < it->second;
}

// 새로 추가된 (x,y)가 dominate 하는 coords의 점들을 제거
void removeDominated(int x, int y) {
    map<int,int>::iterator it = coords.lower_bound(x);
    
    if (it == coords.begin()) return;
    --it;

    while (true) {
        if (it->second > y) break;
        it = coords.erase(it);
        if (it == coords.begin()) break;
        --it;
    }

}

int registered(int x, int y) {
    if (isDominated(x,y)) return coords.size();
    removeDominated(x,y);
    coords[x] = y;
    return coords.size();
}

int sumOfPlayers() {
    int sum = 0;
    for (int j=0; j< number_of_people; ++j) {
        sum += registered(problem[j],ramen[j]);
    }

    return sum;
}

int main() {
    scanf("%d", &number_of_test_cases);

     //number_of_test_cases = 1;
     //number_of_people = 4;
     //problem[0] = 72;
     //ramen[0] = 50;
     //problem[1] = 57;
     //ramen[1] = 67;
     //problem[2] = 74;
     //ramen[2] = 55;
     //problem[3] = 64;
     //ramen[3] = 60;

    for (int i=0; i < number_of_test_cases; ++i) {
        scanf("%d", &number_of_people);
        coords.clear();
        
        for (int j=0; j < number_of_people; ++j) {
            scanf("%d %d", &problem[j], &ramen[j]);
        }

        answer = sumOfPlayers();

        printf("%d\n", answer);
    }

    return 0;
}


