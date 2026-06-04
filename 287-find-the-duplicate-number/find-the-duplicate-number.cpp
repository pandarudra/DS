class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ns = nums.size() ;
        int n = ns - 1 ;

        unordered_map<int , int> mp ;
        
        for(int i = 0 ; i < ns ; i++) {
            if(mp[nums[i]] > 0) return nums[i] ;
            mp[nums[i]]++ ;
        }
        return -1 ;
    }
};