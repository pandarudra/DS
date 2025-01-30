#define INF 0x3f3f3f3f
class Solution {
private:
    bool isBipartite(vector<vector<int>>& graph , vector<int>& connected , int src){
        int n = graph.size() ;
        vector<int> color(n , -1) ;
        queue<int> q ;
        color[src] = 0 ;
        q.push(src) ;
        connected.push_back(src) ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            for(auto &edge : graph[node]){
                if(color[edge] == -1){
                    color[edge] = 1 - color[node] ;
                    connected.push_back(edge) ;
                    q.push(edge) ;
                }else if(color[edge] == color[node]){
                    return false ;
                }
            }
        }
        return true ;
    }
    int bfs(int src , vector<vector<int>>& graph){
        queue<int> q ;
        q.push(src) ;
        int dist = 0 ;
        vector<int> d (graph.size() , -1) ;
        d[src] = 0 ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop();
            for(auto &edge : graph[node]){
                if(d[edge] == -1){
                    d[edge] = d[node] +  1 ;
                    dist = max(dist , d[edge]) ;
                    q.push(edge) ;
                }
            }
        }
        return dist + 1 ;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n) ;
        for(auto &edge : edges){
            graph[edge[0] - 1].push_back(edge[1] - 1) ;
            graph[edge[1] - 1].push_back(edge[0] - 1) ;
        }
        vector<int> vis(n , 0) ;
        int res = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(vis[i])continue ;
            vector<int> connected ;
            if(!isBipartite(graph , connected , i)){
                return -1 ;
            }
            int mx = 0 ;
            for(auto &node : connected){
                mx = max(mx , bfs(node , graph)) ;
            }
            res += mx ;
            for(auto &node : connected){
                vis[node] = 1 ;
            }
        }
        return res ;
    }
};