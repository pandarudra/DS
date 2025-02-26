class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size() ;

        int mxKadan = INT_MIN ;
        int s = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(s < 0){
                s = 0 ;
            }
            s += nums[i] ;
            mxKadan = max(mxKadan , s) ;
        }

        int mnKadan = INT_MAX ;
        s = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(s > 0){
                s = 0 ;
            }
            s += nums[i] ;
            mnKadan = min(mnKadan , s) ;
        }

        return max(abs(mxKadan) , abs(mnKadan)) ;
    }
};