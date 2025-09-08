class Solution {
    bool nonZero(int n , int i) {
        string s = to_string(i) ;
        string t = to_string(n - i) ;

        string st = s + t ;

        return st.find('0') == string::npos ;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1 ; i < n ; i++) {
            if(nonZero(n , i)) {
                return {i , n - i} ;
            }
        }
        return {-1 , -1} ;
    }
};