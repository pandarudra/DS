class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN , subSum = 0 ;
        for(int num : nums) {
            subSum += num ;
            mx = max(subSum , mx) ;
            if(subSum < 0) subSum = 0 ;
        }
        return mx ;
    }
};