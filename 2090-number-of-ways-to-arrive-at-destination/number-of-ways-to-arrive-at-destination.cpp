#define ll long long 
#define pll pair<ll , ll>
class Solution {
private:
    const ll mod = 1e9 + 7 ;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pll> adj[n] ;
        // wt - node 

        for(auto &it : roads){
            ll u = (ll)it[0] ;
            ll v = (ll)it[1] ;
            ll t = (ll)it[2] ;

            adj[u].push_back({v , t}) ;
            adj[v].push_back({u , t}) ;
        }

        vector<ll> dist(n , 1e12) , ways(n , 0) ;
        
        dist[0] = 0 ;
        ways[0] = 1 ;

        priority_queue<pll , vector<pll> , greater<pll>> pq ;
        pq.push({0 , 0}) ;

        while(!pq.empty()){
            auto [d , u] = pq.top() ;
            pq.pop() ;

            for(auto& [v , p] : adj[u]){
                if(p + d < dist[v]){
                    dist[v] = p + d ;
                    ways[v] = ways[u] % mod ;
                    pq.push({p + d , v}) ;
                }else if(p + d == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % mod ;
                }
            }
        } 

        return (int) ways[n - 1] ;
    }
};