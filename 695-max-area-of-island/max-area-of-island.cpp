class Solution {
private:
    int drow[4] = {0 , 0 , -1 , 1} ;
    int dcol[4] = {-1 , 1 , 0 , 0} ;
    
    void bfs(int r , int c , vector<vector<int>>& grid , vector<vector<int>>& vis, int &mxArea){
        int  n = grid.size() ;
        int  m = grid[0].size() ;
        vis[r][c] = 1 ;
        queue<pair<int,int>> q ;
        q.push({r , c}) ;
        int area = 0 ;
        while(!q.empty()){
            int row = q.front().first ;
            int  col = q.front().second ;
            q.pop() ;
            area += grid[row][col] ;
            for(int i = 0 ; i < 4 ; i++){
                int nr = row + drow[i] ;
                int nc = col + dcol[i] ;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] > 0){
                    vis[nr][nc] = 1 ;
                    q.push({nr , nc}) ;
                }
            }
        }
        mxArea = max(mxArea , area) ;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> vis(n , vector<int>(m , 0)) ;
        int mxArea = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                    bfs(i , j , grid , vis , mxArea) ;
                }
            }
        }
        return mxArea ;
    }
};