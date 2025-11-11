class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int>mp;int count = 0;


    for(auto num:nums)
        mp[num]++;




    vector<pair<int,int>>arr(mp.begin(),mp.end());
    sort(arr.begin(),arr.end(),[](auto &a,auto &b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    });


    vector<int>res;
    for(int i=0;i<k;i++) res.push_back(arr[i].first);
    return res;
    }
};