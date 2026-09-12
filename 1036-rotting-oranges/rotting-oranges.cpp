#define pii pair<int , int>
class Solution {
    int dr[4] = {-1 , 0 , 1 , 0} ;
    int dc[4] = {0 , 1 , 0 , -1} ;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;

        int fresh = 0 ;

        queue<pii> q ;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 2) {
                    q.push({i , j}) ;
                } else if(grid[i][j] == 1) {
                    fresh++ ;
                }
            }
        }

        int time = 0 ;
        

        while(!q.empty()) {
            

            int pass = q.size() ;

            while(pass--) {
            pii p = q.front() ;
            int r = p.first , c = p.second ;
            q.pop() ;

            for(int i = 0 ; i < 4 ; i++) {
                int nr = r + dr[i] ;
                int nc = c + dc[i] ;

                if(nr < 0 || nr >= m) continue ;
                if(nc < 0 || nc >= n) continue ;

                if(grid[nr][nc] == 1) {
                    q.push({nr , nc}) ;
                    grid[nr][nc] = 2 ;
                    fresh-- ;
                }
            }
            }
            time++ ;
        }

        if(fresh > 0) return -1 ;

        return max(0 , time - 1) ;
    }
};