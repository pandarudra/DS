class Solution {
private:
    bool canbeLNS(vector<int>& nums , int mid){
        int n = nums.size() ;
        if(n <= 1) return true ;
        for(int i = 0 ; i <= n - mid ; i++){
            int bitMask = 0 ;
            bool nice = true ;
            for(int j = i ; j < i + mid ; j++){
                if((bitMask & nums[j]) != 0){
                    nice = false ;
                    break ;
                }
                bitMask |= nums[j] ;
            }
            if(nice) return true ;
        }
        return false ;
    }
public:
    int longestNiceSubarray(vector<int>& nums) {
        int low = 1 , high = nums.size() ;
        while(low <= high){
            int mid = low + (high - low) / 2 ;
            if(canbeLNS(nums , mid)){
                low = mid + 1 ;
            }else{
                high = mid - 1 ;
            }
        }
        return high ;
    }
};