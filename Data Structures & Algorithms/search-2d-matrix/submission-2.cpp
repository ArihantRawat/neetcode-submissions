class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int r=m*n-1;
        while(l<=r) {
            int mid=l + (r - l) / 2;
            int x = mid/n;
            int y = mid%n;
            if(matrix[x][y] == target) {
                return true;
            } else if(matrix[x][y]>target) {
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        return false;
    }
};
