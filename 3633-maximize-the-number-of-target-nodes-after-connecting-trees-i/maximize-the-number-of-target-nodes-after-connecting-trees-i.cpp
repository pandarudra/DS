#define ipair pair<int ,int>
class Solution {
private:
    void bfs(vector<vector<int>>& tree1 , vector<vector<int>>& tree2 , vector<int>& ans , int k) {
        int m = tree2.size() ;
        int n = tree1.size() ;
        
        vector<int> ext(m , 0) ;
        for(int node2 = 0 ; node2 < m ; node2++) {
            queue<ipair> q ;
            vector<int> vis(m , 0) ;
            q.push({node2 , 1}) ;
            vis[node2] = 1 ;
            while(!q.empty()) {
                auto [node , ne] = q.front() ;
                q.pop() ;
                if(ne <= k && ne > 1) {
                    ext[node2]++ ;
                }
                for(auto& ngbr : tree2[node]) {
                    if(!vis[ngbr]) {
                        vis[ngbr] = 1 ;
                        q.push({ngbr , ne + 1}) ;
                    }
                }
            }
                
        }


        for(int node1 = 0 ; node1 < n ; node1++) {
            vector<int> vis(n , 0) ;
            queue<ipair> q ;
            // node - edge
            q.push({node1 , 0}) ;
            vis[node1] = 1 ;
            while(!q.empty()) {
                auto [node , ne] = q.front() ;
                q.pop() ;
                if(ne <= k) {
                    ans[node1]++ ;
                }
                for(auto& ngbr : tree1[node]) {
                    if(!vis[ngbr]) {
                        vis[ngbr] = 1 ;
                        q.push({ngbr , ne + 1}) ;
                    }
                }
            }

            int base = ans[node1] ;
            
            // let's go for tree2
            for(auto& it : ext) {
                ans[node1] = max(ans[node1] , it + base) ;
            }
          
        }
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1 ;
        int m = edges2.size() + 1 ;

        vector<vector<int>> tree1(n) , tree2(m) ;

        for(auto& v : edges1) {
            tree1[v[0]].push_back(v[1]) ;
            tree1[v[1]].push_back(v[0]) ;
        }

        for(auto& v : edges2) {
            tree2[v[0]].push_back(v[1]) ;
            tree2[v[1]].push_back(v[0]) ;
        }

        vector<int> answer(n , 1) ;

        if(k == 0) {
            return answer ;
        }

        bfs(tree1 , tree2 , answer , k) ;
        
        return answer ;
    }
};