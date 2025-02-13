#define all(v) (v).begin(),(v).end()
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> mndist(n , 1e9) ;
        vector<pair<int , int>> adj[n] ;
        for(auto  &it : times){
            adj[it[0] - 1].push_back({it[1] - 1, it[2]}) ;
        }
        mndist[k - 1] = 0 ;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq ;
        // src ---> dist
        pq.push({0 , k - 1}) ;
        while(!pq.empty()){
            int node = pq.top().second ;
            int edW = pq.top().first ;
            pq.pop() ;
            for(auto &it : adj[node]){
                int u = it.first ;
                int wt = it.second ;
                if(edW + wt < mndist[u]){
                    mndist[u] = edW + wt ;
                    pq.push({edW + wt , u}) ;
                }
            }
        }
        int mx = *max_element(all(mndist)) ;
        if(mx == 1e9)return -1 ;
        return mx ;
    }
};