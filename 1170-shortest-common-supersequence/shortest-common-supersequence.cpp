#define all(v) (v).begin(),(v).end()
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
          int n = str1.length() ;
          int m = str2.length() ;

          // Let's compute LCS table 1st 
          vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1)) ;

          for(int i = 0 ; i <= n ; i++) dp[i][0] = 0 ;
          for(int j = 0 ; j <= m ; j++) dp[0][j] = 0 ;

          for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1] ;
                }else {
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) ;
                }
            }
          }

          // table backtrack

          string s = "" ;

          int i = n , j = m ;
          while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                s.push_back(str1[i - 1]) ;
                i-- ;
                j-- ;
                continue ;
            }
            int top = dp[i - 1][j] ;
            int left = dp[i][j - 1] ;

            char topChar = str2[j - 1] ;
            char leftChar = str1[i - 1] ;

            if(top > left) {
                s.push_back(leftChar) ;
                i-- ;
            }else {
                s.push_back(topChar) ;
                j-- ;
            }

          }

          while(i > 0) {
            s.push_back(str1[i - 1]) ;
            i-- ;
          }

          while(j > 0) {
            s.push_back(str2[j - 1]) ;
            j-- ;
          }

          reverse(all(s)) ;

          return s ;
    }
};