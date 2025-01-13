class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int dx[8] = {-1 , -1 , -1 , 0 , 1 , 1 , 1 , 0} ;
        int dy[8] = {-1 , 0 , 1 , 1 , 1 , 0 , -1 , -1} ;
        int m = img.size() ;
        int n = img[0].size() ;

        vector<vector<int>> res(m , vector<int>(n)) ;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int deno = 1 ;
                int s = img[i][j] ;
                for(int k = 0 ; k < 8 ; k++){
                    int x = i + dx[k] ;
                    int y = j + dy[k] ;
                    if(x >= 0 && x < m && y >= 0 && y < n){
                        deno ++ ;
                        s += img[x][y] ;
                    }
                }
                res[i][j] = floor(s/deno) ;
            }
        }
        return res ;
    }
};