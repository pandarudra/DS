#define ll long long
class Solution {
public:
    long long coloredCells(int n) {
        vector<ll> v(n + 1 , 0) ;
        v[1] = 1 ;
        for(ll i = 2 ; i <= n ; i++){
            v[i] = v[i - 1] + (4 * (i - 1)) ;
        }
        return v[n] ;
    }
};