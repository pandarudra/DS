#define pb push_back
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows) ;
        // (2,1) => (1,0) + (1,1)
        // (i,j) => (i - 1 , j - 1) + (i - 1 , j)
        // j == 0 or i - 1 => 1
        for(int i = 0 ; i < numRows ; i++) {
            for(int j = 0 ; j <= i ; j++) {
                if(j == 0 || j == i) {
                    v[i].pb(1) ;
                    continue ;
                } 
                v[i].pb(v[i - 1][j - 1] + v[i - 1][j]) ;
            }
        }
        return v ;
    }
};