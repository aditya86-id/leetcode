class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int precolor=image[sr][sc];
        vector<vector<int>>ans = image;
        int drow[]={0,+1,0,-1};
        int dcol[]={+1,0,-1,0};
        dfs(sr,sc,color,image,ans,drow,dcol,precolor);
    return ans;
    }

    void dfs(int row, int col,int color, vector<vector<int>>& image, vector<vector<int>>& ans, int drow[], int dcol[],  int precolor){
    ans[row][col]=color;
    int m=image.size();
    int n=image[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && image[nrow][ncol]==precolor && ans[nrow][ncol]!=color){
            dfs(nrow,ncol,color, image, ans, drow,dcol,precolor);
        }
    }
}

    
};