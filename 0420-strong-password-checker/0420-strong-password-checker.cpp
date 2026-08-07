class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = s.size();

        bool lower = false, upper = false, digit = false;

        for (char c : s) {
            if (islower(c)) lower = true;
            else if (isupper(c)) upper = true;
            else if (isdigit(c)) digit = true;
        }

        int missing = (!lower) + (!upper) + (!digit);

        vector<int> groups;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            groups.push_back(j - i);
            i = j;
        }

        int replace = 0;
        for (int len : groups)
            replace += len / 3;

        if (n < 6)
            return max(missing, 6 - n);

        if (n <= 20)
            return max(missing, replace);

        int del = n - 20;

        vector<int> lens = groups;

        // delete from mod 0
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < lens.size() && del > 0; i++) {
                while (lens[i] >= 3 && lens[i] % 3 == k && del > k) {
                    lens[i] -= k + 1;
                    del -= k + 1;
                }
            }
        }

        replace = 0;
        for (int len : lens)
            replace += len / 3;

        return (n - 20) + max(missing, replace);
    }
};