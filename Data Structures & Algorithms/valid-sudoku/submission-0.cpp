class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++) {
            unordered_set<char>s;
            for(int j=0;j<m;j++){
                if(board[i][j]!='.' && s.contains(board[i][j])) {
                    return false;
                }
                s.insert(board[i][j]);
            }
        }
        for(int j=0;j<m;j++) {
            unordered_set<char>s;
            for(int i=0;i<n;i++){
                if(board[i][j]!='.' && s.contains(board[i][j])) {
                    return false;
                }
                s.insert(board[i][j]);
            }
        }

        for (int x=0;x<n;x+=3) {
            for(int y=0;y<m;y+=3) {
              unordered_set<char>s;
                for(int i=x;i<x+3;i++){
                    for(int j=y;j<y+3;j++) {
                        if(board[i][j]!='.' && s.contains(board[i][j])) {
                            return false;
                        }
                        s.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};
