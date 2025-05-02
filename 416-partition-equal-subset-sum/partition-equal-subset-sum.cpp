#define all(v) (v).begin(),(v).end()
class Solution {
private:
    vector<vector<int>> dp ;
    bool f(vector<int>& nums , int n , int k){
        if(n < 0) return k == 0 ;
        if(k < 0) return false ;

        if(dp[n][k] != -1) return dp[n][k] ; 
        
        bool take = f(nums , n - 1 , k - nums[n]) ;
        bool not_take = f(nums , n - 1 , k) ;

        return dp[n][k] = take || not_take ;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int k = accumulate(all(nums) , 0) ;
        if(k % 2 != 0) return false ;
        dp.assign(n + 1 , vector<int>(k + 1 , -1)) ;
        k = k / 2 ; 
        return f(nums , n - 1 , k) ;
    }
};