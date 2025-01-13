class Solution {
public:
    int minimumLength(string s) {
        int cnt   = 0 ;
        int freq[26] = {0} ;
        for(auto &ch : s){
            freq[ch - 'a']++ ;
        }
        for(auto &it  : freq){
            if(it != 0){
                if(it & 1){
                    cnt += 1 ;
                }else{
                    cnt += 2 ;
                }
            }
        }
        return cnt ; 
    }
};