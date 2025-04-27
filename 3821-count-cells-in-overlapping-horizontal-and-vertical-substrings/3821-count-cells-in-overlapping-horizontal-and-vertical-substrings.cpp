vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
class Solution {
public:
    int countCells(vector<vector<char>>& grid, const string& pattern) {
        int n = grid.size(), m = grid[0].size(), pn = pattern.size();
        string h = pattern + "#", v = pattern + "#";
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                h.push_back(grid[i][j]);
        for(int j = 0; j < m; j++)
            for(int i = 0; i < n; i++)
                v.push_back(grid[i][j]);
        vector<int> zh = z_function(h), zv = z_function(v);
        vector<vector<int>> ok(n, vector<int>(m, 0));
        for(int i = pn + 1, sz = h.size(), last = 0; i < sz; i++) {
            if(last < i - 1) last = i - 1;
            if(zh[i] == pn) {
                int end = i + pn - 1;
                while(last < end) {
                    int cIdx = (++last) - (pn + 1);
                    ok[cIdx / m][cIdx % m] |= 0b01;
                }
            }
        }
        for(int i = pn + 1, sz = v.size(), last = 0; i < sz; i++) {
            if(last < i - 1) last = i - 1;
            if(zv[i] == pn) {
                int end = i + pn - 1;
                while(last < end) {
                    int cIdx = (++last) - (pn + 1);
                    ok[cIdx % n][cIdx / n] |= 0b10;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += count(ok[i].begin(), ok[i].end(), 0b11);
        }
        return ans;
    }
};