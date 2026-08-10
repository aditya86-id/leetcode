class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;

        int mn = arrays[0][0];
        int mx = arrays[0].back();

        for (int i = 1; i < arrays.size(); i++) {
            ans = max(ans, arrays[i].back() - mn);

            ans = max(ans, mx - arrays[i][0]);

            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i].back());
        }

        return ans;
    }
};