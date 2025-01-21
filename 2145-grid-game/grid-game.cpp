#define ll long long 
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size() ;
        vector<ll> suffix (n ,0) ;
        vector<ll> preffix (n ,0) ;
        ll mx = LLONG_MIN , mn = LLONG_MAX ;

        suffix[n - 1] = grid[0][n - 1] ;
        for(int i = n - 2 ; i > 0 ; i--){
            suffix[i] = suffix[i + 1] + grid[0][i] ;
        }

        preffix[0] = grid[1][0] ;
        for(int i = 1 ; i < n - 1 ; i++){
            preffix[i] = preffix[i - 1] + grid[1][i] ;
        }

        for(int i = 0 ; i < n ; i++){
            ll before = (i > 0) ? preffix[i - 1] : 0 ;
            ll after = (i < n - 1) ? suffix[i + 1] : 0 ;
            mx = max(after , before) ;
            mn = min(mn,mx) ;
        }

        return mn ;
    }
};