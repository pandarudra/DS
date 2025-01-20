#define umap unordered_map
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        umap<int,pair<int,int>> mp ;
        int n = mat.size() ;
        int m = mat[0].size() ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                mp[mat[i][j]] = {i , j} ;
            }
        }
        vector<int> visRow(n,0) , visCol(m,0) ;

        for(int i = 0 ; i < arr.size() ; i++){
            int r = mp[arr[i]].first ;
            int c = mp[arr[i]].second ;
            visRow[r]++ ;
            visCol[c]++ ;
            if(visRow[r] == m || visCol[c] == n){
                return i ;
            }
        }
        return  -1 ;
    }
};