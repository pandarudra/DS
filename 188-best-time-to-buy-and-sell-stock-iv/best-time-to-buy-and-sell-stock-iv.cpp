class Solution {
private:
    int f(int i , int canBuy , int limit , int N , vector<int>& p , vector<vector<vector<int>>>& dp) {
        if(i >= N || limit == 0) {
            return 0 ;
        }
        if(dp[i][canBuy][limit] != -1) return dp[i][canBuy][limit] ;

        if(canBuy) {
            int buy = -p[i] + f(i + 1 , 0 , limit - 1 , N , p , dp) ;
            int notbuy = f(i + 1 , 1 , limit , N , p , dp) ;
            return dp[i][canBuy][limit] = max(buy , notbuy) ;
        }
        int sell = p[i] + f(i + 1 , 1 , limit - 1 , N , p , dp) ;
        int notsell = f(i + 1 , 0 , limit , N , p , dp) ;

        return dp[i][canBuy][limit] = max(sell , notsell) ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int N = prices.size() ;
        int sz = 2 * k + 1 ;

        vector<vector<vector<int>>> dp(N , vector<vector<int>>(2 , vector<int>(sz , -1))) ;
        return f(0 , 1 , sz - 1 , N , prices , dp) ;
    }
};