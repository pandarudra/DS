class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mx = 0 , s = 0 ;
        s = nums[0] ;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] <= nums[i - 1]){
                mx = max(s , mx) ;
                s = 0 ;
            }
            s += nums[i] ;
        }
        mx = max(mx , s) ;
        return mx ;
    }
};