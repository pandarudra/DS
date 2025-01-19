class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int mx = 0 ;
        unordered_map<int,int> deg ;
        for(int i = 0 ; i < edges.size() ; i++){
            deg[edges[i][0]]++ ;
            deg[edges[i][1]]++ ;
            mx = max(mx,edges[i][0]) ;
            mx = max(mx,edges[i][1]) ;
        }
        for(auto &it : deg){
            if(it.second == mx - 1){
                return it.first ;
            }
        }
        return -1 ;
    }
};