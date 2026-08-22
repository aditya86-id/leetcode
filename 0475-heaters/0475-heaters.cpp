class Solution {
public:
    int f(int r,int n,int m,vector<int>& houses, vector<int>& heaters){
        int i=0,j=0;
        while(i<n && j<m){
            if(abs(houses[i]-heaters[j])<=r) i++;
            else
            j++;
            if(j==m) return false;
        }
        return i==n;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size();
        int m=heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans=-1;
        int l=0,r=1e9,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(f(mid,n,m,houses,heaters)){
                r=mid-1;
                ans=mid;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};