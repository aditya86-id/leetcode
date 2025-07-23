class Solution {
private:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // Base case
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
        else
            return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    }

public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return f(n1 - 1, n2 - 1, s1, s2, dp);
    }
};
