//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void dfs(int i , stack<int>& stack,vector<vector<int>>& adj,vector<bool>& vis){
        vis[i] = true ;
        for(auto &it : adj[i]){
            if(!vis[it]){
                dfs(it,stack,adj,vis) ;
            }
        }
        stack.push(i) ;
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
       vector<int> res ;
       int n = adj.size() ;
       vector<bool> vis(n , false) ;
       stack<int> stack ;
       for(int i = 0 ; i < n ; i++){
           if(!vis[i]){
               dfs(i,stack,adj,vis) ;
           }
       }
       
       while(!stack.empty()){
           res.push_back(stack.top()) ;
           stack.pop() ;
       }
    //   reverse(begin(res),end(res)) ;
       return res ;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends