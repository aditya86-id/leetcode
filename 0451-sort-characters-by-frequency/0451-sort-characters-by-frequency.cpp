class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto &ch:s) mp[ch]++;

        vector<pair<char,int>>temp;
        for(auto it:mp) temp.push_back({it.first,it.second});

        auto lambda=[&](pair<char,int>&p1,pair<char,int>&p2){
            return p1.second>p2.second;
        };
        sort(begin(temp),end(temp),lambda);

        string ans="";
        int i=0,n=temp.size();
        for(int i=0;i<n;i++){
            while(temp[i].second--){
                ans.push_back(temp[i].first);
            }
        }
        return ans;
    }
};