class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for (int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n,0);

        int res = 0;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                res++;
                dfs(adj,visited,i);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>adj, vector<int>& visited, int x) {
        if(!visited[x]) {
            visited[x] = 1;
        }
        for (int i=0;i<adj[x].size();i++) {
            if(!visited[adj[x][i]]) {
                dfs(adj,visited,adj[x][i]);
            }
        }
    }
};
