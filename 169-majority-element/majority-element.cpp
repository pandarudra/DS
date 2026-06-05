class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        int candidate = 0 , vote = 0 ;

        for(auto x : nums) {
            if(vote == 0) {
                candidate = x ;
                vote = 1 ;
            }else if(candidate == x) {
                vote++ ;
            }else {
                vote-- ;
            }
        }
        
        return candidate ;
    }
};