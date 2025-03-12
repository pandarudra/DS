#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size() ;
        int h = lb(all(nums) , 0) - nums.begin() ;
        int h_ = ub(all(nums) , 0) - nums.begin() ;
        return max(h , n - h_) ;
    }
};