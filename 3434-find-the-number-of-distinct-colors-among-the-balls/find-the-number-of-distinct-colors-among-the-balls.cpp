#define uset unordered_set
#define umap unordered_map
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res ;
        
        umap<int , int> val , color ;
        for(auto &q : queries){
            if(val[q[0]] > 0){
                color[val[q[0]]]-- ;
                if(color[val[q[0]]] == 0){
                    color.erase(val[q[0]]) ;
                }
            }
            val[q[0]] = q[1] ;
            color[q[1]]++ ;
            res.push_back(color.size()) ;
        }
        return res ;
    }
};