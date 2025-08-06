class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 1) return 0;

        long long prod = 1;
        int count = 0;
        int i = 0;

        for (int j = 0; j < n; ++j) {
            prod *= nums[j];
            while (prod >= k && i <= j) {
                prod /= nums[i++];
            }
            count += (j - i + 1);
        }
        return count;
    }
};
