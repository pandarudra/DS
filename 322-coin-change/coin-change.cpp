#define ipair pair<int , int>
#define umap unordered_map

class Solution {
private:
    map<ipair , int> dp ;
    int countMin(vector<int>& coins , int n , int amt){
        if(n < 0) {
            if(amt == 0) {
                return 0 ;
            }else{
                return 1e9 ;
            }
        }
        if(amt < 0) return 1e9 ;
        if(amt == 0) return 0 ;

        if(dp.count({n , amt})) return dp[{n , amt}] ;

        int pick = 1 + countMin(coins , n - 1 , amt - coins[n]) ;
        int notpick =  countMin(coins , n - 1 , amt) ;
        int picktwice = 1 + countMin(coins , n , amt - coins[n]) ;

        return dp[{n , amt}] = min({pick , notpick , picktwice}) ;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        int res = countMin(coins , n - 1 , amount) ;

        if(res >= 1e9) return -1 ;

        return res ;
    }
};