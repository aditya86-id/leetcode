class Solution {
public:
vector<vector<int>> dp;

    int maxSum(vector<int>& pref, int idx, int n, int k) {
        if (k == 1) return pref[n - 1] - (idx > 0 ? pref[idx - 1] : 0);

        if (dp[idx][k] != -1) return dp[idx][k];

        int sum = INT_MAX, leftSum;
        int low = idx, high = n - k;

        while (low <= high) {
            int mid = (low + high) / 2;
            leftSum = pref[mid] - (idx > 0 ? pref[idx - 1] : 0);
            int rightSum = maxSum(pref, mid + 1, n, k - 1);
            sum = min(sum, max(leftSum, rightSum));

            if (leftSum < rightSum) low = mid + 1;
            else high = mid - 1;
        }

        return dp[idx][k] = sum;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+nums[i];
        dp.assign(n,vector<int>(k+1,-1));

        return maxSum(pref,0,n,k);
    }
};