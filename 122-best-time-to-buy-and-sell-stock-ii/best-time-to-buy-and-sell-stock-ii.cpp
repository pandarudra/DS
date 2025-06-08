class Solution {
private:
    int f(int i , int canbuy , int N , vector<int>& p , vector<vector<int>>& dp) {

        if(i >= N) return 0 ;
        if(dp[i][canbuy] != -1) return dp[i][canbuy] ;

        if(canbuy) {
            int buy = -p[i] + f(i + 1 , 0 , N , p , dp) ;
            int notbuy = f(i + 1 , 1 , N , p , dp) ;
            return dp[i][canbuy] = max(buy , notbuy) ;
        }

        int sale = p[i] + f(i + 1 , 1 , N , p , dp) ;
        int notsale = f(i + 1 , 0 , N , p , dp) ;

        return dp[i][canbuy] = max(sale , notsale) ;
    }
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size() ;

        vector<vector<int>> dp(N , vector<int>(2 , -1)) ;

        return f(0 , 1 , N , prices , dp) ;
    }
};