class Solution {
private:
    bool khan(vector<vector<int>>& graph , int n){
        queue<int> q ;
        vector<int> indegree(n , 0) ;
        for(int i = 0 ; i < n ; i++){
            for(auto &it : graph[i]){
                indegree[it]++ ;
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }

        int cnt = 0 ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            cnt++ ;
            for(auto &it : graph[node]){
                indegree[it] -- ;
                if(indegree[it] == 0){
                    q.push(it) ;
                }
            }
        }

        return cnt == n ;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses ;
        vector<vector<int>> graph(n) ;
        for(auto &it : prerequisites){
            graph[it[1]].push_back(it[0]) ;
        }
        return khan(graph , n) ;
    }
};