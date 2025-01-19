class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size() ;
        int m = heightMap[0].size() ;
        vector<vector<int>> vis(n,vector<int>(m,0)) ;
        priority_queue<Cell> pq ;

        for(int i = 0 ; i < n ; i++){
            pq.push(Cell(heightMap[i][0] , i , 0)) ;
            pq.push(Cell(heightMap[i][m - 1] , i , m - 1)) ;
            vis[i][0] = 1 ;
            vis[i][m - 1] = 1 ;
        }

        for(int i = 1 ; i < m - 1 ; i++){
            pq.push(Cell(heightMap[0][i],0,i)) ;
            pq.push(Cell(heightMap[n - 1][i],n - 1 , i)) ;
            vis[0][i] = 1 ;
            vis[n - 1][i] = 1 ;
        }

        int trappedWater = 0 ;

        int drow[4] = {0 , 0 , -1 , 1} ;
        int dcol[4] = {-1 , 1 , 0 , 0} ;

        while(!pq.empty()){
            int h  = pq.top().height ;
            int r = pq.top().row ;
            int c = pq.top().col ;
            pq.pop() ;

            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + drow[i] ;
                int ncol = c + dcol[i] ;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                    int ht = heightMap[nrow][ncol] ;
                    if(ht < h){
                        trappedWater += (h - ht) ;
                    }
                    pq.push(Cell(max(h,ht),nrow,ncol)) ;
                    vis[nrow][ncol] = 1 ;
                }
            }
        }

        return trappedWater ;
    }
    struct Cell{
        public:
        int height , row , col ;
        Cell(int h ,int r,int c) : height(h) , row(r) , col(c) {}

        bool operator<(const Cell& other) const{
            return height >= other.height ;
        }
    };
};