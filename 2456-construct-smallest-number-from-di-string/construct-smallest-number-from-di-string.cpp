class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length() ;
        string di = "" ;
        for(int i = 1 ; i <= n + 1 ; i++){
            di += to_string(i) ;
        }
        int s = 0 , e = 0 ;
        while(s <= e && e < n){
            while(s < n && pattern[s] != 'D') s++ ;
            e = s ;
            while(e < n && pattern[e] == 'D') e++ ;
            reverse(di.begin() + s , di.begin() + e + 1) ;
            s = e ;
        }
        return di ;
    }
};