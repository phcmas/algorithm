"""
36. Valid Sudoku
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Example 1:
Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
"""


class Solution:
    def no_duplicates(self, elems: list[str]):
        return len(set(elems) - {"."}) == len(elems) - elems.count(".")

    def is_square_valid(self, board: list[list[str]]):
        squares = [[], [], []]

        for i, row in enumerate(board):
            for j, square in enumerate(squares):
                square.extend(row[j * 3 : j * 3 + 3])

                if i % 3 != 2:
                    continue

                if not self.no_duplicates(squares[j]):
                    return False

                squares[j].clear()

        return True

    def is_valid_sudoku(self, board: list[list[str]]) -> bool:
        is_row_valid = all(self.no_duplicates(row) for row in board)
        is_col_valid = all(self.no_duplicates(list(col)) for col in zip(*board))
        is_square_valid = self.is_square_valid(board)

        return is_row_valid and is_col_valid and is_square_valid
