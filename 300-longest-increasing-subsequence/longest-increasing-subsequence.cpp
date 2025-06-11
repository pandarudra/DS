class Solution {
private:
    int f(int ind , int prev_ind , int N , vector<int>& nums , vector<vector<int>>& dp) {

        if(ind == N) return 0 ;
        if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1] ;

        // pick
        int pick = 0 ; 
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            pick = 1 + f(ind + 1 , ind , N , nums , dp) ;
        }

        // not pick
        int notpick = f(ind + 1 , prev_ind , N , nums , dp) ;

        return dp[ind][prev_ind + 1] = max(pick , notpick) ;

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size() ;

        vector<vector<int>> dp(N , vector<int>(N + 1 , -1)) ;

        return f(0 , -1 , N , nums , dp) ;
    }
};