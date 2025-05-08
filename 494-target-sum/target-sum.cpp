#define ipair pair<int , int>

class Solution {
private:
    map<ipair , int> dp ;
    int diffExp(vector<int>& nums , int n , int sum) {
        if(n < 0) return sum == 0 ;

        if(dp.count({n , sum})) return dp[{n , sum}] ;
        
        int pick = diffExp(nums , n - 1 , sum - nums[n]) ;
        int notpick = diffExp(nums , n - 1 , sum + nums[n]) ;

        return dp[{n , sum}] = pick + notpick ;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ;
        return diffExp(nums , n - 1 , target) ;
    }
};