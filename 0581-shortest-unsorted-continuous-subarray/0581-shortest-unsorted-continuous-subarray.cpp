class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int left = 0;
        while (left < nums.size() && nums[left] == sorted[left])
            left++;

        int right = nums.size() - 1;
        while (right >= 0 && nums[right] == sorted[right])
            right--;

        if (left > right)
            return 0;

        return right - left + 1;
    }
};