#define umap unordered_map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size() ;

        // x + y = target
        // y = target - x
        // if i have x then i just have to find target - x
        // for that i can keep a hashmap
        // then for each x i have to check if target - x exists

        umap<int , int> mp ;

        for(int i = 0 ; i < N ; i++) {
            mp[nums[i]] = i ;
        }


        for(int i = 0 ; i < N ; i++) {
            int x = nums[i] ;
            int t_x = target - x ;
            if(mp.count(t_x) && mp[t_x] != i) {
                return {mp[t_x] , i} ;
            }
        }

        return {-1 , -1} ;
    }
};