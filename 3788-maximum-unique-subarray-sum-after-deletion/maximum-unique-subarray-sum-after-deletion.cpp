#define uset unordered_set
#define all(v) (v).begin(),(v).end()
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int mx = 0 ;
        uset<int> s ;
        for(auto num : nums) {
            if(num > 0) {
                if(!s.count(num)) {
                    mx += num ;
                } 
                s.insert(num) ;
            }
        }

        if(mx == 0) {
            mx += *max_element(all(nums)) ;
        }
        return mx ;
    }
};