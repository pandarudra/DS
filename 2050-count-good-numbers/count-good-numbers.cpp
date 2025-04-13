#define ll long long 
class Solution {
private:
    const ll MOD = 1e9 + 7 ;
    ll mpow(ll x , ll n){
        if(n == 0){
            return 1LL ;
        }
        ll half = mpow(x , n / 2)  ;
        if(n & 1){
            return (x * half * half) % MOD ;
        }
        return (half * half) % MOD ;
    }
public:
    int countGoodNumbers(long long n) {
        ll ne = ceil((1.0) * n / 2) ;
        ll no = n / 2 ;
        ll res = mpow(5 , ne) ;
        res = (res * mpow(4 , no)) % MOD ;
        return res ;
    }
};