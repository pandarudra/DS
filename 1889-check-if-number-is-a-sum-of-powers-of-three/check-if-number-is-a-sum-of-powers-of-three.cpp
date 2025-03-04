#define uset unordered_set
class Solution {
public:
    bool checkPowersOfThree(int n) {
        uset<int> s ;
        while(n > 0){
            int mxpow = 0 , pvalue = 1 ;

            while(pvalue * 3 <= n){
                pvalue *= 3 ;
                mxpow++ ;
            }

            if(s.count(mxpow)){
                return false ;
            }
            s.insert(mxpow) ;
            n -= pvalue ;
        }
        return true ;
    }
};