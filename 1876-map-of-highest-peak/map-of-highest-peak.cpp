class Solution {
public:
    int drow[4] = {0 , 0 , -1 , 1} ;
    int dcol[4] = {-1 , 1 , 0 , 0} ;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size() ;
        int m = isWater[0].size() ;
        vector<vector<int>> vis(n,vector<int>(m , 0)) , height(n,vector<int>(m , 0)) ;

        queue<pair<int,int>> q ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(isWater[i][j] == 1){
                    vis[i][j] = 1 ;
                    q.push({i , j}) ;
                }
            }
        }


        while(!q.empty()){
            int row = q.front().first ;
            int col = q.front().second ;
            q.pop() ;
            for(int i = 0 ; i < 4 ; i++){
                int r = row + drow[i] ;
                int c = col + dcol[i] ;
                if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]){
                    vis[r][c] = 1 ;
                    height[r][c] = 1 + height[row][col] ;
                    q.push({r,c}) ;
                }
            }
        }
        return height ;
    }
};