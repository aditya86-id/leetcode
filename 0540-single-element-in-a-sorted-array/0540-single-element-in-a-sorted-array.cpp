class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    unordered_map<int,int>freq;
    for(auto i:nums){

        freq[i]++;

    }  
    for(int i=0;i<nums.size();i++){
        if(freq[nums[i]]==1){
            return nums[i];
        }
    }
         return -1;

    }
};