#define all(v) (v).begin(),(v).end()
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s ;
        reverse(all(t)) ;

        int n = s.length() ;

        // LCS of string and reversed string == Longest Pallindromic Subsequence
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , - 1)) ;

        for(int i = 0 ; i <= n ; i++) {
            dp[i][0] = 0 ;
            dp[0][i] = 0 ;
        }

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1] ;
                }else{
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) ;
                }
            }
        }

        return dp[n][n] ;
    }
};