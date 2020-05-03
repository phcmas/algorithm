#include <vector>
#include <iostream>

int direction[4][2][2] = {
    {
        {1,0},
        {1,-1}
    },
    {
        {1,0},
        {1,1}
    },
    {
        {1,0},
        {0,1}
    },
    {
        {0,1},
        {1,1}
    }
};

bool checkBoundary (int y, int x, int index, std::vector<std::vector<int>> &board) {
    int new_coord1_y = y+ direction[index][0][0];
    int new_coord1_x = x + direction[index][0][1];
    int new_coord2_y = y+ direction[index][1][0];
    int new_coord2_x = x + direction[index][1][1];

    if (new_coord1_x < 0 || new_coord1_x >= board[0].size() || new_coord2_x <0 || new_coord2_x >= board[0].size() ||
        new_coord1_y >= board.size() || new_coord2_y >= board.size()) return true;
    if (board[y][x] || board[new_coord1_y][new_coord1_x] == 1 || board[new_coord2_y][new_coord2_x] ==1) return true;

    return false;
}

int countBoard(std::vector<std::vector<int>> &board, int number_of_whites) {
    if (number_of_whites % 3 != 0) return 0;
    int count = 0;
    bool all_black = true;
    int i=0;
    int j=0;

    for (i; i<board.size(); ++i) {
        for (j; j<board[0].size(); ++j) {
            if (board[i][j] == 0) {
                all_black =false;
                break;
            }
        }
        if (!all_black) break;
        else j=0;
    }

    for (int k=0; k<4; ++k) {
        std::vector<std::vector<int>> new_board (board);
        if (checkBoundary(i, j, k, board)) continue;
        if (number_of_whites == 3) return 1;
        new_board[i][j] = 1;
        new_board[i + direction[k][0][0]][j + direction[k][0][1]] = 1;
        new_board[i + direction[k][1][0]][j + direction[k][1][1]] = 1;
        count += countBoard(new_board, number_of_whites-3);
    }

    return count;
}


void printBoard(std::vector<std::vector<int>> &board) {
    int height = board.size();
    int width = board[0].size();

    for (int i=0; i< height; ++i) {
        for (int j=0; j<width; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(void) {
    int number_of_test_case = 0;
    std::vector<int> answers;
    std::vector<std::vector<int>> board;

    std::cin >> number_of_test_case;

    for (int i=0; i < number_of_test_case; ++i) {
        int height,width;
        int number_of_whites=0;
        std::string input;
        std::cin >> height >> width;
        board.resize(height);

        for (int j=0; j < height; ++j) {
            std::cin >> input;
            for (int k=0; k<width; ++k) {
                if (input[k] == '#') board[j].push_back(1);
                else if (input[k] == '.') {
                    board[j].push_back(0);
                    number_of_whites +=1;
                }
            }
        }

        answers.push_back(countBoard(board, number_of_whites));
        board.clear();
    }

    for (int iter : answers) {
        std::cout << iter << std::endl;
    }

    return 0;
}





