#define ll long long
class Solution {
private:
    int ncr(int n , int i){
        ll res = 1 ;
        for(int j = 1 ; j <= i ; j++){
            res *= (n--) ;
            res /= j ;
        }
        return (int) res ;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex + 1 , -1) ;
        dp[0] = dp[rowIndex] = 1 ;
        for(int i = 1 ; i < rowIndex ; i++){
            if(dp[rowIndex - i] != -1){
                dp[i] = dp[rowIndex - i] ;
            }else{
                dp[i] = ncr(rowIndex , i) ;
            }
        }
        return dp ;
    }
};