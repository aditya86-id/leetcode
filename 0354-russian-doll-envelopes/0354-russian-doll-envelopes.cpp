class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        auto comp = [](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        set<int> ans;
        for(auto &envelope: envelopes) {
            int num = envelope[1];
            auto it = ans.lower_bound(num);
            if(it != ans.end()) {
                ans.erase(it);
            }
            ans.insert(num);
        }
        return ans.size();
    }
};