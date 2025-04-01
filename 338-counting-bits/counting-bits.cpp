class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1) ;
        dp[0] = 0 ;
        for(int i = 1 ; i <= n ; i++){
            int h_bit = log2(i) ;
            int p = pow(2 , h_bit) ;
            dp[i] = 1 + dp[i - p] ; 
        }
        return dp ;
    }
};