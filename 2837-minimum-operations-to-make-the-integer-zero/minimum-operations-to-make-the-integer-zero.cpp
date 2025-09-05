using ll = long long ;
class Solution {
    ll bits(ll n) {
       return __builtin_popcountll(n) ;
    }
    ll f(ll n , ll m) {
        for(ll x = 1 ; x <= 60 ; x++) {
            ll beta = n - x * m ;
            if(beta < 0) break ;
            ll b = bits(beta) ;
            if(b <= x && x <= beta) return x ;
        }
        return -1 ;
    }
public:
    int makeTheIntegerZero(int num1, int num2) {
        return (int) f((ll) num1 , (ll) num2) ;
    }
};