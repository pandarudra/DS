#define ll long long
#define all(v) (v).begin(),(v).end()
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll maxi = *max_element(all(nums)) ;
        int n = nums.size() ;
        ll cnt = 0 ;
        int  _k = 0 ;
        int left = 0 ;

        for(int right = 0 ; right < n ; right++){
            if(nums[right] == maxi) _k++ ;

            while(_k >= k){
                cnt += (ll)(n - right) ;
                if(nums[left] == maxi) _k-- ;
                left++ ;
            }
        }
        return cnt ;
    }
};