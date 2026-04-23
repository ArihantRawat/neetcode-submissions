class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto& pre : prerequisites) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for (int i=0;i<numCourses;i++) {
            if (indegree[i]==0) {
                q.push(i);
            }
        }

        int finish = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            finish++;
            for(int x: adj[node]) {
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }

        return finish==numCourses;


    }
};
