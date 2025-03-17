class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501] = {} ;
        for(auto& num : nums){
            freq[num]++ ;
        }
        for(auto& it : freq){
            if(it & 1){
                return false ;
            }
        }
        return true ;
    }
};