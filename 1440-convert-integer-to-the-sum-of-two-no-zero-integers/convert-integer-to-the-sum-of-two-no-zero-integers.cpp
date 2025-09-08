class Solution {
    bool nonZero(int n) {
        while(n > 0) {
            if(n % 10 == 0) {
                return false ;
            }
            n /= 10 ;
        }
        return true ;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1 ; i < n ; i++) {
            if(nonZero(i) && nonZero(n - i)) {
                return {i , n - i} ;
            }
        }
        return {-1 , -1} ;
    }
};