class Solution {
public:
    vector<vector<string>> res;

    void solve(int n, int row, vector<int>& queens, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) board[i][queens[i]] = 'Q';
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) continue;
            queens[row] = col;
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
            solve(n, row + 1, queens, cols, diag1, diag2);
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n, 0);
        vector<bool> cols(n, false), diag1(2*n-1, false), diag2(2*n-1, false);
        solve(n, 0, queens, cols, diag1, diag2);
        return res;
    }
};