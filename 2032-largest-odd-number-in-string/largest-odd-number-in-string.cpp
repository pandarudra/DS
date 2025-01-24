class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.length() ;
        while(i >= 0){
            if(num[i] % 2 != 0){
                break ;
            }
            i-- ;
        }
        return (i < 0) ? "" : num.substr(0 , i + 1) ;
    }
};