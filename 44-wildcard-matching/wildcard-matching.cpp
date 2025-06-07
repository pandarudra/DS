class Solution {
private:
    bool Ismatch(int i , int j , string& s , string& t , vector<vector<int>>& dp) {

        if(i < 0 && j < 0) return true ;
        if(i >= 0 && j < 0) return false ;
        if(i < 0 && j >= 0) {
            for(int it = j ; it >= 0 ; it--) {
                if(t[it] != '*') {
                    return false ;
                }
            }
            return true ;
        }

        if(dp[i][j] != -1) return dp[i][j] ;

        // match 
        if(s[i] == t[j] || t[j] == '?') {
            return  dp[i][j] = Ismatch(i - 1 , j - 1 , s , t , dp) ;
        }

        if(t[j] == '*') {
            bool shrinkWithoutStar = Ismatch(i , j - 1 , s , t , dp) ;
            bool shrinkWithStar = Ismatch(i - 1 , j , s , t , dp) ;
            return dp[i][j] = shrinkWithoutStar || shrinkWithStar ;
        } 

        // not match
        return dp[i][j] = false ;
        
    }
public:
    bool isMatch(string s, string p) {
        int n = s.length() ;
        int m = p.length() ;

        vector<vector<int>> dp(n , vector<int>(m , -1)) ;

        return Ismatch(n - 1 , m - 1 , s , p , dp) ;
    }
};