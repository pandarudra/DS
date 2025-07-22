#define umap unordered_map
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int mx = 0 ;
        int N = nums.size() ;
        int sum = 0 ;

        umap<int , int> v2i ;
        // value => index

        int i = 0 , j = 0 ;

        while(i <= j && j < N) {
            sum += nums[j] ;
            if(v2i.count(nums[j])) {
                int k = v2i[nums[j]] ;
                while(i <= k) {
                    sum -= nums[i] ;
                    i++ ;
                }
            }
            v2i[nums[j]] = j ;
            j++ ;
            mx = max(mx , sum) ;
        }

        return mx ;
    }
};