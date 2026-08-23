class Solution {
    // true => Alice
    // false => bob
public:
    bool sumGame(string num) {
        int n = num.length() ;

        int hn = n / 2 ;
        int ls = 0 , rs = 0 , lq = 0 , rq = 0 ;
        
        for(int i = 0 ; i < hn ; i++) {
            if(num[i] == '?') lq++ ;
            else ls += (num[i] - '0') ;
            
            if(num[n - 1 - i] == '?') rq++ ;
            else rs += (num[n - 1 - i] - '0') ;
        }

        if((lq + rq) % 2 != 0) return true ;

        if(lq == rq) return ls != rs ;

        int sl = ls + 9 * (lq / 2) ;
        int sr = rs + 9 * (rq / 2) ;

        return sl != sr ;
    }
};