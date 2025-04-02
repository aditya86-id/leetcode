class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int up = matrix[i - 1][j];
                int leftDiag = (j > 0) ? matrix[i - 1][j - 1] : INT_MAX;
                int rightDiag = (j < m - 1) ? matrix[i - 1][j + 1] : INT_MAX;
                matrix[i][j] += min(up, min(leftDiag, rightDiag));
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};
