#include <iostream>
#include <vector>
#include <cstring>

int cache[101][101];
std::vector<int> first_sequence;
std::vector<int> second_sequence;

int max (int fst, int snd) {
    if (fst <= snd) return snd;
    else return fst;
}

std::vector<int> NextElements (int start_index, std::vector<int> &sequence) {
    std::vector<int> result;
    for (int i=start_index; i < sequence.size(); ++i) {
        if (sequence[i] > sequence[start_index]) {
            result.push_back(i);
        }
    }
    return result;
}

bool IsFirstMove(int start1, int start2, int number_of_next_elem1, int number_of_next_elem2) {
    if (first_sequence[start1] < second_sequence[start2]) {
        if (number_of_next_elem1 > 0) return true;
        else return false;
    } else if (first_sequence[start1] > second_sequence[start2]) {
        if (number_of_next_elem2 > 0) return false;
        else return true;
    } else {
        if (number_of_next_elem1 > 0) return true;
        else return false;
    }
}

int JLIS (int start1, int start2) {
    std::vector<int> next_elem_index1 = NextElements(start1, first_sequence);
    std::vector<int> next_elem_index2 = NextElements(start2, second_sequence);
    int number_of_next_elem1 = next_elem_index1.size();
    int number_of_next_elem2 = next_elem_index2.size();
    int number =1;
    int &answer =cache[start1][start2];
    bool is_same = first_sequence[start1] == second_sequence[start2];
    
    if (answer != -1) return answer;
    if (is_same) number--;
    if (number_of_next_elem1 == 0 && number_of_next_elem2 ==0) return number+1;

    bool move_first = IsFirstMove(start1,start2,number_of_next_elem1,number_of_next_elem2);

    if (move_first) {
        for (int &iter : next_elem_index1) {
            answer = max(answer, JLIS(iter,start2));
        }
    } else {
        for (int &iter : next_elem_index2) {
            answer = max (answer, JLIS(start1, iter));
        }
    }

    answer += number;
    return answer;
}

int main() {
    int number_of_test_cases = 0;
    std::vector<int> answers;
    std::cin >>number_of_test_cases;

    for (int i=0; i< number_of_test_cases; ++i) {
        int answer = 0;
        int first_sequence_length = 0;
        int second_sequence_length = 0;
        first_sequence.clear();
        second_sequence.clear();
        std::cin >> first_sequence_length;
        std::cin >> second_sequence_length;

         for (int j=0; j<first_sequence_length; ++j) {
              int element = 0;
              std::cin >> element;
              first_sequence.push_back(element);
         }

         for (int j=0; j<second_sequence_length; ++j) {
             int element = 0;
             std::cin >> element;
             second_sequence.push_back(element);
         }
         memset(cache, -1, sizeof(cache));

         for (int j=0; j<first_sequence_length; ++j) {
             for (int k=0; k<second_sequence_length; ++k) {
                 answer = max (answer, JLIS(j,k));
             }
         }

         answers.push_back(answer);
    }

    for (int i=0; i<number_of_test_cases; ++i) {
        std::cout << answers[i]<< std::endl;
    }

    return 0;
}