#define all(vect) begin(vect),end(vect)
class Solution {
    void f(vector<int>& a , vector<int>& ds , int i , int t , vector<vector<int>>& ans) {
        int n = a.size() ;
        if(i >= n) {
            if(t == 0) {
                ans.push_back(ds) ;
            }
            return ;
        }

        if(t == 0) {
            ans.push_back(ds) ;
            return ;
        }

        if(t < 0) return ;

        while(i > 0 && a[i] == a[i - 1]) i++ ;

        // take 
        ds.push_back(a[i]) ;
        f(a , ds , i , t - a[i] , ans) ;
        ds.pop_back() ;


        // not take 
        f(a , ds , i + 1 , t , ans) ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size() ;
        sort(all(candidates)) ;
        vector<vector<int>> ans ;
        vector<int> ds ;
        f(candidates , ds , 0 , target , ans) ;
        return ans ;
    }
};