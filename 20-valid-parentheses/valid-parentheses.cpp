class Solution {
    char neg(char ch) {
        if(ch == '(') return ')' ;
        if(ch == '[') return ']' ;
        if(ch == '{') return '}' ;
        return 'n' ;
    }
public:
    bool isValid(string s) {
        stack<char> st ;
        for(char ch : s) {
            if(st.empty()) {
                st.push(ch) ;
                continue ;
            }
            char top = st.top() ;
            if(neg(top) == ch) st.pop() ;
            else st.push(ch) ;
        }
        return st.empty() ;
    }
};