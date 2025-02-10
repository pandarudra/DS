class Solution {
public:
    string clearDigits(string s) {
        string res = "" ;
        int digits = 0 ;
        int n = s.length() ;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(s[i] >= '0' && s[i] <= '9'){
                digits++ ;
                s[i] = '#' ;
            }else if(digits > 0){
                digits-- ;
                s[i] = '#' ;
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(s[i] != '#'){
                res += s[i] ;
            }
        }
        return res ;
    }
};