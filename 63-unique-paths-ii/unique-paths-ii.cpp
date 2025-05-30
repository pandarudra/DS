#define umap unordered_map
#define ipair pair<int , int>

struct hash_pair {
    size_t operator()(const ipair& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
    umap<ipair , int , hash_pair> memo ;
    int dp(vector<vector<int>>& OG , int m , int n){

        if(m < 0 || n < 0) return 0 ;
        if(OG[m][n] == 1) return memo[{m , n}] = 0 ;
        if(m == 0 && n == 0) return 1 ;


        if(memo.count({m , n})) return memo[{m , n}] ;

        int left = dp(OG , m - 1 , n) ;
        int right = dp(OG , m , n - 1) ;

        return memo[{m , n}] = left + right ;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() ;
        int n = obstacleGrid[0].size() ;
        
        return dp(obstacleGrid , m - 1 , n - 1) ;
    }
};