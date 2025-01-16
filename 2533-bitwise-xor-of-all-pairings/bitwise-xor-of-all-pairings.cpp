class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size() ;
        int n2 = nums2.size() ;
        int xorr1 = 0 , xorr2 = 0 ;
        if(n1 & 1){
            for(auto &it : nums2){
                xorr2 ^= it ;
            }
        }
        if(n2 & 1){
            for(auto &it : nums1){
                xorr1 ^= it ;
            }
        }
        return  xorr1 ^ xorr2 ;
    }
};