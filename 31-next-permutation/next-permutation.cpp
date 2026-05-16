#define all(v) (v).begin(),(v).end()
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // break point
        int bp = -1 ;
        int n = nums.size() ;

        if(n == 1) return ;

        for(int i = n - 1 ; i > 0 ; i--) {
            if(nums[i] > nums[i - 1]) {
                bp = i - 1 ;
                break ;
            } 
        }

        if(bp == -1) {
            reverse(all(nums)) ;
            return ;
        }
        // nums[last_inc] <=> nums[lowest >= nums[last_inc]]

        int j = bp ;
        for(int i = n - 1 ; i > bp ; i--) {
            bool cond = j == bp ? nums[i] < INT_MAX : nums[i] < nums[j] ;
            if(nums[i] > nums[bp] && cond) {
                j = i ;
            }
        }
        swap(nums[j] , nums[bp]) ;
        // sort to make minimum the right side list of break point
        reverse(nums.begin() + bp + 1 , nums.end()) ;
    }
};