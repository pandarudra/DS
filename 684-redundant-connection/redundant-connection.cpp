class Solution {
private:
    bool dfs(vector<vector<int>>& graph , vector<int>& vis , int src , int node){
        if(vis[node])return true ;
        vis[node] = 1 ;
        for(auto &it : graph[node]){
            if(it == src)continue ;
            if(dfs(graph , vis , node , it)){
                return true ;
            }
        }
        return false ;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        vector<vector<int>> graph(n + 1) ;

        for(auto &vect : edges){
            vector<int> vis(n + 1 , 0) ;
            graph[vect[0]].push_back(vect[1]) ;
            graph[vect[1]].push_back(vect[0]) ;

            if(dfs(graph , vis , -1 , vect[0])){
                return vect ;
            }
        }
        return {-1 , -1} ;
       
    }
};