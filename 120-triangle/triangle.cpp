#define ll long  long
#define ipair pair<int , int>
class Solution {
private:
    map<ipair , int> memo ;
    ll f(vector<vector<int>>& t , int m , int n){
        if(m < 0 || n < 0 || n > m) return INT_MAX ;

        if(m == 0 && n == 0) return t[0][0] ;

        if(memo.count({m , n})) return memo[{m , n}] ;

        ll top = (ll) f(t , m - 1 , n)  ;
        ll right = (ll) f(t , m - 1 , n - 1)  ;

        return memo[{m , n}] = t[m][n] + min(top , right) ;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ;
        ll mn = INT_MAX ;
        for(int i = 0 ; i < triangle[n - 1].size() ; i++){
            mn = min(mn , f(triangle , n - 1 , i)) ;
        }
        return mn ;
    }
};