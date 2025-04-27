#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll cnt = 0 ;
        int n = nums.size() ;
        deque<int> dq_min , dq_max ;
        ll left = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > maxK || nums[i] < minK){
                dq_min.clear() ;
                dq_max.clear() ;
                left = i + 1 ;
                continue ;
            }

            while(!dq_min.empty() && nums[dq_min.back()] >= nums[i]){
                dq_min.pop_back() ;
            }
            dq_min.push_back(i) ;

            while(!dq_max.empty() && nums[dq_max.back()] <= nums[i]){
                dq_max.pop_back() ;
            }
            dq_max.push_back(i) ;

            if(nums[dq_min.front()] == minK && nums[dq_max.front()] == maxK){
                int start  = min(dq_min.front() , dq_max.front()) ;
                cnt += (start - left + 1) ;
            }
        }
        return cnt ;
    }
};