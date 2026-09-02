class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length() ;
        int left = 0 , right = 0 ;
        vector<int> freq(256 , 0) ;
        int mx = 0 ;
        while(right < n && left <= right) {
            while(freq[s[right]] > 0 && left <= right) {
                freq[s[left]]-- ;
                left++ ;
            }
            freq[s[right]]++ ;
            mx = max(mx , right - left + 1) ;
            right++ ;
        }
        return mx ;
    }
};