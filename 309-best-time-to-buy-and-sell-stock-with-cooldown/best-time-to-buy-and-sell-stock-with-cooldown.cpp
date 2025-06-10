class Solution {
private:
    int f(int i , int canBuy , int N , vector<int>& p , vector<vector<int>>& dp) {
        if(i >= N) return 0 ;
        if(dp[i][canBuy] != -1) return dp[i][canBuy] ;

        if(canBuy) {
            int buy = -p[i] + f(i + 1 , 0 , N , p , dp) ;
            int notbuy = f(i + 1 , 1 , N , p , dp) ;
            return dp[i][canBuy] = max(buy , notbuy) ;
        }
        
        int sale = p[i] + f(i + 2 , 1 , N , p , dp) ;
        int notsale = f(i + 1 , 0 , N , p , dp) ;
        
        return dp[i][canBuy] = max(sale , notsale) ;
    }
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size() ;

        vector<vector<int>> dp(N , vector<int>(2 , -1)) ;

        return f(0 , 1 , N , prices , dp) ;
    }
};