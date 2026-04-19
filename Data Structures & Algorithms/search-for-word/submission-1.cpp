class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool present = false;
        string res = "";
        vector<vector<bool>> mapp;
        for(int i=0;i<board.size();i++) {
            vector<bool>x;
            for(int j=0;j<board[i].size();j++){
                x.push_back(false);
            }
            mapp.push_back(x);
        }
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++){
                check(board,word,i,j,mapp,res, present);
            }
        }
        
        return present;
    }

    void check(vector<vector<char>>& board, string word, int x, int y,vector<vector<bool>> mapp, string res, bool& present) {
        if(present) {
            return;
        }
        if(word==res || word==res+board[x][y]) {
            present = true;
            return;
        }
        int n=board.size();
        int m=board[0].size();
        mapp[x][y] = true;
        if (x<n-1 && !mapp[x+1][y]) {
            check(board,word,x+1,y,mapp,res+board[x][y], present);
        }
        if (x>0 && !mapp[x-1][y]) {
            check(board,word,x-1,y,mapp,res+board[x][y], present);
        }
        if(y<m-1 && !mapp[x][y+1]) {
            check(board,word,x,y+1,mapp,res+board[x][y], present);
        }
        if(y>0 && !mapp[x][y-1]) {
            check(board,word,x,y-1,mapp,res+board[x][y], present);
        }

        mapp[x][y] = false;
        
    }
};
