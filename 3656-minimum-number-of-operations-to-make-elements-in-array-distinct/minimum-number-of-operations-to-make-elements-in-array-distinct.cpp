#define umap unordered_map
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size() ;
        umap<int , int> mp ;
        for(int i = n - 1 ; i >= 0  ; i--){
            if(mp[nums[i]]){
               return (int) ceil((1.0) * (i + 1) / 3) ; 
            }
            mp[nums[i]]++ ;
        }
        return 0 ;
    }
};