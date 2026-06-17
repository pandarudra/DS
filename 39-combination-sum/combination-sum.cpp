class Solution {
    void f(vector<int>& c , vector<vector<int>>& ans , vector<int>& v , int t , int i) {
        if(t < 0) return ;
        if(t == 0) {
            ans.push_back(v) ;
            return ;
        }
        if(i >= c.size()) {
            if(t == 0) {
                ans.push_back(v) ;
            }
            return ;
        }

        v.push_back(c[i]) ;
        f(c , ans , v , t - c[i] , i) ;
        v.pop_back() ;
        f(c , ans , v, t , i + 1) ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> v ;
        f(candidates , ans , v , target , 0) ;
        return ans ;
    }
};