#define ll long long 
#define all(v) (v).begin(),(v).end()
class Solution {
private:
    bool valid(vector<int>& candies , ll mid , ll k){
        ll cnt = 0 ;
        for(auto& it : candies){
            cnt += (it / mid) ;
        }
        return cnt >= k ;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll low = 1 , high = *max_element(all(candies)) ;
        while(low <= high){
            ll mid = low + (high - low) / 2 ;
            if(valid(candies , mid , k)){
                low = mid + 1 ;
            }else{
                high = mid - 1 ;
            }
        }
        return high ;
    }
};