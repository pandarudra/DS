#define ll long long 
#define pll pair<ll , ll>
#define all(v) (v).begin(),(v).end()

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size() ;
        vector <pll> nums ;
        for(int i = 0 ; i < n ; i++){
            nums.push_back({nums1[i] , i}) ;
        }

        sort(all(nums)) ;
        vector <ll> res(n) ;
        ll s = 0 ;
        priority_queue<ll , vector<ll> , greater<ll>> pq ;
        int j = 0 ;
        for(int i = 0 ; i < n ; i++){
            auto& [u , idx] = nums[i] ;
            while(j < i){
                int prev = nums[j].second ;

                if(nums[j].first >= u)break ;
                s += nums2[prev] ;
                pq.push(nums2[prev]) ;

                if(pq.size() > k){
                    s -= pq.top() ;
                    pq.pop() ;
                }
                j++ ;
            }
            res[i] = s ;
        }

        vector<ll> re_res(n) ;
        for(int i = 0 ; i < n ; i++){
            re_res[nums[i].second] = res[i] ;
        }
        return re_res ;
    }
};