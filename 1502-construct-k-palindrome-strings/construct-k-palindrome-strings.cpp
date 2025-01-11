class Solution {
public:
    bool canConstruct(string s, int k) {
        if( k > s.length() ) return false ; 
        unordered_map<char,int> mp ;
        for(auto &ch : s){
            mp[ch]++ ;
        }
        int cnt = 0 ;
        for(const auto& it : mp){
            cnt += (it.second % 2);
        }
        return cnt <= k ;
    }
};