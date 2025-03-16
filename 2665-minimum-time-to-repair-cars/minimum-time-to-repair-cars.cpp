#define all(v) (v).begin(),(v).end()
#define ll long long
class Solution {
private:
    bool canRepair(vector<int>& ranks , ll mid , int cars){
        ll can = 0 ;
        for(auto& it : ranks){
            can += (ll)(sqrt(mid * (1.0) / it)) ;
        }
        return can >= cars ;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll low = 1LL , high = *min_element(all(ranks)) * static_cast<ll>(cars) * cars ;

        while(low <= high){
            ll mid = low + (high - low) / 2 ;
            if(canRepair(ranks , mid , cars)){
                high = mid - 1 ;
            }else{
                low = mid + 1 ;
            }
        }

        return low ;
    }
};