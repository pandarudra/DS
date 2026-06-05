using ll = long long ;
class Solution {
    double power(double x, ll n) {
        if(n == 0) return 1.0 ;
        double half = power(x , n / 2) ;

        if(n & 1) return  x * half * half ;
        return half * half ;
    }
public:
    double myPow(double x, int n) {
        ll N = n ; 
        double v = power(x , abs(N)) ;
        if(n < 0) return 1.0 / v ;
        return v ;
    }
};