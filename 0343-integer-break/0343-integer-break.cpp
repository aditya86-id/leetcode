class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;

        int q = n / 3;
        int rem = n % 3;

        if(rem == 0) {
            return pow(3, q);
        } else if(rem == 1) {
            return pow(3, q - 1) * 4;
        } else { 
            return pow(3, q) * 2;
        }
    }
};
