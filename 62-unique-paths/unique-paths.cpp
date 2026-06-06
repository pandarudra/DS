class Solution {
public:
    int f(int m, int n , vector<vector<int>>& dp) {
        if(m < 1 || n < 1) return 0 ;
        if(m == 1 && n == 1) return 1 ;
        if(dp[m - 1][n - 1]) return dp[m - 1][n - 1] ;
        
        int left = f(m , n - 1 , dp) ;
        int top = f(m - 1 , n , dp) ;
        return dp[m - 1][n - 1] = left + top ;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n)) ;
        return f(m , n , dp) ;
    }
};