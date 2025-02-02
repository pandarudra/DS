class Solution {
private:
    bool Sorted(vector<int>& nums , int start , int n){
        for(int i = start ; i  < n - 1 ; i++){
            if(nums[i + 1] > nums[0] || nums[i] > nums[i + 1]){
                return false ;
            }
        }
        if(start > 0 && start < n && nums[n - 1] > nums[0])return false ;
        return true ;
    }
public:
    bool check(vector<int>& nums) {
        int n = nums.size() ;

        int i = 0 ;
        while(i < n - 1 && nums[i] <= nums[i + 1])i++ ;

        if(Sorted(nums , i + 1 , n))return true ;
        return false ;
    }
};