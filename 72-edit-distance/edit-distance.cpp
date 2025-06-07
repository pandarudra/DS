class Solution {
private:
    int minOp(int i , int j , string& s , string& t , vector<vector<int>>& dp) {
        // s => t
        if(j < 0) return i + 1 ;
        if(i < 0) return j + 1 ;

        if(dp[i][j] != -1) return dp[i][j] ;

        // match
        if(s[i] == t[j]) return dp[i][j] = minOp(i - 1 , j - 1 , s , t , dp) ;

        // not match
        int insert = 1 + minOp(i , j - 1 , s , t , dp) ; // insert
        int deletee = 1 + minOp(i - 1 , j , s , t , dp) ; // delete
        int replace = 1 + minOp(i - 1 , j - 1 , s , t , dp) ; // replace

        return dp[i][j] = min({insert , deletee , replace}) ;
    }
public:
    int minDistance(string word1, string word2) {
         int n = word1.length() ;
         int m = word2.length() ;

         vector<vector<int>> dp(n , vector<int>(m , -1)) ;

         return minOp(n - 1 , m - 1 , word1 , word2 , dp) ;
    }
};