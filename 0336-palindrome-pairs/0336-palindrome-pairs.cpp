class Solution {
public:
    bool isPalindrome(const string &s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

    vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string, int> wordMap;
    vector<vector<int>> result;
    int n = words.size();
    
    // Store reversed words in the map
    for (int i = 0; i < n; i++) {
        string reversedWord = words[i];
        reverse(reversedWord.begin(), reversedWord.end());
        wordMap[reversedWord] = i;
    }
    for (int i = 0; i < n; i++) {
        string word = words[i];
        int len = word.length();
        
        for (int j = 0; j <= len; j++) {
            string left = word.substr(0, j);
            string right = word.substr(j);
            if (isPalindrome(word, 0, j - 1)) {
                if (wordMap.count(right) && wordMap[right] != i) {
                    result.push_back({wordMap[right], i});
                }
            }
            if (isPalindrome(word, j, len - 1) && !right.empty()) {
                if (wordMap.count(left) && wordMap[left] != i) {
                    result.push_back({i, wordMap[left]});
                }
            }
        }
    }
    
    return result;
}

    
};