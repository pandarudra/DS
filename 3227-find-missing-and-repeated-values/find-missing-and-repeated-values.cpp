#define uset unordered_set
#define all(v) (v).begin(),(v).end()
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        uset<int> s ;
        int n = grid.size() ;
        for(int i = 1 ; i <= n * n ; i++){
            s.insert(i) ;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(s.count(grid[i][j])){
                    s.erase(grid[i][j]) ;
                }else{
                    s.insert(grid[i][j]) ;
                }
            }
        }
        vector<int> res(all(s)) ;
        return res ;
    }
};