#define all(v) (v).begin(),(v).end()
class Solution {
    void getmodify(string& s , char ch) {
        if(ch == '*') {
            s.pop_back() ;
        }else if(ch == '#') {
            s += s ;
        }else {
            reverse(all(s)) ;
        }
    }
public:
    string processStr(string s) {
        string r = "" ;
        for(auto ch : s) {
            if(ch != '*' && ch != '#' && ch != '%') {
                r.push_back(ch) ;
                continue ;
            }
            if(!r.empty()) getmodify(r , ch) ;
        }
        return r ;
    }
};