#include <iostream>
#include <vector>
#include <cstring>

/* 내가 처음 구현 했던 코드 - 지금까지 확인된 테스트케이스는 모두 통과하지만 뭔가 문제가 있는듯?? */

int cache[101][101];
int sequence1[100];
int sequence2[100];
int next_elem_index1[100];
int next_elem_index2[100];
int length1 = 0;
int length2 = 0;
int answers[50];

int max (int fst, int snd) {
    if (fst <= snd) return snd;
    else return fst;
}

int NextElements (int start_index, int *sequence, int size, int *next_elements) {
    int count = 0;
    for (int i=start_index; i < size; ++i) {
        if (sequence[i] > sequence[start_index]) {
            next_elements[count] = i;
            count++;
        }
    }
    return count;
}

bool IsFirstMove(int start1, int start2, int number_of_next_elem1, int number_of_next_elem2) {
    if (sequence1[start1] < sequence2[start2]) {
        if (number_of_next_elem1 > 0) return true;
        else return false;
    } else if (sequence1[start1] > sequence2[start2]) {
        if (number_of_next_elem2 > 0) return false;
        else return true;
    } else {
        if (number_of_next_elem1 > 0) return true;
        else return false;
    }
}

int JLIS (int start1, int start2) {
    int number_of_next_elem1 = NextElements(start1, &sequence1[0], length1, &next_elem_index1[0]);
    int number_of_next_elem2 = NextElements(start2, &sequence2[0], length2, &next_elem_index2[0]);
    int number =1;
    int &answer =cache[start1][start2];
    bool is_same = sequence1[start1] == sequence2[start2];
    
    if (answer != -1) return answer;
    if (is_same) number--;
    if (number_of_next_elem1 == 0 && number_of_next_elem2 ==0) return number+1;

    bool move_first = IsFirstMove(start1,start2,number_of_next_elem1,number_of_next_elem2);

    if (move_first) {
        for (int i=0; i<number_of_next_elem1; ++i) {
            answer = max (answer, JLIS(next_elem_index1[i],start2));
        }
    } else {
        for (int i=0; i<number_of_next_elem2; ++i) {
            answer = max (answer, JLIS(start1, next_elem_index2[i]));
        }
    }

    answer += number;
    return answer;
}

int main() {
    int number_of_test_cases = 1;
    int element =0;
    scanf("%d", &number_of_test_cases);

    for (int i=0; i< number_of_test_cases; ++i) {
        int answer = 0;
        scanf("%d", &length1);
        scanf("%d", &length2);

         for (int j=0; j<length1; ++j) {
              scanf("%d", &element);
              sequence1[j] = element;
         }

         for (int j=0; j<length2; ++j) {
             scanf ("%d", &element);
             sequence2[j] = element;
         }

         memset(cache, -1, sizeof(cache));

         for (int j=0; j < length1; ++j) {
             for (int k=0; k<length2; ++k) {
                 answer = max (answer, JLIS(j,k));
             }
         }

         answers[i] = answer;
    }

    for (int i=0; i<number_of_test_cases; ++i) {
        printf("%d\n", answers[i]);
    }

    return 0;
}