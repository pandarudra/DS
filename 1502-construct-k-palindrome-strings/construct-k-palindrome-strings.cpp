class Solution {
public:
    bool canConstruct(string s, int k) {

        if(k > s.length()) return false ; 
        
        int freq[26] = {0};
        
        for(auto &ch : s){
            freq[ch - 'a']++ ;
        }
        int cnt = 0 ;
        for(const auto& it : freq){
            cnt += (it % 2);
        }
        return cnt <= k ;
    }
};