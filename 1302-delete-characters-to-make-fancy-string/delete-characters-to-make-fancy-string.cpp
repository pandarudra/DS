class Solution {
public:
    string makeFancyString(string s) {
        string ans = "" ;
        int N = s.length() ;
        int i = 1 ;
        int x = 1 ;
        ans += s[0] ;
        while(i < N) {
            if(s[i] == s[i - 1]) {
                x++ ;
            } else {
                x = 1 ;
            }
            if(x < 3) {
                ans += s[i] ;
            }
            i++ ;
        }

        return ans ;
    }
};