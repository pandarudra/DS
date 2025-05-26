class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size() ;
        vector<int> topoOrder ;

        vector<int> inDegree(n , 0) ;

        for(int i = 0 ; i < n ; i++) {
            for(auto& v : adj[i]) {
                inDegree[v]++ ;
            }
        }

        queue<int> q ;
        for(int i = 0 ; i < n ; i++) {
            if(inDegree[i] == 0) {
                q.push(i) ;
            }
        }

        while(!q.empty()) {
            int node = q.front() ;
            q.pop() ;
            topoOrder.push_back(node) ;

            for(auto& edV : adj[node]) {
                if(--inDegree[edV] == 0) {
                    q.push(edV) ;
                }
            }
        }

        if(topoOrder.size() != n) {
            return {} ;
        }

        return topoOrder ;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length() ;
        vector<vector<int>> adj(n) ;
        
        for(auto& v : edges) {
            adj[v[0]].push_back(v[1]) ;
        }

        vector<int> topoOrder = topoSort(adj) ;

        if(topoOrder.empty()) return -1 ;

        vector<vector<int>> dp(n , vector<int>(26 , 0)) ;
        int mx = 0 ;

        for(auto& node : topoOrder) {
            int colIndex = colors[node] - 'a' ;
            dp[node][colIndex]++ ;

            for(auto& ngbr : adj[node]) {
                for(int c = 0 ; c < 26 ; c++) {
                    dp[ngbr][c] = max(dp[ngbr][c] , dp[node][c]) ;
                }
            }

            mx = max(mx , *max_element(begin(dp[node]) , end(dp[node]))) ;
        }

        return mx ;
    }
};