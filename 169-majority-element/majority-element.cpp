class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int , int> mp ;
        for(auto x : nums) mp[x]++ ;
        for(auto [u , v] : mp) if(v > n / 2) return u ;
        return -1 ;
    }
};