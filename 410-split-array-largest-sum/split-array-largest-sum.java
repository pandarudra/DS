class Solution {
    public boolean cntK(int k , int  mid , int[] nums){
        int cnt = 1 , s = 0 ;

        for(int i = 0 ; i < nums.length ; i++){
            if(s + nums[i] > mid){
                cnt++ ;
                s = nums[i] ;
                if(cnt > k)return false ;
            }else{
                s += nums[i] ;
            }
        }
        return true ;
    }
    public int splitArray(int[] nums, int k) {

        int low = Arrays.stream(nums).max().getAsInt() ;
        int high = Arrays.stream(nums).sum() ;

        while(low <= high){
            int mid = low  + (high - low) / 2 ;

            if(cntK(k , mid , nums)){
                high = mid - 1 ;
            }else{
                low = mid + 1 ;
            }
        }
        return low ;
    }
}