class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int total = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();

        if (total % n != 0)
            return -1;

        int target = total / n;
        int balance = 0;
        int ans = 0;

        for (int x : machines) {
            int diff = x - target;
            balance += diff;

            
            ans = max(ans, max(abs(balance), diff));
        }

        return ans;
    }
};