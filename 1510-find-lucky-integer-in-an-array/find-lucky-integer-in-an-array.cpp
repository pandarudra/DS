class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501 , 0) ;
        for(auto& a : arr) {
            freq[a]++ ;
        }

        for(int i = 500 ; i >= 1 ; i--) {
            if(i == freq[i]) return i ;
        }

        return -1 ;
    }
};