#define all(v) (v).begin(),(v).end()
class Solution {
    void twoSum(vector<vector<int>>& ans , vector<int>& v , int left , int t) {
        int right = v.size() - 1 ;
        while(left < right) {
            int sum = v[left] + v[right] ;
            if(sum == t) {
                ans.push_back({-t , v[left] , v[right]}) ;
                left++ ;
                right-- ;
                 while(left < v.size() && v[left] == v[left - 1]) left++ ;
                 while(right >= 0 && v[right] == v[right + 1]) right-- ;
            }
            else if(sum < t) left++ ;
            else right-- ;
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;
        sort(all(nums)) ;

        if(nums[0] > 0) return {} ;

        vector<vector<int>> ans ;
        for(int i = 0 ; i < n ; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue ;

            int x = nums[i] ;
            twoSum(ans , nums , i + 1 , -x) ;
        }
        return ans ;
    }
};