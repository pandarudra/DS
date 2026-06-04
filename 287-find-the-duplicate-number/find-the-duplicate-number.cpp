class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        
        int slow = 0 , fast = 0 ;
        for(int i = 0 ; i < n ; i++) {
            slow = nums[slow] ;
            fast = nums[nums[fast]] ;
            if(slow == fast && nums[slow] == nums[fast]) break ;
        }

        int ptr = 0 ;
        while(ptr != slow) {
            ptr = nums[ptr] ;
            slow = nums[slow] ;
        }

        return ptr ;
    }
};