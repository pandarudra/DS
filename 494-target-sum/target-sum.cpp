class Solution {
private:
    int diffExp(vector<int>& nums , int n , int sum) {
        if(n < 0) return sum == 0 ;

        int pick = diffExp(nums , n - 1 , sum - nums[n]) ;
        int notpick = diffExp(nums , n - 1 , sum + nums[n]) ;

        return pick + notpick ;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ;
        return diffExp(nums , n - 1 , target) ;
    }
};