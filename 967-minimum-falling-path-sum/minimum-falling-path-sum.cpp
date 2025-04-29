#define ll long long
#define ipair pair<int , int>
class Solution {
private:
    map<ipair , int> memo ;
    ll f(vector<vector<int>>& matrix , int m , int n , int k){
        if(m < 0 || n < 0 || n > k) return INT_MAX ;
        if(m == 0) return matrix[0][n] ;
        if(memo.count({m , n})) return memo[{m , n}] ;

        ll left = f(matrix , m - 1 , n - 1 , k) ;
        ll top = f(matrix , m - 1 , n , k) ;
        ll right = f(matrix , m - 1 , n + 1 , k) ;

        return memo[{m , n}] = matrix[m][n] + min({left , top , right}) ;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        ll mn = INT_MAX ;
        for(int i = 0 ; i < n ; i++){
            mn = min(mn , f(matrix , n - 1 , i , n - 1)) ;
        }
        return (int) mn ;
    }
};