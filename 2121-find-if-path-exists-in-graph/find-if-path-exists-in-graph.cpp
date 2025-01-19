class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)return true ;
        
        vector<vector<int>> graph(n,vector<int>()) ;
        for(auto &edge : edges){
            graph[edge[0]].push_back(edge[1]) ;
            graph[edge[1]].push_back(edge[0]) ;
        }
        queue<int> q ;
        q.push(source) ;
        vector<int> vis(n , 0) ;
        vis[source] = 1 ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            for(auto &neighbor : graph[node]){
                if(!vis[neighbor]){
                    if(neighbor == destination){
                        return true ;
                    }
                    q.push(neighbor) ;
                    vis[neighbor] = 1 ;
                }
            }
        }
        return false ;
    }
};