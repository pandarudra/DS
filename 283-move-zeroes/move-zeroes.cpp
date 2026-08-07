class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size() ;
        int lo = 0 , hi = 0 ;
        while(hi < n && lo <= hi) {
            if(nums[hi] != 0) {
                swap(nums[lo] , nums[hi]) ;
                lo++ ;
            }
            hi++ ;
        }
    }
};