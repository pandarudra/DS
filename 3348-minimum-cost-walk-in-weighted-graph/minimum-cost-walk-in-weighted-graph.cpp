#define uint unsigned int

class Solution {
private:
class DisjointSet {
    vector<int> rank , parent ;
public:
    DisjointSet(int n){
        rank.resize(n + 1 , 0) ;
        parent.resize(n + 1) ;

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i ;
        }
    }

    int findUPar(int n){
        if(parent[n] == n){
            return n ;
        }
        return parent[n] = findUPar(parent[n]) ;
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return; 

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet ds(n);  // Fix: Use `n` instead of `sze`
        vector<uint> cost(n, -1);  

        for(auto& ed : edges){
            ds.unionByRank(ed[0] , ed[1]);
        }

        // Compute min cost per connected component
        unordered_map<int, uint> minCost;
        for(auto& ed : edges){
            int root = ds.findUPar(ed[0]);
            if (minCost.find(root) == minCost.end()) {
                minCost[root] = ed[2];
            } else {
                minCost[root] &= ed[2];  // Apply AND operation to find min
            }
        }

        vector<int> ans;
        for(auto& q : query){
            int s = q[0];
            int e = q[1];

            if(ds.findUPar(s) != ds.findUPar(e)){
                ans.push_back(-1);
            } else {
                int root = ds.findUPar(s);
                ans.push_back(minCost[root]);
            }
        }
        return ans;
    }
};
