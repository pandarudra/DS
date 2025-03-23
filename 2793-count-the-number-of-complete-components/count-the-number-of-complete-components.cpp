class Solution {
        vector<vector<int>> adj ;
        void bfs(int i , vector<int>& vis , int& v , int& ed){
            queue<int> q ;
            q.push(i) ;
            v = 1 ;
            vis[i] = 1 ;
            while(!q.empty()){
                int node = q.front() ;
                q.pop() ;
                for(auto& ngbr : adj[node]){
                    ed++ ;
                    if(!vis[ngbr]){
                        v++ ;
                        q.push(ngbr) ;
                        vis[ngbr] = 1 ;
                    }
                }
            }
        }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n) ;
        for(auto& ed : edges){
            int u = ed[0] ;
            int v = ed[1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }
        int compos = 0 ;
        vector<int> vis(n , 0) ;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                int v = 0 , ed = 0 ;
                bfs(i , vis , v , ed) ;
                ed /= 2 ;
                if(ed == (v * (v - 1) / 2)){
                    compos++ ;
                }
            }
        }
        return compos ;
    }
};