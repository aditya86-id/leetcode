class Solution {
public:
    bool wordPattern(string pat, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rev; 
        string temp = "";
        int j = 0;

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                if (j == pat.size()) 
                    return false;
                if (mp.count(pat[j])) {
                    if (mp[pat[j]] != temp) 
                        return false;
                } else {
                    if (rev.count(temp)) 
                        return false; 
                    mp[pat[j]] = temp;
                    rev[temp] = pat[j];
                }
                j++;
                temp = "";
            } 
            else 
                temp += s[i];
        }
        return j == pat.size();
    }
};