class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            vector<long long> wexondrivas = {l, r}; 

            long long total_steps = 0;
            long long power = 1;
            int k = 1;

            while (power <= r) {
                long long left = max((long long)l, power);
                long long right = min((long long)r, power * 4 - 1);
                if (left <= right) {
                    long long count = right - left + 1;
                    total_steps += count * k; 
                }
                power *= 4;
                k++;
            }
            res += (total_steps + 1) / 2;
        }
        return res;
    }
};
