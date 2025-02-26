class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size() ;

        int mxKadan = INT_MIN ;
        int mnKadan = INT_MAX ;
        int s1 = 0 , s2 = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(s1 < 0){
                s1 = 0 ;
            }
            if(s2 > 0){
                s2 = 0 ;
            }
            s1 += nums[i] ;
            mxKadan = max(mxKadan , s1) ;

            s2 += nums[i] ;
            mnKadan = min(mnKadan , s2) ;
        }


        return max(abs(mxKadan) , abs(mnKadan)) ;
    }
};