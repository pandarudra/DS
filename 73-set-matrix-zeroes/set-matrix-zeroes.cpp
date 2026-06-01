class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() ;
        int n = matrix[0].size() ;

        bool rowhas0 = false , colhas0 = false ;
        
        // let's check if there is any 0 in 1st col
        for(int i = 0 ; i < m ; i++) {
            if(matrix[i][0] == 0) {
                colhas0 = true ;
                break ;
            }
        }

        // let's check if the first row contains any 0
        for(int j = 0 ; j < n ; j++) {
            if(matrix[0][j] == 0) {
                rowhas0 = true ;
                break ;
            }
        }

        for(int i = 1 ; i < m ; i++) {
            for(int j = 1 ; j < n ; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0 ;
                    matrix[0][j] = 0 ;
                }
            }
        }

        for(int i = 1 ; i < m ; i++) {
            for(int j = 1 ; j < n ; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0 ;
                }
            }
        }

        if(rowhas0) {
            for(int j = 0 ; j < n ; j++) {
                matrix[0][j] = 0 ;
            }
        }

        if(colhas0) {
            for(int i = 0 ; i < m ; i++) {
                matrix[i][0] = 0 ;
            }
        }
    }
};