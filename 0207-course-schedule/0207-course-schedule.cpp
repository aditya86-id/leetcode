class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, path))
                    return false; // cycle found
            }
        }

        return true;
    }

private:
    bool dfs(int node,
             const vector<vector<int>>& adj,
             vector<bool>& vis,
             vector<bool>& path) {

        vis[node] = true;
        path[node] = true;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, path))
                    return true;
            }
            else if (path[it]) {
                return true; // back edge -> cycle
            }
        }

        path[node] = false; // backtrack
        return false;
    }
};