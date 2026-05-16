#define pb push_back
class Solution {
    void getAllPermutes(vector<int>& nums , int i , vector<vector<int>>& v) {
        if(i >= nums.size()) {
            v.pb(nums) ;
            return ;
        }
        for(int j = i ; j < nums.size() ; j++) {
            swap(nums[i] , nums[j]) ;
            getAllPermutes(nums , i + 1 , v) ;
            swap(nums[i] , nums[j]) ;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v ;
        getAllPermutes(nums , 0 , v) ;
        return v ;
    }
};