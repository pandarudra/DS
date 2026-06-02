class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 , buy = prices[0] ;
        int n = prices.size() ;
        
        for(int i = 0 ; i < n ; i++) {
            int sell = prices[i] ;
            if(sell > buy) {
                profit = max(profit , sell - buy) ;
            } else if(sell < buy) {
                buy = sell ;
            }
        }
        return profit ;
    }
};