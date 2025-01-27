class Solution {
public:
    void bfs(vector<vector<int>>& graph , vector<vector<int>>& canReach , vector<int> vis , int i){
        queue<int> q ;
        vis[i] = 1 ;
        q.push(i) ;
        while(!q.empty()){
            int  node = q.front() ;
            q.pop() ;
            for(auto &it : graph[node]){
                if(!vis[it]){
                    vis[it] = 1 ;
                    canReach[i][it] = 1 ;
                    q.push(it) ;
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses) ;
        for(auto &it : prerequisites){
            graph[it[0]].push_back(it[1]) ;
        }
        vector<int> vis(numCourses , 0) ;
        vector<vector<int>> canReach(numCourses , vector<int>(numCourses , 0)) ;
        
        for(int i = 0 ; i < numCourses ; i++){
            if(!vis[i]){
                bfs(graph , canReach , vis , i) ;
            }
        }
        vector<bool> res ;
        for(auto &q : queries){
            bool x = (canReach[q[0]][q[1]] == 1) ? true : false ;
            res.push_back(x) ;
        }
        return res ;
    }
};