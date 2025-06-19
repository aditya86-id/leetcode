class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

        for (int num : nums) {
            if (mp[num - 1].size() > 0) {
                int prevLength = mp[num - 1].top();
                mp[num - 1].pop();
                mp[num].push(prevLength + 1);
            } else {
                mp[num].push(1); // Start a new subsequence
            }
        }

        for (auto& [key, pq] : mp) {
            while (!pq.empty()) {
                if (pq.top() < 3) return false;
                pq.pop();
            }
        }

        return true;
    }
};
