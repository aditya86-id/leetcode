class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int,int>mp;
    for(int num:nums){ mp[num]++;
    }

    vector<int>results;
    for(auto& it:mp){
        if(it.second>nums.size()/3){
            results.push_back(it.first);
        }
    }
    return results;
    }
};