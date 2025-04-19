#define ll long long 
#define all(v) (v).begin(),(v).end()
class Solution {
private:
    int lb(vector<int>& nums , int low , int high , int target){
        while(low <= high){
            int mid = low + (high - low) / 2 ;
            if(nums[mid] >= target){
                high = mid - 1 ;
            }else{
                low = mid + 1 ;
            }
        }
        return low ;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(all(nums)) ;
        ll pairs = 0LL ;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            int low = lb(nums , i + 1 , n - 1 , lower - nums[i]) ;
            int high = lb(nums , i + 1 , n - 1 , upper - nums[i] + 1) ;

            pairs += 1LL * (high - low) ;
        }
        return pairs ;
    }
};