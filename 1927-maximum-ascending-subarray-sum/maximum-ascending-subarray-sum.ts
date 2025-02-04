function maxAscendingSum(nums: number[]): number {
    let mx : number = 0 , s : number = nums[0] ;
    for(let i : number = 1 ; i < nums.length ; i++){
        if(nums[i] <= nums[i - 1]){
            mx = Math.max(mx , s) ;
            s = 0 ;
        }
        s += nums[i] ;
    }
    mx = Math.max(mx , s) ;
    return mx ;
};