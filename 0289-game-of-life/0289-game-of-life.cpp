class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
    vector<pair<int,int>> temp{{1,0},{0,1},{-1,0},{0,-1},{-1,1},{1,-1},{-1,-1},{1,1}};
        
    int row=board.size(), col=board[0].size();
        
    vector<vector<int>>grid (row, vector<int>(col,0));
        
    queue<pair<int,int>> q;
        
    q.push({0,0});
        
    grid[0][0]=2;
    if(board[0][0]==1)
        grid[0][0]=1;
        
    while(!q.empty()){
        pair<int,int> state=q.front();
        q.pop();
        
        bool Alive=0;
        if(board[state.first][state.second]==1 )
            Alive=1;
        
        int death=0, live=0;
        for(int i=0;i<temp.size();i++){
            
            int r= state.first + temp[i].first;
            int c= state.second + temp[i].second;
            
            if(r<0 ||r>=row ||c<0 ||c>=col  )
                continue;
            
            else if(board[r][c]==0)
                death++;
            
            else
                live++;
            
          
            if(grid[r][c]!=1 && grid[r][c]!=2){
                
                if(board[r][c]==1)
                    grid[r][c]=1;
                else
                    grid[r][c]=2;
                q.push({r,c});
            }
                
        }
        
        if(Alive && (live<2  || live>3))
            grid[state.first][state.second]=2;
        else if(!Alive && live==3 )
            grid[state.first][state.second]=1;
        
    
    }
        
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==2)
                board[i][j]=0;
            
            else if(grid[i][j]==1)
                board[i][j]=1;
            
        }
    }
     
    return;   
        
    }
};