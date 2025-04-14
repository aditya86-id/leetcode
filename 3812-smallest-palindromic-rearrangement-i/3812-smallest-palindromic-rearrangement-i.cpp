class Solution {
public:
    string smallestPalindrome(string s) {

        map<char, int> mp;
        // Step 1: Count the frequency of each character in the string
        for (char ch : s) {
            mp[ch]++;
        }
        // Step 2: Check how many characters have an odd frequency
        int oddCount = 0;
        char midChar = '$';
        for (auto &[ch, cnt] : mp) {
            if (cnt % 2 != 0) {
                oddCount++;
                midChar = ch;
            }
        }

        // Step 3: If more than one character has an odd frequency, return an empty string
        if (oddCount > 1) return "";

        string half = "";
        for (auto &[ch, cnt] : mp) {
            half += string(cnt / 2, ch);
        }
        // Step 4: Sort the half string to get the lexicographically smallest palindrome
        sort(half.begin(), half.end());  
        // Step 5: Construct the final palindrome 
        string res = half;
        if (midChar != '$') {
            res += string(1, midChar); // Add middle character if exists
        }
        
        reverse(half.begin(), half.end());
        
        res += half;

        return res;
    }
};