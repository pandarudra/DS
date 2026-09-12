class Solution {
    vector<int> dr = {-1 , 0 , 1 , 0} ;
    vector<int> dc = {0 , 1 , 0 , -1} ;
    
    int mark(int r , int c , vector<vector<int>>& vis , vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        if(r < 0 || r >= m) return 0 ;
        if(c < 0 || c >= n) return 0 ;

        if(vis[r][c]) return 0 ;
        if(grid[r][c] == 0) return 0 ;

        vis[r][c] = 1 ;
        int area = 1 ;

        for(int i = 0 ; i < 4 ; i++) {
            int nr = r + dr[i] ;
            int nc = c + dc[i] ;

            area += mark(nr , nc , vis , grid) ;
        }

        return area ;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> vis(m , vector<int>(n , 0)) ;
        int mx = 0 ;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    int area = mark(i , j , vis , grid) ;
                    mx = max(area , mx) ;
                }
            }
        }
        return mx ;
    }
};