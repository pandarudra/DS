#define ll long long 
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll , vector<ll> , greater<ll>> pq ;
        for(auto &it : nums){
            pq.push((ll)it) ;
        }
        int mn = 0 ;
        while(!pq.empty() && pq.top() < k){
            ll u = pq.top() ;
            pq.pop() ;
            ll v = pq.top() ;
            pq.pop() ;
            ll nu = 2 * u + v ;
            mn++ ;
            pq.push(nu) ;
        }
        return mn ;
    }
};