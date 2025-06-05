class Solution {
private:
    int f(string& s1 , string& s2 , int n , int m , vector<vector<int>>& dp) {
        if (m == 0 || n == 0) return 0 ;
        if(dp[n][m] != -1) {
            return dp[n][m] ;
        }

        // match 
        if(s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = 1 + f(s1 , s2 , n - 1 , m - 1 , dp) ;
        }
        // not match
        return dp[n][m] = max(f(s1 , s2 , n - 1 , m , dp) , f(s1 , s2 , n , m - 1 , dp)) ;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() ;
        int m = text2.size() ;
        
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1)) ;

        return f(text1 , text2 , n , m , dp) ;
    }
};