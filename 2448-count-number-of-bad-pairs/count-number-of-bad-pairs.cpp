#define ll long long 
#define umap unordered_map
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll cnt = 0 ;
        ll n = nums.size() ;

        for(ll i = 0 ; i < n ; i++){
            nums[i] -= i ;
        }

        umap<ll , ll> container ;
        for(ll i = n - 1 ; i >= 0 ; i--){
            ll key = nums[i] ;
            
            if(container.count(key)){
                ll x =  n - 1 - i - container[nums[i]];
                cnt += x ;
            }else{
                cnt += (n - 1 - i) ;
            }
            container[nums[i]]++ ;
        }
        return cnt ;
    }
};