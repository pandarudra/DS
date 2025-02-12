#define umap unordered_map
class Solution {
private:
    int cntDsum(int n){
        int s = 0 ;
        while(n > 0){
            s += (n % 10) ;
            n /= 10 ;
        }
        return s ;
    }
public:
    int maximumSum(vector<int>& nums) {
        int mx = -1 ;
        int n = nums.size() ;
        umap<int , priority_queue<int>> mp ;
        for(auto &it : nums){
            mp[cntDsum(it)].push(it) ;
        }
        for(auto &it : mp){
            priority_queue<int> pq = it.second ;
            if(pq.size() >= 2){
                int u = pq.top() ;
                pq.pop() ;
                int v = pq.top() ;
                mx = max(u + v , mx) ;
            }
        }
        return mx ;
    }
};