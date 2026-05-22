#define umap unordered_map
#define all(S) (S).begin(),(S).end()
#define pb push_back
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;
        sort(all(nums)) ;
        vector<vector<int>> ans ;
        for(int i = 0 ; i < n ; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue ;

            int sum = -nums[i] ;
            int left = i + 1 , right = n - 1 ;

            while(left < right) {
                int theta = nums[left] + nums[right] ;
                if(theta == sum) {
                    ans.pb({nums[i] , nums[left] , nums[right]}) ;
                    left++ ;
                    right-- ;

                    while(left < right &&  nums[left] == nums[left - 1]) left++ ;

                    while(left < right && nums[right] == nums[right + 1]) right-- ;
                    
                } else if(theta > sum) {
                    right-- ;
                } else {
                    left++ ;
                }
            }
        }
        return ans ;
    }
};