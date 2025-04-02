class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return dfs(s, wordSet, memo);
    }
    
private:
    vector<string> dfs(const string& s, unordered_set<string>& wordSet, unordered_map<string, vector<string>>& memo) {
        if (memo.count(s)) {
            return memo[s];
        }
        
        vector<string> result;
        if (s.empty()) {
            return {""};
        }
        
        for (int i = 1; i <= s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (wordSet.count(prefix)) {
                vector<string> suffixes = dfs(s.substr(i), wordSet, memo);
                for (const string& suffix : suffixes) {
                    result.push_back(suffix.empty() ? prefix : prefix + " " + suffix);
                }
            }
        }
        
        memo[s] = result;
        return result;
    }
};
