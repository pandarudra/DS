class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length() ;
        int m = word2.length() ;

        // 1st I have to compute Length(LCS of word1 & word2) => x
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1)) ;

        for(int i = 0 ; i <= n ; i++) dp[i][0] = 0 ;
        for(int j = 0 ; j <= m ; j++) dp[0][j] = 0 ;

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1] ;
                }else {
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) ;
                }
            }
        }

        // x = dp[n][m]
        // no. of operations = (n - x) + (m - x)
        return (n - dp[n][m]) + (m - dp[n][m]) ;
    }
};