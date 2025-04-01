#define  ll long long
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        ll n = questions.size() ;
        vector<ll> dp(n + 1 , 0) ;
        for(ll i = n - 1 ; i >= 0 ; i--){
            ll pt = questions[i][0] ;
            ll bp = questions[i][1] ;

            ll take = pt + ((bp + i + 1) < n ? dp[bp + i + 1] : 0) ;
            ll not_take = dp[i + 1] ;

            dp[i] = max(take , not_take) ;
        }
        return dp[0] ;
    }
};