#define umap unordered_map
class Solution {
private:
    umap<int , int> memo ;
    int fn(vector<int>& nums , int n , int k){
        if(n == 0) return 0 ;
        if(memo.count(n)) return memo[n] ;
        int s = 0 ;
        for(int i = 2 ; i < k ; i++){
            int left = (n - i >= 0) ? fn(nums , n - i , k) + nums[n - i] : 0 ;
            s = max(s , left) ;
        }
        return memo[n] = s ;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        int left = fn(nums , n - 1 , n) ;
        left = (left > 0) ? left + nums[n - 1] : nums[n - 1] ;
        int right = (n - 2 >= 0) ? fn(nums , n - 2 , n) + nums[n - 2] : INT_MIN ;
        return max(left , right) ;
    }
};