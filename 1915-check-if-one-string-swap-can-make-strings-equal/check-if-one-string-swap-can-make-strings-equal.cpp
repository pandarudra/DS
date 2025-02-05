class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        if(s1.length() != s2.length()) return false ;

        int n = s1.length() ;
        int index = -1 , dist = 0 ;
        for(int i =  0 ; i < n ; i++){
           if(s1[i] != s2[i]){
              if(index != -1){
                swap(s1[index] , s1[i]) ;
                if(s1 != s2){
                    return false ;
                }else{
                    return true ;
                }
              }
              dist++ ;
              index = i ;
           }
        }
        if(dist && s1 != s2)return false ;
        return true ;
    }
};