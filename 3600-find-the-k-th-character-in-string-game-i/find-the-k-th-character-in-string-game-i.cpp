class Solution {
private:
    string S ;
    char getNext(char ch) {
        if(ch == 'z') return 'a' ;
        return ch + 1 ;
    }
    void build(string& s) {
        int N = s.length() ;
        for(int i = 0 ; i < N ; i++) {
            s.push_back(getNext(s[i])) ;
        }
    }
    void precompute() {
        for(int i = 1 ; i <= 9 ; i++) {
            build(S) ;
        }
    }
public:
    Solution() {
        S = "a" ;
        precompute() ;
    }
    char kthCharacter(int k) {
        return S[k - 1] ;
    }
};