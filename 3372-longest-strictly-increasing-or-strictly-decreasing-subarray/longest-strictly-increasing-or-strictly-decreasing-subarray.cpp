class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size() ;
        int mx = 1 ;

        for(int i = 0 ; i < n - 1 ; i++){
            int len = 1 ;
            for(int j = i + 1 ; j < n; j++){
                if(nums[j] <= nums[j - 1]){
                    break ;
                }
                len++ ;
            }
            mx = max(mx , len) ;
        }

        for(int i = 0 ; i < n - 1 ; i++){
            int len = 1 ;
            for(int j = i + 1 ; j < n; j++){
                if(nums[j] >= nums[j - 1]){
                    break ;
                }
                len++ ;
            }
            mx = max(mx , len) ;
        }
        return mx ;
    }
};