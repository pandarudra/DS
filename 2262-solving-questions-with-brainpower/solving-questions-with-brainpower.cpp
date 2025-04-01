#define  ll long long
class Solution {
private:
    ll pnp(vector<vector<int>>& q , ll i , vector<ll>& dp , ll n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i] ;

        ll take = q[i][0] + pnp(q , i + q[i][1] + 1 , dp ,  n) ;
        ll not_take = pnp(q , i + 1 , dp ,  n) ;

        return dp[i] = max(take , not_take) ;
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        ll n = questions.size() ;
        vector<ll> dp(n , -1) ;
        return pnp(questions , 0 , dp , n) ;
    }
};