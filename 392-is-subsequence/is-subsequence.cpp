#define uset unordered_set
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0 , j = 0 ;
        int sn = s.length() , tn = t.length() ;
        while(i < sn && j < tn){
            if(s[i] == t[j]){
                i++ ;
                j++ ;
            }else{
                j++ ;
            }
        }
        return i >= sn ;
    }
};