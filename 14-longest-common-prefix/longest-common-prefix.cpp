class Solution {
private:
    string LCP(const string& s , const string& t) {
        int N = s.length() ;
        int M = t.length() ;
        
        int i = 0 ;
        while(i < min(M , N)) {
            if(s[i] != t[i]) {
                break ;
            }
            i++ ;
        }

        return s.substr(0 , i) ;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size() ;
        string ans = strs[0] ;
        for(int i = 1 ; i < N ; i++) {
            ans = LCP(ans , strs[i]) ;
        }
        return ans ;
    }
};