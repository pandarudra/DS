class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size() ;
        int N = matrix[0].size() ;
        vector<int> row(M , 0) , col(N , 0) ;
        for(int i = 0 ; i < M ; i++) {
            for(int j = 0 ; j < N ; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1 ;
                    col[j] = 1 ;
                }
            }
        }

        // set 0
        for(int i = 0 ; i < M ; i++) {
            for(int j = 0 ; j < N ; j++) {
                if(row[i] || col[j]) {
                    matrix[i][j] = 0 ;
                }
            }
        }
    }
};