#define all(v) (v).begin(),(v).end()
class Solution {
    int f(vector<int>& coins , int amt , vector<int>& dp) {
        if(amt == 0) return 0 ;
        if(amt < 0) return INT_MAX ;
        if(dp[amt] != -1) return dp[amt] ;
        int mn = INT_MAX ;
        for(auto c : coins) {
            int left = f(coins , amt - c , dp) ;
            if(left != INT_MAX) mn = min(mn , 1 + left) ;
        }
        return dp[amt] = mn ;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        vector<int> dp(amount + 1 , -1) ;
        int r = f(coins , amount , dp) ;
        return r == INT_MAX ? -1 : r  ;
    }
};