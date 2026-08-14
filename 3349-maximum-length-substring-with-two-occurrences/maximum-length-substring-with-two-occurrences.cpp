class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {0} ;
        int left = 0 , right = 0 ;
        int n = s.length() ;
        int mx = 0 ;
        while(right < n) {

            if(freq[s[right] - 'a'] == 2) {

                mx = max(right - left , mx) ;

                for(int i = left ; i <= right ; i++) {
                    freq[s[i] - 'a']-- ;
                    if(s[i] == s[right]) {
                        left = i + 1 ;
                        break ;
                    }
                }
                

            }

            freq[s[right] - 'a']++ ;
            right++ ;
        }


        mx = max(mx , n - left) ;
        
        return mx ;
    }
};