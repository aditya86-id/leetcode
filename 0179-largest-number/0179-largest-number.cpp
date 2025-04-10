class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string>s(n);
        for(int i=0;i<n;i++){
            s[i]=to_string(nums[i]);
        }

         sort(s.begin(),s.end(),cmp);
         string ans = accumulate(s.begin(),s.end(),string());
         if(ans[0]=='0') return "0";
         return ans;
    }

    static bool cmp(string& x,string& y){
        return x+y>y+x;
        }
};