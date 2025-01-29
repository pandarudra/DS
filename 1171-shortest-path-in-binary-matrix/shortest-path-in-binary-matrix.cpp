#define INF 0x3f3f3f3f
class Solution {
public:
    int drow[8] = {0 , 0 , -1 , 1 , -1 , 1 , -1 , 1} ;
    int dcol[8] = {-1 , 1 , 0 , 0 , -1 , 1 , 1 , -1} ;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;
        if(grid[0][0] || grid[n - 1][n - 1])return -1 ;
        vector<vector<int>> dist(n , vector<int>(n , INF)) ;
        queue<pair<int,int>> q ;
        q.push({0 , 0}) ;
        dist[0][0] = 1 ;
        while(!q.empty()){
            int u = q.front().first ;
            int v = q.front().second ;
            q.pop() ;
            
            for(int i = 0 ; i < 8 ; i++){
                int r = u + drow[i] ;
                int c = v + dcol[i] ;
                if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0 && dist[r][c] > dist[u][v] + 1){
                    dist[r][c] = dist[u][v] + 1 ;
                    q.push({r , c}) ;
                }
            }
        }
        return dist[n - 1][n - 1] < INF ? dist[n - 1][n - 1] : -1 ;
    }
};