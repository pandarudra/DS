class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size() ;

        vector<vector<int>> dp(N + 1 , vector<int>(N + 1 , 0)) ;


        for(int ind = N - 1 ; ind >= 0 ; ind--) {
            for(int prev_ind = ind - 1 ; prev_ind >= -1 ; prev_ind--) {
                int pick = 0 ; 
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    pick = 1 + dp[ind + 1][ind + 1] ;
                }
                 // not pick
                 int notpick = dp[ind + 1][prev_ind + 1] ;
                 dp[ind][prev_ind + 1] = max(pick , notpick) ;
            }
        }
        return dp[0][-1 + 1] ;
    }
};