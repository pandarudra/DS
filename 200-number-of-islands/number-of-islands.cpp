class Solution {
    void dfs(int i , int j , vector<vector<char>>& grid , vector<vector<int>>& vis) {

        int m = grid.size() , n = grid[0].size() ;
        
        if(i >= m || j >= n) return ;
        if(vis[i][j]) return ;
        if(grid[i][j] == '0') return ;

        vis[i][j] = 1 ;

        // up
        if(i - 1 >= 0) dfs(i - 1 , j , grid , vis) ;
        // down
        if(i + 1 < m) dfs(i + 1 , j , grid , vis) ; 
        // left 
        if(j - 1 >= 0) dfs(i , j - 1 , grid , vis) ;
        // right
        if(j + 1 < n) dfs(i , j + 1 , grid , vis) ;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        int cnt = 0 ;
        vector<vector<int>> vis(m , vector<int>(n , 0)) ;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    cnt++ ;
                    dfs(i , j , grid , vis) ;
                }
            }
        }
        return cnt ;
    }
};