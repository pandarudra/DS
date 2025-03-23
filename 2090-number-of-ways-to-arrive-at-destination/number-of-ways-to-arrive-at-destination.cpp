#define ll long long 
#define pll pair<ll , ll>
class Solution {
    const ll mod = 1e9 + 7 ;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pll> adj[n] ;
        for(auto& rd : roads){
            ll u = (ll) rd[0] ;
            ll v = (ll) rd[1] ;
            ll t = (ll) rd[2] ;
            adj[u].push_back({v , t}) ;
            adj[v].push_back({u , t}) ;
        }

        vector<ll> time(n , 1e12) , ways(n , 0) ;
        time[0] = 0 ;
        ways[0] = 1 ;
        priority_queue <pll , vector<pll> , greater<pll>> pq ;
        pq.push({0 , 0}) ;
        while(!pq.empty()){
            auto [t , node] = pq.top() ;
            pq.pop() ;
            for(auto& [node_ , t_] : adj[node]){
                if(t + t_ < time[node_]){
                    time[node_] = t + t_ ;
                    ways[node_] = ways[node] % mod ;
                    pq.push({t + t_ , node_}) ;
                }else if(t + t_ == time[node_]){
                    ways[node_] = (ways[node] + ways[node_]) % mod ;
                }
            }
        }
        return (int) ways[n - 1] ;
    }
};