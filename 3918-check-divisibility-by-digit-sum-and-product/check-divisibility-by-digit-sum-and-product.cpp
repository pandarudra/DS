class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 , product = 1 ;
        int ns = n ;
        while(ns > 0) {
            int unit = ns % 10 ;
            sum += unit ;
            product *= unit ;
            ns /= 10 ;
        }
        int total = sum + product ;
        if(total == 0) return false ;
        return n % total == 0 ;
    }
};