class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length() ;
        vector<int> res ;
        for(int i = 0 ; i <= n ; i++){
            res.push_back(i) ;
        }
        int start = 0 , end = 0 ;
        while(start <= end && end < n){
            while(start < n && s[start] != 'D')start++ ;
            end = start ;
            while(end < n && s[end] == 'D')end++ ;
            end-- ;
            if(end >= n || start > end)break ;
            reverse(res.begin() + start , res.begin() + end + 2) ;
            end++ ;
            start = end ;
        }
        return res ;
    }
};