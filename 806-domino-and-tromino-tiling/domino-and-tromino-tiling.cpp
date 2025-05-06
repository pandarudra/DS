#define umap unordered_map
class Solution {
    const int mod = 1e9 + 7 ;
    umap<int , int> dp ;
public:
    int numTilings(int n) {
        if(n == 0) return 0 ;
        if(n == 1) return 1 ;
        if(n == 2) return 2 ;
        if(n == 3) return 5 ;
        
        if(dp.count(n)) return dp[n] ;

        int left = 2 * (numTilings(n - 1) % mod) ;
        int right = numTilings(n - 3) % mod ;

        return dp[n] = (left % mod + right % mod) % mod ;
    }
};