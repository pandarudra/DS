#define all(v) (v).begin(),(v).end()
#define uset unordered_set

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(all(nums));
        int n = nums.size() ;
        
        vector<vector<int>> sol ;
        for(int i = 0 ; i < n ; i++){

            if(i > 0 && nums[i] == nums[i-1])continue ;

            int a = -nums[i] ;
            int low = i + 1 , high = n - 1 ;
            while(low < high){
                if(nums[low] + nums[high] == a){
                    vector<int> v = {nums[i],nums[low],nums[high]} ;
                    sol.push_back(v) ;

                    while(low < high && nums[low] == nums[low + 1])low ++ ;
                    while(low < high  && nums[high] == nums[high - 1])high -- ;
                    low ++ ;
                    high -- ;
                }else if(nums[low] + nums[high] > a){
                    high -- ;
                }else if(nums[low] + nums[high] < a){
                    low ++ ;
                }
                
            }
        }
        return sol ;
    }
};