#define all(v) (v).begin(),(v).end()
class Solution {
private:
    bool canbePlaced(vector<int>& nums , int mid , int k){
        int possible = 0 ;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i] < mid){
                possible++ ;
                i++ ;
            }
        }
        return possible >= k ;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size() - 1 ;
        int low = 1 , high = *max_element(all(nums)) ;
        while(low <= high){
            int mid = low + (high - low) / 2 ;
            if(canbePlaced(nums , mid , k)){
                high = mid - 1 ;
            }else{
                low = mid + 1 ;
            }
        }
        return high ;
    }
};