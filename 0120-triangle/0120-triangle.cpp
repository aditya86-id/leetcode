class Solution {
public:
    int helper(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>&memo){
        if(i==n-1)
            return triangle[i][j];
            if(memo[i][j] != -1)
			return memo[i][j];


        int bottom = triangle[i][j]+helper(i+1,j,n,triangle,memo);
        int bottom_right=triangle[i][j]+helper(i+1,j+1,n,triangle,memo);

        return memo[i][j]=min(bottom,bottom_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>memo(n,vector<int>(n,-1));
        return helper(0,0,n,triangle,memo);
    }
};