class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        stack<int> st;
        unordered_map<int, int> map;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            map[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
            ans[i] = map[nums1[i]];
        return ans;
    }
};