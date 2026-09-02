class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() ;
        int low = 0 , high = n - 1 ;
        while(low <= high) {
            int mid = low + (high - low) / 2 ;
            int u = nums[low] , v = nums[high] ;
            int w = nums[mid] ;

            if(target == w) return mid ;

            if(u <= w) {
                if(target >= u && target < w) high = mid - 1 ;
                else low = mid + 1 ;
            } else {
                if(target > w && target <= v) low = mid + 1 ;
                else high = mid - 1 ;
            }
        }
        return -1 ;
    }
};