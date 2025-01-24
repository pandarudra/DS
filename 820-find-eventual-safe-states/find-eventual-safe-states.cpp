class Solution {
private: 
    vector<int> khan(vector<vector<int>>& graph){
        queue<int> q ;
        int n = graph.size() ;
        vector<int> indegree(n , 0) ;

        for(int i = 0 ; i < n ; i++){
            for(auto &it : graph[i]){
                indegree[it] ++ ;
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }

        vector<int> res ;

        while(!q.empty()){
            int node = q.front();
            q.pop() ;
            res.push_back(node) ;
            for(auto &it : graph[node]){
                indegree[it] -- ;
                if(indegree[it] == 0){
                    q.push(it) ;
                }
            }
        }
        return res ;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<vector<int>> adj(n) ;

        for(int i = 0 ; i < n ; i++){
            for(auto &it  : graph[i]){
                adj[it].push_back(i) ;
            }
        }

       
        vector<int> k = khan(adj) ;
        sort(begin(k) , end(k)) ;
        return k ;
    }
};