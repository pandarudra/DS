#define all(v) (v).begin(),(v).end()
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> res ;

        int i ;
        for(i = 0 ; i < n - 1 ;){
            if(nums[i] != 0){
                if(nums[i] == nums[i + 1]){
                    res.push_back(2 * nums[i]) ;
                    nums[i + 1] = 0 ;
                    i += 2 ;
                }else{
                    res.push_back(nums[i]) ;
                    i++ ;
                }
            }else{
                i++ ;
            }
        }
        res.push_back(nums[n - 1]) ;

        while(res.size() < n){
            res.push_back(0) ;
        }
        return res ;
    }
};