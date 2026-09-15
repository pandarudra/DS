class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0 ;
        
        int i , si ;
        i = 0 , si = 1 ;

        while(--n) {
            int t = si ;
            si += i ;
            i = t ;
        }

        return si ;
    }
};