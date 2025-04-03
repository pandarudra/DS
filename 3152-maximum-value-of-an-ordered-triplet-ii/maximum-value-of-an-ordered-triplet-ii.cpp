#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll mx = 0 ;
        int n = nums.size() ;
        vector<int> mxprefix(n) , mxsuffix(n) ;

        mxprefix[0] = nums[0] ;
        for(int i = 1 ; i < n ; i++){
            mxprefix[i] = max(mxprefix[i - 1] , nums[i]) ;
        }

        mxsuffix[n - 1] = nums[n - 1] ;
        for(int i = n - 2 ; i >= 0 ; i--){
            mxsuffix[i] = max(mxsuffix[i + 1] , nums[i]) ;
        }

        for(int i = 1 ; i < n - 1 ; i++){
            ll u = mxprefix[i - 1] ;
            ll v = nums[i] ;
            ll w = mxsuffix[i + 1] ;
            mx = max(mx , (u - v) * w) ;
        }

        return mx ;
    }
};