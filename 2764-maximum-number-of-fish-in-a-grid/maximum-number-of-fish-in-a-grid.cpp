class Solution {
private:
   int drow[4] = {0 , 0 , -1 , 1} ;
   int dcol[4] = {-1 , 1 , 0 , 0} ;
   void bfs(int r , int c , vector<vector<int>>& grid , int &cnt , vector<vector<int>>& vis){
       int n = grid.size() ;
       int m = grid[0].size() ;
       queue<pair<int,int>> q ;
       q.push({r  , c}) ;
       vis[r][c] = 1 ;
       int ct = 0  ;
       while(!q.empty()){
          int row = q.front().first ;
          int col = q.front().second ;
          q.pop() ;
          ct += grid[row][col] ;
          for(int i = 0 ; i < 4 ; i++){
              int nr = row + drow[i] ;
              int nc = col + dcol[i] ;
              if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] > 0){
                vis[nr][nc] = 1 ;
                q.push({nr , nc}) ;
              }
          }
       }
       cnt = max(cnt , ct) ;
   }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> vis(n , vector<int>(m , 0)) ;
        int cnt = 0  ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                    bfs(i , j , grid , cnt , vis) ;
                }
            }
        }
        return cnt ;
    }
};