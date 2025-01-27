//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

#define  inf INT_MAX
class Solution {
  private:
    void  bfs(int src , vector<vector<int>>& adj , vector<int>& mndist){
        int n = adj.size() ;
        vector<int> vis(n , 0) ;
        queue<pair<int,int>> q ;
        q.push({src , 0}) ;
        vis[src] = 1 ;
        while(!q.empty()){
            int node = q.front().first ;
            int dist = q.front().second ;
            q.pop() ;
            mndist[node] = min(mndist[node] , dist) ;
            for(auto &it : adj[node]){
                if(!vis[it]){
                    q.push({it , dist + 1}) ;
                    vis[it] = 1 ;
                }
            }
        }
    }
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size() ;
        vector<int> mndist(n , inf) ;
        mndist[src] = 0 ;
        bfs(src , adj , mndist) ;
        for(auto &it : mndist){
            if(it  == inf){
                it = -1 ;
            }
        }
        return mndist ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends