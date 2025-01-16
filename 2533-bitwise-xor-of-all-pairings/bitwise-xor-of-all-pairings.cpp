#define all(v) (v).begin(),(v).end()
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size() ;
        int n2 = nums2.size() ;
        return
        ((n1 & 1) ? accumulate(all(nums2),0,bit_xor<>{}):0) ^ ((n2 & 1) ? accumulate(all(nums1),0,bit_xor<>{}):0) ;
    }
};