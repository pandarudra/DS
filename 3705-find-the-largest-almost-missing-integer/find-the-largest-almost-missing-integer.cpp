#define all(v) (v).begin(),(v).end()
class Solution {
    int k1(vector<int>& nums) {
        int mx = -1 ;
        int freq[51] = {0} ;
        for(auto x : nums) freq[x]++ ;
        for(auto x : nums) {
            if(freq[x] == 1) {
                mx = max(mx , x) ;
            }
        }
        return mx ;
    }
    int k2n(vector<int>& nums) {
        int n = nums.size() ;
        int mx = -1 ;
        int freq[51] = {0} ;
        for(auto x : nums) freq[x]++ ;



        int a = nums[0] , b = nums[n - 1] ;
        mx = freq[max(a , b)] == 1 ? max(a , b) : min(a , b) ;

        if(freq[mx] != 1) mx = -1 ;

        return mx  ;
    }    
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size() ;
        if(k == n) return *max_element(all(nums)) ;
        else if(k == 1) return k1(nums) ;
        else return k2n(nums) ;
        return -1 ;
    }
};