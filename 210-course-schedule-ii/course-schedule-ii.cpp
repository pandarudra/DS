class Solution {
private:
    vector<int> khan(vector<vector<int>>& graph , int n){
        vector<int> indegree(n , 0), res ;
        queue<int> q ;
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
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            res.push_back(node) ;
            for(auto &it : graph[node]){
                indegree[it]-- ;
                if(indegree[it] == 0){
                    q.push(it) ;
                }
            }
        }
        if(res.size() == n){
            return res ;
        }
        return {} ;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses) ;
        for(auto &it : prerequisites){
            graph[it[1]].push_back(it[0]) ;
        }

        vector<int> k = khan(graph , numCourses) ;
        return k ;
    }
};