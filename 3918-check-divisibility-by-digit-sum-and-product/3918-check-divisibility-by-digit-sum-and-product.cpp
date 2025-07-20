class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int s = 0;
        int p = 1;
        while (n > 0) {
            int rem = n % 10;
            s += rem;
            p *= rem;
            n /= 10;
        }
        int total = s + p;
        if (total == 0) return false;
        return (original % total) == 0;
    }
};
