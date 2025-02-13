#define INF 0x3f3f3f3f
class Solution {
private:
    int drow[4] = {0 , 0 , -1 , 1} ;
    int dcol[4] = {-1 , 1 , 0 , 0} ;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq ;
        // wt , u --- v
        pq.push({0 , {0 , 0}}) ;
        int n = heights.size() ;
        int m = heights[0].size() ;
        vector<vector<int>> mndiff(n , vector<int>(m , INF)) ;
        mndiff[0][0] = 0 ;
        while(!pq.empty()){
            int wt = pq.top().first ;
            int u = pq.top().second.first ;
            int v = pq.top().second.second ;
            pq.pop() ;
            for(int i = 0 ; i < 4 ; i++){
                int row = u + drow[i] ;
                int col = v + dcol[i] ;
                if(row >= 0 && row < n && col >= 0 && col < m && max(abs(heights[row][col] - heights[u][v]) , wt) < mndiff[row][col]){
                    mndiff[row][col] =max(abs(heights[row][col] - heights[u][v]) , wt) ;
                    pq.push({mndiff[row][col] ,{row , col}}) ;
                }
            }
        }
        return mndiff[n - 1][m - 1] ;
    }
};