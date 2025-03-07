//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define pii pair<int , int>
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // vector<vector<pii>> graph(V) ;
        
        // for(auto& it : adj){
        //     int u = it[0] ;
        //     int v = it[1] ;
        //     int w = it[2] ;
            
        //     graph[u].push_back({v , wt}) ;
        //     graph[v].push_back({u , wt}) ;
        // }
        
        priority_queue<pii , vector<pii> , greater<pii>> pq ;
        vector<int> vis(V , 0) ;
        
        pq.push({0 , 0}) ;
        // wt -- node
        int sum = 0 ;
        
        while(!pq.empty()){
            int wt = pq.top().first ;
            int node = pq.top().second ;
            pq.pop() ;
            
            if(vis[node]) continue ;
            
            vis[node] = 1 ;
            sum += wt ;
            
            for(auto& edge : adj[node]){
                int edN = edge[0] ;
                int edW = edge[1] ;
                if(!vis[edN]){
                    pq.push({edW , edN}) ;
                }
            }
        }
        return sum ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends