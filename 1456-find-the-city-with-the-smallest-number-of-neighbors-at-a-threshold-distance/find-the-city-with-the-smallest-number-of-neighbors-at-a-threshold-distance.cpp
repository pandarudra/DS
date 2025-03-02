#define umap unordered_map
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n , vector<int>(n , 1e9)) ;

        for(int i = 0 ; i < n ; i++){
            dist[i][i] = 0 ;
        }

        for(auto& it : edges){
            int from = it[0] ;
            int to = it[1] ;
            int wt = it[2] ;
            dist[from][to] = wt ;
            dist[to][from] = wt ;
        }

        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(dist[i][k] != 1e9 && dist[k][j] != 1e9)
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]) ;
                }
            }
        }

        vector<int> reach(n , 0) ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    reach[i]++ ;
                }
            }
        }

        int mx = -1 , mn = 1e9 ;

        for(int i = 0 ; i < n ; i++){
            if(reach[i] <= mn){
                mn = reach[i] ;
                mx = i ;
            }
        }
        return mx ;
    }
};