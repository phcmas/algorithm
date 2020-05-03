#include <vector>
#include <iostream>

int count(std::vector<int> remains, bool table[][10]) {
    std::vector<int> temp;
    std::vector<int> new_remains;
    int answer =0;

    if (remains.size() == 2) {
        if (table[remains[0]][remains[1]]) return 1;
        else return 0;
    }

    for (int i=0; i < 10; ++i) {
        if (table[remains[0]][i] == true) {
            temp.push_back(i);
        }
    }

    for (int i=0; i<temp.size(); ++i) {
        int num = temp[i];
        for (int j=1; j< num; ++j) {
            new_remains.push_back(remains[j]);
        }
        for (int j=num+1; j< remains.size();++j) {
            new_remains.push_back(remains[j]);
        }
        answer += count(new_remains,table);
    }
    return answer;
}

void print(bool table [][10]) {
    for (int j=0; j<10; ++j) {
        for (int k=0; k<10; ++k){
            std::cout << table[j][k] << " ";
        }
        std::cout<<std::endl;
    }
}

int main (void) {
    std::vector<int> no_of_students;
    std::vector<int> no_of_friends;
    std::vector<int> counts;
    int no_of_test_case = 0;
    std::vector<bool**> areFriends;

    // std::cin >> no_of_test_case;
    // areFriends.reserve(no_of_test_case);

    // for (int i=0; i<no_of_test_case; ++i) {
    //     for (int j=0; j<10; ++j) {
    //         for (int k=0; k<10; ++k) {
    //             areFriends[i][j][k] = false;
    //             std::cout << areFriends[i][j][k] << " ";
    //         }
    //         std::cout << std::endl;
    //     }
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    // }

    bool temp[10][10];
    temp[0][1] = true;
    temp[1][0] = true;
    print(temp);

    // for (int i=0; i< no_of_test_case; ++i) {
    //     int num1,num2;
    //     std::cin >> num1 >> num2;
    //     no_of_students.push_back(num1);
    //     no_of_friends.push_back(num2);
    // }

    // for (int i=0; i< no_of_test_case; ++i) {
    //     int num1, num2;
    //     std::cin >> num1 >> num2;
    //     areFriends[i][num1][num2] = true;
    //     areFriends[i][num2][num1] = true;
    // }

    // for (int i=0; i < no_of_test_case; ++i) {
    //     std::vector<int> remains;
    //     for (int j=0; j< no_of_friends[i]; ++j) {
    //         remains.push_back(j);
    //     }
    //     int answer = count(remains, areFriends[i]);
    //     remains.clear();
    // }




}
















