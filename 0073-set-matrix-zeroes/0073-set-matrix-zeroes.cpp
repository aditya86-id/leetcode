class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       set<int> rows, cols;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto it: rows)
        {
            for(int j=0;j<matrix[it].size();j++)
            {
                matrix[it][j]=0;
            }
        }
        for(auto it:cols){
            for(int j=0;j<matrix.size();j++)
            {
                matrix[j][it] = 0;
            }
        }
    }
};