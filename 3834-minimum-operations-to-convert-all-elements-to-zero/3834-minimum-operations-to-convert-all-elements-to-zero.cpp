class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        set<int> st;
        st.insert(0);
        for(auto each:nums){
            if(!st.count(each))
                cnt++;
            st.erase(st.lower_bound(each),st.end());
            st.insert(each);
        }
        return cnt;
    }
};