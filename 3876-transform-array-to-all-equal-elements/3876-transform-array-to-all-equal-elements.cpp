class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        return solve(nums,1)<=k||solve(nums,-1)<=k;
    }
        int solve(vector<int> a,int target){
        int n=a.size();
        int c=0;
        for(int i=0;i<n-1;i++){
            if(a[i]!=target){
                c++;
                a[i]=-a[i];
                a[i+1]=-a[i+1];
            }
        }
        return(a[n-1]==target?c:INT_MAX);
    }
};