class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> pre(n) , suff(n) ;
        pre[0] = nums[0] ;
        for(int i = 1 ; i < n ; i++) pre[i] = nums[i] * pre[i - 1] ;
        suff[n - 1] = nums[n - 1] ;
        for(int i = n - 2 ; i >= 0 ; i--) suff[i] = nums[i] * suff[i + 1] ;

        for(int i = 0 ; i < n ; i++) {
            int a = i > 0 ? pre[i - 1] : 1 ;
            int b = i < n - 1 ? suff[i + 1] : 1 ;
            nums[i] = a *  b ;
        }
        return nums ;
    }
};