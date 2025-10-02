#define pb push_back
#define pob pop_back
class Solution {
  private:
    void f(int n , int k , int s , vector<int>& ds , vector<vector<int>>& ans) {
        if(n == 0 && k == 0) {
            ans.pb(ds) ;
            return ;
        }
        if(n == 0 && k != 0) return ;
        if(k == 0 && n != 0) return ;
        if(n < 0) return ;
        if(s < 0) return ;
        
        ds.pb(s) ;
        f(n - s , k - 1 , s - 1 , ds , ans) ;
        ds.pob() ;
        f(n , k , s - 1 , ds , ans) ;
    }
  public:
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans ;
        vector<int> ds ;
        f(n , k , 9 , ds , ans) ;
        return ans ;
    }
};