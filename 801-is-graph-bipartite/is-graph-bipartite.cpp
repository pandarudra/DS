class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int> vis(n,0) ;
        vector<int> color(n,0) ;

        queue<int> q ;
        for(int i = 0 ; i < n ; i++){
            if(vis[i] != 0)continue ;
            q.push(i) ;
            vis[i] = 1 ;
            while(!q.empty()){
                int u = q.front() ;
                q.pop() ;
                for(auto &neighbor : graph[u]){
                    if(vis[neighbor] && color[u] == color[neighbor]){
                        return false ;
                    }
                    if(!vis[neighbor]){
                        vis[neighbor] = 1 ;
                        color[neighbor] = color[u] ^ 1 ;
                        q.push(neighbor) ;
                    }
                }
            }
        }
        return true ;
    }
};