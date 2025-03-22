class Solution {
public:
    int candy(vector<int>& A) {
        int n = A.size(), ans = 0;
        if (n == 0) return 0;

        vector<int> candy(n, 0); 
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i) pq.push({-A[i], i});

        while (!pq.empty()) {
            auto [negRating, idx] = pq.top();
            pq.pop();
            int left = (idx == 0 ? 0 : (A[idx - 1] == A[idx] ? 0 : candy[idx - 1]));
            int right = (idx == n - 1 ? 0 : (A[idx + 1] == A[idx] ? 0 : candy[idx + 1]));
            candy[idx] = max(left, right) + 1;
            ans += candy[idx];
        }
        return ans;
    }
};