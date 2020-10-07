#include <string>
#include <math.h>

using namespace std;

int titleToNumber(string s) {
    int size = s.size();
    int answer = 0;
    
    for (int i=size-1; i >=0; --i) {
        answer += pow(26,size-i-1) * ((int)s[i] - 64);
    }

    return answer;
}


int main() {

    printf("%d\n", titleToNumber("ZY"));
    return 0;
}