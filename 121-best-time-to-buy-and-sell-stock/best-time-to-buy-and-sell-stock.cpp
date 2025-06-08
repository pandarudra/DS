class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0 , buy = INT_MAX ;

        for(auto& p : prices) {
            buy = min(buy , p) ;
            mx = max(mx , p - buy) ;
        }

        return mx ;
    }
};