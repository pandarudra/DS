int maxAscendingSum(int* nums, int numsSize) {
    int mx = 0 , s = nums[0] ;
    for(int i = 1 ; i < numsSize ; i++){
        if(nums[i] <= nums[i - 1]){
            mx = fmax(mx , s) ;
            s = 0 ;
        }
        s += nums[i] ;
    }
    mx  = fmax(mx , s) ;
    return mx ;
}
