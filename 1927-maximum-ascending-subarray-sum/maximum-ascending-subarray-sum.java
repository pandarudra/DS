class Solution {
    public int maxAscendingSum(int[] nums) {
        int mx = 0 , s = nums[0] ;
        for(int i = 1 ; i < nums.length ; i++){
            if(nums[i] <= nums[i  - 1]){
                mx = Math.max(mx  , s) ;
                s = 0 ;
            }
            s += nums[i] ;
        }
        mx = Math.max(mx , s) ;
        return mx ;
    }
}