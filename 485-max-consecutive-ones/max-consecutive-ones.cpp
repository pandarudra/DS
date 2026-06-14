class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size() ;
        int mx = 0 , sum = 0 ;
        for(auto x : nums) {
            if(x == 1) {
                sum++ ;
            } else {
                sum = 0 ;
            }
            mx = max(sum , mx) ;
        }
        return mx ;
    }
};