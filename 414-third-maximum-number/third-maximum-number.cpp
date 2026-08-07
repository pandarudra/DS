class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 1) return nums[0] ;
        if(n == 2) return max(nums[0] , nums[1]) ;
        long long mx , smx , tmx ;
        mx = LLONG_MIN , smx = mx , tmx = mx ;
        for(int x : nums) {
            if(mx < x) {
                tmx = smx ;
                smx = mx ;
                mx = x ;
                continue ;
            }
            if(x < mx) {
                if(x > smx) {
                    tmx = smx ;
                    smx = x ;
                }
                if(x < smx) {
                    if(x > tmx) {
                        tmx = x ;
                    }
                }
            }
        }
        if(tmx == LLONG_MIN) return mx ;
        return (int)tmx ;
    }
};