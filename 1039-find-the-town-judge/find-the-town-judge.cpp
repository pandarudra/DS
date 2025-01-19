class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n + 1 , 0) , outdeg(n + 1 , 0) ;
        for(auto &node : trust){
            indeg[node[1]] ++ ;
            outdeg[node[0]] ++ ;
        }
        for(int i = 0 ; i <= n ; i++){
            if(indeg[i] == n - 1 && outdeg[i] == 0){
                if(i == 0){
                    return 1 ;
                }
                return i  ;
            }
        }
        return -1 ;
    }
};