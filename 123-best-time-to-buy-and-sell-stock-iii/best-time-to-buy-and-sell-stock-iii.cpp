class Solution {
private:
    int Transaction(vector<int>& p , int i , int canBuy , int limit , int N , vector<vector<vector<int>>>& dp) {
        if(i >= N || limit == 0) return 0 ;
        if(dp[i][canBuy][limit] != -1) return dp[i][canBuy][limit] ;

       
            if(canBuy) {
                int buy = -p[i] + Transaction(p , i + 1 , 0 , limit - 1 , N , dp) ;
                int notbuy = Transaction(p , i + 1 , 1 , limit , N , dp) ;
                return dp[i][canBuy][limit] = max(buy , notbuy) ;
            } else {
                int sell = p[i] + Transaction(p , i + 1 , 1 , limit - 1 , N , dp) ;
                int notsell = Transaction(p , i + 1 , 0 , limit , N , dp) ;
                return dp[i][canBuy][limit] = max(sell , notsell) ;
            }
        
        return 0 ;
    }
public:
    int maxProfit(vector<int>& prices) {
         int N = prices.size() ;

         int mxLimit = 2 ;

         vector<vector<vector<int>>> dp(N , vector<vector<int>>(2 , vector<int>(2 * mxLimit + 1 , -1))) ;

  
         return Transaction(prices , 0 , 1 , 4 , N , dp) ;

         
    }
};