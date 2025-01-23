class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<int> rowVis(n , 0) , colVis(m , 0) ;
        vector<int> rowCnt(n , 0) , colCnt(m , 0) ;

        int cnt = 0 ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if (grid[i][j] == 1) {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }

        for(int  i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && (rowCnt[i] > 1 || colCnt[j] > 1)){
                    cnt++ ;
                }
            }
        }
        return cnt ;
    }
};