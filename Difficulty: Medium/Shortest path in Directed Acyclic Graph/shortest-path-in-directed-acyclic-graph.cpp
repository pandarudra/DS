//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define inf INT_MAX
class Solution {
  private:
    void bfs(vector<vector<pair<int , int>>>& graph , vector<int>& mndist , int V){
        queue<pair<int , int>> q ;
        q.push({0 , 0}) ;
        mndist[0] = 0 ;
        while(!q.empty()){
            int v = q.front().first ;
            int wt = q.front().second ;
            q.pop() ;
            for(auto &it : graph[v]){
                int w = wt + it.second ;
                int node = it.first ;
                if(w < mndist[node]){
                    mndist[node] = w ;
                    q.push({node , w}) ;
                }
            }
        }
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int , int>>> graph(V) ;
        for(auto &vect : edges){
            int u = vect[0] ;
            int v = vect[1] ;
            int wt = vect[2] ;
            // u ---> v 
            graph[u].push_back({v , wt}) ;
        }
        
        vector<int> mndist(V , inf) ;
        bfs(graph , mndist , V) ;
        
        for(int i = 0 ; i < V ; i++){
            if(mndist[i] == inf){
                mndist[i] = -1 ;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends