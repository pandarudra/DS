#define umap unordered_map
class Solution {
    void f(vector<int>& nums ,umap<int ,bool>& mp , vector<vector<int>>& ans , vector<int>& ds) {
       if(ds.size() == nums.size()) {
        ans.push_back(ds) ;
        return ;
       }
       for(int i = 0 ; i < nums.size() ; i++) {
         if(mp[i]) continue ;
         mp[i] = true ;
         ds.push_back(nums[i]) ;
         f(nums , mp , ans , ds) ;
         ds.pop_back() ;
         mp[i] = false ;
       }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        umap<int , bool> mp ;
        vector<int> ds ;
        f(nums , mp , ans , ds) ;
        return ans ;
    }
};