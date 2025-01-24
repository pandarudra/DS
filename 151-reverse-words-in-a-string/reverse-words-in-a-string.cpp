class Solution {
public:
    string reverseWords(string s) {
        stack<string> st ;
        string res = "" ;



        string temp = "" ;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == ' '){
                if(temp != "" && temp != " ")st.push(temp) ;
                temp = "" ;
            }else{
                temp += s[i] ;
            }
        }

        if(temp != "")st.push(temp) ;

        while(!st.empty()){
            res += st.top() ;
            st.pop() ;
            while(!st.empty() && st.top() == " ")st.pop() ;
            if(!st.empty()){
                res += " " ;
            }
        }
        return res ;
    }
};