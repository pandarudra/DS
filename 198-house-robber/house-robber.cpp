#define umap unordered_map
class Solution {
private:
    umap<int , int> memo ;
    int dp(vector<int>& nums , int n , int k){
        if(n == 0){
            return 0 ;
        }
        if(memo.count(n)){
            return memo[n] ;
        }
        int mx = 0 ;
        for(int i = 2 ; i < k ; i++){
            int left = (n - i >= 0) ? dp(nums , n - i , k) + nums[n - i] : 0 ;
            mx = max(mx , left) ;
        }
        return memo[n] = mx ;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        int left = dp(nums , n - 1 , n) + nums[n - 1];
        int right = (n - 2 >= 0) ? dp(nums , n - 2 , n) + nums[n - 2] : INT_MIN ;
        return max(left , right) ;
    }
};