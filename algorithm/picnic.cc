#include <vector>
#include <iostream>

bool areFriends[10][10];

int countPairing(std::vector<int> remains) {
    std::vector<int> pair_indices;
    std::vector<int> new_remains;
    int answer =0;
    int first_element = remains[0];

    if (remains.size() == 2) {
        if (areFriends[first_element][remains[1]]) return 1;
        else return 0;
    }

    for (int i=0; i < remains.size(); ++i) {
        if (areFriends[first_element][remains[i]] == true) {
            pair_indices.push_back(i);
        }
    }

    for (int i=0; i<pair_indices.size(); ++i) {
        int pair_index = pair_indices[i];
        for (int j=1; j< pair_index; ++j) {
            new_remains.push_back(remains[j]);
        }
        for (int j=pair_index+1; j< remains.size();++j) {
            new_remains.push_back(remains[j]);
        }
        answer += countPairing(new_remains);
        new_remains.clear();
    }
    return answer;
}
void clearAreFriends() {
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            areFriends[i][j] =false;
        }
    }
}

int main (void) {
    std::vector<int> answers;
    int no_of_test_case = 1;
    
    clearAreFriends();

    std::cin >> no_of_test_case;

    for (int i=0; i< no_of_test_case; ++i) {
        int no_of_students=6, no_of_friends=10;
        std::vector<int> remains;
        std::cin >> no_of_students >> no_of_friends;
        
        for (int j=0; j< no_of_friends; ++j) {
            int first_one, second_one;
            std::cin >> first_one >> second_one;
            areFriends[first_one][second_one] = true;
            areFriends[second_one][first_one] = true;
        }

        for (int k=0; k< no_of_students; ++k) {
            remains.push_back(k);
        }

        answers.push_back(countPairing(remains));
        clearAreFriends();
        remains.clear();
    }

    for (int i=0; i< no_of_test_case; ++i) {
        std::cout << answers[i] << std::endl;
    }

}















