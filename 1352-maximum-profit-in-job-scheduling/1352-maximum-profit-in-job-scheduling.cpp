

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<array<long long, 3>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }

        // Greedy: sort by end time
        sort(jobs.begin(), jobs.end());

        vector<long long> dp(n);
        vector<long long> endTimes;

        for (auto &job : jobs) endTimes.push_back(job[0]);

        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            long long currProfit = jobs[i][2];

            // Find last job that ends <= current startTime
            int idx = upper_bound(endTimes.begin(), endTimes.end(), jobs[i][1]) - endTimes.begin() - 1;

            if (idx != -1) currProfit += dp[idx];

            dp[i] = max(dp[i-1], currProfit);
        }

        return dp[n-1];
    }
};
