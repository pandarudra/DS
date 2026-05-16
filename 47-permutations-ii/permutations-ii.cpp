#define pb push_back
class Solution {
    set<vector<int>> s ;
    void permute(vector<int>& nums, int i , vector<vector<int>>& v) {
        if(i >= nums.size()) {
            if(!s.count(nums)) v.pb(nums) ;
            s.insert(nums) ;
            return ;
        }
        for(int j = i ; j < nums.size() ; j++) {
            swap(nums[i] , nums[j]) ;
            permute(nums , i + 1 , v) ;
            swap(nums[i] , nums[j]) ;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v ;
        permute(nums , 0 , v) ;
        return v ;
    }
};