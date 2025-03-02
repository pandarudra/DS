#define ll long long 
class Solution {
public:
    int reverse(int x) {
        bool sign = false ;
        ll y = x ;
        if(y < 0){
            sign = true ;
            y = abs(y) ;
        }

        ll rev = 0 ;
        while(y > 0){
            rev = rev * 10 + (y % 10) ;
            if(rev < INT_MIN || rev > INT_MAX)return 0 ;
            y /= 10 ; 
        }

        if(sign){
            rev = -rev ;
        }

        if(rev < INT_MIN || rev > INT_MAX)return 0 ;
       

        return (int)rev ;
    }
};