class Solution {
public:
    int mark(vector<vector<int>>&board,vector<vector<int>>&vis,int i,int j){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()) return 0;
        if(vis[i][j]!=-1) return vis[i][j];
        int count = 0;
        vis[i][j]=board[i][j];
        count+=mark(board,vis,i+1,j+1)+mark(board,vis,i+1,j-1)+mark(board,vis,i-1,
        j-1)+mark(board,vis,i-1,j+1)+mark(board,vis,i+1,j)+mark(board,vis,i-1,j)
        +mark(board,vis,i,j+1)+mark(board,vis,i,j-1);
       

       if(board[i][j]){
        if(count<2 || count>3) board[i][j] = 0;

       } 
       else {
        if(count == 3) board[i][j]=1;
       }
       return vis[i][j];
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        mark(board,vis,0,0);

    }
};