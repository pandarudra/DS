#define ll long long
class Solution {
private:
    void helper(vector<int>& nums , ll& mx , ll n){
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                for(int k = j + 1 ; k < n ; k++){
                    ll u = nums[i] ;
                    ll v = nums[j] ;
                    ll w = nums[k] ;
                    mx = max(mx , (u - v) * w) ;
                }
            }
        }
    }
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll mx = 0LL ;
        ll n = nums.size() ;
        helper(nums , mx , n) ;
        return mx ;
    }
};