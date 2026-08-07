class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> hash(n + 1 , 0) , ans;
        for(auto x : nums) {
            if(hash[x] > 0) {
                ans.push_back(x) ;
            }
            hash[x]++ ;
        }
        return ans ;
    }
};