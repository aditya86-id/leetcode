class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
              int m = dungeon.size();
              int n = dungeon[0].size();  

              vector<vector<int>>dp(m,vector<int>(n,-1));

              return helper(0,0,dungeon,dp);

    }

    private:
    int helper(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>>&dp){
        int m = dungeon.size();
        int n = dungeon[0].size();
        

        if(i==m-1&&j==n-1){return max(1,1-dungeon[i][j]);}

        if(i>=m||j>=n){
            return INT_MAX;}


            if(dp[i][j]!=-1){return dp[i][j];}

            int right=helper(i,j+1,dungeon,dp);
            int down=helper(i+1,j,dungeon,dp);

            int health=min(right,down)-dungeon[i][j];
            dp[i][j]=max(1,health);

            return dp[i][j];
        }

    
    
};