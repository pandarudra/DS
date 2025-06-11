class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int N = nums.size() ;
         vector<vector<int>> dp(N + 1 , vector<int>(N + 1 , -1)) ;

         // i == N
         for(int i = 0 ; i <= N ; i++) dp[N][i] = 0 ;

         // current => i 
         // previous => j

         for(int i = N - 1 ; i >= 0 ; i--) {
            for(int j = i - 1 ; j >= -1 ; j--) {

                if(j == -1 || nums[i] > nums[j]) {
                    int take = 1 + dp[i + 1][i + 1] ;
                    int nottake = dp[i + 1][j + 1] ;

                    dp[i][j + 1] = max(take , nottake) ;
                } else {
                    dp[i][j + 1] = dp[i + 1][j + 1] ;
                }
            }
         }
         

         return dp[0][0] ;
    }
};