#define umap unordered_map
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int sze = nums.size() ;
        umap <int , int> mp ;

        for(int i = 0 ; i < sze ; i++){
            for(int j  = i + 1 ; j < sze ; j++){
                mp[(nums[i] * nums[j])] ++ ;
            }
        }
        int cnt = 0 ;
        for(auto &it : mp){
            int k = it.first ;
            int v = it.second ;
            int c = v * (v - 1) / 2 ;
            cnt += (c * 8) ;
        }
        return cnt ;
    }
};