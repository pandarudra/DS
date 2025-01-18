class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> costs(m , vector<int>(n , INT_MAX)) ;
        int dxy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}} ;
        
        deque<pair<int,int>> dq ;

        costs[0][0] = 0 ;
        dq.push_front({0,0}) ;

        while(!dq.empty()){
            auto [u , v] = dq.front() ;
            dq.pop_front() ;

            for(int d = 0 ; d < 4 ; d++){
                int dx = u + dxy[d][0] ;
                int dy = v + dxy[d][1] ;
                
                int cost = (grid[u][v] != (d + 1)) ? 1 : 0 ;

                if(dx >= 0 && dx < m && dy  >= 0 && dy < n && costs[u][v] + cost < costs[dx][dy]){
                    costs[dx][dy] = costs[u][v] + cost ;

                    if(cost == 1){
                        dq.push_back({dx,dy}) ;
                    }else{
                        dq.push_front({dx,dy}) ;
                    }
                }
            }
        }
        return costs[m - 1][n - 1] ;
    }
};