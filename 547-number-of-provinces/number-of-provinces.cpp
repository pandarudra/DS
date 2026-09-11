class Solution {


    void dfs(int node ,  vector<int>& vis , vector<vector<int>>& graph) {
       vis[node] = 1 ;
       for(int ngbr = 0 ; ngbr < graph.size() ; ngbr++) {
        if(!vis[ngbr] && graph[node][ngbr]) {
            dfs(ngbr , vis , graph) ;
        }
       }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0 ;
        int n = isConnected.size() ;

        vector<int> vis(n , 0) ;

        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                provinces++ ;
                dfs(i , vis , isConnected) ;
            }
        }
        return provinces ;
    }
};