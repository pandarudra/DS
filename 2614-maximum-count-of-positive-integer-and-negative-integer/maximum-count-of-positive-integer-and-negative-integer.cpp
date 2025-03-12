class Solution {
private:
    int beforeZ(vector<int>& nums){
        int n = nums.size() ;
        int low = 0 , high = n - 1 ;
        while(low <= high){
            int mid = low + (high - low) / 2 ;
            if(nums[mid] < 0){
                low = mid + 1 ;
            }else{
                high = mid - 1 ;
            }
        }
        return high ;  
    }
    int afterZ(vector<int>& nums){
        int n = nums.size() ;
        int low = 0 , high = n - 1 ;
        while(low <= high){
            int mid = low + (high - low) / 2 ;
            if(nums[mid] <= 0){
                low = mid + 1 ;
            }else{
                high = mid - 1 ;
            }
        }
        return low ;  
    }
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size() ;
        int h = beforeZ(nums) ;
        int h_ = afterZ(nums) ;
        return max(h + 1 , n - h_) ;
    }
};