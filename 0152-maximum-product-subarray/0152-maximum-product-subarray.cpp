
    class Solution {
public:
    unordered_map<int, pair<int, int>> memo; // Memoization for max and min product ending at each index
    
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size();
        memo.clear();
        memo[0] = {nums[0], nums[0]}; // {max_product, min_product} at index 0
        int result = nums[0];
        
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            int maxProd = max({num, num * memo[i - 1].first, num * memo[i - 1].second});
            int minProd = min({num, num * memo[i - 1].first, num * memo[i - 1].second});
            
            memo[i] = {maxProd, minProd};
            result = max(result, maxProd);
        }
        
        return result;
    }
};

