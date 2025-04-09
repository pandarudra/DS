#define uset unordered_set
#define all(v) (v).begin(),(v).end()
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size() ;
        int mn = *min_element(all(nums)) ;

        if(mn < k) return -1 ;

        uset<int> unique ;
        for(auto& it : nums){
            unique.insert(it) ;
        }

        return unique.size() - ((mn == k) ? 1 : 0) ;
    }
};