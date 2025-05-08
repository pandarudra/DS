#define ipair pair<int , int>
class Solution {
private:
    map<ipair , int> dp ;
    int ways(vector<int>& coins , int n , int amt){
        if(amt < 0) return 0 ;
        if(amt == 0) return 1 ;
        if(n < 0) return amt == 0 ;

        if(dp.count({n , amt})) return  dp[{n , amt}] ;

        int notpick = ways(coins , n - 1 , amt) ;
        int apick = ways(coins , n , amt - coins[n]) ;

        return dp[{n , amt}] = notpick + apick ;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        return ways(coins , n - 1 , amount) ;
    }
};