#define uset unordered_set
#define all(v) (v).begin(),(v).end()
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int mx = 0 ;
        uset<int> s ;
        int maxi = -100 ;
        for(auto num : nums) {
            if(num > 0) {
                if(!s.count(num)) {
                    mx += num ;
                } 
                s.insert(num) ;
            }
            maxi = max(maxi , num) ;
        }

        return mx == 0 ? maxi : mx ;
    }
};