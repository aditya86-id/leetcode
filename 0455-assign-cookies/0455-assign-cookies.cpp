class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        int g_l = g.size();
        int s_l = s.size();

        while (i < g_l && j < s_l) {
            if (s[j] >= g[i]) {
    
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i;  
    }
};
