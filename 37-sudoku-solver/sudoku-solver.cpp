class Solution {
public:
    bool fun(int i, int j, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box, vector<vector<char>>& board) {
        if (i == 9) return true;  // Sudoku solved

        int i_ = i, j_ = j;
        if (j == 8) {
            i_ = i + 1;
            j_ = 0;
        } else {
            j_ = j + 1;
        }

        if (board[i][j] != '.') {
            return fun(i_, j_, row, col, box, board);
        }

        int num_box = (i / 3) * 3 + (j / 3);
        for (int k = 0; k < 9; k++) {
            if (row[i][k] == 0 && col[j][k] == 0 && box[num_box][k] == 0) {
                board[i][j] = char(k + '1');
                row[i][k] = col[j][k] = box[num_box][k] = 1;

                if (fun(i_, j_, row, col, box, board)) return true;  // Stop recursion if solved

                board[i][j] = '.';  // Backtrack
                row[i][k] = col[j][k] = box[num_box][k] = 0;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> box(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int num_box = (i / 3) * 3 + (j / 3);
                    row[i][num] = col[j][num] = box[num_box][num] = 1;
                }
            }
        }

        fun(0, 0, row, col, box, board);
    }
};
