class Solution {
public:
    string convert(string s, int numRows) {
        int N = s.length() ;
        
        if(numRows == 1 || N <= numRows) return s ;

        vector<string> vstr(numRows) ;
        bool toDown = true ;

        int i = 0 , j = 0 ;
        while(j < N) {
            
            vstr[i].push_back(s[j]) ;

            j++ ;

            if(i == 0 && !toDown) {
                toDown = true ;
            }
            if(i == numRows - 1 && toDown) {
                toDown = false ;
            }

            if(toDown) i++ ;
            else i-- ;
        }

        string ans = "" ;

        for(auto& s : vstr) {
            ans += s ;
        }

        return ans ;
    }
};