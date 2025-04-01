class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex + 1) ;
        dp[0] = {1} ;
        for(int i = 1 ; i <= rowIndex ; i++){
            dp[i].resize(i + 1) ;
            dp[i][0] = dp[i][i] = 1 ;
            for(int j = 1 ; j < i ; j++){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] ;
            }
        }
        return dp[rowIndex] ;
    }
};