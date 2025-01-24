#define uset unordered_set
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0 ;
        int n = s.length() ;

        uset<int> st ;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                cnt++ ;
                if(cnt == 1){
                    st.insert(i) ;
                }
            }else{
                cnt-- ;
                if(cnt == 0){
                    st.insert(i) ;
                }
            }
        }
        string  res = "" ;
        for(int i = 0 ; i < n ; i++){
            if(!st.count(i)){
                res += s[i] ;
            }
        }
        return res ;
    }
};