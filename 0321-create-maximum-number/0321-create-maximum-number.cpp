class Solution {
public:

    vector<int> getMax(vector<int>& nums, int k) {
        vector<int> st;
        int remove = nums.size() - k;

        for (int x : nums) {
            while (!st.empty() && remove > 0 && st.back() < x) {
                st.pop_back();
                remove--;
            }

            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == b.size())
            return true;

        if (i == a.size())
            return false;

        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;

        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {

            if (greater(a, i, b, j))
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }

        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> ans;

        int n = nums1.size();
        int m = nums2.size();

        int start = max(0, k - m);
        int end = min(k, n);

        for (int x = start; x <= end; x++) {

            vector<int> a = getMax(nums1, x);

            vector<int> b = getMax(nums2, k - x);

            vector<int> cur = merge(a, b);

            if (ans.empty() || greater(cur, 0, ans, 0)) {
                ans = cur;
            }
        }

        return ans;
    }
};