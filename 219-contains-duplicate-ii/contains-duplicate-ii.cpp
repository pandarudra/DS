#define umap unordered_map
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        umap<int , int> mp ;
        int n = nums.size() ;
        mp[nums[0]] = -1 ;
        for(int i = 1 ; i < n ; i++) {
            int v = mp[nums[i]] ;
            if(v != 0) {
                if(v == -1) {
                    if(i <= k) return true ;
                }else {
                    if(i - v <= k) return true ;
                }
            }
            mp[nums[i]] = i ;
        }
        return false ;
    }
};