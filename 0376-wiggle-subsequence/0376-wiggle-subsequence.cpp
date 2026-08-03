class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 1;

        stack<int> st;

        // Store all non-zero differences
        for (int i = 0; i < n - 1; i++) {
            int diff = nums[i + 1] - nums[i];
            if (diff != 0)
                st.push(diff);
        }

        if (st.empty())
            return 1;

        int count = 2;
        int prev = st.top();
        st.pop();

        while (!st.empty()) {
            int curr = st.top();
            st.pop();

            if ((curr > 0 && prev < 0) || (curr < 0 && prev > 0)) {
                count++;
            }

            prev = curr;
        }

        return count;
    }
};