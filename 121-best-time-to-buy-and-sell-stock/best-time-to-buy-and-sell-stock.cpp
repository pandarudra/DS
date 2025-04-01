class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        int mxp = 0 ;
        int mn = prices[0] ;
        for(int i = 1 ; i < n ; i++){
            mxp = max(mxp , prices[i] - mn) ;
            mn = min(mn , prices[i]) ; 
        }
        return mxp ;
    }
};