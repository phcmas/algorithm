#include <vector>
#include <iostream>

const int INF=99999, CHECK =10;

/* row : switch number, column : connected clocks number */
const int clockswitch[10][16] = {
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
    {1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
    {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

int min (int num1, int num2) {
    if (num1 <= num2) return num1;
    else return num2;
}

void changeClock(std::vector<int> &clocks, int switch_num) {
    if (switch_num <0 || switch_num > 10 || clocks.size() !=16) {
        std::cout << "Error!";
        return;
    } 

    const int *connected_clocks = clockswitch[switch_num];
    for (int i=0; i < 15; ++i) {
        if (connected_clocks[i] ==0) continue;
        switch (clocks[i]) {
            case 12 : clocks[i] =3; break;
            default : clocks[i] +=3; break;
        }
    }
}

bool allPointsAt12(std::vector<int> &clocks) {
    for (int i=0; i <15; ++i) {
        if (clocks[i] != 12) return false;
    }

    return true;
}

int countClock(std::vector<int> &clocks, int switch_num) {
    int answer = INF;

    if (switch_num ==10) {
        answer = allPointsAt12(clocks) ? 0 : INF;
        return answer;
    }

    for (int j=0; j<4; ++j) {
        answer = min(answer, j+countClock(clocks, switch_num+1));            
        changeClock(clocks, switch_num);
    }
    return answer;
}

int main(void) {
    int number_of_test_case = 1;
    std::vector<int> clocks;
    std::vector<int> answers;
    int inputs[16];
    std::cin >> number_of_test_case;

    for (int i=0; i< number_of_test_case; ++i) {
        for (int j=0; j < 16; ++j) {
            std::cin >> inputs[j];
            int input = inputs[j];
            try {
                if (input !=3 && input !=6 && input !=9 && input !=12) throw input;
            } catch (int exception) {
                std::cout << "You entered an incorrect value: " << exception << std::endl;
                return 1;
            }
            clocks.push_back(input);
        }
        answers.push_back(countClock(clocks,0));
    }

    for (int iter : answers) {
        std::cout << iter << std::endl;
    }

    return 0;
}













