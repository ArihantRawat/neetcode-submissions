class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++) {
            if(board[i][0]=='O') {
                q.push({i,0});
            }
            if(board[i][m-1]=='O') {
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++) {
            if(board[0][i]=='O') {
                q.push({0,i});
            }
            if(board[n-1][i]=='O') {
                q.push({n-1,i});
            }
        }
        while (!q.empty()) {
            int st=q.size();
            for (int p=0;p<st;p++) {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                board[x][y]='1';
                if(x-1>0 && board[x-1][y]=='O') {
                    q.push({x-1,y});
                }
                if(x+1<n && board[x+1][y]=='O') {
                    q.push({x+1,y});
                }
                if(y-1>0 && board[x][y-1]=='O') {
                    q.push({x,y-1});
                }
                if(y+1<m && board[x][y+1]=='O') {
                    q.push({x,y+1});
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='O') {
                    board[i][j]='X';
                } else if(board[i][j]=='1') {
                    board[i][j]='O';
                }
            }
        }
    }
};
