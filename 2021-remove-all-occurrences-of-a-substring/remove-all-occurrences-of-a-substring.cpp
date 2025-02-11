#define all(s) (s).begin(),(s).end()
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length() ;
        int pn = part.length() ;
        reverse(all(s)) ;
        reverse(all(part)) ;
        for(int i = n - 1 ; i  >= 0 ; i--){
            if(i + pn <= s.length() && s.substr(i , pn) == part){
                s.erase(i , pn) ;
            }
        }
        reverse(all(s)) ;
        return s ;
    }
};