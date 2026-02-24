class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> freq;
        int k = 0;

        for (int num : nums) {
            if (freq[num] < 2) {
                nums[k++] = num;
                freq[num]++;
            }
        }
        return k;
    }
};