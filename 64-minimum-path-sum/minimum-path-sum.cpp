#define ipair pair<int , int>
class Solution {
private:
    map<ipair , int> memo ;
    int f(vector<vector<int>>& grid , int m , int n){
        if(m == 0 && n == 0) return grid[0][0] ;

        if(memo.count({m , n})) return memo[{m , n}] ;
        
        int left = (m - 1 >= 0) ? grid[m][n] + f(grid , m - 1 , n) : INT_MAX ;
        int right = (n - 1 >= 0) ? grid[m][n] + f(grid , m , n - 1) : INT_MAX ;
        
        return memo[{m , n}] = min(left , right) ;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        return f(grid , m - 1 , n - 1) ;        
    }
};