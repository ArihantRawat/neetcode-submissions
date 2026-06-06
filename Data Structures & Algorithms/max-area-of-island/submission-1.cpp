class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] ==1) {
                    int k = 1;
                    grid[i][j]=2;
                    dfs(i,j,n,m,grid,k);
                    res= max(res,k);
                }
            }
        }
        return res;
    }

    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int &k){
        if(i>0 && grid[i-1][j]==1) {   
            k+=1;
            grid[i-1][j]=2;
            dfs(i-1,j,n,m,grid,k);
        }
        if(j>0 && grid[i][j-1]==1) {   
            k+=1;
            grid[i][j-1]=2;
            dfs(i,j-1,n,m,grid,k);
        }
        if(i<n-1 && grid[i+1][j]==1) {   
            k+=1;
            grid[i+1][j]=2;
            dfs(i+1,j,n,m,grid,k);
        }
        if(j<m-1 && grid[i][j+1]==1) {   
            k+=1;
            grid[i][j+1]=2;
            dfs(i,j+1,n,m,grid,k);
        }
    }
};
