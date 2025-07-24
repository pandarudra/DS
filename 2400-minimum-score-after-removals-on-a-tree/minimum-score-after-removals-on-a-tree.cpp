#define pb push_back

using uset = unordered_set<int>;

class Solution {
private:
        vector<int> subXor ;
        vector<uset> children ;

        void dfs(int node , int parent , vector<int>& value , vector<vector<int>>& adj) {
            subXor[node] = value[node] ;
            children[node].insert(node) ;

            for(auto ngbr : adj[node]) {
                if(ngbr == parent) continue ;
                dfs(ngbr , node , value , adj) ;
                subXor[node] ^= subXor[ngbr] ;
                for(auto x : children[ngbr]) {
                    children[node].insert(x) ;
                }
            }
        }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int N = nums.size() ;
        vector<vector<int>> adj(N) ;

        for(auto& node : edges) {
            int u = node[0] ;
            int v = node[1] ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
        }

        subXor = vector<int>(N) ;
        children = vector<uset>(N) ;

        dfs(0 , -1 , nums , adj) ;

        int totalXor = subXor[0] ;
        int ans = INT_MAX ; // min value

        int M = edges.size() ;

        for(int i = 0 ; i < M ; i++) {
            int a = edges[i][0] ;
            int b = edges[i][1] ;

            int parent1 = (children[a].count(b)) ? a : b ;
            int child1 = (parent1 == a) ? b : a ;

            for(int j = 0 ; j < i ; j++) {
                int c = edges[j][0] ;
                int d = edges[j][1] ;

                int parent2 = (children[c].count(d)) ? c : d ;
                int child2 = (parent2 == c) ? d : c ;

                int x1 , x2 , x3 ;

                // if child2 is a child of child1
                if(children[child1].count(child2)) {
                    x1 = subXor[child2] ;
                    x2 = subXor[child1] ^ subXor[child2] ;
                    x3 = totalXor ^ subXor[child1] ;
                }
                // if child1 is a child of child2
                else if(children[child2].count(child1)) {
                    x1 = subXor[child1] ;
                    x2 = subXor[child1] ^ subXor[child2] ;
                    x3 = totalXor ^ subXor[child2] ;
                }
                // if disjoint
                else {
                    x1 = subXor[child1] ;
                    x2 = subXor[child2] ;
                    x3 = totalXor ^ x1 ^ x2 ;
                }

                int mn = min({x1 , x2 , x3}) ;
                int mx = max({x1 , x2 , x3}) ;

                ans = min(ans , mx - mn) ;
            }
        }

        return ans ;
    }
};