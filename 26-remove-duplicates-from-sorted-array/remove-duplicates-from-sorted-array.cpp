class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size() ;
        int left = 0 ;
        for(int right = 0 ; right < n ; right++) {
            if(left == right) continue ;
            if(nums[right] != nums[left]) {
                left++ ;
                nums[left] = nums[right] ;
            }
        }
        return left+1 ;
    }
};