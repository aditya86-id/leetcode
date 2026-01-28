class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    vector<int>ans;
    vector<int>sol;
    int n = nums.size();

    for(int i=0;i<n;i++){
        if(nums[i]!=0) 
            ans.push_back(nums[i]);
        else
            sol.push_back(nums[i]);


         
    }   nums.clear();
        nums.insert(nums.end(), ans.begin(), ans.end());
        nums.insert(nums.end(), sol.begin(), sol.end());
    }
};