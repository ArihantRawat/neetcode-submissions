class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Step 1: check first row
        for(int j = 0; j < m; j++) {
            if(matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Step 2: check first column
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Step 3: mark rows and columns
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 4: fill matrix using markers
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: handle first row
        if(firstRowZero) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: handle first column
        if(firstColZero) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};