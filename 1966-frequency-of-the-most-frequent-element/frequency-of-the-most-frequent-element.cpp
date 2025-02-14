#define umap unordered_map
#define all(v) (v).begin(),(v).end()
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(all(nums)) ;
        int n = nums.size() ;
        int mx = 0 ;
        long s = 0 ;
        int low = 0 ;
        for(int high  = 0 ; high < n ; high++){
            long v = nums[high] ;
            s += v ;

            while((high - low + 1) * v - s > k){
                s -= nums[low] ;
                low++ ;
            }
            mx = max(mx  , high - low + 1) ;

        }
        return mx ;
    }
};