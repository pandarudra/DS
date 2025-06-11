class Solution {
private:
    int f(int i , int prev , int N , vector<int>& nums , vector<vector<int>>& dp) {
        if(i >= N) return 0 ;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1] ;

        int cur = i ;
        
         if(prev == -1 || nums[cur] > nums[prev]) {
            // take
            int take = 1 + f(i + 1 , cur , N , nums , dp) ;
            // not take
            int _take = f(i + 1 , prev , N , nums , dp) ;

            return dp[i][prev + 1] = max(take , _take) ;
        }

        return dp[i][prev + 1] = f(i + 1 , prev , N , nums , dp) ;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
         int N = nums.size() ;
         vector<vector<int>> dp(N , vector<int>(N + 1 , -1)) ;

         return f(0 , -1 , N , nums , dp) ;
    }
};