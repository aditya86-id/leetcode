class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int len=s.size(), a=0, b=0;
        for (char ch: s) {
            if (ch=='a') a++;
            else b++;
        }
        return len - (min(a, b)*2);
    }
};