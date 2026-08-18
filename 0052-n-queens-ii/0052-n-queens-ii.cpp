class Solution {
public:

    bool isSafe(vector<vector<int>>& board, int row, int col) {
        int n = board.size();

        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1)
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--) {

            if (board[i][j] == 1)
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n;
             i--, j++) {

            if (board[i][j] == 1)
                return false;
        }

        return true;
    }

    void solve(int row, vector<vector<int>>& board, int& count) {
        int n = board.size();

        // All queens have been placed
        if (row == n) {
            count++;
            return;
        }

        // Try every column in the current row
        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col)) {

                // Place queen
                board[row][col] = 1;

                // Place queen in next row
                solve(row + 1, board, count);

                // Backtrack
                board[row][col] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));

        int count = 0;

        solve(0, board, count);

        return count;
    }
};