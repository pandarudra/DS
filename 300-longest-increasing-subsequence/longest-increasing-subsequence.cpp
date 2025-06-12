#define all(t) (t).begin(),(t).end()
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size() ;
        vector<int> t ;
        t.push_back(nums[0]) ;
        int cnt = 1 ;

        for(int i = 1 ; i < N ; i++) {
            if(nums[i] > t.back()) {
                t.push_back(nums[i]) ;
                cnt++ ;
            } else {
                int index = lower_bound(all(t) , nums[i]) - t.begin() ;
                t[index] = nums[i] ;
            }
        }
        return cnt ;
    }
};