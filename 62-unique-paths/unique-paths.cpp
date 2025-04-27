class Solution {
private:
    vector<vector<int>> memo ;
    int f(int m , int n){
        if(m == 0 && n == 0) return 1 ;
        if(m < 0 || n < 0) return 0 ;

        if(memo[m][n] != -1) return memo[m][n] ;

        int left = f(m - 1 , n) ;
        int right = f(m , n - 1) ;
        return memo[m][n] = left + right ;
    }
public:
    int uniquePaths(int m, int n) {
        memo.assign(m , vector<int>(n , -1)) ;
        return f(m - 1 , n - 1) ;
    }
};