class Solution {
private:
        void bfs(vector<int>&vis,int node,vector<vector<int>>& adj,int v){
            vis[node]=1;
            queue<int>q;
            q.push(node);

            while(!q.empty()){
                int k=q.front();
                q.pop();
                for(int i=0;i<v;i++){
                    if(i!=k && !vis[i] && adj[k][i]){
                        vis[i] = 1;
                        q.push(i);
                    }
                }

            }

            return;
        }
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int>vis(v,0);
        int ans = 0;


        int i=0;
        while(i<v){
            if(!vis[i]){
                bfs(vis,i,adj,v);
                ans++;
            }

            i++;
        }
            return ans;
    }
};