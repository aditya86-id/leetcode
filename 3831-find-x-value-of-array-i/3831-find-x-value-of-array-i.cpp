class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);  // Fixed type
        vector<vector<int>> dp(n + 1, vector<int>(k, 0));

        for (int i = 0; i < n; i++) {
            dp[i + 1][nums[i] % k]++;

            for (int j = 0; j < k; j++) {
                if (dp[i][j] > 0) {
                    int rem = (int)(((long long)j * nums[i]) % k);  // safer cast
                    dp[i + 1][rem] += dp[i][j];
                }
            }

            for (int j = 0; j < k; j++) {
                result[j] += dp[i + 1][j];
            }
        }

        return result;
    }
};
